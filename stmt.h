#ifndef _STMT_H_
#define _STMT_H_

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

#endif	/* _STMT_H_ */
