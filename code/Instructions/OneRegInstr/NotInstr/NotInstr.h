#pragma once

#include "../OneRegInstr.h"

using namespace std;

class NotInstr: public OneRegInstr
{
public:
	NotInstr(token_pos pos);
	uint32_t GetOpcode();
};