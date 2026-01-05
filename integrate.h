#ifndef _INTEGRATE_H_
#define _INTEGRATE_H_

char* function_cannot_inline_p( tree fndecl);
void save_for_inline(tree fndecl);
rtx expand_inline_function(tree fndecl, tree parms, rtx target, int ignore, tree type, rtx structure_value_addr);
void output_inline_function(tree fndecl);

#endif	/* _INTEGRATE_H_ */
