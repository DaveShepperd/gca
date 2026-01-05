#ifndef _FLOW_H_
#define _FLOW_H_

void flow_analysis(rtx f, int nregs, FILE* file);
void allocate_for_life_analysis(void);
int regno_uninitialized(int regno);
int regno_clobbered_at_setjmp(int regno);
void dump_flow_info(FILE* file);

#endif	/* _FLOW_H_ */
