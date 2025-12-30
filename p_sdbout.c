# 1 "sdbout.c"
 




















# 1 "config.h" 1
 



















 



 





 





 

# 1 "tm.h" 1
 


 

# 1 "./config/tm-i386v.h" 1
 



















# 1 "./config/tm-i386.h" 1
 



















 


 

 




 

extern int target_flags;

 

 

 

  

 





 














 

 

 
 

 

 
 
 

 
 
 

 


 





 


 



 


 


 


 


 



 
 



 

 

 

 











 






 

 











 













 







 






 


 

 

 


 


 

 





 


 


 






 





 


















   

enum reg_class {
  NO_REGS, AREG, DREG, ADREG, CREG, BREG, Q_REGS, SIREG, DIREG,
  INDEX_REGS, GENERAL_REGS, FLOAT_REGS, ALL_REGS, LIM_REG_CLASSES };



 





 








 





# 283 "./config/tm-i386.h"







 




 




 






 




 


# 323 "./config/tm-i386.h"

 











 





 








# 360 "./config/tm-i386.h"

 

 





 

 



 





 





 







 


 





















 





 





 










 








 








 













 







 











 










 





 



 





 












 






# 583 "./config/tm-i386.h"
 

 
 

 
 

 

 













 














 


 

   




# 641 "./config/tm-i386.h"


 











 










 










 









 














 


















# 749 "./config/tm-i386.h"

 






 



 


 

 




 


 


 



 
 

 


 




 



 




 




 




 




 





 





# 841 "./config/tm-i386.h"

 

 





 


 



 







 















 







 


 







 


 




 







 









 

 



 





 





 









 









 






 
 






 














 




 





 





 





 







 





 








 
























 






 





 





 




# 21 "./config/tm-i386v.h" 2


 

# 1 "./config/tm-att386.h" 1
 





















 

 













 





 


 


 


 


 



 


 


 



 




  
 



 











 

 






 



 
 









 




 




 






 


 


# 156 "./config/tm-att386.h"

 



 



 






# 181 "./config/tm-att386.h"

 

 

 








 


 


# 209 "./config/tm-att386.h"

 







 




 





 





 









# 25 "./config/tm-i386v.h" 2


 



 







 





 



 



 



 



 



 



 




 

 







 


# 6 "tm.h" 2


 






 





 








 



 





# 39 "config.h" 2









# 22 "sdbout.c" 2




# 1 "tree.h" 1
 



















 



enum tree_code {
# 1 "tree.def" 1
 



















 
 









 



 




  ERROR_MARK, 

 



  IDENTIFIER_NODE, 

 


  OP_IDENTIFIER, 

 
 



  TREE_LIST, 

 

 


















 




  VOID_TYPE, 	 

 
 




  INTEGER_TYPE, 

 

  REAL_TYPE, 

 

  COMPLEX_TYPE, 

 




 




  ENUMERAL_TYPE, 

 

  BOOLEAN_TYPE, 

 

  CHAR_TYPE, 

 

  POINTER_TYPE, 

 



  OFFSET_TYPE, 

 

  REFERENCE_TYPE, 

 




  METHOD_TYPE, 

 
  FILE_TYPE, 

 







 
  ARRAY_TYPE, 

 

  SET_TYPE, 

 

  STRING_TYPE, 

 
 


 

  RECORD_TYPE, 

 

 

  UNION_TYPE, 	 

 





  FUNCTION_TYPE, 

 



  LANG_TYPE, 

 
 


 

  LABEL_STMT, 

 
  GOTO_STMT, 

 




  RETURN_STMT, 

 
  EXPR_STMT, 

 



  WITH_STMT, 

 















  LET_STMT, 

 



  IF_STMT, 

 


  EXIT_STMT, 

 








  CASE_STMT, 

 
  LOOP_STMT, 

 
  COMPOUND_STMT, 

 
  ASM_STMT, 

 

 

 




  INTEGER_CST, 

 
  REAL_CST, 

 


  COMPLEX_CST, 

 

  STRING_CST, 

 

















































  FUNCTION_DECL, 
  LABEL_DECL, 
  CONST_DECL, 
  TYPE_DECL, 
  VAR_DECL, 
  PARM_DECL, 
  RESULT_DECL, 
  FIELD_DECL, 

 

 


  COMPONENT_REF, 

 
  INDIRECT_REF, 

 



  OFFSET_REF, 

 
  BUFFER_REF, 

 


  ARRAY_REF, 

 





  CONSTRUCTOR, 

 




 

  COMPOUND_EXPR, 

 
  MODIFY_EXPR, 

 

  INIT_EXPR, 

 

  NEW_EXPR, 
  DELETE_EXPR, 

 


  PUSH_EXPR, 
  POP_EXPR, 

 



  COND_EXPR, 

 




  CALL_EXPR, 

 


  METHOD_CALL_EXPR, 

 







  WITH_CLEANUP_EXPR, 

 

  PLUS_EXPR, 
  MINUS_EXPR, 
  MULT_EXPR, 

 
 



  TRUNC_DIV_EXPR, 

 
  CEIL_DIV_EXPR, 

 
  FLOOR_DIV_EXPR, 

 
  ROUND_DIV_EXPR, 

 
  TRUNC_MOD_EXPR, 
  CEIL_MOD_EXPR, 
  FLOOR_MOD_EXPR, 
  ROUND_MOD_EXPR, 

 



  RDIV_EXPR, 

 

  EXACT_DIV_EXPR, 

 




  FIX_TRUNC_EXPR, 
  FIX_CEIL_EXPR, 
  FIX_FLOOR_EXPR, 
  FIX_ROUND_EXPR, 

 
  FLOAT_EXPR, 

 

  EXPON_EXPR, 

 
  NEGATE_EXPR, 

  MIN_EXPR, 
  MAX_EXPR, 
  ABS_EXPR, 
  FFS_EXPR, 

 





  LSHIFT_EXPR, 
  RSHIFT_EXPR, 
  LROTATE_EXPR, 
  RROTATE_EXPR, 

 
  BIT_IOR_EXPR, 
  BIT_XOR_EXPR, 
  BIT_AND_EXPR, 
  BIT_ANDTC_EXPR, 
  BIT_NOT_EXPR, 

 




  TRUTH_ANDIF_EXPR, 
  TRUTH_ORIF_EXPR, 
  TRUTH_AND_EXPR, 
  TRUTH_OR_EXPR, 
  TRUTH_NOT_EXPR, 

 





  LT_EXPR, 
  LE_EXPR, 
  GT_EXPR, 
  GE_EXPR, 
  EQ_EXPR, 
  NE_EXPR, 

 
  IN_EXPR, 
  SET_LE_EXPR, 
  CARD_EXPR, 
  RANGE_EXPR, 

 


  CONVERT_EXPR, 

 
  NOP_EXPR, 

 




  SAVE_EXPR, 

 



  RTL_EXPR, 

 

  ADDR_EXPR, 

 


  REFERENCE_EXPR, 

 



