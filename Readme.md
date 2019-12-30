# Assembly language compiler for lldevcpu

This is assembly language compiler for lldevcpu architecture.

## Comments
- "//" at the beginning of the line is denote a comment line

## Labels
- A labels now can be used in the code. The label usage example:  
  
*branchHereLabel:*  
*ldi r2, branchHereLabel*  
*br r2*  

## Supporting Instructions

For now compiler supports next Instructions:
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
	- Description: This instruction is using with signed integer numbers. It will branch to the address, that is stored in source register (rs), if negative flag in status register is set (value in rd register was less than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brlts r0
- brgts rs
	- Description: This instruction is using with signed integer numbers. It will branch to the address, that is stored in source register (rs), if negative flag in status register is not set (value in rd register was greater than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brgts r0
- brltu rs
	- Description: This instruction is using with unsigned integer numbers. It will branch to the address, that is stored in source register (rs), if carry flag in status register is set (value in rd register was less than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brltu r0
- brgtu rs
	- Description: This instruction is using with unsigned integer numbers. It will branch to the address, that is stored in source register (rs), if carry flag in status register is not set (value in rd register was greater than value in rs register). Otherwise branch will not be taken and next instruction will be executed.
	- Example: brgtu r0
- cmp rd, rs
	- Description: Compares 2 registers and sets oppropriate flags in Status Register, but do not chance values of these registers.
	- Example: cmp r0, r1
- clr rd
	- Description: Clears all bits in rd register and resets all status flags.
	- Example: clr r0
- ldi rd, imm
	- Description: Loads decimal or hexadecimal immediate value to the register
	- Decimal value example: ldi r0, #10
	- Hexadecimal value example: ldi r0, #0x10
- or rd, rs
	- Description: Doing bitwise OR operation on values from 2 registers and storing the result to destination register (rd)
	- Example: or r0, r1
- and rd, rs
	- Description: Doing bitwise AND operation on values from 2 registers and storing the result to destination register (rd)
	- Example: and r0, r1
- xor rd, rs
	- Description: Doing bitwise XOR operation on values from 2 registers and storing the result to destination register (rd)
	- Example: xor r0, r1
- not rd
	- Description: Doing bitwise NOT operation on value from destination register (rd) and storing the result to destination register (rd)
	- Example: not r0
- lsh rd, imm
	- Description: Doing bitwise left shift operation on value from destination register (rd) and storing the result to destination register (rd)
	- Decimal value example: lsh r0, #10
	- Hexadecimal value example: lsh r0, #0x10
- rsh rd, imm
	- Description: Doing bitwise right shift operation on value from destination register (rd) and storing the result to destination register (rd)
	- Decimal value example: rsh r0, #10
	- Hexadecimal value example: rsh r0, #0x10
- rtl rd, imm
	- Description: Doing bitwise left rotate operation on value from destination register (rd) and storing the result to destination register (rd)
	- Decimal value example: rtl r0, #10
	- Hexadecimal value example: rtl r0, #0x10
- rtr rd, imm
	- Description: Doing bitwise right rotate operation on value from destination register (rd) and storing the result to destination register (rd)
	- Decimal value example: rtr r0, #10
	- Hexadecimal value example: rtr r0, #0x10
- rtlc rd, imm
	- Description: Doing bitwise left rotate operation, through carry bit (value from carry bit will also rotate left), on value from destination register (rd) and storing the result to destination register (rd)
	- Decimal value example: rtlc r0, #10
	- Hexadecimal value example: rtlc r0, #0x10
- rtrc rd, imm
	- Description: Doing bitwise right rotate operation, through carry bit (value from carry bit will also rotate right), on value from destination register (rd) and storing the result to destination register (rd)
	- Decimal value example: rtrc r0, #10
	- Hexadecimal value example: rtrc r0, #0x10
- addc rd, rs
	- Description: Adds values from 2 registers and a carry bit and puts the result to destination register (rd) 
	- Example: addc r0, r1
- subc rd, rs
	- Description: Subtracts source register's (rs) value and a carry bit from destination register's (rd) value and puts the result to destination register.
	- Example: subc r0, r1
- ld rd, rs
	- Description: Loads data from memory address (that is stored in source register (rs)), to destination register (rd).
	- Example: ld r0, r1
- st rd, rs
	- Description: Store data from source register (rs) to memory address (that is stored in destination register (rd)).
	- Example: st r0, r1
- mov rd, rs
	- Description: Move data from source register (rs) to destination register (rd).
	- Example: mov r0, r1
- push rs
	- Description: Store the content of source register (rs) to the top of the stack.
	- Example: push r0
- pop rd
	- Description: Load content from the top of the stack to the destination register (rd).
	- Example: pop r0

At the end of file should always by an empty line.

## Using Context-Free Grammar
For parsing lines of assembly language instructions this compiler is using next context-free grammar:
- prgm -> instr_list **EOF** | **EOF**
- instr_list -> instr_list instr **EOI** | instr **EOI**
- instr -> zero_reg_instr | one_reg_instr | one_reg_imm_instr | two_reg_instr
- zero_reg_instr -> **zero_reg_op**
- one_reg_instr -> **one_reg_op reg**
- one_reg_imm_instr -> **one_reg_imm_op reg, imm**
- two_reg_instr -> **two_reg_op reg, reg**

Terminal symbols are:
- EOF (End of File)
- EOI (End of Input)
- , (Comma)
- zero_reg_op (Operation with zero registers (example: noop))
- one_reg_imm_op (Operation with one register and one immediate value)
- one_reg_op (Operation with one register)
- two_reg_op (Operation with two registers)
- reg (Register)
- imm (Immediate value)

Nonterminal symbols are:
- zero_reg_instr (Instruction with zero registers)
- one_reg_instr (Instruction with one register)
- one_reg_imm_instr (Instructions with one register and one immediate value)
- two_reg_instr (Instruction with two registers)
- instr (Instruction)
- instr_list (Instructions list)
- prgm (Programm)

Compiler is parsing assembly language via LR parser. 

## Links

lldevcpu repository is located [here](https://github.com/LLDevLab/lldevcpu.git)
