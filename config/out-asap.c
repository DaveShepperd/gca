/* Subroutines for insn-output.c for ASAP.
   Copyright (C) 1988 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.  No author or distributor
accepts responsibility to anyone for the consequences of using it
or for whether it serves any particular purpose or works at all,
unless he says so in writing.  Refer to the GNU CC General Public
License for full details.

Everyone is granted permission to copy, modify and redistribute
GNU CC, but only under the conditions described in the
GNU CC General Public License.   A copy of this license is
supposed to have been given to you along with GNU CC so you
can know your rights and responsibilities.  It should be in a
file named COPYING.  Among other things, the copyright notice
and this notice must be preserved on all copies.  */

#include <stdio.h>
#include <tree.h>

static int func_nargs;
static int func_sargs;
static int func_slots;
static int arg_pointer_needed;
static FILE *side_door_file;

void asm_decl_func(file,name,decl)
FILE *file;
char *name;
tree decl;
{
    tree parm;
    int size;
    enum machine_mode mode;
    int funmode;
    char *parm_name;

    side_door_file = file;
    func_nargs = func_sargs = func_slots = arg_pointer_needed = 0;
    funmode = TYPE_MODE(DECL_RESULT_TYPE(decl));
    fprintf(file,"; function %s() returns %s\n",name,GET_MODE_NAME(funmode));
    if ( funmode == BLKmode ) {
	/* function returns a struct. We need to account for the slot
	*  taken to hold a pointer to the receiving struct.
	*/
	fprintf(file,"; Takes slot for struct return pointer\n");
	++func_slots;
    }
    for ( parm = DECL_ARGUMENTS(decl) ; parm ; parm = TREE_CHAIN(parm) ) {
	mode = DECL_MODE(parm);
	if ( mode == BLKmode ) {
	    size = int_size_in_bytes(DECL_ARG_TYPE(parm));
	}
	else size = GET_MODE_SIZE(DECL_MODE(parm));
	func_sargs += size;
	func_slots += (size + 3)/4;
	parm_name = DECL_PRINT_NAME(parm);
	fprintf(file,";%d) \"%s\" %d bytes, %d slots\n",func_nargs,
	    (parm_name ? parm_name : "...") ,size, (size +3) / 4);
	++func_nargs;
	if ( func_slots > ASAP_LAST_PARM_REG && !arg_pointer_needed ) {
	    /* out of regs, force an ARG_POINTER */
	    fprintf(file,"\n; %d slots, needs arg_pointer\n",func_slots);
	    arg_pointer_needed = 1;
	}
    }
    fprintf(file,"; %d parms totaling %d bytes in %d slots\n",
	func_nargs,func_sargs,func_slots);
    ASM_OUTPUT_LABEL(file,name);
}

static rtx find_addr_reg ();

/* Return the best assembler insn template
   for moving operands[1] into operands[0] as a fullword.  */

static char *
singlemove_string (operands)
     rtx *operands;
{
  if (GET_CODE (operands[0]) == MEM)
    return "st %r1,%0";
  if (GET_CODE (operands[1]) == MEM)
    return "ld %0,%1";
  return "add %0,%%0,%1";
}

/* Output assembler code to perform a doubleword move insn
   with operands OPERANDS.  */

extern void debug_rtx();