  WRAPPER_EXPR, 
  ANTI_WRAPPER_EXPR, 

 

  ENTRY_VALUE_EXPR, 

 

  COMPLEX_EXPR, 

 

  CONJ_EXPR, 

 

  REALPART_EXPR, 
  IMAGPART_EXPR, 

 


  PREDECREMENT_EXPR, 
  PREINCREMENT_EXPR, 
  POSTDECREMENT_EXPR, 
  POSTINCREMENT_EXPR, 

 





# 26 "tree.h" 2


  LAST_AND_UNUSED_TREE_CODE	 

};



 


 




extern char *tree_code_type[];

 

extern int tree_code_length[];

 




enum machine_mode {
# 1 "machmode.def" 1
 




















 










 






























 




 

 VOIDmode, 

 QImode, 		 
 HImode, 
 


 PSImode, 
 SImode, 
 PDImode, 
 DImode, 
 TImode, 
 QFmode, 
 HFmode, 	 
 SFmode, 
 DFmode, 
 XFmode,    
 TFmode, 
 CQImode, 
 CHImode,    
 CSImode, 
 CDImode, 
 CTImode, 
 CQFmode, 
 CHFmode,   
 CSFmode, 
 CDFmode, 
 CXFmode, 
 CTFmode, 

 

 BImode, 	 

 

 BLKmode, 

 
 EPmode, 

 


 





# 54 "tree.h" 2

MAX_MACHINE_MODE };











 


enum built_in_function
{
  NOT_BUILT_IN,
  BUILT_IN_ALLOCA,
  BUILT_IN_ABS,
  BUILT_IN_FABS,
  BUILT_IN_LABS,
  BUILT_IN_FFS,
  BUILT_IN_DIV,
  BUILT_IN_LDIV,
  BUILT_IN_FFLOOR,
  BUILT_IN_FCEIL,
  BUILT_IN_FMOD,
  BUILT_IN_FREM,
  BUILT_IN_MEMCPY,
  BUILT_IN_MEMCMP,
  BUILT_IN_MEMSET,
  BUILT_IN_FSQRT,
  BUILT_IN_GETEXP,
  BUILT_IN_GETMAN,
  BUILT_IN_SAVEREGS,
  BUILT_IN_CLASSIFY_TYPE,
  BUILT_IN_NEXT_ARG,

   
  BUILT_IN_NEW,
  BUILT_IN_VEC_NEW,
  BUILT_IN_DELETE,
  BUILT_IN_VEC_DELETE
};

 

 













 

typedef union tree_node *tree;



 




struct tree_common
{
  int uid;
  union tree_node *chain;
  union tree_node *type;
  unsigned char code : 8;

  unsigned external_attr : 1;
  unsigned public_attr : 1;
  unsigned static_attr : 1;
  unsigned volatile_attr : 1;
  unsigned packed_attr : 1;
  unsigned readonly_attr : 1;
  unsigned literal_attr : 1;
  unsigned nonlocal_attr : 1;
  unsigned permanent_attr : 1;
  unsigned addressable_attr : 1;
  unsigned regdecl_attr : 1;
  unsigned this_vol_attr : 1;
  unsigned unsigned_attr : 1;
  unsigned asm_written_attr: 1;
  unsigned inline_attr : 1;
  unsigned used_attr : 1;
  unsigned lang_flag_1 : 1;
  unsigned lang_flag_2 : 1;
  unsigned lang_flag_3 : 1;
  unsigned lang_flag_4 : 1;
   
};

 


 



 




 




 










 

 




 



 



 












 




 







 




 




 






 





 








 




 



 





 



 







 

 
















struct tree_int_cst
{
  char common[sizeof (struct tree_common)];
  long int_cst_low;
  long int_cst_high;
};

 





 
 





# 1 "real.h" 1
 





















 








 




 




 


extern double ldexp ();


 


extern double atof ();


 




 




 


union real_extract 
{
  double  d;
  int i[sizeof (double ) / sizeof (int)];
};

 









 

 




 

double  real_value_from_int_cst ();


# 325 "tree.h" 2


struct tree_real_cst
{
  char common[sizeof (struct tree_common)];
  struct rtx_def *rtl;	 

  double  real_cst;
};

 



struct tree_string
{
  char common[sizeof (struct tree_common)];
  struct rtx_def *rtl;	 

  int length;
  char *pointer;
};

 



struct tree_complex
{
  char common[sizeof (struct tree_common)];
  struct rtx_def *rtl;	 

  union tree_node *real;
  union tree_node *imag;
};

 




struct tree_identifier
{
  char common[sizeof (struct tree_common)];
  int length;
  char *pointer;
};

 



struct tree_list
{
  char common[sizeof (struct tree_common)];
  union tree_node *purpose;
  union tree_node *value;
};

 

 


 



 


 


 



struct tree_exp
{
  char common[sizeof (struct tree_common)];
  int complexity;
  union tree_node *operands[1];
};

 

 




























struct tree_type
{
  char common[sizeof (struct tree_common)];
  union tree_node *values;
  union tree_node *sep;
  union tree_node *size;

  enum machine_mode mode : 8;
  unsigned char size_unit;
  unsigned char align;
  unsigned char sep_unit;

  union tree_node *pointer_to;
  union tree_node *reference_to;
  int parse_info;
  int symtab_address;
  union tree_node *name;
  union tree_node *max;
  union tree_node *next_variant;
  union tree_node *main_variant;
  union tree_node *basetypes;
  union tree_node *noncopied_parts;
   
  struct lang_type *lang_specific;
};

 





























struct tree_decl
{
  char common[sizeof (struct tree_common)];
  char *filename;
  int linenum;
  union tree_node *size;
  enum machine_mode mode : 8;
  unsigned char size_unit;
  unsigned char align;
  unsigned char voffset_unit;
  union tree_node *name;
  union tree_node *context;
  int offset;
  union tree_node *voffset;
  union tree_node *arguments;
  union tree_node *result;
  union tree_node *initial;
  char *print_name;
  char *assembler_name;
  struct rtx_def *rtl;	 

  int frame_size;		 
  struct rtx_def *saved_insns;	 


  int block_symtab_address;
   
  struct lang_decl *lang_specific;
};

 





 





struct tree_stmt
{
  char common[sizeof (struct tree_common)];
  char *filename;
  int linenum;
  union tree_node *body;
};

 

 
 




struct tree_if_stmt
{
  char common[sizeof (struct tree_common)];
  char *filename;
  int linenum;
  union tree_node *cond, *thenpart, *elsepart;
};

 

 
 
 






struct tree_bind_stmt
{
  char common[sizeof (struct tree_common)];
  char *filename;
  int linenum;
  union tree_node *body, *vars, *supercontext, *bind_size, *type_tags;
  union tree_node *subblocks;
};

 




struct tree_case_stmt
{
  char common[sizeof (struct tree_common)];
  char *filename;
  int linenum;
  union tree_node *index, *case_list;
};

 



