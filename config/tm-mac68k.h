
/* Definitions of target machine for GNU compiler.  Atari MAC68K syntax (
   like Generic Motorola syntax, but with different section directives and
   some bells and whistles) (68000/68020) version.
   Intended for use with motorola format assemblers and code compiled with
   the GreenHills Compiler. This was hacked from my previous tm.h, which
   said, in part:

   This was hacked from tm-isi68.h and tm-news800.h by MEA 11-JAN-1989
   Danger/danger/warning/warning tm-68k.h does _not_ do much of anything
   with the #define MOTOROLA. Almost all of what this file "knows" about
   motorola syntax is here, lifted from tm-news800.h. Also note that fsf
   has a somewhat odd idea of just what "motorola" syntax is. This file
   outputs assembly code suitable for the assemblers produced by Motorola!
   To do so, in light of hard-coded stuff in md., it #defines SGS, which is
   not, strictly speaking, true.
   Copyright (C) 1988 Free Software Foundation, Inc.

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


#define MOTOROLA 1
#define SGS 1
#define REALLY_MOTOROLA 1
#include "tm-m68k.h"

/* See tm-m68k.h.  0 means 68000 with no 68881. */

#define TARGET_DEFAULT 0

/* 26JUN1990 - Mike Albaugh adds TARGET_BRAS to enable branch-shortening */
#define TARGET_BRAS (target_flags & 0200)

/* we also have to replace the table for setting target_flags */
#undef TARGET_SWITCHES
/* Macro to define tables used to set the flags.
   This is a list in braces of pairs in braces,
   each pair being { "NAME", VALUE }
   where VALUE is the bits to set or minus the bits to clear.
   An empty string NAME is used to identify the default VALUE.  */

#define TARGET_SWITCHES  \
  { { "68020", 5},				\
    { "c68020", 5},				\
    { "68881", 2},				\
    { "bitfield", 4},				\
    { "68000", -5},				\
    { "c68000", -5},				\
    { "soft-float", -0102},			\
    { "nobitfield", -4},			\
    { "rtd", 8},				\
    { "nortd", -8},				\
    { "short", 040},				\
    { "noshort", -040},				\
    { "fpa", 0100},				\
    { "nofpa", -0100},				\
    { "bras", 0200},				\
    { "nobras", -0200},				\
    { "", TARGET_DEFAULT}}

/* here's where to find cpp and cc1... */
#undef STANDARD_EXEC_PREFIX
#define STANDARD_EXEC_PREFIX "/u/local/lib/gcc-"

/* what to tack onto the above when forming the actual executable name */
#define STANDARD_MACHINE_SUFFIX "m68k-"

#if (1)
/* "added" cpp switch to allow use of native cccp for cross-compile */
#define CPP_SPEC " -I. -I/u/local/cross_clib -nostdinc"
/* a "lib spec" that makes sense to llf. This alone is _not_ enough :-( */
#define LIB_SPEC " -lib /u3/cross_clib/crtl_68k.lib "
#else
/* "added" cpp switch to allow use of native cccp for cross-compile */
#define CPP_SPEC "-nostdinc"
/* a "lib spec" that makes sense to llf. This alone is _not_ enough :-( */
#define LIB_SPEC " -lib /u/local/cross_clib/crtl_68k.lib "
#endif

/* Names to predefine in the preprocessor for this target machine.  */

#define CPP_PREDEFINES "-DM68k"

#define DBX_DEBUGGING_INFO

#define STARTFILE_SPEC  ""

/* Override parts of tm-m68000.h to fit the ISI 68k machine.  */

#undef ASM_FILE_START

/*	The following was hacked into final.c, to allow some notice of
*	source line and filename to be injected into the assembly code,
*	even if not using one of the "approved" debuggers.
*/
#define ASM_NOTE_SOURCE_LINE(FILE, LINE, FILENAME)\
  fprintf(file,"*#line %d \"%s\"\n",(LINE),(FILENAME))

/* Implicit library calls should use memcpy, not bcopy, etc.  */

#define TARGET_MEM_FUNCTIONS

/* Don't try to define `gcc_compiled.' since the assembler might croak on
   un-attached symbols and GDB doesn't run on this machine anyway.  */
#define ASM_IDENTIFY_GCC(FILE)

