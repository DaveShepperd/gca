/*-------------------------------------------------------------------
	FILE: out-m6809.c
- -------------------------------------------------------------------*/
/* Subroutines for insn-output.c for MC6809.
   Copyright (C) 1989 Free Software Foundation, Inc.

 MC6809 Version by Tom Jones (jones@sal.wisc.edu)
 Space Astronomy Laboratory
 University of Wisconsin at Madison


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
#include <stdio.h>

/* macro to return TRUE if length of operand mode is one byte */
#define BYTE_MODE(X) ((GET_MODE_SIZE (GET_MODE (X))) == 1)
#define DEBUG

/*-------------------------------------------------------------------
    Custom abort function
- -------------------------------------------------------------------*/
void
abort ()
{
    fprintf (stderr, "ABORT\n");
    exit (1);
}

override_options ()
{
}

extern int reload_completed;		/* set in toplev.c */
extern FILE *asm_out_file;
static int last_mem_size;	/* operand size (bytes) */
/*-------------------------------------------------------------------
    Return 1 if OP is a data register (there is only one)
- -------------------------------------------------------------------*/
int
data_reg_operand (op, mode)
rtx op;
enum machine_mode mode;
{
    int code = 0;

    if (reg_operand (op, mode)) {
	if (reload_completed) {
	    if (REGNO (op) == HARD_D_REGNUM) {
		code = 1;
	    }
	}
	else {
	    code = 1;
	}
    }

    return (code);
}

/*-------------------------------------------------------------------
    Return 1 if OP can be used as a byte-length operand
- -------------------------------------------------------------------*/
int
byte_operand (op, mode)
rtx op;
enum machine_mode mode;
{
    if ((GET_CODE (op) == REG) || (GET_CODE (op) == SUBREG))
	return (byte_reg_operand (op, mode));
    else
	return (general_operand (op, mode));
}

/*-------------------------------------------------------------------
    Return 1 if OP can be used as a byte-length register
- -------------------------------------------------------------------*/
int
byte_reg_operand (op, mode)
rtx op;
enum machine_mode mode;
{
    int code = 0;

    if (reg_operand (op, mode)) {
	if (reload_completed) {
	    if ((REGNO (op) == HARD_D_REGNUM)
		|| (REGNO (op) == HARD_A_REGNUM)
		|| (REGNO (op) == HARD_B_REGNUM)) {
		code = 1;
	    }
	}
	else {
	    code = 1;
	}
    }

    return (code);
}

/*-------------------------------------------------------------------
    Return 1 if OP can be used as a register
    Hacked from "register_operand" in recog.c, similar but
    with looser mode checking.
- -------------------------------------------------------------------*/
int
reg_operand (op, mode)
rtx op;
enum machine_mode mode;
{
  if (mode == VOIDmode)
    return 1;

  if ((GET_CODE (op) == SUBREG) && (! reload_completed))
	return general_operand (op, mode);

  while (GET_CODE (op) == SUBREG)
    op = SUBREG_REG (op);

  return GET_CODE (op) == REG;
}

/*-------------------------------------------------------------------
    Print Operand for assembler
- -------------------------------------------------------------------*/
void
print_operand (file, x, code)
FILE *file;
rtx x;
int code;
{
    extern void print_operand_address ();

    if (GET_CODE (x) == REG) {
	if ((BYTE_MODE (x)) && (REGNO (x) == HARD_D_REGNUM))
	    fputs ("b", file);
	else
	    fputs (reg_names[REGNO (x)], file);
    }
    else if (GET_CODE (x) == MEM) {
	last_mem_size = GET_MODE_SIZE (GET_MODE (x));
	if (code == 'L') {	/* LSH of word address */
	    x = adj_offsettable_operand (x, 1);
	}
	output_address (XEXP (x, 0));
    }
    else if (GET_CODE (x) == CONST_DOUBLE && GET_MODE (x) != DImode)
    {
	union { double d; int i[2]; } u;
	u.i[0] = CONST_DOUBLE_LOW (x);
	u.i[1] = CONST_DOUBLE_HIGH (x);
	fprintf (file, "#%.9#g", u.d);
    }
    else {
	if (code == 'L') {	/* LSH of word address */
	    x = gen_rtx (CONST_INT, VOIDmode, (INTVAL(x) & 0xff));
	}
	else if (code == 'M') {	/* MSH of word address */
	    x = gen_rtx (CONST_INT, VOIDmode, ((INTVAL(x) >> 8) & 0xff));
	}
	putc ('#', file);
	output_addr_const (file, x);
    }
}

