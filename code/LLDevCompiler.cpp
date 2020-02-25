#include <vector>
#include "Parser/Parser.h"
#include "Compiler/Compiler.h"
#include "Exceptions/LLDevExceptions.h"
#include "SupportComponents/SymbolTable/SymbolTable.h"
#include "SupportComponents/Helpers/Helpers.h"
#include "Types/TypeDef.h"
#include "Parameters/Parameters.h"

vector<string> GetFileNamesVector(int argc, char *argv[]);
vector<string> GetParametersVector(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	int i;
	const char* file_name = NULL;
	Compiler* compiler = NULL;
	SymbolTable symbol_table;
	uint last_bytecode_line = 0;
	ParametersHelper* param_helper = NULL;
	bool isException = false;

	try
	{
		symbol_table.InitSymbolTable(GetFileNamesVector(argc, argv));
		param_helper = new ParametersHelper(GetParametersVector(argc, argv));
		compiler = new Compiler(param_helper);

		for (i = 1; i < argc; i++)
		{
			file_name = argv[i];
			LexAnalyzer analyzer(file_name, &symbol_table);
			Parser parser(&analyzer, last_bytecode_line);
			parser.Parse();
			compiler->AddObjFileToVector(file_name, last_bytecode_line);
			last_bytecode_line = parser.GetLastBytecodeLine();
		}
		compiler->Compile();
	}
	catch (LLDevIOException& e)
	{
		isException = true;

		if (file_name != NULL)
			cout << e.what() << " in " << file_name << endl;
		else
			cout << e.what() << endl;
	}
	catch (LLDevSymbolTableException& e)
	{
		isException = true;
		cout << e.what() << endl;
	}
	catch (LLDevParameterException& e)
	{
		isException = true;
		cout << e.what() << endl;
	}
	catch (exception& e)
	{
		isException = true;
		cout << e.what() << endl;
	}

	if(compiler != NULL)
		delete compiler;
	if (param_helper != NULL)
		delete param_helper;

	if (isException)
		return -1;

	cout << "Compilation complete." << endl;
	return 0;
}

vector<string> GetFileNamesVector(int argc, char *argv[])
{
	vector<string> files_vector;

	for (int i = 1; i < argc; i++)
	{
		if(!ParametersHelper::IsParameter(argv[i]))
			files_vector.push_back(argv[i]);
	}

	return files_vector;
}

vector<string> GetParametersVector(int argc, char *argv[])
{
	vector<string> param_vector;

	for (int i = 1; i < argc; i++)
	{
		if (ParametersHelper::IsParameter(argv[i]))
			param_vector.push_back(argv[i]);
	}

	return param_vector;
}