char *
output_move_double (operands)
     rtx *operands;
{
  enum { REGOP, OFFSOP, MEMOP, PUSHOP, POPOP, CNSTOP, RNDOP } optype0, optype1;
  rtx latehalf[2];
  rtx addreg0 = 0, addreg1 = 0;
#if (0)
  fprintf(stderr,"output_move_double(");
  debug_rtx(operands[0]);
  fputs(" <-\n",stderr);
  debug_rtx(operands[1]);
  fputs(")\n",stderr);
#endif
  /* First classify both operands.  */

  if (REG_P (operands[0]))
    optype0 = REGOP;
  else if (offsettable_memref_p (operands[0]))
    optype0 = OFFSOP;
  else if (GET_CODE (operands[0]) == MEM)
    optype0 = MEMOP;
  else
    optype0 = RNDOP;

  if (REG_P (operands[1]))
    optype1 = REGOP;
  else if (CONSTANT_P (operands[1])
	   || GET_CODE (operands[1]) == CONST_DOUBLE)
    optype1 = CNSTOP;
  else if (offsettable_memref_p (operands[1]))
    optype1 = OFFSOP;
  else if (GET_CODE (operands[1]) == MEM)
    optype1 = MEMOP;
  else
    optype1 = RNDOP;

  /* Check for the cases that the operand constraints are not
     supposed to allow to happen.  Abort if we get one,
     because generating code for these cases is painful.  */

  if (optype0 == RNDOP || optype1 == RNDOP)
    abort ();

  /* If an operand is an unoffsettable memory ref, find a register
     we can increment temporarily to make it refer to the second word.  */

  if (optype0 == MEMOP)
    addreg0 = find_addr_reg (operands[0]);

  if (optype1 == MEMOP)
    addreg1 = find_addr_reg (operands[1]);

  /* Ok, we can do one word at a time.
     Normally we do the low-numbered word first,
     but if either operand is autodecrementing then we
     do the high-numbered word first.

     In either case, set up in LATEHALF the operands to use
     for the high-numbered word and in some cases alter the
     operands in OPERANDS to be suitable for the low-numbered word.  */

  if (optype0 == REGOP)
    latehalf[0] = gen_rtx (REG, SImode, REGNO (operands[0]) + 1);
  else if (optype0 == OFFSOP)
    latehalf[0] = adj_offsettable_operand (operands[0], 4);
  else
    latehalf[0] = operands[0];

  if (optype1 == REGOP)
    latehalf[1] = gen_rtx (REG, SImode, REGNO (operands[1]) + 1);
  else if (optype1 == OFFSOP)
    latehalf[1] = adj_offsettable_operand (operands[1], 4);
  else if (optype1 == CNSTOP)
    {
      if (CONSTANT_P (operands[1]))
	latehalf[1] = const0_rtx;
      else if (GET_CODE (operands[1]) == CONST_DOUBLE)
	{
	  latehalf[1] = gen_rtx (CONST_INT, VOIDmode,
				 CONST_DOUBLE_HIGH (operands[1]));
	  operands[1] = gen_rtx (CONST_INT, VOIDmode,
				 CONST_DOUBLE_LOW (operands[1]));
	}
    }
  else
    latehalf[1] = operands[1];

  /* If the first move would clobber the source of the second one,
     do them in the other order.  This happens only for registers;
     such overlap can't happen in memory unless the user explicitly
     sets it up, and that is an undefined circumstance.  */

  if (optype0 == REGOP && optype1 == REGOP
      && REGNO (operands[0]) == REGNO (latehalf[1]))
    {
      /* Make any unoffsettable addresses point at high-numbered word.  */
      if (addreg0)
	output_asm_insn ("add %0,%0,4", &addreg0);
      if (addreg1)
	output_asm_insn ("add %0,%0,4", &addreg1);

      /* Do that word.  */
      output_asm_insn (singlemove_string (latehalf), latehalf);

      /* Undo the adds we just did.  */
      if (addreg0)
	output_asm_insn ("sub %0,%0,4", &addreg0);
      if (addreg1)
	output_asm_insn ("sub %0,%0,4", &addreg0);

      /* Do low-numbered word.  */
      return singlemove_string (operands);
    }

  /* Normal case: do the two words, low-numbered first.  */

  output_asm_insn (singlemove_string (operands), operands);

  /* Make any unoffsettable addresses point at high-numbered word.  */
  if (addreg0)
    output_asm_insn ("add %0,%0,4", &addreg0);
  if (addreg1)
    output_asm_insn ("add %0,%0,4", &addreg1);

  /* Do that word.  */
  output_asm_insn (singlemove_string (latehalf), latehalf);

  /* Undo the adds we just did.  */
  if (addreg0)
    output_asm_insn ("sub %0,%0,4", &addreg0);
  if (addreg1)
    output_asm_insn ("sub %0,%0,4", &addreg1);

  return "";
}

/* Return a REG that occurs in ADDR with coefficient 1.
   ADDR can be effectively incremented by incrementing REG.  */

static rtx
find_addr_reg (addr)
     rtx addr;
{
  while (GET_CODE (addr) == PLUS)
    {
      if (GET_CODE (XEXP (addr, 0)) == REG)
	addr = XEXP (addr, 0);
      if (GET_CODE (XEXP (addr, 1)) == REG)
	addr = XEXP (addr, 1);
      if (CONSTANT_P (XEXP (addr, 0)))
	addr = XEXP (addr, 1);
      if (CONSTANT_P (XEXP (addr, 1)))
	addr = XEXP (addr, 0);
    }
  if (GET_CODE (addr) == REG)
    return addr;
  return 0;
}


