#ifndef _C_DECL_H_
#define _C_DECL_H_

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

#endif	/* _C_DECL_H_ */
