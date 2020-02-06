#include "FileHelper.h"

#define HEX_FILE_EXT ".hex"
#define OBJ_FILE_EXT ".o"

string FileHelper::GetObjFileName(string file_name)
{
	string obj_file_name = RemoveFileExtension(file_name);
	obj_file_name += OBJ_FILE_EXT;

	return obj_file_name;
}

string FileHelper::GetHexFileName(string file_name)
{
	string hex_file_name = RemoveFileExtension(file_name);
	hex_file_name += HEX_FILE_EXT;

	return hex_file_name;
}

string FileHelper::RemoveFileExtension(string file_name)
{
	string ret = file_name;
	size_t found_pos = ret.find_last_of(".");

	if (found_pos == string::npos)
		return file_name;

	ret = ret.substr(0, found_pos);

	return ret;
}