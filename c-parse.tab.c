/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 39 "/home/dave/tools/ctools/gca-1.40/c-parse.y"

#include "config.h"
#include "tree.h"
#include "input.h"
#include "c-parse.h"
#include "c-tree.h"
#include "flags.h"
/* #include "rtl.h" */
#define _RTL_H_
typedef int rtx;
typedef int rtvec;
#include "stmt.h"
#include "toplev.h"
#include "varasm.h"
#include "c-decl.h"
#include "emit-rtl.h"
#include "c-typeck.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void yyerror ();

/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1

#line 98 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    TYPENAME = 259,                /* TYPENAME  */
    SCSPEC = 260,                  /* SCSPEC  */
    TYPESPEC = 261,                /* TYPESPEC  */
    TYPE_QUAL = 262,               /* TYPE_QUAL  */
    CONSTANT = 263,                /* CONSTANT  */
    STRING = 264,                  /* STRING  */
    ELLIPSIS = 265,                /* ELLIPSIS  */
    SIZEOF = 266,                  /* SIZEOF  */
    ENUM = 267,                    /* ENUM  */
    STRUCT = 268,                  /* STRUCT  */
    UNION = 269,                   /* UNION  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    DO = 273,                      /* DO  */
    FOR = 274,                     /* FOR  */
    SWITCH = 275,                  /* SWITCH  */
    CASE = 276,                    /* CASE  */
    DEFAULT = 277,                 /* DEFAULT  */
    BREAK = 278,                   /* BREAK  */
    CONTINUE = 279,                /* CONTINUE  */
    RETURN = 280,                  /* RETURN  */
    GOTO = 281,                    /* GOTO  */
    ASM = 282,                     /* ASM  */
    TYPEOF = 283,                  /* TYPEOF  */
    ALIGNOF = 284,                 /* ALIGNOF  */
    ATTRIBUTE = 285,               /* ATTRIBUTE  */
    ASSIGN = 286,                  /* ASSIGN  */
    OROR = 287,                    /* OROR  */
    ANDAND = 288,                  /* ANDAND  */
    EQCOMPARE = 289,               /* EQCOMPARE  */
    ARITHCOMPARE = 290,            /* ARITHCOMPARE  */
    LSHIFT = 291,                  /* LSHIFT  */
    RSHIFT = 292,                  /* RSHIFT  */
    UNARY = 293,                   /* UNARY  */
    PLUSPLUS = 294,                /* PLUSPLUS  */
    MINUSMINUS = 295,              /* MINUSMINUS  */
    HYPERUNARY = 296,              /* HYPERUNARY  */
    POINTSAT = 297                 /* POINTSAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
long itype; tree ttype; enum tree_code code; 

#line 190 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPENAME = 4,                   /* TYPENAME  */
  YYSYMBOL_SCSPEC = 5,                     /* SCSPEC  */
  YYSYMBOL_TYPESPEC = 6,                   /* TYPESPEC  */
  YYSYMBOL_TYPE_QUAL = 7,                  /* TYPE_QUAL  */
  YYSYMBOL_CONSTANT = 8,                   /* CONSTANT  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_ELLIPSIS = 10,                  /* ELLIPSIS  */
  YYSYMBOL_SIZEOF = 11,                    /* SIZEOF  */
  YYSYMBOL_ENUM = 12,                      /* ENUM  */
  YYSYMBOL_STRUCT = 13,                    /* STRUCT  */
  YYSYMBOL_UNION = 14,                     /* UNION  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_SWITCH = 20,                    /* SWITCH  */
  YYSYMBOL_CASE = 21,                      /* CASE  */
  YYSYMBOL_DEFAULT = 22,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 23,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 24,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_GOTO = 26,                      /* GOTO  */
  YYSYMBOL_ASM = 27,                       /* ASM  */
  YYSYMBOL_TYPEOF = 28,                    /* TYPEOF  */
  YYSYMBOL_ALIGNOF = 29,                   /* ALIGNOF  */
  YYSYMBOL_ATTRIBUTE = 30,                 /* ATTRIBUTE  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_32_ = 32,                       /* '='  */
  YYSYMBOL_33_ = 33,                       /* '?'  */
  YYSYMBOL_34_ = 34,                       /* ':'  */
  YYSYMBOL_OROR = 35,                      /* OROR  */
  YYSYMBOL_ANDAND = 36,                    /* ANDAND  */
  YYSYMBOL_37_ = 37,                       /* '|'  */
  YYSYMBOL_38_ = 38,                       /* '^'  */
  YYSYMBOL_39_ = 39,                       /* '&'  */
  YYSYMBOL_EQCOMPARE = 40,                 /* EQCOMPARE  */
  YYSYMBOL_ARITHCOMPARE = 41,              /* ARITHCOMPARE  */
  YYSYMBOL_LSHIFT = 42,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 43,                    /* RSHIFT  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_48_ = 48,                       /* '%'  */
  YYSYMBOL_UNARY = 49,                     /* UNARY  */
  YYSYMBOL_PLUSPLUS = 50,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 51,                /* MINUSMINUS  */
  YYSYMBOL_HYPERUNARY = 52,                /* HYPERUNARY  */
  YYSYMBOL_POINTSAT = 53,                  /* POINTSAT  */
  YYSYMBOL_54_ = 54,                       /* '.'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* ';'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* '~'  */
  YYSYMBOL_61_ = 61,                       /* '!'  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* '{'  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_extdefs = 67,                   /* extdefs  */
  YYSYMBOL_68_1 = 68,                      /* @1  */
  YYSYMBOL_69_2 = 69,                      /* @2  */
  YYSYMBOL_extdef = 70,                    /* extdef  */
  YYSYMBOL_datadef = 71,                   /* datadef  */
  YYSYMBOL_fndef = 72,                     /* fndef  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_76_6 = 76,                      /* $@6  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_identifier = 79,                /* identifier  */
  YYSYMBOL_unop = 80,                      /* unop  */
  YYSYMBOL_expr = 81,                      /* expr  */
  YYSYMBOL_exprlist = 82,                  /* exprlist  */
  YYSYMBOL_nonnull_exprlist = 83,          /* nonnull_exprlist  */
  YYSYMBOL_unary_expr = 84,                /* unary_expr  */
  YYSYMBOL_cast_expr = 85,                 /* cast_expr  */
  YYSYMBOL_expr_no_commas = 86,            /* expr_no_commas  */
  YYSYMBOL_primary = 87,                   /* primary  */
  YYSYMBOL_88_9 = 88,                      /* @9  */
  YYSYMBOL_string = 89,                    /* string  */
  YYSYMBOL_xdecls = 90,                    /* xdecls  */
  YYSYMBOL_decls = 91,                     /* decls  */
  YYSYMBOL_setspecs = 92,                  /* setspecs  */
  YYSYMBOL_decl = 93,                      /* decl  */
  YYSYMBOL_typed_declspecs = 94,           /* typed_declspecs  */
  YYSYMBOL_reserved_declspecs = 95,        /* reserved_declspecs  */
  YYSYMBOL_declmods = 96,                  /* declmods  */
  YYSYMBOL_typed_typespecs = 97,           /* typed_typespecs  */
  YYSYMBOL_reserved_typespecquals = 98,    /* reserved_typespecquals  */
  YYSYMBOL_typespec = 99,                  /* typespec  */
  YYSYMBOL_typespecqual_reserved = 100,    /* typespecqual_reserved  */
  YYSYMBOL_initdecls = 101,                /* initdecls  */
  YYSYMBOL_notype_initdecls = 102,         /* notype_initdecls  */
  YYSYMBOL_maybeasm = 103,                 /* maybeasm  */
  YYSYMBOL_initdcl = 104,                  /* initdcl  */
  YYSYMBOL_105_10 = 105,                   /* @10  */
  YYSYMBOL_notype_initdcl = 106,           /* notype_initdcl  */
  YYSYMBOL_107_11 = 107,                   /* @11  */
  YYSYMBOL_maybe_attribute = 108,          /* maybe_attribute  */
  YYSYMBOL_attribute_list = 109,           /* attribute_list  */
  YYSYMBOL_attrib = 110,                   /* attrib  */
  YYSYMBOL_init = 111,                     /* init  */
  YYSYMBOL_initlist = 112,                 /* initlist  */
  YYSYMBOL_declarator = 113,               /* declarator  */
  YYSYMBOL_after_type_declarator = 114,    /* after_type_declarator  */
  YYSYMBOL_parm_declarator = 115,          /* parm_declarator  */
  YYSYMBOL_notype_declarator = 116,        /* notype_declarator  */
  YYSYMBOL_structsp = 117,                 /* structsp  */
  YYSYMBOL_118_12 = 118,                   /* @12  */
  YYSYMBOL_119_13 = 119,                   /* @13  */
  YYSYMBOL_120_14 = 120,                   /* @14  */
  YYSYMBOL_121_15 = 121,                   /* @15  */
  YYSYMBOL_maybecomma = 122,               /* maybecomma  */
  YYSYMBOL_maybecomma_warn = 123,          /* maybecomma_warn  */
  YYSYMBOL_component_decl_list = 124,      /* component_decl_list  */
  YYSYMBOL_component_decl_list2 = 125,     /* component_decl_list2  */
  YYSYMBOL_component_decl = 126,           /* component_decl  */
  YYSYMBOL_components = 127,               /* components  */
  YYSYMBOL_component_declarator = 128,     /* component_declarator  */
  YYSYMBOL_enumlist = 129,                 /* enumlist  */
  YYSYMBOL_enumerator = 130,               /* enumerator  */
  YYSYMBOL_typename = 131,                 /* typename  */
  YYSYMBOL_absdcl = 132,                   /* absdcl  */
  YYSYMBOL_nonempty_type_quals = 133,      /* nonempty_type_quals  */
  YYSYMBOL_type_quals = 134,               /* type_quals  */
  YYSYMBOL_absdcl1 = 135,                  /* absdcl1  */
  YYSYMBOL_stmts = 136,                    /* stmts  */
  YYSYMBOL_xstmts = 137,                   /* xstmts  */
  YYSYMBOL_errstmt = 138,                  /* errstmt  */
  YYSYMBOL_pushlevel = 139,                /* pushlevel  */
  YYSYMBOL_compstmt_or_error = 140,        /* compstmt_or_error  */
  YYSYMBOL_compstmt = 141,                 /* compstmt  */
  YYSYMBOL_simple_if = 142,                /* simple_if  */
  YYSYMBOL_143_16 = 143,                   /* $@16  */
  YYSYMBOL_stmt = 144,                     /* stmt  */
  YYSYMBOL_145_17 = 145,                   /* $@17  */
  YYSYMBOL_146_18 = 146,                   /* $@18  */
  YYSYMBOL_147_19 = 147,                   /* $@19  */
  YYSYMBOL_148_20 = 148,                   /* $@20  */
  YYSYMBOL_149_21 = 149,                   /* $@21  */
  YYSYMBOL_150_22 = 150,                   /* $@22  */
  YYSYMBOL_151_23 = 151,                   /* $@23  */
  YYSYMBOL_152_24 = 152,                   /* $@24  */
  YYSYMBOL_153_25 = 153,                   /* $@25  */
  YYSYMBOL_154_26 = 154,                   /* $@26  */
  YYSYMBOL_155_27 = 155,                   /* $@27  */
  YYSYMBOL_156_28 = 156,                   /* $@28  */
  YYSYMBOL_maybe_type_qual = 157,          /* maybe_type_qual  */
  YYSYMBOL_xexpr = 158,                    /* xexpr  */
  YYSYMBOL_asm_operands = 159,             /* asm_operands  */
  YYSYMBOL_nonnull_asm_operands = 160,     /* nonnull_asm_operands  */
  YYSYMBOL_asm_operand = 161,              /* asm_operand  */
  YYSYMBOL_asm_clobbers = 162,             /* asm_clobbers  */
  YYSYMBOL_parmlist = 163,                 /* parmlist  */
  YYSYMBOL_164_29 = 164,                   /* $@29  */
  YYSYMBOL_parmlist_or_identifiers = 165,  /* parmlist_or_identifiers  */
  YYSYMBOL_166_30 = 166,                   /* $@30  */
  YYSYMBOL_parmlist_or_identifiers_1 = 167, /* parmlist_or_identifiers_1  */
  YYSYMBOL_parmlist_1 = 168,               /* parmlist_1  */
  YYSYMBOL_parmlist_2 = 169,               /* parmlist_2  */
  YYSYMBOL_parms = 170,                    /* parms  */
  YYSYMBOL_parm = 171,                     /* parm  */
  YYSYMBOL_identifiers = 172               /* identifiers  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 161 "/home/dave/tools/ctools/gca-1.40/c-parse.y"

/* the declaration found for the last IDENTIFIER token read in.
   yylex must look this up to detect typedefs, which get token type TYPENAME,
   so it is left around in case the identifier is not a typedef but is
   used in a context which makes it a reference to a variable.  */
static tree lastiddecl;

static tree make_pointer_declarator ();
static tree combine_strings ();
static void reinit_parse_for_function ();

/* List of types and structure classes of the current declaration.  */
tree current_declspecs;

/* Stack of saved values of current_declspecs.  */
tree declspec_stack;

int undeclared_variable_notice;	/* 1 if we explained undeclared var errors.  */

static int yylex ();

