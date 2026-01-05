#ifndef _DBXOUT_H_
#define _DBXOUT_H_

void dbxout_init(FILE* asm_file, char* input_file_name);
void dbxout_symbol(tree decl, int local);
void dbxout_args(tree args);
void dbxout_types( tree types);
void dbxout_tags(tree tags);
void dbxout_function(tree decl);
void dbxout_init(FILE* asm_file, char* input_file_name);

#endif	/* _DBXOUT_H_ */
