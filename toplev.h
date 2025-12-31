/* Prints out tree in human readable form - GNU C-compiler
   Copyright (C) 1990 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 1, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#ifndef _TOPLEV_H_
#define _TOPLEV_H_ (1)

#if 0
#include <sys/types.h>
#include <stdarg.h>

extern void fatal (const char *format, ... ) __attribute__ ((__format__ (__printf__, 1, 0)));

extern void error( const char *format, ... ) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void error_with_file_and_line (const char *file, int line, const char *fmt, ... ) __attribute__ ((__format__ (__printf__, 3, 0)));
extern void verror_with_file_and_line (const char *file, int line, const char *format, va_list ap);
extern void error_with_decl (tree decl, const char *format /*, int arg */ );
extern void error_for_asm (rtx insn, const char *fmt, ...) __attribute__ ((__format__ (__printf__, 2, 0)));

extern void warning (const char *format, ...) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void warning_with_file_and_line (const char *file, int line, const char *format, ...) __attribute__ ((__format__ (__printf__, 3, 0)));
extern void vwarning_with_file_and_line (const char *file, int line, const char *format, va_list ap);
extern void warning_with_decl (tree decl, const char *format /*, int arg */ );
extern void warning_for_asm (rtx insn, const char *fmt, ...) __attribute__ ((__format__ (__printf__, 2, 0)));

extern void sorry (const char *format, ...) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void really_sorry (const char *format, ...)  __attribute__ ((__format__ (__printf__, 1, 0)));

extern void *xmalloc(unsigned int len);
extern void *xrealloc (void *ptr, unsigned int size);

extern void end_temporary_allocation (void);
extern void rest_of_decl_compilation (tree decl, char *asmspec, int top_level, int at_end );
extern void fancy_abort (void);
extern void botch (const char *msg);

extern void set_target_switch (char *name);
extern void print_target_switch_defaults (void);

extern void debug_rtx(rtx insn);	/* actually in aux-output.c */
extern void init_emit_once(void);	/* in emit-rtl.c */
extern int check_newline(void);		/* in c-parse.tab.c */

/* in symout.c */
extern void symout_init (char *filename, FILE *asm_file, char *sourcename);
extern void symout_types (tree types);
extern int symout_block (tree decls, tree tags, tree args, int superblock_address);
extern int symout_function (tree stmt, tree args, int superblock_address);
extern void symout_function_end (void);
extern void symout_top_blocks (tree decls, tree tags);
extern void symout_finish (char *filename, int filetime);


extern void text_section(void);		/* in varasm.c */

/* in dbxout.c */
extern void dbxout_init (FILE *asm_file, char *input_file_name);
extern void dbxout_symbol (tree decl, int local);
extern void dbxout_types (tree types);
extern void dbxout_tags (tree tags);
extern void dbxout_function (tree decl);

/* in final.c */
extern void init_final (char *filename);
extern void end_final (char *filename);
extern void app_enable (void);
extern void app_disable (void);
extern int dbr_sequence_length (void);
extern void final_start_function (rtx first, FILE *file, enum debugger write_symbols, int optimize);
extern void profile_function (FILE *file);
extern void final_end_function (rtx first, FILE *file, enum debugger write_symbols, int optimize);
extern void final (rtx first, FILE *file, enum debugger write_symbols, int optimize, int prescan);
extern rtx final_scan_insn  (rtx insn, FILE *file, enum debugger write_symbols, int optimize, int prescan, int nopeepholes);
extern void set_current_gdbfile (char *filename);


extern int yyparse(void);	/* in cexp.c */
extern void output_inline_function (tree fndecl);	/* in integrate.c */

extern tree get_permanent_types (void);
#else
#include "prototypes.h"
#endif

#endif	/* _TOPLEV_H_ */
