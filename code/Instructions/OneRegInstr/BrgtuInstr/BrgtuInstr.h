#pragma once

#include "../OneRegInstr.h"

using namespace std;

class BrgtuInstr: public OneRegInstr
{
public:
	BrgtuInstr(token_pos pos);
	uint32_t GetOpcode();
};