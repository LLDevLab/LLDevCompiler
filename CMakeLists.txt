cmake_minimum_required(VERSION "3.17.0")

project("LLDevCompiler")
add_executable("${CMAKE_PROJECT_NAME}")

set(SRC_MAIN_DIR "code")
set(CODE_GENERATOR_DIR "${SRC_MAIN_DIR}/CodeGenerator")
set(COMPILER_DIR "${SRC_MAIN_DIR}/Compiler")
set(EXCEPTIONS_DIR "${SRC_MAIN_DIR}/Exceptions")
set(LLDEV_IO_EXCEPTION_DIR "${EXCEPTIONS_DIR}/LLDevIOException")
set(LLDEV_PARAMETER_EXCEPTION_DIR "${EXCEPTIONS_DIR}/LLDevParameterException")
set(LLDEV_SYMBOL_TABLE_EXCEPTION_DIR "${EXCEPTIONS_DIR}/LLDevSymbolTableException")
set(INSTRUCTIONS_DIR "${SRC_MAIN_DIR}/Instructions")
set(ONE_REG_IMM_INSTR_DIR "${INSTRUCTIONS_DIR}/OneRegImmInstr")
set(LDI_INSTR_DIR "${ONE_REG_IMM_INSTR_DIR}/LdiInstr")
set(SHIFT_ROTATE_INSTR_DIR "${ONE_REG_IMM_INSTR_DIR}/ShiftRotateInstr")
set(LSH_INSTR_DIR "${SHIFT_ROTATE_INSTR_DIR}/LshInstr")
set(RSH_INSTR_DIR "${SHIFT_ROTATE_INSTR_DIR}/RshInstr")
set(RTLC_INSTR_DIR "${SHIFT_ROTATE_INSTR_DIR}/RtlcInstr")
set(RTL_INSTR_DIR "${SHIFT_ROTATE_INSTR_DIR}/RtlInstr")
set(RTRC_INSTR_DIR "${SHIFT_ROTATE_INSTR_DIR}/RtrcInstr")
set(RTR_INSTR_DIR "${SHIFT_ROTATE_INSTR_DIR}/RtrInstr")
set(ONE_REG_INSTR_DIR "${INSTRUCTIONS_DIR}/OneRegInstr")
set(BREQ_INSTR_DIR "${ONE_REG_INSTR_DIR}/BreqInstr")
set(BRGTS_INSTR_DIR "${ONE_REG_INSTR_DIR}/BrgtsInstr")
set(BRGTU_INSTR_DIR "${ONE_REG_INSTR_DIR}/BrgtuInstr")
set(BR_INSTR_DIR "${ONE_REG_INSTR_DIR}/BrInstr")
set(BRLTS_INSTR_DIR "${ONE_REG_INSTR_DIR}/BrltsInstr")
set(BRLTU_INSTR_DIR "${ONE_REG_INSTR_DIR}/BrltuInstr")
set(BRNE_INSTR_DIR "${ONE_REG_INSTR_DIR}/BrneInstr")
set(CALL_INSTR_DIR "${ONE_REG_INSTR_DIR}/CallInstr")
set(CLR_INSTR_DIR "${ONE_REG_INSTR_DIR}/ClrInstr")
set(NOT_INSTR_DIR "${ONE_REG_INSTR_DIR}/NotInstr")
set(POP_INSTR_DIR "${ONE_REG_INSTR_DIR}/PopInstr")
set(PUSH_INSTR_DIR "${ONE_REG_INSTR_DIR}/PushInstr")
set(ZERO_REG_INSTR_DIR "${INSTRUCTIONS_DIR}/ZeroRegInstr")
set(NOOP_INSTR_DIR "${ZERO_REG_INSTR_DIR}/NoopInstr")
set(RET_INSTR_DIR "${ZERO_REG_INSTR_DIR}/RetInstr")
set(TWO_REG_INSTR_DIR "${INSTRUCTIONS_DIR}/TwoRegInstr")
set(ADDC_INSTR_DIR "${TWO_REG_INSTR_DIR}/AddcInstr")
set(ADD_INSTR_DIR "${TWO_REG_INSTR_DIR}/AddInstr")
set(AND_INSTR_DIR "${TWO_REG_INSTR_DIR}/AndInstr")
set(CMP_INSTR_DIR "${TWO_REG_INSTR_DIR}/CmpInstr")
set(LD_INSTR_DIR "${TWO_REG_INSTR_DIR}/LdInstr")
set(MOV_INSTR_DIR "${TWO_REG_INSTR_DIR}/MovInstr")
set(OR_INSTR_DIR "${TWO_REG_INSTR_DIR}/OrInstr")
set(ST_INSTR_DIR "${TWO_REG_INSTR_DIR}/StInstr")
set(SUBC_INSTR_DIR "${TWO_REG_INSTR_DIR}/SubcInstr")
set(SUB_INSTR_DIR "${TWO_REG_INSTR_DIR}/SubInstr")
set(XOR_INSTR_DIR "${TWO_REG_INSTR_DIR}/XorInstr")
set(LEX_ANALYZER_DIR "${SRC_MAIN_DIR}/LexAnalyzer")
set(PARAMETER_HANDLERS_DIR "${SRC_MAIN_DIR}/ParameterHandlers")
set(PARAMETER_HANDLER_DIR "${PARAMETER_HANDLERS_DIR}/ParameterHandler")
set(DBG_INFO_PARAM_HANDLER_DIR "${PARAMETER_HANDLER_DIR}/DbgInfoParamHandler")
set(PARAMETERS_DIR "${SRC_MAIN_DIR}/Parameters")
set(PARAMETER_DIR "${PARAMETERS_DIR}/Parameter")
set(DBG_INFO_PARAM_DIR "${PARAMETER_DIR}/DbgInfoParam")
set(PARSER_DIR "${SRC_MAIN_DIR}/Parser")
set(SUPPORT_COMPONENTS_DIR "${SRC_MAIN_DIR}/SupportComponents")
set(FILES_DIR "${SUPPORT_COMPONENTS_DIR}/Files")
set(DBG_FILE_DIR "${FILES_DIR}/DbgFile")
set(HEX_FILE_DIR "${FILES_DIR}/HexFile")
set(OBJ_FILE_DIR "${FILES_DIR}/ObjFile")
set(SRC_FILE_DIR "${FILES_DIR}/SrcFile")
set(LDA_SRC_FILE_DIR "${SRC_FILE_DIR}/LdaSrcFile")
set(HELPERS_DIR "${SUPPORT_COMPONENTS_DIR}/Helpers")
set(LINE_HELPER_DIR "${HELPERS_DIR}/LineHelper")
set(PARAMETERS_HELPER_DIR "${HELPERS_DIR}/ParametersHelper")
set(SYMBOL_TABLE_DIR "${SUPPORT_COMPONENTS_DIR}/SymbolTable")
set(SYMBOL_DIR "${SYMBOL_TABLE_DIR}/Symbol")
set(LABEL_SYMBOL_DIR "${SYMBOL_DIR}/LabelSymbol")
set(RET_SYMBOL_DIR "${SYMBOL_DIR}/RetSymbol")
set(TOKEN_DIR "${SRC_MAIN_DIR}/Token")
set(TYPES_DIR "${SRC_MAIN_DIR}/Types")

