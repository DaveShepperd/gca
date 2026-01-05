/* Definitions of target machine for GNU compiler (1.40), for ASAP chip.
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


/* Note that some other tm- files include this one and then override
   many of the definitions that relate to assembler syntax.  */


/* Names to predefine in the preprocessor for this target machine.  */

#define CPP_PREDEFINES "-Dasap"

#define DBX_DEBUGGING_INFO

#define ASM_SPEC "-r %{!nolist:-l %b.lis} "
#define CC1_SPEC "%{!use-frame:-fomit-frame-pointer}"
#define STANDARD_MACHINE_SUFFIX "asap-"

/*	The following was hacked into final.c, to allow some notice of
*	source line and filename to be injected into the assembly code,
*	even if not using one of the "approved" debuggers.
*/
#define ASM_NOTE_SOURCE_LINE(FILE, LINE, FILENAME)\
  fprintf(file,";#line %d \"%s\"\n",(LINE),(FILENAME))

/* Print subsidiary information on the compiler version in use.  */
#define TARGET_VERSION fprintf (stderr," (%s silicon ASAP target)",\
 (target_flags &1) ? "1st" : "2nd");

/* define the following to get trace of calls to LEGITIMATE_CONSTANT_P */
/* #define DEBUG_LEGIT_CONST */
/* define the following to get trace of calls to GO_IF_LEGITIMATE_ADDRESS */
/* #define DEBUG_LEGIT_ADDR */

/* Implicit library calls should use memcpy, not bcopy, etc.  */

#define TARGET_MEM_FUNCTIONS

#define ASM_IDENTIFY_GCC(x)  fputs ("; compiled by gcc 1.40 ASAP\n", x)

/* Run-time compilation parameters selecting different hardware subsets.

   On the ASAP, The first-silicon has a bug related to ASHL.C, suppress
    generation of that instruction if -mrev1 is set.  */

extern int target_flags;

/* Macro to define tables used to set the flags.
   This is a list in braces of pairs in braces,
   each pair being { "NAME", VALUE }
   where VALUE is the bits to set or minus the bits to clear.
   An empty string NAME is used to identify the default VALUE.  */

#define TARGET_SWITCHES  { { "rev1", 1}, { "", TARGET_DEFAULT}}
#define TARGET_ASHL_BUG (target_flags & 1)
#define TARGET_DEFAULT (0)

/* target machine storage layout */

/* Define this if most significant bit is lowest numbered
   in instructions that operate on numbered bit-fields.
   This is a moot question on the ASAP due to the lack of bit-field insns.  */
/* #define BITS_BIG_ENDIAN */

/* Define this if most significant byte of a word is the lowest numbered.  */
/* That is not true on ASAP.  */
/* #define BYTES_BIG_ENDIAN */

/* Define this if most significant word of a multiword number is numbered.  */
/* For ASAP we can decide arbitrarily
   since there are no machine instructions for them.  */
/* #define WORDS_BIG_ENDIAN */

/* number of bits in an addressible storage unit */
#define BITS_PER_UNIT 8

/* Width in bits of a "word", which is the contents of a machine register.
   Note that this is not necessarily the width of data type `int';
   if using 16-bit ints on a 68000, this would still be 32.
   But on a machine with 16-bit registers, this would be 16.  */
#define BITS_PER_WORD 32

/* Width of a word, in units (bytes).  */
#define UNITS_PER_WORD 4

/* Width in bits of a pointer.
   See also the macro `Pmode' defined below.  */
#define POINTER_SIZE 32

/* Allocation boundary (in *bits*) for storing pointers in memory.  */
#define POINTER_BOUNDARY 32

/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
#define PARM_BOUNDARY 32

/* Boundary (in *bits*) on which stack pointer should be aligned.  */
#define STACK_BOUNDARY 32

/* Allocation boundary (in *bits*) for the code of a function.  */
#define FUNCTION_BOUNDARY 32

/* Alignment of field after `int : 0' in a structure.  */
#define EMPTY_FIELD_BOUNDARY 32

/* Every structure's size must be a multiple of this.  */
#define STRUCTURE_SIZE_BOUNDARY 8

/* No data type wants to be aligned rounder than this.  */
#define BIGGEST_ALIGNMENT 32

/* Define this if move instructions will actually fail to work
   when given unaligned data.  */
#define STRICT_ALIGNMENT

/* Standard register usage.  */

/* Number of actual hardware registers.
   The hardware registers are assigned numbers for the compiler
   from 0 to just below FIRST_PSEUDO_REGISTER.
   All registers that the compiler knows about must be given numbers,
   even those that are not normally considered general registers.

   ASAP has 32 fullword registers (including the reserved REGS 0,30,31) */

#define FIRST_PSEUDO_REGISTER 32

/* 1 for registers that have pervasive standard uses
*   and are not available for the register allocator.
*   On ASAP, this includes R0 (hardwired 0) and the Interrupt
*   return registers R30 and R31. It also includes the software convention
*   of R29 being the stack pointer, and R28 the return register,
*   R30 is the fake ARG_POINTER register,
*   and R27 being the (optional) frame pointer and R26 being the literal pool
*   pointer.
*	As of Mar 20, 1989, it does _not_ include R28, which will get saved
*   iff a procedure is called. The function_prolog below is simpler if the
*   (clobber (reg:SI 28 )) (note hard-coded RETURN_POINTER_REGNUM) in "call"
*   does the trick.
*/
#define FIXED_REGISTERS  \
 {1, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 1, 0, 0, 1, 1, 1 }

/* 1 for registers not available across function calls.
   These must include the FIXED_REGISTERS and also any
   registers that can be used without being saved.
   The latter must include the registers where values are returned
   and the register where structure-value addresses are passed.
   Aside from that, you can include as many other registers as you like.  */
/* For ASAP, we (for now) define R1-R10 as CALL_USED, expecting return values
   in R1 (& R2) and Params/temps in the rest. */
#define CALL_USED_REGISTERS  \
 {1, 1, 1, 1, 1, 1, 1, 1, \
  1, 1, 1, 0, 0, 0, 0, 0, \
  0, 0, 0, 0, 0, 0, 0, 0, \
  0, 0, 1, 0, 0, 1, 1, 1 }

#define ASAP_LAST_PARM_REG (5)

/* Return number of consecutive hard regs needed starting at reg REGNO
   to hold something of mode MODE.
   This is ordinarily the length in words of a value of mode MODE
   but can be less for certain modes in special long registers.

   On ASAP, all registers are ordinary registers holding 32 bits worth. */
#define HARD_REGNO_NREGS(REGNO, MODE)   \
    ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)

/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.
   On ASAP, the cpu registers can hold any mode. */
#define HARD_REGNO_MODE_OK(REGNO, MODE) 1

