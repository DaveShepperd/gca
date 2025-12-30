;;- Machine description for ASAP chip for GNU C compiler (1.37)
;;   Copyright (C) 1988 Free Software Foundation, Inc.

;; This file is part of GNU CC.

;; GNU CC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY.  No author or distributor
;; accepts responsibility to anyone for the consequences of using it
;; or for whether it serves any particular purpose or works at all,
;; unless he says so in writing.  Refer to the GNU CC General Public
;; License for full details.

;; Everyone is granted permission to copy, modify and redistribute
;; GNU CC, but only under the conditions described in the
;; GNU CC General Public License.   A copy of this license is
;; supposed to have been given to you along with GNU CC so you
;; can know your rights and responsibilities.  It should be in a
;; file named COPYING.  Among other things, the copyright notice
;; and this notice must be preserved on all copies.


;;- See file "rtl.def" for documentation on define_insn, match_*, et. al.

;;- cpp macro #define NOTICE_UPDATE_CC in file tm.h handles condition code
;;- updates for most instructions.

;;- Operand classes for the register allocator:

;; Virtual argument pointer handling.  We use register 30 (first interrupt
;; save register) internally to indicate usage of the argument pointer.
;; The following patterns need to occur before the normal patterns, and
;; should be the only ones that deal with the argument pointer in a
;; non-address fashion.  The operand is changed to refer to the frame pointer
;; (r27) or stack pointer (r29) as appropriate.

(define_insn ""
  [(set (match_operand:SI 0 "register_operand" "=r")
	(reg:SI 30))]
  ""
  "*
{
  output_arg_ptr (0);
  operands[1] = gen_rtx (REG, SImode, ARG_POINTER_REGNUM);
  return \"LEA %0,%a1\";
}")

(define_insn ""
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (reg:SI 30)
		 (match_operand:SI 1 "nonmemory_operand" "rIMJK")))]
  ""
  "*
{
  if ( REG_P (operands[1]) ) {
    output_arg_ptr (0);
    if ( asap_ap_offset == 0)
    {
      operands[2] = ( asap_ap_in_use == STACK_POINTER_REGNUM)
		? stack_pointer_rtx
		: frame_pointer_rtx;

      return \"add %0,%1,%2\";
    }
    else
    {
      operands[2] = gen_rtx (REG, SImode, ARG_POINTER_REGNUM);
      return \"LEA %0,%a2\\n\\tadd %0,%0,%1\";
    }
  }
  else {
    output_arg_ptr (INTVAL (operands[1]));
    operands[1] = gen_rtx (REG, SImode, ARG_POINTER_REGNUM);
    return \"LEA %0,%a1\";
  }
}")

(define_insn ""
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (match_operand:SI 1 "register_operand" "r")
		 (reg:SI 30)))]
  ""
  "*
{
  output_arg_ptr (0);
  if ( asap_ap_offset == 0)
    {
      operands[2] = ( asap_ap_in_use == STACK_POINTER_REGNUM)
		? stack_pointer_rtx
		: frame_pointer_rtx;

      return \"add %0,%1,%2\";
    }
  else
    {
      operands[2] = gen_rtx (REG, SImode, ARG_POINTER_REGNUM);
      return \"LEA %0,%a2\\n\\tadd %0,%0,%1\";
    }
}")

