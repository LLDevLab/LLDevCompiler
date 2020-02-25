#include "SymbolTable.h"

SymbolTable::~SymbolTable()
{
	map<string, Symbol*>::iterator sym_map_it;
	vector<ObjFile*>::iterator obj_file_vect_it;

	for (sym_map_it = symbols_map.begin(); sym_map_it != symbols_map.end(); sym_map_it++)
	{
		Symbol* sym = sym_map_it->second;
		delete sym;
	}
	symbols_map.clear();

	for (obj_file_vect_it = obj_file_vector.begin(); obj_file_vect_it != obj_file_vector.end(); obj_file_vect_it++)
	{
		ObjFile* file = *obj_file_vect_it;
		delete file;
	}
	obj_file_vector.clear();
}

void SymbolTable::InitSymbolTable(vector<string> file_names)
{
	vector<string>::iterator file_names_it;
	ObjFile* obj_file = NULL;
	string line = "";
	Symbol* sym;
	uint i;
	uint init_bytecode_line_num = 0;

	for (file_names_it = file_names.begin(); file_names_it != file_names.end(); file_names_it++)
	{
		vector<Symbol*> file_sym_vect;
		LdaSrcFile lda_file(*file_names_it);
		obj_file = new ObjFile(lda_file.GetFileName(), init_bytecode_line_num);
		obj_file_vector.push_back(obj_file);
		
		lda_file.Open(FILE_IO_INPUT);
		i = 0;

		while (true)
		{
			line = ReadLine(&lda_file);

			// Here empty line could be return when end of file was reached
			if (line == "")
				break;

			if (!LineHelper::CanSkip(line))
				i++;
			
			if (Symbol::IsSymbol(line))
			{
				if(LineHelper::IsLabel(line))
					line = line.substr(0, line.size() - 1);

				if (SymbolExist(line))
					throw LLDevSymbolTableException("Label \"" + line + "\" already exists in symbol table.");
				
				sym = InitSymbol(line, i, obj_file);
				symbols_map.insert(pair<string, Symbol*>(sym->GetSymbolName(), sym));
				file_sym_vect.push_back(sym);
			}
		}

		lda_file.Close(FILE_IO_INPUT);

		sort(file_sym_vect.begin(), file_sym_vect.end());
		file_sym_map.insert(pair<string, vector<Symbol*>>(obj_file->GetFileName(), file_sym_vect));

		init_bytecode_line_num += i;
	}

	sort(obj_file_vector.begin(), obj_file_vector.end());
}

bool SymbolTable::SymbolExist(string symbol)
{
	return symbols_map.find(symbol) != symbols_map.end();
}

uint SymbolTable::GetSymbolPos(string symbol)
{
	map<string, Symbol*>::iterator it = symbols_map.find(symbol);
	Symbol* sym;

	if (it == symbols_map.end())
		SymbolNotFoundException(symbol);

	sym = it->second;

	return sym->GetSymbolPosOffset() + sym->GetSymbolPos();
}

string SymbolTable::ReadLine(LdaSrcFile* lda_file)
{
	string ret = "";

	do
	{
		ret = lda_file->ReadLine();

	} while (!lda_file->IsEndOfInput() && ret == "");			// ignore empty lines

	return ret;
}

Symbol* SymbolTable::InitSymbol(string line, uint pos, ObjFile* obj_file)
{
	Symbol* sym = NULL;

	if (LineHelper::IsRet(line))
		sym = new RetSymbol(line, pos, obj_file);
	else
		sym = new LabelSymbol(line, pos, obj_file);

	return sym;
}

vector<Symbol*> SymbolTable::GetFileSymVector(string file_name)
{
	vector<Symbol*> sym_vector;
	map<string, vector<Symbol*>>::iterator file_sym_map_it = file_sym_map.find(file_name);
	
	if (file_sym_map_it != file_sym_map.end())
		sym_vector = file_sym_map_it->second;

	return sym_vector;
}

void SymbolTable::SetSymbolPos(string sym_name, uint sym_pos)
{
	map<string, Symbol*>::iterator it = symbols_map.find(sym_name);
	Symbol* sym;

	if (it == symbols_map.end())
		SymbolNotFoundException(sym_name);

	sym = it->second;
	sym->SetSymbolPos(sym_pos);
}

vector<ObjFile*> SymbolTable::GetObjFileVector()
{
	return obj_file_vector;
}

inline void SymbolTable::SymbolNotFoundException(string sym_name)
{
	throw LLDevSymbolTableException("Label \"" + sym_name + "\" not found in symbol table.");
}