#line 410 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1556

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  296
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  515

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    48,    39,     2,
      55,    57,    46,    44,    62,    45,    54,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    58,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    64,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    37,    59,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    35,    36,    40,
      41,    42,    43,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   184,   184,   185,   193,   193,   194,   194,   198,   199,
     200,   208,   213,   215,   217,   219,   221,   222,   223,   230,
     234,   229,   237,   240,   244,   239,   247,   250,   254,   249,
     257,   262,   263,   266,   268,   270,   272,   274,   276,   278,
     282,   288,   289,   293,   295,   300,   301,   303,   305,   318,
     320,   353,   358,   359,   362,   377,   378,   380,   382,   384,
     386,   388,   390,   392,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   415,   463,   464,   466,   468,   471,   470,
     490,   492,   494,   496,   498,   500,   506,   507,   511,   513,
     517,   518,   519,   520,   528,   535,   539,   543,   545,   554,
     556,   561,   562,   564,   573,   575,   577,   579,   589,   591,
     596,   597,   605,   606,   607,   608,   612,   620,   621,   622,
     626,   627,   631,   632,   637,   638,   648,   647,   652,   659,
     658,   663,   671,   672,   677,   678,   682,   686,   694,   701,
     702,   706,   708,   710,   717,   719,   727,   728,   734,   736,
     741,   743,   745,   747,   756,   761,   763,   765,   767,   774,
     779,   781,   783,   785,   787,   792,   791,   799,   802,   805,
     804,   808,   811,   814,   813,   820,   819,   825,   829,   831,
     834,   836,   841,   843,   849,   850,   852,   867,   872,   877,
     883,   886,   887,   892,   894,   896,   906,   907,   913,   915,
     920,   922,   928,   929,   933,   935,   941,   942,   947,   950,
     952,   954,   956,   958,   960,   962,   964,   973,   974,   975,
     978,   980,   983,   987,   996,   998,  1001,  1003,  1007,  1011,
    1019,  1018,  1025,  1026,  1037,  1036,  1040,  1043,  1047,  1042,
    1052,  1056,  1051,  1064,  1069,  1075,  1062,  1085,  1084,  1094,
    1093,  1126,  1125,  1136,  1140,  1144,  1147,  1150,  1155,  1162,
    1169,  1176,  1183,  1182,  1188,  1195,  1198,  1206,  1207,  1213,
    1214,  1218,  1219,  1224,  1229,  1231,  1238,  1238,  1249,  1249,
    1258,  1259,  1261,  1266,  1267,  1274,  1275,  1277,  1282,  1284,
    1291,  1293,  1295,  1297,  1299,  1305,  1307
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPENAME", "SCSPEC", "TYPESPEC", "TYPE_QUAL", "CONSTANT", "STRING",
  "ELLIPSIS", "SIZEOF", "ENUM", "STRUCT", "UNION", "IF", "ELSE", "WHILE",
  "DO", "FOR", "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN",
  "GOTO", "ASM", "TYPEOF", "ALIGNOF", "ATTRIBUTE", "ASSIGN", "'='", "'?'",
  "':'", "OROR", "ANDAND", "'|'", "'^'", "'&'", "EQCOMPARE",
  "ARITHCOMPARE", "LSHIFT", "RSHIFT", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UNARY", "PLUSPLUS", "MINUSMINUS", "HYPERUNARY", "POINTSAT", "'.'",
  "'('", "'['", "')'", "';'", "'}'", "'~'", "'!'", "','", "'{'", "']'",
  "$accept", "program", "extdefs", "@1", "@2", "extdef", "datadef",
  "fndef", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "identifier", "unop",
  "expr", "exprlist", "nonnull_exprlist", "unary_expr", "cast_expr",
  "expr_no_commas", "primary", "@9", "string", "xdecls", "decls",
  "setspecs", "decl", "typed_declspecs", "reserved_declspecs", "declmods",
  "typed_typespecs", "reserved_typespecquals", "typespec",
  "typespecqual_reserved", "initdecls", "notype_initdecls", "maybeasm",
  "initdcl", "@10", "notype_initdcl", "@11", "maybe_attribute",
  "attribute_list", "attrib", "init", "initlist", "declarator",
  "after_type_declarator", "parm_declarator", "notype_declarator",
  "structsp", "@12", "@13", "@14", "@15", "maybecomma", "maybecomma_warn",
  "component_decl_list", "component_decl_list2", "component_decl",
  "components", "component_declarator", "enumlist", "enumerator",
  "typename", "absdcl", "nonempty_type_quals", "type_quals", "absdcl1",
  "stmts", "xstmts", "errstmt", "pushlevel", "compstmt_or_error",
  "compstmt", "simple_if", "$@16", "stmt", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "maybe_type_qual", "xexpr", "asm_operands", "nonnull_asm_operands",
  "asm_operand", "asm_clobbers", "parmlist", "$@29",
  "parmlist_or_identifiers", "$@30", "parmlist_or_identifiers_1",
  "parmlist_1", "parmlist_2", "parms", "parm", "identifiers", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-377)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-286)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      61,    73,    85,  1390,  -377,  1390,    -6,  -377,  -377,  -377,
    -377,    47,    54,    63,    56,    80,  -377,  -377,  -377,  -377,
     113,    83,   271,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,    95,  -377,    97,  -377,   157,   220,  1243,  -377,  -377,
     113,    41,  -377,   259,  -377,   177,  -377,  -377,  -377,   113,
    -377,   865,   145,  -377,   179,   365,  -377,   189,  -377,  -377,
      74,  -377,  -377,  -377,  1310,  1323,  -377,  -377,  -377,  1377,
    -377,  -377,   402,  -377,  -377,  1377,   193,   174,  -377,  -377,
    1446,   467,   258,   107,  -377,   212,  1401,    35,   224,  -377,
     177,  -377,   219,  -377,   898,   291,   288,  -377,  -377,   177,
     117,  -377,    42,   136,   171,   195,   731,   865,  -377,  -377,
    -377,  -377,  -377,   256,   239,  -377,   145,  -377,  -377,  -377,
    -377,   265,   633,  -377,  -377,  -377,  -377,   281,   402,  -377,
     402,  -377,  -377,   294,   296,   280,   298,  -377,  -377,  1377,
    1377,  1377,  1377,  1377,  1377,  1377,  1377,  1377,  1377,  1377,
    1377,  1377,  1377,  1377,  1377,  1377,  1377,  -377,  -377,   145,
     145,  1377,  1377,  -377,   107,   921,  -377,   200,   426,  -377,
    -377,  -377,  -377,  -377,   171,  -377,  -377,   330,   220,  -377,
     699,  -377,   252,   301,  -377,   637,   487,   303,   376,  -377,
     307,   333,   215,   253,  -377,   177,  -377,   291,   288,  -377,
     966,  -377,  -377,   291,  1377,   145,   311,   239,   182,  -377,
     182,   314,   315,  -377,   318,   327,  -377,  -377,   326,   329,
    1182,  1446,  1446,  1446,  -377,   353,  1475,  1487,  1498,  1508,
    1014,  1023,   439,   199,   199,   279,   279,  -377,  -377,  -377,
    -377,  -377,   334,   174,   331,   286,   278,  -377,   839,  -377,
     332,  -377,   989,  -377,   426,    75,   337,  -377,    88,   415,
    -377,   340,   336,  -377,    76,  -377,  -377,    38,  -377,  -377,
    -377,   177,  -377,   113,   346,  -377,   136,  -377,  -377,  -377,
     370,  -377,  -377,   348,  -377,  1446,  -377,  -377,   358,  1377,
     228,   363,  -377,   363,  -377,  -377,  -377,  -377,  -377,   548,
    -377,   853,  -377,  1377,  -377,  -377,   200,  -377,   378,  -377,
     379,  -377,  -377,  -377,   381,  -377,  -377,  -377,  -377,    99,
     282,   171,  -377,  -377,   171,  -377,  -377,   576,  -377,   447,
     280,  -377,  -377,   232,   244,   101,   448,   853,    38,  -377,
    -377,    38,  -377,  1446,  1377,  -377,   182,   289,   408,   420,
     401,  -377,  -377,   403,   404,  1377,   430,   410,   411,  1256,
     145,   459,  -377,   438,   416,  1096,   609,  -377,   457,  -377,
    -377,   746,  1446,  -377,   417,  1462,  -377,  -377,  -377,   473,
    -377,  1034,    91,  -377,  -377,  -377,  -377,  -377,  -377,   434,
     104,  -377,  -377,  -377,   853,  -377,  1428,  -377,  -377,  1377,
     442,  1157,  1377,  1377,   490,  -377,  -377,  -377,  -377,   469,
     472,  -377,   470,  -377,  -377,   670,   475,  -377,  -377,  -377,
    -377,  -377,     1,   769,   476,   282,  -377,  -377,   477,   161,
     479,   448,  -377,  -377,   482,  1377,   523,   485,   501,  -377,
    1157,  -377,  -377,   220,  1157,  -377,  1157,  -377,   830,  -377,
    -377,  -377,   507,   110,  -377,  -377,  -377,   521,  -377,  -377,
    -377,  1157,  -377,    31,  -377,  -377,  -377,  -377,  -377,  1157,
    -377,   489,  1377,  1157,  -377,   570,   526,  -377,  1157,  1377,
     527,  -377,   536,     7,   533,  -377,  -377,  -377,   539,  -377,
    1377,   570,   542,   570,   543,  1377,   540,    79,  -377,  -377,
    -377,   545,  -377,   220,   547,  -377,   258,   120,  -377,  1157,
     549,   220,  -377,  -377,   258
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     0,     6,     0,     1,     0,     0,   114,   105,   112,
     104,     0,     0,     0,     0,     0,    18,     5,     9,     8,
       0,    94,    94,   101,   113,     7,    16,    17,    31,    32,
     175,   177,   184,   168,   184,   172,     0,     0,   164,   206,
       0,     0,   122,     0,    15,     0,   107,   106,    14,     0,
     101,    99,     0,   173,     0,     0,   165,     0,   169,    86,
       0,    73,   204,    74,     0,     0,    33,    35,    34,     0,
      36,    37,     0,    38,    39,     0,     0,    40,    52,    55,
      43,    45,    75,   202,   110,     0,   202,     0,     0,    11,
       0,    30,     0,   278,     0,     0,   132,   153,   206,     0,
       0,   120,     0,   146,   147,     0,     0,   100,   103,   117,
     118,   102,   119,   198,   180,   196,     0,   167,   189,   186,
      94,   183,    94,   184,   171,   184,    87,     0,     0,    48,
       0,    50,    46,     0,     0,     0,     0,    47,   115,     0,
       0,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,    41,     0,   206,   276,     0,   200,   203,   108,   116,
     205,   110,   201,   207,   161,   160,   123,   124,     0,   159,
       0,   163,     0,     0,    28,    89,     0,    94,    94,    91,
       0,   131,     0,     0,    13,     0,    22,     0,   132,   278,
       0,    12,    26,     0,     0,   181,     0,   180,   190,   185,
     190,     0,     0,    10,     0,     0,    77,    76,   223,     0,
       0,    44,    72,    71,   268,     0,    69,    68,    66,    67,
      65,    64,    63,    61,    62,    56,    57,    58,    59,    60,
      83,    82,     0,    42,     0,   210,     0,   214,     0,   216,
       0,   276,     0,   111,   109,     0,     0,   295,   202,   202,
     279,     0,   286,   288,     0,   162,   222,     0,    92,    93,
      97,     0,    98,     0,     0,   129,   152,   148,   121,    20,
     128,   149,   151,     0,    24,   199,   197,   176,     0,     0,
     132,   187,   191,   188,   166,   170,    49,    51,   226,     0,
      79,     0,    53,     0,    80,    81,   209,   208,     0,   277,
       0,   215,   211,   213,     0,   125,   282,   158,   206,   276,
     290,   291,   292,   206,   293,   294,   280,     0,   281,     0,
       0,    29,   224,     0,     0,   124,     0,     0,     0,   126,
     150,     0,   174,   195,     0,   193,     0,     0,    73,   114,
       0,   237,   240,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   264,     0,     0,   220,     0,   232,   236,   217,
     143,     0,   139,   144,   178,    70,   284,   283,   212,   210,
     278,     0,   210,   287,   289,   296,   225,    95,    96,   136,
       0,   134,   130,    21,     0,    25,   132,   192,   228,     0,
       0,     0,   267,     0,     0,   251,   253,   254,   255,     0,
       0,   266,     0,   262,   233,     0,     0,   229,   219,   218,
     234,   140,     0,     0,     0,   157,   154,   156,     0,     0,
       0,     0,   127,   194,     0,     0,     0,     0,     0,   249,
       0,   256,   261,     0,     0,   227,     0,   141,     0,   145,
      54,   155,     0,     0,   133,   135,   230,     0,   241,   243,
     247,     0,   252,     0,   263,   235,   142,   137,   138,     0,
     238,     0,   267,     0,   250,   269,     0,   231,     0,     0,
       0,   248,     0,     0,   270,   271,   257,   239,     0,   244,
       0,   269,     0,     0,     0,   267,     0,     0,   258,   272,
     242,     0,   273,     0,     0,   245,   274,     0,   259,     0,
       0,     0,   246,   260,   275
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -377,  -377,  -377,  -377,  -377,   610,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,    -8,  -377,   -35,  -377,   453,   285,
     -50,    55,  -377,  -377,   -36,  -126,   317,     2,  -150,     3,
     569,     4,   566,   451,   -10,  -140,   352,   -32,   -68,   -70,
    -377,  -377,  -377,  -184,  -377,   194,  -308,   287,   -34,   -63,
     273,   -19,   -29,  -377,  -377,  -377,  -377,  -377,   449,    -2,
    -377,  -377,   452,   320,   541,   458,   -41,   -71,   620,   -88,
    -148,   312,  -377,  -173,  -377,  -259,  -117,  -377,  -377,  -133,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -376,   185,  -377,   187,  -377,   431,  -377,
    -166,  -377,  -377,  -377,   435,  -377,   357,   257
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     3,     5,    17,    18,    19,   197,   338,
     203,   341,    95,   267,   363,    75,   364,   242,    77,    78,
      79,    80,    81,   135,    82,   184,   185,    20,   186,   187,
      51,   188,    83,   168,    23,   111,   100,    41,    96,   101,
     394,    42,   337,   191,   390,   391,   373,   374,   177,   103,
     320,   104,    24,   123,   125,   116,    52,   424,   206,    54,
      55,   121,   291,   292,   114,   115,    85,   166,    86,    87,
     167,   366,   416,   189,   299,   331,   367,   368,   469,   369,
     446,   400,   478,   401,   471,   472,   495,   509,   473,   461,
     440,   444,   412,   225,   483,   484,   485,   507,   247,   248,
     179,   180,   260,   309,   261,   262,   263,   264
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    43,    76,    31,    33,    35,    21,    22,    21,    22,
     192,   102,    50,   269,   280,   172,   246,   105,   219,   132,
     176,    88,   112,    45,    49,   137,   437,    84,   253,   392,
     106,   136,    57,   281,   198,   268,   193,   134,    38,   330,
     126,   491,   173,   196,   113,    84,   -19,   -19,   -19,   -19,
      28,    29,    26,    27,   -19,   -19,   -19,    28,    29,   182,
     447,    -2,    84,   448,   492,   475,    28,    29,   174,    92,
     -19,   279,  -124,     4,  -124,   245,   171,   284,   112,   393,
      88,    39,   395,   126,   126,    -3,   432,   214,   476,   215,
      40,    38,   317,   134,    38,   134,   480,   306,   173,    89,
    -124,   218,    38,    90,  -124,   -19,   345,   224,   113,   198,
      30,    36,   171,   503,   253,   449,    38,    32,    84,   501,
      84,   211,   208,   212,   210,   278,    34,   244,    92,   276,
     250,   127,   315,   328,   318,    37,   504,   323,   329,   112,
     449,    44,   255,   319,   165,   323,   319,   165,    28,    29,
     332,   240,   241,   163,   319,   165,    93,    94,    53,    39,
      56,   430,   164,   165,   257,   283,   431,   468,    40,   452,
     302,   246,   329,   174,   290,   194,   290,   510,    50,   195,
      38,    97,   511,   258,   259,    38,    97,   322,   325,   271,
     273,   199,   200,   418,   221,   222,   223,   113,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   433,   386,   426,   268,   289,   314,    38,    97,
      58,   332,   173,    98,   332,   112,    93,    94,    98,    59,
     379,   306,    99,   419,   306,   382,   139,    99,   117,   321,
     324,   334,   418,   152,   153,   154,   155,   156,   124,    50,
     138,   258,   259,   201,   335,   251,   252,    90,   190,   285,
      91,    98,   344,   -27,   -27,   -27,   -27,   126,   436,   169,
      99,   -27,   -27,   -27,   178,     7,    46,     9,    47,    93,
      94,   175,   419,    11,    12,    13,    92,   -27,   204,  -124,
     387,  -124,   183,   173,   195,     7,     8,     9,    10,    15,
      88,   205,   388,    11,    12,    13,    90,   462,   199,   200,
     277,   464,   290,   465,    93,    94,   265,  -124,   190,    15,
     404,  -124,   -27,   209,   409,   154,   155,   156,   474,    48,
     258,   259,   163,   251,   252,   307,   477,   380,   381,   213,
     481,   164,   165,   218,   343,   487,   428,   266,   398,   129,
     131,   216,   410,   217,   -88,   220,   372,    92,   375,   266,
     174,   270,   274,   174,   434,   275,   118,   224,   438,     7,
     287,     9,    62,   294,   295,   296,   512,    11,    12,    13,
       7,    46,     9,    47,   297,   298,   300,   303,    11,    12,
      13,   304,   372,    15,   316,   305,   311,   326,   327,   396,
     457,   336,   339,   133,    15,    61,     7,   463,     9,    62,
      63,    59,   340,    64,    11,    12,    13,   342,    38,     7,
      46,     9,    47,   119,  -182,   346,   372,    11,    12,    13,
      15,    65,   109,   110,   272,   376,   377,   224,    11,    12,
      13,    66,   -31,    15,   488,   378,    67,    68,    69,   372,
     385,   389,    70,    71,   -32,   496,   399,    72,   402,   403,
     224,   323,    73,    74,   405,   -78,   411,   506,   406,   407,
     319,   165,   413,   420,   414,   514,    38,   317,   372,   423,
     173,   150,   151,   152,   153,   154,   155,   156,   183,   429,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   435,   -90,   -90,
     -90,   -90,   -90,   372,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   157,   158,   318,
     159,   160,   161,   162,   439,   443,   -90,   441,   319,   165,
     442,   -90,   -90,   -90,   445,   450,   454,   -90,   -90,   456,
     458,   451,   -90,   459,   479,   -90,   -90,   -90,   -90,   347,
     -90,   348,   349,     8,     9,    10,    63,    59,   460,    64,
      11,    12,    13,   350,   467,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,    15,    65,   470,   482,
       7,     8,     9,    10,   486,   489,   383,    66,    11,    12,
      13,   490,    67,    68,    69,   493,   494,   502,    70,    71,
     498,   500,   505,    72,    15,   508,   362,   513,    73,    74,
     183,   218,   348,    29,   243,    25,   365,    63,    59,   107,
      64,   120,   254,   333,   350,   455,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,     7,    65,     9,
     170,     7,     8,     9,    10,    11,    12,    13,    66,    11,
      12,    13,   425,    67,    68,    69,   288,   207,   422,    70,
      71,    15,   293,   286,    72,    15,   397,   362,   417,    73,
      74,   183,   218,   348,    29,   122,   497,   415,    63,    59,
     499,    64,   312,   310,   384,   350,   453,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,     0,    65,
     256,     0,   257,     7,     8,     9,    10,     0,     0,    66,
       0,    11,    12,    13,    67,    68,    69,     0,     0,     0,
      70,    71,     0,     0,     0,    72,     0,    15,   362,  -221,
      73,    74,   202,   218,     0,   -23,   -23,   -23,   -23,     0,
       0,     0,     0,   -23,   -23,   -23,     0,   370,     0,    61,
       0,     0,     0,     0,    63,    59,  -285,    64,    92,   -23,
       0,  -124,     0,  -124,     0,     0,     0,     0,     0,     0,
     370,     0,    61,     0,     0,    65,     0,    63,    59,     0,
      64,     0,     0,     0,     0,    66,    93,    94,     0,  -124,
      67,    68,    69,  -124,   -23,     0,    70,    71,    65,     0,
       0,    72,     0,     0,     0,   421,    73,    74,    66,   371,
       0,     0,     0,    67,    68,    69,     0,     0,     0,    70,
      71,     0,     0,     0,    72,     0,     0,     0,  -179,    73,
      74,   370,   371,    61,     0,     0,     0,     0,    63,    59,
     308,    64,     0,     7,     8,     9,    10,     0,     0,     0,
       0,    11,    12,    13,   370,     0,    61,     0,     0,    65,
       0,    63,    59,     0,    64,     0,     0,    15,     0,    66,
     108,   109,   110,     0,    67,    68,    69,    11,    12,    13,
      70,    71,    65,     0,     0,    72,     0,     0,     0,   466,
      73,    74,    66,   371,     0,     0,  -285,    67,    68,    69,
       0,    61,     0,    70,    71,     0,    63,    59,    72,    64,
       0,     0,     0,    73,    74,     0,   371,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    65,     0,    63,
      59,     0,    64,     0,     0,     0,     0,    66,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,    70,    71,
      65,     0,     0,    72,     0,     0,     0,     0,    73,    74,
      66,     0,   181,     0,     0,    67,    68,    69,     0,    61,
       0,    70,    71,     0,    63,    59,    72,    64,     0,     0,
       0,    73,    74,     0,     0,   249,     0,     0,     0,     0,
       0,     0,    61,     0,     0,    65,     0,    63,    59,     0,
      64,     0,     0,     0,     0,    66,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,    70,    71,    65,     0,
       0,    72,     0,     0,     0,     0,    73,    74,    66,     0,
     282,     0,     0,    67,    68,    69,     0,    61,     0,    70,
      71,     0,    63,    59,    72,    64,     0,     0,     0,    73,
      74,     0,     0,   313,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    65,   149,   150,   151,   152,   153,   154,
     155,   156,     0,    66,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,    70,    71,     0,     0,     0,    72,
       0,     0,     0,     0,    73,    74,     0,     0,   427,   348,
     349,     8,     9,    10,    63,    59,     0,    64,    11,    12,
      13,   350,     0,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,    15,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,    70,    71,     0,     0,
       0,    72,     0,     0,   362,     0,    73,    74,     0,   218,
     348,    29,     0,     0,     0,    63,    59,     0,    64,     0,
       0,     0,   350,     0,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,    61,    65,     0,     0,     0,
      63,    59,     0,    64,     0,     0,    66,     0,     0,     0,
       0,    67,    68,    69,     0,     0,     0,    70,    71,     0,
       0,    65,    72,     0,     0,   362,     0,    73,    74,     0,
     218,    66,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,    70,    71,     0,     0,     0,    72,     0,     0,
       0,     0,    73,    74,     0,   301,    61,     7,     0,     9,
      62,    63,    59,     0,    64,    11,    12,    13,     0,    61,
       0,     0,     0,     0,    63,    59,     0,    64,     0,     0,
       0,    15,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,     0,    65,     0,    67,    68,    69,
       0,     0,     0,    70,    71,    66,     0,     0,    72,     0,
      67,    68,    69,    73,    74,     0,    70,    71,     0,     0,
       0,    72,     0,    61,   408,     0,    73,    74,    63,    59,
       0,    64,     0,     0,     0,     0,    61,     0,     0,     0,
       0,    63,    59,     0,    64,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,     0,    65,     0,    67,    68,    69,     0,     0,     0,
      70,    71,    66,     0,     0,   128,     0,    67,    68,    69,
      73,    74,     0,    70,    71,     0,     0,     0,   130,     0,
      61,     0,     0,    73,    74,    63,    59,     0,    64,     0,
       0,     6,     0,   -94,     7,     8,     9,    10,     0,     0,
       0,     0,    11,    12,    13,     7,    65,     9,   170,     0,
       0,     0,     0,    11,    12,    13,    66,    14,    15,     0,
       0,    67,    68,    69,     0,     0,     0,    70,    71,    15,
       0,     0,    72,     0,     0,     0,   -94,    73,    74,     0,
       0,     0,     0,     0,     0,   -94,     0,   163,    16,     0,
       0,     0,     0,     0,     0,     0,   164,   165,   190,   140,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   140,   141,   142,
       0,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   142,     0,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156
};