/* Value is 1 if it is a good idea to tie two pseudo registers
   when one has mode MODE1 and one has mode MODE2.
   If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,
   for any hard reg, then this must be 0 for correct output.  */
#define MODES_TIEABLE_P(MODE1, MODE2) 1

/* Specify the registers used for certain standard purposes.
   The values of these macros are register numbers.  */

/* ASAP pc isn't overloaded on a register that the compiler knows about.  */
/* #define PC_REGNUM  */

/* Register to use for pushing function arguments.  */
#define STACK_POINTER_REGNUM 29

/* Base register for access to local variables of the function. If used, the
   ASAP convention is R27 */
#define FRAME_POINTER_REGNUM 27

/* Value should be nonzero if functions must have frame pointers.
   Zero means the frame pointer need not be set up (and parms
   may be accessed via the stack pointer) in functions that seem suitable.
   This is computed in `reload', in reload1.c.  */
#define FRAME_POINTER_REQUIRED 0

/* Base register for access to arguments of the function.  */
/* The documentation is very confusing here. If the arg_pointer is the
   Frame pointer, which is only a software convention, does it have to
   be a fixed reg (ARG_POINTER.. says yes) or not (FRAME_POINTER... says no) */
/* On ASAP, we are going to lie and say the ARG_POINTER is one of the
   interrupt link registers. The idea is to fix-up the assembly just before
   output to reference the FRAME_POINTER (or STACK_POINTER) with the size
   of the locals added in. This will get seriously messy if the ARG_POINTER
   is being used in anything more exotic than REG[OFFSET] mode. */

#define ARG_POINTER_REGNUM 30

/* Register in which static-chain is passed to a function.  */
/* ??? was the SPUR comment. If I ever get an ALGOL-60 front-end I'll use R25.*/
#define STATIC_CHAIN_REGNUM 25

/* ASAP does not stack a return address for "call", but simply sticks it
   in a register. This _should_ define which one, but the programs which
   process the machine description can't cope, so be sure you hack asap.md
   to match if you change this (4 places, (clobber (reg:SI 28))). */
#define RETURN_POINTER_REGNUM 28

/* Register in which address to store a structure value
   is passed to a function. On ASAP, we use R1 for this. Why not? If a function
   is returning a structure, it sure isn't returning a scalar */
#define STRUCT_VALUE_REGNUM 1

/* Define the classes of registers for register constraints in the
   machine description.  Also define ranges of constants.

   One of the classes must always be named ALL_REGS and include all hard regs.
   If there is more than one class, another class must be named NO_REGS
   and contain no registers.

   The name GENERAL_REGS must be the name of a class (or an alias for
   another name such as ALL_REGS).  This is the class of registers
   that is allowed by "g" or "r" in a register constraint.
   Also, registers outside this class are allocated only when
   instructions express preferences for them.

   The classes must be numbered in nondecreasing order; that is,
   a larger-numbered class must never be contained completely
   in a smaller-numbered class.

   For any two classes, it is very desirable that there be another
   class that represents their union.  */
   
/* The ASAP has only one kind of registers, hence really only one class.  */

enum reg_class { NO_REGS, ALL_REGS, LIM_REG_CLASSES };

#define N_REG_CLASSES (int) LIM_REG_CLASSES
#define GENERAL_REGS ALL_REGS
/* Give names of register classes as strings for dump file.   */

#define REG_CLASS_NAMES  {"NO_REGS", "ALL_REGS" }

/* Define which registers fit in which classes.
   This is an initializer for a vector of HARD_REG_SET
   of length N_REG_CLASSES.  */

#define REG_CLASS_CONTENTS { 0, 0xFFFFFFFF }

/* The same information, inverted:
   Return the class number of the smallest class containing
   reg number REGNO.  This could be a conditional expression
   or could index an array.  */

#define REGNO_REG_CLASS(REGNO) ALL_REGS

/* The class value for index registers, and the one for base regs.  */
#define INDEX_REG_CLASS GENERAL_REGS
#define BASE_REG_CLASS GENERAL_REGS

/* Get reg_class from a letter such as appears in the machine description.  */
/* ASAP has no register "classes", so this should never be invoked */
#define REG_CLASS_FROM_LETTER(C) NO_REGS

/* The letters I, J, K, L and M in a register constraint string
   can be used to stand for particular ranges of immediate operands.
   This macro defines what the ranges are.
   C is the letter, and VALUE is a constant value.
   Return 1 if VALUE is in the range specified by C.

   For ASAP:
	`I' is used for the range of constants an insn can actually contain.
	`J' is the expanded range gotten by shifting left once
	`K' is the expanded range gotten by shifting left twice
	`L' is the one's complement of `I' (for logical ops)
	`M' is the two's complement of `I' (for ADD/SUB)
*/

#define CONST_OK_FOR_LETTER_P(VALUE, C)  \
  (  ( (C) == 'I' && (unsigned) (VALUE) < 0xFFE0 )	\
  || ( (C) == 'J' && (unsigned) (VALUE) < 0x1FFC0 && !((VALUE) & 1) )  \
  || ( (C) == 'K' && (unsigned) (VALUE) < 0x3FF80 && !((VALUE) & 3) )  \
  || ( (C) == 'L' && ~((unsigned) (VALUE)) < 0xFFE0 )  \
  || ( (C) == 'M' &&  (VALUE) < 0 && (VALUE) > -0xFFE0 ) )

/* Similar, but for floating constants, and defining letters G and H.
   Here VALUE is the CONST_DOUBLE rtx itself.  */

#define CONST_DOUBLE_OK_FOR_LETTER_P(VALUE, C)  0

/* Given an rtx X being reloaded into a reg required to be
   in class CLASS, return the class of reg to actually use.
   In general this is just CLASS; but on some machines
   in some cases it is preferable to use a more restrictive class.  */
#define PREFERRED_RELOAD_CLASS(X,CLASS) (CLASS)

/* Return the maximum number of consecutive registers
   needed to represent mode MODE in a register of class CLASS.  */
/* On ASAP, this is the size of MODE in words */

#define CLASS_MAX_NREGS(CLASS, MODE)	\
  ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)

/* Stack layout; function entry, exit and calling.  */

/* Define this if pushing a word on the stack
   makes the stack pointer a smaller address.  */
#define STACK_GROWS_DOWNWARD

/* Define this if the nominal address of the stack frame
   is at the high-address end of the local variables;
   that is, each additional local variable allocated
   goes at a more negative offset in the frame.  */
/* #define FRAME_GROWS_DOWNWARD */

/* Offset within stack frame to start allocating local variables at.
   If FRAME_GROWS_DOWNWARD, this is the offset to the END of the
   first local allocated.  Otherwise, it is the offset to the BEGINNING
   of the first local allocated.  */
#define STARTING_FRAME_OFFSET 0

