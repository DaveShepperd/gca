#ifndef _REGCLASS_H_
#define _REGCLASS_H_

void init_reg_sets(void);
void init_reg_sets_1(void);
void fix_register (char* name, int fixed, int call_used);
enum reg_class reg_preferred_class (int regno);
char reg_preferred_or_nothing(int regno);
int regclass_init(void);
void regclass(rtx f, int nregs);
void reg_class_record (rtx op, int opno, char * const *constraints);
void record_address_regs(rtx x, int bcost, int icost);
void reg_scan(rtx f, int nregs, int repeat);
void reg_scan_mark_refs(rtx x, int uid);

#endif	/* _REGCLASS_H_ */
