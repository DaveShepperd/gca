#ifndef _EMIT_RTL_H_
#define _EMIT_RTL_H_

#include "rtl.h"
rtx gen_rtx (int code, int mode, ...);
rtvec gen_rtvec(int n, ...);
rtvec gen_rtvec_v(int n, rtx *argp);
rtx gen_reg_rtx(enum machine_mode mode);
void mark_reg_pointer (rtx reg);
int max_reg_num(void);
int max_label_num(void);
int get_first_label_num(void);
rtx gen_lowpart(enum machine_mode mode,  rtx x);
rtx gen_highpart(enum machine_mode mode,  rtx x);
int subreg_lowpart_p(rtx x);
rtx change_address(rtx memref, enum machine_mode mode, rtx addr);
rtx gen_label_rtx(void);
rtx gen_inline_header_rtx(rtx insn, rtx last_insn, int first_labelno, int last_labelno, int max_parm_regnum, int max_regnum, int args_size, rtx stack_slots);
void set_new_first_and_last_insn(rtx first, rtx last);
void unshare_all_rtl( rtx insn);
rtx make_safe_from(rtx x, rtx other);
rtx get_insns(void);
rtx get_last_insn(void);
void set_last_insn(rtx insn);
int get_max_uid(void);
rtx next_insn(rtx insn);
rtx previous_insn(rtx insn);
void delete_insns_since(rtx from);
void reorder_insns(rtx from, rtx to, rtx after);
rtx emit_insn_before( rtx pattern,  rtx before);
rtx emit_jump_insn_before( rtx pattern,  rtx before);
rtx emit_call_insn_before( rtx pattern,  rtx before);
rtx emit_insn_after( rtx pattern,  rtx after);
rtx emit_jump_insn_after( rtx pattern,  rtx after);
rtx emit_barrier_after( rtx after);
void emit_label_after(rtx label, rtx after);
void emit_note_after(int subtype, rtx after);
rtx emit_insn(rtx pattern);
rtx emit_insns(rtx insn);
rtx emit_jump_insn(rtx pattern);
rtx emit_call_insn(rtx pattern);
rtx emit_label(rtx label);
rtx emit_barrier(void);
rtx emit_line_note(char* file, int line);
rtx emit_note(char* file, int line);
rtx emit_line_note_force(char* file, int line);
void force_next_line_note(void);
enum rtx_code classify_insn (rtx x);
void emit(rtx x);
rtx start_sequence(void);
void push_to_sequence(rtx first);
void end_sequence(void);
rtx gen_sequence(void);
void restore_reg_data(rtx first);
void init_emit(int write_symbols);
void init_emit_once(void);

#endif	/* _EMIT_RTL_H_ */
