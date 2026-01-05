#ifndef _CSE_H_
#define _CSE_H_

int refers_to_p(rtx x, rtx y);
int refers_to_mem_p(rtx x, rtx reg, int start, int end);
int cse_main(rtx f, int nregs);

#endif	/* _CSE_H_ */