/* emit some boilerplate, also kluge the enum write_symbols to trace
*  line numbers in comments if no "official" de-bugger
*/
#define ASM_FILE_START(FILE) \
 do { fputs("\t.enabl gbl\n\t.psect text,dat=1,seg=1\n",FILE);\
     if ( write_symbols == 0 ) write_symbols = 5;} while (0)

#ifdef MOTOROLA
#undef FUNCTION_PROLOGUE
#undef FUNCTION_EPILOGUE
#undef TEXT_SECTION_ASM_OP
#undef DATA_SECTION_ASM_OP
#undef BSS_SECTION_ASM_OP
#undef ASM_APP_ON
#undef ASM_APP_OFF
#undef ASM_GLOBALIZE_LABEL
#undef ASM_OUTPUT_LABELREF
#undef ASM_GENERATE_INTERNAL_LABEL
#undef ASM_OUTPUT_INTERNAL_LABEL
#undef ASM_OUTPUT_INT
#undef ASM_OUTPUT_DOUBLE
#undef ASM_OUTPUT_FLOAT
#undef ASM_OUTPUT_SHORT
#undef ASM_OUTPUT_CHAR
#undef ASM_OUTPUT_BYTE
#undef ASM_OUTPUT_ADDR_DIFF_ELT
#undef ASM_OUTPUT_ALIGN
#undef ASM_OUTPUT_REG_PUSH
#undef ASM_OUTPUT_REG_POP
#undef ASM_OUTPUT_SKIP
#undef ASM_OUTPUT_COMMON
#undef ASM_OUTPUT_LOCAL
#undef ASM_OUTPUT_OPCODE
#undef PRINT_OPERAND
#undef PRINT_OPERAND_ADDRESS
#undef ASM_RETURN_CASE_JUMP

/* This macro generates the assembly code for function entry.
   FILE is a stdio stream to output the code to.
   SIZE is an int: how many units of temporary storage to allocate.
   Refer to the array `regs_ever_live' to determine which registers
   to save; `regs_ever_live[I]' is nonzero if register number I
   is ever used in the function.  This macro is responsible for
   knowing which registers should not be saved even if used.  */

/* Note that the order of the bit mask for fmovem is the opposite
   of the order for movem!  */

#define FUNCTION_PROLOGUE(FILE, SIZE)     \
{ register int regno;						\
  register int mask = 0;					\
  static char *reg_names[] = REGISTER_NAMES;			\
  extern char call_used_regs[];					\
  int fsize = (SIZE);						\
  if (frame_pointer_needed)					\
    { if (TARGET_68020 || fsize < 0x10000)			\
        fprintf (FILE, "\tlink a6,#%d\n", -fsize);		\
      else							\
	fprintf (FILE, "\tlink a6,#0\n\tsub.l #%d,sp\n", fsize); }  \
  for (regno = 16; regno < FIRST_PSEUDO_REGISTER; regno++)	\
    if (regs_ever_live[regno] && ! call_used_regs[regno])	\
       mask |= 1 << (regno - 16);				\
  if (mask != 0)						\
    /* this is gonna croak but I don't know the MOTOROLA syntax (MEA) */\
    fprintf (FILE, "\tfmovem.x #0x%x,-(sp)\n", mask & 0xff);    \
  mask = 0;							\
  for (regno = 0; regno < 16; regno++)				\
    if (regs_ever_live[regno] && ! call_used_regs[regno])	\
       mask |= 1 << (15 - regno);				\
  if (frame_pointer_needed)					\
    mask &= ~ (1 << (15-FRAME_POINTER_REGNUM));			\
  if (exact_log2 (mask) >= 0)					\
    fprintf (FILE, "\tmove.l %s,-(sp)\n", reg_names[15 - exact_log2 (mask)]);  \
  else if (mask) {						\
    fprintf (FILE, "\tmovem.l ");				\
    for (regno = 0; regno < 16; regno++) {			\
      if ( mask & (1 << regno) ) {				\
	fputs (reg_names[15-regno], FILE);			\
	if ( mask &= ~(1<<regno) ) fputc ( '/', FILE);		\
	else break;						\
      }								\
    }								\
    fprintf (FILE, ",-(sp)\n"); 				\
    }}

/* This macro generates the assembly code for function exit,
   on machines that need it.  If FUNCTION_EPILOGUE is not defined
   then individual return instructions are generated for each
   return statement.  Args are same as for FUNCTION_PROLOGUE.

   The function epilogue should not depend on the current stack pointer!
   It should use the frame pointer only.  This is mandatory because
   of alloca; we also take advantage of it to omit stack adjustments
   before returning.  */