;; This controls RTL generation and register allocation.
(define_insn "cmpsi"
  [(set (cc0)
	(compare (match_operand:SI 0 "nonmemory_operand" "rI")
	       (match_operand:SI 1 "nonmemory_operand" "rI")))]
  ""
  "*
{
  cc_status.value1 = operands[0], cc_status.value2 = operands[1];
  if ( !REG_P (operands[0]) ) return \"SUBR.C %%0,%1,%0\";
  return \"SUB.C %%0,%0,%1\";
}")

;; We have to have this because cse can optimize the previous pattern
;; into this one.

(define_insn "tstsi"
  [(set (cc0)
	(match_operand:SI 0 "general_operand" "rm"))]
  ""
  "*
{
  cc_status.value1 = operands[0], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  if ( !REG_P (operands[0]) ) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"LD.C %%0,%0\";
  }
  return \"OR.C %%0,%0,0\";
}")

;;- This version of tsthi will not work on rev1 chips, due to the ASHL.C bug
(define_insn "tsthi"
  [(set (cc0)
	(match_operand:HI 0 "general_operand" "rm"))]
  "!TARGET_ASHL_BUG"
  "*
{
  cc_status.value1 = operands[0], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  if ( !REG_P (operands[0]) ) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"LDS.C %%0,%0\";
  }
  return \"ASHL.C %%0,%0,16\";
}")

;;- The following anonymous version is the in-memory case, which always works
(define_insn ""
  [(set (cc0)
	(match_operand:HI 0 "memory_operand" "m"))]
  ""
  "*
{
  cc_status.value1 = operands[0], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  FIX_ADDRESS_IF_NEEDED (operands[0]);
  return \"LDS.C %%0,%0\";
}")
;;- Here is the peephole that uses the in-memory tsthi
(define_peephole
  [(set (match_operand:SI 0 "register_operand" "=r")
	(zero_extend:SI
	 (match_operand:HI 1 "general_operand" "rm")))
   (set (cc0) (match_dup 0))]
  ""
  "*
{
  if ( !REG_P (operands[1]) ) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    if ( dead_or_set_p(insn, operands[0]) ) {
      cc_status.value1 = operands[1], cc_status.value2 = const0_rtx;
      cc_status.flags |= CC_NO_OVERFLOW;
      return \"LDUS.C %%0,%1\";
    } else {
      cc_status.value1 = operands[0], cc_status.value2 = const0_rtx;
      cc_status.flags |= CC_NO_OVERFLOW;
      return \"LDUS.C %0,%1\";
    }
  } else {
    cc_status.value1 = operands[0], cc_status.value2 = const0_rtx;
    cc_status.flags |= CC_NO_OVERFLOW;
    return \"ASHL %0,%1,16\;LSHR.C %0,%0,16\";
  }
}")

(define_peephole
  [(set (match_operand:SI 0 "register_operand" "=r")
	(sign_extend:SI
	 (match_operand:HI 1 "memory_operand" "m")))
   (set (cc0) (match_dup 0))]
  "dead_or_set_p(insn, operands[0])"
  "*
{
  FIX_ADDRESS_IF_NEEDED (operands[1]);
  cc_status.value1 = operands[1], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  return \"LDS.C %%0,%1\";
}")

;;- This version of tstqi will not work on rev1 chips, due to the ASHL.C bug
(define_insn "tstqi"
  [(set (cc0)
	(match_operand:QI 0 "general_operand" "rm"))]
  "!TARGET_ASHL_BUG"
  "*
{
  cc_status.value1 = operands[0], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  if ( !REG_P (operands[0]) ) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"LDB.C %%0,%0\";
  }
  return \"ASHL.C %%0,%0,24\";
}")

;;- The following anonymous version is the in-memory case, which always works
(define_insn ""
  [(set (cc0)
	(match_operand:QI 0 "memory_operand" "m"))]
  ""
  "*
{
  cc_status.value1 = operands[0], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  FIX_ADDRESS_IF_NEEDED (operands[0]);
  return \"LDB.C %%0,%0\";
}")

;;- Here is the peephole that uses the in-memory tstqi
(define_peephole
  [(set (match_operand:SI 0 "register_operand" "=r")
	(zero_extend:SI
	 (match_operand:QI 1 "memory_operand" "m")))
   (set (cc0) (match_dup 0))]
  "dead_or_set_p(insn, operands[0])"
  "*
{
  FIX_ADDRESS_IF_NEEDED (operands[1]);
  cc_status.value1 = operands[1], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  return \"LDUB.C %%0,%1\";
}")
(define_peephole
  [(set (match_operand:SI 0 "register_operand" "=r")
	(sign_extend:SI
	 (match_operand:QI 1 "memory_operand" "m")))
   (set (cc0) (match_dup 0))]
  "dead_or_set_p(insn, operands[0])"
  "*
{
  FIX_ADDRESS_IF_NEEDED (operands[1]);
  cc_status.value1 = operands[1], cc_status.value2 = const0_rtx;
  cc_status.flags |= CC_NO_OVERFLOW;
  return \"LDB.C %%0,%1\";
}")

;; Basic conditional jump instructions.

(define_insn "beq"
  [(set (pc)
	(if_then_else (eq (cc0)
			  (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_Z_IN_NOT_N)
    return \"BPL %l0\;ADD %%0,%%0,0\";
    return \"BEQ %l0\;ADD %%0,%%0,0\";
}")

(define_insn "bne"
  [(set (pc)
	(if_then_else (ne (cc0)
			  (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_Z_IN_NOT_N)
    return \"BMI %l0\;ADD %%0,%%0,0\";
    return \"BNE %l0\;ADD %%0,%%0,0\";
}")

(define_insn "bgt"
  [(set (pc)
	(if_then_else (gt (cc0)
			  (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BSP %l0\;ADD %%0,%%0,0\";
    return \"BGT %l0\;ADD %%0,%%0,0\";
}")


(define_insn "bgtu"
  [(set (pc)
	(if_then_else (gtu (cc0)
			   (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "BHI %l0\;ADD %%0,%%0,0")

(define_insn "blt"
  [(set (pc)
	(if_then_else (lt (cc0)
			  (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BMI %l0\;ADD %%0,%%0,0\";
    return \"BLT %l0\;ADD %%0,%%0,0\";
}")

(define_insn "bltu"
  [(set (pc)
	(if_then_else (ltu (cc0)
			   (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "BLO %l0\;ADD %%0,%%0,0")

(define_insn "bge"
  [(set (pc)
	(if_then_else (ge (cc0)
			  (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BPL %l0\;ADD %%0,%%0,0\";
    return \"BGE %l0\;ADD %%0,%%0,0\";
}")

(define_insn "bgeu"
  [(set (pc)
	(if_then_else (geu (cc0)
			   (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "BHS %l0\;ADD %%0,%%0,0")

(define_insn "ble"
  [(set (pc)
	(if_then_else (le (cc0)
			  (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BMZ %l0\;ADD %%0,%%0,0\";
    return \"BLE %l0\;ADD %%0,%%0,0\";
}")

(define_insn "bleu"
  [(set (pc)
	(if_then_else (leu (cc0)
			   (const_int 0))
		      (label_ref (match_operand 0 "" ""))
		      (pc)))]
  ""
  "BLS %l0\;ADD %%0,%%0,0")

;; These match inverted jump insns for register allocation.
(define_insn ""
  [(set (pc)
	(if_then_else (eq (cc0)
			  (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_Z_IN_NOT_N)
    return \"BMI %l0\;ADD %%0,%%0,0\";
    return \"BNE %l0\;ADD %%0,%%0,0\";
}")

(define_insn ""
  [(set (pc)
	(if_then_else (ne (cc0)
			  (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_Z_IN_NOT_N)
    return \"BPL %l0\;ADD %%0,%%0,0\";
    return \"BEQ %l0\;ADD %%0,%%0,0\";
}")

(define_insn ""
  [(set (pc)
	(if_then_else (gt (cc0)
			  (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BMZ %l0\;ADD %%0,%%0,0\";
    return \"BLE %l0\;ADD %%0,%%0,0\";
}")

(define_insn ""
  [(set (pc)
	(if_then_else (gtu (cc0)
			   (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "BLS %l0\;ADD %%0,%%0,0")

(define_insn ""
  [(set (pc)
	(if_then_else (lt (cc0)
			  (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BPL %l0\;ADD %%0,%%0,0\";
    return \"BGE %l0\;ADD %%0,%%0,0\";
}")

(define_insn ""
  [(set (pc)
	(if_then_else (ltu (cc0)
			   (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "BHS %l0\;ADD %%0,%%0,0")
;; vv--- 29
(define_insn ""
  [(set (pc)
	(if_then_else (ge (cc0)
			  (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BMI %l0\;ADD %%0,%%0,0\";
    return \"BLT %l0\;ADD %%0,%%0,0\";
}")

;; vv--- 30
(define_insn ""
  [(set (pc)
	(if_then_else (geu (cc0)
			   (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "BLO %l0\;ADD %%0,%%0,0")

;; vv--- 31
(define_insn ""
  [(set (pc)
	(if_then_else (le (cc0)
			  (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "*
{
  if (cc_prev_status.flags & CC_NO_OVERFLOW)
    return \"BSP %l0\;ADD %%0,%%0,0\";
    return \"BGT %l0\;ADD %%0,%%0,0\";
}")

;; vv--- 32
(define_insn ""
  [(set (pc)
	(if_then_else (leu (cc0)
			   (const_int 0))
		      (pc)
		      (label_ref (match_operand 0 "" ""))))]
  ""
  "BHI %l0\;ADD %%0,%%0,0")

;; Indexed Stores, which come before moves to match as much as possible

;; Special cases of moves when source is zero.

;; vv--- 33
(define_insn ""
  [(set (match_operand:SI 0 "general_operand" "=mr")
	(const_int 0))]
  ""
  "*
{
  if (GET_CODE (operands[0]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"ST %%0,%0\";
  }
  return \"OR %0,%%0,0\";
}")

;; vv--- 34
(define_insn ""
  [(set (match_operand:HI 0 "general_operand" "=mr")
	(const_int 0))]
  ""
  "*
{
  if (GET_CODE (operands[0]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"STS %%0,%0\";
  }
  return \"OR %0,%%0,0\";
}")

;; vv--- 35
(define_insn ""
  [(set (match_operand:QI 0 "general_operand" "=mr")
	(const_int 0))]
  ""
  "*
{
  if (GET_CODE (operands[0]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"STB %%0,%0\";
  }
  return \"OR %0,%%0,0\";
}")
;; vv--- 36
(define_insn "movsi"
  [(set (match_operand:SI 0 "general_operand" "=r,=m")
	(match_operand:SI 1 "general_operand" "rmIMJKi,r"))]
  ""
  "*
{
  if (GET_CODE (operands[0]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"ST %1,%0\";
  }
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LD %0,%1\";
  }
  if (GET_CODE (operands[1]) == CONST_INT) {
      int val = (INTVAL (operands[1]));
      if (CONST_OK_FOR_LETTER_P(val,'I'))
	  return \"OR %0,%%0,%1\";
      if (CONST_OK_FOR_LETTER_P(val,'M'))
	  return \"SUB %0,%%0,%n1\";
      if (CONST_OK_FOR_LETTER_P(val,'J'))
	  return \"LEAS %0,%%0[%1]\";
      if (CONST_OK_FOR_LETTER_P(val,'K'))
	  return \"LEA %0,%%0[%1]\";
  }
  if (GET_CODE (operands[1]) == REG)
    return \"OR %0,%%0,%1\";
  return \"LDLIT %0,%1\";
}")

;; vv--- 37
(define_insn "movhi"
  [(set (match_operand:HI 0 "general_operand" "=r,=m")
	(match_operand:HI 1 "general_operand" "rmIMJKi,r"))]
  ""
  "*
{
  if (GET_CODE (operands[0]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"STS %1,%0\";
  }
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDS %0,%1\";
  }
  if (GET_CODE (operands[1]) == CONST_INT) {
      int val = (INTVAL (operands[1]));
      if (CONST_OK_FOR_LETTER_P(val,'I'))
	  return \"OR %0,%%0,%1\";
      if (CONST_OK_FOR_LETTER_P(val,'M'))
	  return \"SUB %0,%%0,%n1\";
      if (CONST_OK_FOR_LETTER_P(val,'J'))
	  return \"LEAS %0,%%0[%1]\";
      if (CONST_OK_FOR_LETTER_P(val,'K'))
	  return \"LEA %0,%%0[%1]\";
  }
  if (GET_CODE (operands[1]) == REG)
    return \"OR %0,%%0,%1\";
  return \"LDLIT %0,%1\";
}")

;; vv--- 38
(define_insn "movqi"
  [(set (match_operand:QI 0 "general_operand" "=r,=m")
	(match_operand:QI 1 "general_operand" "rmIMJKi,r"))]
  ""
  "*
{
  if (GET_CODE (operands[0]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"STB %1,%0\";
  }
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDB %0,%1\";
  }
  if (GET_CODE (operands[1]) == CONST_INT) {
      int val = (INTVAL (operands[1]));
      if (CONST_OK_FOR_LETTER_P(val,'I'))
	  return \"OR %0,%%0,%1\";
      if (CONST_OK_FOR_LETTER_P(val,'M'))
	  return \"SUB %0,%%0,%n1\";
      if (CONST_OK_FOR_LETTER_P(val,'J'))
	  return \"LEAS %0,%%0[%1]\";
      if (CONST_OK_FOR_LETTER_P(val,'K'))
	  return \"LEA %0,%%0[%1]\";
  }
  if (GET_CODE (operands[1]) == REG)
    return \"AND %0,%1,255\";
  return \"LDLIT %0,%1\";
}")

;; Extension and truncation insns.
;; Those for integer source operand
;; are ordered widest source type first.
;; Note that the sihi case does _not_ really truncate

(define_insn "truncsiqi2"
  [(set (match_operand:QI 0 "register_operand" "=r")
	(truncate:QI (match_operand:SI 1 "register_operand" "r")))]
  ""
  "AND %0,%1,0xFF")

(define_insn "truncsihi2"
  [(set (match_operand:HI 0 "register_operand" "=r")
	(truncate:HI (match_operand:SI 1 "general_operand" "rmIMJKi")))]
  ""
  "*
{
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDS %0,%1\";
  }
  if (GET_CODE (operands[1]) == CONST_INT) {
      int val = (INTVAL (operands[1]));
      if (CONST_OK_FOR_LETTER_P(val,'I'))
	  return \"OR %0,%%0,%1\";
      if (CONST_OK_FOR_LETTER_P(val,'M'))
	  return \"SUB %0,%%0,%n1\";
      if (CONST_OK_FOR_LETTER_P(val,'J'))
	  return \"LEAS %0,%%0[%1]\";
      if (CONST_OK_FOR_LETTER_P(val,'K'))
	  return \"LEA %0,%%0[%1]\";
  }
  if (GET_CODE (operands[1]) == REG)
    return \"OR %0,%%0,%1\";
  return \"LDLIT %0,(%1)&0xFFFF\";
}")

(define_insn "trunchiqi2"
  [(set (match_operand:QI 0 "register_operand" "=r")
	(truncate:QI (match_operand:HI 1 "register_operand" "r")))]
  ""
  "AND %0,%1,0xFF")

;;- zero extension instructions

(define_insn "zero_extendqihi2"
  [(set (match_operand:HI 0 "register_operand" "=r")
	(zero_extend:HI
	 (match_operand:QI 1 "general_operand" "g")))]
  ""
  "*
{
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDUB %0,%1\";
  }
  return \"AND %0,%1,255\";
}")

(define_insn "zero_extendhisi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(zero_extend:SI
	 (match_operand:HI 1 "general_operand" "g")))]
  ""
  "*
{
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDUS %0,%1\";
  }
  return \"ASHL %0,%1,16\;LSHR %0,%0,16\";
}")

(define_insn "zero_extendqisi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(zero_extend:SI
	 (match_operand:QI 1 "general_operand" "g")))]
  ""
  "*
{
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDUB %0,%1\";
  }
  return \"AND %0,%1,255\";
}")

;;- sign extension instructions
(define_insn "extendhisi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(sign_extend:SI
	 (match_operand:HI 1 "general_operand" "g")))]
  ""
  "*
{
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDS %0,%1\";
  }
  return \"ASHL %0,%1,16\;ASHR %0,%0,16\";
}")

(define_insn "extendqisi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(sign_extend:SI
	 (match_operand:QI 1 "general_operand" "g")))]
  ""
  "*
{
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDB %0,%1\";
  }
  return \"ASHL %0,%1,24\;ASHR %0,%0,24\";
}")

(define_insn "extendqihi2"
  [(set (match_operand:HI 0 "register_operand" "=r")
	(sign_extend:HI
	 (match_operand:QI 1 "general_operand" "g")))]
  ""
  "*
{
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LDB %0,%1\";
  }
  return \"ASHL %0,%1,24\;ASHR %0,%0,24\";
}")

;;- arithmetic instructions

(define_insn "addsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (match_operand:SI 1 "nonmemory_operand" "%r")
		 (match_operand:SI 2 "nonmemory_operand" "rIMJK")))]
  ""
  "*
{
  if (GET_CODE (operands[2]) == CONST_INT) {
      int val = (INTVAL (operands[2]));
      if (CONST_OK_FOR_LETTER_P(val,'I'))
	  return \"ADD %0,%1,%2\";
      if (CONST_OK_FOR_LETTER_P(val,'M'))
	  return \"SUB %0,%1,%n2\";
      if (CONST_OK_FOR_LETTER_P(val,'J'))
	  return \"LEAS %0,%1[%2]\";
      if (CONST_OK_FOR_LETTER_P(val,'K'))
	  return \"LEA %0,%1[%2]\";
  }
    return \"ADD %0,%1,%2\";
}")

(define_insn "subsi3"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
	(minus:SI (match_operand:SI 1 "register_operand" "r,I")
		  (match_operand:SI 2 "nonmemory_operand" "rI,r")))]
  ""
  "*
{
  if ( !REG_P (operands[1]) ) return \"SUBR %0,%2,%1\";
  return \"SUB %0,%1,%2\";
}")

(define_insn "andsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(and:SI (match_operand:SI 1 "nonmemory_operand" "%r")
		(match_operand:SI 2 "nonmemory_operand" "rI")))]
  ""
  "AND %0,%1,%2")

(define_insn ""
  [(set (match_operand:SI 0 "register_operand" "=r")
	(and:SI (match_operand:SI 1 "nonmemory_operand" "%r")
		(not:SI (match_operand:SI 2 "nonmemory_operand" "rI"))))]
  ""
  "ANDN %0,%1,%2")

(define_insn "iorsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ior:SI (match_operand:SI 1 "nonmemory_operand" "%r")
		(match_operand:SI 2 "nonmemory_operand" "rI")))]
  ""
  "OR %0,%1,%2")

(define_insn "xorsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(xor:SI (match_operand:SI 1 "nonmemory_operand" "%r")
		(match_operand:SI 2 "nonmemory_operand" "rI")))]
  ""
  "XOR %0,%1,%2")

(define_insn ""
  [(set (match_operand:SI 0 "register_operand" "=r")
	(xor:SI (match_operand:SI 1 "nonmemory_operand" "%r")
		(not:SI (match_operand:SI 2 "nonmemory_operand" "rI"))))]
  ""
  "XORN %0,%1,%2")

(define_insn "negsi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(neg:SI (match_operand:SI 1 "nonmemory_operand" "rI")))]
  ""
  "SUB %0,%%0,%1")

(define_insn "one_cmplsi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(not:SI (match_operand:SI 1 "register_operand" "rI")))]
  ""
  "XORN %0,%%0,%1")

;; Floating point arithmetic instructions.
;; Shift instructions

(define_insn "ashlsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ashift:SI (match_operand:SI 1 "register_operand" "r")
		   (match_operand:SI 2 "nonmemory_operand" "rI")))]
  ""
  "ASHL %0,%1,%2")

(define_insn "rotlsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(rotate:SI (match_operand:SI 1 "register_operand" "r")
		   (match_operand:SI 2 "nonmemory_operand" "rI")))]
  ""
  "ROTL %0,%1,%2")

(define_insn "ashrsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ashiftrt:SI (match_operand:SI 1 "register_operand" "r")
		     (match_operand:SI 2 "nonmemory_operand" "rI")))]
  ""
  "ASHR %0,%1,%2")

(define_insn "lshrsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(lshiftrt:SI (match_operand:SI 1 "register_operand" "r")
		     (match_operand:SI 2 "nonmemory_operand" "rI")))]
  ""
  "LSHR %0,%1,%2")

;; Unconditional and other jump instructions
(define_insn "jump"
  [(set (pc)
	(label_ref (match_operand 0 "" "")))]
  ""
  "BRA %l0\;ADD %%0,%%0,0")

(define_insn ""
  [(set (pc)
	(match_operand:SI 0 "register_operand" "r"))]
  ""
  "JSR %%0,%0[0]\;ADD %%0,%%0,0")

(define_insn ""
  [(set (pc)
	(plus:SI (match_operand:SI 0 "register_operand" "r")
	  	 (umult:SI (match_operand:SI 1 "register_operand" "r")
			   (const_int 4) )))]
  ""
  "JSR %%0,%0[%1]\;ADD %%0,%%0,0")

;;- jump to subroutine (no value returned)
(define_insn "call"
  [(call (match_operand:SI 0 "memory_operand" "m")
	 (match_operand:SI 1 "general_operand" "g"))
   (clobber (reg:SI 28))]
  ;;- Don't use operand 1 for most machines.
  ""
  "JSR .RP,%0\;ADD %%0,%%0,0")

;; Call subroutine, returning value in operand 0
;; (which must be a hard register).
(define_insn "call_value"
  [(set (match_operand 0 "" "r")
	(call (match_operand:SI 1 "memory_operand" "m")
	      (match_operand:SI 2 "general_operand" "g")))
   (clobber (reg:SI 28))]
  ;; Operand 2 not really used most machines.
  ""
  "JSR .RP,%1\;ADD %%0,%%0,0")

;; The following anon. define_insn's are for the only "general-reach"
;; instruction, BSR

(define_insn ""
  [(call (mem:SI (match_operand:SI 0 "" "i"))
	 (match_operand:SI 1 "general_operand" "g"))
   (clobber (reg:SI 28))]
  ;;- Don't use operand 1 for most machines.
  "GET_CODE (operands[0]) == SYMBOL_REF"
  "BSR .RP,%0\;ADD %%0,%%0,0")

(define_insn ""
  [(set (match_operand 0 "" "g")
	(call (mem:SI (match_operand:SI 1 "" "i"))
	      (match_operand:SI 2 "general_operand" "g")))
   (clobber (reg:SI 28))]
  ;;- Don't use operand 1 for most machines.
  "GET_CODE (operands[1]) == SYMBOL_REF"
  "BSR .RP,%1\;ADD %%0,%%0,0")

;;- tablejump, aka case
(define_insn "tablejump"
  [(set (pc) (match_operand:SI 0 "register_operand" "r"))
   (use (label_ref (match_operand 1 "" "")))]
  ""
  "JSR %%0,%0[0]\;ADD %%0,%%0,0")

(define_insn "nop"
  [(const_int 0)]
  ""
  "ADD %%0,%%0,42")

(define_insn "movsf"
  [(set (match_operand:SF 0 "general_operand" "=r,=m")
	(match_operand:SF 1 "general_operand" "rms,r"))]
  ""
  "*
{
  if (GET_CODE (operands[0]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[0]);
    return \"ST %1,%0\";
  }
  if (GET_CODE (operands[1]) == MEM) {
    FIX_ADDRESS_IF_NEEDED (operands[1]);
    return \"LD %0,%1\";
  }
  if (GET_CODE (operands[1]) == REG)
    return \"OR %0,%%0,%1\";
  return \"LDLIT %0,%1\";
}")

(define_insn "movdf"
  [(set (match_operand:DF 0 "general_operand" "=r,m")
	(match_operand:DF 1 "general_operand" "rmi,r"))]
  ""
  "* return output_move_double (operands);")

(define_insn "movdi"
  [(set (match_operand:DI 0 "general_operand" "=r,m")
	(match_operand:DI 1 "general_operand" "rmi,r"))]
  ""
  "* return output_move_double (operands);")


;; LEA(H) patterns
(define_insn ""
  [(set (match_operand:SI 0 "register_operand" "=r")
	(match_operand:SI 1 "address_operand" "p"))]
  ""
  "*
{
  FIX_ADDRESS_IF_NEEDED (operands[1]);
  return \"LEA %0,%a1\";
}")

(define_insn ""
  [(set (match_operand:SI 0 "register_operand" "=r")
	(match_operand:HI 1 "address_operand" "p"))]
  ""
  "*
{
  FIX_ADDRESS_IF_NEEDED (operands[1]);
  return \"LEAS %0,%a1\";
}")

;;- Local variables:
;;- mode:emacs-lisp
;;- comment-start: ";;- "
;;- eval: (set-syntax-table (copy-sequence (syntax-table)))
;;- eval: (modify-syntax-entry ?[ "(]")
;;- eval: (modify-syntax-entry ?] ")[")
;;- eval: (modify-syntax-entry ?{ "(}")
;;- eval: (modify-syntax-entry ?} "){")
;;- End:


