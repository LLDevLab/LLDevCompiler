#pragma once

// Nonterminal values could be from 0 to 100
enum NONTERMINALS {
	PRGM = 0,				// Programm
	INSTR_LIST = 1,			// Instruction list
	INSTR = 2,				// Instruction
	ZERO_REG_INSTR = 3,		// Zero register instruction
	ONE_REG_INSTR = 4,		// One register instruction
	TWO_REG_INSTR = 5,		// Two register instruction
	ONE_REG_IMM_INSTR = 6	// One register and immediate value instruction
};