/*-------------------------------------------------------------------
    Print a memory operand whose address is X, on file FILE.
- -------------------------------------------------------------------*/
void
print_operand_address (file, addr)
FILE *file;
register rtx addr;
{
    extern void debug_rtx ();		/* DEBUG */
    register rtx base = 0;
    register rtx offset = 0;
    int regno;
    int indirect_flag = 0;

    /*** check for indirect addressing ***/
    if (GET_CODE (addr) == MEM) {
	last_mem_size = GET_MODE_SIZE (GET_MODE (addr));
	indirect_flag = 1;
	fprintf (file, "[");
	addr = XEXP (addr, 0);
    }

    switch (GET_CODE (addr)) {
    case REG:
	regno = REGNO (addr);
	if ((BYTE_MODE (addr)) && (REGNO (addr) == HARD_D_REGNUM))
	    fprintf (file, ",b");
	else
	    fprintf (file, ",%s", reg_names[regno]);
	break;

    case PRE_DEC:
	regno = REGNO (XEXP (addr, 0));
	fputs (((last_mem_size == 1) ? ",-" : ",--"), file);
	fprintf (file, "%s", reg_names[regno]);
	break;

    case POST_INC:
	regno = REGNO (XEXP (addr, 0));
	fprintf (file, ",%s", reg_names[regno]);
	fputs (((last_mem_size == 1) ? "+" : "++"), file);
	break;

    case PLUS:
	base = XEXP (addr, 0);
	if (GET_CODE (base) == MEM)
	    base = XEXP (base, 0);
	offset = XEXP (addr, 1);
	if (GET_CODE (offset) == MEM)
	    offset = XEXP (offset, 0);

	if ((CONSTANT_ADDRESS_P (base))
	    && (CONSTANT_ADDRESS_P (offset))) {
	    output_addr_const (file, base);
	    fputs ("+", file);
	    output_addr_const (file, offset);
	}

	else if ((CONSTANT_ADDRESS_P (base)) && (A_REG_P (offset))) {
	    output_addr_const (file, base);
	    fprintf (file, ",%s", reg_names[REGNO (offset)]);
	}

	else if ((CONSTANT_ADDRESS_P (offset)) && (A_REG_P (base))) {
	    output_addr_const (file, offset);
	    fprintf (file, ",%s", reg_names[REGNO (base)]);
	}

	/*** accumulator offset ***/
	else if (((D_REG_P (offset)) || (Q_REG_P (offset)))
	&& (A_REG_P (base))) {
	    fprintf (file, "%s,%s",
		reg_names[REGNO (offset)], reg_names[REGNO (base)]);
	}

	else if (((D_REG_P (base)) || (Q_REG_P (base)))
	&& (A_REG_P (offset))) {
	    fprintf (file, "%s,%s",
		reg_names[REGNO (base)], reg_names[REGNO (offset)]);
	}

	else if (GET_CODE (base) == PRE_DEC) {
	    regno = REGNO (XEXP (base, 0));
	    fputs (((last_mem_size == 1) ? ",-" : ",--"), file);
	    fprintf (file, "%s", reg_names[regno]);
	}
	else if ((REG_P (base)) && (REG_P (offset))) {
	    fprintf (file, "%s,%s ;BOGUS",
		reg_names[REGNO (offset)], reg_names[REGNO (base)]);
	    debug_rtx (addr);		/* DEBUG */
	}
	else {
	    fprintf (file, "BOGUS+");
	    debug_rtx (addr);		/* DEBUG */
	}
	break;

	default:
	    output_addr_const (file, addr);
	    break;
    }

    if (indirect_flag)
	fprintf (file, "]");
}

