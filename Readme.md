# Assembly language compiler for lldevcpu

This is assembly language compiler for lldevcpu architecture.

## Supporting Operations

For now compiler supports next operations:
- noop
	- Description: no operation instruction.
	- Example: noop
- add rd, rs
	- Description: Adds values from 2 registers and puts the result to destination register (rd) 
	- Example: add r0, r1
- sub rd, rs
	- Description: Subtracts source register's (rs) value from destination register's (rd) value and puts the result to destination register.
	- Example: sub r0, r1
- br rs
	- Description: Unconditional branch to the address, that is stored in source register (rs).
	- Example: br r0
	
- breq rs
	- Description: If zero flag is set in Status register, this instruction will branch to the address, that is stored in source register (rs). Otherwise branch will not be taken and next instruction will be executed. 
	- Example: breq r0
	
- brne rs
	- Description: If zero flag is not set in Status register, this instruction will branch to the address, that is stored in source register (rs). Otherwise branch will not be taken and next instruction will be executed. 
	- Example: brne r0
	
- brlts rs
	- Description: This operation is using with signed integer numbers. It will branch to the address, that is stored in source register (rs), if negative flag in status register is set (value in rd register was less than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brlts r0

- brgts rs
	- Description: This operation is using with signed integer numbers. It will branch to the address, that is stored in source register (rs), if negative flag in status register is not set (value in rd register was greater than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brgts r0
	
- brltu rs
	- Description: This operation is using with unsigned integer numbers. It will branch to the address, that is stored in source register (rs), if carry flag in status register is set (value in rd register was less than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brltu r0
	
- brgtu rs
	- Description: This operation is using with unsigned integer numbers. It will branch to the address, that is stored in source register (rs), if carry flag in status register is not set (value in rd register was greater than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brgtu r0

At the end of file should always by an empty line.

## Using Context-Free Grammar
For parsing lines of assembly language instructions this compiler is using next context-free grammar:
- prgm -> instr_list **EOF** | **EOF**
- instr_list -> instr_list instr **EOI** | instr **EOI**
- instr -> zero_reg_instr | one_reg_instr | two_reg_instr
- zero_reg_instr -> **zero_reg_op**
- one_reg_instr -> **one_reg_op reg**
- two_reg_instr -> **two_reg_op reg, reg**

Terminal symbols are:
- EOF (End of File)
- EOI (End of Input)
- , (Comma)
- zero_reg_op (Operation with zero registers (example: noop))
- one_reg_op (Operation with one register)
- two_reg_op (Operation with two registers)
- reg (Register)

Nonterminal symbols are:
- zero_reg_instr (Instruction with zero registers)
- one_reg_instr (Instruction with one register)
- two_reg_instr (Instruction with two registers)
- instr (Instruction)
- instr_list (Instructions list)
- prgm (Programm)

Compiler is parsing assembly language via LR parser. 

## Links

lldevcpu repository is located [here](https://github.com/LLDevLab/lldevcpu.git)
