#pragma once
#include "../ZeroRegInstr.h"

using namespace std;

class NoopInstr : public ZeroRegInstr
{
public:	
	NoopInstr(uint line_num);
	uint32_t GetOpcode();
};