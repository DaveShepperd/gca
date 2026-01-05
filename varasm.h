#ifndef _VARASM_H_
#define _VARASM_H_ 1

void text_section(void);
void data_section(void);
int in_text_section(void);
void make_function_rtl(tree decl);
int decode_reg_name(char* asmspec);
void make_decl_rtl(tree decl, char* asmspec, int top_level);
void assemble_asm(tree string);
void assemble_function(tree decl);
void assemble_integer_zero(void);
void assemble_string(unsigned char* p, int size);
void assemble_variable(tree decl, int top_level, enum debugger write_symbols, int at_end);
void assemble_external(tree decl);
void assemble_name(FILE* file, char* name);
rtx assemble_static_space(int size);
rtx immed_double_const(int i0, int i1, enum machine_mode mode);
rtx immed_real_const_1(REAL_VALUE_TYPE d, enum machine_mode mode);
rtx immed_real_const(tree exp);
rtx force_const_double_mem(rtx r);
void clear_const_double_mem(void);
int const_hash(tree exp);
rtx output_constant_def(tree exp);
void init_const_rtx_hash_table(void);
int const_hash_rtx(enum machine_mode mode, rtx x);
rtx force_const_mem(enum machine_mode mode, rtx x);
void output_addressed_constants(tree exp);
void output_constant(register tree exp, register int size);
void output_constructor(tree exp, int size);

#endif	/* _VARASM_H_ */