static const yytype_int16 yycheck[] =
{
      36,    20,    37,    11,    12,    13,     3,     3,     5,     5,
      98,    45,    22,   186,   198,    86,   164,    49,   135,    69,
      90,    40,    51,    21,    22,    75,   402,    37,   168,   337,
      49,    72,    34,   199,   102,   185,    99,    72,     3,     1,
       9,    34,     7,     1,    52,    55,     4,     5,     6,     7,
       3,     4,    58,    59,    12,    13,    14,     3,     4,    94,
      59,     0,    72,    62,    57,    34,     3,     4,    87,    27,
      28,   197,    30,     0,    32,   163,    86,   203,   107,   338,
      99,    46,   341,     9,     9,     0,   394,   128,    57,   130,
      55,     3,     4,   128,     3,   130,   472,   245,     7,    58,
      58,    63,     3,    62,    62,    63,   290,   142,   116,   177,
      63,    55,   122,    34,   254,   423,     3,    63,   128,   495,
     130,   123,   120,   125,   122,   195,    63,   162,    27,   192,
     165,    57,    57,    57,    46,    55,    57,    46,    62,   168,
     448,    58,   178,    55,    56,    46,    55,    56,     3,     4,
     267,   159,   160,    46,    55,    56,    55,    56,    63,    46,
      63,    57,    55,    56,     3,   200,    62,    57,    55,     8,
     220,   319,    62,   192,   208,    58,   210,    57,   188,    62,
       3,     4,    62,   180,   180,     3,     4,   258,   259,   187,
     188,    55,    56,   366,   139,   140,   141,   205,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   396,   330,   380,   365,    34,   252,     3,     4,
      63,   338,     7,    46,   341,   254,    55,    56,    46,     9,
     318,   379,    55,   366,   382,   323,    62,    55,    59,   258,
     259,   273,   415,    44,    45,    46,    47,    48,    59,   259,
      57,   248,   248,    58,   273,    55,    56,    62,    30,   204,
       1,    46,    34,     4,     5,     6,     7,     9,   401,    57,
      55,    12,    13,    14,    55,     4,     5,     6,     7,    55,
      56,    57,   415,    12,    13,    14,    27,    28,    32,    30,
      58,    32,     1,     7,    62,     4,     5,     6,     7,    28,
     319,    62,    58,    12,    13,    14,    62,   440,    55,    56,
      57,   444,   346,   446,    55,    56,    64,    58,    30,    28,
     355,    62,    63,    58,   359,    46,    47,    48,   461,    58,
     327,   327,    46,    55,    56,    57,   469,    55,    56,    58,
     473,    55,    56,    63,   289,   478,   381,    58,    59,    64,
      65,    57,   360,    57,    63,    57,   301,    27,   303,    58,
     379,    58,    55,   382,   399,    32,     1,   402,   403,     4,
      59,     6,     7,    59,    59,    57,   509,    12,    13,    14,
       4,     5,     6,     7,    57,    59,    57,    34,    12,    13,
      14,    57,   337,    28,    57,    64,    64,    57,    62,   344,
     435,    55,    32,     1,    28,     3,     4,   443,     6,     7,
       8,     9,    64,    11,    12,    13,    14,    59,     3,     4,
       5,     6,     7,    58,    59,    62,   371,    12,    13,    14,
      28,    29,     6,     7,    58,    57,    57,   472,    12,    13,
      14,    39,    34,    28,   479,    64,    44,    45,    46,   394,
       3,     3,    50,    51,    34,   490,    55,    55,    55,    55,
     495,    46,    60,    61,    34,    63,     7,   503,    58,    58,
      55,    56,    34,    16,    58,   511,     3,     4,   423,    62,
       7,    42,    43,    44,    45,    46,    47,    48,     1,    55,
       3,     4,     5,     6,     7,     8,     9,    55,    11,    12,
      13,    14,    15,   448,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    50,    51,    46,
      53,    54,    55,    56,    34,    55,    39,    58,    55,    56,
      58,    44,    45,    46,    59,    59,    57,    50,    51,    57,
      17,    64,    55,    58,    55,    58,    59,    60,    61,     1,
      63,     3,     4,     5,     6,     7,     8,     9,    57,    11,
      12,    13,    14,    15,    57,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    57,     9,
       4,     5,     6,     7,    58,    58,    10,    39,    12,    13,
      14,    55,    44,    45,    46,    62,    57,    57,    50,    51,
      58,    58,    57,    55,    28,    58,    58,    58,    60,    61,
       1,    63,     3,     4,   161,     5,   299,     8,     9,    50,
      11,    55,   171,   271,    15,   431,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     4,    29,     6,
       7,     4,     5,     6,     7,    12,    13,    14,    39,    12,
      13,    14,   379,    44,    45,    46,   207,   116,   371,    50,
      51,    28,   210,   205,    55,    28,   346,    58,    59,    60,
      61,     1,    63,     3,     4,    55,   491,   365,     8,     9,
     493,    11,   251,   248,   327,    15,   429,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    39,
      -1,    12,    13,    14,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    55,    -1,    28,    58,    59,
      60,    61,     1,    63,    -1,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,     1,    -1,     3,
      -1,    -1,    -1,    -1,     8,     9,    57,    11,    27,    28,
      -1,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    -1,    -1,    29,    -1,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    39,    55,    56,    -1,    58,
      44,    45,    46,    62,    63,    -1,    50,    51,    29,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    39,    63,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,     1,    63,     3,    -1,    -1,    -1,    -1,     8,     9,
       1,    11,    -1,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,     1,    -1,     3,    -1,    -1,    29,
      -1,     8,     9,    -1,    11,    -1,    -1,    28,    -1,    39,
       5,     6,     7,    -1,    44,    45,    46,    12,    13,    14,
      50,    51,    29,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    39,    63,    -1,    -1,    57,    44,    45,    46,
      -1,     3,    -1,    50,    51,    -1,     8,     9,    55,    11,
      -1,    -1,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    29,    -1,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      29,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    61,
      39,    -1,    64,    -1,    -1,    44,    45,    46,    -1,     3,
      -1,    50,    51,    -1,     8,     9,    55,    11,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    29,    -1,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    29,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    60,    61,    39,    -1,
      64,    -1,    -1,    44,    45,    46,    -1,     3,    -1,    50,
      51,    -1,     8,     9,    55,    11,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    29,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    55,    -1,    -1,    58,    -1,    60,    61,    -1,    63,
       3,     4,    -1,    -1,    -1,     8,     9,    -1,    11,    -1,
      -1,    -1,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     3,    29,    -1,    -1,    -1,
       8,     9,    -1,    11,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    29,    55,    -1,    -1,    58,    -1,    60,    61,    -1,
      63,    39,    -1,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    60,    61,    -1,    63,     3,     4,    -1,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    -1,     3,
      -1,    -1,    -1,    -1,     8,     9,    -1,    11,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    29,    -1,    44,    45,    46,
      -1,    -1,    -1,    50,    51,    39,    -1,    -1,    55,    -1,
      44,    45,    46,    60,    61,    -1,    50,    51,    -1,    -1,
      -1,    55,    -1,     3,    58,    -1,    60,    61,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    29,    -1,    44,    45,    46,    -1,    -1,    -1,
      50,    51,    39,    -1,    -1,    55,    -1,    44,    45,    46,
      60,    61,    -1,    50,    51,    -1,    -1,    -1,    55,    -1,
       3,    -1,    -1,    60,    61,     8,     9,    -1,    11,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,     4,    29,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    39,    27,    28,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    50,    51,    28,
      -1,    -1,    55,    -1,    -1,    -1,    46,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    46,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,    68,     0,    69,     1,     4,     5,     6,
       7,    12,    13,    14,    27,    28,    58,    70,    71,    72,
      92,    94,    96,    99,   117,    70,    58,    59,     3,     4,
      63,    79,    63,    79,    63,    79,    55,    55,     3,    46,
      55,   102,   106,   116,    58,    92,     5,     7,    58,    92,
      99,    95,   121,    63,   124,   125,    63,   124,    63,     9,
      89,     3,     7,     8,    11,    29,    39,    44,    45,    46,
      50,    51,    55,    60,    61,    80,    81,    83,    84,    85,
      86,    87,    89,    97,    99,   131,   133,   134,   116,    58,
      62,     1,    27,    55,    56,    77,   103,     4,    46,    55,
     101,   104,   113,   114,   116,   102,   116,    95,     5,     6,
       7,   100,   117,    79,   129,   130,   120,    59,     1,    58,
      97,   126,   133,   118,    59,   119,     9,    57,    55,    84,
      55,    84,    85,     1,    81,    88,   131,    85,    57,    62,
      31,    32,    33,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    50,    51,    53,
      54,    55,    56,    46,    55,    56,   132,   135,    98,    57,
       7,    99,   132,     7,   116,    57,   104,   113,    55,   165,
     166,    64,    81,     1,    90,    91,    93,    94,    96,   138,
      30,   108,   134,   114,    58,    62,     1,    73,   103,    55,
      56,    58,     1,    75,    32,    62,   123,   129,    92,    58,
      92,   124,   124,    58,   131,   131,    57,    57,    63,   141,
      57,    86,    86,    86,    81,   158,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      79,    79,    82,    83,    81,   134,   135,   163,   164,    64,
      81,    55,    56,   100,    98,    89,     1,     3,    94,    96,
     167,   169,   170,   171,   172,    64,    58,    78,    93,   138,
      58,    92,    58,    92,    55,    32,   114,    57,   104,    90,
     108,   165,    64,    81,    90,    86,   130,    59,   123,    34,
     113,   127,   128,   127,    59,    59,    57,    57,    59,   139,
      57,    63,    85,    34,    57,    64,   135,    57,     1,   168,
     169,    64,   163,    64,    81,    57,    57,     4,    46,    55,
     115,   116,   132,    46,   116,   132,    57,    62,    57,    62,
       1,   140,   141,   101,   102,   116,    55,   107,    74,    32,
      64,    76,    59,    86,    34,   108,    62,     1,     3,     4,
      15,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    58,    79,    81,    91,   136,   141,   142,   144,
       1,    63,    86,   111,   112,    86,    57,    57,    64,   134,
      55,    56,   134,    10,   171,     3,   141,    58,    58,     3,
     109,   110,   111,   140,   105,   140,    86,   128,    59,    55,
     146,   148,    55,    55,    81,    34,    58,    58,    58,    81,
      79,     7,   157,    34,    58,   136,   137,    59,   138,   144,
      16,    59,   112,    62,   122,   115,   165,    64,    81,    55,
      57,    62,   111,   108,    81,    55,   144,   158,    81,    34,
     155,    58,    58,    55,   156,    59,   145,    59,    62,   111,
      59,    64,     8,   172,    57,   110,    57,    81,    17,    58,
      57,   154,   144,    89,   144,   144,    59,    57,    57,   143,
      57,   149,   150,   153,   144,    34,    57,   144,   147,    55,
     158,   144,     9,   159,   160,   161,    58,   144,    81,    58,
      55,    34,    57,    62,    57,   151,    81,   159,    58,   161,
      58,   158,    57,    34,    57,    57,    89,   162,    58,   152,
      57,    62,   144,    58,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    68,    67,    69,    67,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    73,
      74,    72,    72,    75,    76,    72,    72,    77,    78,    72,
      72,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    88,    87,
      87,    87,    87,    87,    87,    87,    89,    89,    90,    90,
      91,    91,    91,    91,    92,    93,    93,    93,    93,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,   100,   100,   100,
     101,   101,   102,   102,   103,   103,   105,   104,   104,   107,
     106,   106,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   115,   115,   115,   115,   115,   116,
     116,   116,   116,   116,   116,   118,   117,   117,   117,   119,
     117,   117,   117,   120,   117,   121,   117,   117,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   126,   126,   126,
     127,   127,   127,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   136,   136,   136,
     137,   137,   138,   139,   140,   140,   141,   141,   141,   141,
     143,   142,   144,   144,   145,   144,   144,   146,   147,   144,
     148,   149,   144,   150,   151,   152,   144,   153,   144,   154,
     144,   155,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   156,   144,   144,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   162,   162,   164,   163,   166,   165,
     167,   167,   167,   168,   168,   169,   169,   169,   170,   170,
     171,   171,   171,   171,   171,   172,   172
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     0,     2,     0,     3,     1,     1,
       5,     3,     4,     4,     2,     2,     2,     2,     1,     0,
       0,     7,     4,     0,     0,     7,     4,     0,     0,     6,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     3,     1,     2,     2,     2,     4,
       2,     4,     1,     4,     7,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     3,     3,     1,     1,     1,     3,     3,     0,     4,
       4,     4,     3,     3,     2,     2,     1,     2,     0,     1,
       1,     1,     2,     2,     0,     4,     4,     2,     2,     2,
       3,     0,     2,     2,     1,     1,     2,     2,     2,     3,
       0,     2,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     3,     1,     3,     0,     4,     0,     6,     3,     0,
       6,     3,     0,     6,     1,     3,     1,     4,     4,     1,
       2,     3,     4,     1,     1,     3,     1,     1,     3,     3,
       4,     3,     3,     1,     3,     4,     3,     3,     1,     3,
       3,     3,     4,     3,     1,     0,     6,     4,     2,     0,
       6,     4,     2,     0,     7,     0,     6,     2,     0,     1,
       0,     1,     1,     2,     0,     3,     2,     3,     3,     1,
       0,     1,     3,     2,     4,     2,     1,     3,     1,     3,
       2,     2,     0,     1,     1,     2,     0,     2,     3,     3,
       2,     3,     4,     3,     2,     3,     2,     1,     2,     2,
       0,     1,     2,     0,     1,     2,     2,     5,     4,     4,
       0,     6,     1,     2,     0,     4,     1,     0,     0,     7,
       0,     0,     9,     0,     0,     0,    12,     0,     6,     0,
       5,     0,     4,     2,     2,     2,     3,     6,     8,    10,
      12,     3,     0,     4,     1,     0,     1,     0,     1,     0,
       1,     1,     3,     4,     1,     3,     0,     2,     0,     2,
       2,     2,     2,     2,     2,     0,     1,     3,     1,     3,
       2,     2,     2,     2,     2,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* @1: %empty  */
#line 193 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
        {(yyval.ttype) = NULL_TREE; }
#line 1953 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 6: /* @2: %empty  */
#line 194 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                  {(yyval.ttype) = NULL_TREE; }
#line 1959 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 10: /* extdef: ASM '(' string ')' ';'  */
#line 201 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic)
		    warning ("ANSI C forbids use of `asm' keyword");
		  if (TREE_CHAIN ((yyvsp[-2].ttype))) (yyvsp[-2].ttype) = combine_strings ((yyvsp[-2].ttype));
		  assemble_asm ((yyvsp[-2].ttype)); }
#line 1968 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 11: /* datadef: setspecs notype_initdecls ';'  */
#line 209 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic)
		    error ("ANSI C forbids data definition lacking type or storage class");
		  else if (!flag_traditional)
		    warning ("data definition lacks type or storage class"); }
#line 1977 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 12: /* datadef: declmods setspecs notype_initdecls ';'  */
#line 214 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
          {}
#line 1983 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 13: /* datadef: typed_declspecs setspecs initdecls ';'  */
#line 216 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
          {}
#line 1989 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 14: /* datadef: declmods ';'  */
#line 218 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
          { error ("empty declaration"); }
#line 1995 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 15: /* datadef: typed_declspecs ';'  */
#line 220 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
          { shadow_tag ((yyvsp[-1].ttype)); }
#line 2001 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 18: /* datadef: ';'  */
#line 224 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic)
		    warning ("ANSI C does not allow extra `;' outside of a function"); }
#line 2008 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 230 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (! start_function ((yyvsp[-2].ttype), (yyvsp[0].ttype)))
		    YYERROR;
		  reinit_parse_for_function (); }