union tree_node
{
  struct tree_common common;
  struct tree_int_cst int_cst;
  struct tree_real_cst real_cst;
  struct tree_string string;
  struct tree_complex complex;
  struct tree_identifier identifier;
  struct tree_decl decl;
  struct tree_type type;
  struct tree_list list;
  struct tree_exp exp;
  struct tree_stmt stmt;
  struct tree_if_stmt if_stmt;
  struct tree_bind_stmt bind_stmt;
  struct tree_case_stmt case_stmt;
};

extern char *oballoc ();
extern char *permalloc ();

 



extern tree make_node ();

 



extern tree copy_node ();

 

extern tree copy_list ();

 


extern tree get_identifier ();

 

extern tree build_int_2 ();
extern tree build_real ();
extern tree build_real_from_string ();
extern tree build_real_from_int_cst ();
extern tree build_complex ();
extern tree build_string ();
extern tree build ();
extern tree build_nt ();
extern tree build_tree_list ();
extern tree build_op_identifier ();
extern tree build_decl ();
extern tree build_let ();

 

extern tree make_signed_type ();
extern tree make_unsigned_type ();
extern void fixup_unsigned_type ();
extern tree build_pointer_type ();
extern tree build_reference_type ();
extern tree build_index_type ();
extern tree build_array_type ();
extern tree build_function_type ();
extern tree build_method_type ();
extern tree build_offset_type ();
extern tree array_type_nelts ();

 

extern tree build_binary_op ();
extern tree build_indirect_ref ();
extern tree build_unary_op ();

 






extern tree build_type_variant ();

 




extern void layout_type ();

 




extern tree type_hash_canon ();

 







extern void layout_decl ();

 





extern tree fold ();

 



extern tree combine ();

extern tree convert ();
extern tree convert_units ();
extern tree size_in_bytes ();
extern tree genop ();
extern tree build_int ();
extern tree get_pending_sizes ();

 

extern tree sizetype;

 



extern tree chainon ();

 

extern tree tree_cons (), perm_tree_cons (), temp_tree_cons ();
extern tree saveable_tree_cons ();

 

extern tree tree_last ();

 

extern tree nreverse ();

 


extern int list_length ();

 

extern int integer_zerop ();

 

extern int integer_onep ();

 


extern int integer_all_onesp ();

 




extern int type_unsigned_p ();

 


extern int staticp ();

 


extern int lvalue_or_else ();

 



extern tree save_expr ();

 



extern tree stabilize_reference ();

 




extern tree get_unwidened ();

 




extern tree get_narrower ();

 




extern tree type_for_size ();

 




extern tree unsigned_type ();

 




extern tree signed_type ();

 

extern tree get_floating_type ();

 




extern char *function_cannot_inline_p ();

 

 
extern tree integer_zero_node;

 
extern tree integer_one_node;

 
extern tree size_zero_node;

 
extern tree size_one_node;

 
extern tree null_pointer_node;

 
extern tree error_mark_node;

 
extern tree void_type_node;

 
extern tree integer_type_node;

 
extern tree unsigned_type_node;

 
extern tree char_type_node;

 

extern char *input_filename;

 
extern int lineno;

 

extern int pedantic;

 


extern int immediate_size_expand;

 

extern tree current_function_decl;

 

extern int current_function_calls_setjmp;

 

extern int all_types_permanent;

 

extern tree expand_start_stmt_expr ();
extern tree expand_end_stmt_expr ();
extern void expand_expr_stmt (), clear_last_expr ();
extern void expand_label (), expand_goto (), expand_asm ();
extern void expand_start_cond (), expand_end_cond ();
extern void expand_start_else (), expand_end_else ();
extern void expand_start_loop (), expand_start_loop_continue_elsewhere ();
extern void expand_loop_continue_here ();
extern void expand_end_loop ();
extern int expand_continue_loop ();
extern int expand_exit_loop (), expand_exit_loop_if_false ();
extern int expand_exit_something ();

extern void expand_start_delayed_expr ();
extern tree expand_end_delayed_expr ();
extern void expand_emit_delayed_expr ();

extern void expand_null_return (), expand_return ();
extern void expand_start_bindings (), expand_end_bindings ();
extern void expand_start_case (), expand_end_case ();
extern int pushcase (), pushcase_range ();
extern void expand_start_function (), expand_end_function ();
# 26 "sdbout.c" 2

# 1 "rtl.h" 1
 





















 


enum rtx_code  {


# 1 "rtl.def" 1
 





















 






















 




 
  UNKNOWN , 

 

  NIL , 

 



 
  EXPR_LIST , 

 

  INSN_LIST , 

 




 































  MATCH_OPERAND , 

 


  MATCH_DUP , 

 




  MATCH_OPERATOR , 

 
















  DEFINE_INSN , 

 




  DEFINE_PEEPHOLE , 

 

  DEFINE_COMBINE , 

 









  DEFINE_EXPAND , 
   
 



  SEQUENCE , 

 



  ADDRESS , 

 









 
  INSN , 

 



  JUMP_INSN , 

 



  CALL_INSN , 

 
  BARRIER , 

 




  CODE_LABEL , 
     
 







  NOTE , 

 



  INLINE_HEADER , 

 


   
 
  PARALLEL , 

 





  ASM_INPUT , 

 











  ASM_OPERANDS , 

 
 
  ADDR_VEC , 

 



  ADDR_DIFF_VEC , 

 



 





  SET , 

 


  USE , 

 


  CLOBBER , 

 



  CALL , 

 

  RETURN , 

 



 
  CONST_INT , 

 






  CONST_DOUBLE , 

 



  CONST , 

 

  PC , 

 


  REG , 

 







  SUBREG , 

 










  STRICT_LOW_PART , 

 

  MEM , 

 



  LABEL_REF , 

 



  SYMBOL_REF , 

 




  CC0 , 

 















  QUEUED , 

 



 





  IF_THEN_ELSE , 

 
  COMPARE , 

 
  PLUS , 

 
  MINUS , 

 
  NEG , 

  MULT , 

 
  DIV , 
 
  MOD , 

 

  UMULT , 
  UDIV , 
  UMOD , 

 
  AND , 

  IOR , 

  XOR , 

  NOT , 

 




  LSHIFT , 
  ASHIFT , 
  ROTATE , 

 


  ASHIFTRT , 
  LSHIFTRT , 
  ROTATERT , 

 






  PRE_DEC , 
  PRE_INC , 
  POST_DEC , 
  POST_INC , 

 

  NE , 
  EQ , 
  GE , 
  GT , 
  LE , 
  LT , 
  GEU , 
  GTU , 
  LEU , 
  LTU , 

 


  SIGN_EXTEND , 

 
  ZERO_EXTEND , 

 
  TRUNCATE , 

 
  FLOAT_EXTEND , 
  FLOAT_TRUNCATE , 

 
  FLOAT , 

 





  FIX , 

 
  UNSIGNED_FLOAT , 

 


  UNSIGNED_FIX , 

 
  ABS , 

 
  SQRT , 

 


  FFS , 

 








  SIGN_EXTRACT , 

 
  ZERO_EXTRACT , 

 





# 29 "rtl.h" 2



