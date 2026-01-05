#ifndef _LOOP_H_
#define _LOOP_H_

void loop_optimize(rtx f, FILE* dumpfile);
int loop_skip_over(rtx start, rtx end, rtx loop_entry_jump);
int addr_overlap_p(rtx other, rtx base, int size);
int other_reg_use_p( rtx reg,  rtx expr,  rtx in);

#endif	/* _LOOP_H_ */
