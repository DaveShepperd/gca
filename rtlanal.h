#ifndef _RTLANAL_H_
#define _RTLANAL_H_

/* From rtlanal.c */
int rtx_unstable_p(rtx x);
int rtx_varies_p(rtx x);
int rtx_addr_varies_p(rtx x);
int reg_mentioned_p( rtx reg,  rtx in);
int reg_used_between_p(rtx reg, rtx from_insn, rtx to_insn);
int reg_set_between_p(rtx reg, rtx from_insn, rtx to_insn);
int refers_to_regno_p(int regno, int endregno, rtx x, rtx* loc);
int reg_overlap_mentioned_p(rtx reg, rtx x);
int rtx_equal_p(rtx x, rtx y);
int dead_or_set_p(rtx insn, rtx reg);
rtx find_reg_note(rtx insn, enum reg_note kind, rtx datum);
rtx find_regno_note(rtx insn, enum reg_note kind, int regno);
int no_labels_between( rtx from,  rtx to);
int volatile_refs_p(rtx x);
int may_trap_p(rtx x);
void note_stores (register rtx x, void (*fun) (rtx dest, rtx x));

#endif	/* _RTLANAL_H_ */