/* If we generate an insn to push BYTES bytes,
   this says how many the stack pointer really advances by.
   On SPUR, don't define this because there are no push insns.  */
/* ASAP similarly lacks push _instructions_, but a push _macro_ would round
   to a longword. What to do??? */
/*  #define PUSH_ROUNDING(BYTES) */

/* Offset of first parameter from the argument pointer register value.  */
/* This is actually quite useless for ASAP, or any machine that uses positive-
*  only offsets. The _real_ offset will be calculated by the ARGP_kluges.
*  We need to add an offset to the frame-pointer (or stack-pointer) based
*  on the size of locals and number of registers actually saved
*/

#define FIRST_PARM_OFFSET(fndecl) (0)

/* Value is 1 if returning from a function call automatically
   pops the arguments described by the number-of-args field in the call.
   FUNTYPE is the data type of the function (as a tree),
   or for a library call it is an identifier node for the subroutine name.  */

#define RETURN_POPS_ARGS(FUNTYPE) 0

/* Define how to find the value returned by a function.
   VALTYPE is the data type of the value (as a tree).
   If the precise function being called is known, FUNC is its FUNCTION_DECL;
   otherwise, FUNC is 0.  */

/* On ASAP, the value is found in the R1 (or R1 and R2).  */

#define FUNCTION_VALUE(VALTYPE, FUNC)  \
  gen_rtx (REG, TYPE_MODE (VALTYPE), 1)

/* No windows, so no "outgoing_value" */

/* #define FUNCTION_OUTGOING_VALUE(VALTYPE, FUNC)  \
  gen_rtx (REG, TYPE_MODE (VALTYPE), 11) */

/* Define how to find the value returned by a library function
   assuming the value has mode MODE.  */

#define LIBCALL_VALUE(MODE)  gen_rtx (REG, MODE, 1)

/* 1 if N is a possible register number for a function value
   as seen by the caller.
   On ASAP, R1 is the only register thus used.  */

#define FUNCTION_VALUE_REGNO_P(N) ((N) == 1)
/* 1 if N is a possible register number for function argument passing.
   On SPUR, these are the "output" registers.  */

#define FUNCTION_ARG_REGNO_P(N) ((N) <= ASAP_LAST_PARM_REG && (N) > 0)

/* Define a data type for recording info about an argument list
   during the scan of that argument list.  This data type should
   hold all necessary information about the function itself
   and about the args processed so far, enough to enable macros
   such as FUNCTION_ARG to determine where the next arg should go.

   On ASAP, this is a single integer, which is a number of words
   of arguments scanned so far (including the invisible argument,
   if any, which holds the structure-value-address).
   Thus (ASAP_LAST_PARM_REG) (5) or more means all following args should
   go on the stack.  */

#define CUMULATIVE_ARGS int

/* Initialize a variable CUM of type CUMULATIVE_ARGS
   for a call to a function whose data type is FNTYPE.
   For a library call, FNTYPE is 0.

   On ASAP, the offset normally starts at 0, but starts at 4 bytes
   when the function gets a structure-value-address as an
   invisible first argument.  */

#define INIT_CUMULATIVE_ARGS(CUM,FNTYPE)	\
 ((CUM) = ((FNTYPE) != 0 && TYPE_MODE (TREE_TYPE (FNTYPE)) == BLKmode))

/* Update the data in CUM to advance over an argument
   of mode MODE and data type TYPE.
   (TYPE is null for libcalls where that information may not be available.)  */

#define FUNCTION_ARG_ADVANCE(CUM, MODE, TYPE, NAMED)	\
 ((CUM) += ((MODE) != BLKmode			\
	    ? (GET_MODE_SIZE (MODE) + 3) / 4	\
	    : (sizeof(/*size_in_bytes (*/TYPE) + 3) / 4))

/* Determine where to put an argument to a function.
   Value is zero to push the argument on the stack,
   or a hard register in which to store the argument.

   MODE is the argument's machine mode.
   TYPE is the data type of the argument (as a tree).
    This is null for libcalls where that information may
    not be available.
   CUM is a variable of type CUMULATIVE_ARGS which gives info about
    the preceding args and about the function being called.
   NAMED is nonzero if this argument is a named parameter
    (otherwise it is an extra parameter matching an ellipsis).  */

/* On SPUR the first five words of args are normally in registers
   and the rest are pushed.  But any arg that won't entirely fit in regs
   is pushed.  */

#define FUNCTION_ARG(CUM, MODE, TYPE, NAMED)		\
(ASAP_LAST_PARM_REG >= ((CUM)						\
       + ((MODE) == BLKmode				\
	  ? (sizeof(/*size_in_bytes (*/TYPE) + 3) / 4		\
	  : (GET_MODE_SIZE (MODE) + 3) / 4))		\
 ? gen_rtx (REG, (MODE), 1 + (CUM))			\
 : 0)

/* Define where a function finds its arguments.
   This is different from FUNCTION_ARG because of register windows.  */
/* ASAP does not have windows, but it does pass args in registers,
*  and must account for this when dealing with a varargs function. Yucch!
*/
extern int asap_last_named_arg;
#define FUNCTION_INCOMING_ARG(CUM, MODE, TYPE, NAMED)\
(((NAMED) && (ASAP_LAST_PARM_REG >= ((CUM)				\
       + ((MODE) == BLKmode				\
	  ? (sizeof(/*size_in_bytes (*/TYPE) + 3) / 4		\
	  : (GET_MODE_SIZE (MODE) + 3) / 4))))		\
 ? gen_rtx (REG, (MODE), (asap_last_named_arg = 1 + (CUM))) \
 : 0)


/* For an arg passed partly in registers and partly in memory,
   this is the number of registers used.
   For args passed entirely in registers or entirely in memory, zero.  */

#define FUNCTION_ARG_PARTIAL_NREGS(CUM, MODE, TYPE, NAMED) 0

/* This macro generates the assembly code for function entry.
   FILE is a stdio stream to output the code to.
   SIZE is an int: how many units of temporary storage to allocate.
   Refer to the array `regs_ever_live' to determine which registers
   to save; `regs_ever_live[I]' is nonzero if register number I
   is ever used in the function.  This macro is responsible for
   knowing which registers should not be saved even if used.  */

