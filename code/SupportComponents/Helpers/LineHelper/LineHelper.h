#pragma once
#include <string>

using namespace std;

class LineHelper
{
public:
	static bool IsComment(string str_line);
	static bool IsEmptyLine(string str_line);
	static bool IsLabel(string str_line);
	static bool CanSkip(string str_line);
private:
	LineHelper() {};
};