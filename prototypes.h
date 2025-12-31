#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_ 1

#define POINTER_DEF
#ifdef X3J11
typedef void    *pointer;               /* generic pointer type */
#else
typedef char    *pointer;               /* generic pointer type */
#endif

#define U_CHAR_DEF
typedef unsigned char U_CHAR;

#define FILE_BUF_DEF
typedef struct file_buf {
  char *fname;
  int lineno;
  int length;
  U_CHAR *buf;
  U_CHAR *bufp;
  /* Macro that this level is the expansion of.
     Included so that we can reenable the macro
     at the end of this level.  */
  struct hashnode *macro;
  /* Value of if_stack at start of this file.
     Used to prohibit unmatched #endif (etc) in an include file.  */
  struct if_stack *if_stack;
  /* Object to be freed at end of input at this level.  */
  U_CHAR *free_ptr;
} FILE_BUF;

#define DEFINITION_DEF
typedef struct definition {
  int nargs;
  int length;                   /* length of expansion string */
  U_CHAR *expansion;
  struct reflist {
    struct reflist *next;
    char stringify;             /* nonzero if this arg was preceded by a
                                   # operator. */
    char raw_before;            /* Nonzero if a ## operator before arg. */
    char raw_after;             /* Nonzero if a ## operator after arg. */
    int nchars;                 /* Number of literal chars to copy before
                                   this arg occurrence.  */
    int argno;                  /* Number of arg to substitute (origin-0) */
  } *pattern;
  /* Names of macro args, concatenated in reverse order
     with comma-space between them.
     The only use of this is that we warn on redefinition
     if this differs between the old and new definitions.  */
  U_CHAR *argnames;
} DEFINITION;

#define HASHMODE_DEF
/* different kinds of things that can appear in the value field
   of a hash node.  Actually, this may be useless now. */
union hashval {
  int ival;
  char *cpval;
  DEFINITION *defn;
};


/* The structure of a node in the hash table.  The hash table
   has entries for all tokens defined by #define commands (type T_MACRO),
   plus some special tokens like __LINE__ (these each have their own
   type, and the appropriate code is run when that type of node is seen.
   It does not contain control words like "#define", which are recognized
   by a separate piece of code. */

/* different flavors of hash nodes --- also used in keyword table */
enum node_type {
 T_DEFINE = 1,  /* the `#define' keyword */
 T_INCLUDE,     /* the `#include' keyword */
 T_IFDEF,       /* the `#ifdef' keyword */
 T_IFNDEF,      /* the `#ifndef' keyword */
 T_IF,          /* the `#if' keyword */
 T_ELSE,        /* `#else' */
 T_PRAGMA,      /* `#pragma' */
 T_ELIF,        /* `#else' */
 T_UNDEF,       /* `#undef' */
 T_LINE,        /* `#line' */
 T_ERROR,       /* `#error' */
 T_ENDIF,       /* `#endif' */
 T_SCCS,        /* `#sccs', used on system V.  */
 T_IDENT,       /* `#ident', used on system V.  */
 T_SPECLINE,    /* special symbol `__LINE__' */
 T_DATE,        /* `__DATE__' */
 T_FILE,        /* `__FILE__' */
 T_BASE_FILE,   /* `__BASE_FILE__' */
 T_INCLUDE_LEVEL, /* `__INCLUDE_LEVEL__' */
 T_VERSION,     /* `__VERSION__' */
 T_TIME,        /* `__TIME__' */
 T_CONST,       /* Constant value, used by `__STDC__' */
 T_MACRO,       /* macro defined by `#define' */
 T_DISABLED,    /* macro temporarily turned off for rescan */
 T_SPEC_DEFINED, /* special `defined' macro for use in #if statements */
 T_UNUSED       /* Used for something not defined.  */
 };
typedef struct hashnode {
  struct hashnode *next;        /* double links for easy deletion */
  struct hashnode *prev;
  struct hashnode **bucket_hdr; /* also, a back pointer to this node's hash
                                   chain is kept, in case the node is the head
                                   of the chain and gets deleted. */
  enum node_type type;          /* type of special token */
  int length;                   /* length of token, for quick comparison */
  U_CHAR *name;                 /* the actual name */
  union hashval value;          /* pointer to expansion, or whatever */
} HASHNODE;

#define DIRECTIVE_DEF
typedef struct directive {
  int length;                   /* Length of name */
  int (*func)();                /* Function to handle directive */
  char *name;                   /* Name of directive */
  enum node_type type;          /* Code which describes which directive. */
  char angle_brackets;          /* Nonzero => <...> is special.  */
  char traditional_comments;    /* Nonzero: keep comments if -traditional.  */
  char pass_thru;               /* Copy preprocessed directive to output file.  */
} DIRECTIVE;

#define FILE_CHANGE_ENUM_DEF
enum file_change_code {same_file, enter_file, leave_file};

/* From alloca.c */
pointer alloca(unsigned size);

/* From caller-save.c */
void save_call_clobbered_regs(void);