/*-------------------------------------------------------------------
    Update the CC Status
- ---------------------------------------------------------------------
   Set the cc_status for the results of an insn whose pattern is EXP.
   We assume that jumps don't affect the condition codes.
   All else, clobbers the condition codes, by assumption.

   We assume that ALL add, minus, etc. instructions effect the condition
   codes.
- -------------------------------------------------------------------*/
notice_update_cc (exp, insn)
rtx exp;
rtx insn;
{
    /*** recognize SET insn's ***/
    if (GET_CODE (exp) == SET) {
	/* Jumps do not alter the cc's.  */
	if (SET_DEST (exp) == pc_rtx)
	    return;

	/* Moving one register into another register (tfr):
	Doesn't alter the cc's.  */
	if (REG_P (SET_DEST (exp)) && (REG_P (SET_SRC (exp)))) {
	    return;
	}

	/* Moving memory into a register (load): Sets cc's. */
	if (REG_P (SET_DEST (exp)) && GET_CODE (SET_SRC (exp)) == MEM) {
	    cc_status.value1 = SET_SRC (exp);
	    cc_status.value2 = SET_DEST (exp);
	    return;
	}

	/* Moving register into memory (store): Sets cc's. */
	if (GET_CODE (SET_DEST (exp)) == MEM && REG_P (SET_SRC (exp))) {
	    cc_status.value1 = SET_SRC (exp);
	    cc_status.value2 = SET_DEST (exp);
	    return;
	}

	/* Function calls clobber the cc's.  */
	else if (GET_CODE (SET_SRC (exp)) == CALL) {
	    CC_STATUS_INIT;
	    return;
	}

	/* Tests and compares set the cc's in predictable ways.  */
	else if (SET_DEST (exp) == cc0_rtx) {
	    cc_status.flags = 0;
	    cc_status.value1 = SET_SRC (exp);
	    cc_status.value2 = SET_DEST (exp);
	    return;
	}

	/* Certain instructions effect the condition codes. */
	else if (GET_MODE (SET_SRC (exp)) == SImode
	    || GET_MODE (SET_SRC (exp)) == HImode) {
		switch (GET_CODE (SET_SRC (exp))) {
		case PLUS: case MINUS: case NEG:
		case AND: case IOR: case XOR:
		if (A_REG_P (SET_DEST (exp))) {
		    CC_STATUS_INIT;
		}
		else {
		    cc_status.value1 = SET_SRC (exp);
		    cc_status.value2 = SET_DEST (exp);
		}
		    break;

		default:
		    CC_STATUS_INIT;
		}
	    return;
	}
    }
    else if (GET_CODE (exp) == PARALLEL
	&& GET_CODE (XVECEXP (exp, 0, 0)) == SET) {
	    if (SET_DEST (XVECEXP (exp, 0, 0)) == pc_rtx)
		return;
	if (SET_DEST (XVECEXP (exp, 0, 0)) == cc0_rtx) {
	    CC_STATUS_INIT;
	    cc_status.value1 = SET_SRC (XVECEXP (exp, 0, 0));
	    return;
	}
    }

    /*** default action if we haven't recognized something
    and returned earlier ***/
    CC_STATUS_INIT;
}

				/* See flags.h and toplev.c */
extern int optimize;
extern int flag_combine_regs;
extern int flag_strength_reduce;
extern int flag_no_peephole;
extern int flag_inline_functions;
extern int flag_omit_frame_pointer;
extern char *main_input_filename;
extern char *asm_file_name;
				/* See c-tree.h  and c-decl.c */
extern int flag_signed_char;

#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>

void
print_options (out)
     FILE *out;
{
  char *a_time;
  long c_time;

  fprintf (out, " ;OPTIONS:\t%s%s%s%s%s%s%s%s\n",
	   (TARGET_SHORT_INT ? " -mshort_int":" -mlong_int"),
	   (TARGET_SHORT_BRANCH ? " -mshort_branch":" -mlong_branch"),
	   (optimize ? " optimize" : ""),
	   (flag_combine_regs ? " -fcombine-regs" : " !combine-regs"),
	   (flag_strength_reduce ? "" : " !strength_reduce"),
	   (flag_omit_frame_pointer ?"" :" !omit_frame_pointer"),
	   (flag_no_peephole ? "" : " peephole"),
	   (flag_inline_functions ?" inline-functions":""));
  fprintf (out, " ;OPTIONS:\t%s\n",
	   (flag_signed_char ? " signed-char" : " !signed-char"));
  fprintf (out, " ;Source:\t%s\n", main_input_filename);
  fprintf (out, " ;Destination:\t%s\n", asm_file_name);
  c_time = time (0);
  a_time = ctime (&c_time);
  fprintf (out, " ;Compiled:\t%s", a_time);
#ifdef __GNUC__
#ifndef __VERSION__
#define __VERSION__ "[unknown]"
#endif
  fprintf (out, " ; (META)compiled by GNU C version %s.\n", __VERSION__);
#else
  fprintf (out, " ; (META)compiled by CC.\n");
#endif
}