#define FUNCTION_EPILOGUE(FILE, SIZE) \
{ register int regno;						\
  register int mask, fmask;					\
  register int nregs;						\
  int offset, foffset;						\
  extern char call_used_regs[];					\
  static char *reg_names[] = REGISTER_NAMES;			\
  extern int current_function_pops_args;			\
  extern int current_function_args_size;			\
  int fsize = (SIZE);						\
  int big = 0;							\
  nregs = 0;  fmask = 0;					\
  for (regno = 16; regno < FIRST_PSEUDO_REGISTER; regno++)	\
    if (regs_ever_live[regno] && ! call_used_regs[regno])	\
      { nregs++; fmask |= 1 << (23 - regno); }			\
  foffset = nregs * 12;						\
  nregs = 0;  mask = 0;						\
  if (frame_pointer_needed) regs_ever_live[FRAME_POINTER_REGNUM] = 0; \
  for (regno = 0; regno < 16; regno++)				\
    if (regs_ever_live[regno] && ! call_used_regs[regno])	\
      { nregs++; mask |= 1 << regno; }				\
  offset = foffset + nregs * 4;					\
  if (offset + fsize >= 0x8000 && frame_pointer_needed)		\
    { fprintf (FILE, "\tmove.l #%d,a0\n", -fsize);		\
      fsize = 0, big = 1; }					\
  if (exact_log2 (mask) >= 0) {					\
    if (big)							\
      fprintf (FILE, "\tmove.l -%d(a6,a0.l),%s\n",		\
	       offset + fsize, reg_names[exact_log2 (mask)]);	\
    else if (! frame_pointer_needed)				\
      fprintf (FILE, "\tmove.l (sp)+,%s\n",			\
	       reg_names[exact_log2 (mask)]);			\
    else							\
      fprintf (FILE, "\tmove.l -%d(a6),%s\n",			\
	       offset + fsize, reg_names[exact_log2 (mask)]); }	\
  else if (mask) {						\
    if (big)							\
      fprintf (FILE, "\tmovem.l -%d(a6,a0.l),",			\
	       offset + fsize);					\
    else if (! frame_pointer_needed)				\
      fprintf (FILE, "\tmovem.l (sp)+,");			\
    else							\
      fprintf (FILE, "\tmovem.l -%d(a6),",			\
	       offset + fsize);					\
    for (regno = 0; regno < 16; regno++) {			\
      if ( mask & (1 << regno) ) {				\
	fputs (reg_names[regno], FILE);				\
	if ( mask &= ~(1<<regno) ) fputc ( '/', FILE);		\
	else break; }}						\
    fputc ('\n' , FILE); }	 				\
  if (fmask) {							\
    if (big)							\
      fprintf (FILE, "\tfmovem.x -%d(a6,a0.l),#0x%x\n",		\
	       foffset + fsize, fmask);				\
    else if (! frame_pointer_needed)				\
      fprintf (FILE, "\tfmovem.x (sp)+,#0x%x\n", fmask);	\
    else							\
      fprintf (FILE, "\tfmovem.x -%d(a6),#0x%x\n",		\
	       foffset + fsize, fmask); }			\
  if (frame_pointer_needed)					\
    fprintf (FILE, "\tunlk a6\n");				\
  if (current_function_pops_args && current_function_args_size)	\
    fprintf (FILE, "\trtd #%d\n", current_function_args_size);	\
  else fprintf (FILE, "\trts\n"); }

/* Output before read-only data.  */

#define TEXT_SECTION_ASM_OP "\t.psect text,dat=1,seg=1"

/* Output before initialized (but writable) data.  */

#define DATA_SECTION_ASM_OP "\t.psect data,dat=1,seg=1"

/* For def/ref linkers: Output before un-initialized writable data.  */

#define BSS_SECTION_ASM_OP "\t.psect bss,dat=1,seg=1"

#define ASCII_DATA_ASM_OP "\tDC.B"

/* non-unix assemblers don't need "APP_ON" and "APP_OFF" wrapped around
*  user asm() code.
*/

#define ASM_APP_ON ""
#define ASM_APP_OFF ""

/* This is how to output a command to make the user-level label named NAME
   defined for reference from other files.  */