static char * addr_q[] = {
    "<illegit>", "REG", "SYMBOL", "REG[INDEX/OFFSET]", "INDEXED", "OFFSET"};

#define STRICT_INDEX_TERM_P(MODE, X)  \
  ((GET_CODE (X) == MULT					\
    && ((REG_P (XEXP (X, 0))					\
         && REGNO (XEXP (X, 0)) < FIRST_PSEUDO_REGISTER		\
         && GET_CODE (XEXP (X, 1)) == CONST_INT			\
         && INTVAL (XEXP (X, 1)) <= 4				\
         && (INTVAL (XEXP (X, 1)) == GET_MODE_SIZE (MODE)))	\
        || (REG_P (XEXP (X, 1))					\
	    && REGNO (XEXP (X, 1)) < FIRST_PSEUDO_REGISTER		\
            && GET_CODE (XEXP (X, 0)) == CONST_INT		\
            && INTVAL (XEXP (X, 0)) <= 4			\
            && (INTVAL (XEXP (X, 0)) == GET_MODE_SIZE (MODE))	\
	      && (warning ("MULT backwards"), 1))))		\
  || (REG_P (X) && REGNO (XEXP (X, 0)) < FIRST_PSEUDO_REGISTER && GET_MODE_SIZE (MODE) == 1))

extern char *mode_name[];

int
legit_addr_p(mode,x,line,file,strict)
enum machine_mode mode;
rtx x;
int line;
char *file;
int strict;
{

  int retval;
  extern void debug_rtx();

  retval = 0;
  if ( strict == 0 ) {
      if (GET_CODE (x) == REG) retval = 1;
      else if (GET_CODE (x) == SYMBOL_REF && (x)->unchanging) retval = 2;
      else if (GET_CODE (x) == PLUS
	  && REG_P (XEXP (x, 0))
	  && (  (VALID_OFFSET_P(mode, XEXP (x, 1)))
	     || (INDEX_TERM_P (mode, XEXP (x, 1))))) retval = 3;
      else if (INDEX_TERM_P (mode, x)) retval = 4;
      else if (VALID_OFFSET_P (mode, x))	retval = 5;
  } else {
    /* strict means don't accept psuedo-regs */
      if (GET_CODE (x) == REG && REGNO(x) < FIRST_PSEUDO_REGISTER ) retval = 1;
      else if (GET_CODE (x) == SYMBOL_REF && (x)->unchanging) retval = 2;
      else if (GET_CODE (x) == PLUS
	  && REG_P (XEXP (x, 0))
	  && REGNO (XEXP (x, 0)) < FIRST_PSEUDO_REGISTER
	  && (  (VALID_OFFSET_P(mode, XEXP (x, 1)))
	     || (STRICT_INDEX_TERM_P (mode, XEXP (x, 1))))) retval = 3;
      else if (STRICT_INDEX_TERM_P (mode, x)) retval = 4;
      else if (VALID_OFFSET_P (mode, x))	retval = 5;
  }
#if (1)
  fprintf(stderr,"\n%s:%d: %slegit_addr_p(%s,",file,line,
    strict ? "strict_" : "",mode_name[mode]);
  debug_rtx(x);
  fprintf(stderr,") = %s\n",addr_q[retval]);
#endif
  return retval;
}

int legit_const_p(x,dbltype,line,file)
rtx x;
int dbltype,line;
char *file;
{
 int retval;
 extern void debug_rtx();

 retval = (GET_CODE (x) != dbltype);

 fprintf(stderr,"\n%s:%d: legit_const_p(",file,line);
 debug_rtx(x);
 fprintf(stderr,") = %d\n",retval);
 return retval;
}

/*	Following is function version of the macro FUNCTION_PROLOGUE
*	defined in tm.h and invoked in final.c. It has been put here
*	so I could play with it without re-making the whole mess.
*/
extern int frame_pointer_needed;
extern int current_function_args_size;
       int asap_last_named_arg;
       int asap_anonymous_args;
static int asap_anonymous_args_size;
static int asap_ap_in_use;
static int asap_ap_offset;
static unsigned long asap_saved_reg_mask;
static int asap_stack_size;
static int asap_stack_extra;
static int asap_variable_stack;