#line 2016 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 234 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { store_parm_decls (); }
#line 2022 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 21: /* fndef: typed_declspecs setspecs declarator $@3 xdecls $@4 compstmt_or_error  */
#line 236 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { finish_function (lineno); }
#line 2028 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 22: /* fndef: typed_declspecs setspecs declarator error  */
#line 238 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { }
#line 2034 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 240 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (! start_function ((yyvsp[-2].ttype), (yyvsp[0].ttype)))
		    YYERROR;
		  reinit_parse_for_function (); }
#line 2042 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 24: /* $@6: %empty  */
#line 244 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { store_parm_decls (); }
#line 2048 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 25: /* fndef: declmods setspecs notype_declarator $@5 xdecls $@6 compstmt_or_error  */
#line 246 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { finish_function (lineno); }
#line 2054 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 26: /* fndef: declmods setspecs notype_declarator error  */
#line 248 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { }
#line 2060 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 250 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (! start_function (0, (yyvsp[0].ttype)))
		    YYERROR;
		  reinit_parse_for_function (); }
#line 2068 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 28: /* $@8: %empty  */
#line 254 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { store_parm_decls (); }
#line 2074 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 29: /* fndef: setspecs notype_declarator $@7 xdecls $@8 compstmt_or_error  */
#line 256 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { finish_function (lineno); }
#line 2080 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 30: /* fndef: setspecs notype_declarator error  */
#line 258 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { }
#line 2086 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 33: /* unop: '&'  */
#line 267 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.code) = ADDR_EXPR; }
#line 2092 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 34: /* unop: '-'  */
#line 269 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.code) = NEGATE_EXPR; }
#line 2098 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 35: /* unop: '+'  */
#line 271 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.code) = CONVERT_EXPR; }
#line 2104 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 36: /* unop: PLUSPLUS  */
#line 273 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.code) = PREINCREMENT_EXPR; }
#line 2110 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 37: /* unop: MINUSMINUS  */
#line 275 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.code) = PREDECREMENT_EXPR; }
#line 2116 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 38: /* unop: '~'  */
#line 277 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.code) = BIT_NOT_EXPR; }
#line 2122 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 39: /* unop: '!'  */
#line 279 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.code) = TRUTH_NOT_EXPR; }
#line 2128 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 40: /* expr: nonnull_exprlist  */
#line 283 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_compound_expr ((yyvsp[0].ttype)); }
#line 2134 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 41: /* exprlist: %empty  */
#line 288 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 2140 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 43: /* nonnull_exprlist: expr_no_commas  */
#line 294 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[0].ttype)); }
#line 2146 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 44: /* nonnull_exprlist: nonnull_exprlist ',' expr_no_commas  */
#line 296 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { chainon ((yyvsp[-2].ttype), build_tree_list (NULL_TREE, (yyvsp[0].ttype))); }
#line 2152 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 46: /* unary_expr: '*' cast_expr  */
#line 302 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_indirect_ref ((yyvsp[0].ttype), "unary *"); }
#line 2158 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 47: /* unary_expr: unop cast_expr  */
#line 304 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_unary_op ((yyvsp[-1].code), (yyvsp[0].ttype), 0); }
#line 2164 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 48: /* unary_expr: SIZEOF unary_expr  */
#line 306 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (TREE_CODE ((yyvsp[0].ttype)) == COMPONENT_REF
		      && TREE_PACKED (TREE_OPERAND ((yyvsp[0].ttype), 1)))
		    error ("`sizeof' applied to a bit-field");
		  /* ANSI says arrays and functions are converted inside comma.
		     But we can't really convert them in build_compound_expr
		     because that would break commas in lvalues.
		     So do the conversion here if operand was a comma.  */
		  if (TREE_CODE ((yyvsp[0].ttype)) == COMPOUND_EXPR
		      && (TREE_CODE (TREE_TYPE ((yyvsp[0].ttype))) == ARRAY_TYPE
			  || TREE_CODE (TREE_TYPE ((yyvsp[0].ttype))) == FUNCTION_TYPE))
		    (yyvsp[0].ttype) = default_conversion ((yyvsp[0].ttype));
		  (yyval.ttype) = c_sizeof (TREE_TYPE ((yyvsp[0].ttype))); }
#line 2181 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 49: /* unary_expr: SIZEOF '(' typename ')'  */
#line 319 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = c_sizeof (groktypename ((yyvsp[-1].ttype))); }
#line 2187 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 50: /* unary_expr: ALIGNOF unary_expr  */
#line 321 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (TREE_CODE ((yyvsp[0].ttype)) == COMPONENT_REF
		      && TREE_PACKED (TREE_OPERAND ((yyvsp[0].ttype), 1)))
		    error ("`__alignof' applied to a bit-field");
		  if (TREE_CODE ((yyvsp[0].ttype)) == INDIRECT_REF)
		    {
		      tree t = TREE_OPERAND ((yyvsp[0].ttype), 0);
		      tree best = t;
		      int bestalign = TYPE_ALIGN (TREE_TYPE (TREE_TYPE (t)));
		      while (TREE_CODE (t) == NOP_EXPR
			     && TREE_CODE (TREE_TYPE (TREE_OPERAND (t, 0))) == POINTER_TYPE)
			{
			  int thisalign;
			  t = TREE_OPERAND (t, 0);
			  thisalign = TYPE_ALIGN (TREE_TYPE (TREE_TYPE (t)));
			  if (thisalign > bestalign)
			    best = t, bestalign = thisalign;
			}
		      (yyval.ttype) = c_alignof (TREE_TYPE (TREE_TYPE (best)));
		    }
		  else
		    {
		      /* ANSI says arrays and fns are converted inside comma.
			 But we can't convert them in build_compound_expr
			 because that would break commas in lvalues.
			 So do the conversion here if operand was a comma.  */
		      if (TREE_CODE ((yyvsp[0].ttype)) == COMPOUND_EXPR
			  && (TREE_CODE (TREE_TYPE ((yyvsp[0].ttype))) == ARRAY_TYPE
			      || TREE_CODE (TREE_TYPE ((yyvsp[0].ttype))) == FUNCTION_TYPE))
			(yyvsp[0].ttype) = default_conversion ((yyvsp[0].ttype));
		      (yyval.ttype) = c_alignof (TREE_TYPE ((yyvsp[0].ttype)));
		    }
		}
#line 2224 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 51: /* unary_expr: ALIGNOF '(' typename ')'  */
#line 354 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = c_alignof (groktypename ((yyvsp[-1].ttype))); }
#line 2230 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 53: /* cast_expr: '(' typename ')' cast_expr  */
#line 360 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { tree type = groktypename ((yyvsp[-2].ttype));
		  (yyval.ttype) = build_c_cast (type, (yyvsp[0].ttype)); }
#line 2237 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 54: /* cast_expr: '(' typename ')' '{' initlist maybecomma '}'  */
#line 363 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { tree type = groktypename ((yyvsp[-5].ttype));
		  if (pedantic)
		    warning ("ANSI C forbids constructor expressions");
		  (yyval.ttype) = digest_init (type, build_nt (CONSTRUCTOR, NULL_TREE, nreverse ((yyvsp[-2].ttype))), 0);
		  if (TREE_CODE (type) == ARRAY_TYPE && TYPE_SIZE (type) == 0)
		    {
		      int failure = complete_array_type (type, (yyval.ttype), 1);
		      if (failure)
			abort ();
		    }
		}
#line 2253 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 56: /* expr_no_commas: expr_no_commas '+' expr_no_commas  */
#line 379 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2259 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 57: /* expr_no_commas: expr_no_commas '-' expr_no_commas  */
#line 381 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2265 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 58: /* expr_no_commas: expr_no_commas '*' expr_no_commas  */
#line 383 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2271 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 59: /* expr_no_commas: expr_no_commas '/' expr_no_commas  */
#line 385 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2277 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 60: /* expr_no_commas: expr_no_commas '%' expr_no_commas  */
#line 387 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2283 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 61: /* expr_no_commas: expr_no_commas LSHIFT expr_no_commas  */
#line 389 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2289 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 62: /* expr_no_commas: expr_no_commas RSHIFT expr_no_commas  */
#line 391 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2295 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 63: /* expr_no_commas: expr_no_commas ARITHCOMPARE expr_no_commas  */
#line 393 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2301 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 64: /* expr_no_commas: expr_no_commas EQCOMPARE expr_no_commas  */
#line 395 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2307 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 65: /* expr_no_commas: expr_no_commas '&' expr_no_commas  */
#line 397 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2313 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 66: /* expr_no_commas: expr_no_commas '|' expr_no_commas  */
#line 399 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2319 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 67: /* expr_no_commas: expr_no_commas '^' expr_no_commas  */
#line 401 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op ((yyvsp[-1].code), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2325 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 68: /* expr_no_commas: expr_no_commas ANDAND expr_no_commas  */
#line 403 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op (TRUTH_ANDIF_EXPR, (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2331 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 69: /* expr_no_commas: expr_no_commas OROR expr_no_commas  */
#line 405 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_binary_op (TRUTH_ORIF_EXPR, (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2337 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 70: /* expr_no_commas: expr_no_commas '?' xexpr ':' expr_no_commas  */
#line 407 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_conditional_expr ((yyvsp[-4].ttype), (yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2343 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 71: /* expr_no_commas: expr_no_commas '=' expr_no_commas  */
#line 409 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_modify_expr ((yyvsp[-2].ttype), NOP_EXPR, (yyvsp[0].ttype)); }
#line 2349 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 72: /* expr_no_commas: expr_no_commas ASSIGN expr_no_commas  */
#line 411 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_modify_expr ((yyvsp[-2].ttype), (yyvsp[-1].code), (yyvsp[0].ttype)); }
#line 2355 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 73: /* primary: IDENTIFIER  */
#line 416 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = lastiddecl;
		  if (!(yyval.ttype) || (yyval.ttype) == error_mark_node)
		    {
		      if (yychar == YYEMPTY)
			yychar = yylex();
		      if (yychar == '(')
			{
			  (yyval.ttype) = implicitly_declare ((yyvsp[0].ttype));
			  assemble_external ((yyval.ttype));
			  TREE_USED ((yyval.ttype)) = 1;
			}
		      else if (current_function_decl == 0)
			{
			  error ("`%s' undeclared, outside of functions",
				 IDENTIFIER_POINTER ((yyvsp[0].ttype)));
			  (yyval.ttype) = error_mark_node;
			}
		      else
			{
			  if (IDENTIFIER_GLOBAL_VALUE ((yyvsp[0].ttype)) != error_mark_node
			      || IDENTIFIER_ERROR_LOCUS ((yyvsp[0].ttype)) != current_function_decl)
			    {
			      error ("`%s' undeclared (first use this function)",
				     IDENTIFIER_POINTER ((yyvsp[0].ttype)));

			      if (! undeclared_variable_notice)
				{
				  error ("(Each undeclared identifier is reported only once");
				  error ("for each function it appears in.)");
				  undeclared_variable_notice = 1;
				}
			    }
			  (yyval.ttype) = error_mark_node;
			  /* Prevent repeated error messages.  */
			  IDENTIFIER_GLOBAL_VALUE ((yyvsp[0].ttype)) = error_mark_node;
			  IDENTIFIER_ERROR_LOCUS ((yyvsp[0].ttype)) = current_function_decl;
			}
		    }
		  else if (! TREE_USED ((yyval.ttype)))
		    {
		      if (TREE_EXTERNAL ((yyval.ttype)))
			assemble_external ((yyval.ttype));
		      TREE_USED ((yyval.ttype)) = 1;
		    }
		  if (TREE_CODE ((yyval.ttype)) == CONST_DECL)
		    (yyval.ttype) = DECL_INITIAL ((yyval.ttype));
		}
#line 2407 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 75: /* primary: string  */
#line 465 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = combine_strings ((yyvsp[0].ttype)); }
#line 2413 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 76: /* primary: '(' expr ')'  */
#line 467 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[-1].ttype); }
#line 2419 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 77: /* primary: '(' error ')'  */
#line 469 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = error_mark_node; }
#line 2425 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 78: /* @9: %empty  */
#line 471 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (current_function_decl == 0)
		    {
		      error ("braced-group within expression allowed only inside a function");
		      YYERROR;
		    }
		  keep_next_level ();
		  (yyval.ttype) = expand_start_stmt_expr (); }
#line 2437 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 79: /* primary: '(' @9 compstmt ')'  */
#line 479 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { tree rtl_exp;
		  if (pedantic)
		    warning ("ANSI C forbids braced-groups within expressions");
		  rtl_exp = expand_end_stmt_expr ((yyvsp[-2].ttype));
		  (yyval.ttype) = (yyvsp[-1].ttype);
		  TREE_USED ((yyval.ttype)) = 0;
		  /* Since the statements have side effects,
		     consider this volatile.  */
		  TREE_VOLATILE ((yyval.ttype)) = 1;
		  TREE_TYPE ((yyval.ttype)) = TREE_TYPE (rtl_exp);
		  STMT_BODY ((yyval.ttype)) = rtl_exp; }
#line 2453 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 80: /* primary: primary '(' exprlist ')'  */
#line 491 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_function_call ((yyvsp[-3].ttype), (yyvsp[-1].ttype)); }
#line 2459 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 81: /* primary: primary '[' expr ']'  */
#line 493 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_array_ref ((yyvsp[-3].ttype), (yyvsp[-1].ttype)); }
#line 2465 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 82: /* primary: primary '.' identifier  */
#line 495 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_component_ref ((yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 2471 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 83: /* primary: primary POINTSAT identifier  */
#line 497 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_component_ref (build_indirect_ref ((yyvsp[-2].ttype), "->"), (yyvsp[0].ttype)); }
#line 2477 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 84: /* primary: primary PLUSPLUS  */
#line 499 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_unary_op (POSTINCREMENT_EXPR, (yyvsp[-1].ttype), 0); }
#line 2483 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 85: /* primary: primary MINUSMINUS  */
#line 501 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_unary_op (POSTDECREMENT_EXPR, (yyvsp[-1].ttype), 0); }
#line 2489 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 87: /* string: string STRING  */
#line 508 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 2495 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 94: /* setspecs: %empty  */
#line 528 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.itype) = suspend_momentary ();
		  declspec_stack = tree_cons (0, current_declspecs,
					      declspec_stack);
		  current_declspecs = (yyvsp[0].ttype); }
#line 2504 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 95: /* decl: typed_declspecs setspecs initdecls ';'  */
#line 536 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { current_declspecs = TREE_VALUE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack);
		  resume_momentary ((yyvsp[-2].itype)); }
#line 2512 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 96: /* decl: declmods setspecs notype_initdecls ';'  */
#line 540 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { current_declspecs = TREE_VALUE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack);
		  resume_momentary ((yyvsp[-2].itype)); }
#line 2520 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 97: /* decl: typed_declspecs ';'  */
#line 544 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { shadow_tag ((yyvsp[-1].ttype)); }
#line 2526 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 98: /* decl: declmods ';'  */
#line 546 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { warning ("empty declaration"); }
#line 2532 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 99: /* typed_declspecs: typespec reserved_declspecs  */
#line 555 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 2538 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 100: /* typed_declspecs: declmods typespec reserved_declspecs  */
#line 557 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[0].ttype), tree_cons (NULL_TREE, (yyvsp[-1].ttype), (yyvsp[-2].ttype))); }
#line 2544 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 101: /* reserved_declspecs: %empty  */
#line 561 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 2550 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 102: /* reserved_declspecs: reserved_declspecs typespecqual_reserved  */
#line 563 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-1].ttype)); }
#line 2556 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 103: /* reserved_declspecs: reserved_declspecs SCSPEC  */
#line 565 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-1].ttype)); }
#line 2562 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 104: /* declmods: TYPE_QUAL  */
#line 574 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), NULL_TREE); }
#line 2568 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 105: /* declmods: SCSPEC  */
#line 576 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), NULL_TREE); }
#line 2574 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 106: /* declmods: declmods TYPE_QUAL  */
#line 578 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-1].ttype)); }
#line 2580 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 107: /* declmods: declmods SCSPEC  */
#line 580 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-1].ttype)); }
#line 2586 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 108: /* typed_typespecs: typespec reserved_typespecquals  */
#line 590 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 2592 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 109: /* typed_typespecs: nonempty_type_quals typespec reserved_typespecquals  */
#line 592 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[0].ttype), tree_cons (NULL_TREE, (yyvsp[-1].ttype), (yyvsp[-2].ttype))); }
#line 2598 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 110: /* reserved_typespecquals: %empty  */
#line 596 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 2604 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 111: /* reserved_typespecquals: reserved_typespecquals typespecqual_reserved  */
#line 598 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-1].ttype)); }
#line 2610 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 115: /* typespec: TYPEOF '(' expr ')'  */
#line 609 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = TREE_TYPE ((yyvsp[-1].ttype));
		  if (pedantic)
		    warning ("ANSI C forbids `typeof'"); }
#line 2618 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 116: /* typespec: TYPEOF '(' typename ')'  */
#line 613 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = groktypename ((yyvsp[-1].ttype));
		  if (pedantic)
		    warning ("ANSI C forbids `typeof'"); }
#line 2626 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 124: /* maybeasm: %empty  */
#line 637 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 2632 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 125: /* maybeasm: ASM '(' string ')'  */
#line 639 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (TREE_CHAIN ((yyvsp[-1].ttype))) (yyvsp[-1].ttype) = combine_strings ((yyvsp[-1].ttype));
		  (yyval.ttype) = (yyvsp[-1].ttype);
		  if (pedantic)
		    warning ("ANSI C forbids use of `asm' keyword");
		}
#line 2642 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 126: /* @10: %empty  */
#line 648 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = start_decl ((yyvsp[-3].ttype), current_declspecs, 1); }
#line 2648 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 127: /* initdcl: declarator maybeasm maybe_attribute '=' @10 init  */
#line 651 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { finish_decl ((yyvsp[-1].ttype), (yyvsp[0].ttype), (yyvsp[-4].ttype)); }
#line 2654 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 128: /* initdcl: declarator maybeasm maybe_attribute  */
#line 653 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { tree d = start_decl ((yyvsp[-2].ttype), current_declspecs, 0);
		  finish_decl (d, NULL_TREE, (yyvsp[-1].ttype)); }