#ifdef FUNCTION_PROLOGUE_IS_MACRO
#define FUNCTION_PROLOGUE(FILE, SIZE)	\
{								\
  static char *reg_names[] = REGISTER_NAMES;			\
  extern char call_used_regs[];					\
  extern int current_function_pretend_args_size;		\
  int fsize = ((SIZE) + 3) & ~3;				\
  int nregs, i;							\
  int true_size;							\
  for ( nregs = 0, i = 1 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {	\
    if (regs_ever_live[i] && !call_used_regs[i]) ++nregs;}	\
  if ( frame_pointer_needed && !regs_ever_live[FRAME_POINTER_REGNUM])++nregs;\
  true_size = (nregs * 4) + fsize + current_function_pretend_args_size;	\
  if (true_size != 0)						\
    fprintf (FILE, "\tSUB %s,%s,%d\n",reg_names[STACK_POINTER_REGNUM],\
      reg_names[STACK_POINTER_REGNUM],true_size);		\
  for ( i = 1 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {		\
    if ((regs_ever_live[i] && !call_used_regs[i]) ||		\
	(frame_pointer_needed && i == FRAME_POINTER_REGNUM))	\
      fprintf (FILE, "\tST %s,%s[%d]\n",reg_names[i],		\
        reg_names[STACK_POINTER_REGNUM],--nregs*4+fsize);}	\
  if ( frame_pointer_needed ) fprintf(FILE, "\tADD %s,%s,0\n", \
       reg_names[FRAME_POINTER_REGNUM],reg_names[STACK_POINTER_REGNUM]);}
#else
extern void emit_function_prologue();
#define FUNCTION_PROLOGUE(FILE, SIZE) emit_function_prologue(FILE, SIZE)
#endif

/* Output assembler code to FILE to increment profiler label # LABELNO
   for profiling a function entry.  */

#define FUNCTION_PROFILER(FILE, LABELNO)  \
   fprintf (FILE, "\t.profile LP%d\n", LABELNO);

/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,
   the stack pointer does not matter.  The value is tested only in
   functions that have frame pointers.
   No definition is equivalent to always zero.  */

#define EXIT_IGNORE_STACK 1

/* This macro generates the assembly code for function exit,
   on machines that need it.  If FUNCTION_EPILOGUE is not defined
   then individual return instructions are generated for each
   return statement.  Args are same as for FUNCTION_PROLOGUE.

   The function epilogue should not depend on the current stack pointer!
   It should use the frame pointer only.  This is mandatory because
   of alloca; we also take advantage of it to omit stack adjustments
   before returning.  */

#ifdef FUNCTION_EPILOGUE_IS_MACRO
#define FUNCTION_EPILOGUE(FILE, SIZE)	\
{								\
  static char *reg_names[] = REGISTER_NAMES;			\
  extern char call_used_regs[];					\
  extern int may_call_alloca;					\
  extern int current_function_pretend_args_size;		\
  int fsize = ((SIZE) + 3) & ~3;				\
  int nregs, i, j;						\
  for ( nregs = 0, i = 1 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {	\
    if (regs_ever_live[i] && !call_used_regs[i]) ++nregs;}	\
  if ( frame_pointer_needed && !regs_ever_live[FRAME_POINTER_REGNUM] )++nregs;\
  j = nregs*4 + fsize + current_function_pretend_args_size;	\
  if ( frame_pointer_needed ) fprintf(FILE, "\tADD %s,%s,0\n", \
       reg_names[STACK_POINTER_REGNUM],reg_names[FRAME_POINTER_REGNUM]);\
  for ( i = 1 ; i < FIRST_PSEUDO_REGISTER ; ++i ) {		\
    if ((regs_ever_live[i] && !call_used_regs[i]) ||		\
	(frame_pointer_needed && i == FRAME_POINTER_REGNUM)) {	\
      fprintf (FILE, "\tLD %s,%s[%d]\n",reg_names[i],		\
	      reg_names[STACK_POINTER_REGNUM],--nregs*4+fsize);}} \
  fprintf (FILE, "\tJSR %%0,%s[0]\n",reg_names[RETURN_POINTER_REGNUM]);	\
  fprintf (FILE, "\tADD %s,%s,%d\n",reg_names[STACK_POINTER_REGNUM],\
    reg_names[STACK_POINTER_REGNUM],j);}
#else
extern void emit_function_epilogue();
#define FUNCTION_EPILOGUE(FILE, SIZE) emit_function_epilogue(FILE, SIZE)
#endif

/* If the memory address ADDR is relative to the frame pointer,
   correct it to be relative to the stack pointer instead.
   This is for when we don't use a frame pointer.
   ADDR should be a variable name.  */

/* ASAP uses only positive displacements for the Frame pointer, so all we
   have to do is add DEPTH, if we do anything at all */

#define FIX_FRAME_POINTER_ADDRESS(ADDR,DEPTH)  \
{ int offset = -1;							\
  if (ADDR == frame_pointer_rtx)					\
    offset = 0;								\
  else if (GET_CODE (ADDR) == PLUS && XEXP (ADDR, 0) == frame_pointer_rtx \
	   && GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\
    offset = INTVAL (XEXP (ADDR, 1));					\
  if (offset >= 0)							\
    { ADDR = plus_constant (stack_pointer_rtx, offset + (DEPTH)); } }

/* Addressing modes, and classification of registers for them.  */

/* #define HAVE_POST_INCREMENT */
/* #define HAVE_POST_DECREMENT */

/* #define HAVE_PRE_DECREMENT */
/* #define HAVE_PRE_INCREMENT */

/* Macros to check register numbers against specific register classes.  */

/* These assume that REGNO is a hard or pseudo reg number.
   They give nonzero only if REGNO is a hard reg of the suitable class
   or a pseudo reg currently allocated to a suitable hard reg.
   Since they use reg_renumber, they are safe only once reg_renumber
   has been allocated, which happens in local-alloc.c.  */
/* Any register is as good as any other on ASAP, so these are all the same */

#define REGNO_OK_FOR_INDEX_P(REGNO) \
((REGNO) < FIRST_PSEUDO_REGISTER || \
(unsigned) reg_renumber[REGNO] < FIRST_PSEUDO_REGISTER)
#define REGNO_OK_FOR_BASE_P(REGNO) \
((REGNO) < FIRST_PSEUDO_REGISTER || \
(unsigned) reg_renumber[REGNO] < FIRST_PSEUDO_REGISTER)
#define REGNO_OK_FOR_FP_P(REGNO) \
((REGNO) < FIRST_PSEUDO_REGISTER || \
(unsigned) reg_renumber[REGNO] < FIRST_PSEUDO_REGISTER)

/* Now macros that check whether X is a register and also,
   strictly, whether it is in a specified class.

   These macros are specific to the SPUR, and may be used only
   in code for printing assembler insns and in conditions for
   define_optimization.  */
/* This was left in, because I (MEA) didn't understand it. ASAP has no
   "classes" of registers. */

/* 1 if X is an fp register.  */

#define FP_REG_P(X) (REG_P (X) && REGNO_OK_FOR_FP_P (REGNO (X)))

/* Maximum number of registers that can appear in a valid memory address.  */

#define MAX_REGS_PER_ADDRESS 2

/* Recognize any constant value that is a valid address.  */

#define CONSTANT_ADDRESS_P(X)  CONSTANT_P (X)

/* Nonzero if the constant value X is a legitimate general operand.
   It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */

#ifdef DEBUG_LEGIT_CONST
extern int legit_const_p();
#define LEGITIMATE_CONSTANT_P(X)\
 legit_const_p((X),CONST_DOUBLE,__LINE__,__FILE__)
#else
#define LEGITIMATE_CONSTANT_P(X) (GET_CODE (X) != CONST_DOUBLE)
#endif

/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx
   and check its validity for a certain class.
   We have two alternate definitions for each of them.
   The usual definition accepts all pseudo regs; the other rejects
   them unless they have been allocated suitable hard regs.
   The symbol REG_OK_STRICT causes the latter definition to be used.

   Most source files want to accept pseudo regs in the hope that
   they will get allocated to the class that the insn wants them to be in.
   Source files for reload pass need to be strict.
   After reload, it makes no difference, since pseudo regs have
   been eliminated by then.  */
/* ASAP has no registers that _aren't_ ok for base or index */
#ifndef REG_OK_STRICT

/* Nonzero if X is a hard reg that can be used as an index
   or if it is a pseudo reg.  */
#define REG_OK_FOR_INDEX_P(X) (1)
/* Nonzero if X is a hard reg that can be used as a base reg
   or if it is a pseudo reg.  */
#define REG_OK_FOR_BASE_P(X) (1)

#else

/* Nonzero if X is a hard reg that can be used as an index.  */
#define REG_OK_FOR_INDEX_P(X) REGNO_OK_FOR_INDEX_P (REGNO (X))
/* Nonzero if X is a hard reg that can be used as a base reg.  */
#define REG_OK_FOR_BASE_P(X) REGNO_OK_FOR_BASE_P (REGNO (X))

#endif

/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression
   that is a valid memory address for an instruction.
   The MODE argument is the machine mode for the MEM expression
   that wants to use this address.
   (following is quote from tm-spur.h)
   On SPUR, the actual legitimate addresses must be REG+REG or REG+SMALLINT.
   But we can treat a SYMBOL_REF as legitimate if it is part of this
   function's constant-pool, because such addresses can actually
   be output as REG+SMALLINT.
   (end quote)
   On ASAP, an address is reg+(mode_size*reg) or reg+(mode_size*small_int),
   but GCC gives much grief for admitting that constants are scaled too.
   On MAR 19, 1990 MEA hack this section to relax the constraints so that
   they _only_ check for whether an address is in range, not whether it
   is properly aligned. This was needed because offsettable_addr_p adds
   one _less_ than mode-size to the constant to check for addressability.
   This, of course, changes _any_ valid address to a mis-aligned one if
   mode_size is larger than 1!
  */
#ifdef DEBUG_INDEX_TERM_ADDR
extern int index_term_addr_p(const char *filename, int line, int mode, void *addr);
#define INDEX_TERM_P(MODE,X) index_term_addr_p(__FILE__, __LINE__, (int)MODE, (void *)X)
extern int strict_index_term_addr_p(const char *filename, int line, int mode, void *addr);
#define STRICT_INDEX_TERM_P(MODE,X) strict_index_term_addr_p(__FILE__, __LINE__, (int)MODE, (void *)X)
#else
#define INDEX_TERM_P(MODE, X)  \
  ((GET_CODE (X) == MULT					\
    && ((REG_P (XEXP (X, 0))					\
         && GET_CODE (XEXP (X, 1)) == CONST_INT			\
         && INTVAL (XEXP (X, 1)) <= 4				\
         && (INTVAL (XEXP (X, 1)) == GET_MODE_SIZE (MODE)))	\
        || (REG_P (XEXP (X, 1))					\
            && GET_CODE (XEXP (X, 0)) == CONST_INT		\
            && INTVAL (XEXP (X, 0)) <= 4			\
            && (INTVAL (XEXP (X, 0)) == GET_MODE_SIZE (MODE))	\
	      && (warning ("MULT backwards"), 1))))		\
  || (REG_P (X) && GET_MODE_SIZE (MODE) == 1))

#define STRICT_INDEX_TERM_P(MODE, X)  \
  ((GET_CODE (X) == MULT					\
    && ((REG_P (XEXP (X, 0))					\
         && REGNO (XEXP (X, 0)) < FIRST_PSEUDO_REGISTER		\
         && GET_CODE (XEXP (X, 1)) == CONST_INT			\
         && INTVAL (XEXP (X, 1)) <= 4				\
         && (INTVAL (XEXP (X, 1)) == GET_MODE_SIZE (MODE)))	\
        || (REG_P (XEXP (X, 1))					\
	    && REGNO (XEXP (X, 1)) < FIRST_PSEUDO_REGISTER	\
            && GET_CODE (XEXP (X, 0)) == CONST_INT		\
            && INTVAL (XEXP (X, 0)) <= 4			\
            && (INTVAL (XEXP (X, 0)) == GET_MODE_SIZE (MODE))	\
	      && (warning ("MULT backwards"), 1))))		\
  || (REG_P (X) && REGNO (X) < FIRST_PSEUDO_REGISTER  \
     && GET_MODE_SIZE (MODE) == 1))
#endif
#define VALID_OFFSET_P(MODE, X) \
( (GET_CODE (X) == CONST_INT)				\
    &&( (   (GET_MODE_SIZE (MODE) >= 4)			\
	/* &&((INTVAL (X) & 0x3) == 0) */		\
	&&((unsigned) INTVAL (X) < (0xFFE0 << 2)))	\
    ||(   (GET_MODE_SIZE (MODE) == 2)			\
	/* &&((INTVAL (X) & 0x1) == 0) */		\
	&&((unsigned) INTVAL (X) < (0xFFE0 << 1)))	\
    ||(   (GET_MODE_SIZE (MODE) <= 1)			\
	&&((unsigned) INTVAL (X) < 0xFFE0))))

#ifdef DEBUG_LEGIT_ADDR
extern int legit_addr_p();
#ifdef REG_OK_STRICT
#define GO_IF_LEGITIMATE_ADDRESS(MODE, X, ADDR)  \
	if ( legit_addr_p(MODE, X, __LINE__, __FILE__,1) ) goto ADDR;
#else
#define GO_IF_LEGITIMATE_ADDRESS(MODE, X, ADDR)  \
	if ( legit_addr_p(MODE, X, __LINE__, __FILE__,0) ) goto ADDR;
#endif
#else
#ifdef REG_OK_STRICT
#define GO_IF_LEGITIMATE_ADDRESS(MODE, X, ADDR) \
{ if (GET_CODE (X) == REG			\
	&& REGNO(X) < FIRST_PSEUDO_REGISTER )	\
    goto ADDR;					\
  if (GET_CODE (X) == SYMBOL_REF && (X)->unchanging)	\
    goto ADDR;					\
  if (GET_CODE (X) == PLUS			\
      && REG_P (XEXP (X, 0))			\
      && REGNO (XEXP (X, 0)) < FIRST_PSEUDO_REGISTER	\
      && (  (VALID_OFFSET_P(MODE, XEXP (X, 1))) \
         || (STRICT_INDEX_TERM_P (MODE, XEXP (X, 1)))))\
    goto ADDR;					\
  if (STRICT_INDEX_TERM_P (MODE, X))			\
    goto ADDR;					\
  if (VALID_OFFSET_P (MODE, X))			\
    goto ADDR;					\
}
#else
#define GO_IF_LEGITIMATE_ADDRESS(MODE, X, ADDR)  \
{ if (GET_CODE (X) == REG)			\
    goto ADDR;					\
  if (GET_CODE (X) == SYMBOL_REF && (X)->unchanging)	\
    goto ADDR;					\
  if (GET_CODE (X) == PLUS			\
      && REG_P (XEXP (X, 0))			\
      && (  (VALID_OFFSET_P(MODE, XEXP (X, 1))) \
         || (INDEX_TERM_P (MODE, XEXP (X, 1)))))\
    goto ADDR;					\
  if (INDEX_TERM_P (MODE, X))			\
    goto ADDR;					\
  if (VALID_OFFSET_P (MODE, X))			\
    goto ADDR;					\
}
#endif	/* REG_OK_STRICT */
#endif /* DEBUG_LEGIT_ADDR */

/* Try machine-dependent ways of modifying an illegitimate address
   to be legitimate.  If we find one, return the new, valid address.
   This macro is used in only one place: `memory_address' in explow.c.

   OLDX is the address as it was before break_out_memory_refs was called.
   In some cases it is useful to look at this to decide what needs to be done.

   MODE and WIN are passed so that this macro can use
   GO_IF_LEGITIMATE_ADDRESS.

   It is always safe for this macro to do nothing.  It exists to recognize
   opportunities to optimize the output.  */

/* For now ASAP version does nothing */

#define LEGITIMIZE_ADDRESS(X,OLDX,MODE,WIN) {;}

/* Go to LABEL if ADDR (a legitimate address expression)
   has an effect that depends on the machine mode it is used for.
   On the ASAP this is never true.  */

#define GO_IF_MODE_DEPENDENT_ADDRESS(ADDR,LABEL)

/* Specify the machine mode that this machine uses
   for the index in the tablejump instruction.  */
#define CASE_VECTOR_MODE SImode

/* Define this if the tablejump instruction expects the table
   to contain offsets from the address of the table.
   Do not define this if the table should contain absolute addresses.  */
/* #define CASE_VECTOR_PC_RELATIVE */


/* The FIX_ADDRESS_IF_NEEDED macro is used to hook in the various kluges
*  you need to get around GCC believing all the world's a vax, in re:
*  ARG_POINTERS. This one was liberally adapted from the one Michael Meissner
*  posted (for the 88k)
*/

/* Generalized macro to fix up any addresses that need it, possibly
   emitting output_asm_insn's.  Presently it does (not literal synthesis)
   and argument pointer conversion.  */

#define FIX_ADDRESS_IF_NEEDED(op)				\
  do {								\
    rtx op2 = (GET_CODE (op) == MEM) ? XEXP (op, 0) : op;	\
								\
    if (REG_P (op2) && REGNO (op2) == ARG_POINTER_REGNUM)	\
      output_arg_ptr (0);					\
								\
    else if (GET_CODE (op2) == PLUS &&				\
	     REG_P (XEXP (op2, 0)) &&				\
	     REGNO (XEXP (op2, 0)) == ARG_POINTER_REGNUM &&	\
	     GET_CODE (XEXP (op2, 1)) == CONST_INT)		\
      output_arg_ptr (INTVAL (XEXP (op2, 1)));			\
								\
    else if (GET_CODE (op2) == PLUS &&				\
	     REG_P (XEXP (op2, 1)) &&				\
	     REGNO (XEXP (op2, 1)) == ARG_POINTER_REGNUM &&	\
	     GET_CODE (XEXP (op2, 0)) == CONST_INT)		\
      output_arg_ptr (INTVAL (XEXP (op2, 0)));			\
								\
  } while (0)
   
/* Specify the tree operation to be used to convert reals to integers.  */
#define IMPLICIT_FIX_EXPR FIX_ROUND_EXPR

/* This is the kind of divide that is easiest to do in the general case.  */
#define EASY_DIV_EXPR TRUNC_DIV_EXPR

/* Define this as 1 if `char' should by default be signed; else as 0.  */
/* first attempt at ASAP defines as '1' for backwards compat. with GHC */
#define DEFAULT_SIGNED_CHAR 1

/* Max number of bytes we can move from memory to memory
   in one reasonably fast instruction.  */
#define MOVE_MAX 4

/* Nonzero if access to memory by bytes is slow and undesirable.  */
#define SLOW_BYTE_ACCESS 1

/* Do not break .stabs pseudos into continuations.  */
#define DBX_CONTIN_LENGTH 0

/* Don't try to use the `x' type-cross-reference character in DBX data.
   Also has the consequence of putting each struct, union or enum
   into a separate .stabs, containing only cross-refs to the others.  */
#define DBX_NO_XREFS

/* Value is 1 if truncating an integer of INPREC bits to OUTPREC bits
   is done just by pretending it is already truncated.  */
#define TRULY_NOOP_TRUNCATION(OUTPREC, INPREC) 1

/* Specify the machine mode that pointers have.
   After generation of rtl, the compiler makes no further distinction
   between pointers and any other objects of this machine mode.  */
#define Pmode SImode

/* A function address in a call instruction
   is a byte address (for indexing purposes)
   so give the MEM rtx a byte's mode.  */
/* this was actually SImode for SPUR, and I (MEA) think that's right for ASAP */
#define FUNCTION_MODE SImode

/* Define this if addresses of constant functions
   shouldn't be put through pseudo regs where they can be cse'd.
   Desirable on machines where ordinary constants are expensive
   but a CALL with constant address is cheap.  */
#define NO_FUNCTION_CSE

/* Define this to keep induction variable optimizations
   from pessimizing code.  */
#define DONT_REDUCE_ADDR

/* Compute the cost of computing a constant rtl expression RTX
   whose rtx-code is CODE.  The body of this macro is a portion
   of a switch statement.  If the code is computed here,
   return it with a return statement.  Otherwise, break from the switch.  */

#define CONST_COSTS(RTX,CODE) \
  case CONST_INT:						\
    if (INTVAL (RTX) >= 0 && INTVAL (RTX) <= 0xFFE0) return 1; \
  case CONST:							\
  case LABEL_REF:						\
  case SYMBOL_REF:						\
    return 2;							\
  case CONST_DOUBLE:						\
    return 4;

/* Tell final.c how to eliminate redundant test instructions.  */

/* Here we define machine-dependent flags and fields in cc_status
   (see `conditions.h').  */

/* (None are needed on SPUR.)  */

/* Store in cc_status the expressions
   that the condition codes will describe
   after execution of an instruction whose pattern is EXP.
   Do not alter them if the instruction would not alter the cc's.  */

/* The SPUR does not really have a condition code.  */
/* ASAP does, but they are never _implicitly_ set */
#define NOTICE_UPDATE_CC(EXP, INSN) \
{ CC_STATUS_INIT; }

/* Control the assembler format that we output.  */

/* Output at beginning of assembler file.  */

/* The following is a hack to get at least line numbers */
#define ASM_FILE_START(FILE) \
do { text_section();\
  fputs(".RP = %28.\n.SP = %29.\n.FP = %27.\n",FILE);\
  if ( write_symbols == NO_DEBUG ) write_symbols = 5; } while (0)

/* Output to assembler file text saying following lines
   may contain character constants, extra white space, comments, etc.  */

#define ASM_APP_ON " "

/* Output to assembler file text saying following lines
   no longer contain unusual constructs.  */

#define ASM_APP_OFF " "

/* Output before executable code and read-only data */

#define TEXT_SECTION_ASM_OP "\t.psect text,dat=2,seg=2"

/* Output before initialized (but writable) data.  */
/* (comment _was_ "Output before writable data.")  */

#define DATA_SECTION_ASM_OP "\t.psect data,dat=2,seg=2"

/* Output before bss (also writable data, a hack for the .comm stuff.)  */
#define BSS_SECTION_ASM_OP "\t.psect bss,dat=2,seg=2"

/* Output to define an ASCII string (NOT automatically zero-terminated) */
#define ASCII_DATA_ASM_OPEN "\t.ascii\t\""
#define ASCII_DATA_ASM_CLOSE "\"\n"

/* How to refer to registers in assembler output.
   This sequence is indexed by compiler's hard-register-number (see above).  */
#ifdef COLLIDABLE_NAMES
#define REGISTER_NAMES \
{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9",		\
 "r10", "r11", "r12", "r13", "r14", "r15", "r16", "r17", "r18", "r19",	\
 "r20", "r21", "r22", "r23", "r24", "r25", "r26", ".FP", ".RP", ".SP",	\
 ".X0", ".X1"}
#else
#define REGISTER_NAMES \
{"%0", "%1", "%2", "%3", "%4", "%5", "%6", "%7", "%8", "%9",		\
 "%10", "%11", "%12", "%13", "%14", "%15", "%16", "%17", "%18", "%19",	\
 "%20", "%21", "%22", "%23", "%24", "%25", "%26", ".FP", ".RP", ".SP",	\
 ".X0", ".X1"}
#endif

/* How to renumber registers for dbx and gdb.  */

#define DBX_REGISTER_NUMBER(REGNO) (REGNO)

/* This is a hook at the point where we begin to assemble a function.
*  it is needed to extract the size and number of args, so we can decide
*  (in FUNCTION_PROLOGUE()) whether we need an ARG_POINTER. KLUGE!!!
*/
extern void asm_decl_func();

#define ASM_DECLARE_FUNCTION_NAME(FILE,NAME,DECL)\
asm_decl_func(FILE,NAME,DECL);

/* This is how to output the definition of a user-level label named NAME,
   such as the label on a static function or variable NAME.  */

#define ASM_OUTPUT_LABEL(FILE,NAME)	\
  do { assemble_name (FILE, NAME); fputs (":\n", FILE); } while (0)

/* This is how to output a command to make the user-level label named NAME
   defined for reference from other files.  */

#define ASM_GLOBALIZE_LABEL(FILE,NAME)	\
  do { fputs ("\t.globl ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)

/* This is how to output a reference to a user-level label named NAME.
   `assemble_name' uses this.  */

#define ASM_OUTPUT_LABELREF(FILE,NAME)	\
  fprintf (FILE, "%s", NAME)

/* This is how to output an internal numbered label where
   PREFIX is the class of label and NUM is the number within the class.  */

#define ASM_OUTPUT_INTERNAL_LABEL(FILE,PREFIX,NUM)	\
  fprintf (FILE, ".%s%d:\n", PREFIX, NUM)

/* This is how to store into the string LABEL
   the symbol_ref name of an internal numbered label where
   PREFIX is the class of label and NUM is the number within the class.
   This is suitable for output with `assemble_name'.  */

#define ASM_GENERATE_INTERNAL_LABEL(LABEL,PREFIX,NUM)	\
  sprintf (LABEL, "*.%s%d", PREFIX, NUM)

/* This is how to output an assembler line defining a `double' constant.  */

#define ASM_OUTPUT_DOUBLE(FILE,VALUE)  \
  fprintf (FILE, "\t.double %.20e\n", (VALUE))

/* This is how to output an assembler line defining a `float' constant.  */

#define ASM_OUTPUT_FLOAT(FILE,VALUE)  \
  fprintf (FILE, "\t.single %.12e\n", (VALUE))

#define	ASM_OUTPUT_ASCII(f, p, size)	\
{ register int i;			\
  int inside,j=0;			\
  inside = FALSE;			\
  for (i = 0; i < size; i++) {		\
    if ((j &= 15) == 0) {		\
      if (inside) { 			\
	fputs(ASCII_DATA_ASM_CLOSE,f);	\
	inside = FALSE;			\
      }					\
    }					\
    if (p[i] < 32 || p[i] == '\'' || p[i] & 0x80 || p[i] == 127) {	\
      if (inside) {			\
	fputs(ASCII_DATA_ASM_CLOSE,f);	\
	inside = FALSE;			\
	j = 0;				\
      }					\
      if ( (j & 15) != 0) fputc(',', f);\
      else fputs("\t.byte\t",f);	\
      fprintf(f, "%d", p[i]);		\
    } else {				\
      if (!inside) {			\
	if ((j & 15) != 0) fputc('\n',f);\
	fputs(ASCII_DATA_ASM_OPEN,f);	\
	j = 0;				\
	inside = TRUE;			\
      }					\
      fputc(p[i], f);			\
    }					\
  ++j;					\
  }					\
  if (inside) fputs(ASCII_DATA_ASM_CLOSE,f);\
  else fputc('\n', f);			\
}

/* This is how to output an assembler line defining an `int' constant.  */

#define ASM_OUTPUT_INT(FILE,VALUE)  \
( fprintf (FILE, "\t.long "),			\
  output_addr_const (FILE, (VALUE)),		\
  fprintf (FILE, "\n"))

/* Likewise for `char' and `short' constants.  */

#define ASM_OUTPUT_SHORT(FILE,VALUE)  \
( fprintf (FILE, "\t.hword "),			\
  output_addr_const (FILE, (VALUE)),		\
  fprintf (FILE, "\n"))

#define ASM_OUTPUT_CHAR(FILE,VALUE)  \
( fprintf (FILE, "\t.byte "),			\
  output_addr_const (FILE, (VALUE)),		\
  fprintf (FILE, "\n"))

/* This is how to output an assembler line for a numeric constant byte.  */

#define ASM_OUTPUT_BYTE(FILE,VALUE)  \
  fprintf (FILE, "\t.byte %d\n", (VALUE))

/* This is how to output an insn to push a register on the stack.
   It need not be very fast code.  */

#define ASM_OUTPUT_REG_PUSH(FILE,REGNO)  \
  fprintf (FILE, "\tSUB %s,%s,4\n\tST %s,%s[0]\n",\
    reg_names[STACK_POINTER_REGNUM],	\
    reg_names[STACK_POINTER_REGNUM],	\
    reg_names[REGNO],			\
    reg_names[STACK_POINTER_REGNUM])

/* This is how to output an insn to pop a register from the stack.
   It need not be very fast code.  */

#define ASM_OUTPUT_REG_POP(FILE,REGNO)  \
  fprintf (FILE, "\tLD %s,%s[0]\n\tADD %s,%s,4\n", \
    reg_names[REGNO],	\
    reg_names[STACK_POINTER_REGNUM],	\
    reg_names[STACK_POINTER_REGNUM],	\
    reg_names[STACK_POINTER_REGNUM])

/* This is how to output an element of a case-vector that is absolute.  */

#define ASM_OUTPUT_ADDR_VEC_ELT(FILE, VALUE)  \
  fprintf (FILE, "\t.long .L%d\n", VALUE)

/* This is how to output an element of a case-vector that is relative.
   (SPUR does not use such vectors,
   but we must define this macro anyway.)  */

#define ASM_OUTPUT_ADDR_DIFF_ELT(FILE, VALUE, REL)  \
  fprintf (FILE, "\t.short (.L%d-.L%d)/4\n", VALUE, REL)

/* This is how to output an assembler line
   that says to advance the location counter
   to a multiple of 2**LOG bytes.  */

#define ASM_OUTPUT_ALIGN(FILE,LOG)	\
  if ((LOG) != 0)			\
    fprintf (FILE, "\t.align %d\n", (LOG))

#define ASM_OUTPUT_SKIP(FILE,SIZE)  \
 fprintf (FILE, \
 (in_bss_section() ? "\t.blkb %d\n" : "\t.rept %d\n\t.byte 0\n\t.endr\n"), \
 (SIZE))

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

/* Store in OUTPUT a string (made with alloca) containing
   an assembler-name for a local static variable named NAME.
   LABELNO is an integer which is different for each call.  */

#define ASM_FORMAT_PRIVATE_NAME(OUTPUT, NAME, LABELNO)	\
( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\
  sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))

/* Define the parentheses used to group arithmetic operations
   in assembler code.  */

#define ASM_OPEN_PAREN "("
#define ASM_CLOSE_PAREN ")"

/* Define results of standard character escape sequences.  */
#define TARGET_BELL 007
#define TARGET_BS 010
#define TARGET_TAB 011
#define TARGET_NEWLINE 012
#define TARGET_VT 013
#define TARGET_FF 014
#define TARGET_CR 015

/* Print operand X (an rtx) in assembler syntax to file FILE.
   CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.
   For `%' followed by punctuation, CODE is the punctuation and X is null.

   On ASAP, the CODE can be:
	`a', meaning this is an address, output with PRINT_OPERAND_ADDRESS
	`n', meaning the negative of the value should be used
*/

#define PRINT_OPERAND(FILE, X, CODE)  \
{ if ( CODE == 'a' ) PRINT_OPERAND_ADDRESS(FILE, X);			\
  else if ( CODE == 'n' ) fprintf(FILE, "%d", -(INTVAL (X)));		 \
  else if (GET_CODE (X) == REG)						\
    fprintf (FILE, "%s", reg_names[REGNO (X)]);				\
  else if (GET_CODE (X) == MEM)						\
    output_address (XEXP (X, 0));					\
  else if (GET_CODE (X) == CONST_DOUBLE)				\
    abort ();								\
  else if (CONSTANT_ADDRESS_P (X))					\
    output_addr_const (FILE, X);					\
  else output_address (X); }

/* Print a memory address as an operand to reference that memory location.
*
*  This has been "temporarily" moved to aux-output.c to enable hacking.
*/
#ifndef MACRO_PRINT_OPERAND_ADDRESS
extern void asap_print_operand_address();
#define PRINT_OPERAND_ADDRESS(FILE, ADDR) asap_print_operand_address(FILE,ADDR)
#else
#define PRINT_OPERAND_ADDRESS(FILE, ADDR)  \
{ register rtx base, index = 0;					\
  int offset = 0;						\
  register rtx addr = ADDR;					\
  if (GET_CODE (addr) == REG)					\
    {								\
      fprintf (FILE, "%s[0]", reg_names[REGNO (addr)]);	\
    }								\
  else if (GET_CODE (addr) == PLUS)				\
    {								\
      if (GET_CODE (XEXP (addr, 0)) == CONST_INT)		\
	offset = INTVAL (XEXP (addr, 0)), base = XEXP (addr, 1);\
      else if (GET_CODE (XEXP (addr, 1)) == CONST_INT)		\
	offset = INTVAL (XEXP (addr, 1)), base = XEXP (addr, 0);\
      else							\
	base = XEXP (addr, 0), index = XEXP (addr, 1);		\
      if (index && GET_CODE (index) == MULT)			\
	{							\
	  if (GET_CODE (XEXP (index, 0)) == REG)		\
	    index = XEXP (index, 0);				\
	  else if (GET_CODE (XEXP (index, 1)) == REG)		\
	    index = XEXP (index, 1);				\
	  else abort ();					\
	}							\
      fprintf (FILE, "%s[", reg_names[REGNO (base)]);		\
      if (index == 0)						\
	fprintf (FILE, "%d]", offset);				\
      else							\
	fprintf (FILE, "%s]", reg_names[REGNO (index)]);	\
    }								\
  else if ((GET_CODE (addr) == MULT)				\
	 && (GET_CODE (index = XEXP(addr,0)) == REG))		\
    {								\
      fprintf (FILE, "%%0[%s]", reg_names[REGNO (index)]);	\
    }								\
  else if ((GET_CODE (addr) == CONST_INT))			\
    {								\
      fprintf (FILE, "%%0[%d]", INTVAL (addr));			\
    }								\
  else 								\
    {								\
      fprintf (FILE, "%%0[");					\
      output_addr_const (FILE, addr);				\
      fprintf (FILE, "] ; kluge for literals");			\
    }								\
}
#endif