target_sources("${CMAKE_PROJECT_NAME}" 
				PRIVATE 
					"${SRC_MAIN_DIR}/LLDevCompiler.cpp"
					"${CODE_GENERATOR_DIR}/CodeGenerator.cpp"
					"${CODE_GENERATOR_DIR}/CodeGenerator.h"
					"${COMPILER_DIR}/Compiler.cpp"
					"${COMPILER_DIR}/Compiler.h"
					"${EXCEPTIONS_DIR}/LLDevException.h"
					"${EXCEPTIONS_DIR}/LLDevExceptions.h"
					"${LLDEV_IO_EXCEPTION_DIR}/LLDevIOException.cpp"
					"${LLDEV_IO_EXCEPTION_DIR}/LLDevIOException.h"
					"${LLDEV_PARAMETER_EXCEPTION_DIR}/LLDevParameterException.cpp"
					"${LLDEV_PARAMETER_EXCEPTION_DIR}/LLDevParameterException.h"
					"${LLDEV_SYMBOL_TABLE_EXCEPTION_DIR}/LLDevSymbolTableException.cpp"
					"${LLDEV_SYMBOL_TABLE_EXCEPTION_DIR}/LLDevSymbolTableException.h"
					"${INSTRUCTIONS_DIR}/Instruction.cpp"
					"${INSTRUCTIONS_DIR}/Instruction.h"
					"${ONE_REG_IMM_INSTR_DIR}/OneRegImmInstuctions.h"
					"${ONE_REG_IMM_INSTR_DIR}/OneRegImmInstr.cpp"
					"${ONE_REG_IMM_INSTR_DIR}/OneRegImmInstr.h"
					"${LDI_INSTR_DIR}/LdiInstr.cpp"
					"${LDI_INSTR_DIR}/LdiInstr.h"
					"${SHIFT_ROTATE_INSTR_DIR}/ShiftRotateInstructions.h"
					"${SHIFT_ROTATE_INSTR_DIR}/ShiftRotateInstr.cpp"
					"${SHIFT_ROTATE_INSTR_DIR}/ShiftRotateInstr.h"
					"${LSH_INSTR_DIR}/LshInstr.cpp"
					"${LSH_INSTR_DIR}/LshInstr.h"
					"${RSH_INSTR_DIR}/RshInstr.cpp"
					"${RSH_INSTR_DIR}/RshInstr.h"
					"${RTLC_INSTR_DIR}/RtlcInstr.cpp"
					"${RTLC_INSTR_DIR}/RtlcInstr.h"
					"${RTL_INSTR_DIR}/RtlInstr.cpp"
					"${RTL_INSTR_DIR}/RtlInstr.h"
					"${RTRC_INSTR_DIR}/RtrcInstr.cpp"
					"${RTRC_INSTR_DIR}/RtrcInstr.h"
					"${RTR_INSTR_DIR}/RtrInstr.cpp"
					"${RTR_INSTR_DIR}/RtrInstr.cpp"
					"${ONE_REG_INSTR_DIR}/OneRegInstructions.h"
					"${ONE_REG_INSTR_DIR}/OneRegInstr.cpp"
					"${ONE_REG_INSTR_DIR}/OneRegInstr.h"
					"${BREQ_INSTR_DIR}/BreqInstr.cpp"
					"${BREQ_INSTR_DIR}/BreqInstr.h"
					"${BRGTS_INSTR_DIR}/BrgtsInstr.cpp"
					"${BRGTS_INSTR_DIR}/BrgtsInstr.h"
					"${BRGTU_INSTR_DIR}/BrgtuInstr.cpp"
					"${BRGTU_INSTR_DIR}/BrgtuInstr.h"
					"${BR_INSTR_DIR}/BrInstr.cpp"
					"${BR_INSTR_DIR}/BrInstr.h"
					"${BRLTS_INSTR_DIR}/BrltsInstr.cpp"
					"${BRLTS_INSTR_DIR}/BrltsInstr.h"
					"${BRLTU_INSTR_DIR}/BrltuInstr.cpp"
					"${BRLTU_INSTR_DIR}/BrltuInstr.h"
					"${BRNE_INSTR_DIR}/BrneInstr.cpp"
					"${BRNE_INSTR_DIR}/BrneInstr.h"
					"${CALL_INSTR_DIR}/CallInstr.cpp"
					"${CALL_INSTR_DIR}/CallInstr.h"
					"${CLR_INSTR_DIR}/ClrInstr.cpp"
					"${CLR_INSTR_DIR}/ClrInstr.h"
					"${NOT_INSTR_DIR}/NotInstr.cpp"
					"${NOT_INSTR_DIR}/NotInstr.h"
					"${POP_INSTR_DIR}/PopInstr.cpp"
					"${POP_INSTR_DIR}/PopInstr.h"
					"${PUSH_INSTR_DIR}/PushInstr.cpp"
					"${PUSH_INSTR_DIR}/PushInstr.h"
					"${ZERO_REG_INSTR_DIR}/ZeroRegInstructions.h"
					"${ZERO_REG_INSTR_DIR}/ZeroRegInstr.cpp"
					"${ZERO_REG_INSTR_DIR}/ZeroRegInstr.h"
					"${NOOP_INSTR_DIR}/NoopInstr.cpp"
					"${NOOP_INSTR_DIR}/NoopInstr.h"
					"${RET_INSTR_DIR}/RetInstr.cpp"
					"${RET_INSTR_DIR}/RetInstr.h"
					"${TWO_REG_INSTR_DIR}/TwoRegInstructions.h"
					"${TWO_REG_INSTR_DIR}/TwoRegInstr.cpp"
					"${TWO_REG_INSTR_DIR}/TwoRegInstr.h"
					"${ADDC_INSTR_DIR}/AddcInstr.cpp"
					"${ADDC_INSTR_DIR}/AddcInstr.h"
					"${ADD_INSTR_DIR}/AddInstr.cpp"
					"${ADD_INSTR_DIR}/AddInstr.h"
					"${AND_INSTR_DIR}/AndInstr.cpp"
					"${AND_INSTR_DIR}/AndInstr.h"
					"${CMP_INSTR_DIR}/CmpInstr.cpp"
					"${CMP_INSTR_DIR}/CmpInstr.h"
					"${LD_INSTR_DIR}/LdInstr.cpp"
					"${LD_INSTR_DIR}/LdInstr.h"
					"${MOV_INSTR_DIR}/MovInstr.cpp"
					"${MOV_INSTR_DIR}/MovInstr.h"
					"${OR_INSTR_DIR}/OrInstr.cpp"
					"${OR_INSTR_DIR}/OrInstr.h"
					"${ST_INSTR_DIR}/StInstr.cpp"
					"${ST_INSTR_DIR}/StInstr.h"
					"${SUBC_INSTR_DIR}/SubcInstr.cpp"
					"${SUBC_INSTR_DIR}/SubcInstr.h"
					"${SUB_INSTR_DIR}/SubInstr.cpp"
					"${SUB_INSTR_DIR}/SubInstr.h"
					"${XOR_INSTR_DIR}/XorInstr.cpp"
					"${XOR_INSTR_DIR}/XorInstr.h"
					"${LEX_ANALYZER_DIR}/LexAnalyzer.cpp"
					"${LEX_ANALYZER_DIR}/LexAnalyzer.h"
					"${PARAMETER_HANDLERS_DIR}/ParameterHandlers.h"
					"${PARAMETER_HANDLER_DIR}/ParameterHandler.h"
					"${DBG_INFO_PARAM_HANDLER_DIR}/DbgInfoParamHandler.cpp"
					"${DBG_INFO_PARAM_HANDLER_DIR}/DbgInfoParamHandler.h"
					"${PARAMETERS_DIR}/Parameters.h"
					"${PARAMETER_DIR}/Parameter.cpp"
					"${PARAMETER_DIR}/Parameter.h"
					"${DBG_INFO_PARAM_DIR}/DbgInfoParam.cpp"
					"${DBG_INFO_PARAM_DIR}/DbgInfoParam.h"
					"${PARSER_DIR}/Nonterminals.h"
					"${PARSER_DIR}/Parser.cpp"
					"${PARSER_DIR}/Parser.h"
					"${FILES_DIR}/Files.h"
					"${FILES_DIR}/File.cpp"
					"${FILES_DIR}/File.h"
					"${DBG_FILE_DIR}/DbgFile.cpp"
					"${DBG_FILE_DIR}/DbgFile.h"
					"${HEX_FILE_DIR}/HexFile.cpp"
					"${HEX_FILE_DIR}/HexFile.h"
					"${OBJ_FILE_DIR}/ObjFile.cpp"
					"${OBJ_FILE_DIR}/ObjFile.h"
					"${LDA_SRC_FILE_DIR}/LdaSrcFile.cpp"
					"${LDA_SRC_FILE_DIR}/LdaSrcFile.h"
					"${HELPERS_DIR}/Helpers.h"
					"${LINE_HELPER_DIR}/LineHelper.cpp"
					"${LINE_HELPER_DIR}/LineHelper.h"
					"${PARAMETERS_HELPER_DIR}/ParametersHelper.cpp"
					"${PARAMETERS_HELPER_DIR}/ParametersHelper.h"
					"${SYMBOL_TABLE_DIR}/SymbolTable.cpp"
					"${SYMBOL_TABLE_DIR}/SymbolTable.h"
					"${SYMBOL_DIR}/Symbols.h"
					"${SYMBOL_DIR}/Symbol.cpp"
					"${SYMBOL_DIR}/Symbol.h"
					"${LABEL_SYMBOL_DIR}/LabelSymbol.cpp"
					"${LABEL_SYMBOL_DIR}/LabelSymbol.h"
					"${RET_SYMBOL_DIR}/RetSymbol.cpp"
					"${RET_SYMBOL_DIR}/RetSymbol.h"
					"${TOKEN_DIR}/Token.cpp"
					"${TOKEN_DIR}/Token.h"
					"${TYPES_DIR}/TypeDef.h"
					)
					
					