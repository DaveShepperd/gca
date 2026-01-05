#ifndef _COMBINE_H_
#define _COMBINE_H_

void combine_instructions(rtx f, int nregs);
int regno_dead_p(int regno, rtx insn);
void remove_death(int regno, rtx insn);
void dump_combine_stats(FILE* file);
void dump_combine_total_stats(FILE* file);

#endif	/* _COMBINE_H_ */
