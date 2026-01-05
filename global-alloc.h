#ifndef _GLOBAL_ALLOC_H_
#define _GLOBAL_ALLOC_H_

void global_alloc(FILE *file);
void retry_global_alloc(int regno, short *forbidden_regs);
int check_frame_pointer_required(rtx *reg_equiv_constant, rtx *reg_equiv_mem, rtx *reg_equiv_address);
void dump_global_regs(FILE *file);

#endif	/* _GLOBAL_ALLOC_H_ */