  LAST_AND_UNUSED_RTX_CODE};	 




				 

extern int rtx_length[];


extern char *rtx_name[];


extern char *rtx_format[];



 

# 63 "rtl.h"






 

extern char *mode_name[];


enum mode_class { MODE_RANDOM, MODE_INT, MODE_FLOAT,
		  MODE_COMPLEX_INT, MODE_COMPLEX_FLOAT, MODE_FUNCTION };

 


extern enum mode_class mode_class[];


 

extern int mode_size[];


 

extern int mode_unit_size[];


 



 






 

extern enum machine_mode mode_wider_mode[];


 

typedef union rtunion_def
{
  int rtint;
  char *rtstr;
  struct rtx_def *rtx;
  struct rtvec_def *rtvec;
  enum machine_mode rttype;
} rtunion;

 

typedef struct rtx_def
{



   
  enum rtx_code code : 16;

   
  enum machine_mode mode : 8;
   

  unsigned int jump : 1;
   
  unsigned int call : 1;
   




  unsigned int unchanging : 1;
   
   

   

  unsigned int volatil : 1;
   


  unsigned int in_struct : 1;
   


  unsigned int used : 1;
   


  unsigned integrated : 1;
   


  rtunion fld[1];
} *rtx;



 















 



typedef struct rtvec_def{
  unsigned num_elem;		 
  rtunion elem[1];
} *rtvec;






 



 






 








 

 



 



 


 



 






 


 





































 
enum reg_note { REG_DEAD = 1, REG_INC = 2, REG_EQUIV = 3, REG_WAS_0 = 4,
		REG_EQUAL = 5, REG_RETVAL = 6, REG_LIBCALL = 7,
		REG_NONNEG = 8, REG_UNSET = 9 };

 


 

extern char *reg_note_name[];


 






 




 



 


 



 






 





 

 

 







 

extern char *note_insn_name[];


 



 




 





 





 




 



 




 


 



 





 












 



 


 




 

 


 





















 

extern rtx rtx_alloc ();
extern rtvec rtvec_alloc ();
extern rtx find_reg_note ();
extern rtx gen_rtx ();
extern rtx copy_rtx ();
extern rtvec gen_rtvec ();
extern rtvec gen_rtvec_v ();
extern rtx gen_reg_rtx ();
extern rtx gen_label_rtx ();
extern rtx gen_inline_header_rtx ();
extern rtx gen_lowpart ();
extern rtx gen_highpart ();
extern int subreg_lowpart_p ();
extern rtx make_safe_from ();
extern rtx memory_address ();
extern rtx get_insns ();
extern rtx get_last_insn ();
extern rtx start_sequence ();
extern rtx gen_sequence ();
extern rtx expand_expr ();
extern rtx output_constant_def ();
extern rtx immed_real_const ();
extern rtx immed_real_const_1 ();
extern rtx immed_double_const ();
extern rtx force_const_double_mem ();
extern rtx force_const_mem ();
extern rtx get_parm_real_loc ();
extern rtx assign_stack_local ();
extern rtx protect_from_queue ();
extern void emit_queue ();
extern rtx emit_move_insn ();
extern rtx emit_insn ();
extern rtx emit_jump_insn ();
extern rtx emit_call_insn ();
extern rtx emit_call_insn_before ();
extern rtx emit_insn_before ();
extern rtx emit_insn_after ();
extern rtx emit_label ();
extern rtx emit_barrier ();
extern rtx emit_barrier_after ();
extern rtx emit_note ();
extern rtx emit_line_note ();
extern rtx emit_line_note_force ();
extern rtx prev_real_insn ();
extern rtx next_real_insn ();
extern rtx next_nondeleted_insn ();
extern rtx plus_constant ();
extern rtx find_equiv_reg ();
extern rtx delete_insn ();
extern rtx adj_offsettable_operand ();

 



extern int max_parallel;

extern int asm_noperands ();
extern char *decode_asm_operands ();


 
extern enum reg_class reg_preferred_class ();


extern rtx get_first_nonparm_insn ();

 
extern rtx pc_rtx;
extern rtx cc0_rtx;
extern rtx const0_rtx;
extern rtx const1_rtx;
extern rtx fconst0_rtx;
extern rtx dconst0_rtx;

 







 


extern rtx stack_pointer_rtx;
extern rtx frame_pointer_rtx;
extern rtx arg_pointer_rtx;
extern rtx struct_value_rtx;
extern rtx struct_value_incoming_rtx;
extern rtx static_chain_rtx;
extern rtx static_chain_incoming_rtx;
# 27 "sdbout.c" 2

# 1 "/usr/include/stdio.h" 1
 







 




# 1 "./limits.h" 1
 


 


 



 


 








 



 


 



 


 




 

# 14 "/usr/include/stdio.h" 2




typedef long	fpos_t;



typedef char	*va_list;



typedef unsigned int	size_t;
















 


typedef struct {

	int	_cnt;
	unsigned char	*_ptr;





	unsigned char	*_base;
	char	_flag;
	char	_file;
} FILE;

 
















































extern FILE	_iob[60 ];

extern FILE	*tmpfile(void);	 
extern char	*tmpnam(char *s);	 
extern int	fclose(FILE *stream);	 
extern int	fflush(FILE *stream);	 
extern FILE	*fopen(const char *filename, const char *mode);	 
extern FILE	*freopen(const char *filename, const char *mode, FILE *stream);
extern void	setbuf(FILE *stream, char *buf);
extern int	setvbuf(FILE *stream, char *buf, int mode, size_t size);
extern int	fprintf(FILE *stream, const char *format, ...);
extern int	fscanf(FILE *stream, const char *format, ...);
extern int	printf(const char *format, ...);
extern int	scanf(const char *format, ...);
extern int	sprintf(char *s, const char *format, ...);
extern int	sscanf(const char *s, const char *format, ...);
extern int	vfprintf(FILE *stream, const char *format, va_list arg);
extern int	vprintf(const char *format, va_list arg);
extern int	vsprintf(char *s, const char *format, va_list arg);
extern int	fgetc(FILE *stream);
extern char	*fgets(char *s, int n, FILE *stream);
extern int	fputc(int c, FILE *stream);
extern int	fputs(const char *s, FILE *stream);
extern char	*gets(char *s);
 
 
 
 
extern int	puts(char *s);
extern int	ungetc(int c, FILE *stream);
extern size_t	fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
extern size_t	fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
extern int	fseek(FILE *stream, long offset, int whence);
extern long	ftell(FILE *stream);
extern void	rewind(FILE *stream);
extern void	perror(const char *s);
 
extern int	putw(int w, FILE *stream);
extern int	getw(FILE *stream);
extern FILE	*fdopen(int fildes, const char *type);
extern FILE	*popen(const char *command, const char *type);
extern int	pclose(FILE *stream);
extern int	system(const char *command);
extern char	*tempnam(char *dir, char *pfx);
extern char	*ctermid(char *s);
extern char	*cuserid(char *s);

