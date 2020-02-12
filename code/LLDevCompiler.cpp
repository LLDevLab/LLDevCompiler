#include "Parser/Parser.h"
#include "Compiler/Compiler.h"
#include "Exceptions/LLDevExceptions.h"
#include "SupportComponents/SymbolTable/SymbolTable.h"
#include "SupportComponents/Helpers/Helpers.h"

int main(int argc, char *argv[])
{
	int i;
	const char* file_name = NULL;
	Compiler compiler;
	SymbolTable symbol_table(argc, argv);
	unsigned int last_bytecode_line = 0;
	try
	{
		symbol_table.InitSymbolTable();

		for (i = 1; i < argc; i++)
		{
			file_name = argv[i];
			LexAnalyzer analyzer(file_name, &symbol_table);
			Parser parser(&analyzer, last_bytecode_line);
			parser.Parse();
			compiler.AddFileName(FileHelper::GetObjFileName(file_name));
			last_bytecode_line = parser.GetLastBytecodeLine();
		}
		compiler.Compile();
	}
	catch (LLDevIOException& e)
	{
		if (file_name != NULL)
			cout << e.what() << " in " << file_name << endl;
		else
			cout << e.what() << endl;
		return -1;
	}
	catch (LLDevSymbolTableException& e)
	{
		cout << e.what() << endl;
		return -1;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		return -1;
	}

	cout << "Compilation complete." << endl;
	return 0;
}
