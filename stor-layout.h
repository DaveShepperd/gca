#ifndef _STOR_LAYOUT_H_
#define _STOR_LAYOUT_H_

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

#endif	/* _STOR_LAYOUT_H_ */