extern int	rename(const char *old, const char *new);
extern int	fsetpos(FILE *, const fpos_t *);
extern int	fgetpos(FILE *, fpos_t *);
# 175 "/usr/include/stdio.h"

extern unsigned char *_bufendtab[];














# 28 "sdbout.c" 2



# 1 "/usr/include/syms.h" 1
 








 
 

 
 
 

 



/* #pragma comment(exestr, "@(#) syms.h 1.6 89/08/09 ") */
 


 
# 1 "/usr/include/storclass.h" 1
 








 
 

 
 
 

 



/* #pragma comment(exestr, "@(#) storclass.h 1.6 89/08/09 ") */
 


 




























	 







			        




# 26 "/usr/include/syms.h" 2


 

 

 



struct syment
{
	union
	{
		char		_n_name[8 ];	 
		struct
		{
			long	_n_zeroes;	 
			long	_n_offset;	 
		} _n_n;
		char		*_n_nptr[2];	 
	} _n;
	long			n_value;	 
	short			n_scnum;	 
	unsigned short		n_type;		 
	char			n_sclass;	 
	char			n_numaux;	 
};






 




         

         

         

	 


	 



 























 








 










 



	 



	 



	 



	 



	 







 



union auxent
{
	struct
	{
		long		x_tagndx;	 
		union
		{
			struct
			{
				unsigned short	x_lnno;	 
				unsigned short	x_size;	 
			} x_lnsz;
			long	x_fsize;	 
		} x_misc;
		union
		{
			struct			 
			{
				long	x_lnnoptr;	 
				long	x_endndx;	 
			} 	x_fcn;
			struct			 
			{
				unsigned short	x_dimen[	4 ];
			} 	x_ary;
		}		x_fcnary;
		unsigned short  x_tvndx;		 
	} 	x_sym;
	struct
	{
		char	x_fname[14 ];
	} 	x_file;
        struct
        {
                long    x_scnlen;           
                unsigned short  x_nreloc;   
                unsigned short  x_nlinno;   
        }       x_scn;

	struct
	{
		long		x_tvfill;	 
		unsigned short	x_tvlen;	 
		unsigned short	x_tvran[2];	 
	}	x_tv;	 
};







 





















# 31 "sdbout.c" 2

 

# 95 "sdbout.c"


 


int sdb_begin_function_line = -1;

 

static int unnamed_struct_number = 0;

extern FILE *asm_out_file;

extern tree current_function_decl;

void sdbout_init ();
void sdbout_symbol ();
void sdbout_tags();
void sdbout_types();

static void sdbout_syms ();
static void sdbout_one_type ();
static int plain_type_1 ();

 

 


 





































































































 

  


 




 







 



 






void
sdbout_filename (asm_file, input_name)
     FILE *asm_file;
     char *input_name;
{
  int len = strlen (input_name);
  char *na = input_name + len;

   
  while (na > input_name)
    {
      if (na[-1] == '/')
	break;
      na--;
    }




  fprintf (asm_file, "\t.file\t\"%s\"\n", na);

}

 

void
sdbout_init ()
{
   
  sdbout_types (nreverse (get_permanent_types ()));
}

# 307 "sdbout.c"


 

static char *
gen_fake_label ()
{
  char label[10];
  char *labelstr;
  sprintf ((label), ".%dfake", ( unnamed_struct_number)); ;
  unnamed_struct_number++;
  labelstr = (char *) permalloc (strlen (label) + 1);
  strcpy (labelstr, label);
  return labelstr;
}

 




 








 





 
static int sdb_n_dims = 0;

 
static int sdb_dims[4 ];

 
static int sdb_type_size = -1;

static int
plain_type (type)
     tree type;
{
  int val = plain_type_1 (type);

   
  if (sdb_n_dims > 0)
    {
      int i;
      fprintf(asm_out_file, "\t.dim\t") ;
      for (i = sdb_n_dims - 1; i > 0; i--)
	fprintf(asm_out_file, "%d,", sdb_dims[i]) ;
      fprintf(asm_out_file, "%d;", sdb_dims[0]) ;
      sdb_n_dims = 0;

      sdb_type_size = int_size_in_bytes (type);
       
      if (sdb_type_size < 0)
	sdb_type_size = 0;
    }
   

  if (sdb_type_size >= 0)
    {
      fprintf(asm_out_file, "\t.size\t%d;", sdb_type_size) ;
      sdb_type_size = -1;
    }
  return val;
}

static void
sdbout_record_type_name (type)
     tree type;
{
  char *name = 0;

  if ((char *)(((type)->type.symtab_address) ) )
    return;

  if (((type)->type.name)  != 0) 
    {
      tree t = 0;
       
      if (((enum tree_code) (((type)->type.name) )->common.code)  == IDENTIFIER_NODE)
	{
	  t = ((type)->type.name) ;
	}
      else if (((enum tree_code) (((type)->type.name) )->common.code)  == TYPE_DECL)
	{
	  t = ((((type)->type.name) )->decl.name) ;
	}

       
      if (t != 0)
	name = ((t)->identifier.pointer) ;
    }

  if (name == 0)
    name = gen_fake_label ();

  (((type)->type.symtab_address)  = (int)( name)) ;
}

static int
plain_type_1 (type)
     tree type;
{
  if (type == 0)  
    type = void_type_node;
  if (type == error_mark_node)
    type = integer_type_node;
  type = ((type)->type.main_variant) ;

  switch (((enum tree_code) (type)->common.code) )
    {
    case VOID_TYPE:
      return      4          ;
    case INTEGER_TYPE:
      switch (int_size_in_bytes (type))
	{
	case 4:
	  return (((type)->common.unsigned_attr)  ?     14          :      4          );
	case 1:
	  return (((type)->common.unsigned_attr)  ?    12          :     2          );
	case 2:
	  return (((type)->common.unsigned_attr)  ?   13          :    3          );
	default:
	  return 0;
	}
    case REAL_TYPE:
      switch (int_size_in_bytes (type))
	{
	case 4:
	  return    6          ;
	default:
	  return   7          ;
	}

    case ARRAY_TYPE:
      {
	int m;
	m = plain_type_1 (((type)->common.type) );
	if (sdb_n_dims < 4 )
	  sdb_dims[sdb_n_dims++]
	    = (((type)->type.values) 
	       ? ((((((type)->type.values) )->type.max) )->int_cst.int_cst_low)  + 1
	       : 0);
	return (((( m)&~    017 )<<    2 )|(     3          <<    4 )|( m&    017 )) ;
      }

    case RECORD_TYPE:
    case UNION_TYPE:
    case ENUMERAL_TYPE:
      {
	char *tag;





	if (((type)->common.asm_written_attr) 

	    && (char *)(((type)->type.symtab_address) ) 

	    )
	  {
	     



	    tag = (char *)(((type)->type.symtab_address) ) ;
	    do { fprintf (asm_out_file, "\t.tag\t");	fprintf (asm_out_file, "%s",  tag) ;	fprintf (asm_out_file, ";"); } while (0) ;
	  }
	sdb_type_size = int_size_in_bytes (type);
	if (sdb_type_size < 0)
	  sdb_type_size = 0;
	return ((((enum tree_code) (type)->common.code)  == RECORD_TYPE) ?   8          
		: (((enum tree_code) (type)->common.code)  == UNION_TYPE) ?    9          
		:     10         );
      }
    case POINTER_TYPE:
    case REFERENCE_TYPE:
      {
	int m = plain_type_1 (((type)->common.type) );
	return (((( m)&~    017 )<<    2 )|(     1          <<    4 )|( m&    017 )) ;
      }
    case FUNCTION_TYPE:
    case METHOD_TYPE:
      {
	int m = plain_type_1 (((type)->common.type) );
	return (((( m)&~    017 )<<    2 )|(     2          <<    4 )|( m&    017 )) ;
      }
    default:
      return 0;
    }
}

 





