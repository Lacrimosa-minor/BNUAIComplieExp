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
#line 1 "csubsub_bison.y"

	#include<stdio.h>
	#include"lex.yy.c"
	#include"syntax_tree.h"
	// #include "syntax_tree.c"

#line 78 "csubsub_bison.tab.c"

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

#include "csubsub_bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRUCT = 3,                     /* STRUCT  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_TYPE = 10,                      /* TYPE  */
  YYSYMBOL_SEMI = 11,                      /* SEMI  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_ASSIGNOP = 13,                  /* ASSIGNOP  */
  YYSYMBOL_RELOP = 14,                     /* RELOP  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_STAR = 17,                      /* STAR  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_DOT = 21,                       /* DOT  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_LP = 23,                        /* LP  */
  YYSYMBOL_RP = 24,                        /* RP  */
  YYSYMBOL_LB = 25,                        /* LB  */
  YYSYMBOL_RB = 26,                        /* RB  */
  YYSYMBOL_LC = 27,                        /* LC  */
  YYSYMBOL_RC = 28,                        /* RC  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 30,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_Program = 32,                   /* Program  */
  YYSYMBOL_ExtDefList = 33,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 34,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 35,                /* ExtDecList  */
  YYSYMBOL_Specifier = 36,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 37,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 38,                    /* OptTag  */
  YYSYMBOL_Tag = 39,                       /* Tag  */
  YYSYMBOL_VarDec = 40,                    /* VarDec  */
  YYSYMBOL_FunDec = 41,                    /* FunDec  */
  YYSYMBOL_VarList = 42,                   /* VarList  */
  YYSYMBOL_ParamDec = 43,                  /* ParamDec  */
  YYSYMBOL_InnerCompSt = 44,               /* InnerCompSt  */
  YYSYMBOL_CompSt = 45,                    /* CompSt  */
  YYSYMBOL_Stmt = 46,                      /* Stmt  */
  YYSYMBOL_DefList = 47,                   /* DefList  */
  YYSYMBOL_Def = 48,                       /* Def  */
  YYSYMBOL_DecList = 49,                   /* DecList  */
  YYSYMBOL_Dec = 50,                       /* Dec  */
  YYSYMBOL_Exp = 51,                       /* Exp  */
  YYSYMBOL_Args = 52                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int8 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    53,    55,    57,    60,    62,    65,    67,
      68,    75,    76,    78,    83,    87,    88,    90,    94,    95,
      99,   103,   105,   109,   112,   114,   117,   119,   124,   126,
     128,   132,   140,   141,   142,   145,   150,   157,   162,   165,
     167,   169,   173,   174,   178,   179,   186,   189,   192,   195,
     198,   201,   204,   207,   210,   213,   215,   217,   221,   224,
     228,   231,   232,   233,   236,   239
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
  "\"end of file\"", "error", "\"invalid token\"", "STRUCT", "RETURN",
  "IF", "ELSE", "WHILE", "FLOAT", "INT", "TYPE", "SEMI", "COMMA",
  "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT",
  "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "ID", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "InnerCompSt", "CompSt", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   -41,    -2,   -41,    20,   -41,    18,     0,   -41,     6,
      44,   -41,   -41,   -41,    49,   -41,    54,    69,    -9,    59,
      12,     7,   -41,     3,     5,    45,   -41,     3,    60,    12,
     -41,     3,    63,    77,   -41,   -41,   -41,    65,    67,   -41,
      86,    81,    83,   -41,   -41,    86,    86,    86,    84,    82,
     -41,    45,    45,   103,    -1,   100,   101,   -41,   -41,    87,
     -41,    12,   -41,   -41,   116,    86,    86,   222,    22,   157,
      76,   -41,   -41,   -41,   -41,    86,    86,    86,    86,    86,
      86,    86,    86,    96,    86,    86,   -41,     3,   -41,   -41,
     170,   183,   -41,   -41,   130,   102,   196,    41,   222,   222,
      22,    22,   220,   208,   -41,   143,   196,   -41,    74,    74,
      86,   -41,   -41,   132,   -41,   -41,    74,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     8,    16,    11,     0,     2,     0,     0,    12,    17,
       0,    14,     1,     3,    21,     6,    18,     0,     9,     0,
      40,     0,     5,     0,     0,     0,     7,     0,     0,    40,
      23,     0,     0,    26,    21,    18,    10,     0,     0,    38,
       0,     0,     0,    63,    62,     0,     0,     0,    61,     0,
      33,     0,     0,     0,    44,     0,    42,    13,    39,    27,
      22,     0,    19,    20,     0,     0,     0,    55,    56,     0,
       0,    31,    29,    28,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    25,    34,
       0,     0,    54,    58,    65,     0,    46,    49,    50,    51,
      52,    53,    47,    48,    60,     0,    45,    43,     0,     0,
       0,    57,    59,    35,    37,    64,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   133,   -41,   117,     2,   -41,   -41,   -41,   -18,
     -41,    91,   -41,    13,   134,   140,   125,    31,    78,   -41,
     -40,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    17,    27,     8,    10,    11,    18,
      19,    32,    33,    49,    50,    51,    28,    52,    55,    56,
      53,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    14,     7,    23,    34,    67,    68,    69,     7,    54,
       2,    15,    85,    59,    37,     2,    24,     3,    -4,     1,
      12,     2,     3,    31,    24,    90,    91,     9,     3,    16,
      94,    30,    35,   -15,    38,    96,    97,    98,    99,   100,
     101,   102,   103,    83,   105,   106,    39,    84,     2,    40,
      41,    29,    42,    43,    44,     3,    77,    78,    79,    80,
      29,    45,    83,    31,    72,    73,    84,    46,    47,    54,
      94,    20,    25,   -30,    48,    39,   -24,    21,    40,    41,
      22,    42,    43,    44,    43,    44,    25,    60,    57,    61,
      45,    62,    45,    63,    43,    44,    46,    47,    46,    47,
      93,    25,    45,    48,    65,    48,    66,    70,    46,    47,
      71,    86,    24,    87,    74,    48,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   104,   111,    89,    84,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   116,    13,
      36,    84,   110,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    88,    26,    58,    84,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   107,   115,     0,    84,   112,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,    92,    84,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,   108,    84,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,   109,    84,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,    84,    76,    77,    78,    79,    80,    81,     0,    83,
       0,     0,     0,    84,    76,    77,    78,    79,    80,    79,
      80,    83,     0,    83,     0,    84,     0,    84,   113,   114,
       0,     0,     0,     0,     0,     0,   117
};

