#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrltuInstr: public OneRegInstr
{
public:
	BrltuInstr(token_pos pos);
	uint32_t GetOpcode();
};