void
name_regs(file,which_regs)
FILE *file;
unsigned char *which_regs;
{
    int i;
    int nregs = 0;

    for ( i = 0 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {
	if ( *which_regs++ ) {
	    if ( nregs == 0 ) fputc('[',file);
	    else fputc(',',file);
	    fputs(reg_names[i],file);
	    ++nregs;
	}
    }
    fprintf(file,"%s(%d total)\n",(nregs ? "]" : "<none>"),nregs);
}

void
show_reg_mask(file,which_regs)
FILE *file;
unsigned long which_regs;
{
    int i;

    if ( which_regs == 0 ) {
        fputs("<none>\n",file);
        return;
    }
    fputc('[',file);
    for ( i = 0 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {
	if ( which_regs & 1 ) {
	    fputs(reg_names[i],file);
	    if ( which_regs == 1 ) break;
	    else fputc(',',file);
	}
	which_regs >>= 1;
    }
    fputs("]\n",file);
}

void
emit_function_prologue(file,size)
FILE *file;
int size;
{
  extern char call_used_regs[];
  extern int current_function_pretend_args_size;
  extern int may_call_alloca;
  int fsize = (size + 3) & ~3;
  int nregs, i;
  int true_size;
  unsigned long reg_mask;
  fprintf(file,";regs_ever_live = ");
  name_regs(file,regs_ever_live);
  fprintf(file,"; args_size = %d\n",current_function_args_size);
  fprintf(file,"; pretend_args_size = %d\n",current_function_pretend_args_size);
  fprintf(file,"; size of locals %d (%d)\n",size,fsize);
  if ( may_call_alloca ) fputs("; may call alloca\n",file);
  if ( arg_pointer_needed ) {
    fputs("; arg pointer needed, hence\n",file);
    frame_pointer_needed = 1;
  }
  if ( frame_pointer_needed ) fputs("; frame pointer needed\n",file);
  reg_mask = 0;
  for ( nregs = 0, i = FIRST_PSEUDO_REGISTER-1 ; i > 0 ; --i ) {
    if (regs_ever_live[i] && !call_used_regs[i]) {
	reg_mask |= 1;
	++nregs;
    }
    reg_mask <<= 1;
  }
  if (frame_pointer_needed && !regs_ever_live[FRAME_POINTER_REGNUM]) {
    reg_mask |= (1L << FRAME_POINTER_REGNUM);
    asap_ap_in_use = FRAME_POINTER_REGNUM;
    ++nregs;
  }
/*  if ( arg_pointer_needed && !regs_ever_live[ARG_POINTER_REGNUM])++nregs; */
  fprintf(file,";saved_reg_mask =");
  show_reg_mask(file,asap_saved_reg_mask = reg_mask);
  asap_stack_size = (nregs * 4) + fsize;
  fprintf(file,";asap_stack_size = %d\n",asap_stack_size);
  fprintf(file,";asap_last_named_arg = %d\n",asap_last_named_arg);
  true_size = asap_stack_size + current_function_pretend_args_size;
  if ( asap_last_named_arg < ASAP_LAST_PARM_REG
       && asap_last_named_arg < func_slots ) {
    /* the last named arg was not the last arg, we need to spill it
    *  for varargs.
    */
    asap_anonymous_args = (ASAP_LAST_PARM_REG-asap_last_named_arg);
    asap_anonymous_args_size = (asap_anonymous_args*4);
    true_size += asap_anonymous_args_size;
  }
  if (true_size != 0)
    fprintf (file, "\tSUB %s,%s,%d\n",reg_names[STACK_POINTER_REGNUM],
      reg_names[STACK_POINTER_REGNUM],true_size);
  while ( asap_anonymous_args ) {
    fprintf(file,"\tST %s,%s[%d] ; anon arg %d\n",
      reg_names[asap_anonymous_args+asap_last_named_arg],
      reg_names[STACK_POINTER_REGNUM],
      asap_stack_size+current_function_pretend_args_size+
        (asap_anonymous_args*4) - 4,
      asap_anonymous_args);
    --asap_anonymous_args;
  }
  for ( i = 1 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {
    if ( (reg_mask >>= 1) == 0 ) break;
    if ( reg_mask & 1 ) {
      fprintf (file, "\tST %s,%s[%d]\n",reg_names[i],
        reg_names[STACK_POINTER_REGNUM],--nregs*4+fsize);}
  }
/*  if ( arg_pointer_needed ) fprintf(file, "\tADD %s,%s,%d\n",
       reg_names[ARG_POINTER_REGNUM],
       reg_names[STACK_POINTER_REGNUM],
       true_size-current_function_pretend_args_size);
*/
  if ( frame_pointer_needed ) fprintf(file, "\tADD %s,%s,0\n",
       reg_names[FRAME_POINTER_REGNUM],reg_names[STACK_POINTER_REGNUM]);
}

void
emit_function_epilogue(file, size)
FILE *file;
int size;
{
  extern char call_used_regs[];
  extern int current_function_pretend_args_size;
  int fsize = (size + 3) & ~3;
  int nregs, i, j;
  for ( nregs = 0, i = 1 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {
    if (regs_ever_live[i] && !call_used_regs[i]) ++nregs;}
  if ( frame_pointer_needed && !regs_ever_live[FRAME_POINTER_REGNUM] )++nregs;
/*  if ( arg_pointer_needed && !regs_ever_live[ARG_POINTER_REGNUM] )++nregs; */
  j = nregs*4 + fsize + current_function_pretend_args_size +
     asap_anonymous_args_size;
  if ( frame_pointer_needed ) fprintf(file, "\tADD %s,%s,0\n",
       reg_names[STACK_POINTER_REGNUM],reg_names[FRAME_POINTER_REGNUM]);
  for ( i = 1 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {
    if ((regs_ever_live[i] && !call_used_regs[i]) ||
/*	(arg_pointer_needed && i == ARG_POINTER_REGNUM) || */
	(frame_pointer_needed && i == FRAME_POINTER_REGNUM)) {
      fprintf (file, "\tLD %s,%s[%d]\n",reg_names[i],
	      reg_names[STACK_POINTER_REGNUM],--nregs*4+fsize);}}
  fprintf (file, "\tJSR %%0,%s[0]\n",reg_names[RETURN_POINTER_REGNUM]);
  fprintf (file, "\tADD %s,%s,%d\n",reg_names[STACK_POINTER_REGNUM],
    reg_names[STACK_POINTER_REGNUM],j);
  asap_ap_in_use = 0;
  asap_ap_offset = 0;
  arg_pointer_needed = 0;
  asap_anonymous_args = 0;
  asap_anonymous_args_size = 0;
  asap_last_named_arg = 0;
}

void
bad_operand(x,why)
rtx x;
char *why;
{
    debug_rtx(x);
    fatal(why);
}

#ifndef ASAP_MAX_FRAME_OFFSET 
#define ASAP_MAX_FRAME_OFFSET (0xFFE0)
#endif

/* asap_print_operand_address() is here to allow hacking it without
*  re-compiling everything in sight, as would happen if it were a
*  macro in tm-asap.h. The version below is taken from the original,
*  with a few tweaks from the ARGP_kluges from Miessner at DG.
*/
void
asap_print_operand_address(file,addr)
FILE *file;
register rtx addr;
{ register rtx base, index = 0;
  int offset = 0;
  register rtx reg0,reg1;

  switch (GET_CODE (addr)) {
    case REG:
    {
#if ARG_POINTER_REGNUM > FRAME_POINTER_REGNUM
      if ( REGNO (addr) == ARG_POINTER_REGNUM) {
	/* Need to kluge arg_pointer[0] reference */
	switch ( asap_ap_in_use ) {
	    case FRAME_POINTER_REGNUM:
	    case STACK_POINTER_REGNUM:
		fprintf(file,"%s[%d]",reg_names[asap_ap_in_use],asap_ap_offset);
		break;
	    default:
		bad_operand (
		  addr,"PRINT_OPERAND_ADDRESS, need arg-pointer surrogate");
	  }
      }
      else 
#endif
      fprintf (file, "%s[0]", reg_names[REGNO (addr)]);
      break;
    }
    case PLUS:
    {
      reg0 = XEXP (addr, 0);
      reg1 = XEXP (addr, 1);
      if ( GET_CODE (reg0) == MULT || GET_CODE (reg0) == CONST_INT) {
	/* somehow the RTL got swapped, get simple reg in reg0 */
	rtx tmp = reg0;
	reg0 = reg1;
	reg1 = tmp;
      }
      if ( !REG_P (reg0) ) bad_operand( addr, "PRINT_OPERAND_ADDRESS, non-reg base[]");
      base = reg0;
      if (GET_CODE (reg1) == CONST_INT)
	offset = INTVAL (reg1);
      else {
	index = reg1;
      }
      if (index && GET_CODE (index) == MULT)
	{
	  if (GET_CODE (XEXP (index, 0)) == REG)
	    index = XEXP (index, 0);
	  else if (GET_CODE (XEXP (index, 1)) == REG)
	    index = XEXP (index, 1);
	  else bad_operand (addr,"PRINT_OPERAND_ADDRESS, Bogus MULT of non-reg");
#if (ARG_POINTER_REGNUM > FRAME_POINTER_REGNUM)
	  if ( REGNO (index) == ARG_POINTER_REGNUM ) {
	      bad_operand (addr,"PRINT_OPERAND_ADDRESS, cannot mul psuedo-ap");
	  }	
#endif
	}
#if (ARG_POINTER_REGNUM > FRAME_POINTER_REGNUM)
      if ( REGNO (base) == ARG_POINTER_REGNUM ) {
	/* We need to substitute a surrogate reg for the non-existent arg-
	*  pointer. If there is no index, then we just add the offset.
	*  otherwise, we're scrod!
	*/
	if ( index ) bad_operand (addr,"PRINT_OPERAND_ADDRESS, cannot fixup AP[reg]");
	if ( (asap_ap_offset) > ASAP_MAX_FRAME_OFFSET ) {
	    bad_operand (addr,"PRINT_OPERAND_ADDRESS, frame too big for AP kluge");
	}
	switch ( asap_ap_in_use ) {
	    case FRAME_POINTER_REGNUM:
	    case STACK_POINTER_REGNUM:
		fprintf(file,"%s[",reg_names[asap_ap_in_use]);
		offset = asap_ap_offset;
		break;
	    default:
		bad_operand(addr,"PRINT_OPERAND_ADDRESS, need arg-pointer surrogate");
	  }
      }
      else
#endif
      fprintf (file, "%s[", reg_names[REGNO (base)]);
      if (index == 0)
	fprintf (file, "%d]", offset);
      else
	fprintf (file, "%s]", reg_names[REGNO (index)]);
      break;
    }
    case MULT:
    {
      reg0 = XEXP (addr, 0);
      reg1 = XEXP (addr, 1);
      if ( !REG_P (reg0) ) bad_operand(addr,"PRINT_OPERAND_ADDRESS, MULT of non-reg");
#if (ARG_POINTER_REGNUM > FRAME_POINTER_REGNUM)
      if ( REGNO (reg0) == ARG_POINTER_REGNUM)
	bad_operand(addr,"PRINT_OPERAND_ADDRESS, MULT of non-existant AP");
#endif
      fprintf (file, "%s[%s]", reg_names[0],reg_names[REGNO (reg0)]);
      break;
    }
    case CONST_INT:
    {
      fprintf (file, "%s[%d]", reg_names[0],INTVAL (addr));
      break;
    }
    default:
    {
      fprintf(stderr,"asap_print_operand_address() can't handle:");
      debug_rtx(addr);
      fprintf (file, "%s[",reg_names[0]);
      output_addr_const (file, addr);
      fprintf (file, "] ; kluge for literals");
      break;
    }
  } /* end switch */
}

/* Resolve an offset based on the pseudo argument pointer to one based
   off of either the frame pointer or stack pointer as appropriate.  */

void
output_arg_ptr (offset)
     int offset;		/* offset from the arg. pointer in bytes */
{

  if ( side_door_file ) {
    fprintf(side_door_file,"; fixing up AP[%d] to be:",offset);
  }
  offset += asap_stack_size;
  if (!(asap_saved_reg_mask & (1 << FRAME_POINTER_REGNUM)) )
    {
      if (asap_variable_stack)
	error ("Arg pointer referenced when frame omitted and variable stack allocated");

      offset += asap_stack_extra;
      asap_ap_in_use = STACK_POINTER_REGNUM;
      if ( side_door_file ) fprintf(side_door_file," SP[%d]\n",offset);
    }
  else
    {
      asap_ap_in_use = FRAME_POINTER_REGNUM;
      if ( side_door_file ) fprintf(side_door_file," FP[%d]\n",offset);
    }

  if ( offset < 0 ) fatal ("output_arg_ptr, computes negative offset");
  if ( offset > 0xFFE0 ) fatal ("AP offset too large");
  asap_ap_offset = offset;
  return;
}