#line 2661 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 129: /* @11: %empty  */
#line 659 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = start_decl ((yyvsp[-3].ttype), current_declspecs, 1); }
#line 2667 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 130: /* notype_initdcl: notype_declarator maybeasm maybe_attribute '=' @11 init  */
#line 662 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { finish_decl ((yyvsp[-1].ttype), (yyvsp[0].ttype), (yyvsp[-4].ttype)); }
#line 2673 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 131: /* notype_initdcl: notype_declarator maybeasm maybe_attribute  */
#line 664 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { tree d = start_decl ((yyvsp[-2].ttype), current_declspecs, 0);
		  finish_decl (d, NULL_TREE, (yyvsp[-1].ttype)); }
#line 2680 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 132: /* maybe_attribute: %empty  */
#line 671 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
        { (yyval.ttype) = NULL_TREE; }
#line 2686 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 133: /* maybe_attribute: ATTRIBUTE '(' '(' attribute_list ')' ')'  */
#line 673 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
        { (yyval.ttype) = (yyvsp[-2].ttype); }
#line 2692 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 136: /* attrib: IDENTIFIER  */
#line 683 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
        { warning ("`%s' attribute directive ignored",
		   IDENTIFIER_POINTER ((yyvsp[0].ttype)));
	  (yyval.ttype) = (yyvsp[0].ttype); }
#line 2700 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 137: /* attrib: IDENTIFIER '(' CONSTANT ')'  */
#line 687 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
        { /* if not "aligned(1)", then issue warning */
	  if (strcmp (IDENTIFIER_POINTER ((yyvsp[-3].ttype)), "aligned") != 0
	      || TREE_CODE ((yyvsp[-1].ttype)) != INTEGER_CST
	      || TREE_INT_CST_LOW ((yyvsp[-1].ttype)) != 1)
	    warning ("`%s' attribute directive ignored",
		     IDENTIFIER_POINTER ((yyvsp[-3].ttype)));
	  (yyval.ttype) = (yyvsp[-3].ttype); }
#line 2712 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 138: /* attrib: IDENTIFIER '(' identifiers ')'  */
#line 695 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
        { warning ("`%s' attribute directive ignored",
		   IDENTIFIER_POINTER ((yyvsp[-3].ttype)));
	  (yyval.ttype) = (yyvsp[-3].ttype); }
#line 2720 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 140: /* init: '{' '}'  */
#line 703 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CONSTRUCTOR, NULL_TREE, NULL_TREE);
		  if (pedantic)
		    warning ("ANSI C forbids empty initializer braces"); }
#line 2728 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 141: /* init: '{' initlist '}'  */
#line 707 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CONSTRUCTOR, NULL_TREE, nreverse ((yyvsp[-1].ttype))); }
#line 2734 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 142: /* init: '{' initlist ',' '}'  */
#line 709 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CONSTRUCTOR, NULL_TREE, nreverse ((yyvsp[-2].ttype))); }
#line 2740 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 143: /* init: error  */
#line 711 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 2746 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 144: /* initlist: init  */
#line 718 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[0].ttype)); }
#line 2752 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 145: /* initlist: initlist ',' init  */
#line 720 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-2].ttype)); }
#line 2758 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 148: /* after_type_declarator: '(' after_type_declarator ')'  */
#line 735 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[-1].ttype); }
#line 2764 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 149: /* after_type_declarator: after_type_declarator '(' parmlist_or_identifiers  */
#line 737 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[-2].ttype), (yyvsp[0].ttype), NULL_TREE); }
#line 2770 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 150: /* after_type_declarator: after_type_declarator '[' expr ']'  */
#line 742 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-3].ttype), (yyvsp[-1].ttype)); }
#line 2776 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 151: /* after_type_declarator: after_type_declarator '[' ']'  */
#line 744 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-2].ttype), NULL_TREE); }
#line 2782 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 152: /* after_type_declarator: '*' type_quals after_type_declarator  */
#line 746 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = make_pointer_declarator ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 2788 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 154: /* parm_declarator: parm_declarator '(' parmlist_or_identifiers  */
#line 757 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[-2].ttype), (yyvsp[0].ttype), NULL_TREE); }
#line 2794 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 155: /* parm_declarator: parm_declarator '[' expr ']'  */
#line 762 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-3].ttype), (yyvsp[-1].ttype)); }
#line 2800 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 156: /* parm_declarator: parm_declarator '[' ']'  */
#line 764 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-2].ttype), NULL_TREE); }
#line 2806 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 157: /* parm_declarator: '*' type_quals parm_declarator  */
#line 766 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = make_pointer_declarator ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 2812 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 159: /* notype_declarator: notype_declarator '(' parmlist_or_identifiers  */
#line 775 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[-2].ttype), (yyvsp[0].ttype), NULL_TREE); }
#line 2818 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 160: /* notype_declarator: '(' notype_declarator ')'  */
#line 780 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[-1].ttype); }
#line 2824 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 161: /* notype_declarator: '*' type_quals notype_declarator  */
#line 782 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = make_pointer_declarator ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 2830 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 162: /* notype_declarator: notype_declarator '[' expr ']'  */
#line 784 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-3].ttype), (yyvsp[-1].ttype)); }
#line 2836 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 163: /* notype_declarator: notype_declarator '[' ']'  */
#line 786 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-2].ttype), NULL_TREE); }
#line 2842 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 165: /* @12: %empty  */
#line 792 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = start_struct (RECORD_TYPE, (yyvsp[-1].ttype));
		  /* Start scope of tag before parsing components.  */
		}
#line 2850 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 166: /* structsp: STRUCT identifier '{' @12 component_decl_list '}'  */
#line 796 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = finish_struct ((yyvsp[-2].ttype), (yyvsp[-1].ttype));
		  /* Really define the structure.  */
		}
#line 2858 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 167: /* structsp: STRUCT '{' component_decl_list '}'  */
#line 800 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = finish_struct (start_struct (RECORD_TYPE, NULL_TREE),
				      (yyvsp[-1].ttype)); }
#line 2865 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 168: /* structsp: STRUCT identifier  */
#line 803 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = xref_tag (RECORD_TYPE, (yyvsp[0].ttype)); }
#line 2871 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 169: /* @13: %empty  */
#line 805 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = start_struct (UNION_TYPE, (yyvsp[-1].ttype)); }
#line 2877 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 170: /* structsp: UNION identifier '{' @13 component_decl_list '}'  */
#line 807 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = finish_struct ((yyvsp[-2].ttype), (yyvsp[-1].ttype)); }
#line 2883 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 171: /* structsp: UNION '{' component_decl_list '}'  */
#line 809 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = finish_struct (start_struct (UNION_TYPE, NULL_TREE),
				      (yyvsp[-1].ttype)); }
#line 2890 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 172: /* structsp: UNION identifier  */
#line 812 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = xref_tag (UNION_TYPE, (yyvsp[0].ttype)); }
#line 2896 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 173: /* @14: %empty  */
#line 814 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyvsp[0].itype) = suspend_momentary ();
		  (yyval.ttype) = start_enum ((yyvsp[-1].ttype)); }
#line 2903 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 174: /* structsp: ENUM identifier '{' @14 enumlist maybecomma_warn '}'  */
#line 817 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = finish_enum ((yyvsp[-3].ttype), nreverse ((yyvsp[-2].ttype)));
		  resume_momentary ((yyvsp[-4].itype)); }
#line 2910 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 175: /* @15: %empty  */
#line 820 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyvsp[0].itype) = suspend_momentary ();
		  (yyval.ttype) = start_enum (NULL_TREE); }
#line 2917 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 176: /* structsp: ENUM '{' @15 enumlist maybecomma_warn '}'  */
#line 823 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = finish_enum ((yyvsp[-3].ttype), nreverse ((yyvsp[-2].ttype)));
		  resume_momentary ((yyvsp[-4].itype)); }
#line 2924 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 177: /* structsp: ENUM identifier  */
#line 826 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = xref_tag (ENUMERAL_TYPE, (yyvsp[0].ttype)); }
#line 2930 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 181: /* maybecomma_warn: ','  */
#line 837 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic) warning ("comma at end of enumerator list"); }
#line 2936 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 182: /* component_decl_list: component_decl_list2  */
#line 842 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[0].ttype); }
#line 2942 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 183: /* component_decl_list: component_decl_list2 component_decl  */
#line 844 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[-1].ttype), (yyvsp[0].ttype));
		  warning ("no semicolon at end of struct or union"); }
#line 2949 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 184: /* component_decl_list2: %empty  */
#line 849 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 2955 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 185: /* component_decl_list2: component_decl_list2 component_decl ';'  */
#line 851 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[-2].ttype), (yyvsp[-1].ttype)); }
#line 2961 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 186: /* component_decl_list2: component_decl_list2 ';'  */
#line 853 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic)
		    warning ("extra semicolon in struct or union specified"); }
#line 2968 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 187: /* component_decl: typed_typespecs setspecs components  */
#line 868 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[0].ttype);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack);
		  resume_momentary ((yyvsp[-1].itype)); }
#line 2977 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 188: /* component_decl: nonempty_type_quals setspecs components  */
#line 873 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[0].ttype);
		  current_declspecs = TREE_VALUE (declspec_stack);
		  declspec_stack = TREE_CHAIN (declspec_stack);
		  resume_momentary ((yyvsp[-1].itype)); }
#line 2986 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 189: /* component_decl: error  */
#line 878 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 2992 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 190: /* components: %empty  */
#line 883 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic)
		    warning ("ANSI C forbids member declarations with no members");
		  (yyval.ttype) = NULL_TREE; }
#line 3000 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 192: /* components: components ',' component_declarator  */
#line 888 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 3006 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 193: /* component_declarator: declarator maybe_attribute  */
#line 893 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = grokfield (input_filename, lineno, (yyvsp[-1].ttype), current_declspecs, NULL_TREE); }
#line 3012 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 194: /* component_declarator: declarator ':' expr_no_commas maybe_attribute  */
#line 895 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = grokfield (input_filename, lineno, (yyvsp[-3].ttype), current_declspecs, (yyvsp[-1].ttype)); }
#line 3018 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 195: /* component_declarator: ':' expr_no_commas  */
#line 897 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = grokfield (input_filename, lineno, NULL_TREE, current_declspecs, (yyvsp[0].ttype)); }
#line 3024 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 197: /* enumlist: enumlist ',' enumerator  */
#line 908 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[0].ttype), (yyvsp[-2].ttype)); }
#line 3030 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 198: /* enumerator: identifier  */
#line 914 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_enumerator ((yyvsp[0].ttype), NULL_TREE); }
#line 3036 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 199: /* enumerator: identifier '=' expr_no_commas  */
#line 916 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_enumerator ((yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 3042 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 200: /* typename: typed_typespecs absdcl  */
#line 921 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 3048 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 201: /* typename: nonempty_type_quals absdcl  */
#line 923 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 3054 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 202: /* absdcl: %empty  */
#line 928 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 3060 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 204: /* nonempty_type_quals: TYPE_QUAL  */
#line 934 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), NULL_TREE); }
#line 3066 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 205: /* nonempty_type_quals: nonempty_type_quals TYPE_QUAL  */
#line 936 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-1].ttype)); }
#line 3072 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 206: /* type_quals: %empty  */
#line 941 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 3078 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 207: /* type_quals: type_quals TYPE_QUAL  */
#line 943 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, (yyvsp[0].ttype), (yyvsp[-1].ttype)); }
#line 3084 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 208: /* absdcl1: '(' absdcl1 ')'  */
#line 948 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[-1].ttype); }
#line 3090 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 209: /* absdcl1: '*' type_quals absdcl1  */
#line 951 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = make_pointer_declarator ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 3096 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 210: /* absdcl1: '*' type_quals  */
#line 953 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = make_pointer_declarator ((yyvsp[0].ttype), NULL_TREE); }
#line 3102 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 211: /* absdcl1: absdcl1 '(' parmlist  */
#line 955 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CALL_EXPR, (yyvsp[-2].ttype), (yyvsp[0].ttype), NULL_TREE); }
#line 3108 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 212: /* absdcl1: absdcl1 '[' expr ']'  */
#line 957 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-3].ttype), (yyvsp[-1].ttype)); }
#line 3114 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 213: /* absdcl1: absdcl1 '[' ']'  */
#line 959 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, (yyvsp[-2].ttype), NULL_TREE); }
#line 3120 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 214: /* absdcl1: '(' parmlist  */
#line 961 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (CALL_EXPR, NULL_TREE, (yyvsp[0].ttype), NULL_TREE); }
#line 3126 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 215: /* absdcl1: '[' expr ']'  */
#line 963 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, NULL_TREE, (yyvsp[-1].ttype)); }
#line 3132 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 216: /* absdcl1: '[' ']'  */
#line 965 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_nt (ARRAY_REF, NULL_TREE, NULL_TREE); }
#line 3138 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 223: /* pushlevel: %empty  */
#line 987 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { pushlevel (0);
		  clear_last_expr ();
		  push_momentary ();
		  expand_start_bindings (0); }
#line 3147 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 224: /* compstmt_or_error: compstmt  */
#line 997 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                {}
#line 3153 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 226: /* compstmt: '{' '}'  */
#line 1002 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = 0; }
#line 3159 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 227: /* compstmt: '{' pushlevel decls xstmts '}'  */
#line 1004 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_end_bindings (getdecls (), 1, 0);
		  (yyval.ttype) = poplevel (1, 1, 0);
		  pop_momentary (); }
#line 3167 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 228: /* compstmt: '{' pushlevel error '}'  */
#line 1008 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_end_bindings (getdecls (), kept_level_p (), 0);
		  (yyval.ttype) = poplevel (kept_level_p (), 0, 0);
		  pop_momentary (); }
#line 3175 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 229: /* compstmt: '{' pushlevel stmts '}'  */
#line 1012 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_end_bindings (getdecls (), kept_level_p (), 0);
		  (yyval.ttype) = poplevel (kept_level_p (), 0, 0);
		  pop_momentary (); }
#line 3183 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 230: /* $@16: %empty  */
#line 1019 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  expand_start_cond (truthvalue_conversion ((yyvsp[-1].ttype)), 0); }
#line 3190 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 232: /* stmt: compstmt  */
#line 1025 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                        {}
#line 3196 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 233: /* stmt: expr ';'  */
#line 1027 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  /* Do default conversion if safe and possibly important,
		     in case within ({...}).  */
		  if ((TREE_CODE (TREE_TYPE ((yyvsp[-1].ttype))) == ARRAY_TYPE
		       && lvalue_p ((yyvsp[-1].ttype)))
		      || TREE_CODE (TREE_TYPE ((yyvsp[-1].ttype))) == FUNCTION_TYPE)
		    (yyvsp[-1].ttype) = default_conversion ((yyvsp[-1].ttype));
		  expand_expr_stmt ((yyvsp[-1].ttype));
		  clear_momentary (); }
#line 3210 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 234: /* $@17: %empty  */
#line 1037 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_start_else (); }
#line 3216 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 235: /* stmt: simple_if ELSE $@17 stmt  */
#line 1039 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_end_else (); }
#line 3222 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 236: /* stmt: simple_if  */
#line 1041 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_end_cond (); }
#line 3228 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 237: /* $@18: %empty  */
#line 1043 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_nop ();
		  emit_line_note (input_filename, lineno);
		  expand_start_loop (1); }
#line 3236 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 238: /* $@19: %empty  */
#line 1047 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  expand_exit_loop_if_false (truthvalue_conversion ((yyvsp[-1].ttype))); }
#line 3243 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 239: /* stmt: WHILE $@18 '(' expr ')' $@19 stmt  */
#line 1050 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_end_loop (); }
#line 3249 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 240: /* $@20: %empty  */
#line 1052 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_nop ();
		  emit_line_note (input_filename, lineno);
		  expand_start_loop_continue_elsewhere (1); }
#line 3257 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 241: /* $@21: %empty  */
#line 1056 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_loop_continue_here (); }
#line 3263 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 242: /* stmt: DO $@20 stmt WHILE $@21 '(' expr ')' ';'  */
#line 1058 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  expand_exit_loop_if_false (truthvalue_conversion ((yyvsp[-2].ttype)));
		  expand_end_loop ();
		  clear_momentary (); }
#line 3272 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 243: /* $@22: %empty  */
#line 1064 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_nop ();
		  emit_line_note (input_filename, lineno);
		  if ((yyvsp[-1].ttype)) expand_expr_stmt ((yyvsp[-1].ttype));
		  expand_start_loop_continue_elsewhere (1); }
#line 3281 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 244: /* $@23: %empty  */
#line 1069 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  if ((yyvsp[-1].ttype))
		    expand_exit_loop_if_false (truthvalue_conversion ((yyvsp[-1].ttype))); }
#line 3289 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 245: /* $@24: %empty  */
#line 1075 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { push_momentary ();
		  (yyvsp[0].itype) = lineno; }
#line 3296 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 246: /* stmt: FOR '(' xexpr ';' $@22 xexpr ';' $@23 xexpr ')' $@24 stmt  */
#line 1078 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, (yyvsp[-2].itype));
		  expand_loop_continue_here ();
		  if ((yyvsp[-3].ttype))
		    expand_expr_stmt ((yyvsp[-3].ttype));
		  pop_momentary ();
		  expand_end_loop (); }
#line 3307 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 247: /* $@25: %empty  */
#line 1085 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  c_expand_start_case ((yyvsp[-1].ttype));
		  /* Don't let the tree nodes for $3 be discarded by
		     clear_momentary during the parsing of the next stmt.  */
		  push_momentary (); }
#line 3317 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 248: /* stmt: SWITCH '(' expr ')' $@25 stmt  */
#line 1091 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { expand_end_case ((yyvsp[-3].ttype));
		  pop_momentary (); }
