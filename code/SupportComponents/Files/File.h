#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../../Types/TypeDef.h"
#include "../../Exceptions/LLDevExceptions.h"

using namespace std;

enum file_io_type {FILE_IO_INPUT = 0, FILE_IO_OUTPUT = 1};

class File
{
public:
	string GetFileName();
	virtual string GetFileExtension() = 0;
	void Open(file_io_type io_type);
	void Close(file_io_type io_type);
	void WriteLine(string line);
	void Write(string line);
	bool IsEndOfInput();
	string ReadLine();
	~File();
protected:
	File(string file_name);
	string RemoveFileExtension(string file_name);
private:
	void ThrowFileStreamIsNotOpenException(file_io_type io_type);

	string file_name;
	ofstream out_stream;
	ifstream io_stream;
};