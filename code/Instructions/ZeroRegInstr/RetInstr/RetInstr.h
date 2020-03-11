#pragma once
#include "../ZeroRegInstr.h"

using namespace std;

class RetInstr : public ZeroRegInstr
{
public:	
	RetInstr(token_pos pos);
	uint32_t GetOpcode();
};