static const yytype_int8 yycheck[] =
{
      40,     1,     0,    12,     1,    45,    46,    47,     6,    27,
       3,    11,    13,    31,     9,     3,    25,    10,     0,     1,
       0,     3,    10,    21,    25,    65,    66,    29,    10,    29,
      70,    24,    29,    27,    29,    75,    76,    77,    78,    79,
      80,    81,    82,    21,    84,    85,     1,    25,     3,     4,
       5,    20,     7,     8,     9,    10,    15,    16,    17,    18,
      29,    16,    21,    61,    51,    52,    25,    22,    23,    87,
     110,    27,    27,    28,    29,     1,    27,    23,     4,     5,
      11,     7,     8,     9,     8,     9,    27,    24,    28,    12,
      16,    26,    16,    26,     8,     9,    22,    23,    22,    23,
      24,    27,    16,    29,    23,    29,    23,    23,    22,    23,
      28,    11,    25,    12,    11,    29,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    29,    24,    11,    25,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     6,     6,
      23,    25,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    61,    19,    29,    25,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    87,   110,    -1,    25,    26,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    -1,    25,    14,    15,    16,    17,    18,    17,
      18,    21,    -1,    21,    -1,    25,    -1,    25,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    10,    32,    33,    34,    36,    37,    29,
      38,    39,     0,    33,     1,    11,    29,    35,    40,    41,
      27,    23,    11,    12,    25,    27,    45,    36,    47,    48,
      24,    36,    42,    43,     1,    29,    35,     9,    29,     1,
       4,     5,     7,     8,     9,    16,    22,    23,    29,    44,
      45,    46,    48,    51,    40,    49,    50,    28,    47,    40,
      24,    12,    26,    26,    51,    23,    23,    51,    51,    51,
      23,    28,    44,    44,    11,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    25,    13,    11,    12,    42,    11,
      51,    51,    24,    24,    51,    52,    51,    51,    51,    51,
      51,    51,    51,    51,    29,    51,    51,    49,    24,    24,
      12,    24,    26,    46,    46,    52,     6,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    34,    35,
      35,    36,    36,    37,    37,    38,    38,    39,    40,    40,
      40,    40,    41,    41,    41,    42,    42,    43,    44,    44,
      44,    45,    46,    46,    46,    46,    46,    46,    46,    47,
      47,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     1,
       3,     1,     1,     5,     2,     1,     0,     1,     1,     4,
       4,     1,     4,     3,     1,     3,     1,     2,     2,     2,
       0,     3,     2,     1,     3,     5,     7,     5,     1,     2,
       0,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     3,     4,
       3,     1,     1,     1,     3,     1
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 50 "csubsub_bison.y"
                     {yyval = insertNode(yyvsp[0], "Program", (yylsp[0]).first_line, NONTERMINAL);}
#line 1333 "csubsub_bison.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 53 "csubsub_bison.y"
                               { yyval = insertNode(yyvsp[-1], "ExtDefList", (yylsp[-1]).first_line, NONTERMINAL);
								 yyvsp[-1] -> brother = yyvsp[0];}
#line 1340 "csubsub_bison.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 55 "csubsub_bison.y"
                            { yyval = insertNode(NULL, "ExtDefList", -1 , NONTERMINAL);}
#line 1346 "csubsub_bison.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 57 "csubsub_bison.y"
                                    { yyval = insertNode(yyvsp[-2], "ExtDef", (yylsp[-2]).first_line, NONTERMINAL);
									 yyvsp[-2] -> brother = yyvsp[-1];
									 yyvsp[-1] -> brother = yyvsp[0];}
#line 1354 "csubsub_bison.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 60 "csubsub_bison.y"
                                  { yyval = insertNode(yyvsp[-1], "ExtDef", (yylsp[-1]).first_line, NONTERMINAL);
						  yyvsp[-1] -> brother = yyvsp[0];}
#line 1361 "csubsub_bison.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 62 "csubsub_bison.y"
                                          { yyval = insertNode(yyvsp[-2], "ExtDef", (yylsp[-2]).first_line, NONTERMINAL);
									yyvsp[-2] -> brother = yyvsp[-1];
									yyvsp[-1] -> brother = yyvsp[0];}
#line 1369 "csubsub_bison.tab.c"
    break;

  case 8: /* ExtDef: error  */
#line 65 "csubsub_bison.y"
                        {yylloc.missing_flag = 1; yylloc.missing_char = s_pop(yylloc.stackptr);yyerror();}
#line 1375 "csubsub_bison.tab.c"
    break;

  case 9: /* ExtDecList: VarDec  */
#line 67 "csubsub_bison.y"
                    { yyval = insertNode(yyvsp[0], "ExtDecList", (yylsp[0]).first_line, NONTERMINAL);}
#line 1381 "csubsub_bison.tab.c"
    break;

  case 10: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 68 "csubsub_bison.y"
                                          { yyval = insertNode(yyvsp[-2], "ExtDecList", (yylsp[-2]).first_line, NONTERMINAL);
									 yyvsp[-2] -> brother = yyvsp[-1];
									 yyvsp[-1] -> brother = yyvsp[0];}
#line 1389 "csubsub_bison.tab.c"
    break;

  case 11: /* Specifier: TYPE  */
#line 75 "csubsub_bison.y"
                 { yyval = insertNode(yyvsp[0], "Specifier", (yylsp[0]).first_line, NONTERMINAL);}
#line 1395 "csubsub_bison.tab.c"
    break;

  case 12: /* Specifier: StructSpecifier  */
#line 76 "csubsub_bison.y"
                                  { yyval = insertNode(yyvsp[0], "Specifier", (yylsp[0]).first_line, NONTERMINAL);}
#line 1401 "csubsub_bison.tab.c"
    break;

  case 13: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 78 "csubsub_bison.y"
                                               { yyval = insertNode(yyvsp[-4], "StructSpecifier", (yylsp[-4]).first_line, NONTERMINAL);
												  yyvsp[-4] -> brother = yyvsp[-3];
												  yyvsp[-3] -> brother = yyvsp[-2];
												  yyvsp[-2] -> brother = yyvsp[-1];
												  yyvsp[-1] -> brother = yyvsp[0];}
#line 1411 "csubsub_bison.tab.c"
    break;

  case 14: /* StructSpecifier: STRUCT Tag  */
#line 83 "csubsub_bison.y"
                             { yyval = insertNode(yyvsp[-1], "StructSpecifier", (yylsp[-1]).first_line, NONTERMINAL);
					   yyvsp[-1] -> brother = yyvsp[0];}
#line 1418 "csubsub_bison.tab.c"
    break;

  case 15: /* OptTag: ID  */
#line 87 "csubsub_bison.y"
            { yyval = insertNode(yyvsp[0], "OptTag", (yylsp[0]).first_line, NONTERMINAL);}
#line 1424 "csubsub_bison.tab.c"
    break;

  case 16: /* OptTag: %empty  */
#line 88 "csubsub_bison.y"
                            { yyval = insertNode(NULL, "Specifier", -1, NONTERMINAL);}
#line 1430 "csubsub_bison.tab.c"
    break;

  case 17: /* Tag: ID  */
#line 90 "csubsub_bison.y"
         { yyval = insertNode(yyvsp[0], "Tag", (yylsp[0]).first_line, NONTERMINAL);}
#line 1436 "csubsub_bison.tab.c"
    break;

  case 18: /* VarDec: ID  */
#line 94 "csubsub_bison.y"
            { yyval = insertNode(yyvsp[0], "VarDec", (yylsp[0]).first_line, NONTERMINAL);}
#line 1442 "csubsub_bison.tab.c"
    break;

  case 19: /* VarDec: VarDec LB INT RB  */
#line 95 "csubsub_bison.y"
                                    {yyval = insertNode(yyvsp[-3], "VarDec", (yylsp[-3]).first_line, NONTERMINAL);
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1451 "csubsub_bison.tab.c"
    break;

  case 20: /* VarDec: VarDec LB ID RB  */
#line 99 "csubsub_bison.y"
                                   {yyval = insertNode(yyvsp[-3], "VarDec", (yylsp[-3]).first_line, NONTERMINAL);
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1460 "csubsub_bison.tab.c"
    break;

  case 21: /* VarDec: error  */
#line 103 "csubsub_bison.y"
                        {yylloc.missing_flag = 1; yylloc.missing_char = s_pop(yylloc.stackptr);yyerror();}
#line 1466 "csubsub_bison.tab.c"
    break;

  case 22: /* FunDec: ID LP VarList RP  */
#line 105 "csubsub_bison.y"
                           {yyval = insertNode(yyvsp[-3], "FunDec", (yylsp[-3]).first_line, NONTERMINAL);
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1475 "csubsub_bison.tab.c"
    break;

  case 23: /* FunDec: ID LP RP  */
#line 109 "csubsub_bison.y"
                            {yyval = insertNode(yyvsp[-2], "FunDec", (yylsp[-2]).first_line, NONTERMINAL);
					yyvsp[-2] -> brother = yyvsp[-1];
					yyvsp[-1] -> brother = yyvsp[0];}
#line 1483 "csubsub_bison.tab.c"
    break;

  case 24: /* FunDec: error  */
#line 112 "csubsub_bison.y"
                        {yylloc.missing_flag = 1; yylloc.missing_char = s_pop(yylloc.stackptr);yyerror();}
#line 1489 "csubsub_bison.tab.c"
    break;

  case 25: /* VarList: ParamDec COMMA VarList  */
#line 114 "csubsub_bison.y"
                                {yyval = insertNode(yyvsp[-2], "VarList", (yylsp[-2]).first_line, NONTERMINAL);
					yyvsp[-2] -> brother = yyvsp[-1];
					yyvsp[-1] -> brother = yyvsp[0];}
#line 1497 "csubsub_bison.tab.c"
    break;

  case 26: /* VarList: ParamDec  */
#line 117 "csubsub_bison.y"
                           {yyval = insertNode(yyvsp[0], "VarList", (yylsp[0]).first_line, NONTERMINAL);}
#line 1503 "csubsub_bison.tab.c"
    break;

  case 27: /* ParamDec: Specifier VarDec  */
#line 119 "csubsub_bison.y"
                            {yyval = insertNode(yyvsp[-1], "ParamDec", (yylsp[-1]).first_line, NONTERMINAL);
					yyvsp[-1] -> brother = yyvsp[0];}
#line 1510 "csubsub_bison.tab.c"
    break;

  case 28: /* InnerCompSt: Def InnerCompSt  */
#line 124 "csubsub_bison.y"
                              {yyval = insertNode(yyvsp[-1], "InnerCompSt", (yylsp[-1]).first_line, NONTERMINAL);
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1517 "csubsub_bison.tab.c"
    break;

  case 29: /* InnerCompSt: Stmt InnerCompSt  */
#line 126 "csubsub_bison.y"
                                           {yyval = insertNode(yyvsp[-1], "InnerCompSt", (yylsp[-1]).first_line, NONTERMINAL);
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1524 "csubsub_bison.tab.c"
    break;

  case 30: /* InnerCompSt: %empty  */
#line 128 "csubsub_bison.y"
                                    {yyval = insertNode(NULL, "InnerCompSt", -1, NONTERMINAL);}
#line 1530 "csubsub_bison.tab.c"
    break;

  case 31: /* CompSt: LC InnerCompSt RC  */
#line 132 "csubsub_bison.y"
                            {yyval = insertNode(yyvsp[-2], "CompSt", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1538 "csubsub_bison.tab.c"
    break;

  case 34: /* Stmt: RETURN Exp SEMI  */
#line 142 "csubsub_bison.y"
                                   {yyval = insertNode(yyvsp[-2], "Stmt", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1546 "csubsub_bison.tab.c"
    break;

  case 35: /* Stmt: IF LP Exp RP Stmt  */
#line 145 "csubsub_bison.y"
                                                           {yyval = insertNode(yyvsp[-4], "Stmt", (yylsp[-4]).first_line, NONTERMINAL);
							yyvsp[-4] -> brother = yyvsp[-3];
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1556 "csubsub_bison.tab.c"
    break;

  case 36: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 150 "csubsub_bison.y"
                                               {yyval = insertNode(yyvsp[-6], "Stmt", (yylsp[-6]).first_line, NONTERMINAL);
							yyvsp[-6] -> brother = yyvsp[-5];
							yyvsp[-5] -> brother = yyvsp[-4];
							yyvsp[-4] -> brother = yyvsp[-3];
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1568 "csubsub_bison.tab.c"
    break;

  case 37: /* Stmt: WHILE LP Exp RP Stmt  */
#line 157 "csubsub_bison.y"
                                        {yyval = insertNode(yyvsp[-4], "Stmt", (yylsp[-4]).first_line, NONTERMINAL);
							yyvsp[-4] -> brother = yyvsp[-3];
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1578 "csubsub_bison.tab.c"
    break;

  case 38: /* Stmt: error  */
#line 162 "csubsub_bison.y"
                        {yylloc.missing_flag = 1; yylloc.missing_char = s_pop(yylloc.stackptr);yyerror();}
#line 1584 "csubsub_bison.tab.c"
    break;

  case 39: /* DefList: Def DefList  */
#line 165 "csubsub_bison.y"
                      {yyval = insertNode(yyvsp[-1], "DefList", (yylsp[-1]).first_line, NONTERMINAL);
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1591 "csubsub_bison.tab.c"
    break;

  case 40: /* DefList: %empty  */
#line 167 "csubsub_bison.y"
                            {yyval = insertNode(NULL, "DefList", -1, NONTERMINAL);}
#line 1597 "csubsub_bison.tab.c"
    break;

  case 41: /* Def: Specifier DecList SEMI  */
#line 169 "csubsub_bison.y"
                              {yyval = insertNode(yyvsp[-2], "Def", (yylsp[-2]).first_line, NONTERMINAL);
							  yyvsp[-2] -> brother = yyvsp[-1];
							  yyvsp[-1] -> brother = yyvsp[0];}
#line 1605 "csubsub_bison.tab.c"
    break;

  case 42: /* DecList: Dec  */
#line 173 "csubsub_bison.y"
                {yyval = insertNode(yyvsp[0], "DecList", (yylsp[0]).first_line, NONTERMINAL);}
#line 1611 "csubsub_bison.tab.c"
    break;

  case 43: /* DecList: Dec COMMA DecList  */
#line 174 "csubsub_bison.y"
                                    {yyval = insertNode(yyvsp[-2], "DecList", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1619 "csubsub_bison.tab.c"
    break;

  case 44: /* Dec: VarDec  */
#line 178 "csubsub_bison.y"
             {yyval = insertNode(yyvsp[0], "Dec", (yylsp[0]).first_line, NONTERMINAL);}
#line 1625 "csubsub_bison.tab.c"
    break;

  case 45: /* Dec: VarDec ASSIGNOP Exp  */
#line 179 "csubsub_bison.y"
                                      {yyval = insertNode(yyvsp[-2], "Dec", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1633 "csubsub_bison.tab.c"
    break;

  case 46: /* Exp: Exp ASSIGNOP Exp  */
#line 186 "csubsub_bison.y"
                       {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1641 "csubsub_bison.tab.c"
    break;

  case 47: /* Exp: Exp AND Exp  */
#line 189 "csubsub_bison.y"
                              {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1649 "csubsub_bison.tab.c"
    break;

  case 48: /* Exp: Exp OR Exp  */
#line 192 "csubsub_bison.y"
                             {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1657 "csubsub_bison.tab.c"
    break;

  case 49: /* Exp: Exp RELOP Exp  */
#line 195 "csubsub_bison.y"
                                {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1665 "csubsub_bison.tab.c"
    break;

  case 50: /* Exp: Exp PLUS Exp  */
#line 198 "csubsub_bison.y"
                               {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1673 "csubsub_bison.tab.c"
    break;

  case 51: /* Exp: Exp MINUS Exp  */
#line 201 "csubsub_bison.y"
                                {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1681 "csubsub_bison.tab.c"
    break;

  case 52: /* Exp: Exp STAR Exp  */
#line 204 "csubsub_bison.y"
                               {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1689 "csubsub_bison.tab.c"
    break;

  case 53: /* Exp: Exp DIV Exp  */
#line 207 "csubsub_bison.y"
                              {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1697 "csubsub_bison.tab.c"
    break;

  case 54: /* Exp: LP Exp RP  */
#line 210 "csubsub_bison.y"
                             {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1705 "csubsub_bison.tab.c"
    break;

  case 55: /* Exp: MINUS Exp  */
#line 213 "csubsub_bison.y"
                            {yyval = insertNode(yyvsp[-1], "Exp", (yylsp[-1]).first_line, NONTERMINAL);
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1712 "csubsub_bison.tab.c"
    break;

  case 56: /* Exp: NOT Exp  */
#line 215 "csubsub_bison.y"
                          {yyval = insertNode(yyvsp[-1], "Exp", (yylsp[-1]).first_line, NONTERMINAL);
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1719 "csubsub_bison.tab.c"
    break;

  case 57: /* Exp: ID LP Args RP  */
#line 217 "csubsub_bison.y"
                                 {yyval = insertNode(yyvsp[-3], "Exp", (yylsp[-3]).first_line, NONTERMINAL);
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1728 "csubsub_bison.tab.c"
    break;

  case 58: /* Exp: ID LP RP  */
#line 221 "csubsub_bison.y"
                            {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1736 "csubsub_bison.tab.c"
    break;

  case 59: /* Exp: Exp LB Exp RB  */
#line 224 "csubsub_bison.y"
                                 {yyval = insertNode(yyvsp[-3], "Exp", (yylsp[-3]).first_line, NONTERMINAL);
							yyvsp[-3] -> brother = yyvsp[-2];
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1745 "csubsub_bison.tab.c"
    break;

  case 60: /* Exp: Exp DOT ID  */
#line 228 "csubsub_bison.y"
                             {yyval = insertNode(yyvsp[-2], "Exp", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1753 "csubsub_bison.tab.c"
    break;

  case 61: /* Exp: ID  */
#line 231 "csubsub_bison.y"
                     {yyval = insertNode(yyvsp[0], "Exp", (yylsp[0]).first_line, NONTERMINAL);}
#line 1759 "csubsub_bison.tab.c"
    break;

  case 62: /* Exp: INT  */
#line 232 "csubsub_bison.y"
                      {yyval = insertNode(yyvsp[0], "Exp", (yylsp[0]).first_line, NONTERMINAL);}
#line 1765 "csubsub_bison.tab.c"
    break;

  case 63: /* Exp: FLOAT  */
#line 233 "csubsub_bison.y"
                        {yyval = insertNode(yyvsp[0], "Exp", (yylsp[0]).first_line, NONTERMINAL);}
#line 1771 "csubsub_bison.tab.c"
    break;

  case 64: /* Args: Exp COMMA Args  */
#line 236 "csubsub_bison.y"
                      {yyval = insertNode(yyvsp[-2], "Args", (yylsp[-2]).first_line, NONTERMINAL);
							yyvsp[-2] -> brother = yyvsp[-1];
							yyvsp[-1] -> brother = yyvsp[0];}
#line 1779 "csubsub_bison.tab.c"
    break;

  case 65: /* Args: Exp  */
#line 239 "csubsub_bison.y"
                      {yyval = insertNode(yyvsp[0], "Args", (yylsp[0]).first_line, NONTERMINAL);}
#line 1785 "csubsub_bison.tab.c"
    break;


#line 1789 "csubsub_bison.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 242 "csubsub_bison.y"

int yyerror()
{
	if(yylloc.missing_flag){
		printf("ERROR type B at line %d. Missing character: '%c'\n", yylloc.first_line, yylloc.missing_char);
		yylloc.missing_flag = 0;
		return 0;
	}
	
	// printf("ERROR type B at line %d. Sytax error.\n", yylloc.first_line);
	// return 0;
	
}

int main(int argc, char** argv){
   	if(argc <=1) {
		return 1;
	}

    mystack.top = 0;
    mystack.Waiting_RC_Flag = 0;
    yylloc.stackptr = &mystack;
	yylloc.missing_char = '#';
	yylloc.missing_flag = 0;
   	FILE* f = fopen(argv[1], "r");
   	if(!f){
		perror(argv[1]);
    	return 1;
    }
	yydebug = 1;
   	yyrestart(f);
   	yyparse();
   	return 0;  
}
