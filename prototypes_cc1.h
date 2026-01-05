/* cc -g -O -v -m32 -D_POSIX_SOURCE  -g -m32 -o cc1
   c-parse.tab.o c-decl.o c-typeck.o c-convert.o toplev.o
   version.o tree.o print-tree.o stor-layout.o fold-const.o
   rtl.o rtlanal.o expr.o stmt.o expmed.o explow.o optabs.o
   varasm.o symout.o dbxout.o sdbout.o emit-rtl.o insn-emit.o
   integrate.o jump.o cse.o loop.o flow.o stupid.o combine.o
   regclass.o local-alloc.o global-alloc.o reload.o reload1.o
   caller-save.o insn-peep.o final.o recog.o insn-recog.o
   insn-extract.o insn-output.o pragma.o obstack.o
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>
#include <string.h>

#ifndef _PROTOTYPES_CC1_H_
#define _PROTOTYPES_CC1_H_ 1
#endif
#ifndef _PROTOTYPES_CC1_H_
#define _PROTOTYPES_CC1_H_ 1

#include "flags.h"
#include "tree.h"
#include "rtl.h"
#include "expr.h"
#include "real.h"

#ifndef _POINTER_DEF_
#define _POINTER_DEF_
typedef void *pointer;               /* generic ptr type */
#define POINTER pointer
#endif

/* From c-parse.tab.c */
int yyparse(void);
#if 0
__inline static int hash( char* str,  int len);
__inline struct resword* is_reserved_word( char* str,  int len);
#endif
void init_lex(void);
int check_newline(void);

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
tree finish_struct( tree t,  tree fieldlist);
tree start_enum(tree name);
tree finish_enum( tree enumtype,  tree values);
tree build_enumerator(tree name, tree value);
int start_function(tree declspecs, tree declarator);
void store_parm_decls(void);
void finish_function(int lineno);

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
tree build_c_cast( tree type, tree expr);
tree build_modify_expr(tree lhs, enum tree_code modifycode, tree rhs);
int language_lvalue_valid(tree exp);
void store_init_value(tree decl, tree init);
tree digest_init(tree type, tree init, tree tail);
void c_expand_asm_operands(tree string, tree outputs, tree inputs, tree clobbers, int vol, char* filename, int line);
void c_expand_return(tree retval);
tree c_expand_start_case(tree exp);

/* From c-convert.c */
tree convert(tree type, tree expr);

/* From toplev.c */
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
extern void error_with_decl (tree decl, const char *format /*, int arg */ );
extern void error_for_asm (rtx insn, const char *fmt, ...) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void warning (const char *format, ...) __attribute__ ((__format__ (__printf__, 1, 0)));
extern void warning_with_file_and_line (const char *file, int line, const char *format, ...) __attribute__ ((__format__ (__printf__, 3, 0)));
extern void vwarning_with_file_and_line (const char *file, int line, const char *format, va_list ap);
extern void warning_with_decl (tree decl, const char *format /*, int arg */ );
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
extern int main(int argc, char** argv, char** envp);
extern void set_target_switch(char* name);
extern void print_target_switch_defaults(void);

/* From print-tree.c */
void debug_tree(tree node);
void print_node_brief(FILE* file, char* prefix, tree node, int indent);
void indent_to(FILE* file, int column);
void print_node(FILE* file, char* prefix, tree node, int indent);

/* From print-tree.c */
void debug_tree(tree node);
void print_node_brief(FILE* file, char* prefix, tree node, int indent);
void indent_to(FILE* file, int column);
void print_node(FILE* file, char* prefix, tree node, int indent);

/* From stor-layout.c */
void chain_type(tree t);
tree get_permanent_types(void);
tree get_temporary_types(void);
tree get_pending_sizes(void);
int round_size(int size);
tree build_int(unsigned int v);
tree genop(enum tree_code opc, tree op1, tree op2);
tree convert_units(tree size,  int inunits,  int outunits);
void layout_decl(tree decl, unsigned known_align);
void layout_type(tree type);
tree make_signed_type(int precision);
tree make_unsigned_type(int precision);
void fixup_unsigned_type(tree type);

