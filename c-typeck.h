#ifndef _C_TYPECK_H_
#define _C_TYPECK_H_

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
tree digest_init(tree type, tree init, tree *tail);
void c_expand_asm_operands(tree string, tree outputs, tree inputs, tree clobbers, int vol, char* filename, int line);
void c_expand_return(tree retval);
tree c_expand_start_case(tree exp);

#endif	/* _C_TYPECK_H_ */
