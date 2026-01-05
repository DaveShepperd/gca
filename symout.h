#ifndef _SYMOUT_H_
#define _SYMOUT_H_

void symout_init(char* filename, FILE* asm_file, char* sourcename);
void symout_types(tree types);
int symout_block(tree decls, tree tags, tree args, int superblock_address);
int symout_function( tree stmt, tree args, int superblock_address);
void symout_function_end(void);
void symout_top_blocks(tree decls, tree tags);
void symout_finish(char* filename, int filetime);

#endif	/* _SYMOUT_H_ */