/* From fold-const.c */
tree combine(enum tree_code code,  tree arg1,  tree arg2);
tree fold(tree expr);

#if 0
/* From rtl.c */
rtvec rtvec_alloc(int n);
rtx rtx_alloc(RTX_CODE code);
rtx copy_rtx( rtx orig);
void debug_rtx(rtx x);
void print_rtl(FILE* outf, rtx rtx_first);
int read_skip_spaces(FILE* infile);
rtx read_rtx(FILE* infile);
void init_rtl(void);
#endif

/* From rtlanal.c */
int rtx_unstable_p(rtx x);
int rtx_varies_p(rtx x);
int rtx_addr_varies_p(rtx x);
int reg_mentioned_p( rtx reg,  rtx in);
int reg_used_between_p(rtx reg, rtx from_insn, rtx to_insn);
int reg_set_between_p(rtx reg, rtx from_insn, rtx to_insn);
int refers_to_regno_p(int regno, int endregno, rtx x, rtx* loc);
int reg_overlap_mentioned_p(rtx reg, rtx x);
int rtx_equal_p(rtx x, rtx y);
int dead_or_set_p(rtx insn, rtx reg);
rtx find_reg_note(rtx insn, enum reg_note kind, rtx datum);
rtx find_regno_note(rtx insn, enum reg_note kind, int regno);
int no_labels_between( rtx from,  rtx to);
int volatile_refs_p(rtx x);
int may_trap_p(rtx x);

/* From expr.c */
void init_comparisons(void);
void init_expr(void);
rtx protect_from_queue( rtx x, int modify);
void emit_queue(void);
void convert_move( rtx to,  rtx from, int unsignedp);
rtx convert_to_mode(enum machine_mode mode, rtx x, int unsignedp);
int integer_mode_p(enum machine_mode mode);
void move_block_from_reg(int regno, rtx x, int nregs);
void clear_storage(rtx object, int size);
rtx emit_move_insn(rtx x, rtx y);
rtx push_block(rtx size, int extra);
void emit_library_call(int va_alist);
rtx expand_assignment(tree to, tree from, int want_value, int suggest_reg);
rtx store_expr( tree exp,  rtx target, int suggest_reg);
rtx force_operand(rtx value, rtx target);
rtx expand_expr( tree exp, rtx target, enum machine_mode tmode, enum expand_modifier modifier);
void init_pending_stack_adjust(void);
void clear_pending_stack_adjust(void);
void do_pending_stack_adjust(void);
void jumpifnot(tree exp, rtx label);
void jumpif(tree exp, rtx label);
void do_jump(tree exp, rtx if_false_label, rtx if_true_label);
void do_tablejump(rtx index, rtx range, rtx table_label, rtx default_label);

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
void expand_decl( tree decl, tree cleanup);
void expand_decl_init(tree decl);
void expand_anon_union_decl(tree decl, tree cleanup, tree decl_elts);
void move_cleanups_up(void);
int this_contour_has_cleanups_p(void);
void expand_start_case(int exit_flag, tree expr, tree type);
void expand_start_case_dummy(void);
void expand_end_case_dummy(void);
int pushcase( tree value,  tree label);
int pushcase_range( tree value1,  tree value2,  tree label);
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