static int do_block = 0;

static int next_block_number;

static void
sdbout_block (stmt)
     register tree stmt;
{
  while (stmt)
    {
      switch (((enum tree_code) (stmt)->common.code) )
	{
	case COMPOUND_STMT:
	case LOOP_STMT:
	  sdbout_block (((stmt)->stmt.body) );
	  break;

	case IF_STMT:
	  sdbout_block (((stmt)->if_stmt.thenpart) );
	  sdbout_block (((stmt)->if_stmt.elsepart) );
	  break;

	case LET_STMT:
	   
	  if (! ((stmt)->common.used_attr) )
	    break;
	   
	  if (next_block_number == do_block)
	    {
	      sdbout_tags (((stmt)->bind_stmt.type_tags) );
	      sdbout_syms (((stmt)->bind_stmt.vars) );
	    }

	   
	  if (next_block_number > do_block)
	    return;

	  next_block_number++;

	   
	  sdbout_block (((stmt)->bind_stmt.subblocks) );
	}
      stmt = ((stmt)->common.chain) ;
    }
}

 

static void
sdbout_syms (syms)
     tree syms;
{
  while (syms)
    {
      sdbout_symbol (syms, 1);
      syms = ((syms)->common.chain) ;
    }
}

 


void
sdbout_symbol (decl, local)
     tree decl;
     int local;
{
  int letter = 0;
  tree type = ((decl)->common.type) ;
  rtx value;

   



  if (local == 0)
    {
      sdbout_tags (gettags ());
      sdbout_types (nreverse (get_permanent_types ()));
    }


  sdbout_one_type (type);


  switch (((enum tree_code) (decl)->common.code) )
    {
    case CONST_DECL:
       
      return;

    case FUNCTION_DECL:
      if (((decl)->common.external_attr) )
	return;
      if (	((((decl)->decl.rtl) )->code)  != MEM
	  || 	((((((decl)->decl.rtl) )->fld[ 0].rtx) )->code)  != SYMBOL_REF)
	return;
      do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((decl)->decl.name) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;
      ( fputs ("\t.val\t", asm_out_file),	output_addr_const (asm_out_file, (((((decl)->decl.rtl) )->fld[ 0].rtx) )),	fputc (';', asm_out_file)) ;
      fprintf(asm_out_file, "\t.scl\t%d;", (((decl)->common.public_attr)  ?           2      :          3     )) ;
      break;

    case TYPE_DECL:
       
      do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((decl)->decl.name) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;
      fprintf(asm_out_file, "\t.scl\t%d;", (        13    )) ;
      break;
      
    case PARM_DECL:
       

      abort ();

    case VAR_DECL:
       

      if (((decl)->common.external_attr) )
	return;

      value = ((decl)->decl.rtl) ;

       

      if (	((value)->code)  == REG
	  && (((value)->fld[0].rtint)  < 0
	      || ((value)->fld[0].rtint)  >= 10 ))
	return;

       
      do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((decl)->decl.name) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;

      if (	((value)->code)  == MEM
	  && 	((((value)->fld[ 0].rtx) )->code)  == SYMBOL_REF)
	{
	  if (((decl)->common.public_attr) )
	    {
	      ( fputs ("\t.val\t", asm_out_file),	output_addr_const (asm_out_file, (((value)->fld[ 0].rtx) )),	fputc (';', asm_out_file)) ;
              fprintf(asm_out_file, "\t.scl\t%d;", (          2     )) ;
	    }
	  else
	    {
	      ( fputs ("\t.val\t", asm_out_file),	output_addr_const (asm_out_file, (((value)->fld[ 0].rtx) )),	fputc (';', asm_out_file)) ;
              fprintf(asm_out_file, "\t.scl\t%d;", (         3     )) ;
	    }
	}
      else if (	((value)->code)  == REG)
	{
	  fprintf (asm_out_file, "\t.val\t%d;", (((((value)->fld[0].rtint) )==0?0 :(((value)->fld[0].rtint) )==1?2 :(((value)->fld[0].rtint) )==2?1 :(((value)->fld[0].rtint) )==3?3 :(((value)->fld[0].rtint) )==4?6 :(((value)->fld[0].rtint) )==5?7 :(((value)->fl
d[0].rtint) )==6?4 :(((value)->fld[0].rtint) )==7?5 :(((value)->fld[0].rtint) )==8?12 :(((value)->fld[0].rtint) )==9?12 :(((value)->fld[0].rtint) )) )) ;
	  fprintf(asm_out_file, "\t.scl\t%d;", (          4     )) ;
	}
      else if (	((value)->code)  == SUBREG)
	{
	  int offset = 0;
	  while (	((value)->code)  == SUBREG)
	    {
	      offset += ((value)->fld[1].rtint) ;
	      value = ((value)->fld[0].rtx) ;
	    }
	  fprintf (asm_out_file, "\t.val\t%d;", (((((value)->fld[0].rtint)  + offset)==0?0 :(((value)->fld[0].rtint)  + offset)==1?2 :(((value)->fld[0].rtint)  + offset)==2?1 :(((value)->fld[0].rtint)  + offset)==3?3 :(((value)->fld[0].rtint)  + offset)==4?6 :(
((value)->fld[0].rtint)  + offset)==5?7 :(((value)->fld[0].rtint)  + offset)==6?4 :(((value)->fld[0].rtint)  + offset)==7?5 :(((value)->fld[0].rtint)  + offset)==8?12 :(((value)->fld[0].rtint)  + offset)==9?12 :(((value)->fld[0].rtint)  + offset)) )) ;
	  fprintf(asm_out_file, "\t.scl\t%d;", (          4     )) ;
	}
      else if (	((value)->code)  == MEM
	       && (	((((value)->fld[ 0].rtx) )->code)  == MEM
		   || (	((((value)->fld[ 0].rtx) )->code)  == REG
		       && ((((value)->fld[ 0].rtx) )->fld[0].rtint)  != 6 )))
	 




	{
	  if (	((((value)->fld[ 0].rtx) )->code)  == REG)
	    {
	      fprintf (asm_out_file, "\t.val\t%d;", (((((((value)->fld[ 0].rtx) )->fld[0].rtint) )==0?0 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )==1?2 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )==2?1 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )==3?3 :(((
((value)->fld[ 0].rtx) )->fld[0].rtint) )==4?6 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )==5?7 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )==6?4 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )==7?5 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )==8?12 :(
((((value)->fld[ 0].rtx) )->fld[0].rtint) )==9?12 :(((((value)->fld[ 0].rtx) )->fld[0].rtint) )) )) ;
	      fprintf(asm_out_file, "\t.scl\t%d;", (          4     )) ;
	    }
	  else
	    {
	       


	       
	      fprintf (asm_out_file, "\t.val\t%d;", (((((((((value)->fld[ 0].rtx) )->fld[ 0].rtx) )->fld[ 1].rtx) )->fld[0].rtint) )) ;
	      fprintf(asm_out_file, "\t.scl\t%d;", (         1     )) ;
	    }

	  type = build_pointer_type (((decl)->common.type) );
	}
      else if (	((value)->code)  == MEM
	       && 	((((value)->fld[ 0].rtx) )->code)  == PLUS
	       && 	((((((value)->fld[ 0].rtx) )->fld[ 0].rtx) )->code)  == REG
	       && 	((((((value)->fld[ 0].rtx) )->fld[ 1].rtx) )->code)  == CONST_INT)
	{
	   

	  fprintf (asm_out_file, "\t.val\t%d;", (((((((value)->fld[ 0].rtx) )->fld[ 1].rtx) )->fld[0].rtint) )) ;
	  fprintf(asm_out_file, "\t.scl\t%d;", (         1     )) ;
	}
      else
	{
	   
	}
      break;
    }
  fprintf(asm_out_file, "\t.type\t0%o;", plain_type (type)) ;
  fputs("\t.endef\n", asm_out_file) ;
}

 




