#include "Compiler.h"

#define END_OF_HEX_FILE ":00000001FF"

Compiler::Compiler(ParametersHelper* param_helper)
{
	this->param_helper = param_helper;
	hex_file = NULL;
}

Compiler::~Compiler()
{
	vector<ObjFile*>::iterator it;
	ObjFile* obj_file;

	for (it = obj_files.begin(); it != obj_files.end(); it++)
	{
		obj_file = *it;
		delete obj_file;
	}

	obj_files.clear();

	if (hex_file != NULL)
		delete hex_file;
}

// Creating new local  ObjFile object and adding it to vector of object files
void Compiler::AddObjFileToVector(string file_name, uint bytecode_line_num)
{
	ObjFile* file = new ObjFile(file_name, bytecode_line_num);
	obj_files.push_back(file);
}

void Compiler::Compile()
{
	vector<ObjFile*>::iterator it;
	bool is_first_file = true;
	bool is_last_file;
	string input_line;
	size_t files_count = 1;
	ObjFile* obj_file;

	for (it = obj_files.begin(); it != obj_files.end(); it++)
	{
		obj_file = *it;
		is_last_file = files_count == obj_files.size();
		if (is_first_file)
		{
			hex_file = new HexFile(obj_file->GetFileName());
			hex_file->Open(FILE_IO_OUTPUT);
		}
		obj_file->Open(FILE_IO_INPUT);

		do
		{
			input_line = obj_file->ReadLine();

			if (!is_last_file && input_line == END_OF_HEX_FILE)
				continue;

			if (input_line != END_OF_HEX_FILE)
				hex_file->WriteLine(input_line);
			else
				hex_file->Write(input_line);

		} while (!obj_file->IsEndOfInput());

		obj_file->Close(FILE_IO_INPUT);

		is_first_file = false;
		files_count++;
	}
	
	ProcessParams();
}

void Compiler::ProcessParams()
{
	vector<Parameter*>* param_vector = param_helper->GetParameters();
	vector<Parameter*>::iterator it;

	for (it = param_vector->begin(); it != param_vector->end(); it++)
	{
		Parameter* param = *it;
		param_type type = param->GetParameterType();
		DbgInfoParam* dbg_info_param = NULL;
		DbgInfoParamHandler* dbg_info_param_handler = NULL;

		switch (type)
		{
		case PARAM_DBG_INFO:
			dbg_info_param = (DbgInfoParam*)param;
			dbg_info_param_handler = (DbgInfoParamHandler*)dbg_info_param->GetHandler();

			if (hex_file == NULL)
				throw new LLDevIOException("Hex file pointer is not pointing to a file.");

			dbg_info_param_handler->GenerateDbgFile(hex_file->GetFileName());
			break;
		default:
			break;
		}
	}
}