/* From expmed.c */
rtx negate_rtx(enum machine_mode mode, rtx x);
rtx store_bit_field(rtx str_rtx,  int bitsize, int bitnum, enum machine_mode fieldmode, rtx value, int align, int total_size);
rtx extract_bit_field(rtx str_rtx,  int bitsize, int bitnum, int unsignedp, rtx target, enum machine_mode mode, enum machine_mode tmode, int align, int total_size);
void expand_inc(rtx target, rtx inc);
void expand_dec(rtx target, rtx dec);
rtx expand_shift(enum tree_code code,  enum machine_mode mode, rtx shifted, tree amount,  rtx target, int unsignedp);
rtx expand_bit_and(enum machine_mode mode, rtx op0, rtx op1, rtx target);
rtx expand_mult(enum machine_mode mode,  rtx op0,  rtx op1,  rtx target, int unsignedp);
rtx expand_divmod(int rem_flag, enum tree_code code, enum machine_mode mode,  rtx op0,  rtx op1,  rtx target, int unsignedp);
rtx expand_mult_add(rtx x, rtx mult, rtx add, enum machine_mode mode, int unsignedp);

/* From explow.c */
rtx plus_constant( rtx x,  int c);
rtx eliminate_constant_term(rtx x, int* constptr);
rtx expr_size(tree exp);
rtx lookup_static_chain(rtx context);
rtx copy_all_regs( rtx x);
rtx memory_address(enum machine_mode mode,  rtx x);
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

/* From optabs.c */
rtx expand_binop(enum machine_mode mode, optab binoptab, rtx op0, rtx op1, rtx target, int unsignedp, enum optab_methods methods);
rtx sign_expand_binop(enum machine_mode mode, optab uoptab, optab soptab, rtx op0, rtx op1, rtx target, int unsignedp, enum optab_methods methods);
int expand_twoval_binop(optab binoptab, rtx op0, rtx op1, rtx targ0, rtx targ1, int unsignedp);
int expand_twoval_binop_convert( optab binoptab, int mode,  rtx op0,  rtx op1,  rtx targ0,  rtx targ1, int unsignedp);
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
void expand_fix( rtx to,  rtx from, int unsignedp);
void init_optabs(void);

/* From varasm.c */
/* EXTRA_SECTION_FUNCTIONS */
void text_section(void);
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
void output_constant( tree exp,  int size);
void output_constructor(tree exp, int size);

/* From symout.c */
void symout_init(char* filename, FILE* asm_file, char* sourcename);
void symout_types(tree types);
int symout_block(tree decls, tree tags, tree args, int superblock_address);
int symout_function( tree stmt, tree args, int superblock_address);
void symout_function_end(void);
void symout_top_blocks(tree decls, tree tags);
void symout_finish(char* filename, int filetime);

/* From dbxout.c */
void dbxout_init(FILE* asm_file, char* input_file_name);
void dbxout_symbol(tree decl, int local);
void dbxout_args(tree args);
void dbxout_types( tree types);
void dbxout_tags(tree tags);
void dbxout_function(tree decl);
void dbxout_init(FILE* asm_file, char* input_file_name);

/* From p_sdbout.c */
void sdbout_filename(FILE* asm_file, char* input_name);
void sdbout_init(void);
void sdbout_symbol(tree decl, int local);
void sdbout_tags(tree tags);
void sdbout_types( tree types);
void sdbout_begin_block(FILE* file, int line, int n);
void sdbout_end_block(FILE* file, int line);
void sdbout_mark_begin_function(void);
void sdbout_begin_function(int line);
void sdbout_end_function(int line);
void sdbout_end_epilogue(void);