#line 3324 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 249: /* $@26: %empty  */
#line 1094 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { register tree value = fold ((yyvsp[-1].ttype));
		  register tree label
		    = build_decl (LABEL_DECL, NULL_TREE, NULL_TREE);

		  /* build_c_cast puts on a NOP_EXPR to make a non-lvalue.
		     Strip such NOP_EXPRs.  */
		  if (TREE_CODE (value) == NOP_EXPR
		      && TREE_TYPE (value) == TREE_TYPE (TREE_OPERAND (value, 0)))
		    value = TREE_OPERAND (value, 0);

		  if (TREE_CODE (value) != INTEGER_CST
		      && value != error_mark_node)
		    {
		      error ("case label does not reduce to an integer constant");
		      value = error_mark_node;
		    }
		  else
		    /* Promote char or short to int.  */
		    value = default_conversion (value);
		  if (value != error_mark_node)
		    {
		      int success = pushcase (value, label);
		      if (success == 1)
			error ("case label not within a switch statement");
		      else if (success == 2)
			error ("duplicate case value");
		      else if (success == 3)
			warning ("case value out of range");
		    }
		}
#line 3359 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 251: /* $@27: %empty  */
#line 1126 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                {
		  register tree label
		    = build_decl (LABEL_DECL, NULL_TREE, NULL_TREE);
		  int success = pushcase (NULL_TREE, label);
		  if (success == 1)
		    error ("default label not within a switch statement");
		  else if (success == 2)
		    error ("multiple default labels in one switch");
		}
#line 3373 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 253: /* stmt: BREAK ';'  */
#line 1137 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  if ( ! expand_exit_something ())
		    error ("break statement not within loop or switch"); }
#line 3381 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 254: /* stmt: CONTINUE ';'  */
#line 1141 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  if (! expand_continue_loop ())
		    error ("continue statement not within a loop"); }
#line 3389 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 255: /* stmt: RETURN ';'  */
#line 1145 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  c_expand_return (NULL_TREE); }
#line 3396 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 256: /* stmt: RETURN expr ';'  */
#line 1148 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { emit_line_note (input_filename, lineno);
		  c_expand_return ((yyvsp[-1].ttype)); }
#line 3403 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 257: /* stmt: ASM maybe_type_qual '(' string ')' ';'  */
#line 1151 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (TREE_CHAIN ((yyvsp[-2].ttype))) (yyvsp[-2].ttype) = combine_strings ((yyvsp[-2].ttype));
		  emit_line_note (input_filename, lineno);
		  expand_asm ((yyvsp[-2].ttype)); }
#line 3411 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 258: /* stmt: ASM maybe_type_qual '(' string ':' asm_operands ')' ';'  */
#line 1156 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (TREE_CHAIN ((yyvsp[-4].ttype))) (yyvsp[-4].ttype) = combine_strings ((yyvsp[-4].ttype));
		  emit_line_note (input_filename, lineno);
		  c_expand_asm_operands ((yyvsp[-4].ttype), (yyvsp[-2].ttype), NULL_TREE, NULL_TREE,
					 (yyvsp[-6].ttype) == ridpointers[(int)RID_VOLATILE],
					 input_filename, lineno); }
#line 3421 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 259: /* stmt: ASM maybe_type_qual '(' string ':' asm_operands ':' asm_operands ')' ';'  */
#line 1163 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (TREE_CHAIN ((yyvsp[-6].ttype))) (yyvsp[-6].ttype) = combine_strings ((yyvsp[-6].ttype));
		  emit_line_note (input_filename, lineno);
		  c_expand_asm_operands ((yyvsp[-6].ttype), (yyvsp[-4].ttype), (yyvsp[-2].ttype), NULL_TREE,
					 (yyvsp[-8].ttype) == ridpointers[(int)RID_VOLATILE],
					 input_filename, lineno); }
#line 3431 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 260: /* stmt: ASM maybe_type_qual '(' string ':' asm_operands ':' asm_operands ':' asm_clobbers ')' ';'  */
#line 1171 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (TREE_CHAIN ((yyvsp[-8].ttype))) (yyvsp[-8].ttype) = combine_strings ((yyvsp[-8].ttype));
		  emit_line_note (input_filename, lineno);
		  c_expand_asm_operands ((yyvsp[-8].ttype), (yyvsp[-6].ttype), (yyvsp[-4].ttype), (yyvsp[-2].ttype),
					 (yyvsp[-10].ttype) == ridpointers[(int)RID_VOLATILE],
					 input_filename, lineno); }
#line 3441 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 261: /* stmt: GOTO identifier ';'  */
#line 1177 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { tree decl;
		  emit_line_note (input_filename, lineno);
		  decl = lookup_label ((yyvsp[-1].ttype));
		  TREE_USED (decl) = 1;
		  expand_goto (decl); }
#line 3451 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 262: /* $@28: %empty  */
#line 1183 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { tree label = define_label (input_filename, lineno, (yyvsp[-1].ttype));
		  emit_nop ();
		  if (label)
		    expand_label (label); }
#line 3460 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 265: /* maybe_type_qual: %empty  */
#line 1195 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic)
		    warning ("ANSI C forbids use of `asm' keyword");
		  emit_line_note (input_filename, lineno); }
#line 3468 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 266: /* maybe_type_qual: TYPE_QUAL  */
#line 1199 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { if (pedantic)
		    warning ("ANSI C forbids use of `asm' keyword");
		  emit_line_note (input_filename, lineno); }
#line 3476 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 267: /* xexpr: %empty  */
#line 1206 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 3482 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 269: /* asm_operands: %empty  */
#line 1213 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = NULL_TREE; }
#line 3488 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 272: /* nonnull_asm_operands: nonnull_asm_operands ',' asm_operand  */
#line 1220 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[-2].ttype), (yyvsp[0].ttype)); }
#line 3494 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 273: /* asm_operand: STRING '(' expr ')'  */
#line 1225 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-3].ttype), (yyvsp[-1].ttype)); }
#line 3500 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 274: /* asm_clobbers: string  */
#line 1230 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, combine_strings ((yyvsp[0].ttype)), NULL_TREE); }
#line 3506 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 275: /* asm_clobbers: asm_clobbers ',' string  */
#line 1232 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, combine_strings ((yyvsp[0].ttype)), (yyvsp[-2].ttype)); }
#line 3512 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 276: /* $@29: %empty  */
#line 1238 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { pushlevel (0);
		  declare_parm_level (); }
#line 3519 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 277: /* parmlist: $@29 parmlist_1  */
#line 1241 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[0].ttype);
		  parmlist_tags_warning ();
		  poplevel (0, 0, 0); }
#line 3527 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 278: /* $@30: %empty  */
#line 1249 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { pushlevel (0);
		  declare_parm_level (); }
#line 3534 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 279: /* parmlist_or_identifiers: $@30 parmlist_or_identifiers_1  */
#line 1252 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = (yyvsp[0].ttype);
		  parmlist_tags_warning ();
		  poplevel (0, 0, 0); }
#line 3542 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 281: /* parmlist_or_identifiers_1: identifiers ')'  */
#line 1260 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, NULL_TREE, (yyvsp[-1].ttype)); }
#line 3548 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 282: /* parmlist_or_identifiers_1: error ')'  */
#line 1262 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, NULL_TREE, NULL_TREE); }
#line 3554 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 284: /* parmlist_1: error ')'  */
#line 1268 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = tree_cons (NULL_TREE, NULL_TREE, NULL_TREE); }
#line 3560 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 285: /* parmlist_2: %empty  */
#line 1274 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = get_parm_info (0); }
#line 3566 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 286: /* parmlist_2: parms  */
#line 1276 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = get_parm_info (1); }
#line 3572 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 287: /* parmlist_2: parms ',' ELLIPSIS  */
#line 1278 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = get_parm_info (0); }
#line 3578 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 288: /* parms: parm  */
#line 1283 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { push_parm_decl ((yyvsp[0].ttype)); }
#line 3584 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 289: /* parms: parms ',' parm  */
#line 1285 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { push_parm_decl ((yyvsp[0].ttype)); }
#line 3590 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 290: /* parm: typed_declspecs parm_declarator  */
#line 1292 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-1].ttype), (yyvsp[0].ttype))	; }
#line 3596 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 291: /* parm: typed_declspecs notype_declarator  */
#line 1294 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-1].ttype), (yyvsp[0].ttype))	; }
#line 3602 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 292: /* parm: typed_declspecs absdcl  */
#line 1296 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 3608 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 293: /* parm: declmods notype_declarator  */
#line 1298 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-1].ttype), (yyvsp[0].ttype))	; }
#line 3614 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 294: /* parm: declmods absdcl  */
#line 1300 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list ((yyvsp[-1].ttype), (yyvsp[0].ttype)); }
#line 3620 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 295: /* identifiers: IDENTIFIER  */
#line 1306 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = build_tree_list (NULL_TREE, (yyvsp[0].ttype)); }
#line 3626 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;

  case 296: /* identifiers: identifiers ',' IDENTIFIER  */
#line 1308 "/home/dave/tools/ctools/gca-1.40/c-parse.y"
                { (yyval.ttype) = chainon ((yyvsp[-2].ttype), build_tree_list (NULL_TREE, (yyvsp[0].ttype))); }
#line 3632 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"
    break;


#line 3636 "/home/dave/tools/ctools/gca-1.40/c-parse.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1310 "/home/dave/tools/ctools/gca-1.40/c-parse.y"


/* Return something to represent absolute declarators containing a *.
   TARGET is the absolute declarator that the * contains.
   TYPE_QUALS is a list of modifiers such as const or volatile
   to apply to the pointer type, represented as identifiers.

   We return an INDIRECT_REF whose "contents" are TARGET
   and whose type is the modifier list.  */

static tree
make_pointer_declarator (type_quals, target)
     tree type_quals, target;
{
  return build (INDIRECT_REF, type_quals, target);
}

/* Given a chain of STRING_CST nodes,
   concatenate them into one STRING_CST
   and give it a suitable array-of-chars data type.  */

static tree
combine_strings (strings)
     tree strings;
{
  register tree value, t;
  register int length = 1;
  int wide_length = 0;
  int wide_flag = 0;
  int nchars;

  if (TREE_CHAIN (strings))
    {
      /* More than one in the chain, so concatenate.  */
      register char *p, *q;

      /* Don't include the \0 at the end of each substring,
	 except for the last one.
	 Count wide strings and ordinary strings separately.  */
      for (t = strings; t; t = TREE_CHAIN (t))
	{
	  if (TREE_TYPE (t) == int_array_type_node)
	    {
	      wide_length += (TREE_STRING_LENGTH (t) - UNITS_PER_WORD);
	      wide_flag = 1;
	    }
	  else
	    length += (TREE_STRING_LENGTH (t) - 1);
	}

      /* If anything is wide, the non-wides will be converted,
	 which makes them take more space.  */
      if (wide_flag)
	length = length * UNITS_PER_WORD + wide_length;

      p = (char *) savealloc (length);

      /* Copy the individual strings into the new combined string.
	 If the combined string is wide, convert the chars to ints
	 for any individual strings that are not wide.  */

      q = p;
      for (t = strings; t; t = TREE_CHAIN (t))
	{
	  int len = (TREE_STRING_LENGTH (t) 
		     - ((TREE_TYPE (t) == int_array_type_node)
			? UNITS_PER_WORD : 1));
	  if ((TREE_TYPE (t) == int_array_type_node) == wide_flag)
	    {
	      bcopy (TREE_STRING_POINTER (t), q, len);
	      q += len;
	    }
	  else
	    {
	      int i;
	      for (i = 0; i < len; i++)
		((int *) q)[i] = TREE_STRING_POINTER (t)[i];
	      q += len * UNITS_PER_WORD;
	    }
	}
      if (wide_flag)
	{
	  int i;
	  for (i = 0; i < UNITS_PER_WORD; i++)
	    *q++ = 0;
	}
      else
	*q = 0;

      value = make_node (STRING_CST);
      TREE_STRING_POINTER (value) = p;
      TREE_STRING_LENGTH (value) = length;
      TREE_LITERAL (value) = 1;
    }
  else
    {
      value = strings;
      length = TREE_STRING_LENGTH (value);
      if (TREE_TYPE (value) == int_array_type_node)
	wide_flag = 1;
    }

  /* Compute the number of elements, for the array type.  */ 
  nchars = wide_flag ? length / UNITS_PER_WORD : length;

  /* Create the array type for the string constant.
     -Wwrite-strings says make the string constant an array of const char
     so that copying it to a non-const pointer will get a warning.  */
  if (warn_write_strings)
    {
      tree elements
	= build_type_variant (wide_flag ? integer_type_node : char_type_node,
			      1, 0);
      TREE_TYPE (value)
	= build_array_type (elements,
			    build_index_type (build_int_2 (nchars - 1, 0)));
    }
  else
    TREE_TYPE (value)
      = build_array_type (wide_flag ? integer_type_node : char_type_node,
			  build_index_type (build_int_2 (nchars - 1, 0)));
  TREE_LITERAL (value) = 1;
  TREE_STATIC (value) = 1;
  return value;
}

FILE *finput;			/* input file.
				   Normally a pipe from the preprocessor.  */

/* lexical analyzer */

static int maxtoken;		/* Current nominal length of token buffer.  */
static char *token_buffer;	/* Pointer to token buffer.
				   Actual allocated length is maxtoken + 2.  */
static int max_wide;		/* Current nominal length of wide_buffer.  */
static int *wide_buffer;	/* Pointer to wide-string buffer.
				   Actual allocated length is max_wide + 1.  */

/* Nonzero if end-of-file has been seen on input.  */
static int end_of_file;

/* Data type that represents the GNU C reserved words. */
struct resword { char *name; short token; enum rid rid; };

#define MIN_WORD_LENGTH     2      /* minimum size for C keyword */
#define MAX_WORD_LENGTH     13     /* maximum size for C keyword */
#define MIN_HASH_VALUE      7      /* range of the hash keys values  */
#define MAX_HASH_VALUE      91     /* for the perfect hash generator */
#define NORID RID_UNUSED

/* This function performs the minimum-perfect hash mapping from input
   string to reswords table index.  It only looks at the first and
   last characters in the string, thus assuring the O(1) lookup time
   (this keeps our constant down to an insignificant amount!).  Compiling
   the following 2 functions as inline removes all overhead of the
   function calls. */

#ifdef __GNUC__
__inline
#endif
static int
hash (str, len)
     register char *str;
     register int len;
{
/* This table is used to build the hash table index that recognizes
   reserved words in 0(1) steps.  It is larger than strictly necessary,
   but I'm trading off the space for the time-saving luxury of avoiding
   subtraction of an offset.  All those ``91's'' (actually just a
   short-hand for MAX_HASH_VALUE #defined above) are used to speed up
   the search when the string found on the input stream doesn't have a
   first or last character that is part of the set of alphabetic
   characters that comprise the first or last characters in C
   reserved words. */

  static int hash_table[] =
    {
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
     91, 91, 91, 91, 91,  1, 91,  2,  1, 32,
      7,  5, 18, 20,  1, 17, 91,  1, 18,  1,
     28,  1, 23, 91, 12, 20,  1, 41,  7, 15,
     91, 91, 10, 91, 91, 91, 91, 91,
    };
  register int hval = len ;

  switch (hval)
    {
      default:
      case 3:
        hval += hash_table[str[2]];
      case 2:
      case 1:
        return hval + hash_table[str[0]] + hash_table[str[len - 1]];
    }
}

/* This routine attempts to match the string found in the reswords table
   with the one from the input stream.  If all the relevant details
   match then an actual strcmp comparison is performed and the address of
   correct struct resword entry is returned.  Otherwise, a NULL
   pointer is returned. */

#ifdef __GNUC__
__inline
#endif
static struct resword *
is_reserved_word (str, len)
     register char *str;
     register int len;
{
  /* This is the hash table of keywords.
     The order of keywords has been chosen for perfect hashing.
     Therefore, this table cannot be updated by hand.
     Use the program ``gperf,'' available with the latest libg++
     distribution, to generate an updated table.  A file called
     c-parse.gperf, distributed with GNU C, contains the keyword file.  */

  static struct resword reswords[] =
    {
      { "", }, { "", }, { "", }, { "", }, { "", }, { "", }, { "", }, 
      {"asm",  ASM, NORID },
      {"auto",  SCSPEC, RID_AUTO },
      {"__asm",  ASM, NORID },
      {"do",  DO, NORID },
      {"__asm__",  ASM, NORID },
      {"break",  BREAK, NORID },
      {"__typeof__",  TYPEOF, NORID },
      { "", }, 
      {"__alignof__",  ALIGNOF, NORID },
      { "", }, 
      {"__attribute__",  ATTRIBUTE, NORID },
      { "", }, 
      {"__attribute",  ATTRIBUTE, NORID },
      { "", }, 
      {"__volatile__",  TYPE_QUAL, RID_VOLATILE },
      {"int",  TYPESPEC, RID_INT },
      {"__volatile",  TYPE_QUAL, RID_VOLATILE },
      { "", }, 
      {"float",  TYPESPEC, RID_FLOAT },
      {"goto",  GOTO, NORID },
      {"short",  TYPESPEC, RID_SHORT },
      {"__typeof",  TYPEOF, NORID },
      {"__inline__",  SCSPEC, RID_INLINE },
      {"__alignof",  ALIGNOF, NORID },
      {"__inline",  SCSPEC, RID_INLINE },
      {"__signed__",  TYPESPEC, RID_SIGNED },
      {"default",  DEFAULT, NORID },
      {"else",  ELSE, NORID },
      {"void",  TYPESPEC, RID_VOID },
      {"__signed",  TYPESPEC, RID_SIGNED },
      {"if",  IF, NORID },
      {"volatile",  TYPE_QUAL, RID_VOLATILE },
      {"struct",  STRUCT, NORID },
      {"extern",  SCSPEC, RID_EXTERN },
      {"__const",  TYPE_QUAL, RID_CONST },
      {"while",  WHILE, NORID },
      {"__const__",  TYPE_QUAL, RID_CONST },
      {"switch",  SWITCH, NORID },
      {"for",  FOR, NORID },
      {"inline",  SCSPEC, RID_INLINE },
      {"return",  RETURN, NORID },
      {"typeof",  TYPEOF, NORID },
      {"typedef",  SCSPEC, RID_TYPEDEF },
      {"char",  TYPESPEC, RID_CHAR },
      {"enum",  ENUM, NORID },
      {"register",  SCSPEC, RID_REGISTER },
      {"signed",  TYPESPEC, RID_SIGNED },
      {"sizeof",  SIZEOF, NORID },
      { "", }, { "", }, { "", }, { "", }, 
      {"double",  TYPESPEC, RID_DOUBLE },
      {"static",  SCSPEC, RID_STATIC },
      {"case",  CASE, NORID },
      { "", }, { "", }, { "", }, { "", }, 
      {"const",  TYPE_QUAL, RID_CONST },
      { "", }, { "", }, { "", }, 
      {"long",  TYPESPEC, RID_LONG },
      { "", }, { "", }, 
      {"continue",  CONTINUE, NORID },
      { "", }, { "", }, 
      {"unsigned",  TYPESPEC, RID_UNSIGNED },
      { "", }, { "", }, { "", }, { "", }, { "", }, { "", }, { "", }, { "", }, { "", }, 
      { "", }, { "", }, { "", }, { "", }, { "", }, 
      {"union",  UNION, NORID },
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register char *s = reswords[key].name;

          if (*s == *str && !strcmp (str + 1, s + 1))
            return &reswords[key];
        }
    }
  return 0;
}

