#include "File.h"

File::File(string file_name)
{
	this->file_name = file_name;
}

File::~File()
{
	Close(FILE_IO_INPUT);
	Close(FILE_IO_OUTPUT);
}

string File::GetFileName()
{
	string ret = RemoveFileExtension(file_name);
	ret += GetFileExtension();

	return ret;
}

string File::RemoveFileExtension(string file_name)
{
	string ret = file_name;
	size_t found_pos = ret.find_last_of(".");

	if (found_pos == string::npos)
		return file_name;

	ret = ret.substr(0, found_pos);

	return ret;
}

void File::Open(file_io_type io_type)
{
	string file_name = GetFileName();
	if (io_type == FILE_IO_INPUT && !io_stream.is_open())
		io_stream.open(file_name);
	else if(io_type == FILE_IO_OUTPUT && !out_stream.is_open())
		out_stream.open(file_name);
}

void File::Close(file_io_type io_type)
{
	if (io_type == FILE_IO_INPUT && io_stream.is_open())
		io_stream.close();
	else if (io_type == FILE_IO_OUTPUT && out_stream.is_open())
		out_stream.close();
}

void File::WriteLine(string line)
{
	if (!out_stream.is_open())
		ThrowFileStreamIsNotOpenException(FILE_IO_OUTPUT);

	out_stream << line << endl;
}

void File::Write(string line)
{
	if (!out_stream.is_open())
		ThrowFileStreamIsNotOpenException(FILE_IO_OUTPUT);

	out_stream << line;
}

bool File::IsEndOfInput()
{
	if (!io_stream.is_open())
		ThrowFileStreamIsNotOpenException(FILE_IO_INPUT);

	return io_stream.eof();
}

string File::ReadLine()
{
	string line = "";

	if (!io_stream.is_open())
		ThrowFileStreamIsNotOpenException(FILE_IO_INPUT);

	if(!io_stream.eof())
		getline(io_stream, line);

	return line;
}


void File::ThrowFileStreamIsNotOpenException(file_io_type io_type)
{
	string operation;

	if (io_type == FILE_IO_INPUT)
		operation = "reading";
	else
		operation = "writing";

	throw new LLDevIOException("File " + GetFileName() + " is not open for " + operation + ".");
}