/* From emit-rtl.c */
rtx gen_rtx (int code, int mode, ...);
rtvec gen_rtvec(int n, ...);
rtvec gen_rtvec_v(int n, rtx *argp);
rtx gen_reg_rtx(enum machine_mode mode);
void mark_reg_ptr(rtx reg);
int max_reg_num(void);
int max_label_num(void);
int get_first_label_num(void);
rtx gen_lowpart(enum machine_mode mode,  rtx x);
rtx gen_highpart(enum machine_mode mode,  rtx x);
int subreg_lowpart_p(rtx x);
rtx change_address(rtx memref, enum machine_mode mode, rtx addr);
rtx gen_label_rtx(void);
rtx gen_inline_header_rtx(rtx insn, rtx last_insn, int first_labelno, int last_labelno, int max_parm_regnum, int max_regnum, int args_size, rtx stack_slots);
void set_new_first_and_last_insn(rtx first, rtx last);
void unshare_all_rtl( rtx insn);
rtx make_safe_from(rtx x, rtx other);
rtx get_insns(void);
rtx get_last_insn(void);
void set_last_insn(rtx insn);
int get_max_uid(void);
rtx next_insn(rtx insn);
rtx previous_insn(rtx insn);
void delete_insns_since(rtx from);
void reorder_insns(rtx from, rtx to, rtx after);
rtx emit_insn_before( rtx pattern,  rtx before);
rtx emit_jump_insn_before( rtx pattern,  rtx before);
rtx emit_call_insn_before( rtx pattern,  rtx before);
rtx emit_insn_after( rtx pattern,  rtx after);
rtx emit_jump_insn_after( rtx pattern,  rtx after);
rtx emit_barrier_after( rtx after);
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

/* insn-emit.c */
rtx gen_cmpsi(rtx operand0, rtx operand1);
rtx gen_tstsi(rtx operand0);
rtx gen_tsthi(rtx operand0);
rtx gen_tstqi(rtx operand0);
rtx gen_beq(rtx operand0);
rtx gen_bne(rtx operand0);
rtx gen_bgt(rtx operand0);
rtx gen_bgtu(rtx operand0);
rtx gen_blt(rtx operand0);
rtx gen_bltu(rtx operand0);
rtx gen_bge(rtx operand0);
rtx gen_bgeu(rtx operand0);
rtx gen_ble(rtx operand0);
rtx gen_bleu(rtx operand0);
rtx gen_movsi(rtx operand0, rtx operand1);
rtx gen_movhi(rtx operand0, rtx operand1);
rtx gen_movqi(rtx operand0, rtx operand1);
rtx gen_truncsiqi2(rtx operand0, rtx operand1);
rtx gen_truncsihi2(rtx operand0, rtx operand1);
rtx gen_trunchiqi2(rtx operand0, rtx operand1);
rtx gen_zero_extendqihi2(rtx operand0, rtx operand1);
rtx gen_zero_extendhisi2(rtx operand0, rtx operand1);
rtx gen_zero_extendqisi2(rtx operand0, rtx operand1);
rtx gen_extendhisi2(rtx operand0, rtx operand1);
rtx gen_extendqisi2(rtx operand0, rtx operand1);
rtx gen_extendqihi2(rtx operand0, rtx operand1);
rtx gen_addsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_subsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_andsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_iorsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_xorsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_negsi2(rtx operand0, rtx operand1);
rtx gen_one_cmplsi2(rtx operand0, rtx operand1);
rtx gen_ashlsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_rotlsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_ashrsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_lshrsi3(rtx operand0, rtx operand1, rtx operand2);
rtx gen_jump(rtx operand0);
rtx gen_call(rtx operand0, rtx operand1);
rtx gen_call_value(rtx operand0, rtx operand1, rtx operand2);
rtx gen_tablejump(rtx operand0, rtx operand1);
rtx gen_nop(void);
rtx gen_movsf(rtx operand0, rtx operand1);
rtx gen_movdf(rtx operand0, rtx operand1);
rtx gen_movdi(rtx operand0, rtx operand1);

/* From integrate.c */
char* function_cannot_inline_p( tree fndecl);
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
rtx delete_insn( rtx insn);
rtx next_nondeleted_insn(rtx insn);
void delete_for_peephole( rtx from,  rtx to);
void invert_jump(rtx jump, rtx nlabel);
void invert_exp(rtx x, rtx olabel, rtx nlabel);
void redirect_jump(rtx jump, rtx nlabel);
int rtx_renumbered_equal_p(rtx x, rtx y);
int true_regnum(rtx x);