/* The elements of `ridpointers' are identifier nodes
   for the reserved type names and storage classes.
   It is indexed by a RID_... value.  */

tree ridpointers[(int) RID_MAX];

int check_newline ();

void
init_lex ()
{
  /* Start it at 0, because check_newline is called at the very beginning
     and will increment it to 1.  */
  lineno = 0;

  maxtoken = 40;
  token_buffer = (char *) xmalloc (maxtoken + 2);
  max_wide = 40;
  wide_buffer = (int *) xmalloc ((max_wide + 1) * UNITS_PER_WORD);

  ridpointers[(int) RID_INT] = get_identifier ("int");
  ridpointers[(int) RID_CHAR] = get_identifier ("char");
  ridpointers[(int) RID_VOID] = get_identifier ("void");
  ridpointers[(int) RID_FLOAT] = get_identifier ("float");
  ridpointers[(int) RID_DOUBLE] = get_identifier ("double");
  ridpointers[(int) RID_SHORT] = get_identifier ("short");
  ridpointers[(int) RID_LONG] = get_identifier ("long");
  ridpointers[(int) RID_UNSIGNED] = get_identifier ("unsigned");
  ridpointers[(int) RID_SIGNED] = get_identifier ("signed");
  ridpointers[(int) RID_INLINE] = get_identifier ("inline");
  ridpointers[(int) RID_CONST] = get_identifier ("const");
  ridpointers[(int) RID_VOLATILE] = get_identifier ("volatile");
  ridpointers[(int) RID_AUTO] = get_identifier ("auto");
  ridpointers[(int) RID_STATIC] = get_identifier ("static");
  ridpointers[(int) RID_EXTERN] = get_identifier ("extern");
  ridpointers[(int) RID_TYPEDEF] = get_identifier ("typedef");
  ridpointers[(int) RID_REGISTER] = get_identifier ("register");
}

static void
reinit_parse_for_function ()
{
}

/* If C is not whitespace, return C.
   Otherwise skip whitespace and return first nonwhite char read.  */

static int
skip_white_space (c)
     register int c;
{
#if 0
  register int inside;
#endif

  for (;;)
    {
      switch (c)
	{
	  /* Don't recognize comments in cc1: all comments are removed by cpp,
	     and cpp output can include / and * consecutively as operators.  */
#if 0
	case '/':
	  c = getc (finput);
	  if (c != '*')
	    {
	      ungetc (c, finput);
	      return '/';
	    }

	  c = getc (finput);

	  inside = 1;
	  while (inside)
	    {
	      if (c == '*')
		{
		  while (c == '*')
		    c = getc (finput);

		  if (c == '/')
		    {
		      inside = 0;
		      c = getc (finput);
		    }
		}
	      else if (c == '\n')
		{
		  lineno++;
		  c = getc (finput);
		}
	      else if (c == EOF)
		{
		  error ("unterminated comment");
		  break;
		}
	      else
		c = getc (finput);
	    }

	  break;
#endif

	case '\n':
	  c = check_newline ();
	  break;

	case ' ':
	case '\t':
	case '\f':
	case '\r':
	case '\v':
	case '\b':
	  c = getc (finput);
	  break;

	case '\\':
	  c = getc (finput);
	  if (c == '\n')
	    lineno++;
	  else
	    error ("stray '\\' in program");
	  c = getc (finput);
	  break;

	default:
	  return (c);
	}
    }
}



/* Make the token buffer longer, preserving the data in it.
   P should point to just beyond the last valid character in the old buffer.
   The value we return is a pointer to the new buffer
   at a place corresponding to P.  */

static char *
extend_token_buffer (p)
     char *p;
{
  int offset = p - token_buffer;

  maxtoken = maxtoken * 2 + 10;
  token_buffer = (char *) xrealloc (token_buffer, maxtoken + 2);

  return token_buffer + offset;
}

/* At the beginning of a line, increment the line number
   and process any #-directive on this line.
   If the line is a #-directive, read the entire line and return a newline.
   Otherwise, return the line's first non-whitespace character.  */

int
check_newline ()
{
  register int c;
  register int token;

  lineno++;

  /* Read first nonwhite char on the line.  */

  c = getc (finput);
  while (c == ' ' || c == '\t')
    c = getc (finput);

  if (c != '#')
    {
      /* If not #, return it so caller will use it.  */
      return c;
    }

  /* Read first nonwhite char after the `#'.  */

  c = getc (finput);
  while (c == ' ' || c == '\t')
    c = getc (finput);

  /* If a letter follows, then if the word here is `line', skip
     it and ignore it; otherwise, ignore the line, with an error
     if the word isn't `pragma'.  */

  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      if (c == 'p')
	{
	  if (getc (finput) == 'r'
	      && getc (finput) == 'a'
	      && getc (finput) == 'g'
	      && getc (finput) == 'm'
	      && getc (finput) == 'a'
	      && ((c = getc (finput)) == ' ' || c == '\t' || c == '\n'))
#ifdef PRAGMA_PACK
	  {
		while ( c == ' ' || c == '\t' )
		  c = getc (finput);
		if ( c == '\n' )
		  return c;

		if ( c != 'p' 
		  || ( c = getc (finput)) != 'a'
		  || ( c = getc (finput)) != 'c'
		  || ( c = getc (finput)) != 'k' ) goto skipline;

		token = yylex();
  		if (token != '(') {
			error ("invalid #pragma pack expecting '('");
			goto skipline;
		}

		/* setup default alignment first */

		pragma_pack_default();

		token = yylex();
		if (token != ')')
		{
			if (token == CONSTANT
				&& TREE_CODE (yylval.ttype) == INTEGER_CST) {
				int l = TREE_INT_CST_LOW (yylval.ttype);
				pragma_pack(l);
			}
			else {
				error ("invalid #pragma pack expecting 1, 2 or 4");
				goto skipline;
			}

			token = yylex();
		}

  		if (token != ')') {
			error ("invalid #pragma pack expecting ')'");
			goto skipline;
		}
	    }
#endif
	    goto skipline;
	}

      else if (c == 'l')
	{
	  if (getc (finput) == 'i'
	      && getc (finput) == 'n'
	      && getc (finput) == 'e'
	      && ((c = getc (finput)) == ' ' || c == '\t'))
	    goto linenum;
	}
      else if (c == 'i')
	{
	  if (getc (finput) == 'd'
	      && getc (finput) == 'e'
	      && getc (finput) == 'n'
	      && getc (finput) == 't'
	      && ((c = getc (finput)) == ' ' || c == '\t'))
	    {
	      extern FILE *asm_out_file;

	      if (pedantic)
		error ("ANSI C does not allow #ident");

	      /* Here we have just seen `#ident '.
		 A string constant should follow.  */

	      while (c == ' ' || c == '\t')
		c = getc (finput);

	      /* If no argument, ignore the line.  */
	      if (c == '\n')
		return c;

	      ungetc (c, finput);
	      token = yylex ();
	      if (token != STRING
		  || TREE_CODE (yylval.ttype) != STRING_CST)
		{
		  error ("invalid #ident");
		  goto skipline;
		}

#ifdef ASM_OUTPUT_IDENT
	      ASM_OUTPUT_IDENT (asm_out_file, TREE_STRING_POINTER (yylval.ttype));
#endif

	      /* Skip the rest of this line.  */
	      goto skipline;
	    }
	}

      error ("undefined or invalid # directive");
      goto skipline;
    }

linenum:
  /* Here we have either `#line' or `# <nonletter>'.
     In either case, it should be a line number; a digit should follow.  */

  while (c == ' ' || c == '\t')
    c = getc (finput);

  /* If the # is the only nonwhite char on the line,
     just ignore it.  Check the new newline.  */
  if (c == '\n')
    return c;

  /* Something follows the #; read a token.  */

  ungetc (c, finput);
  token = yylex ();

  if (token == CONSTANT
      && TREE_CODE (yylval.ttype) == INTEGER_CST)
    {
      int old_lineno = lineno;
      /* subtract one, because it is the following line that
	 gets the specified number */

      int l = TREE_INT_CST_LOW (yylval.ttype) - 1;

      /* Is this the last nonwhite stuff on the line?  */
      c = getc (finput);
      while (c == ' ' || c == '\t')
	c = getc (finput);
      if (c == '\n')
	{
	  /* No more: store the line number and check following line.  */
	  lineno = l;
	  return c;
	}
      ungetc (c, finput);

      /* More follows: it must be a string constant (filename).  */

      token = yylex ();
      if (token != STRING || TREE_CODE (yylval.ttype) != STRING_CST)
	{
	  error ("invalid #line");
	  goto skipline;
	}

      input_filename
	= (char *) permalloc (TREE_STRING_LENGTH (yylval.ttype) + 1);
      strcpy (input_filename, TREE_STRING_POINTER (yylval.ttype));
      lineno = l;

      if (main_input_filename == 0)
	main_input_filename = input_filename;

      /* Is this the last nonwhite stuff on the line?  */
      c = getc (finput);
      while (c == ' ' || c == '\t')
	c = getc (finput);
      if (c == '\n')
	return c;
      ungetc (c, finput);

      token = yylex ();

      /* `1' after file name means entering new file.
	 `2' after file name means just left a file.  */

      if (token == CONSTANT
	  && TREE_CODE (yylval.ttype) == INTEGER_CST)
	{
	  if (TREE_INT_CST_LOW (yylval.ttype) == 1)
	    {
	      struct file_stack *p
		= (struct file_stack *) xmalloc (sizeof (struct file_stack));
	      input_file_stack->line = old_lineno;
	      p->next = input_file_stack;
	      p->name = input_filename;
	      input_file_stack = p;
	      input_file_stack_tick++;
	    }
	  else if (input_file_stack->next)
	    {
	      struct file_stack *p = input_file_stack;
	      input_file_stack = p->next;
	      free (p);
	      input_file_stack_tick++;
	    }
	  else
	    error ("#-lines for entering and leaving files don't match");
	}
    }
  else
    error ("invalid #-line");

  /* skip the rest of this line.  */
 skipline:
  if (c == '\n')
    return c;
  while ((c = getc (finput)) != EOF && c != '\n');
  return c;
}

#define isalnum(char) ((char >= 'a' && char <= 'z') || (char >= 'A' && char <= 'Z') || (char >= '0' && char <= '9'))
#define isdigit(char) (char >= '0' && char <= '9')
#define ENDFILE -1  /* token that represents end-of-file */


static int
readescape ()
{
  register int c = getc (finput);
  register int count, code;
  int firstdig;

  switch (c)
    {
    case 'x':
      code = 0;
      count = 0;
      while (1)
	{
	  c = getc (finput);
	  if (!(c >= 'a' && c <= 'f')
	      && !(c >= 'A' && c <= 'F')
	      && !(c >= '0' && c <= '9'))
	    {
	      ungetc (c, finput);
	      break;
	    }
	  code *= 16;
	  if (c >= 'a' && c <= 'f')
	    code += c - 'a' + 10;
	  if (c >= 'A' && c <= 'F')
	    code += c - 'A' + 10;
	  if (c >= '0' && c <= '9')
	    code += c - '0';
	  if (count == 0)
	    firstdig = code;
	  count++;
	}
      if (count == 0)
	error ("\\x used with no following hex digits");
      else if ((count - 1) * 4 >= TYPE_PRECISION (integer_type_node)
	       || (count > 1
		   && ((1 << (TYPE_PRECISION (integer_type_node) - (count - 1) * 4))
		       <= firstdig)))
	warning ("hex escape out of range");
      return code;

    case '0':  case '1':  case '2':  case '3':  case '4':
    case '5':  case '6':  case '7':
      code = 0;
      count = 0;
      while ((c <= '7') && (c >= '0') && (count++ < 3))
	{
	  code = (code * 8) + (c - '0');
	  c = getc (finput);
	}
      ungetc (c, finput);
      return code;

    case '\\': case '\'': case '"':
      return c;

    case '\n':
      lineno++;
      return -1;

    case 'n':
      return TARGET_NEWLINE;

    case 't':
      return TARGET_TAB;

    case 'r':
      return TARGET_CR;

    case 'f':
      return TARGET_FF;

    case 'b':
      return TARGET_BS;

    case 'a':
      return TARGET_BELL;

    case 'v':
      return TARGET_VT;

    case 'E':
      return 033;

    case '?':
      /* `\(', etc, are used at beginning of line to avoid confusing Emacs.  */
    case '(':
    case '{':
    case '[':
      return c;
    }
  if (c >= 040 && c <= 0177)
    warning ("unknown escape sequence `\\%c'", c);
  else
    warning ("unknown escape sequence: `\\' followed by char code 0x%x", c);
  return c;
}

void
yyerror (string)
     char *string;
{
  char buf[200];

  strcpy (buf, string);

  /* We can't print string and character constants well
     because the token_buffer contains the result of processing escapes.  */
  if (end_of_file)
    strcat (buf, " at end of input");
  else if (token_buffer[0] == 0)
    strcat (buf, " at null character");
  else if (token_buffer[0] == '"')
    strcat (buf, " before string constant");
  else if (token_buffer[0] == '\'')
    strcat (buf, " before character constant");
  else if (token_buffer[0] < 040 || token_buffer[0] >= 0177)
    sprintf (buf + strlen (buf), " before character 0%o", token_buffer[0]);
  else
    strcat (buf, " before `%s'");

  error (buf, token_buffer);
}

static int nextchar = -1;

