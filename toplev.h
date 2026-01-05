#ifndef _TOPLEV_H_
#define _TOPLEV_H_

extern int gettime(void);
extern void print_time(const char* str, int total);
extern int count_error(int warningp);
extern void pfatal_with_name(const char* name);
extern void fatal_io_error(const char* name);
extern void fatal (const char *format, ... ) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void fatal_insn_not_found(rtx insn);
extern void announce_function(tree decl);
extern void report_error_function(const char* file);
extern void error( const char *format, ... ) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void error_with_file_and_line (const char *file, int line, const char *fmt, ... ) __attribute__ ((__format__ (__printf__, 3, 0)));
extern void verror_with_file_and_line (const char *file, int line, const char *format, va_list ap);
extern void error_with_decl (tree decl, const char *format, ...);
extern void error_for_asm (rtx insn, const char *fmt, ...) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void warning (const char *format, ...) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void warning_with_file_and_line (const char *file, int line, const char *format, ...) __attribute__ ((__format__ (__printf__, 3, 0)));
extern void vwarning_with_file_and_line (const char *file, int line, const char *format, va_list ap);
extern void warning_with_decl (tree decl, const char *format, ... );
extern void warning_for_asm (rtx insn, const char *fmt, ...) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void sorry (const char *format, ...) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void really_sorry (const char *format, ...)  __attribute__ ((__format__ (__printf__, 1, 0)));
extern void fancy_abort(void);
extern void botch(const char* msg);
extern void* xmalloc(unsigned int size);
extern void* xrealloc(void* ptr, unsigned int size);
extern int exact_log2(unsigned int x);
extern int floor_log2( unsigned int x);
extern void set_float_handler(jmp_buf handler);
extern void rest_of_decl_compilation(tree decl, char* asmspec, int top_level, int at_end);
extern void rest_of_compilation(tree decl);
extern void set_target_switch(char* name);
extern void print_target_switch_defaults(void);

#endif /* _TOPLEV_H_ */
