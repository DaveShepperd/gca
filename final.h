#ifndef _FINAL_H_
#define _FINAL_H_

void init_final(char* filename);
void end_final(char* filename);
void app_enable(void);
void app_disable(void);
int dbr_sequence_length(void);
void final_start_function(rtx first, FILE* file, enum debugger write_symbols, int optimize);
void profile_function(FILE* file);
void final_end_function(rtx first, FILE* file, enum debugger write_symbols, int optimize);
void final(rtx first, FILE* file, enum debugger write_symbols, int optimize, int prescan);
rtx final_scan_insn(rtx insn, FILE* file, enum debugger write_symbols, int optimize, int prescan, int nopeepholes);
void set_current_gdbfile(char* filename);
rtx alter_subreg( rtx x);
void output_asm_insn(char* template, rtx* operands);
void output_asm_label(rtx x);
void output_address(rtx x);
void output_addr_const(FILE* file, rtx x);

#endif	/* _FINAL_H_ */
