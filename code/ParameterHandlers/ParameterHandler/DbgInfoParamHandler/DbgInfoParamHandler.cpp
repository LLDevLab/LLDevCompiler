#include "DbgInfoParamHandler.h"

DbgInfoParamHandler::DbgInfoParamHandler(SymbolTable* symbol_table)
{
	this->symbol_table = symbol_table;
}

void DbgInfoParamHandler::GenerateDbgFile(DbgFile file)
{
	vector<ObjFile*> obj_file_vector = symbol_table->GetObjFileVector();
	vector<ObjFile*>::iterator obj_file_it;

	file.Open(FILE_IO_OUTPUT);

	for (obj_file_it = obj_file_vector.begin(); obj_file_it != obj_file_vector.end(); obj_file_it++)
	{
		ObjFile* obj_file = *obj_file_it;
		vector<Symbol*> file_sym_vector = symbol_table->GetFileSymVector(obj_file->GetFileName());

		vector<Symbol*>::iterator it;
		Symbol* sym;

		for (it = file_sym_vector.begin(); it != file_sym_vector.end(); it++)
		{
			sym = *it;
			file.WriteLine(sym->ToString());
		}
	}

	file.Close(FILE_IO_OUTPUT);
}