void
sdbout_tags (tags)
     tree tags;
{
  register tree link;

  for (link = tags; link; link = ((link)->common.chain) )
    {
      register tree type = ((link)->list.value) ;

      if (((link)->list.purpose)  != 0
	  && ((type)->type.size)  != 0)
	sdbout_one_type (type);
    }
}

 


void
sdbout_types (types)
     register tree types;
{
  register tree link;

  for (link = types; link; link = ((link)->common.chain) )
    sdbout_one_type (link);
}

static void
sdbout_type (type)
     tree type;
{
  register tree tem;
  if (type == error_mark_node)
    type = integer_type_node;
  fprintf(asm_out_file, "\t.type\t0%o;", plain_type (type)) ;
}

 




static void
sdbout_field_types (type)
     tree type;
{
  tree tail;
  for (tail = ((type)->type.values) ; tail; tail = ((tail)->common.chain) )
    {

      if (((enum tree_code) (((tail)->common.type) )->common.code)  == POINTER_TYPE)
	sdbout_one_type (((((tail)->common.type) )->common.type) );
      else

	sdbout_one_type (((tail)->common.type) );
    }
}

 






static void
sdbout_one_type (type)
     tree type;
{
  text_section ();

  switch (((enum tree_code) (type)->common.code) )
    {
    case RECORD_TYPE:
    case UNION_TYPE:
    case ENUMERAL_TYPE:
      type = ((type)->type.main_variant) ;
       
      if (((type)->common.asm_written_attr) )
	return;

       
      if (((type)->type.size)  == 0)
	return;

      ((type)->common.asm_written_attr)  = 1;

       
      if (((enum tree_code) (type)->common.code)  != ENUMERAL_TYPE)
	sdbout_field_types (type);


      sdbout_record_type_name (type);

       
      {
	int size = int_size_in_bytes (type);
	int member_scl;
	tree tem;

	do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  (char *)(((type)->type.symtab_address) ) ) ; fprintf (asm_out_file, ";"); } while (0) ;

	switch (((enum tree_code) (type)->common.code) )
	  {
	  case UNION_TYPE:
	    fprintf(asm_out_file, "\t.scl\t%d;", (        12    )) ;
	    fprintf(asm_out_file, "\t.type\t0%o;",    9          ) ;
	    member_scl =           11    ;
	    break;

	  case RECORD_TYPE:
	    fprintf(asm_out_file, "\t.scl\t%d;", (       10    )) ;
	    fprintf(asm_out_file, "\t.type\t0%o;",   8          ) ;
	    member_scl =           8     ;
	    break;

	  case ENUMERAL_TYPE:
	    fprintf(asm_out_file, "\t.scl\t%d;", (        15    )) ;
	    fprintf(asm_out_file, "\t.type\t0%o;",     10         ) ;
	    member_scl =           16    ;
	    break;
	  }

	fprintf(asm_out_file, "\t.size\t%d;", size) ;
	fputs("\t.endef\n", asm_out_file) ;

	 

	if (((enum tree_code) (type)->common.code)  == ENUMERAL_TYPE)
	  for (tem = ((type)->type.values) ; tem; tem = ((tem)->common.chain) )
	    {
	      do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((tem)->list.purpose) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;
	      fprintf (asm_out_file, "\t.val\t%d;", (((((tem)->list.value) )->int_cst.int_cst_low) )) ;
	      fprintf(asm_out_file, "\t.scl\t%d;", (          16    )) ;
	      fprintf(asm_out_file, "\t.type\t0%o;",      11         ) ;
	      fputs("\t.endef\n", asm_out_file) ;
	    }
      
	else			 
	  for (tem = ((type)->type.values) ; tem; tem = ((tem)->common.chain) )
	     

	     
	    if (((tem)->decl.name)  != 0)
	      {
		 ;
		do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((tem)->decl.name) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;
		if (((tem)->common.packed_attr) )
		  {
		    fprintf (asm_out_file, "\t.val\t%d;", (((tem)->decl.offset) )) ;
		    fprintf(asm_out_file, "\t.scl\t%d;", (        18    )) ;
		    sdbout_type (((tem)->common.type) );
		    fprintf(asm_out_file, "\t.size\t%d;", ((((tem)->decl.size) )->int_cst.int_cst_low) 
				  * ((tem)->decl.size_unit) ) ;
		  }
		else
		  {
		    fprintf (asm_out_file, "\t.val\t%d;", (((tem)->decl.offset)  / 8 )) ;
		    fprintf(asm_out_file, "\t.scl\t%d;", (member_scl)) ;
		    sdbout_type (((tem)->common.type) );
		  }
		fputs("\t.endef\n", asm_out_file) ;
	      }
	 
   
	fprintf(asm_out_file,"\t.def\t.%s;","eos") ;
	fprintf (asm_out_file, "\t.val\t%d;", (size)) ;
	fprintf(asm_out_file, "\t.scl\t%d;", (          102   )) ;
	do { fprintf (asm_out_file, "\t.tag\t");	fprintf (asm_out_file, "%s",  (char *)(((type)->type.symtab_address) ) ) ;	fprintf (asm_out_file, ";"); } while (0) ;
	fprintf(asm_out_file, "\t.size\t%d;", size) ;
	fputs("\t.endef\n", asm_out_file) ;
	break;
      }
    }
}

 




