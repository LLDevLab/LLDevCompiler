#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BreqInstr: public OneRegInstr
{
public:
	BreqInstr(token_pos pos);
	uint32_t GetOpcode();
};