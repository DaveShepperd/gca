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

#ifndef _PRINT_TREE_H_
#define _PRINT_TREE_H_ (1)

extern char *mode_name[];

void print_node ();
void print_node_brief (FILE *file, char *prefix, tree node, int indent );
void indent_to (FILE *file, int column);
void print_node ( FILE *file, char *prefix, tree node, int indent );

#endif	/* _PRINT_TREE_H_ */
