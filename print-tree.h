#ifndef _PRINT_TREE_H_
#define _PRINT_TREE_H_

void debug_tree(tree node);
void print_node_brief(FILE* file, char* prefix, tree node, int indent);
void indent_to(FILE* file, int column);
void print_node(FILE* file, char* prefix, tree node, int indent);

#endif	/* _PRINT_TREE_H_ */