/* From cse.c */
int refers_to_p(rtx x, rtx y);
int refers_to_mem_p(rtx x, rtx reg, int start, int end);
int cse_main(rtx f, int nregs);

/* From loop.c */
void loop_optimize(rtx f, FILE* dumpfile);
int loop_skip_over(rtx start, rtx end, rtx loop_entry_jump);
int addr_overlap_p(rtx other, rtx base, int size);
int other_reg_use_p( rtx reg,  rtx expr,  rtx in);

/* From flow.c */
void flow_analysis(rtx f, int nregs, FILE* file);
void allocate_for_life_analysis(void);
int regno_uninitialized(int regno);
int regno_clobbered_at_setjmp(int regno);
void dump_flow_info(FILE* file);

/* From stupid.c */
void stupid_life_analysis(rtx f, int nregs, FILE* file);

/* From combine.c */
void combine_instructions(rtx f, int nregs);
int regno_dead_p(int regno, rtx insn);
void remove_death(int regno, rtx insn);
void dump_combine_stats(FILE* file);
void dump_combine_total_stats(FILE* file);

#if 0
/* From regclass.c */
void init_reg_sets(void);
void init_reg_sets_1(void);
void fix_(char* name, int fixed, int call_used);
int reg_preferred_class(int regno);
int reg_preferred_or_nothing(regno);
int regclass_init(void);
void regclass(rtx f, int nregs);
void reg_class_record(rtx op, int opno, char** constraints);
void record_address_regs(rtx x, int bcost, int icost);
void reg_scan(rtx f, int nregs, int repeat);
void reg_scan_mark_refs(rtx x, int uid);
#endif

/* From local-alloc.c */
void local_alloc(void);
void dump_local_alloc(FILE* file);

/* From global-alloc.c */
void global_alloc(FILE* file);
void retry_global_alloc(int regno, short* forbidden_regs);
int check_frame_ptr_required(rtx* reg_equiv_constant, rtx* reg_equiv_mem, rtx* reg_equiv_address);
void dump_global_regs(FILE* file);

/* From reload1.c */
void reload(rtx first, int global, FILE* dumpfile);
void mark_home_live(int regno);

/* From reload1.c */
void reload(rtx first, int global, FILE* dumpfile);
void mark_home_live(int regno);

/* From caller-save.c */
void save_call_clobbered_regs(void);

/* From insn-peep.c */
rtx peephole(rtx ins1);

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
rtx alter_subreg( rtx x);
void output_asm_insn(char* template, rtx* operands);
void output_asm_label(rtx x);
void output_address(rtx x);
void output_addr_const(FILE* file, rtx x);

/* From recog.c */
void init_recog(void);
int recog_memoized(rtx insn);
int next_insn_tests_no_inequality(rtx insn);
int next_insns_test_no_inequality(rtx insn);
int general_operand( rtx op, enum machine_mode mode);
int address_operand( rtx op, enum machine_mode mode);
int _operand( rtx op, enum machine_mode mode);
int immediate_operand( rtx op, enum machine_mode mode);
int nonimmediate_operand( rtx op, enum machine_mode mode);
int nonmemory_operand( rtx op, enum machine_mode mode);
int push_operand(rtx op, enum machine_mode mode);
int memory_address_p(enum machine_mode mode,  rtx addr);
int memory_operand( rtx op, enum machine_mode mode);
int indirect_operand( rtx op, enum machine_mode mode);
int asm_noperands(rtx body);
char* decode_asm_operands(rtx body, rtx* operands, rtx** operand_locs, char** constraints, enum machine_mode* modes);
int offsettable_memref_p(rtx op);
int offsettable_address_p(int strictp, enum machine_mode mode,  rtx y);
int mode_dependent_address_p(rtx addr);
int mode_independent_operand(rtx op, enum machine_mode mode);
rtx adj_offsettable_operand(rtx op, int offset);
int constrain_operands(int insn_code_num);
int reg_fits_class_p(rtx operand,  enum reg_class class, int offset, enum machine_mode mode);

