#include "SymbolTable.h"

SymbolTable::SymbolTable(int argc, char* argv[])
{
	int i;

	file_names_len = argc - 1;
	file_names = new string[file_names_len];

	for (i = 0; i < file_names_len; i++)
		file_names[i] = argv[i + 1];
}

SymbolTable::~SymbolTable()
{
	delete[] file_names;
}

void SymbolTable::InitSymbolTable()
{
	string line = "";
	int i = 0;
	int j;

	for (j = 0; j < file_names_len; j++)
	{
		OpenFile(file_names[j]);

		while (true)
		{
			line = ReadLine();

			if (line == "")
				break;

			if (!LineHelper::CanSkip(line))
				i++;
			else if (LineHelper::IsLabel(line))
			{
				line = line.substr(0, line.size() - 1);

				if(label_to_line_num_map.find(line) != label_to_line_num_map.end())
					throw LLDevSymbolTableException("Label already exists in symbol table.");
				
				label_to_line_num_map.insert_or_assign(line, i);					
			}
		}

		CloseFile();
	}
}

bool SymbolTable::LabelExist(string label)
{
	return label_to_line_num_map.find(label) != label_to_line_num_map.end();
}

int SymbolTable::GetLabelLineNum(string label)
{
	return label_to_line_num_map.find(label)->second;
}

void SymbolTable::OpenFile(string file_name)
{
	ios_file.open(file_name);

	if (!ios_file.is_open())
		throw exception("File is not open.");
}

void SymbolTable::CloseFile()
{
	if (ios_file.is_open())
		ios_file.close();
}

string SymbolTable::ReadLine()
{
	string ret = "";

	do
	{
		getline(ios_file, ret);

	} while (!ios_file.eof() && ret == "");			// ignore empty lines

	return ret;
}