#ifndef _OPTABS_H_
#define _OPTABS_H_

#include "expr.h"	/* go get optab type */

/* From optabs.c */
rtx expand_binop(enum machine_mode mode, optab binoptab, rtx op0, rtx op1, rtx target, int unsignedp, enum optab_methods methods);
rtx sign_expand_binop(enum machine_mode mode, optab uoptab, optab soptab, rtx op0, rtx op1, rtx target, int unsignedp, enum optab_methods methods);
int expand_twoval_binop(optab binoptab, rtx op0, rtx op1, rtx targ0, rtx targ1, int unsignedp);
int expand_twoval_binop_convert( optab binoptab, int mode,  rtx op0,  rtx op1,  rtx targ0,  rtx targ1, int unsignedp);
rtx expand_unop(enum machine_mode mode, optab unoptab, rtx op0, rtx target, int unsignedp);
void emit_unop_insn(int icode, rtx target, rtx op0, enum rtx_code code);
void emit_clr_insn(rtx x);
void emit_0_to_1_insn(rtx x);
void emit_cmp_insn(rtx x, rtx y, rtx size, int unsignedp, int align);
rtx gen_add2_insn(rtx x, rtx y);
int have_add2_insn(enum machine_mode mode);
rtx gen_sub2_insn(rtx x, rtx y);
int have_sub2_insn(enum machine_mode mode);
rtx gen_move_insn(rtx x, rtx y);
rtx gen_extend_insn(rtx x, rtx y, enum machine_mode mto, enum machine_mode mfrom, int unsignedp);
void init_fixtab(void);
void init_floattab(void);
void expand_float(rtx real_to, rtx from, int unsignedp);
void expand_fix( rtx to,  rtx from, int unsignedp);
void init_optabs(void);

#endif	/* _OPTABS_H_ */