#define ASM_GLOBALIZE_LABEL(FILE,NAME)	\
  do { fputs ("\txdef ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)

/* This is how to output a reference to a user-level label named NAME.
   `assemble_name' uses this.  */

#define ASM_OUTPUT_LABELREF(FILE,NAME)	\
  fputs (NAME, FILE)

/* This is how to store into the string LABEL
   the symbol_ref name of an internal numbered label where
   PREFIX is the class of label and NUM is the number within the class.
   This is suitable for output with `assemble_name'.  */

#define ASM_GENERATE_INTERNAL_LABEL(LABEL,PREFIX,NUM)	\
  sprintf (LABEL, "*.%s%d", PREFIX, NUM)

/* This is how to output (to FILE)
   the symbol_ref name of an internal numbered label where
   PREFIX is the class of label and NUM is the number within the class.
   This is because some places don't use `assemble_name'.  */

#define ASM_OUTPUT_INTERNAL_LABEL(FILE,PREFIX,NUM)	\
  fprintf (FILE, ".%s%d:\n", PREFIX, NUM)

/* This is how to output an assembler line defining an `int' constant.  */

#define ASM_OUTPUT_INT(FILE,VALUE)  \
( fprintf (FILE, "\tDC.L "),			\
  output_addr_const (FILE, (VALUE)),		\
  fprintf (FILE, "\n"))

/* Likewise for `char' and `short' constants.  */

#define ASM_OUTPUT_SHORT(FILE,VALUE)  \
( fprintf (FILE, "\tDC.W "),			\
  output_addr_const (FILE, (VALUE)),		\
  fprintf (FILE, "\n"))

#define ASM_OUTPUT_CHAR(FILE,VALUE)  \
( fprintf (FILE, "\tDC.B "),			\
  output_addr_const (FILE, (VALUE)),		\
  fprintf (FILE, "\n"))

/* This is how to output an assembler line for a numeric constant byte.  */

#define ASM_OUTPUT_BYTE(FILE,VALUE)  \
  fprintf (FILE, "\tDC.B $0%x\n", (VALUE))

/* This is how to output an assembler line defining a `double' constant.  */

#define ASM_OUTPUT_DOUBLE(FILE,VALUE)  \
do { union { double d; long l[2];} tem;			\
     tem.d = (VALUE);					\
     fprintf (FILE, "\tDC.L 0x%x,0x%x\n", tem.l[0], tem.l[1]);	\
   } while (0)

/* This is how to output an assembler line defining a `float' constant.  */

#define ASM_OUTPUT_FLOAT(FILE,VALUE)  \
do { union { float f; long l;} tem;			\
     tem.f = (VALUE);					\
     fprintf (FILE, "\tDC.L 0x%x\n", tem.l);	\
   } while (0)
/* output a ".ascii" string.	*/

#define	ASM_OUTPUT_ASCII(f, p, size)	\
{ register int i;			\
  int inside,j=0;			\
  inside = FALSE;			\
  for (i = 0; i < size; i++) {		\
    if ((j &= 15) == 0) {		\
      if (i != 0) {			\
	if (inside)			\
	  putc('\'', f);			\
	putc('\n', f);			\
	inside = FALSE;			\
      }					\
      fprintf(f, "%s ", ASCII_DATA_ASM_OP);	\
    }					\
    if (p[i] < 32 || p[i] == '\'' || p[i] & 0x80 || p[i] == 127) {	\
      if (inside) {			\
	fprintf(f, "'\n%s ", ASCII_DATA_ASM_OP);	\
	inside = FALSE;			\
	j = 0;				\
      }					\
      if ( (j & 15) != 0) 	\
	fputc(',', f);			\
      fprintf(f, "%d", p[i]);		\
    } else {				\
      if (!inside) {			\
	if ((j & 15) != 0) {		\
	  fprintf(f, "\n%s ", ASCII_DATA_ASM_OP);\
	  j = 0;}			\
	putc('\'', f);			\
	inside = TRUE;			\
      }					\
      putc(p[i], f);			\
    }					\
  ++j;					\
  }					\
  if (inside)				\
    putc('\'', f);			\
  putc('\n', f);			\
}

/* This is how to output an element of a case-vector that is relative.  */

#define ASM_OUTPUT_ADDR_DIFF_ELT(FILE, VALUE, REL)  \
  fprintf (FILE, "\tDC.W .L%d-.L%d\n", VALUE, REL)

/* This is how to output an assembler line
   that says to advance the location counter
   to a multiple of 2**LOG bytes.  */

#define ASM_OUTPUT_ALIGN(FILE,LOG)	\
  if ((LOG) == 1)			\
    fprintf (FILE, "\tDS.W 0\n");	\
  else if ((LOG) != 0)			\
    abort ();

/* This is how to output an insn to push a register on the stack.
   It need not be very fast code.  */

#define ASM_OUTPUT_REG_PUSH(FILE,REGNO)  \
  fprintf (FILE, "\tmove.l %s,-(sp)\n", reg_names[REGNO])

/* This is how to output an insn to pop a register from the stack.
   It need not be very fast code.  */

#define ASM_OUTPUT_REG_POP(FILE,REGNO)  \
  fprintf (FILE, "\tmove.l (sp)+,%s\n", reg_names[REGNO])
  
#define ASM_OUTPUT_SKIP(FILE,SIZE)  \
 fprintf (FILE, \
 (in_bss_section() ? "\tDS.B %d\n" : "\tDCB.B %d,0\n"),(SIZE))

/*	We are not going to support the peculiar *nix notion of "common".
*	For the (blissfully) un-initiated, this was a hack to allow a
*	programmer to define (as opposed to declare) a variable in more
*	than one file and have them all end up in the same place. This
*	is very convenient for people who are too lazy to use extern and
*	figure out which module properly "owns" a piece of info. It is also
*	very dangerous in that a mis-spelled variable name is quietly
*	incarnated as if it were declared static, and the programmer is left
*	scratching his/her head wondering why changes made in one module are
*	not showing up in the other.
*		Anyway, we will implement .comm and .lcomm as simply globl
*	(or not, respectively) labels on pieces of bss. To do so, we have
*	to add the following "hooks"...
*/

/*	define the extra section "bss" for the enum in_section in varasm.c */
extern void bss_section();
extern int in_bss_section();

#define EXTRA_SECTIONS in_bss
/* Now a function to get into bss (if needed) */
#define EXTRA_SECTION_FUNCTIONS \
void \
bss_section ()\
{\
  if (in_section != in_bss)\
    {\
      fprintf (asm_out_file, "%s\n", BSS_SECTION_ASM_OP);\
      in_section = in_bss;\
    }\
}\
int in_bss_section() { return in_section == in_bss; }

/* This says how to output an assembler line
   to define a global common symbol.  */

#define ASM_OUTPUT_COMMON(FILE, NAME, SIZE, ROUNDED)  \
do { ASM_GLOBALIZE_LABEL((FILE),(NAME));\
    bss_section(); \
    ASM_OUTPUT_LABEL((FILE),(NAME));\
    ASM_OUTPUT_SKIP((FILE),(ROUNDED)); } while (0)

/* This says how to output an assembler line
   to define a local common symbol.  */
#define ASM_OUTPUT_LOCAL(FILE, NAME, SIZE, ROUNDED)	\
do {bss_section(); \
    ASM_OUTPUT_LABEL((FILE),(NAME));\
    ASM_OUTPUT_SKIP((FILE),(ROUNDED)); } while (0)

/* Print operand X (an rtx) in assembler syntax to file FILE.
   CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.
   For `%' followed by punctuation, CODE is the punctuation and X is null.

   On the 68000, we use several CODE characters:
   'f' for float insn (print a CONST_DOUBLE as a float rather than in hex)
   'b' for byte insn (no effect, on the Sun; this is for the ISI).
   '.' for dot needed in Motorola-style opcode names.
   '-' for an operand pushing on the stack:
       sp@-, -(sp) or -(%sp) depending on the style of syntax.
   '+' for an operand pushing on the stack:
       sp@+, (sp)+ or (%sp)+ depending on the style of syntax.
   '@' for a reference to the top word on the stack:
       sp@, (sp) or (%sp) depending on the style of syntax.
   '#' for an immediate operand prefix (# in MIT and Motorola syntax
       but & in SGS syntax).
   '!' for the cc register (used in an `and to cc' insn).  */

#define PRINT_OPERAND(FILE, X, CODE)  \
{ if (CODE == '.') fprintf (FILE, ".");					\
  else if (CODE == '#') fprintf (FILE, "#");				\
  else if (CODE == '-') fprintf (FILE, "-(sp)");			\
  else if (CODE == '+') fprintf (FILE, "(sp)+");			\
  else if (CODE == '@') fprintf (FILE, "(sp)");				\
  else if (CODE == '!') fprintf (FILE, "ccr");				\
  else if (GET_CODE (X) == REG)						\
    fprintf (FILE, "%s", reg_names[REGNO (X)]);				\
  else if (GET_CODE (X) == MEM)						\
    output_address (XEXP (X, 0));					\
  else if (GET_CODE (X) == CONST_DOUBLE && GET_MODE (X) == SFmode)	\
    { union { double d; int i[2]; } u;					\
      union { float f; int i; } u1;					\
      u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\
      u1.f = u.d;							\
      if (CODE == 'f')							\
        fprintf (FILE, "#0f%.9e", u1.f);				\
      else								\
        fprintf (FILE, "#0x%x", u1.i); }				\
  else if (GET_CODE (X) == CONST_DOUBLE && GET_MODE (X) != DImode)	\
    { union { double d; int i[2]; } u;					\
      u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\
      fprintf (FILE, "#0d%.20e", u.d); }				\
  else if (CODE == 'b') output_addr_const (FILE, X);			\
  else { putc ('#', FILE); output_addr_const (FILE, X); }}

/* Note that this contains a kludge that knows that the only reason
   we have an address (plus (label_ref...) (reg...))
   is in the insn before a tablejump, and we know that m68k.md
   generates a label LInnn: on such an insn.  */

#define PRINT_OPERAND_ADDRESS(FILE, ADDR)  \
{ register rtx reg1, reg2, breg, ireg;					\
  register rtx addr = ADDR;						\
  rtx offset;								\
  switch (GET_CODE (addr))						\
    {									\
    case REG:								\
      fprintf (FILE, "(%s)", reg_names[REGNO (addr)]);			\
      break;								\
    case PRE_DEC:							\
      fprintf (FILE, "-(%s)", reg_names[REGNO (XEXP (addr, 0))]);	\
      break;								\
    case POST_INC:							\
      fprintf (FILE, "(%s)+", reg_names[REGNO (XEXP (addr, 0))]);	\
      break;								\
    case PLUS:								\
      reg1 = 0;	reg2 = 0;						\
      ireg = 0;	breg = 0;						\
      offset = 0;							\
      if (CONSTANT_ADDRESS_P (XEXP (addr, 0)))				\
	{								\
	  offset = XEXP (addr, 0);					\
	  addr = XEXP (addr, 1);					\
	}								\
      else if (CONSTANT_ADDRESS_P (XEXP (addr, 1)))			\
	{								\
	  offset = XEXP (addr, 1);					\
	  addr = XEXP (addr, 0);					\
	}								\
      if (GET_CODE (addr) != PLUS) ;					\
      else if (GET_CODE (XEXP (addr, 0)) == SIGN_EXTEND)		\
	{								\
	  reg1 = XEXP (addr, 0);					\
	  addr = XEXP (addr, 1);					\
	}								\
      else if (GET_CODE (XEXP (addr, 1)) == SIGN_EXTEND)		\
	{								\
	  reg1 = XEXP (addr, 1);					\
	  addr = XEXP (addr, 0);					\
	}								\
      else if (GET_CODE (XEXP (addr, 0)) == MULT)			\
	{								\
	  reg1 = XEXP (addr, 0);					\
	  addr = XEXP (addr, 1);					\
	}								\
      else if (GET_CODE (XEXP (addr, 1)) == MULT)			\
	{								\
	  reg1 = XEXP (addr, 1);					\
	  addr = XEXP (addr, 0);					\
	}								\
      else if (GET_CODE (XEXP (addr, 0)) == REG)			\
	{								\
	  reg1 = XEXP (addr, 0);					\
	  addr = XEXP (addr, 1);					\
	}								\
      else if (GET_CODE (XEXP (addr, 1)) == REG)			\
	{								\
	  reg1 = XEXP (addr, 1);					\
	  addr = XEXP (addr, 0);					\
	}								\
      if (GET_CODE (addr) == REG || GET_CODE (addr) == MULT		\
	  || GET_CODE (addr) == SIGN_EXTEND)				\
	{ if (reg1 == 0) reg1 = addr; else reg2 = addr; addr = 0; }	\
      if (offset != 0) { if (addr != 0) abort (); addr = offset; }	\
      if ((reg1 && (GET_CODE (reg1) == SIGN_EXTEND			\
		    || GET_CODE (reg1) == MULT))			\
	  || (reg2 != 0 && REGNO_OK_FOR_BASE_P (REGNO (reg2))))		\
	{ breg = reg2; ireg = reg1; }					\
      else if (reg1 != 0 && REGNO_OK_FOR_BASE_P (REGNO (reg1)))		\
	{ breg = reg1; ireg = reg2; }					\
      if (ireg != 0 && breg == 0 && GET_CODE (addr) == LABEL_REF)	\
        { int scale = 1;						\
	  if (GET_CODE (ireg) == MULT)					\
	    { scale = INTVAL (XEXP (ireg, 1));				\
	      ireg = XEXP (ireg, 0); }					\
	  if (GET_CODE (ireg) == SIGN_EXTEND)				\
	    fprintf (FILE, ".L%d(pc,%s.w",				\
		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\
		     reg_names[REGNO (XEXP (ireg, 0))]); 		\
	  else								\
	    fprintf (FILE, ".L%d(pc,%s.l",				\
		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\
		     reg_names[REGNO (ireg)]);				\
	  if (scale != 1) fprintf (FILE, "*%d", scale);			\
	  putc (')', FILE);						\
	  break; }							\
      if (ireg != 0 || breg != 0)					\
	{ int scale = 1;						\
	  if (breg == 0)						\
	    abort ();							\
	  if (addr != 0) {						\
	    output_addr_const (FILE, addr);				\
	    putc ('(', FILE); }						\
	  else { fprintf (FILE, "0("); }				\
	  fprintf (FILE, "%s", reg_names[REGNO (breg)]);		\
	  if (ireg != 0)						\
	    putc (',', FILE);						\
	  if (ireg != 0 && GET_CODE (ireg) == MULT)			\
	    { scale = INTVAL (XEXP (ireg, 1));				\
	      ireg = XEXP (ireg, 0); }					\
	  if (ireg != 0 && GET_CODE (ireg) == SIGN_EXTEND)		\
	    fprintf (FILE, "%s.w", reg_names[REGNO (XEXP (ireg, 0))]);	\
	  else if (ireg != 0)						\
	    fprintf (FILE, "%s.l", reg_names[REGNO (ireg)]);		\
	  if (scale != 1) fprintf (FILE, "*%d", scale);			\
	  putc (')', FILE);						\
	  break;							\
	}								\
      else if (reg1 != 0 && GET_CODE (addr) == LABEL_REF)		\
	{ fprintf (FILE, ".L%d(pc,%s.l)",				\
		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\
		   reg_names[REGNO (reg1)]);				\
	  break; }							\
    default:								\
/*	 Motorola has, unfortunately, no way to spec addr.w		\
      if (GET_CODE (addr) == CONST_INT					\
	  && INTVAL (addr) < 0x8000					\
	  && INTVAL (addr) >= -0x8000)					\
	fprintf (FILE, "%d.w", INTVAL (addr));				\
      else								\
*/									\
        output_addr_const (FILE, addr);					\
    }}

#undef OUTPUT_JUMP
extern char *moto_jump();
#define OUTPUT_JUMP(NORMAL, FLOAT, NO_OV)  \
{ if (cc_prev_status.flags & CC_IN_68881)			\
    return FLOAT;						\
  if (cc_prev_status.flags & CC_NO_OVERFLOW)			\
    return moto_jump(NO_OV,insn);				\
  return moto_jump(NORMAL,insn); }

/* Translate alledgedly Motorola opcodes such as `jbeq'
*   into actual Motorola opcodes such as `beq'.
*/

#define ASM_OUTPUT_OPCODE(FILE, PTR)			\
{ if ((PTR)[0] == 'j' && (PTR)[1] == 'b')		\
    { ++(PTR);						\
      while (*(PTR) != ' ')				\
	{ putc (*(PTR), (FILE)); ++(PTR); }}}

#define ASM_RETURN_CASE_JUMP return "jmp %l1(pc,%0.w)"

#else /* Using GAS, which uses the MIT assembler syntax, like a Sun.  */

#define FUNCTION_PROFILER(FILE, LABEL_NO) \
   fprintf (FILE, "\tmovl #LP%d,d0\n\tjsr mcount\n", (LABEL_NO));

#endif /* MOTOROLA */
