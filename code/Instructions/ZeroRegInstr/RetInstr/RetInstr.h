#pragma once
#include "../ZeroRegInstr.h"

using namespace std;

class RetInstr : public ZeroRegInstr
{
public:	
	RetInstr(uint line_num);
	uint32_t GetOpcode();
};