static int
yylex ()
{
  register int c;
  register char *p;
  register int value;
  int wide_flag = 0;

  if (nextchar >= 0)
    c = nextchar, nextchar = -1;
  else
    c = getc (finput);

  /* Effectively do c = skip_white_space (c)
     but do it faster in the usual cases.  */
  while (1)
    switch (c)
      {
      case ' ':
      case '\t':
      case '\f':
      case '\r':
      case '\v':
      case '\b':
	c = getc (finput);
	break;

      case '\n':
      case '/':
      case '\\':
	c = skip_white_space (c);
      default:
	goto found_nonwhite;
      }
 found_nonwhite:

  token_buffer[0] = c;
  token_buffer[1] = 0;

/*  yylloc.first_line = lineno; */

  switch (c)
    {
    case EOF:
      end_of_file = 1;
      token_buffer[0] = 0;
      value = ENDFILE;
      break;

    case '$':
      if (dollars_in_ident)
	goto letter;
      return '$';

    case 'L':
      /* Capital L may start a wide-string or wide-character constant.  */
      {
	register int c = getc (finput);
	if (c == '\'')
	  {
	    wide_flag = 1;
	    goto char_constant;
	  }
	if (c == '"')
	  {
	    wide_flag = 1;
	    goto string_constant;
	  }
	ungetc (c, finput);
      }

    case 'A':  case 'B':  case 'C':  case 'D':  case 'E':
    case 'F':  case 'G':  case 'H':  case 'I':  case 'J':
    case 'K':		  case 'M':  case 'N':  case 'O':
    case 'P':  case 'Q':  case 'R':  case 'S':  case 'T':
    case 'U':  case 'V':  case 'W':  case 'X':  case 'Y':
    case 'Z':
    case 'a':  case 'b':  case 'c':  case 'd':  case 'e':
    case 'f':  case 'g':  case 'h':  case 'i':  case 'j':
    case 'k':  case 'l':  case 'm':  case 'n':  case 'o':
    case 'p':  case 'q':  case 'r':  case 's':  case 't':
    case 'u':  case 'v':  case 'w':  case 'x':  case 'y':
    case 'z':
    case '_':
    letter:
      p = token_buffer;
      while (isalnum (c) || c == '_' || c == '$')
	{
	  if (p >= token_buffer + maxtoken)
	    p = extend_token_buffer (p);
	  if (c == '$' && ! dollars_in_ident)
	    break;

	  *p++ = c;
	  c = getc (finput);
	}

      *p = 0;
      nextchar = c;

      value = IDENTIFIER;
      yylval.itype = 0;

      /* Try to recognize a keyword.  Uses minimum-perfect hash function */

      {
	register struct resword *ptr;

	if (ptr = is_reserved_word (token_buffer, p - token_buffer))
	  {
	    if (ptr->rid)
	      yylval.ttype = ridpointers[(int) ptr->rid];
	    if ((! flag_no_asm
		 /* -fno-asm means don't recognize the non-ANSI keywords.  */
		 || ((int) ptr->token != ASM
		     && (int) ptr->token != TYPEOF
		     && ptr->rid != RID_INLINE)
		 /* Recognize __asm and __inline despite -fno-asm.  */
		 || token_buffer[0] == '_')
		/* -ftraditional means don't recognize nontraditional keywords
		   typeof, const, volatile, signed or inline.  */
		&& (! flag_traditional
		    || ((int) ptr->token != TYPE_QUAL
			&& (int) ptr->token != TYPEOF
			&& ptr->rid != RID_SIGNED
			&& ptr->rid != RID_INLINE)
		    /* Recognize __inline, etc. despite -ftraditional.  */
		    || token_buffer[0] == '_'))
	      value = (int) ptr->token;
	  }
      }

      /* If we did not find a keyword, look for an identifier
	 (or a typename).  */

      if (value == IDENTIFIER)
	{
          yylval.ttype = get_identifier (token_buffer);
	  lastiddecl = lookup_name (yylval.ttype);

	  if (lastiddecl != 0 && TREE_CODE (lastiddecl) == TYPE_DECL)
	    value = TYPENAME;
	}

      break;

    case '0':  case '1':  case '2':  case '3':  case '4':
    case '5':  case '6':  case '7':  case '8':  case '9':
    case '.':
      {
	int base = 10;
	int count = 0;
	int largest_digit = 0;
	int numdigits = 0;
	/* for multi-precision arithmetic,
	   we store only 8 live bits in each short,
	   giving us 64 bits of reliable precision */
	short shorts[8];
	int overflow = 0;

	enum anon1 { NOT_FLOAT, AFTER_POINT, TOO_MANY_POINTS} floatflag
	  = NOT_FLOAT;

	for (count = 0; count < 8; count++)
	  shorts[count] = 0;

	p = token_buffer;
	*p++ = c;

	if (c == '0')
	  {
	    *p++ = (c = getc (finput));
	    if ((c == 'x') || (c == 'X'))
	      {
		base = 16;
		*p++ = (c = getc (finput));
	      }
	    else
	      {
		base = 8;
		numdigits++;
	      }
	  }

	/* Read all the digits-and-decimal-points.  */

	while (c == '.'
	       || (isalnum (c) && (c != 'l') && (c != 'L')
		   && (c != 'u') && (c != 'U')
		   && (floatflag == NOT_FLOAT || ((c != 'f') && (c != 'F')))))
	  {
	    if (c == '.')
	      {
		if (base == 16)
		  error ("floating constant may not be in radix 16");
		if (floatflag == AFTER_POINT)
		  {
		    error ("malformed floating constant");
		    floatflag = TOO_MANY_POINTS;
		  }
		else
		  floatflag = AFTER_POINT;

		base = 10;
		*p++ = c = getc (finput);
		/* Accept '.' as the start of a floating-point number
		   only when it is followed by a digit.
		   Otherwise, unread the following non-digit
		   and use the '.' as a structural token.  */
		if (p == token_buffer + 2 && !isdigit (c))
		  {
		    if (c == '.')
		      {
			c = getc (finput);
			if (c == '.')
			  {
			    *p++ = c;
			    *p = 0;
			    return ELLIPSIS;
			  }
			error ("parse error at `..'");
		      }
		    ungetc (c, finput);
		    token_buffer[1] = 0;
		    value = '.';
		    goto done;
		  }
	      }
	    else
	      {
		/* It is not a decimal point.
		   It should be a digit (perhaps a hex digit).  */

		if (isdigit (c))
		  {
		    c = c - '0';
		  }
		else if (base <= 10)
		  {
		    if ((c&~040) == 'E')
		      {
			base = 10;
			floatflag = AFTER_POINT;
			break;   /* start of exponent */
		      }
		    error ("nondigits in number and not hexadecimal");
		    c = 0;
		  }
		else if (c >= 'a')
		  {
		    c = c - 'a' + 10;
		  }
		else
		  {
		    c = c - 'A' + 10;
		  }
		if (c >= largest_digit)
		  largest_digit = c;
		numdigits++;

		for (count = 0; count < 8; count++)
		  {
		    shorts[count] *= base;
		    if (count)
		      {
			shorts[count] += (shorts[count-1] >> 8);
			shorts[count-1] &= (1<<8)-1;
		      }
		    else shorts[0] += c;
		  }

		if (shorts[7] >= 1<<8
		    || shorts[7] < - (1 << 8))
		  overflow = TRUE;

		if (p >= token_buffer + maxtoken - 3)
		  p = extend_token_buffer (p);
		*p++ = (c = getc (finput));
	      }
	  }

	if (numdigits == 0)
	  error ("numeric constant with no digits");

	if (largest_digit >= base)
	  error ("numeric constant contains digits beyond the radix");

	/* Remove terminating char from the token buffer and delimit the string */
	*--p = 0;

	if (floatflag != NOT_FLOAT)
	  {
	    tree type = double_type_node;
	    char f_seen = 0;
	    char l_seen = 0;
	    REAL_VALUE_TYPE value;

	    /* Read explicit exponent if any, and put it in tokenbuf.  */

	    if ((c == 'e') || (c == 'E'))
	      {
		if (p >= token_buffer + maxtoken - 3)
		  p = extend_token_buffer (p);
		*p++ = c;
		c = getc (finput);
		if ((c == '+') || (c == '-'))
		  {
		    *p++ = c;
		    c = getc (finput);
		  }
		if (! isdigit (c))
		  error ("floating constant exponent has no digits");
	        while (isdigit (c))
		  {
		    if (p >= token_buffer + maxtoken - 3)
		      p = extend_token_buffer (p);
		    *p++ = c;
		    c = getc (finput);
		  }
	      }

	    *p = 0;
	    errno = 0;
	    value = REAL_VALUE_ATOF (token_buffer);
#ifdef ERANGE
	    if (errno == ERANGE && !flag_traditional)
	      {
		char *p1 = token_buffer;
		/* Check for "0.0" and variants;
		   Sunos 4 spuriously returns ERANGE for them.  */
		while (*p1 == '0') p1++;
		if (*p1 == '.')
		  {
		    p1++;
		    while (*p1 == '0') p1++;
		  }
		if (*p1 == 'e' || *p1 == 'E')
		  {
		    /* with significand==0, ignore the exponent */
		    p1++;
		    while (*p1 != 0) p1++;
		  }
		/* ERANGE is also reported for underflow,
		   so test the value to distinguish overflow from that.  */
		if (*p1 != 0 && (value > 1.0 || value < -1.0))
		  warning ("floating point number exceeds range of `double'");
	      }
#endif

	    /* Read the suffixes to choose a data type.  */
	    while (1)
	      {
		if (c == 'f' || c == 'F')
		  {
		    float floater;
		    if (f_seen)
		      error ("two `f's in floating constant");
		    f_seen = 1;
		    type = float_type_node;
		    floater = value;
		    value = floater;
		  }
		else if (c == 'l' || c == 'L')
		  {
		    if (l_seen)
		      error ("two `l's in floating constant");
		    l_seen = 1;
		    type = long_double_type_node;
		  }
		else
		  {
		    if (isalnum (c))
		      {
			error ("garbage at end of number");
			while (isalnum (c))
			  {
			    if (p >= token_buffer + maxtoken - 3)
			      p = extend_token_buffer (p);
			    *p++ = c;
			    c = getc (finput);
			  }
		      }
		    break;
		  }
		if (p >= token_buffer + maxtoken - 3)
		  p = extend_token_buffer (p);
		*p++ = c;
		c = getc (finput);
	      }

	    /* Create a node with determined type and value.  */
	    yylval.ttype = build_real (type, value);

	    ungetc (c, finput);
	    *p = 0;
	  }
	else
	  {
	    tree type;
	    int spec_unsigned = 0;
	    int spec_long = 0;
	    int spec_long_long = 0;

	    while (1)
	      {
		if (c == 'u' || c == 'U')
		  {
		    if (spec_unsigned)
		      error ("two `u's in integer constant");
		    spec_unsigned = 1;
		  }
		else if (c == 'l' || c == 'L')
		  {
		    if (spec_long)
		      {
			if (spec_long_long)
			  error ("three `l's in integer constant");
			else if (pedantic)
			  warning ("ANSI C forbids long long integer constants");
			spec_long_long = 1;
		      }
		    spec_long = 1;
		  }
		else
		  {
		    if (isalnum (c))
		      {
			error ("garbage at end of number");
			while (isalnum (c))
			  {
			    if (p >= token_buffer + maxtoken - 3)
			      p = extend_token_buffer (p);
			    *p++ = c;
			    c = getc (finput);
			  }
		      }
		    break;
		  }
		if (p >= token_buffer + maxtoken - 3)
		  p = extend_token_buffer (p);
		*p++ = c;
		c = getc (finput);
	      }

	    ungetc (c, finput);

	    if ((overflow || shorts[7] || shorts[6] || shorts[5] || shorts[4])
		&& !spec_long_long)
	      warning ("integer constant out of range");

	    /* If it won't fit in a signed long long, make it unsigned.
	       We can't distinguish based on the tree node because
	       any integer constant fits any long long type.  */
	    if (shorts[7] >= (1<<8))
	      spec_unsigned = 1;

	    /* This is simplified by the fact that our constant
	       is always positive.  */
	    yylval.ttype
	      = (build_int_2
		 ((shorts[3]<<24) + (shorts[2]<<16) + (shorts[1]<<8) + shorts[0],
		  (spec_long_long
		   ? (shorts[7]<<24) + (shorts[6]<<16) + (shorts[5]<<8) + shorts[4]
		   : 0)));

	    if (!spec_long && !spec_unsigned
		&& int_fits_type_p (yylval.ttype, integer_type_node))
	      type = integer_type_node;

	    else if (!spec_long && (base != 10 || spec_unsigned)
		     && int_fits_type_p (yylval.ttype, unsigned_type_node))
	      type = unsigned_type_node;

	    else if (!spec_unsigned && !spec_long_long
		     && int_fits_type_p (yylval.ttype, long_integer_type_node))
	      type = long_integer_type_node;

	    else if (! spec_long_long
		     && int_fits_type_p (yylval.ttype,
					 long_unsigned_type_node))
	      type = long_unsigned_type_node;

	    else if (! spec_unsigned
		     && int_fits_type_p (yylval.ttype,
					 long_long_integer_type_node))
	      type = long_long_integer_type_node;

	    else if (int_fits_type_p (yylval.ttype,
				      long_long_unsigned_type_node))
	      type = long_long_unsigned_type_node;

	    else
	      {
		type = long_long_integer_type_node;
		warning ("integer constant out of range");
	      }

	    TREE_TYPE (yylval.ttype) = type;
	    *p = 0;
	  }

	value = CONSTANT; break;
      }

    case '\'':
    char_constant:
      {
	register int result = 0;
	register int num_chars = 0;
	int width = TYPE_PRECISION (char_type_node);
	int max_chars;

	if (wide_flag) width = TYPE_PRECISION (integer_type_node);

	max_chars = TYPE_PRECISION (integer_type_node) / width;

	while (1)
	  {
	  tryagain:

	    c = getc (finput);

	    if (c == '\'' || c == EOF)
	      break;

	    if (c == '\\')
	      {
		c = readescape ();
		if (c < 0)
		  goto tryagain;
		if (width < HOST_BITS_PER_INT
		    && (unsigned) c >= (1 << width))
		  warning ("escape sequence out of range for character");
	      }
	    else if (c == '\n')
	      {
		if (pedantic)
		  warning ("ANSI C forbids newline in character constant");
		lineno++;
	      }

	    num_chars++;
	    if (num_chars > maxtoken - 4)
	      extend_token_buffer (token_buffer);

	    token_buffer[num_chars] = c;

	    /* Merge character into result; ignore excess chars.  */
	    if (num_chars < max_chars + 1)
	      {
		if (width < HOST_BITS_PER_INT)
		  result = (result << width) | (c & ((1 << width) - 1));
		else
		  result = c;
	      }
	  }

	token_buffer[num_chars + 1] = '\'';
	token_buffer[num_chars + 2] = 0;

	if (c != '\'')
	  error ("malformatted character constant");
	else if (num_chars == 0)
	  error ("empty character constant");
	else if (num_chars > max_chars)
	  {
	    num_chars = max_chars;
	    error ("character constant too long");
	  }
	else if (num_chars != 1 && ! flag_traditional)
	  warning ("multi-character character constant");

	/* If char type is signed, sign-extend the constant.  */
	if (! wide_flag)
	  {
	    int num_bits = num_chars * width;
	    if (TREE_UNSIGNED (char_type_node)
		|| ((result >> (num_bits - 1)) & 1) == 0)
	      yylval.ttype
		= build_int_2 (result & ((unsigned) ~0
					 >> (HOST_BITS_PER_INT - num_bits)),
			       0);
	    else
	      yylval.ttype
		= build_int_2 (result | ~((unsigned) ~0
					  >> (HOST_BITS_PER_INT - num_bits)),
			       -1);
	  }
	else
	  yylval.ttype = build_int_2 (result, 0);

	TREE_TYPE (yylval.ttype) = integer_type_node;
	value = CONSTANT; break;
      }

    case '"':
    string_constant:
      {
	int *widep;

	c = getc (finput);
	p = token_buffer + 1;

	if (wide_flag)
	  widep = wide_buffer;

	while (c != '"' && c >= 0)
	  {
	    if (c == '\\')
	      {
		c = readescape ();
		if (c < 0)
		  goto skipnewline;
		if (!wide_flag && c >= (1 << TYPE_PRECISION (char_type_node)))
		  warning ("escape sequence out of range for character");
	      }
	    else if (c == '\n')
	      {
		if (pedantic)
		  warning ("ANSI C forbids newline in string constant");
		lineno++;
	      }

	    /* Store the char in C into the appropriate buffer.  */

	    if (wide_flag)
	      {
		if (widep == wide_buffer + max_wide)
		  {
		    int n = widep - wide_buffer;
		    max_wide *= 2;
		    wide_buffer
		      = (int *) xrealloc (wide_buffer,
					  (max_wide + 1) * UNITS_PER_WORD);
		    widep = wide_buffer + n;
		  }
		*widep++ = c;
	      }
	    else
	      {
		if (p == token_buffer + maxtoken)
		  p = extend_token_buffer (p);
		*p++ = c;
	      }

	  skipnewline:
	    c = getc (finput);
	  }

	/* We have read the entire constant.
	   Construct a STRING_CST for the result.  */

	if (wide_flag)
	  {
	    /* If this is a L"..." wide-string, make a vector
	       of the ints in wide_buffer.  */
	    *widep = 0;
	    /* We have not implemented the case where `int'
	       on the target and on the execution machine differ in size.  */
	    if (TYPE_PRECISION (integer_type_node)
		!= sizeof (int) * BITS_PER_UNIT)
	      abort ();
	    yylval.ttype
	      = build_string ((widep - wide_buffer + 1) * sizeof (int),
			      (char *)wide_buffer);
	    TREE_TYPE (yylval.ttype) = int_array_type_node;
	  }
	else
	  {
	    *p = 0;
	    yylval.ttype = build_string (p - token_buffer, token_buffer + 1);
	    TREE_TYPE (yylval.ttype) = char_array_type_node;
	  }

	*p++ = '"';
	*p = 0;

	value = STRING; break;
      }

    case '+':
    case '-':
    case '&':
    case '|':
    case '<':
    case '>':
    case '*':
    case '/':
    case '%':
    case '^':
    case '!':
    case '=':
      {
	register int c1;

      combine:

	switch (c)
	  {
	  case '+':
	    yylval.code = PLUS_EXPR; break;
	  case '-':
	    yylval.code = MINUS_EXPR; break;
	  case '&':
	    yylval.code = BIT_AND_EXPR; break;
	  case '|':
	    yylval.code = BIT_IOR_EXPR; break;
	  case '*':
	    yylval.code = MULT_EXPR; break;
	  case '/':
	    yylval.code = TRUNC_DIV_EXPR; break;
	  case '%':
	    yylval.code = TRUNC_MOD_EXPR; break;
	  case '^':
	    yylval.code = BIT_XOR_EXPR; break;
	  case LSHIFT:
	    yylval.code = LSHIFT_EXPR; break;
	  case RSHIFT:
	    yylval.code = RSHIFT_EXPR; break;
	  case '<':
	    yylval.code = LT_EXPR; break;
	  case '>':
	    yylval.code = GT_EXPR; break;
	  }

	token_buffer[1] = c1 = getc (finput);
	token_buffer[2] = 0;

	if (c1 == '=')
	  {
	    switch (c)
	      {
	      case '<':
		value = ARITHCOMPARE; yylval.code = LE_EXPR; goto done;
	      case '>':
		value = ARITHCOMPARE; yylval.code = GE_EXPR; goto done;
	      case '!':
		value = EQCOMPARE; yylval.code = NE_EXPR; goto done;
	      case '=':
		value = EQCOMPARE; yylval.code = EQ_EXPR; goto done;
	      }
	    value = ASSIGN; goto done;
	  }
	else if (c == c1)
	  switch (c)
	    {
	    case '+':
	      value = PLUSPLUS; goto done;
	    case '-':
	      value = MINUSMINUS; goto done;
	    case '&':
	      value = ANDAND; goto done;
	    case '|':
	      value = OROR; goto done;
	    case '<':
	      c = LSHIFT;
	      goto combine;
	    case '>':
	      c = RSHIFT;
	      goto combine;
	    }
	else if ((c == '-') && (c1 == '>'))
	  { value = POINTSAT; goto done; }
	ungetc (c1, finput);
	token_buffer[1] = 0;

	if ((c == '<') || (c == '>'))
	  value = ARITHCOMPARE;
	else value = c;
	goto done;
      }

    case 0:
      /* Don't make yyparse think this is eof.  */
      value = 1;
      break;

    default:
      value = c;
    }

done:
/*  yylloc.last_line = lineno; */

  return value;
}

