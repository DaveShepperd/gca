#ifndef _JUMP_H_
#define _JUMP_H_

void jump_optimize(rtx f, int cross_jump, int noop_moves);
int simplejump_p(rtx insn);
int condjump_p(rtx insn);
int sets_cc0_p(rtx x);
int no_labels_between_p(rtx beg, rtx end);
rtx prev_real_insn(rtx label);
rtx next_real_insn(rtx label);
rtx next_label(rtx insn);
rtx delete_insn( rtx insn);
rtx next_nondeleted_insn(rtx insn);
void delete_for_peephole( rtx from,  rtx to);
void invert_jump(rtx jump, rtx nlabel);
void invert_exp(rtx x, rtx olabel, rtx nlabel);
void redirect_jump(rtx jump, rtx nlabel);
int rtx_renumbered_equal_p(rtx x, rtx y);
int true_regnum(rtx x);

#endif	/* _JUMP_H_ */
