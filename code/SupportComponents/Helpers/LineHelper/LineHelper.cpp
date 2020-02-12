#include "LineHelper.h"

bool LineHelper::IsComment(string str_line)
{
	return (str_line.length() > 1 && str_line.substr(0, 2) == "//");
}

bool LineHelper::IsEmptyLine(string str_line)
{
	size_t str_len = str_line.length();
	bool ret = str_len > 0 ? true : false;		// string with length 0 can get here only if end of file was reached

	for (size_t i = 0; i < str_len; i++)
	{
		char chr = str_line.at(i);
		if (chr != ' ' && chr != '\t')
		{
			ret = false;
			break;
		}
	}

	return ret;
}

// Checks if this is a label
bool LineHelper::IsLabel(string str_line)
{
	size_t size = str_line.size();
	int label_pos = 0;

	if (IsComment(str_line)) 
		return false;
	return size > 0 && str_line.at(size - 1) == ':';
}

bool LineHelper::CanSkip(string str_line)
{
	return IsComment(str_line) || IsEmptyLine(str_line) || IsLabel(str_line);
}