static void
sdbout_parms (parms1)
     tree parms1;
{
  tree type;
  tree parms;

  for (parms = parms1; parms; parms = ((parms)->common.chain) )
    {
      int current_sym_value = ((parms)->decl.offset)  / 8 ;

      if (((parms)->decl.name) )
	do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((parms)->decl.name) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;
      else
	do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  gen_fake_label ()) ; fprintf (asm_out_file, ";"); } while (0) ;

      if (	((((parms)->decl.rtl) )->code)  == REG
	  && ((((parms)->decl.rtl) )->fld[0].rtint)  >= 0
	  && ((((parms)->decl.rtl) )->fld[0].rtint)  < 10 )
	type = ((parms)->decl.arguments)   ;
      else
	{
	   











	  if (	((((parms)->decl.rtl) )->code)  == MEM
	      && 	((((((parms)->decl.rtl) )->fld[ 0].rtx) )->code)  == PLUS
	      && 	((((((((parms)->decl.rtl) )->fld[ 0].rtx) )->fld[ 1].rtx) )->code)  == CONST_INT
	      && (((((((((parms)->decl.rtl) )->fld[ 0].rtx) )->fld[ 1].rtx) )->fld[0].rtint) 
		  == current_sym_value))
	    type = ((parms)->common.type) ;
	  else
	    {
	      current_sym_value = ((parms)->decl.offset)  / 8 ;
	      type = ((parms)->decl.arguments)   ;
	    }
	}
     
      fprintf (asm_out_file, "\t.val\t%d;", (current_sym_value)) ;
      fprintf(asm_out_file, "\t.scl\t%d;", (          9     )) ;
      fprintf(asm_out_file, "\t.type\t0%o;", plain_type (type)) ;
      fputs("\t.endef\n", asm_out_file) ;
    }
}

 




static void
sdbout_reg_parms (parms)
     tree parms;
{
  while (parms)
    {
      if (	((((parms)->decl.rtl) )->code)  == REG
	  && ((((parms)->decl.rtl) )->fld[0].rtint)  >= 0
	  && ((((parms)->decl.rtl) )->fld[0].rtint)  < 10 )
	{
	  do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((parms)->decl.name) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;
	  fprintf (asm_out_file, "\t.val\t%d;", (((((((parms)->decl.rtl) )->fld[0].rtint) )==0?0 :(((((parms)->decl.rtl) )->fld[0].rtint) )==1?2 :(((((parms)->decl.rtl) )->fld[0].rtint) )==2?1 :(((((parms)->decl.rtl) )->fld[0].rtint) )==3?3 :(((((parms)->decl.r
tl) )->fld[0].rtint) )==4?6 :(((((parms)->decl.rtl) )->fld[0].rtint) )==5?7 :(((((parms)->decl.rtl) )->fld[0].rtint) )==6?4 :(((((parms)->decl.rtl) )->fld[0].rtint) )==7?5 :(((((parms)->decl.rtl) )->fld[0].rtint) )==8?12 :(((((parms)->decl.rtl) )->fld[0]
.rtint) )==9?12 :(((((parms)->decl.rtl) )->fld[0].rtint) )) )) ;
  	  fprintf(asm_out_file, "\t.scl\t%d;", (          4     )) ;
	  fprintf(asm_out_file, "\t.type\t0%o;", plain_type (((parms)->common.type) , 0)) ;
	  fputs("\t.endef\n", asm_out_file) ;
	}
      else if (	((((parms)->decl.rtl) )->code)  == MEM
	       && 	((((((parms)->decl.rtl) )->fld[ 0].rtx) )->code)  == PLUS
	       && 	((((((((parms)->decl.rtl) )->fld[ 0].rtx) )->fld[ 1].rtx) )->code)  == CONST_INT)
	{
	  int offset = ((parms)->decl.offset)  / 8 ;
	   







	  if (((((((((parms)->decl.rtl) )->fld[ 0].rtx) )->fld[ 1].rtx) )->fld[0].rtint)  != offset)
	    {
	      do { fprintf (asm_out_file, "\t.def\t");	fprintf (asm_out_file, "%s",  ((((parms)->decl.name) )->identifier.pointer) ) ; fprintf (asm_out_file, ";"); } while (0) ;	      
	      fprintf (asm_out_file, "\t.val\t%d;", (((((((((parms)->decl.rtl) )->fld[ 0].rtx) )->fld[ 1].rtx) )->fld[0].rtint) )) ;
	      fprintf(asm_out_file, "\t.scl\t%d;", (         1     )) ;
	      fprintf(asm_out_file, "\t.type\t0%o;", plain_type (((parms)->common.type) )) ;
	      fputs("\t.endef\n", asm_out_file) ;
	    }
	}
      parms = ((parms)->common.chain) ;
    }
}

 







void
sdbout_begin_block (file, line, n)
     FILE *file;
     int line;
     int n;
{
  tree decl = current_function_decl;
  if (line <= sdb_begin_function_line) line = sdb_begin_function_line + 1 ;
  fprintf (asm_out_file,	"\t.def\t.bb;\t.val\t.;\t.scl\t100;\t.line\t%d;\t.endef\n",	(line - sdb_begin_function_line)) ;
  if (n == 1)
    {
       
      next_block_number = 0;
      do_block = 0;
      sdbout_block (((decl)->decl.initial) );
    }
  next_block_number = 0;
  do_block = n;
  sdbout_block (((decl)->decl.initial) );
}

 
	 
void
sdbout_end_block (file, line)
     FILE *file;
     int line;
{
  if (line <= sdb_begin_function_line) line = sdb_begin_function_line + 1 ;
  fprintf (asm_out_file,	"\t.def\t.eb;.val\t.;\t.scl\t100;\t.line\t%d;\t.endef\n",	(line - sdb_begin_function_line)) ;
}

 


void
sdbout_mark_begin_function ()
{
  sdbout_symbol (current_function_decl, 0);
}

 





void
sdbout_begin_function (line)
     int line;
{
  sdb_begin_function_line = line - 1;
  fprintf (asm_out_file,	"\t.def\t.bf;\t.val\t.;\t.scl\t101;\t.line\t%d;\t.endef\n",	(line)) ;
  sdbout_parms (((current_function_decl)->decl.arguments)  );
  sdbout_reg_parms (((current_function_decl)->decl.arguments)  );
}

 


void
sdbout_end_function (line)
     int line;
{
  if (line <= sdb_begin_function_line) line = sdb_begin_function_line + 1 ;
  fprintf (asm_out_file,	"\t.def\t.ef;\t.val\t.;\t.scl\t101;\t.line\t%d;\t.endef\n",	(line - sdb_begin_function_line)) ;

   
  sdb_begin_function_line = -1;
}

 


void
sdbout_end_epilogue ()
{
  char *name = ((((current_function_decl)->decl.name) )->identifier.pointer) ;
  fprintf (asm_out_file,	"\t.def\t%s;\t.val\t.;\t.scl\t-1;\t.endef\n",	(name)) ;
}


