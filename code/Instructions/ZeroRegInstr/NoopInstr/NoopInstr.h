#pragma once
#include "../ZeroRegInstr.h"

using namespace std;

class NoopInstr : public ZeroRegInstr
{
public:	
	NoopInstr(token_pos pos);
	uint32_t GetOpcode();
};