/* From cccp.c */
/* int main(int argc, char** argv); */
void trigraph_pcp(FILE_BUF* buf);
void newline_fix(U_CHAR* bp);
void name_newline_fix(U_CHAR* bp);
int rescan(FILE_BUF* op, int output_marks);
FILE_BUF expand_to_temp_buffer(U_CHAR* buf, U_CHAR* limit, int output_marks);
int handle_directive(FILE_BUF* ip, FILE_BUF* op);
void special_symbol(HASHNODE* hp, FILE_BUF* op);
void do_include(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
void finclude(int f, char* fname, FILE_BUF* op);
int do_define(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
int compare_defs(DEFINITION* d1, DEFINITION* d2);
int comp_def_part(int first, U_CHAR* beg1, int len1, U_CHAR* beg2, int len2, int last);
DEFINITION* collect_expansion(U_CHAR* buf, U_CHAR* end, int nargs, struct arglist);
void do_line(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
void do_undef(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
void do_error(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
void do_once(void);
void do_pragma(U_CHAR* buf, U_CHAR* limit);
void do_sccs(void);
void do_if(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
int do_elif(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
int eval_if_expression(U_CHAR* buf, int length);
int do_xifdef(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
void conditional_skip(FILE_BUF* ip, int skip, enum node_type type);
void skip_if_group(FILE_BUF* ip, int any);
void do_else(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
void do_endif(U_CHAR* buf, U_CHAR* limit, FILE_BUF* op, struct directive* keyword);
int validate_else( U_CHAR* p);
U_CHAR* skip_to_end_of_comment( FILE_BUF* ip, int* line_counter);
U_CHAR* skip_quoted_string( U_CHAR* bp,  U_CHAR* limit, int start_line, int* count_newlines, int* backslash_newlines_p, int* eofp);
void output_line_command(FILE_BUF* ip, FILE_BUF* op, int conditional, enum file_change_code file_change);
void macroexpand(HASHNODE* hp, FILE_BUF* op);
char* macarg( struct argdata* argptr);
U_CHAR* macarg1(U_CHAR* start,  U_CHAR* limit, int* depthptr, int* newlines, int* comments);
int discard_comments(U_CHAR* start, int length, int newlines);
int error(char* msg, int arg1, int arg2, int arg3);
int error_from_errno(char* name);
int warning(char* msg, int arg1, int arg2, int arg3);
int error_with_line(int line, char* msg, int arg1, int arg2, int arg3);
int line_for_error(int line);
int grow_outbuf( FILE_BUF* obuf,  int needed);
HASHNODE* install(U_CHAR* name, int len, enum node_type type, int value, int hash);
HASHNODE* lookup(U_CHAR* name, int len, int hash);
int delete_macro(HASHNODE* hp);
int hashf( U_CHAR* name,  int len, int hashsize);
void dump_all_macros(void);
void dump_defn_1(U_CHAR* base, int start, int length);
void dump_arg_n(DEFINITION* defn, int argnum);
void initialize_char_syntax(void);
void initialize_builtins(void);
void make_definition(U_CHAR* str);
void make_undef(U_CHAR* str);
int deps_output(char* string, int size);
/* void bzero( char* b,  int length); */
/* void bcopy( char* b1,  char* b2,  int length); */
/* int bcmp( char* b1,  char* b2,  int length); */
void fatal(char* str, char* arg);
void fancy_abort(void);
void perror_with_name(char* name);
void pfatal_with_name(char* name);
void memory_full(void);
char* xmalloc(int size);
char* xrealloc(char* old, int size);
char* xcalloc(int number, int size);
char* savestring(char* input);
int file_size_and_mode(int fd, int* mode_pointer, long int* size_pointer);
int hack_vms_include_specification(char* fname);
int read(int fd, char* buf, int size);
int write(int fd, char* buf, int size);

/* From c-convert.c */
tree convert(tree type, tree expr);

/* From c-decl.c */
int lang_decode_option(char* p);
void print_lang_identifier(FILE* file, tree node, int indent);
int global_bindings_p(void);
void keep_next_level(void);
int kept_level_p(void);
void declare_parm_level(void);
int in_parm_level_p(void);
void pushlevel(int tag_transparent);
tree poplevel(int keep, int reverse, int functionbody);
void pushtag(tree name, tree type);
tree pushdecl(tree x);
tree implicitly_declare(tree functionid);
tree lookup_label(tree id);
tree define_label(char* filename, int line, tree name);
tree getdecls(void);
tree gettags(void);
tree lookup_name(tree name);
void init_decl_processing(void);
void shadow_tag(tree declspecs);
tree groktypename(tree typename);
tree start_decl(tree declarator, tree declspecs, int initialized);
void finish_decl(tree decl, tree init, tree asmspec_tree);
void push_parm_decl(tree parm);
int complete_array_type(tree type, tree initial_value, int do_default);
tree c_build_type_variant(tree type, int constp, int volatilep);
tree get_parm_info(int void_at_end);
void parmlist_tags_warning(void);
tree xref_tag(enum tree_code code, tree name);
tree start_struct(enum tree_code code, tree name);
tree grokfield(char* filename, int line, tree declarator, tree declspecs, tree width);
tree finish_struct(register tree t, register tree fieldlist);
tree start_enum(tree name);
tree finish_enum(register tree enumtype, register tree values);
tree build_enumerator(tree name, tree value);
int start_function(tree declspecs, tree declarator);
void store_parm_decls(void);
void finish_function(int lineno);

/* From cexp.c */
int yyparse(void);
int parse_number(int olen);
int yylex(void);
int parse_escape(char** string_ptr);
void yyerror(char* s);
int parse_c_expression(char* string);
#if 0
int main(void);
int initialize_random_junk(void);
int error(msg);
int warning(msg);
int lookup(char* name, int len, int hash);
#endif

/* From combine.c */
void combine_instructions(rtx f, int nregs);
int regno_dead_p(int regno, rtx insn);
void remove_death(int regno, rtx insn);
void dump_combine_stats(FILE* file);
void dump_combine_total_stats(FILE* file);

/* From c-parse.tab.c */
int yyparse(void);
__inline static int hash(register char* str, register int len);
__inline struct resword* is_reserved_word(register char* str, register int len);
void init_lex(void);
int check_newline(void);

/* From cross_gnulib.c */
unsigned long __umulsi3(unsigned long a, unsigned long b);

/* From cse.c */
int refers_to_p(rtx x, rtx y);
int refers_to_mem_p(rtx x, rtx reg, int start, int end);
int cse_main(rtx f, int nregs);

/* From c-typeck.c */
tree datatype(tree node);
tree require_complete_type(tree value);
void incomplete_type_error(tree value, tree type);
tree commontype(tree t1, tree t2);
int comptypes(tree type1, tree type2);
int comp_target_types(tree ttl, tree ttr);
int compparms1(tree parms);
tree unsigned_type(tree type);
tree signed_type(tree type);
tree signed_or_unsigned_type(int unsignedp, tree type);
tree type_for_size(int bits, int unsignedp);
tree get_floating_type(enum machine_mode mode);
tree c_sizeof(tree type);
tree c_sizeof_nowarn(tree type);
tree c_alignof(tree type);
tree default_conversion(tree exp);
tree build_component_ref(tree datum, tree component);
tree build_indirect_ref(tree ptr, char* errorstring);
tree build_array_ref(tree array, tree index);
tree build_function_call(tree function, tree params);
tree actualparameterlist(tree typelist, tree values, tree name);
tree build_binary_op(enum tree_code code, tree arg1, tree arg2);
tree build_binary_op_nodefault(enum tree_code code, tree op0, tree op1, enum tree_code error_code);
tree build_unary_op(enum tree_code code, tree xarg, int noconvert);
void readonly_warning(tree arg, char* string);
tree truthvalue_conversion(tree expr);
int mark_addressable(tree exp);
tree build_conditional_expr(tree ifexp, tree op1, tree op2);
tree build_compound_expr(tree list);
tree build_c_cast(register tree type, tree expr);
tree build_modify_expr(tree lhs, enum tree_code modifycode, tree rhs);
int language_lvalue_valid(tree exp);
void store_init_value(tree decl, tree init);
tree digest_init(tree type, tree init, tree tail);
void c_expand_asm_operands(tree string, tree outputs, tree inputs, tree clobbers, int vol, char* filename, int line);
void c_expand_return(tree retval);
tree c_expand_start_case(tree exp);

/* From dbranch.c */
void dbr_schedule(rtx f, FILE* dump_file);

/* From dbxout.c */
void dbxout_init(FILE* asm_file, char* input_file_name);
void dbxout_symbol(tree decl, int local);
void dbxout_args(tree args);
void dbxout_types(register tree types);
void dbxout_tags(tree tags);
void dbxout_function(tree decl);
void dbxout_init(FILE* asm_file, char* input_file_name);

/* From emit-rtl.c */
rtx gen_rtx(int va_alist);
rtvec gen_rtvec(int va_alist);
rtvec gen_rtvec_v(int n, rtx* argp);
rtx gen_reg_rtx(enum machine_mode mode);
void mark_reg_pointer(rtx reg);
int max_reg_num(void);
int max_label_num(void);
int get_first_label_num(void);
rtx gen_lowpart(enum machine_mode mode, register rtx x);
rtx gen_highpart(enum machine_mode mode, register rtx x);
int subreg_lowpart_p(rtx x);
rtx change_address(rtx memref, enum machine_mode mode, rtx addr);
rtx gen_label_rtx(void);
rtx gen_inline_header_rtx(rtx insn, rtx last_insn, int first_labelno, int last_labelno, int max_parm_regnum, int max_regnum, int args_size, rtx stack_slots);
void set_new_first_and_last_insn(rtx first, rtx last);
void unshare_all_rtl(register rtx insn);
rtx make_safe_from(rtx x, rtx other);
rtx get_insns(void);
rtx get_last_insn(void);
void set_last_insn(rtx insn);
int get_max_uid(void);
rtx next_insn(rtx insn);
rtx previous_insn(rtx insn);
void delete_insns_since(rtx from);
void reorder_insns(rtx from, rtx to, rtx after);
rtx emit_insn_before(register rtx pattern, register rtx before);
rtx emit_jump_insn_before(register rtx pattern, register rtx before);
rtx emit_call_insn_before(register rtx pattern, register rtx before);
rtx emit_insn_after(register rtx pattern, register rtx after);
rtx emit_jump_insn_after(register rtx pattern, register rtx after);
rtx emit_barrier_after(register rtx after);
void emit_label_after(rtx label, rtx after);
void emit_note_after(int subtype, rtx after);
rtx emit_insn(rtx pattern);
rtx emit_insns(rtx insn);
rtx emit_jump_insn(rtx pattern);
rtx emit_call_insn(rtx pattern);
rtx emit_label(rtx label);
rtx emit_barrier(void);
rtx emit_line_note(char* file, int line);
rtx emit_note(char* file, int line);
rtx emit_line_note_force(char* file, int line);
void force_next_line_note(void);
int classify_insn(rtx x);
void emit(rtx x);
rtx start_sequence(void);
void push_to_sequence(rtx first);
void end_sequence(rtx saved);
rtx gen_sequence(void);
void restore_reg_data(rtx first);
void init_emit(int write_symbols);
void init_emit_once(void);

/* From explow.c */
rtx plus_constant(register rtx x, register int c);
rtx eliminate_constant_term(rtx x, int* constptr);
rtx expr_size(tree exp);
rtx lookup_static_chain(rtx context);
rtx copy_all_regs(register rtx x);
rtx memory_address(enum machine_mode mode, register rtx x);
rtx memory_address_noforce(enum machine_mode mode, rtx x);
rtx stabilize(rtx x);
rtx copy_to_reg(rtx x);
rtx copy_addr_to_reg(rtx x);
rtx copy_to_mode_reg(enum machine_mode mode, rtx x);
rtx force_reg(enum machine_mode mode, rtx x);
rtx force_not_mem(rtx x);
rtx copy_to_suggested_reg(rtx x, rtx target);
void adjust_stack(rtx adjust);
void anti_adjust_stack(rtx adjust);
rtx round_push(rtx size);
rtx hard_function_value(tree valtype, tree func);
rtx hard_libcall_value(enum machine_mode mode);

/* From expmed.c */
rtx negate_rtx(enum machine_mode mode, rtx x);
rtx store_bit_field(rtx str_rtx, register int bitsize, int bitnum, enum machine_mode fieldmode, rtx value, int align, int total_size);
rtx extract_bit_field(rtx str_rtx, register int bitsize, int bitnum, int unsignedp, rtx target, enum machine_mode mode, enum machine_mode tmode, int align, int total_size);
void expand_inc(rtx target, rtx inc);
void expand_dec(rtx target, rtx dec);
rtx expand_shift(enum tree_code code, register enum machine_mode mode, rtx shifted, tree amount, register rtx target, int unsignedp);
rtx expand_bit_and(enum machine_mode mode, rtx op0, rtx op1, rtx target);
rtx expand_mult(enum machine_mode mode, register rtx op0, register rtx op1, register rtx target, int unsignedp);
rtx expand_divmod(int rem_flag, enum tree_code code, enum machine_mode mode, register rtx op0, register rtx op1, register rtx target, int unsignedp);
rtx expand_mult_add(rtx x, rtx mult, rtx add, enum machine_mode mode, int unsignedp);

/* From expr.c */
void init_comparisons(void);
void init_expr(void);
rtx protect_from_queue(register rtx x, int modify);
void emit_queue(void);
void convert_move(register rtx to, register rtx from, int unsignedp);
rtx convert_to_mode(enum machine_mode mode, rtx x, int unsignedp);
int integer_mode_p(enum machine_mode mode);
void move_block_from_reg(int regno, rtx x, int nregs);
void clear_storage(rtx object, int size);
rtx emit_move_insn(rtx x, rtx y);
rtx push_block(rtx size, int extra);
void emit_library_call(int va_alist);
rtx expand_assignment(tree to, tree from, int want_value, int suggest_reg);
rtx store_expr(register tree exp, register rtx target, int suggest_reg);
rtx force_operand(rtx value, rtx target);
rtx expand_expr(register tree exp, rtx target, enum machine_mode tmode, enum expand_modifier modifier);
void init_pending_stack_adjust(void);
void clear_pending_stack_adjust(void);
void do_pending_stack_adjust(void);
void jumpifnot(tree exp, rtx label);
void jumpif(tree exp, rtx label);
void do_jump(tree exp, rtx if_false_label, rtx if_true_label);
void do_tablejump(rtx index, rtx range, rtx table_label, rtx default_label);

/* From final.c */
void init_final(char* filename);
void end_final(char* filename);
void app_enable(void);
void app_disable(void);
int dbr_sequence_length(void);
void final_start_function(rtx first, FILE* file, enum debugger write_symbols, int optimize);
void profile_function(FILE* file);
void final_end_function(rtx first, FILE* file, enum debugger write_symbols, int optimize);
void final(rtx first, FILE* file, enum debugger write_symbols, int optimize, int prescan);
rtx final_scan_insn(rtx insn, FILE* file, enum debugger write_symbols, int optimize, int prescan, int nopeepholes);
void set_current_gdbfile(char* filename);
rtx alter_subreg(register rtx x);
void output_asm_insn(char* template, rtx* operands);
void output_asm_label(rtx x);
void output_address(rtx x);
void output_addr_const(FILE* file, rtx x);

/* From flow.c */
void flow_analysis(rtx f, int nregs, FILE* file);
void allocate_for_life_analysis(void);
int regno_uninitialized(int regno);
int regno_clobbered_at_setjmp(int regno);
void dump_flow_info(FILE* file);

/* From fold-const.c */
tree combine(enum tree_code code, register tree arg1, register tree arg2);
tree fold(tree expr);

/* From gcc.c */
void clear_args(void);
void store_arg(char* arg, int delete_always, int delete_failure);
void record_temp_file(char* filename, int always_delete, int fail_delete);
void delete_temp_files(void);
void delete_failure_queue(void);
void clear_failure_queue(void);
void choose_temp_base(void);
int execute(void);
void process_command(int argc, char** argv);
int do_spec(char* spec);
int do_spec_1(char* spec, int inswitch);
void give_switch(int switchnum);
char* find_file(char* name);
#if 0
void fatal_error(int signum);
int main(int argc, char** argv);
int xmalloc(int size);
int xrealloc(int ptr, int size);
char* concat(char* s1, char* s2, char* s3);
char* save_string(char* s, int len);
void pfatal_with_name(char* name);
void perror_with_name(char* name);
void perror_exec(char* name);
void fancy_abort(void);
int fatal(int va_alist);
void error(int va_alist);
int fatal(char* msg, char* arg1, char* arg2);
int error(char* msg, char* arg1, char* arg2);
void validate_all_switches(void);
#endif

/* From gcc_etrc.c */
#if 0
void clear_args(void);
void store_arg(char* arg, int delete_always, int delete_failure);
void record_temp_file(char* filename, int always_delete, int fail_delete);
void delete_temp_files(void);
void delete_failure_queue(void);
void clear_failure_queue(void);
void choose_temp_base(void);
int execute(void);
void process_command(int argc, char** argv);
int do_spec(char* spec);
int do_spec_1(char* spec, int inswitch);
int give_switch(int switchnum);
char* find_file(char* name);
void fatal_error(int signum);
/* int main(int argc, char** argv); */
void *xmalloc(unsigned int size);
void *xrealloc(void *ptr, int size);
char* concat(char* s1, char* s2, char* s3);
char* save_string(char* s, int len);
int pfatal_with_name(char* name);
int perror_with_name(char* name);
int perror_exec(char* name);
void fancy_abort(void);
int fatal(int va_alist);
int error(int va_alist);
int fatal(char* msg, char* arg1, char* arg2);
int error(char* msg, char* arg1, char* arg2);
void validate_all_switches(void);
#endif

/* From gencodes.c */
void gen_insn(rtx insn);
int xmalloc(size);
int xrealloc(char* ptr, int size);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
int main(int argc, char** argv);

/* From genconfig.c */
void walk_insn_part(rtx part);
void gen_insn(rtx insn);
void gen_expand(rtx insn);
void gen_peephole(rtx peep);
int xmalloc(size);
int xrealloc(char* ptr, int size);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
int main(int argc, char** argv);

/* From genemit.c */
void max_operand_1(rtx x);
int max_operand_vec(rtx insn, int arg);
void print_code(RTX_CODE code);
void gen_exp(rtx x);
void gen_insn(rtx insn);
void gen_expand(rtx expand);
int xmalloc(size);
int xrealloc(char* ptr, int size);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
int main(int argc, char** argv);

/* From genextract.c */
void gen_insn(rtx insn);
void gen_peephole(rtx peep);
void walk_rtx(rtx x, struct link* path);
void print_path(struct link* path);
int xmalloc(size);
int xrealloc(char* ptr, int size);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
int main(int argc, char** argv);

/* From genflags.c */
void gen_insn(rtx insn);
int xmalloc(size);
int xrealloc(char* ptr, int size);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
int main(int argc, char** argv);

/* From genoutput.c */
void output_prologue(void);
void output_epilogue(void);
void scan_operands(rtx part, int this_address_p, int this_strict_low);
void gen_insn(rtx insn);
void gen_peephole(rtx peep);
void gen_expand(rtx insn);
int xmalloc(size);
int xrealloc(char* ptr, int size);
void mybzero(register char* b, register int length);
void mybcopy(register char* b1, register char* b2, register int length);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
void error(char* s, int a1, int a2);
int main(int argc, char** argv);
int n_occurrences(char c, char* s);

/* From genpeep.c */
void gen_peephole(rtx peep);
void match_rtx(rtx x, struct link* path, int fail_label);
void print_path(struct link* path);
void print_code(RTX_CODE code);
int xmalloc(size);
int xrealloc(char* ptr, int size);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
int main(int argc, char** argv);

/* From genrecog.c */
int make_insn_sequence(rtx insn);
int add_to_sequence(rtx pattern, struct decision* last, char* position);
int merge_trees(register struct decision* old, register struct decision* add);
int try_merge_1(register struct decision* old, register struct decision* add);
int try_merge_2(struct decision* old, struct decision* add);
int no_same_mode(struct decision* node);
int break_out_subroutines(struct decision* node);
void write_subroutine(struct decision* tree);
void write_tree(struct decision* tree, char* prevpos, int afterward, char* afterpos, int initial);
void print_code(RTX_CODE code);
int same_codes(register struct decision* p, register RTX_CODE code);
void clear_codes(register struct decision* p);
int same_modes(register struct decision* p, register enum machine_mode mode);
void clear_modes(register struct decision* p);
void change_state(char* oldpos, char* newpos);
char* copystr(char* s1);
void mybzero(register char* b, register int length);
char* concat(char* s1, char* s2);
int xrealloc(char* ptr, int size);
int xmalloc(size);
void fatal(char* s, int a1, int a2);
void fancy_abort(void);
int main(int argc, char** argv);

/* From global-alloc.c */
void global_alloc(FILE* file);
void retry_global_alloc(int regno, short* forbidden_regs);
int check_frame_pointer_required(rtx* reg_equiv_constant, rtx* reg_equiv_mem, rtx* reg_equiv_address);
void dump_global_regs(FILE* file);

/* From gnulib2.c */
long long __adddi3(long long u, long long v);
long long __anddi3(long long u, long long v);
long long __iordi3(long long u, long long v);
long long __xordi3(long long u, long long v);
long long __one_cmpldi2(long long u);
long long __lshldi3(long long u, long long b1);
long long __lshrdi3(long long u, long long b1);
long long __ashldi3(long long u, long long b1);
long long __ashrdi3(long long u, long long b1);
long long __subdi3(long long u, long long v);
long long __muldi3(long long u, long long v);
long long __divdi3(long long u, long long v);
long long __moddi3(long long u, long long v);
long long __udivdi3(long long u, long long v);
long long __umoddi3(long long u, long long v);
long long __negdi2(long long u);
void __bdiv(unsigned short* a, unsigned short* b, unsigned short* q, unsigned short* r, size_t m, size_t n);
SItype __cmpdi2(long long a, long long b);
SItype __ucmpdi2(long long a, long long b);
long long __fixunsdfdi(double a);
long long __fixdfdi(double a);
double __floatdidf(long long u);
int __builtin_saveregs(void);

/* From gnulib.c */
void __eprintf(char* string, char* expression, int line, char* filename);
SItype __umulsi3(unsigned SItype a, unsigned SItype b);
SItype __mulsi3(SItype a, SItype b);
SItype __udivsi3(unsigned SItype a, unsigned SItype b);
SItype __divsi3(SItype a, SItype b);
SItype __umodsi3(unsigned SItype a, unsigned SItype b);
SItype __modsi3(SItype a, SItype b);
SItype __lshrsi3(unsigned SItype a, unsigned SItype b);
SItype __lshlsi3(unsigned SItype a, unsigned SItype b);
SItype __ashrsi3(SItype a, SItype b);
SItype __ashlsi3(SItype a, SItype b);
double __divdf3(double a, double b);
double __muldf3(double a, double b);
double __negdf2(double a);
double __adddf3(double a, double b);
double __subdf3(double a, double b);
SItype __cmpdf2(double a, double b);
SItype __fixunsdfsi(double a);
SItype __fixdfsi(double a);
double __floatsidf(SItype a);
SFVALUE __addsf3(FLOAT_ARG_TYPE a, FLOAT_ARG_TYPE b);
SFVALUE __negsf2(FLOAT_ARG_TYPE a);
SFVALUE __subsf3(FLOAT_ARG_TYPE a, FLOAT_ARG_TYPE b);
SItype __cmpsf2(FLOAT_ARG_TYPE a, FLOAT_ARG_TYPE b);
SFVALUE __mulsf3(FLOAT_ARG_TYPE a, FLOAT_ARG_TYPE b);
SFVALUE __divsf3(FLOAT_ARG_TYPE a, FLOAT_ARG_TYPE b);
SFVALUE __truncdfsf2(double a);
double __extendsfdf2(FLOAT_ARG_TYPE a);
int __bb_init_func(struct bb* blocks);
char* __builtin_new(long sz);
vfp __set_new_handler(vfp handler);
vfp set_new_handler(vfp handler);
void __builtin_delete(char* ptr);

/* From hard-params.c */
int setjmp(int lab);

/* From hello.c */
int main(void);

/* From integrate.c */
char* function_cannot_inline_p(register tree fndecl);
void save_for_inline(tree fndecl);
rtx expand_inline_function(tree fndecl, tree parms, rtx target, int ignore, tree type, rtx structure_value_addr);
void output_inline_function(tree fndecl);

/* From jump.c */
void jump_optimize(rtx f, int cross_jump, int noop_moves);
int simplejump_p(rtx insn);
int condjump_p(rtx insn);
int sets_cc0_p(rtx x);
int no_labels_between_p(rtx beg, rtx end);
rtx prev_real_insn(rtx label);
rtx next_real_insn(rtx label);
rtx next_label(rtx insn);
rtx delete_insn(register rtx insn);
rtx next_nondeleted_insn(rtx insn);
void delete_for_peephole(register rtx from, register rtx to);
void invert_jump(rtx jump, rtx nlabel);
void invert_exp(rtx x, rtx olabel, rtx nlabel);
void redirect_jump(rtx jump, rtx nlabel);
int rtx_renumbered_equal_p(rtx x, rtx y);
int true_regnum(rtx x);

/* From local-alloc.c */
void local_alloc(void);
void dump_local_alloc(FILE* file);

/* From loop.c */
void loop_optimize(rtx f, FILE* dumpfile);
int loop_skip_over(rtx start, rtx end, rtx loop_entry_jump);
int addr_overlap_p(rtx other, rtx base, int size);
int other_reg_use_p(register rtx reg, register rtx expr, register rtx in);

/* From masm386.c */
int add_to_implicit_list(tree t);
int write_implicit_declares(void);
void asm_write_decls(tree decls, int toplevel);
void mark_name_used(char* name);
int asm_output_labelref(int file, char* name);
void asm_library_declare(rtx fun);

/* From mkproto.c */

/* From obstack.c */
void _obstack_begin(void* inpH, int size, int alignment, POINTER* chunkfun* freefun);
void _obstack_newchunk(void* inpH, int length);
int _obstack_allocated_p(struct obstack* h, POINTER obj);
void obstack_free(struct obstack* h, POINTER obj h, obj);
void _obstack_free(struct obstack* h, POINTER obj);
int POINTER(int obstack_base, struct obstack);
int POINTER(int obstack_next_free, struct obstack);
int ( obstack_object_size )(struct obstack);
int ( obstack_room )(struct obstack);
void ( obstack_grow )(struct obstack, POINTER pointer, int length);
void ( obstack_grow0 )(struct obstack, POINTER pointer, int length);
void ( obstack_1grow )(struct obstack, int character);
void ( obstack_blank )(struct obstack, int length);
void ( obstack_1grow_fast )(struct obstack, int character);
void ( obstack_blank_fast )(struct obstack, int length);
int POINTER(int obstack_finish, struct obstack);
int POINTER(int obstack_alloc, struct obstack, int length);
int POINTER(int obstack_copy, struct obstack, POINTER pointer, int length);
int POINTER(int obstack_copy0, struct obstack, POINTER pointer, int length);

/* From optabs.c */
rtx expand_binop(enum machine_mode mode, optab binoptab, rtx op0, rtx op1, rtx target, int unsignedp, enum optab_methods methods);
rtx sign_expand_binop(enum machine_mode mode, optab uoptab, optab soptab, rtx op0, rtx op1, rtx target, int unsignedp, enum optab_methods methods);
int expand_twoval_binop(optab binoptab, rtx op0, rtx op1, rtx targ0, rtx targ1, int unsignedp);
int expand_twoval_binop_convert(register optab binoptab, int mode, register rtx op0, register rtx op1, register rtx targ0, register rtx targ1, int unsignedp);
rtx expand_unop(enum machine_mode mode, optab unoptab, rtx op0, rtx target, int unsignedp);
void emit_unop_insn(int icode, rtx target, rtx op0, enum rtx_code code);
void emit_clr_insn(rtx x);
void emit_0_to_1_insn(rtx x);
void emit_cmp_insn(rtx x, rtx y, rtx size, int unsignedp, int align);
rtx gen_add2_insn(rtx x, rtx y);
int have_add2_insn(enum machine_mode mode);
rtx gen_sub2_insn(rtx x, rtx y);
int have_sub2_insn(enum machine_mode mode);
rtx gen_move_insn(rtx x, rtx y);
rtx gen_extend_insn(rtx x, rtx y, enum machine_mode mto, enum machine_mode mfrom, int unsignedp);
void init_fixtab(void);
void init_floattab(void);
void expand_float(rtx real_to, rtx from, int unsignedp);
void expand_fix(register rtx to, register rtx from, int unsignedp);
void init_optabs(void);

/* From packtest.c */
int main(void);

/* From pragma.c */
void pragma_pack(int val);
int pragma_align_val(void);
void pragma_pack_default(void);
int pragma_pack_seen(void);

/* From print-self1.c */
int main(a);

/* From print-self.c */
int main(void);

/* From print-tree.c */
void debug_tree(tree node);
void print_node_brief(FILE* file, char* prefix, tree node, int indent);
void indent_to(FILE* file, int column);
void print_node(FILE* file, char* prefix, tree node, int indent);

/* From prtst.c */
int fred(void);

/* From p_sdbout.c */
void sdbout_filename(FILE* asm_file, char* input_name);
void sdbout_init(void);
void sdbout_symbol(tree decl, int local);
void sdbout_tags(tree tags);
void sdbout_types(register tree types);
void sdbout_begin_block(FILE* file, int line, int n);
void sdbout_end_block(FILE* file, int line);
void sdbout_mark_begin_function(void);
void sdbout_begin_function(int line);
void sdbout_end_function(int line);
void sdbout_end_epilogue(void);

/* From recog.c */
void init_recog(void);
int recog_memoized(rtx insn);
int next_insn_tests_no_inequality(rtx insn);
int next_insns_test_no_inequality(rtx insn);
int general_operand(register rtx op, enum machine_mode mode);
int address_operand(register rtx op, enum machine_mode mode);
int register_operand(register rtx op, enum machine_mode mode);
int immediate_operand(register rtx op, enum machine_mode mode);
int nonimmediate_operand(register rtx op, enum machine_mode mode);
int nonmemory_operand(register rtx op, enum machine_mode mode);
int push_operand(rtx op, enum machine_mode mode);
int memory_address_p(enum machine_mode mode, register rtx addr);
int memory_operand(register rtx op, enum machine_mode mode);
int indirect_operand(register rtx op, enum machine_mode mode);
int asm_noperands(rtx body);
char* decode_asm_operands(rtx body, rtx* operands, rtx** operand_locs, char** constraints, enum machine_mode* modes);
int offsettable_memref_p(rtx op);
int offsettable_address_p(int strictp, enum machine_mode mode, register rtx y);
int mode_dependent_address_p(rtx addr);
int mode_independent_operand(rtx op, enum machine_mode mode);
rtx adj_offsettable_operand(rtx op, int offset);
int constrain_operands(int insn_code_num);
int reg_fits_class_p(rtx operand, register enum reg_class class, int offset, enum machine_mode mode);

/* From regclass.c */
void init_reg_sets(void);
void init_reg_sets_1(void);
void fix_register(char* name, int fixed, int call_used);
int reg_preferred_class(int regno);
int reg_preferred_or_nothing(regno);
int regclass_init(void);
void regclass(rtx f, int nregs);
void reg_class_record(rtx op, int opno, char** constraints);
void record_address_regs(rtx x, int bcost, int icost);
void reg_scan(rtx f, int nregs, int repeat);
void reg_scan_mark_refs(rtx x, int uid);

/* From reload1.c */
void reload(rtx first, int global, FILE* dumpfile);
void mark_home_live(int regno);

/* From reload.c */
int strict_memory_address_p(enum machine_mode mode, register rtx addr);
int operands_match_p(register rtx x, register rtx y);
void find_reloads(rtx insn, int replace, int ind_ok, int live_known, short* reload_reg_p);
void subst_reloads(void);
rtx find_equiv_reg(register rtx goal, rtx insn, enum reg_class class, register int other, short* reload_reg_p, int goalreg, enum machine_mode mode);

/* From rtlanal.c */
int rtx_unstable_p(rtx x);
int rtx_varies_p(rtx x);
int rtx_addr_varies_p(rtx x);
int reg_mentioned_p(register rtx reg, register rtx in);
int reg_used_between_p(rtx reg, rtx from_insn, rtx to_insn);
int reg_set_between_p(rtx reg, rtx from_insn, rtx to_insn);
int refers_to_regno_p(int regno, int endregno, rtx x, rtx* loc);
int reg_overlap_mentioned_p(rtx reg, rtx x);
int rtx_equal_p(rtx x, rtx y);
int dead_or_set_p(rtx insn, rtx reg);
rtx find_reg_note(rtx insn, enum reg_note kind, rtx datum);
rtx find_regno_note(rtx insn, enum reg_note kind, int regno);
int no_labels_between(register rtx from, register rtx to);
int volatile_refs_p(rtx x);
int may_trap_p(rtx x);

/* From rtl.c */
rtvec rtvec_alloc(int n);
rtx rtx_alloc(RTX_CODE code);
rtx copy_rtx(register rtx orig);
void debug_rtx(rtx x);
void print_rtl(FILE* outf, rtx rtx_first);
int read_skip_spaces(FILE* infile);
rtx read_rtx(FILE* infile);
void init_rtl(void);

/* From sdbout.c */
void sdbout_filename(FILE* asm_file, char* input_name);
void sdbout_init(void);
char* tag_of_ru_type(tree type, tree link);
void sdbout_symbol(tree decl, int local);
void sdbout_tags(tree tags);
void sdbout_types(register tree types);
void sdbout_begin_block(FILE* file, int line, int n);
void sdbout_end_block(FILE* file, int line);
void sdbout_mark_begin_function(void);
void sdbout_begin_function(int line);
void sdbout_end_function(int line);
void sdbout_end_epilogue(void);

/* From stmt.c */
rtx emit_nop(void);
void emit_jump(rtx label);
void expand_label(tree body);
void expand_goto(tree body);
void expand_asm(tree body);
void expand_asm_operands(tree string, tree outputs, tree inputs, tree clobbers, int vol, char* filename, int line);
void expand_expr_stmt(tree exp);
void clear_last_expr(void);
tree expand_start_stmt_expr(void);
tree expand_end_stmt_expr(tree t);
void expand_start_cond(tree cond, int exitflag);
void expand_end_cond(void);
void expand_start_else(void);
void expand_end_else(void);
void expand_start_loop(int exit_flag);
void expand_start_loop_continue_elsewhere(int exit_flag);
void expand_loop_continue_here(void);
void expand_end_loop(void);
int expand_continue_loop(void);
int expand_exit_loop(void);
int expand_exit_loop_if_false(tree cond);
int inside_loop(void);
int expand_exit_something(void);
void expand_null_return(void);
void expand_return(tree retval);
int drop_through_at_end_p(void);
void expand_start_bindings(int exit_flag);
void use_variable(rtx rtl);
void expand_end_bindings(tree vars, int mark_ends, int dont_jump_in);
void expand_decl(register tree decl, tree cleanup);
void expand_decl_init(tree decl);
void expand_anon_union_decl(tree decl, tree cleanup, tree decl_elts);
void move_cleanups_up(void);
int this_contour_has_cleanups_p(void);
void expand_start_case(int exit_flag, tree expr, tree type);
void expand_start_case_dummy(void);
void expand_end_case_dummy(void);
int pushcase(register tree value, register tree label);
int pushcase_range(register tree value1, register tree value2, register tree label);
void expand_end_case(tree orig_index);
int get_frame_size(void);
rtx assign_stack_local(enum machine_mode mode, int size);
void put_var_into_stack(tree decl);
void fixup_stack_slots(void);
int max_parm_reg_num(void);
rtx get_first_nonparm_insn(void);
int aggregate_value_p(tree exp);
rtx validize_mem(rtx ref);
rtx get_structure_value_addr(rtx sizex);
void push_structure_value(rtx* rtx_ptr, int* size_ptr);
void pop_structure_value(rtx rtx_value, int size);
void uninitialized_vars_warning(tree block);
void setjmp_protect(tree block);
void init_function_start(tree subr, char* filename, int line);
void expand_function_start(tree subr, int parms_have_cleanups);
void expand_function_end(char* filename, int line);

/* From stor-layout.c */
void chain_type(tree t);
tree get_permanent_types(void);
tree get_temporary_types(void);
tree get_pending_sizes(void);
int round_size(int size);
tree build_int(unsigned int v);
tree genop(enum tree_code opc, tree op1, tree op2);
tree convert_units(tree size, register int inunits, register int outunits);
void layout_decl(tree decl, unsigned known_align);
void layout_type(tree type);
tree make_signed_type(int precision);
tree make_unsigned_type(int precision);
void fixup_unsigned_type(tree type);

/* From stupid.c */
void stupid_life_analysis(rtx f, int nregs, FILE* file);

/* From symout.c */
void symout_init(char* filename, FILE* asm_file, char* sourcename);
void symout_types(tree types);
int symout_block(tree decls, tree tags, tree args, int superblock_address);
int symout_function(register tree stmt, tree args, int superblock_address);
void symout_function_end(void);
void symout_top_blocks(tree decls, tree tags);
void symout_finish(char* filename, int filetime);

/* From toplev.c */
int gettime(void);
void print_time(const char* str, int total);
int count_error(int warningp);
void pfatal_with_name(const char* name);
void fatal_io_error(const char* name);
extern void fatal (const char *format, ... ) __attribute__ ((__format__ (__printf__, 1, 0)));
void fatal_insn_not_found(rtx insn);
void announce_function(tree decl);
void report_error_function(const char* file);
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
void fancy_abort(void);
void botch(const char* msg);
void* xmalloc(unsigned int size);
void* xrealloc(void* ptr, unsigned int size);
int exact_log2(unsigned int x);
int floor_log2(register unsigned int x);
void set_float_handler(jmp_buf handler);
void rest_of_decl_compilation(tree decl, char* asmspec, int top_level, int at_end);
void rest_of_compilation(tree decl);
int main(int argc, char** argv, char** envp);
void set_target_switch(char* name);
void print_target_switch_defaults(void);

/* From tree.c */
void init_tree(void);
void temporary_allocation(void);
void end_temporary_allocation(void);
void resume_temporary_allocation(void);
int allocation_temporary_p(void);
void permanent_allocation(void);
void preserve_data(void);
char* oballoc(int size);
void obfree(char* ptr);
char* permalloc(long size);
char* savealloc(int size);
void push_momentary(void);
void clear_momentary(void);
void pop_momentary(void);
int suspend_momentary(void);
void resume_momentary(int yes);
tree make_node(enum tree_code code);
tree copy_node(tree node);
tree copy_list(tree list);
tree get_identifier(register char* text);
void start_identifier_warnings(void);
void set_identifier_size(int size);
tree build_int_2(int low, int hi);
tree build_real(tree type, REAL_VALUE_TYPE d);
REAL_VALUE_TYPE real_value_from_int_cst(tree i);
tree build_real_from_int_cst(tree type, tree i);
tree build_string(int len, char* str);
tree build_complex(tree real, tree imag);
int integer_zerop(tree expr);
int integer_onep(tree expr);
int integer_all_onesp(tree expr);
int list_length(tree t);
tree chainon(tree op1, tree op2);
tree build_tree_list(tree parm, tree value);
tree tree_cons(tree purpose, tree value, tree chain);
tree perm_tree_cons(tree purpose, tree value, tree chain);
tree temp_tree_cons(tree purpose, tree value, tree chain);
tree saveable_tree_cons(tree purpose, tree value, tree chain);
tree tree_last(register tree chain);
tree nreverse(tree t);
tree size_in_bytes(tree type);
int int_size_in_bytes(tree type);
tree array_type_nelts(tree type);
int staticp(tree arg);
int lvalue_p(tree ref);
int lvalue_or_else(tree ref, char* string);
tree save_expr(tree expr);
tree stabilize_reference(tree ref);
tree build(int va_alist);
tree build_nt(int va_alist);
tree build_op_identifier(tree op1, tree op2);
tree build_decl(enum tree_code code, tree name, tree type);
tree build_goto(char* filename, int line, tree label);
tree build_return(char* filename, int line, tree arg);
tree build_expr_stmt(char* filename, int line, tree expr);
tree build_if(char* filename, int line, tree cond, tree thenclause, tree elseclause);
tree build_exit(char* filename, int line, tree cond);
tree build_asm_stmt(char* filename, int line, tree asmcode);
tree build_case(char* filename, int line, tree object, tree cases);
tree build_loop(char* filename, int line, tree body);
tree build_compound(char* filename, int line, tree body);
tree build_let(char* filename, int line, tree vars, tree subblocks, tree supercontext, tree tags);
tree build_type_variant(tree type, int constp, int volatilep);
int type_hash_list(tree list);
tree type_hash_lookup(int hashcode, tree type);
void type_hash_add(int hashcode, tree type);
tree type_hash_canon(int hashcode, tree type);
int type_list_equal(tree l1, tree l2);
int tree_int_cst_equal(tree t1, tree t2);
int tree_int_cst_lt(tree t1, tree t2);
int simple_cst_equal(tree t1, tree t2);
tree build_pointer_type(tree to_type);
tree build_index_type(tree maxval);
tree build_array_type(tree elt_type, tree index_type);
tree build_function_type(tree value_type, tree arg_types);
tree build_reference_type(tree to_type);
tree build_method_type(tree basetype, tree type);
tree build_offset_type(tree basetype, tree type);
tree get_unwidened(register tree op, tree for_type);
tree get_narrower(register tree op, int* unsignedp_ptr);
int type_precision(register tree type);
int int_fits_type_p(tree c, tree type);

/* From varasm.c */
EXTRA_SECTION_FUNCTIONS void text_section(void);
void data_section(void);
int in_text_section(void);
void make_function_rtl(tree decl);
int decode_reg_name(char* asmspec);
void make_decl_rtl(tree decl, char* asmspec, int top_level);
void assemble_asm(tree string);
void assemble_function(tree decl);
void assemble_integer_zero(void);
void assemble_string(unsigned char* p, int size);
void assemble_variable(tree decl, int top_level, enum debugger write_symbols, int at_end);
void assemble_external(tree decl);
void assemble_name(FILE* file, char* name);
rtx assemble_static_space(int size);
rtx immed_double_const(int i0, int i1, enum machine_mode mode);
rtx immed_real_const_1(REAL_VALUE_TYPE d, enum machine_mode mode);
rtx immed_real_const(tree exp);
rtx force_const_double_mem(rtx r);
void clear_const_double_mem(void);
int const_hash(tree exp);
rtx output_constant_def(tree exp);
void init_const_rtx_hash_table(void);
int const_hash_rtx(enum machine_mode mode, rtx x);
rtx force_const_mem(enum machine_mode mode, rtx x);
void output_addressed_constants(tree exp);
void output_constant(register tree exp, register int size);
void output_constructor(tree exp, int size);

/* From version.c */