/* From insn-recog.c */
int recog_1( rtx x0, rtx insn);
int recog_2( rtx x0, rtx insn);
int recog( rtx x0, rtx insn);

/* From insn-extract.c */
void extract_0(rtx insn);
void extract_1(rtx insn);
void extract_2(rtx insn);
void extract_3(rtx insn);
void extract_4(rtx insn);
void extract_5(rtx insn);
void extract_6(rtx insn);
void extract_7(rtx insn);
void extract_8(rtx insn);
void extract_9(rtx insn);
void extract_10(rtx insn);
void extract_11(rtx insn);
void extract_12(rtx insn);
void extract_13(rtx insn);
void extract_14(rtx insn);
void extract_15(rtx insn);
void extract_16(rtx insn);
void extract_17(rtx insn);
void extract_18(rtx insn);
void extract_19(rtx insn);
void extract_20(rtx insn);
void extract_21(rtx insn);
void extract_22(rtx insn);
void extract_23(rtx insn);
void extract_24(rtx insn);
void extract_25(rtx insn);
void extract_26(rtx insn);
void extract_27(rtx insn);
void extract_28(rtx insn);
void extract_29(rtx insn);
void extract_30(rtx insn);
void extract_31(rtx insn);
void extract_32(rtx insn);
void extract_33(rtx insn);
void extract_34(rtx insn);
void extract_35(rtx insn);
void extract_36(rtx insn);
void extract_37(rtx insn);
void extract_38(rtx insn);
void extract_39(rtx insn);
void extract_40(rtx insn);
void extract_41(rtx insn);
void extract_42(rtx insn);
void extract_43(rtx insn);
void extract_44(rtx insn);
void extract_45(rtx insn);
void extract_46(rtx insn);
void extract_47(rtx insn);
void extract_48(rtx insn);
void extract_49(rtx insn);
void extract_50(rtx insn);
void extract_51(rtx insn);
void extract_52(rtx insn);
void extract_53(rtx insn);
void extract_54(rtx insn);
void extract_55(rtx insn);
void extract_56(rtx insn);
void extract_57(rtx insn);
void extract_58(rtx insn);
void extract_59(rtx insn);
void extract_60(rtx insn);
void extract_61(rtx insn);
void extract_62(rtx insn);
void extract_63(rtx insn);
void extract_64(rtx insn);
void extract_65(rtx insn);
void extract_66(rtx insn);
void extract_67(rtx insn);
void extract_68(rtx insn);
void extract_69(rtx insn);
void extract_70(rtx insn);
void extract_71(rtx insn);
void extract_72(rtx insn);
void extract_73(rtx insn);
void extract_74(rtx insn);
void (* insn_extract_fn [ ]);
void insn_extract(rtx insn);

#if 0
/* From insn-output.c */
char* (* const insn_outfun [ ] )(void);
/* rtx (* const insn_gen_function [ ]); */
int (* const insn_operand_predicate [ ] [ MAX_RECOG_OPERANDS ] )(void);
#endif

/* From pragma.c */
void pragma_pack(int val);
int pragma_align_val(void);
void pragma_pack_default(void);
int pragma_pack_seen(void);

#if 0
struct obstack;
/* From obstack.c */
void _obstack_begin ( struct obstack *h, int size, int alignment, void *(*chunkfun) (int size), void (*freefun) (void *ptr));
void _obstack_newchunk(void* inpH, int length);
int _obstack_allocated_p(struct obstack* h, POINTER obj);
void obstack_free (struct obstack* h, POINTER obj);
void _obstack_free(struct obstack* h, POINTER obj);
#endif

#endif	/* _PROTOTYPES_CC1_H_ */
