#pragma once
#include <string>

using namespace std;

class FileHelper
{
public:
	static string GetObjFileName(string file_name);
	static string GetHexFileName(string file_name);
private:
	FileHelper() {};
	static string RemoveFileExtension(string file_name);
};