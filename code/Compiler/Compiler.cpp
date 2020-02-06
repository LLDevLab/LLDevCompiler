#include "Compiler.h"

#define END_OF_HEX_FILE ":00000001FF"

Compiler::~Compiler()
{
	CloseFiles();
}

void Compiler::CloseFiles()
{
	if (os_hex_file.is_open())
		os_hex_file.close();
	if (is_obj_file.is_open())
		is_obj_file.close();
}

// Adding object file name to vector of file names
void Compiler::AddFileName(string file_name)
{
	obj_file_names.push_back(file_name);
}

void Compiler::Compile()
{
	vector<string>::iterator it;
	bool is_first_file = true;
	bool is_last_file;
	string hex_file_name;
	string file_name;
	string input_line;
	size_t files_count = 1;

	for (it = obj_file_names.begin(); it != obj_file_names.end(); it++)
	{
		is_last_file = files_count == obj_file_names.size();
		file_name = *it;
		if (is_first_file)
		{
			hex_file_name = FileHelper::GetHexFileName(file_name);
			os_hex_file.open(hex_file_name);
		}
		is_obj_file.open(file_name);

		do
		{
			is_obj_file >> input_line;

			if (!is_last_file && input_line == END_OF_HEX_FILE)
				continue;

			os_hex_file << input_line;

			if (input_line != END_OF_HEX_FILE)
				os_hex_file << endl;

		} while (!is_obj_file.eof());

		is_obj_file.close();

		is_first_file = false;
		files_count++;
	}

	CloseFiles();
}