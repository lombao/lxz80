/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "defs.h"
#include "codedata.h"
 
int yyparse();
int yylex();


extern int setLabelAddress(const char * label, const int pc);
extern int setLabelValue(const char * label, const int val);
extern int LookupTableLabels(const char * label);
extern void labelUndefinedError(const char * label);
extern void warningError(const char *str);
extern void fatalError(const char *str);
extern int getLabelValue(const char * label, uint * k);
extern int outCode( int num, ... );
extern void yyerror(const char *str);

extern int yylineno;
extern int pc;
extern int prepc;
extern int condStatus;

char msg[200];
uint8_t * p;

int yywrap()
{
        return 1;
} 
  



#line 110 "grammar.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_GRAMMAR_H_INCLUDED
# define YY_YY_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DEFB = 258,
    DEFS = 259,
    DEFW = 260,
    DEFC = 261,
    DEFD = 262,
    PLUS = 263,
    MINUS = 264,
    MULT = 265,
    DIVIDE = 266,
    GREATERTHAN = 267,
    GREATEREQ = 268,
    LESSTHAN = 269,
    LESSEQ = 270,
    BITOR = 271,
    BITAND = 272,
    OPSHLF = 273,
    OPSHRT = 274,
    PARRIGHT = 275,
    PARLEFT = 276,
    EXCLAMATION = 277,
    NEQUAL = 278,
    EQUAL = 279,
    IF = 280,
    IFDEF = 281,
    IFNDEF = 282,
    ENDIF = 283,
    INCLUDEBIN = 284,
    DEFINED = 285,
    NEWLINE = 286,
    ERROR = 287,
    DOLAR = 288,
    ALIGN = 289,
    COMMA = 290,
    CHAR = 291,
    LDDR = 292,
    CALL = 293,
    RRCA = 294,
    OTDR = 295,
    OTIR = 296,
    OUTI = 297,
    OUTD = 298,
    RETI = 299,
    RETN = 300,
    PUSH = 301,
    END = 302,
    EQU = 303,
    DEC = 304,
    AND = 305,
    SBC = 306,
    OUT = 307,
    ADC = 308,
    LDD = 309,
    LDI = 310,
    ADD = 311,
    RRA = 312,
    RRC = 313,
    SRA = 314,
    SRL = 315,
    SLL = 316,
    RRD = 317,
    POP = 318,
    CCF = 319,
    RET = 320,
    XOR = 321,
    BIT = 322,
    SCF = 323,
    NOP = 324,
    SET = 325,
    JP = 326,
    DJNZ = 327,
    HALT = 328,
    INDR = 329,
    INIR = 330,
    IND = 331,
    LDIR = 332,
    SLA = 333,
    NEG = 334,
    LD = 335,
    AF = 336,
    HL = 337,
    SP = 338,
    BC = 339,
    DE = 340,
    IX = 341,
    IY = 342,
    IXH = 343,
    IXL = 344,
    IYH = 345,
    IYL = 346,
    OR = 347,
    AFPLUS = 348,
    SUB = 349,
    CP = 350,
    RES = 351,
    CPD = 352,
    CPDR = 353,
    CPI = 354,
    CPIR = 355,
    CPL = 356,
    RLA = 357,
    RLC = 358,
    RLCA = 359,
    DAA = 360,
    RL = 361,
    RLD = 362,
    DI = 363,
    EI = 364,
    EX = 365,
    JR = 366,
    RR = 367,
    EXX = 368,
    RST = 369,
    IM = 370,
    IN = 371,
    INI = 372,
    INC = 373,
    NC = 374,
    NZ = 375,
    PO = 376,
    PE = 377,
    Z = 378,
    P = 379,
    M = 380,
    A = 381,
    B = 382,
    C = 383,
    D = 384,
    E = 385,
    H = 386,
    L = 387,
    R = 388,
    I = 389,
    F = 390,
    STRING = 391,
    LITERAL = 392,
    LABEL = 393,
    INTEGER = 394,
    UMINUS = 395
  };
#endif
/* Tokens.  */
#define DEFB 258
#define DEFS 259
#define DEFW 260
#define DEFC 261
#define DEFD 262
#define PLUS 263
#define MINUS 264
#define MULT 265
#define DIVIDE 266
#define GREATERTHAN 267
#define GREATEREQ 268
#define LESSTHAN 269
#define LESSEQ 270
#define BITOR 271
#define BITAND 272
#define OPSHLF 273
#define OPSHRT 274
#define PARRIGHT 275
#define PARLEFT 276
#define EXCLAMATION 277
#define NEQUAL 278
#define EQUAL 279
#define IF 280
#define IFDEF 281
#define IFNDEF 282
#define ENDIF 283
#define INCLUDEBIN 284
#define DEFINED 285
#define NEWLINE 286
#define ERROR 287
#define DOLAR 288
#define ALIGN 289
#define COMMA 290
#define CHAR 291
#define LDDR 292
#define CALL 293
#define RRCA 294
#define OTDR 295
#define OTIR 296
#define OUTI 297
#define OUTD 298
#define RETI 299
#define RETN 300
#define PUSH 301
#define END 302
#define EQU 303
#define DEC 304
#define AND 305
#define SBC 306
#define OUT 307
#define ADC 308
#define LDD 309
#define LDI 310
#define ADD 311
#define RRA 312
#define RRC 313
#define SRA 314
#define SRL 315
#define SLL 316
#define RRD 317
#define POP 318
#define CCF 319
#define RET 320
#define XOR 321
#define BIT 322
#define SCF 323
#define NOP 324
#define SET 325
#define JP 326
#define DJNZ 327
#define HALT 328
#define INDR 329
#define INIR 330
#define IND 331
#define LDIR 332
#define SLA 333
#define NEG 334
#define LD 335
#define AF 336
#define HL 337
#define SP 338
#define BC 339
#define DE 340
#define IX 341
#define IY 342
#define IXH 343
#define IXL 344
#define IYH 345
#define IYL 346
#define OR 347
#define AFPLUS 348
#define SUB 349
#define CP 350
#define RES 351
#define CPD 352
#define CPDR 353
#define CPI 354
#define CPIR 355
#define CPL 356
#define RLA 357
#define RLC 358
#define RLCA 359
#define DAA 360
#define RL 361
#define RLD 362
#define DI 363
#define EI 364
#define EX 365
#define JR 366
#define RR 367
#define EXX 368
#define RST 369
#define IM 370
#define IN 371
#define INI 372
#define INC 373
#define NC 374
#define NZ 375
#define PO 376
#define PE 377
#define Z 378
#define P 379
#define M 380
#define A 381
#define B 382
#define C 383
#define D 384
#define E 385
#define H 386
#define L 387
#define R 388
#define I 389
#define F 390
#define STRING 391
#define LITERAL 392
#define LABEL 393
#define INTEGER 394
#define UMINUS 395

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "grammar.y"

  uint32_t 	normal;
  uint8_t 	byte;
  uint16_t 	word;
  uint16_t 	address;
  uint8_t * listexpr;
  char 		literal[64];
  

#line 452 "grammar.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  308
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3700

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  457
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  849

#define YYUNDEFTOK  2
#define YYMAXUTOK   397


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   178,   178,   180,   181,   183,   184,   185,   186,   187,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   278,   280,   281,   283,   285,   287,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   323,   324,   325,   326,   327,   328,   329,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   345,   346,   347,   348,   353,   354,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   383,   386,   387,   388,   389,   390,   392,   400,   401,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   417,   418,   419,   420,   421,   423,   424,
     425,   426,   427,   428,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   463,   465,   469,   473,   479,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     540,   541,   543,   544,   545,   547,   548,   549,   552,   553,
     554,   555,   558,   559,   562,   563,   564,   565,   567,   568,
     569,   570,   572,   573,   574,   575,   577,   578,   579,   580,
     582,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   602,   603,   604,   605,   608,   609,   610,   611,   613,
     614,   615,   616,   618,   619,   620,   621,   623,   624,   625,
     626,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   659,   660,
     661,   662,   669,   670,   671,   672,   679,   680,   681,   689,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   706,   707,   708,   709,   710,   711,   712,   713,
     715,   719,   720,   721,   722,   726,   727,   728,   729,   730,
     731,   732,   734,   735,   737,   738,   739,   740,   742,   743,
     744,   745,   748,   749,   751,   752,   754,   755,   756,   757,
     758,   759,   760,   761,   763,   764,   765,   766
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFB", "DEFS", "DEFW", "DEFC", "DEFD",
  "PLUS", "MINUS", "MULT", "DIVIDE", "GREATERTHAN", "GREATEREQ",
  "LESSTHAN", "LESSEQ", "BITOR", "BITAND", "OPSHLF", "OPSHRT", "PARRIGHT",
  "PARLEFT", "EXCLAMATION", "NEQUAL", "EQUAL", "IF", "IFDEF", "IFNDEF",
  "ENDIF", "INCLUDEBIN", "DEFINED", "NEWLINE", "ERROR", "DOLAR", "ALIGN",
  "COMMA", "CHAR", "LDDR", "CALL", "RRCA", "OTDR", "OTIR", "OUTI", "OUTD",
  "RETI", "RETN", "PUSH", "END", "EQU", "DEC", "AND", "SBC", "OUT", "ADC",
  "LDD", "LDI", "ADD", "RRA", "RRC", "SRA", "SRL", "SLL", "RRD", "POP",
  "CCF", "RET", "XOR", "BIT", "SCF", "NOP", "SET", "JP", "DJNZ", "HALT",
  "INDR", "INIR", "IND", "LDIR", "SLA", "NEG", "LD", "AF", "HL", "SP",
  "BC", "DE", "IX", "IY", "IXH", "IXL", "IYH", "IYL", "OR", "AFPLUS",
  "SUB", "CP", "RES", "CPD", "CPDR", "CPI", "CPIR", "CPL", "RLA", "RLC",
  "RLCA", "DAA", "RL", "RLD", "DI", "EI", "EX", "JR", "RR", "EXX", "RST",
  "IM", "IN", "INI", "INC", "NC", "NZ", "PO", "PE", "Z", "P", "M", "A",
  "B", "C", "D", "E", "H", "L", "R", "I", "F", "STRING", "LITERAL",
  "LABEL", "INTEGER", "UMINUS", "\"word\"", "\"sequence\"", "$accept",
  "program", "lines", "line", "auxline", "instruction", "directivedefc",
  "directivedefs", "directivedefb", "directivedefw", "directivedefd",
  "opcodeadc", "opcodeadd", "opcodeand", "opcodebit", "opcodecall",
  "opcodecp", "opcodedec", "opcodedjnz", "opcodeex", "opcodeim",
  "opcodein", "opcodeinc", "opcodejp", "opcodejr", "opcodeld", "opcodeor",
  "opcodeout", "opcodepop", "opcodepush", "opcoderes", "opcoderet",
  "opcoderl", "opcoderlc", "opcoderr", "opcoderrc", "opcoderst",
  "opcodesbc", "opcodeset", "opcodesla", "opcodesll", "opcodesra",
  "opcodesrl", "opcodesub", "opcodexor", "listexprw", "listexprd",
  "listexpr", "expr", "expritem", "reg8", "regixiy", "reg16", "reg16af",
  "undocregix", "undocregiy", "cc", "ccreduced", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397
};
# endif

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-243)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     113,    62,   257,   518,  -129,   947,   257,  -125,  -114,  -234,
    -234,  -111,   257,  -234,   234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,   190,   257,  1767,   476,   -47,    12,   -45,  -234,
    -234,   -39,  -234,   110,   181,   402,   640,  -234,   295,  -234,
     596,   538,   257,  -234,  -234,   257,  1109,   257,  -234,  -234,
    -234,  -234,  -234,   784,  -234,  1676,   671,   899,   915,   257,
    -234,  -234,  -234,  -234,  -234,  -234,   993,  -234,  -234,  1027,
    -234,  -234,  -234,    -3,  1230,  1172,  -234,   257,   257,   131,
    -234,  1777,   -12,   789,    72,   113,  -234,    76,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,   257,   257,
     257,   -28,  -234,  -234,  -234,  -234,  -234,    90,  3608,  -234,
      51,  -234,   107,  3608,   122,  -234,   114,  3608,  3608,  -234,
    -234,  -234,  3608,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  3608,   160,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    3608,    46,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,   609,  -234,  -234,  -234,  -234,   161,  3608,  -234,   162,
     168,    -2,   169,   199,   217,   233,   256,   261,   202,  -234,
     254,  -234,   279,  -234,   320,  -234,  -234,  -234,  -234,  -234,
    1386,  -234,  -234,  -234,  -234,   263,  3608,  -234,  1865,  1908,
    1396,  3608,   267,  3608,   323,  -234,   418,   269,  -234,  -234,
     271,   302,   303,   304,   308,   310,   311,   312,   315,   325,
    1412,  -234,  -234,  -234,  -234,   332,  3608,  -234,  1428,  -234,
    -234,  -234,  -234,  3608,  -234,  1508,  -234,  -234,  -234,  -234,
    3608,  -234,  1936,   355,  -234,   363,  -234,    65,   334,   335,
    -234,  -234,   353,   354,  -234,   360,   364,  -234,  3608,   376,
     380,  -234,  3608,  3608,   377,   401,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,   257,  -234,   257,   238,  -234,  -234,
    -234,  -234,  1964,  -234,  -234,   963,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,  1588,   257,  1679,   257,   245,     1,     6,
     272,     7,     9,   931,   198,  1044,   393,  1993,   198,  1060,
     198,   492,   351,  1076,   399,   412,   413,   409,   420,   435,
     424,   438,   444,   437,   447,   451,   460,   474,   483,  1189,
    1179,  1510,   464,   473,   479,   257,   481,   488,   507,   504,
     515,   516,  2021,    30,   257,  1234,  1252,  1363,  1379,   338,
     416,   257,   342,   264,  1525,   529,   542,   544,  1205,   533,
     548,   550,   541,    22,    77,  1642,   543,   554,   561,   552,
     562,   565,   559,   487,   508,   257,   257,   257,   257,   257,
     569,   583,   588,   667,   577,    86,    94,  3608,  2049,  -234,
    -234,  -234,  3608,  3623,  3623,  1763,  1763,   230,   230,   230,
     230,    81,    81,    99,    99,  -234,  -234,  1811,  1811,  3608,
    -234,  3608,  3608,  -234,  3608,  3608,  -234,   257,  -234,   257,
    -234,  -234,   257,  -234,   257,  -234,  1541,  -234,  -234,  -234,
    -234,  3608,  -234,  -234,  1548,  -234,  -234,  -234,  -234,  3608,
    -234,   563,   566,  -234,  1566,  -234,  -234,  -234,  -234,  3608,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    1583,  -234,  -234,  -234,  -234,  3608,  -234,  -234,   257,   257,
    -234,   257,   257,  -234,   257,   257,  -234,   257,   257,  -234,
     257,   257,  1646,  -234,  -234,  -234,  -234,  3608,  -234,   408,
    -234,   436,  -234,  -234,  -234,  -234,  3608,  -234,   257,   257,
     576,   581,   582,   586,   257,   257,  3608,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  3608,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  3608,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    3608,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  3608,  -234,
    -234,  3608,   626,  -234,  -234,  -234,  -234,  -234,  -234,  3608,
    -234,  -234,  -234,   257,  3608,   257,  -234,  3608,  -234,  -234,
     257,   257,  1662,  -234,  -234,  -234,  -234,  3608,  -234,  -234,
     257,   257,  -234,   257,  -234,   257,  -234,   439,  -234,  -234,
     257,   257,  -234,   257,   257,   589,  -234,  -234,  3608,  3608,
    3608,  3608,  3608,  -234,   257,   257,  1709,  3608,  -234,   257,
    -234,   257,  -234,  -234,  2078,  2106,  2134,  2163,   605,   624,
     628,   617,   633,   635,   131,   520,   629,    95,   186,   630,
     224,   225,  2191,  2219,  2248,  2276,  2304,  2333,  2361,  2389,
    2418,  2446,   631,   636,   644,   638,   645,   652,   643,   663,
     664,  2474,  2503,   456,   547,   553,   -33,  2531,  2559,   654,
     658,   661,  2588,   675,  2616,  2644,  2673,  2701,   665,   676,
     678,  2729,  2758,  2786,  2814,   670,   679,   686,  2843,  2871,
    2899,  2928,   459,  2956,  2984,   682,  3013,  3041,  -234,  -234,
    -234,  -234,  -234,   257,   257,  -234,   257,   257,  -234,  -234,
    -234,   257,  -234,   257,  -234,  -234,   257,  -234,   257,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,   257,   257,  -234,   257,   257,  -234,   257,   257,  -234,
    -234,  3608,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,   692,   693,  -234,  -234,  -234,   668,   257,   674,
     683,  -234,  -234,  -234,   257,   257,  -234,  -234,  -234,  -234,
    -234,   257,   257,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  3069,  3098,  3126,  3154,  3183,
    3211,  3239,  3268,  3296,  3324,  3353,  3381,  3409,  3438,   456,
     456,  3466,  3494,  3523,  3551,  3579,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    3608,  -234,  3608,  -234,  -234,  -234,  -234,  -234,  -234
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       6,     0,     0,    75,     0,    90,    80,    81,    83,    82,
      84,    85,     0,    16,     0,     0,     0,     0,     0,    74,
      76,     0,    89,     0,     0,     0,     0,    91,     0,    59,
     312,     0,     0,    92,    79,     0,     0,     0,    69,    71,
      73,    70,    77,     0,    78,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    86,     0,    87,    65,     0,
      88,    66,    67,     0,     0,     0,    68,     0,     0,     0,
      72,     0,     0,     0,     0,     2,     3,     0,    10,    21,
      19,    18,    20,    22,    27,    28,    26,    37,    32,    38,
      35,    30,    39,    40,    41,    42,    33,    34,    25,    43,
      31,    44,    45,    46,    29,    47,    48,    49,    50,    51,
      52,    53,    54,    57,    55,    56,    58,    36,     0,     0,
       0,     0,   423,   422,   397,   420,   421,    96,   396,   400,
      94,   390,    97,   388,     0,   394,    98,   392,    11,    12,
      13,    15,    24,   448,   446,   450,   451,   447,   452,   453,
     449,   155,     0,   441,   440,   438,   439,   306,   307,   305,
      17,     0,   436,   437,   434,   435,   175,   176,   177,   178,
     179,   180,   425,   426,   427,   428,   429,   430,   431,   168,
     174,     0,   138,   139,   140,   141,   425,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   326,
       0,   353,     0,   357,     0,   349,   303,   304,   302,   313,
       0,   375,   376,   377,   378,   425,   371,   370,     0,     0,
       0,   203,     0,   181,     0,   345,     0,     0,   432,   433,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   425,   282,   283,     0,   366,
     367,   368,   369,   362,   361,     0,   164,   165,   166,   167,
     157,   158,     0,     0,   318,     0,   314,     0,     0,     0,
     456,   454,     0,     0,   455,     0,     0,   457,   209,     0,
       0,   322,   330,   187,     0,     0,   197,   198,   199,   200,
     201,   202,   190,   191,     0,     8,     0,     0,     1,     4,
       5,   403,     0,   401,   424,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     7,
     402,   399,   398,   404,   405,   406,   407,   415,   414,   417,
     416,   409,   408,   410,   411,   412,   413,   418,   419,    95,
     391,   389,    93,   395,   393,   156,   169,     0,   172,     0,
     173,   133,     0,   136,     0,   137,     0,   147,   148,   149,
     150,   142,   143,   336,     0,   337,   338,   339,   340,   332,
     331,     0,     0,   106,     0,   107,   108,   109,   110,    99,
     100,   118,   122,   119,   120,   121,   126,   123,   124,   125,
       0,   127,   128,   129,   130,   111,   112,   327,     0,     0,
     354,     0,     0,   358,     0,     0,   350,     0,     0,   372,
       0,     0,     0,   384,   385,   386,   387,   380,   379,     0,
     154,     0,   341,   205,   206,   207,   204,   346,     0,     0,
       0,     0,     0,     0,     0,     0,   281,   252,   253,   254,
     248,   249,   250,   251,   279,   259,   260,   261,   255,   256,
     257,   258,   277,   266,   267,   268,   262,   263,   264,   265,
     278,   273,   274,   275,   269,   270,   271,   272,   276,   239,
     237,   280,     0,   442,   443,   444,   445,   238,   236,   216,
     214,   246,   247,     0,   241,     0,   244,   243,   245,   284,
       0,     0,     0,   296,   297,   298,   299,   291,   292,   363,
       0,     0,   159,     0,   162,     0,   163,     0,   308,   319,
       0,     0,   315,     0,     0,     0,   182,   183,   213,   212,
     211,   210,   208,   323,     0,     0,     0,   189,   192,     0,
     195,     0,   196,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   170,   171,
     134,   135,   144,     0,     0,   333,     0,     0,   301,   300,
     101,     0,   104,     0,   105,   113,     0,   116,     0,   117,
     328,   329,   355,   356,   359,   360,   351,   352,   373,   374,
     381,     0,     0,   151,     0,     0,   342,     0,     0,   347,
     348,   221,   222,   219,   220,   231,   230,   228,   229,   232,
     233,   227,     0,     0,   218,   234,   235,   402,     0,   402,
     402,   285,   286,   293,     0,     0,   364,   365,   160,   161,
     309,     0,     0,   320,   321,   316,   317,   184,   185,   186,
     324,   325,   188,   193,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   334,   335,
     102,   103,   114,   115,   382,   383,   152,   153,   343,   344,
     223,   224,   225,   226,   217,   294,   295,   310,   311
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,   613,   623,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,    -1,  -234,
      55,  -233,   -49,   691,  -234,  -234,   -30,  -234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   142,   146,   137,   312,   139,
     189,   248,   190,   169,   591,   592,   162,   289
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     138,   140,   143,   383,   147,   148,   249,   128,   144,   457,
     219,   152,   149,   161,   459,   462,   232,   464,   277,   129,
     130,   458,   170,   150,   197,   151,   460,   463,   131,   465,
     613,   132,   303,   201,   133,   199,   304,   202,   544,   545,
     226,   228,   614,   204,   229,   231,   233,   205,   206,   765,
     766,   767,   768,   769,   770,   256,   263,   270,   272,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   128,   308,   288,   328,   329,   292,   293,   278,   200,
     198,   203,   279,   129,   130,   615,   332,   207,   209,   211,
     213,   215,   131,   771,   639,   132,   227,   616,   133,   326,
     327,   330,   641,   731,   328,   329,   640,   310,   235,   314,
     247,   257,   264,   271,   642,   732,     1,     2,     3,     4,
       5,   274,   328,   329,   276,   315,   346,   311,   337,   313,
     291,   208,   338,   339,   294,   135,   302,   136,     6,     7,
       8,     9,   333,   331,    10,    11,   334,    12,   412,   335,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   598,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   733,   336,   343,   344,   134,   135,
     347,   136,   210,   345,   348,    56,   734,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   736,   738,   349,   382,   182,   183,   184,   185,
     186,   187,   188,   128,   737,   739,   324,   325,   326,   327,
      82,    83,   350,   328,   329,   129,   130,   182,   183,   184,
     185,   186,   187,   188,   131,   456,   128,   132,   351,   429,
     133,   163,   164,   128,   165,   166,   167,   168,   129,   130,
     172,   173,   174,   175,   354,   593,   130,   131,   355,   356,
     132,   352,   461,   133,   131,   473,   353,   132,   369,   483,
     133,   491,   375,   427,   384,   428,   385,   182,   183,   184,
     185,   186,   187,   188,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   451,   452,   454,   455,   357,   386,   387,   388,
     358,   359,   471,   389,   479,   390,   391,   392,   489,   693,
     393,   128,   505,   153,   154,   155,   156,   157,   158,   159,
     394,   360,   160,   582,   130,   361,   362,   398,   527,   413,
     414,   135,   131,   136,   536,   132,   163,   164,   133,   165,
     166,   216,   217,   546,   554,   562,   570,   578,   415,   416,
     581,   589,   594,   597,   135,   417,   136,   607,   472,   418,
     480,   135,   363,   136,   490,   376,   364,   365,   506,   377,
     378,   419,   423,   481,   628,   629,   630,   631,   632,   507,
     508,   509,   637,   212,   528,   530,   532,   128,   511,   510,
     583,   584,   585,   586,   496,   497,   498,   406,   499,   129,
     130,   407,   408,   512,   513,   409,   514,   590,   131,   410,
     411,   132,   515,   608,   133,   517,   644,   516,   645,   518,
     618,   646,   420,   647,   579,   128,   421,   422,   182,   183,
     184,   185,   186,   187,   188,   587,   588,   129,   130,   135,
     519,   136,   520,   424,   533,   128,   131,   425,   426,   132,
     675,   521,   133,   534,   676,   677,   538,   191,   130,   535,
     379,   537,   380,   381,   238,   239,   131,   662,   663,   132,
     664,   665,   133,   666,   667,   539,   668,   669,   678,   670,
     671,   705,   679,   680,   540,   706,   707,   128,   182,   183,
     184,   185,   186,   187,   188,   541,   542,   681,   682,   129,
     130,   797,   580,   687,   688,   798,   799,   128,   131,   599,
     600,   132,   601,   609,   133,   135,   610,   136,   611,   220,
     130,   612,   620,   619,   192,   193,   194,   195,   131,   621,
     623,   132,   622,   624,   133,   492,   493,   494,   495,   625,
     626,   692,   182,   183,   184,   185,   186,   187,   188,   633,
     627,   634,   694,   135,   695,   136,   635,   638,   654,   696,
     697,   655,   196,   183,   184,   185,   186,   187,   188,   701,
     702,   683,   703,   135,   704,   136,   684,   685,   128,   708,
     709,   686,   710,   711,   712,   722,   221,   222,   223,   224,
     129,   130,   723,   713,   714,   128,   724,   725,   716,   131,
     717,   726,   132,   727,   751,   133,   729,   129,   130,   730,
     735,   750,   752,   754,   141,   135,   131,   136,   753,   132,
     755,   214,   133,   756,   225,   183,   184,   185,   186,   187,
     188,   757,   758,   763,   774,   135,   128,   136,   775,   764,
     128,   776,   761,   778,   784,   783,   785,   791,   636,   130,
     790,   340,   250,   130,   792,   341,   342,   131,   309,  -215,
     132,   131,   802,   133,   132,  -240,   307,   133,   689,   728,
     690,   691,   238,   239,  -242,   153,   154,   155,   156,   157,
     158,   159,   805,   806,   160,   807,   808,   819,   820,   218,
     809,     0,   810,     0,     0,   811,     0,   812,   762,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,     0,
     813,   814,     0,   815,   816,     0,   817,   818,     0,   251,
     252,   253,   254,   135,     0,   136,   182,   183,   184,   185,
     186,   187,   188,     0,     0,     0,     0,   821,     0,     0,
       0,     0,     0,   822,   823,     0,     0,     0,     0,     0,
     824,   825,     1,     2,     3,     4,     5,   255,   183,   184,
     185,   186,   187,   188,   135,   234,   136,     0,   135,     0,
     136,     0,     0,     0,     6,     7,     8,     9,   840,   842,
     305,    11,     0,    12,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   306,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       0,     0,     0,     0,   841,   843,     0,     0,     0,     0,
       0,    56,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   128,     0,
     182,   183,   184,   185,   186,   187,   188,     0,     0,     0,
     258,   130,     0,     0,   128,     0,    82,     0,     0,   131,
       0,     0,   132,     0,     0,   133,   265,   130,     0,     0,
     128,     0,     0,     0,     0,   131,     0,     0,   132,     0,
       0,   133,   466,   130,     0,     0,   128,     0,     0,     0,
       0,   131,     0,     0,   132,     0,     0,   133,   129,   130,
       0,     0,   128,     0,     0,     0,     0,   131,     0,     0,
     132,     0,     0,   133,   129,   130,     0,   259,   260,   261,
     262,     0,     0,   131,     0,     0,   132,     0,     0,   133,
       0,     0,     0,   266,   267,   268,   269,     0,     0,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,   467,
     468,   469,   470,     0,     0,   182,   183,   184,   185,   186,
     187,   188,     0,     0,     0,     0,   135,     0,   136,     0,
       0,   182,   183,   184,   185,   186,   187,   188,   275,     0,
       0,     0,   135,   128,   136,     0,     0,   182,   183,   184,
     185,   186,   187,   188,     0,   474,   130,     0,   135,   128,
     136,     0,     0,     0,   131,     0,     0,   132,     0,     0,
     133,   484,   130,   145,   135,   128,   136,     0,     0,     0,
     131,     0,     0,   132,     0,     0,   133,   500,   130,   431,
     135,     0,   136,     0,     0,     0,   131,     0,     0,   132,
       0,     0,   133,     0,     0,     0,     0,     0,   128,   182,
     183,   184,   185,   186,   187,   188,     0,     0,     0,     0,
     230,   130,   475,   476,   477,   478,     0,     0,     0,   131,
       0,     0,   132,     0,     0,   133,     0,     0,   485,   486,
     487,   488,     0,   182,   183,   184,   185,   186,   187,   188,
       0,     0,     0,     0,   501,   502,   503,   504,     0,     0,
     182,   183,   184,   185,   186,   187,   188,     0,     0,     0,
       0,   135,     0,   136,     0,     0,   182,   183,   184,   185,
     186,   187,   188,   290,     0,     0,     0,   135,   128,   136,
     529,     0,   182,   183,   184,   185,   186,   187,   188,     0,
     522,   130,     0,   135,   128,   136,     0,     0,     0,   131,
       0,     0,   132,     0,     0,   133,   602,   130,   153,   154,
     155,   156,   157,   158,   159,   131,     0,   160,   132,   128,
       0,   133,     0,   128,     0,     0,   135,     0,   136,     0,
       0,   129,   130,     0,     0,   129,   130,     0,     0,     0,
     131,   128,     0,   132,   131,     0,   133,   132,     0,     0,
     133,     0,     0,   129,   130,     0,     0,   523,   524,   525,
     526,     0,   131,     0,     0,   132,     0,     0,   133,     0,
       0,     0,     0,   603,   604,   605,   606,     0,   182,   183,
     184,   185,   186,   187,   188,   182,   183,   184,   185,   186,
     187,   188,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   547,   548,     0,     0,   135,     0,   136,     0,
       0,   182,   183,   184,   185,   186,   187,   188,     0,     0,
     555,   556,   135,     0,   136,     0,     0,     0,     0,   280,
     281,   282,   283,   284,   285,   286,     0,     0,   287,     0,
     549,   550,   551,   552,   553,     0,     0,   135,     0,   136,
       0,   135,   128,   136,     0,     0,     0,     0,   557,   558,
     559,   560,   561,     0,   129,   130,     0,     0,   128,   135,
       0,   136,     0,   131,     0,   128,   132,     0,     0,   133,
     129,   130,     0,     0,     0,   128,     0,   129,   130,   131,
       0,     0,   132,     0,     0,   133,   131,   129,   130,   132,
       0,   128,   133,     0,     0,     0,   131,     0,     0,   132,
       0,     0,   133,   129,   130,     0,     0,   128,     0,     0,
       0,     0,   131,     0,     0,   132,     0,     0,   133,   129,
     130,     0,     0,   563,   564,     0,     0,     0,   131,     0,
       0,   132,     0,     0,   133,     0,     0,     0,   366,   571,
     572,     0,   367,   368,     0,     0,     0,     0,   372,     0,
       0,     0,   373,   374,     0,     0,     0,     0,     0,   565,
     566,   567,   568,   569,   395,     0,     0,     0,   396,   397,
     135,     0,   136,     0,     0,   573,   574,   575,   576,   577,
     399,     0,     0,     0,   400,   401,   135,   128,   136,     0,
       0,     0,     0,   135,     0,   136,     0,     0,     0,   129,
     130,   531,     0,   135,   128,   136,     0,     0,   131,     0,
       0,   132,     0,     0,   133,     0,   595,   130,     0,   135,
     128,   136,     0,     0,     0,   131,     0,   128,   132,     0,
       0,   133,   129,   130,     0,   135,     0,   136,     0,   129,
     130,   131,     0,     0,   132,   128,     0,   133,   131,     0,
       0,   132,     0,     0,   133,     0,     0,   129,   130,     0,
     402,     0,   128,     0,   403,   404,   131,   128,     0,   132,
       0,     0,   133,     0,   129,   130,     0,   596,     0,   129,
     130,   238,   239,   131,     0,     0,   132,     0,   131,   133,
       0,   132,     0,   648,   133,     0,     0,   649,   650,     0,
     651,     0,     0,     0,   652,   653,   182,   183,   184,   185,
     186,   187,   188,     0,     0,   135,     0,   136,   656,     0,
       0,     0,   657,   658,     0,   128,     0,     0,     0,     0,
       0,     0,   135,   617,   136,   659,     0,   129,   130,   660,
     661,   128,     0,     0,     0,     0,   131,     0,   135,   132,
     136,     0,   133,   129,   130,   135,     0,   136,   128,     0,
       0,     0,   131,     0,     0,   132,     0,   236,   133,     0,
     129,   130,     0,   135,     0,   136,     0,     0,     0,   131,
       0,     0,   132,     0,     0,   133,     0,     0,   128,     0,
     135,     0,   136,     0,   450,   135,     0,   136,   672,     0,
     129,   130,   673,   674,     0,     0,     0,     0,     0,   131,
       0,     0,   132,     0,   698,   133,     0,     0,   699,   700,
       0,     0,     0,     0,     0,     0,     0,   237,   172,   173,
     174,   175,   238,   239,   240,   241,   242,   243,   182,   183,
     184,   185,   186,   187,   188,   320,   321,   322,   323,   324,
     325,   326,   327,   135,     0,   136,   328,   329,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   135,
       0,   136,   182,   183,   184,   185,   186,   187,   188,   244,
     245,   246,     0,     0,     0,   453,   135,     0,   136,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,     0,     0,     0,   328,   329,     0,   715,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   172,
     173,   174,   175,   296,   297,   298,   299,   300,   301,     0,
       0,     0,     0,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,     0,     0,     0,   328,   329,
       0,     0,     0,   182,   183,   184,   185,   186,   187,   188,
     370,     0,     0,   182,   183,   184,   185,   186,   187,   188,
       0,     0,     0,     0,     0,   330,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,     0,     0,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   371,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,     0,   331,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   405,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   430,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   482,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   543,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,     0,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
     643,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   718,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   719,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   720,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   721,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   740,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   741,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   742,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   743,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   744,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   745,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   746,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   747,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   748,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   749,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   759,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   760,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   772,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   773,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   777,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   779,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   780,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   781,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   782,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   786,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   787,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   788,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   789,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   793,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   794,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   795,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   796,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   800,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   801,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   803,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   804,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   826,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   827,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   828,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   829,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   830,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   831,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   832,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   833,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   834,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   835,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   836,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   837,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   838,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   839,   330,
       0,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   844,     0,   330,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   845,     0,   330,   328,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   846,   330,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   847,     0,   330,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   848,
       0,   330,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,     0,   330,
       0,   328,   329,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   331,     0,     0,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,   236,     5,     6,    55,     9,   137,     8,
      40,    12,   137,    14,     8,     8,    46,     8,    21,    21,
      22,    20,    23,   137,    25,   136,    20,    20,    30,    20,
       8,    33,    81,    21,    36,    82,    48,    82,     8,     9,
      41,    42,    20,    82,    45,    46,    47,    86,    87,    82,
      83,    84,    85,    86,    87,    56,    57,    58,    59,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     9,     0,    74,    23,    24,    77,    78,    81,   126,
      25,   126,    85,    21,    22,     8,    35,   126,    33,    34,
      35,    36,    30,   126,     8,    33,    41,    20,    36,    18,
      19,    50,     8,     8,    23,    24,    20,    31,    53,   137,
      55,    56,    57,    58,    20,    20,     3,     4,     5,     6,
       7,    66,    23,    24,    69,    35,   128,   128,    82,   130,
      75,    21,    86,    87,    79,   137,    81,   139,    25,    26,
      27,    28,    35,    92,    31,    32,    24,    34,    83,    35,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   394,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     8,    35,    35,    35,   136,   137,
     201,   139,    21,    35,    35,    92,    20,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     8,     8,    35,   236,   126,   127,   128,   129,
     130,   131,   132,     9,    20,    20,    16,    17,    18,    19,
     137,   138,    35,    23,    24,    21,    22,   126,   127,   128,
     129,   130,   131,   132,    30,    20,     9,    33,    35,    31,
      36,    81,    82,     9,    84,    85,    86,    87,    21,    22,
      82,    83,    84,    85,    82,    21,    22,    30,    86,    87,
      33,    35,    20,    36,    30,   344,    35,    33,    35,   348,
      36,   350,    35,   304,    35,   306,    35,   126,   127,   128,
     129,   130,   131,   132,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,    82,    35,    35,    35,
      86,    87,   343,    35,   345,    35,    35,    35,   349,   582,
      35,     9,   353,   119,   120,   121,   122,   123,   124,   125,
      35,    82,   128,    21,    22,    86,    87,    35,   369,    35,
      35,   137,    30,   139,   375,    33,    81,    82,    36,    84,
      85,    86,    87,   384,   385,   386,   387,   388,    35,    35,
     391,   392,   393,   394,   137,    35,   139,   398,   343,    35,
     345,   137,    82,   139,   349,    82,    86,    87,   353,    86,
      87,    35,    35,    20,   415,   416,   417,   418,   419,    20,
       8,     8,   423,    21,   369,   370,   371,     9,     8,    20,
      88,    89,    90,    91,    83,    84,    85,    82,    87,    21,
      22,    86,    87,     8,    20,    82,     8,   392,    30,    86,
      87,    33,     8,   398,    36,     8,   457,    20,   459,     8,
     405,   462,    82,   464,   126,     9,    86,    87,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    21,    22,   137,
      20,   139,     8,    82,    20,     9,    30,    86,    87,    33,
      82,     8,    36,    20,    86,    87,     8,    21,    22,    20,
      82,    20,    84,    85,    86,    87,    30,   508,   509,    33,
     511,   512,    36,   514,   515,     8,   517,   518,    82,   520,
     521,    82,    86,    87,    20,    86,    87,     9,   126,   127,
     128,   129,   130,   131,   132,    20,    20,   538,   539,    21,
      22,    82,   126,   544,   545,    86,    87,     9,    30,    20,
       8,    33,     8,    20,    36,   137,     8,   139,     8,    21,
      22,    20,     8,    20,    88,    89,    90,    91,    30,     8,
       8,    33,    20,     8,    36,    83,    84,    85,    86,    20,
      93,   582,   126,   127,   128,   129,   130,   131,   132,    20,
      82,     8,   593,   137,   595,   139,     8,    20,    35,   600,
     601,    35,   126,   127,   128,   129,   130,   131,   132,   610,
     611,    35,   613,   137,   615,   139,    35,    35,     9,   620,
     621,    35,   623,   624,    35,    20,    88,    89,    90,    91,
      21,    22,     8,   634,   635,     9,     8,    20,   639,    30,
     641,     8,    33,     8,     8,    36,   126,    21,    22,    20,
      20,    20,     8,     8,   136,   137,    30,   139,    20,    33,
       8,    21,    36,    20,   126,   127,   128,   129,   130,   131,
     132,     8,     8,   126,    20,   137,     9,   139,    20,   126,
       9,    20,   683,     8,     8,    20,     8,     8,    21,    22,
      20,    82,    21,    22,     8,    86,    87,    30,    85,    31,
      33,    30,    20,    36,    33,    31,    83,    36,    82,   654,
      84,    85,    86,    87,    31,   119,   120,   121,   122,   123,
     124,   125,   723,   724,   128,   726,   727,    35,    35,    38,
     731,    -1,   733,    -1,    -1,   736,    -1,   738,   683,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,    -1,
     751,   752,    -1,   754,   755,    -1,   757,   758,    -1,    88,
      89,    90,    91,   137,    -1,   139,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   778,    -1,    -1,
      -1,    -1,    -1,   784,   785,    -1,    -1,    -1,    -1,    -1,
     791,   792,     3,     4,     5,     6,     7,   126,   127,   128,
     129,   130,   131,   132,   137,    21,   139,    -1,   137,    -1,
     139,    -1,    -1,    -1,    25,    26,    27,    28,   819,   820,
      31,    32,    -1,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,   819,   820,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     9,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      21,    22,    -1,    -1,     9,    -1,   137,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    36,    21,    22,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      -1,    36,    21,    22,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    -1,    36,    21,    22,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    36,    21,    22,    -1,    88,    89,    90,
      91,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    36,
      -1,    -1,    -1,    88,    89,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    21,    -1,
      -1,    -1,   137,     9,   139,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    21,    22,    -1,   137,     9,
     139,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,
      36,    21,    22,   136,   137,     9,   139,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    -1,    36,    21,    22,   136,
     137,    -1,   139,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,     9,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
      21,    22,    88,    89,    90,    91,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    36,    -1,    -1,    88,    89,
      90,    91,    -1,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,   139,    -1,    -1,   126,   127,   128,   129,
     130,   131,   132,    21,    -1,    -1,    -1,   137,     9,   139,
      21,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
      21,    22,    -1,   137,     9,   139,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    36,    21,    22,   119,   120,
     121,   122,   123,   124,   125,    30,    -1,   128,    33,     9,
      -1,    36,    -1,     9,    -1,    -1,   137,    -1,   139,    -1,
      -1,    21,    22,    -1,    -1,    21,    22,    -1,    -1,    -1,
      30,     9,    -1,    33,    30,    -1,    36,    33,    -1,    -1,
      36,    -1,    -1,    21,    22,    -1,    -1,    88,    89,    90,
      91,    -1,    30,    -1,    -1,    33,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    -1,   126,   127,
     128,   129,   130,   131,   132,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    88,    89,    -1,    -1,   137,    -1,   139,    -1,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      88,    89,   137,    -1,   139,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,   128,    -1,
     126,   127,   128,   129,   130,    -1,    -1,   137,    -1,   139,
      -1,   137,     9,   139,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    21,    22,    -1,    -1,     9,   137,
      -1,   139,    -1,    30,    -1,     9,    33,    -1,    -1,    36,
      21,    22,    -1,    -1,    -1,     9,    -1,    21,    22,    30,
      -1,    -1,    33,    -1,    -1,    36,    30,    21,    22,    33,
      -1,     9,    36,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    -1,    36,    21,    22,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    36,    21,
      22,    -1,    -1,    90,    91,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    36,    -1,    -1,    -1,    82,    90,
      91,    -1,    86,    87,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    82,    -1,    -1,    -1,    86,    87,
     137,    -1,   139,    -1,    -1,   126,   127,   128,   129,   130,
      82,    -1,    -1,    -1,    86,    87,   137,     9,   139,    -1,
      -1,    -1,    -1,   137,    -1,   139,    -1,    -1,    -1,    21,
      22,    21,    -1,   137,     9,   139,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    36,    -1,    21,    22,    -1,   137,
       9,   139,    -1,    -1,    -1,    30,    -1,     9,    33,    -1,
      -1,    36,    21,    22,    -1,   137,    -1,   139,    -1,    21,
      22,    30,    -1,    -1,    33,     9,    -1,    36,    30,    -1,
      -1,    33,    -1,    -1,    36,    -1,    -1,    21,    22,    -1,
      82,    -1,     9,    -1,    86,    87,    30,     9,    -1,    33,
      -1,    -1,    36,    -1,    21,    22,    -1,    82,    -1,    21,
      22,    86,    87,    30,    -1,    -1,    33,    -1,    30,    36,
      -1,    33,    -1,    82,    36,    -1,    -1,    86,    87,    -1,
      82,    -1,    -1,    -1,    86,    87,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,   137,    -1,   139,    82,    -1,
      -1,    -1,    86,    87,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    21,   139,    82,    -1,    21,    22,    86,
      87,     9,    -1,    -1,    -1,    -1,    30,    -1,   137,    33,
     139,    -1,    36,    21,    22,   137,    -1,   139,     9,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    21,    36,    -1,
      21,    22,    -1,   137,    -1,   139,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    36,    -1,    -1,     9,    -1,
     137,    -1,   139,    -1,   136,   137,    -1,   139,    82,    -1,
      21,    22,    86,    87,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    82,    36,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   126,   127,
     128,   129,   130,   131,   132,    12,    13,    14,    15,    16,
      17,    18,    19,   137,    -1,   139,    23,    24,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,   137,
      -1,   139,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,   136,   137,    -1,   139,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   139,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      -1,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,   126,   127,   128,   129,   130,   131,   132,
      35,    -1,    -1,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    50,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    92,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    50,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    50,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    50,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    50,
      -1,    23,    24,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    92,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    25,    26,    27,    28,
      31,    32,    34,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    92,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   137,   138,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     9,    21,
      22,    30,    33,    36,   136,   137,   139,   190,   191,   192,
     191,   136,   188,   191,   137,   136,   189,   191,   191,   137,
     137,   136,   191,   119,   120,   121,   122,   123,   124,   125,
     128,   191,   199,    81,    82,    84,    85,    86,    87,   196,
     191,    21,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   126,   127,   128,   129,   130,   131,   132,   193,
     195,    21,    88,    89,    90,    91,   126,   191,   193,    82,
     126,    21,    82,   126,    82,    86,    87,   126,    21,   193,
      21,   193,    21,   193,    21,   193,    86,    87,   196,   199,
      21,    88,    89,    90,    91,   126,   191,   193,   191,   191,
      21,   191,   199,   191,    21,   193,    21,    81,    86,    87,
      88,    89,    90,    91,   133,   134,   135,   193,   194,   195,
      21,    88,    89,    90,    91,   126,   191,   193,    21,    88,
      89,    90,    91,   191,   193,    21,    88,    89,    90,    91,
     191,   193,   191,    21,   193,    21,   193,    21,    81,    85,
     119,   120,   121,   122,   123,   124,   125,   128,   191,   200,
      21,   193,   191,   191,   193,    21,    86,    87,    88,    89,
      90,    91,   193,   195,    48,    31,    48,   147,     0,   146,
      31,   191,   191,   191,   137,    35,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    23,    24,
      50,    92,    35,    35,    24,    35,    35,    82,    86,    87,
      82,    86,    87,    35,    35,    35,   128,   191,    35,    35,
      35,    35,    35,    35,    82,    86,    87,    82,    86,    87,
      82,    86,    87,    82,    86,    87,    82,    86,    87,    35,
      35,    35,    82,    86,    87,    35,    82,    86,    87,    82,
      84,    85,   191,   194,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    82,    86,    87,    35,    82,
      86,    87,    82,    86,    87,    35,    82,    86,    87,    82,
      86,    87,    83,    35,    35,    35,    35,    35,    35,    35,
      82,    86,    87,    35,    82,    86,    87,   191,   191,    31,
      20,   136,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     136,   191,   191,   136,   191,   191,    20,     8,    20,     8,
      20,    20,     8,    20,     8,    20,    21,    88,    89,    90,
      91,   191,   193,   195,    21,    88,    89,    90,    91,   191,
     193,    20,    20,   195,    21,    88,    89,    90,    91,   191,
     193,   195,    83,    84,    85,    86,    83,    84,    85,    87,
      21,    88,    89,    90,    91,   191,   193,    20,     8,     8,
      20,     8,     8,    20,     8,     8,    20,     8,     8,    20,
       8,     8,    21,    88,    89,    90,    91,   191,   193,    21,
     193,    21,   193,    20,    20,    20,   191,    20,     8,     8,
      20,    20,    20,    20,     8,     9,   191,    88,    89,   126,
     127,   128,   129,   130,   191,    88,    89,   126,   127,   128,
     129,   130,   191,    90,    91,   126,   127,   128,   129,   130,
     191,    90,    91,   126,   127,   128,   129,   130,   191,   126,
     126,   191,    21,    88,    89,    90,    91,   133,   134,   191,
     193,   197,   198,    21,   191,    21,    82,   191,   194,    20,
       8,     8,    21,    88,    89,    90,    91,   191,   193,    20,
       8,     8,    20,     8,    20,     8,    20,    21,   193,    20,
       8,     8,    20,     8,     8,    20,    93,    82,   191,   191,
     191,   191,   191,    20,     8,     8,    21,   191,    20,     8,
      20,     8,    20,    31,   191,   191,   191,   191,    82,    86,
      87,    82,    86,    87,    35,    35,    82,    86,    87,    82,
      86,    87,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,    82,    86,    87,    82,    86,    87,    82,    86,
      87,   191,   191,    35,    35,    35,    35,   191,   191,    82,
      84,    85,   191,   194,   191,   191,   191,   191,    82,    86,
      87,   191,   191,   191,   191,    82,    86,    87,   191,   191,
     191,   191,    35,   191,   191,   128,   191,   191,    20,    20,
      20,    20,    20,     8,     8,    20,     8,     8,   193,   126,
      20,     8,    20,     8,    20,    20,     8,    20,     8,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,     8,     8,    20,     8,     8,    20,     8,     8,    20,
      20,   191,   193,   126,   126,    82,    83,    84,    85,    86,
      87,   126,    20,    20,    20,    20,    20,    20,     8,    20,
      20,    20,    20,    20,     8,     8,    20,    20,    20,    20,
      20,     8,     8,    20,    20,    20,    20,    82,    86,    87,
      20,    20,    20,    20,    20,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,    35,
      35,   191,   191,   191,   191,   191,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
     191,   193,   191,   193,    20,    20,    20,    20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   143,   144,   145,   145,   146,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   149,   150,   150,   151,   152,   153,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   157,   157,   157,   157,   158,   158,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   161,   162,   162,   162,   162,   162,   163,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   166,   166,   166,   166,   166,   167,   167,
     167,   167,   167,   167,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     170,   170,   171,   171,   171,   172,   172,   172,   173,   173,
     173,   173,   174,   174,   175,   175,   175,   175,   176,   176,
     176,   176,   177,   177,   177,   177,   178,   178,   178,   178,
     179,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   181,   181,   181,   181,   182,   182,   182,   182,   183,
     183,   183,   183,   184,   184,   184,   184,   185,   185,   185,
     185,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   188,   188,
     188,   188,   189,   189,   189,   189,   190,   190,   190,   190,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     192,   192,   192,   192,   192,   193,   193,   193,   193,   193,
     193,   193,   194,   194,   195,   195,   195,   195,   196,   196,
     196,   196,   197,   197,   198,   198,   199,   199,   199,   199,
     199,   199,   199,   199,   200,   200,   200,   200
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     3,     2,     4,
       1,     2,     2,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     4,     2,     2,     2,     4,
       4,     6,     8,     8,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     6,     8,     8,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     2,     4,     6,     6,     4,     4,     2,     2,
       2,     2,     4,     4,     6,     8,     8,     4,     4,     4,
       4,     6,     8,     8,     4,     2,     4,     2,     2,     4,
       6,     6,     4,     4,     2,     2,     2,     2,     2,     4,
       6,     6,     4,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     4,     6,     6,     6,     2,     6,     4,
       2,     2,     4,     6,     6,     4,     4,     2,     2,     2,
       2,     2,     2,     2,     4,     4,     4,     4,     4,     2,
       4,     4,     4,     4,     4,     6,     4,     8,     6,     6,
       6,     6,     6,     8,     8,     8,     8,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     4,     4,     4,     4,
       6,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     2,     2,     4,     6,     6,     2,     2,     2,
       2,     4,     4,     6,     8,     8,     4,     4,     4,     4,
       6,     6,     2,     2,     2,     2,     2,     2,     4,     6,
       8,     8,     1,     2,     2,     4,     6,     6,     2,     4,
       6,     6,     2,     4,     6,     6,     2,     4,     6,     6,
       2,     4,     4,     6,     8,     8,     4,     4,     4,     4,
       4,     4,     6,     8,     8,     2,     4,     6,     6,     2,
       4,     6,     6,     2,     4,     6,     6,     2,     4,     6,
       6,     2,     2,     4,     6,     6,     2,     2,     2,     2,
       2,     2,     4,     6,     6,     2,     2,     2,     2,     4,
       4,     6,     8,     8,     4,     4,     4,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     3,     3,
       1,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 178 "grammar.y"
                     {  }
#line 2804 "grammar.c"
    break;

  case 3:
#line 180 "grammar.y"
                         {  yylineno++; }
#line 2810 "grammar.c"
    break;

  case 4:
#line 181 "grammar.y"
                                     {  yylineno++; }
#line 2816 "grammar.c"
    break;

  case 5:
#line 183 "grammar.y"
                                                        { prepc = pc;   }
#line 2822 "grammar.c"
    break;

  case 6:
#line 184 "grammar.y"
                                                                { prepc = pc;  outCode(0);  }
#line 2828 "grammar.c"
    break;

  case 7:
#line 185 "grammar.y"
                                                { setLabelAddress((yyvsp[-2].literal),prepc); prepc = pc; }
#line 2834 "grammar.c"
    break;

  case 8:
#line 186 "grammar.y"
                                                        { setLabelAddress((yyvsp[-1].literal),prepc); prepc = pc; outCode(0); }
#line 2840 "grammar.c"
    break;

  case 9:
#line 187 "grammar.y"
                                                { setLabelValue((yyvsp[-3].literal),(yyvsp[-1].normal));  outCode(0);  }
#line 2846 "grammar.c"
    break;

  case 10:
#line 190 "grammar.y"
                                                { }
#line 2852 "grammar.c"
    break;

  case 11:
#line 191 "grammar.y"
                                                                        { condStatus = ((yyvsp[0].normal)==0)?0:1; }
#line 2858 "grammar.c"
    break;

  case 12:
#line 192 "grammar.y"
                                                                { condStatus = (LookupTableLabels((yyvsp[0].literal))<0)?0:1; }
#line 2864 "grammar.c"
    break;

  case 13:
#line 193 "grammar.y"
                                                                { condStatus = (LookupTableLabels((yyvsp[0].literal))<0)?1:0; }
#line 2870 "grammar.c"
    break;

  case 14:
#line 194 "grammar.y"
                                                                        { if (condStatus < 0) { fatalError("Syntax error. Detected ENDIF without IF"); } condStatus = -1; }
#line 2876 "grammar.c"
    break;

  case 15:
#line 195 "grammar.y"
                                                                {  fprintf(stderr,">>DIRECTIVE ERROR in line: %d ::: %s\n",yylineno,(yyvsp[0].literal)); exit(EXIT_FAILURE); }
#line 2882 "grammar.c"
    break;

  case 16:
#line 196 "grammar.y"
                                                { return 0; /* we should stop here compilation */}
#line 2888 "grammar.c"
    break;

  case 17:
#line 197 "grammar.y"
                                                        { return 0; /* MISSING, in order to allow entry point definition */ }
#line 2894 "grammar.c"
    break;

  case 18:
#line 198 "grammar.y"
                                                { }
#line 2900 "grammar.c"
    break;

  case 19:
#line 199 "grammar.y"
                                                { }
#line 2906 "grammar.c"
    break;

  case 20:
#line 200 "grammar.y"
                                                { }
#line 2912 "grammar.c"
    break;

  case 21:
#line 201 "grammar.y"
                                                { }
#line 2918 "grammar.c"
    break;

  case 22:
#line 202 "grammar.y"
                                                { }
#line 2924 "grammar.c"
    break;

  case 23:
#line 203 "grammar.y"
                                                                { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal));  }
#line 2930 "grammar.c"
    break;

  case 24:
#line 204 "grammar.y"
                                                { int k = (((pc/(yyvsp[0].normal))+1)*(yyvsp[0].normal)); for(int a=pc; a < k; a++) { outCode(1,0x0); } }
#line 2936 "grammar.c"
    break;

  case 25:
#line 207 "grammar.y"
                                    {  }
#line 2942 "grammar.c"
    break;

  case 26:
#line 208 "grammar.y"
                                    {  }
#line 2948 "grammar.c"
    break;

  case 27:
#line 209 "grammar.y"
                                    {  }
#line 2954 "grammar.c"
    break;

  case 28:
#line 210 "grammar.y"
                                    {  }
#line 2960 "grammar.c"
    break;

  case 29:
#line 211 "grammar.y"
                                    {  }
#line 2966 "grammar.c"
    break;

  case 30:
#line 212 "grammar.y"
                                    {  }
#line 2972 "grammar.c"
    break;

  case 31:
#line 213 "grammar.y"
                                    {  }
#line 2978 "grammar.c"
    break;

  case 32:
#line 214 "grammar.y"
                                {  }
#line 2984 "grammar.c"
    break;

  case 33:
#line 215 "grammar.y"
                                {  }
#line 2990 "grammar.c"
    break;

  case 34:
#line 216 "grammar.y"
                                {  }
#line 2996 "grammar.c"
    break;

  case 35:
#line 217 "grammar.y"
                                {  }
#line 3002 "grammar.c"
    break;

  case 36:
#line 218 "grammar.y"
                                {  }
#line 3008 "grammar.c"
    break;

  case 37:
#line 219 "grammar.y"
                                {  }
#line 3014 "grammar.c"
    break;

  case 38:
#line 220 "grammar.y"
                                {  }
#line 3020 "grammar.c"
    break;

  case 39:
#line 221 "grammar.y"
                                {  }
#line 3026 "grammar.c"
    break;

  case 40:
#line 222 "grammar.y"
                                {  }
#line 3032 "grammar.c"
    break;

  case 41:
#line 223 "grammar.y"
                                {  }
#line 3038 "grammar.c"
    break;

  case 42:
#line 224 "grammar.y"
                                {  }
#line 3044 "grammar.c"
    break;

  case 43:
#line 225 "grammar.y"
                                {  }
#line 3050 "grammar.c"
    break;

  case 44:
#line 226 "grammar.y"
                                {  }
#line 3056 "grammar.c"
    break;

  case 45:
#line 227 "grammar.y"
                                {  }
#line 3062 "grammar.c"
    break;

  case 46:
#line 228 "grammar.y"
                                {  }
#line 3068 "grammar.c"
    break;

  case 47:
#line 229 "grammar.y"
                                {  }
#line 3074 "grammar.c"
    break;

  case 48:
#line 230 "grammar.y"
                                {  }
#line 3080 "grammar.c"
    break;

  case 49:
#line 231 "grammar.y"
                                {  }
#line 3086 "grammar.c"
    break;

  case 50:
#line 232 "grammar.y"
                                {  }
#line 3092 "grammar.c"
    break;

  case 51:
#line 233 "grammar.y"
                                {  }
#line 3098 "grammar.c"
    break;

  case 52:
#line 234 "grammar.y"
                                {  }
#line 3104 "grammar.c"
    break;

  case 53:
#line 235 "grammar.y"
                                {  }
#line 3110 "grammar.c"
    break;

  case 54:
#line 236 "grammar.y"
                                {  }
#line 3116 "grammar.c"
    break;

  case 55:
#line 237 "grammar.y"
                                {  }
#line 3122 "grammar.c"
    break;

  case 56:
#line 238 "grammar.y"
                                {  }
#line 3128 "grammar.c"
    break;

  case 57:
#line 239 "grammar.y"
                                {  }
#line 3134 "grammar.c"
    break;

  case 58:
#line 240 "grammar.y"
                                {  }
#line 3140 "grammar.c"
    break;

  case 59:
#line 241 "grammar.y"
                                { outCode(1,0x3F); }
#line 3146 "grammar.c"
    break;

  case 60:
#line 242 "grammar.y"
                                { outCode(2,0xED,0xA9); }
#line 3152 "grammar.c"
    break;

  case 61:
#line 243 "grammar.y"
                                { outCode(2,0xED,0xB9); }
#line 3158 "grammar.c"
    break;

  case 62:
#line 244 "grammar.y"
                                { outCode(2,0xED,0xA1); }
#line 3164 "grammar.c"
    break;

  case 63:
#line 245 "grammar.y"
                                { outCode(2,0xED,0xB1); }
#line 3170 "grammar.c"
    break;

  case 64:
#line 246 "grammar.y"
                                { outCode(1,0x2F); }
#line 3176 "grammar.c"
    break;

  case 65:
#line 247 "grammar.y"
                                { outCode(1,0x27); }
#line 3182 "grammar.c"
    break;

  case 66:
#line 248 "grammar.y"
                                { outCode(1,0xF3); }
#line 3188 "grammar.c"
    break;

  case 67:
#line 249 "grammar.y"
                                { outCode(1,0xFB); }
#line 3194 "grammar.c"
    break;

  case 68:
#line 250 "grammar.y"
                                { outCode(1,0xD9); }
#line 3200 "grammar.c"
    break;

  case 69:
#line 251 "grammar.y"
                                { outCode(1,0x76); }
#line 3206 "grammar.c"
    break;

  case 70:
#line 252 "grammar.y"
                                { outCode(2,0xED,0xAA); }
#line 3212 "grammar.c"
    break;

  case 71:
#line 253 "grammar.y"
                                { outCode(2,0xED,0xBA); }
#line 3218 "grammar.c"
    break;

  case 72:
#line 254 "grammar.y"
                                { outCode(2,0xED,0xA2); }
#line 3224 "grammar.c"
    break;

  case 73:
#line 255 "grammar.y"
                                { outCode(2,0xED,0xB2); }
#line 3230 "grammar.c"
    break;

  case 74:
#line 256 "grammar.y"
                                    { outCode(2,0xED,0xA8); }
#line 3236 "grammar.c"
    break;

  case 75:
#line 257 "grammar.y"
                                    { outCode(2,0xED,0xB8); }
#line 3242 "grammar.c"
    break;

  case 76:
#line 258 "grammar.y"
                                    { outCode(2,0xED,0xA0); }
#line 3248 "grammar.c"
    break;

  case 77:
#line 259 "grammar.y"
                                    { outCode(2,0xED,0xB0); }
#line 3254 "grammar.c"
    break;

  case 78:
#line 260 "grammar.y"
                                    { outCode(2,0xED,0x44); }
#line 3260 "grammar.c"
    break;

  case 79:
#line 261 "grammar.y"
                                    { outCode(1,0x00);      }
#line 3266 "grammar.c"
    break;

  case 80:
#line 262 "grammar.y"
                                    { outCode(2,0xED,0xBB); }
#line 3272 "grammar.c"
    break;

  case 81:
#line 263 "grammar.y"
                                    { outCode(2,0xED,0xB3); }
#line 3278 "grammar.c"
    break;

  case 82:
#line 264 "grammar.y"
                                    { outCode(2,0xED,0xAB); }
#line 3284 "grammar.c"
    break;

  case 83:
#line 265 "grammar.y"
                                    { outCode(2,0xED,0xA3); }
#line 3290 "grammar.c"
    break;

  case 84:
#line 266 "grammar.y"
                                    { outCode(2,0xED,0x4D); }
#line 3296 "grammar.c"
    break;

  case 85:
#line 267 "grammar.y"
                                    { outCode(2,0xED,0x45); }
#line 3302 "grammar.c"
    break;

  case 86:
#line 268 "grammar.y"
                                    { outCode(1,0x17);      }
#line 3308 "grammar.c"
    break;

  case 87:
#line 269 "grammar.y"
                                    { outCode(1,0x07);      }
#line 3314 "grammar.c"
    break;

  case 88:
#line 270 "grammar.y"
                                    { outCode(2,0xED,0x6F); }
#line 3320 "grammar.c"
    break;

  case 89:
#line 271 "grammar.y"
                                    { outCode(1,0x1F);      }
#line 3326 "grammar.c"
    break;

  case 90:
#line 272 "grammar.y"
                                    { outCode(1,0x0F);      }
#line 3332 "grammar.c"
    break;

  case 91:
#line 273 "grammar.y"
                                    { outCode(2,0xED,0x67); }
#line 3338 "grammar.c"
    break;

  case 92:
#line 274 "grammar.y"
                                    { outCode(1,0x37); }
#line 3344 "grammar.c"
    break;

  case 93:
#line 278 "grammar.y"
                                                 { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal)); }
#line 3350 "grammar.c"
    break;

  case 94:
#line 280 "grammar.y"
                                                 { for(int a=0;a<abs((yyvsp[0].normal));a++) { outCode(1,0x0); } }
#line 3356 "grammar.c"
    break;

  case 95:
#line 281 "grammar.y"
                                            {  for(int a=0;a<abs((yyvsp[-2].normal));a++) { outCode(1,(yyvsp[0].normal)); }  }
#line 3362 "grammar.c"
    break;

  case 96:
#line 283 "grammar.y"
                                           { for(int a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3368 "grammar.c"
    break;

  case 97:
#line 285 "grammar.y"
                                           { for(int a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3374 "grammar.c"
    break;

  case 98:
#line 287 "grammar.y"
                                       { for(int a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3380 "grammar.c"
    break;

  case 99:
#line 289 "grammar.y"
                                      { outCode(2,0xCE,(yyvsp[0].normal)); }
#line 3386 "grammar.c"
    break;

  case 100:
#line 290 "grammar.y"
                                           { int k = (((yyvsp[0].byte))|128|8); outCode(1,k); }
#line 3392 "grammar.c"
    break;

  case 101:
#line 291 "grammar.y"
                                                   { outCode(1,0x8E); }
#line 3398 "grammar.c"
    break;

  case 102:
#line 292 "grammar.y"
                                                             { outCode(3,0xDD,0x8E,(yyvsp[-1].normal)); }
#line 3404 "grammar.c"
    break;

  case 103:
#line 293 "grammar.y"
                                                             { outCode(3,0xFD,0x8E,(yyvsp[-1].normal)); }
#line 3410 "grammar.c"
    break;

  case 104:
#line 294 "grammar.y"
                                                   { outCode(3,0xDD,0x8E,0); }
#line 3416 "grammar.c"
    break;

  case 105:
#line 295 "grammar.y"
                                                   { outCode(3,0xFD,0x8E,0); }
#line 3422 "grammar.c"
    break;

  case 106:
#line 296 "grammar.y"
                                           { int k = (((yyvsp[0].byte)<<4)|64|8|2); outCode(2,0xED,k); }
#line 3428 "grammar.c"
    break;

  case 107:
#line 297 "grammar.y"
                                           {  outCode(2,0xDD,0x8C); }
#line 3434 "grammar.c"
    break;

  case 108:
#line 298 "grammar.y"
                                           {  outCode(2,0xDD,0x8D); }
#line 3440 "grammar.c"
    break;

  case 109:
#line 299 "grammar.y"
                                           {  outCode(2,0xFD,0x8C); }
#line 3446 "grammar.c"
    break;

  case 110:
#line 300 "grammar.y"
                                           {  outCode(2,0xFD,0x8D); }
#line 3452 "grammar.c"
    break;

  case 111:
#line 302 "grammar.y"
                                      { outCode(2,0xC6,(yyvsp[0].normal)); }
#line 3458 "grammar.c"
    break;

  case 112:
#line 303 "grammar.y"
                                           { int k = (((yyvsp[0].byte))|128); outCode(1,k); }
#line 3464 "grammar.c"
    break;

  case 113:
#line 304 "grammar.y"
                                                   { outCode(1,0x86); }
#line 3470 "grammar.c"
    break;

  case 114:
#line 305 "grammar.y"
                                                             { outCode(3,0xDD,0x86,(yyvsp[-1].normal)); }
#line 3476 "grammar.c"
    break;

  case 115:
#line 306 "grammar.y"
                                                             { outCode(3,0xFD,0x86,(yyvsp[-1].normal)); }
#line 3482 "grammar.c"
    break;

  case 116:
#line 307 "grammar.y"
                                                   { outCode(3,0xDD,0x86,0); }
#line 3488 "grammar.c"
    break;

  case 117:
#line 308 "grammar.y"
                                                   { outCode(3,0xFD,0x86,0); }
#line 3494 "grammar.c"
    break;

  case 118:
#line 309 "grammar.y"
                                           { int k = (((yyvsp[0].byte)<<4)|8|1); outCode(1,k); }
#line 3500 "grammar.c"
    break;

  case 119:
#line 310 "grammar.y"
                                           { outCode(2,0xDD,0x09); }
#line 3506 "grammar.c"
    break;

  case 120:
#line 311 "grammar.y"
                                           { outCode(2,0xDD,0x19); }
#line 3512 "grammar.c"
    break;

  case 121:
#line 312 "grammar.y"
                                           { outCode(2,0xDD,0x29); }
#line 3518 "grammar.c"
    break;

  case 122:
#line 313 "grammar.y"
                                           { outCode(2,0xDD,0x39); }
#line 3524 "grammar.c"
    break;

  case 123:
#line 314 "grammar.y"
                                           { outCode(2,0xFD,0x09); }
#line 3530 "grammar.c"
    break;

  case 124:
#line 315 "grammar.y"
                                           { outCode(2,0xFD,0x19); }
#line 3536 "grammar.c"
    break;

  case 125:
#line 316 "grammar.y"
                                           { outCode(2,0xFD,0x29); }
#line 3542 "grammar.c"
    break;

  case 126:
#line 317 "grammar.y"
                                           { outCode(2,0xFD,0x39); }
#line 3548 "grammar.c"
    break;

  case 127:
#line 318 "grammar.y"
                                           {  outCode(2,0xDD,0x84); }
#line 3554 "grammar.c"
    break;

  case 128:
#line 319 "grammar.y"
                                           {  outCode(2,0xDD,0x85); }
#line 3560 "grammar.c"
    break;

  case 129:
#line 320 "grammar.y"
                                           {  outCode(2,0xFD,0x84); }
#line 3566 "grammar.c"
    break;

  case 130:
#line 321 "grammar.y"
                                           {  outCode(2,0xFD,0x85); }
#line 3572 "grammar.c"
    break;

  case 131:
#line 323 "grammar.y"
                              { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3578 "grammar.c"
    break;

  case 132:
#line 324 "grammar.y"
                                   { int k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3584 "grammar.c"
    break;

  case 133:
#line 325 "grammar.y"
                                           { outCode(1,0xA6); }
#line 3590 "grammar.c"
    break;

  case 134:
#line 326 "grammar.y"
                                                     { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3596 "grammar.c"
    break;

  case 135:
#line 327 "grammar.y"
                                                     { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3602 "grammar.c"
    break;

  case 136:
#line 328 "grammar.y"
                                           { outCode(3,0xDD,0xA6,0); }
#line 3608 "grammar.c"
    break;

  case 137:
#line 329 "grammar.y"
                                           { outCode(3,0xFD,0xA6,0); }
#line 3614 "grammar.c"
    break;

  case 138:
#line 331 "grammar.y"
                                    { outCode(2,0xDD,0xA4); }
#line 3620 "grammar.c"
    break;

  case 139:
#line 332 "grammar.y"
                                    { outCode(2,0xDD,0xA5); }
#line 3626 "grammar.c"
    break;

  case 140:
#line 333 "grammar.y"
                                    { outCode(2,0xFD,0xA4); }
#line 3632 "grammar.c"
    break;

  case 141:
#line 334 "grammar.y"
                                    { outCode(2,0xFD,0xA5); }
#line 3638 "grammar.c"
    break;

  case 142:
#line 335 "grammar.y"
                                      { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3644 "grammar.c"
    break;

  case 143:
#line 336 "grammar.y"
                                           { int k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3650 "grammar.c"
    break;

  case 144:
#line 337 "grammar.y"
                                                   { outCode(1,0xA6); }
#line 3656 "grammar.c"
    break;

  case 145:
#line 338 "grammar.y"
                                                             { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3662 "grammar.c"
    break;

  case 146:
#line 339 "grammar.y"
                                                             { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3668 "grammar.c"
    break;

  case 147:
#line 340 "grammar.y"
                                            { outCode(2,0xDD,0xA4); }
#line 3674 "grammar.c"
    break;

  case 148:
#line 341 "grammar.y"
                                            { outCode(2,0xDD,0xA5); }
#line 3680 "grammar.c"
    break;

  case 149:
#line 342 "grammar.y"
                                            { outCode(2,0xFD,0xA4); }
#line 3686 "grammar.c"
    break;

  case 150:
#line 343 "grammar.y"
                                            { outCode(2,0xFD,0xA5); }
#line 3692 "grammar.c"
    break;

  case 151:
#line 345 "grammar.y"
                                                      { if ((yyvsp[-4].normal) > 7) { warningError("Bit number is bigger out of range, truncating"); } outCode(2,0xCB,(((yyvsp[-4].normal)<<3)|64|6)); }
#line 3698 "grammar.c"
    break;

  case 152:
#line 346 "grammar.y"
                                                                { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xDD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3704 "grammar.c"
    break;

  case 153:
#line 347 "grammar.y"
                                                                { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xFD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3710 "grammar.c"
    break;

  case 154:
#line 348 "grammar.y"
                                   { 	if ((yyvsp[-2].normal)>7) { warningError("Bit number is bigger out of range, truncating"); }
                                            outCode(2,0xCB,(((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|64));
                                        }
#line 3718 "grammar.c"
    break;

  case 155:
#line 353 "grammar.y"
                               { outCode(3,0xCD,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3724 "grammar.c"
    break;

  case 156:
#line 354 "grammar.y"
                                       { outCode(3, (((yyvsp[-2].byte)<<3)|128|64|4),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3730 "grammar.c"
    break;

  case 157:
#line 356 "grammar.y"
                            { outCode(2,0xFE,(yyvsp[0].normal)); }
#line 3736 "grammar.c"
    break;

  case 158:
#line 357 "grammar.y"
                                  { int k = (((yyvsp[0].byte))|128|32|16|8); outCode(1,k); }
#line 3742 "grammar.c"
    break;

  case 159:
#line 358 "grammar.y"
                                          { outCode(1,0xBE); }
#line 3748 "grammar.c"
    break;

  case 160:
#line 359 "grammar.y"
                                                    { outCode(3,0xDD,0xBE,(yyvsp[-1].normal)); }
#line 3754 "grammar.c"
    break;

  case 161:
#line 360 "grammar.y"
                                                    { outCode(3,0xFD,0xBE,(yyvsp[-1].normal)); }
#line 3760 "grammar.c"
    break;

  case 162:
#line 361 "grammar.y"
                                          { outCode(3,0xDD,0xBE,0); }
#line 3766 "grammar.c"
    break;

  case 163:
#line 362 "grammar.y"
                                          { outCode(3,0xFD,0xBE,0); }
#line 3772 "grammar.c"
    break;

  case 164:
#line 363 "grammar.y"
                                  {  outCode(2,0xDD,0xBC); }
#line 3778 "grammar.c"
    break;

  case 165:
#line 364 "grammar.y"
                                  {  outCode(2,0xDD,0xBD); }
#line 3784 "grammar.c"
    break;

  case 166:
#line 365 "grammar.y"
                                  {  outCode(2,0xFD,0xBC); }
#line 3790 "grammar.c"
    break;

  case 167:
#line 366 "grammar.y"
                                  {  outCode(2,0xFD,0xBD); }
#line 3796 "grammar.c"
    break;

  case 168:
#line 368 "grammar.y"
                                   { int k = (((yyvsp[0].byte)<<3)|4|1); outCode(1,k); }
#line 3802 "grammar.c"
    break;

  case 169:
#line 369 "grammar.y"
                                           { outCode(1,0x35); }
#line 3808 "grammar.c"
    break;

  case 170:
#line 370 "grammar.y"
                                                     { outCode(3,0xDD,0x35,(yyvsp[-1].normal)); }
#line 3814 "grammar.c"
    break;

  case 171:
#line 371 "grammar.y"
                                                     { outCode(3,0xFD,0x35,(yyvsp[-1].normal)); }
#line 3820 "grammar.c"
    break;

  case 172:
#line 372 "grammar.y"
                                           { outCode(3,0xDD,0x35,0); }
#line 3826 "grammar.c"
    break;

  case 173:
#line 373 "grammar.y"
                                           { outCode(3,0xFD,0x35,0); }
#line 3832 "grammar.c"
    break;

  case 174:
#line 374 "grammar.y"
                                   { int k = (((yyvsp[0].byte)<<4)|8|2|1); outCode(1,k); }
#line 3838 "grammar.c"
    break;

  case 175:
#line 375 "grammar.y"
                                   { outCode(2,0xDD,0x2B); }
#line 3844 "grammar.c"
    break;

  case 176:
#line 376 "grammar.y"
                                   { outCode(2,0xFD,0x2B); }
#line 3850 "grammar.c"
    break;

  case 177:
#line 377 "grammar.y"
                                { outCode(1,0xDD,0x25); }
#line 3856 "grammar.c"
    break;

  case 178:
#line 378 "grammar.y"
                                { outCode(1,0xDD,0x2D); }
#line 3862 "grammar.c"
    break;

  case 179:
#line 379 "grammar.y"
                                { outCode(1,0xFD,0x25); }
#line 3868 "grammar.c"
    break;

  case 180:
#line 380 "grammar.y"
                                { outCode(1,0xFD,0x2C); }
#line 3874 "grammar.c"
    break;

  case 181:
#line 383 "grammar.y"
                                           {  outCode(2,0x10,((yyvsp[0].normal) - pc - 2) ); }
#line 3880 "grammar.c"
    break;

  case 182:
#line 386 "grammar.y"
                                        { outCode(1,0x08); }
#line 3886 "grammar.c"
    break;

  case 183:
#line 387 "grammar.y"
                                        { outCode(1,0xEB); }
#line 3892 "grammar.c"
    break;

  case 184:
#line 388 "grammar.y"
                                                         { outCode(1,0xE3); }
#line 3898 "grammar.c"
    break;

  case 185:
#line 389 "grammar.y"
                                                         { outCode(2,0xDD,0xE3); }
#line 3904 "grammar.c"
    break;

  case 186:
#line 390 "grammar.y"
                                                         { outCode(2,0xFD,0xE3); }
#line 3910 "grammar.c"
    break;

  case 187:
#line 392 "grammar.y"
                       { switch((yyvsp[0].normal)) {
                                case 0: outCode(2,0xED,0x46); break;
                                case 1: outCode(2,0xED,0x56); break;
                                case 2: outCode(2,0xED,0x5E); break;
                                default: fatalError("Interruption mode value is out of range: Only allowed 0, 1 or 2"); break;
                               }
                             }
#line 3922 "grammar.c"
    break;

  case 188:
#line 400 "grammar.y"
                                                { outCode(2,0xED,(((yyvsp[-4].byte)<<3)|64)); }
#line 3928 "grammar.c"
    break;

  case 189:
#line 401 "grammar.y"
                                                { outCode(2,0xDB,(yyvsp[0].normal)); if ((yyvsp[-2].byte) != 7) { fatalError("IN only can use the A Register, sorry"); } }
#line 3934 "grammar.c"
    break;

  case 190:
#line 403 "grammar.y"
                                { outCode(1,((yyvsp[0].byte)<<3)|4); }
#line 3940 "grammar.c"
    break;

  case 191:
#line 404 "grammar.y"
                                { outCode(1,(((yyvsp[0].byte)<<4)|1|2));  }
#line 3946 "grammar.c"
    break;

  case 192:
#line 405 "grammar.y"
                                       { outCode(1,0x34); }
#line 3952 "grammar.c"
    break;

  case 193:
#line 406 "grammar.y"
                                                 { outCode(3,0xDD,0x34,(yyvsp[-1].normal)); }
#line 3958 "grammar.c"
    break;

  case 194:
#line 407 "grammar.y"
                                                 { outCode(3,0xFD,0x34,(yyvsp[-1].normal)); }
#line 3964 "grammar.c"
    break;

  case 195:
#line 408 "grammar.y"
                                        { outCode(3,0xDD,0x34,0); }
#line 3970 "grammar.c"
    break;

  case 196:
#line 409 "grammar.y"
                                        { outCode(3,0xFD,0x34,0); }
#line 3976 "grammar.c"
    break;

  case 197:
#line 410 "grammar.y"
                                { outCode(1,0xDD,0x23); }
#line 3982 "grammar.c"
    break;

  case 198:
#line 411 "grammar.y"
                                { outCode(1,0xFD,0x23); }
#line 3988 "grammar.c"
    break;

  case 199:
#line 412 "grammar.y"
                                { outCode(1,0xDD,0x24); }
#line 3994 "grammar.c"
    break;

  case 200:
#line 413 "grammar.y"
                                { outCode(1,0xDD,0x2C); }
#line 4000 "grammar.c"
    break;

  case 201:
#line 414 "grammar.y"
                                { outCode(1,0xFD,0x24); }
#line 4006 "grammar.c"
    break;

  case 202:
#line 415 "grammar.y"
                                { outCode(1,0xFD,0x2C); }
#line 4012 "grammar.c"
    break;

  case 203:
#line 417 "grammar.y"
                                 { outCode(3,0xC3,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4018 "grammar.c"
    break;

  case 204:
#line 418 "grammar.y"
                                 { outCode(3,(((yyvsp[-2].byte)<<3)|128|64|2),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4024 "grammar.c"
    break;

  case 205:
#line 419 "grammar.y"
                                       { outCode(1,0xE9); }
#line 4030 "grammar.c"
    break;

  case 206:
#line 420 "grammar.y"
                                       { outCode(2,0xDD,0xE9); }
#line 4036 "grammar.c"
    break;

  case 207:
#line 421 "grammar.y"
                                       { outCode(2,0xDD,0xE9); }
#line 4042 "grammar.c"
    break;

  case 208:
#line 423 "grammar.y"
                                           { outCode(2,((yyvsp[-2].byte)<<3)|32,((yyvsp[0].normal) - pc - 2)); }
#line 4048 "grammar.c"
    break;

  case 209:
#line 424 "grammar.y"
                                    { outCode(2,0x18, ((yyvsp[0].normal) - pc - 2) ); }
#line 4054 "grammar.c"
    break;

  case 210:
#line 425 "grammar.y"
                                    { fatalError("You cannot use M flag bit in JR instruction"); }
#line 4060 "grammar.c"
    break;

  case 211:
#line 426 "grammar.y"
                                    { fatalError("You cannot use P flag bit in JR instruction"); }
#line 4066 "grammar.c"
    break;

  case 212:
#line 427 "grammar.y"
                                     { fatalError("You cannot use PE flag bit in JR instruction"); }
#line 4072 "grammar.c"
    break;

  case 213:
#line 428 "grammar.y"
                                     { fatalError("You cannot use PO flag bit in JR instruction"); }
#line 4078 "grammar.c"
    break;

  case 214:
#line 431 "grammar.y"
                                                                                                { int k = (((yyvsp[-2].byte) << 3)|64); k = k | (yyvsp[0].byte); outCode(1,k); }
#line 4084 "grammar.c"
    break;

  case 215:
#line 432 "grammar.y"
                                                                        { outCode(3,0x3A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");} }
#line 4090 "grammar.c"
    break;

  case 216:
#line 433 "grammar.y"
                                                                                                        { outCode(2,(((yyvsp[-2].byte) << 3)|6),(yyvsp[0].normal)); }
#line 4096 "grammar.c"
    break;

  case 217:
#line 434 "grammar.y"
                                                                        { outCode(3,(yyvsp[-3].normal),((yyvsp[-6].byte)<<3)|64|4|2,(yyvsp[-1].normal)); }
#line 4102 "grammar.c"
    break;

  case 218:
#line 435 "grammar.y"
                                                                                                { outCode(1,((yyvsp[-4].byte)<<3)|64|4|2); }
#line 4108 "grammar.c"
    break;

  case 219:
#line 436 "grammar.y"
                                                                                                { outCode(1,0x02); }
#line 4114 "grammar.c"
    break;

  case 220:
#line 437 "grammar.y"
                                                                                                { outCode(1,0x12); }
#line 4120 "grammar.c"
    break;

  case 221:
#line 438 "grammar.y"
                                                                                                { outCode(2,0x36,(yyvsp[0].normal)); }
#line 4126 "grammar.c"
    break;

  case 222:
#line 439 "grammar.y"
                                                                                                { outCode(1,(yyvsp[0].byte)|64|32|16); }
#line 4132 "grammar.c"
    break;

  case 223:
#line 440 "grammar.y"
                                                                                { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),(yyvsp[0].normal)); }
#line 4138 "grammar.c"
    break;

  case 224:
#line 441 "grammar.y"
                                                                                { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),(yyvsp[-3].normal)); }
#line 4144 "grammar.c"
    break;

  case 225:
#line 442 "grammar.y"
                                                                                { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),-(yyvsp[0].normal)); }
#line 4150 "grammar.c"
    break;

  case 226:
#line 443 "grammar.y"
                                                                                { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),-(yyvsp[-3].normal)); }
#line 4156 "grammar.c"
    break;

  case 227:
#line 444 "grammar.y"
                                                                                                { outCode(3,0x32,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4162 "grammar.c"
    break;

  case 228:
#line 445 "grammar.y"
                                                                                                { outCode(4,0xED,43,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4168 "grammar.c"
    break;

  case 229:
#line 446 "grammar.y"
                                                                                                { outCode(4,0xED,53,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4174 "grammar.c"
    break;

  case 230:
#line 447 "grammar.y"
                                                                                                { outCode(4,0xED,73,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4180 "grammar.c"
    break;

  case 231:
#line 448 "grammar.y"
                                                                                                { outCode(3,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4186 "grammar.c"
    break;

  case 232:
#line 449 "grammar.y"
                                                                                                { outCode(4,0xDD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4192 "grammar.c"
    break;

  case 233:
#line 450 "grammar.y"
                                                                                                { outCode(3,0xFD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4198 "grammar.c"
    break;

  case 234:
#line 451 "grammar.y"
                                                                                                { outCode(1,0x0A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4204 "grammar.c"
    break;

  case 235:
#line 452 "grammar.y"
                                                                                                { outCode(1,0x1A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4210 "grammar.c"
    break;

  case 236:
#line 453 "grammar.y"
                                                                                                        { outCode(2,0xED,0x57); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4216 "grammar.c"
    break;

  case 237:
#line 454 "grammar.y"
                                                                                                        { outCode(2,0xED,0x47); }
#line 4222 "grammar.c"
    break;

  case 238:
#line 455 "grammar.y"
                                                                                                        { outCode(2,0xED,0x5F); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4228 "grammar.c"
    break;

  case 239:
#line 456 "grammar.y"
                                                                                                        { outCode(2,0xED,0x4F); }
#line 4234 "grammar.c"
    break;

  case 240:
#line 457 "grammar.y"
                                                                                { outCode(4,(yyvsp[-4].normal),0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
#line 4240 "grammar.c"
    break;

  case 241:
#line 458 "grammar.y"
                                                                                        { outCode(4,(yyvsp[-2].normal),0x21,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4246 "grammar.c"
    break;

  case 242:
#line 459 "grammar.y"
                                                                                { 
																		if ((yyvsp[-4].byte) != 2) { outCode(4,0xED,0x4B,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																		else            { outCode(3,0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																	}
#line 4255 "grammar.c"
    break;

  case 243:
#line 463 "grammar.y"
                                                                                                                { outCode(3,((yyvsp[-2].byte)<<4)|1,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4261 "grammar.c"
    break;

  case 244:
#line 465 "grammar.y"
                                                                                                { 
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else { outCode(1,0xF9);  }
																	}
#line 4270 "grammar.c"
    break;

  case 245:
#line 469 "grammar.y"
                                                                                                {
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else  { outCode(2,(yyvsp[0].normal),0xF9); }
																	}
#line 4279 "grammar.c"
    break;

  case 246:
#line 473 "grammar.y"
                                                                                                        { 
		                                                                switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																			case 7: outCode(2,0xDD,(5<<3)|64|(yyvsp[0].byte)); break;
																			default: outCode(2,0xDD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	    }
																	}
#line 4290 "grammar.c"
    break;

  case 247:
#line 479 "grammar.y"
                                                                                                { switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																		case 7: outCode(2,0xFD,(5<<3)|64|(yyvsp[0].byte)); break;
																		default: outCode(2,0xFD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	  }
																	}
#line 4300 "grammar.c"
    break;

  case 248:
#line 484 "grammar.y"
                                         { outCode(2,0xDD,0x60); }
#line 4306 "grammar.c"
    break;

  case 249:
#line 485 "grammar.y"
                                         { outCode(2,0xDD,0x61); }
#line 4312 "grammar.c"
    break;

  case 250:
#line 486 "grammar.y"
                                         { outCode(2,0xDD,0x62); }
#line 4318 "grammar.c"
    break;

  case 251:
#line 487 "grammar.y"
                                         { outCode(2,0xDD,0x63); }
#line 4324 "grammar.c"
    break;

  case 252:
#line 488 "grammar.y"
                                         { outCode(2,0xDD,0x64); }
#line 4330 "grammar.c"
    break;

  case 253:
#line 489 "grammar.y"
                                         { outCode(2,0xDD,0x65); }
#line 4336 "grammar.c"
    break;

  case 254:
#line 490 "grammar.y"
                                         { outCode(2,0xDD,0x67); }
#line 4342 "grammar.c"
    break;

  case 255:
#line 491 "grammar.y"
                                         { outCode(2,0xDD,0x68); }
#line 4348 "grammar.c"
    break;

  case 256:
#line 492 "grammar.y"
                                         { outCode(2,0xDD,0x69); }
#line 4354 "grammar.c"
    break;

  case 257:
#line 493 "grammar.y"
                                         { outCode(2,0xDD,0x6A); }
#line 4360 "grammar.c"
    break;

  case 258:
#line 494 "grammar.y"
                                         { outCode(2,0xDD,0x6B); }
#line 4366 "grammar.c"
    break;

  case 259:
#line 495 "grammar.y"
                                         { outCode(2,0xDD,0x6C); }
#line 4372 "grammar.c"
    break;

  case 260:
#line 496 "grammar.y"
                                         { outCode(2,0xDD,0x6D); }
#line 4378 "grammar.c"
    break;

  case 261:
#line 497 "grammar.y"
                                         { outCode(2,0xDD,0x6F); }
#line 4384 "grammar.c"
    break;

  case 262:
#line 498 "grammar.y"
                                         { outCode(2,0xFD,0x60); }
#line 4390 "grammar.c"
    break;

  case 263:
#line 499 "grammar.y"
                                         { outCode(2,0xFD,0x61); }
#line 4396 "grammar.c"
    break;

  case 264:
#line 500 "grammar.y"
                                         { outCode(2,0xFD,0x62); }
#line 4402 "grammar.c"
    break;

  case 265:
#line 501 "grammar.y"
                                         { outCode(2,0xFD,0x63); }
#line 4408 "grammar.c"
    break;

  case 266:
#line 502 "grammar.y"
                                         { outCode(2,0xFD,0x64); }
#line 4414 "grammar.c"
    break;

  case 267:
#line 503 "grammar.y"
                                         { outCode(2,0xFD,0x65); }
#line 4420 "grammar.c"
    break;

  case 268:
#line 504 "grammar.y"
                                         { outCode(2,0xFD,0x67); }
#line 4426 "grammar.c"
    break;

  case 269:
#line 505 "grammar.y"
                                         { outCode(2,0xFD,0x68); }
#line 4432 "grammar.c"
    break;

  case 270:
#line 506 "grammar.y"
                                         { outCode(2,0xFD,0x69); }
#line 4438 "grammar.c"
    break;

  case 271:
#line 507 "grammar.y"
                                         { outCode(2,0xFD,0x6A); }
#line 4444 "grammar.c"
    break;

  case 272:
#line 508 "grammar.y"
                                         { outCode(2,0xFD,0x6B); }
#line 4450 "grammar.c"
    break;

  case 273:
#line 509 "grammar.y"
                                         { outCode(2,0xFD,0x6C); }
#line 4456 "grammar.c"
    break;

  case 274:
#line 510 "grammar.y"
                                         { outCode(2,0xFD,0x6D); }
#line 4462 "grammar.c"
    break;

  case 275:
#line 511 "grammar.y"
                                         { outCode(2,0xFD,0x6F); }
#line 4468 "grammar.c"
    break;

  case 276:
#line 512 "grammar.y"
                                    { outCode(2,0xFD,0x2E,(yyvsp[0].normal)); }
#line 4474 "grammar.c"
    break;

  case 277:
#line 513 "grammar.y"
                                    { outCode(2,0xDD,0x2E,(yyvsp[0].normal)); }
#line 4480 "grammar.c"
    break;

  case 278:
#line 514 "grammar.y"
                                    { outCode(2,0xFD,0x26,(yyvsp[0].normal)); }
#line 4486 "grammar.c"
    break;

  case 279:
#line 515 "grammar.y"
                                    { outCode(2,0xDD,0x26,(yyvsp[0].normal)); }
#line 4492 "grammar.c"
    break;

  case 280:
#line 516 "grammar.y"
                                    { fatalError("Sorry, LD option into F register is not allowed in the Z80"); }
#line 4498 "grammar.c"
    break;

  case 281:
#line 517 "grammar.y"
                                    { fatalError("Sorry, LD option into AF register is not allowed in the Z80"); }
#line 4504 "grammar.c"
    break;

  case 282:
#line 520 "grammar.y"
                             { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4510 "grammar.c"
    break;

  case 283:
#line 521 "grammar.y"
                                  { int k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4516 "grammar.c"
    break;

  case 284:
#line 522 "grammar.y"
                                          { outCode(1,0xB6); }
#line 4522 "grammar.c"
    break;

  case 285:
#line 523 "grammar.y"
                                                    { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4528 "grammar.c"
    break;

  case 286:
#line 524 "grammar.y"
                                                    { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4534 "grammar.c"
    break;

  case 287:
#line 525 "grammar.y"
                                   { outCode(2,0xDD,0xB4); }
#line 4540 "grammar.c"
    break;

  case 288:
#line 526 "grammar.y"
                                   { outCode(2,0xDD,0xB5); }
#line 4546 "grammar.c"
    break;

  case 289:
#line 527 "grammar.y"
                                   { outCode(2,0xFD,0xB4); }
#line 4552 "grammar.c"
    break;

  case 290:
#line 528 "grammar.y"
                                   { outCode(2,0xFD,0xB5); }
#line 4558 "grammar.c"
    break;

  case 291:
#line 529 "grammar.y"
                                     { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4564 "grammar.c"
    break;

  case 292:
#line 530 "grammar.y"
                                          { int k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4570 "grammar.c"
    break;

  case 293:
#line 531 "grammar.y"
                                                  { outCode(1,0xB6); }
#line 4576 "grammar.c"
    break;

  case 294:
#line 532 "grammar.y"
                                                            { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4582 "grammar.c"
    break;

  case 295:
#line 533 "grammar.y"
                                                            { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4588 "grammar.c"
    break;

  case 296:
#line 534 "grammar.y"
                                           { outCode(2,0xDD,0xB4); }
#line 4594 "grammar.c"
    break;

  case 297:
#line 535 "grammar.y"
                                           { outCode(2,0xDD,0xB5); }
#line 4600 "grammar.c"
    break;

  case 298:
#line 536 "grammar.y"
                                           { outCode(2,0xFD,0xB4); }
#line 4606 "grammar.c"
    break;

  case 299:
#line 537 "grammar.y"
                                           { outCode(2,0xFD,0xB5); }
#line 4612 "grammar.c"
    break;

  case 300:
#line 540 "grammar.y"
                                                      { outCode(2,0xD3,(yyvsp[-3].normal)); }
#line 4618 "grammar.c"
    break;

  case 301:
#line 541 "grammar.y"
                                                           { outCode(2,0xED,((yyvsp[0].byte)<<3)|1|64); }
#line 4624 "grammar.c"
    break;

  case 302:
#line 543 "grammar.y"
                           { outCode(1,((yyvsp[0].byte)<<4)|1|128|64); }
#line 4630 "grammar.c"
    break;

  case 303:
#line 544 "grammar.y"
                         { outCode(2,0xDD,0xE1); }
#line 4636 "grammar.c"
    break;

  case 304:
#line 545 "grammar.y"
                         { outCode(2,0xFD,0xE1); }
#line 4642 "grammar.c"
    break;

  case 305:
#line 547 "grammar.y"
                             { outCode(1,((yyvsp[0].byte)<<4)|1|4|64|128); }
#line 4648 "grammar.c"
    break;

  case 306:
#line 548 "grammar.y"
                           { outCode(2,0xDD,0xE5); }
#line 4654 "grammar.c"
    break;

  case 307:
#line 549 "grammar.y"
                           { outCode(2,0xFD,0xE5); }
#line 4660 "grammar.c"
    break;

  case 308:
#line 552 "grammar.y"
                                   { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128); }
#line 4666 "grammar.c"
    break;

  case 309:
#line 553 "grammar.y"
                                                  { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|4|2); }
#line 4672 "grammar.c"
    break;

  case 310:
#line 554 "grammar.y"
                                                            { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4678 "grammar.c"
    break;

  case 311:
#line 555 "grammar.y"
                                                            { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4684 "grammar.c"
    break;

  case 312:
#line 558 "grammar.y"
                                                           { outCode(1,0xC9); }
#line 4690 "grammar.c"
    break;

  case 313:
#line 559 "grammar.y"
                                           { outCode(1,((yyvsp[0].byte)<<3)|128|64); }
#line 4696 "grammar.c"
    break;

  case 314:
#line 562 "grammar.y"
                                                          { outCode(2,0xCB,((yyvsp[0].byte))|16); }
#line 4702 "grammar.c"
    break;

  case 315:
#line 563 "grammar.y"
                                                      { outCode(2,0xCB,16); }
#line 4708 "grammar.c"
    break;

  case 316:
#line 564 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4714 "grammar.c"
    break;

  case 317:
#line 565 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4720 "grammar.c"
    break;

  case 318:
#line 567 "grammar.y"
                                       { outCode(2,0xCB,  (yyvsp[0].byte)); }
#line 4726 "grammar.c"
    break;

  case 319:
#line 568 "grammar.y"
                                         { outCode(2,0xCB,0x06); }
#line 4732 "grammar.c"
    break;

  case 320:
#line 569 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4738 "grammar.c"
    break;

  case 321:
#line 570 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4744 "grammar.c"
    break;

  case 322:
#line 572 "grammar.y"
                                      { outCode(2,0xCB,(yyvsp[0].byte)|8|16); }
#line 4750 "grammar.c"
    break;

  case 323:
#line 573 "grammar.y"
                                      { outCode(2,0xCB,0x1E);     }
#line 4756 "grammar.c"
    break;

  case 324:
#line 574 "grammar.y"
                                                { outCode(2,0xDD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4762 "grammar.c"
    break;

  case 325:
#line 575 "grammar.y"
                                                { outCode(2,0xFD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4768 "grammar.c"
    break;

  case 326:
#line 577 "grammar.y"
                                       { outCode(2,0xCB,(yyvsp[0].byte)|8); }
#line 4774 "grammar.c"
    break;

  case 327:
#line 578 "grammar.y"
                                       { outCode(2,0xCB,0x0E); }
#line 4780 "grammar.c"
    break;

  case 328:
#line 579 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4786 "grammar.c"
    break;

  case 329:
#line 580 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4792 "grammar.c"
    break;

  case 330:
#line 582 "grammar.y"
                        { switch ((yyvsp[0].normal)) {
                                case 0x0: case 0x8:
                                case 0x10: case 0x18:
                                case 0x20: case 0x28:
                                case 0x30: case 0x38: outCode(1,((yyvsp[0].normal)<<3)|128|64|4|2|1); break;
                                default: fatalError("Wrong vector provided for RST"); break;
                               }
                             }
#line 4805 "grammar.c"
    break;

  case 331:
#line 591 "grammar.y"
                                { outCode(1,(yyvsp[0].byte)|8|16|128); }
#line 4811 "grammar.c"
    break;

  case 332:
#line 592 "grammar.y"
                                { outCode(2,0xDE,(yyvsp[0].normal)); }
#line 4817 "grammar.c"
    break;

  case 333:
#line 593 "grammar.y"
                                               { outCode(1,0x9E); }
#line 4823 "grammar.c"
    break;

  case 334:
#line 594 "grammar.y"
                                                         { outCode(3,0xDD,0x9E,(yyvsp[-1].normal)); }
#line 4829 "grammar.c"
    break;

  case 335:
#line 595 "grammar.y"
                                                         { outCode(3,0xFD,0x9E,(yyvsp[-1].normal)); }
#line 4835 "grammar.c"
    break;

  case 336:
#line 596 "grammar.y"
                                  { outCode(2,0xED,((yyvsp[0].byte)<<4)|2|64); }
#line 4841 "grammar.c"
    break;

  case 337:
#line 597 "grammar.y"
                                       {  outCode(2,0xDD,0x9C); }
#line 4847 "grammar.c"
    break;

  case 338:
#line 598 "grammar.y"
                                           {  outCode(2,0xDD,0x9D); }
#line 4853 "grammar.c"
    break;

  case 339:
#line 599 "grammar.y"
                                           {  outCode(2,0xFD,0x9C); }
#line 4859 "grammar.c"
    break;

  case 340:
#line 600 "grammar.y"
                                           {  outCode(2,0xFD,0x9D); }
#line 4865 "grammar.c"
    break;

  case 341:
#line 602 "grammar.y"
                                   { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128|64); }
#line 4871 "grammar.c"
    break;

  case 342:
#line 603 "grammar.y"
                                                  { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|64|4|2); }
#line 4877 "grammar.c"
    break;

  case 343:
#line 604 "grammar.y"
                                                            { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4883 "grammar.c"
    break;

  case 344:
#line 605 "grammar.y"
                                                            { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4889 "grammar.c"
    break;

  case 345:
#line 608 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32); }
#line 4895 "grammar.c"
    break;

  case 346:
#line 609 "grammar.y"
                                                       { outCode(2,0xCB,26); }
#line 4901 "grammar.c"
    break;

  case 347:
#line 610 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 4907 "grammar.c"
    break;

  case 348:
#line 611 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 4913 "grammar.c"
    break;

  case 349:
#line 613 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|16); }
#line 4919 "grammar.c"
    break;

  case 350:
#line 614 "grammar.y"
                                                       { outCode(2,0xCB,36); }
#line 4925 "grammar.c"
    break;

  case 351:
#line 615 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 4931 "grammar.c"
    break;

  case 352:
#line 616 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 4937 "grammar.c"
    break;

  case 353:
#line 618 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|8); }
#line 4943 "grammar.c"
    break;

  case 354:
#line 619 "grammar.y"
                                                { outCode(2,0xCB,0x2E); }
#line 4949 "grammar.c"
    break;

  case 355:
#line 620 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 4955 "grammar.c"
    break;

  case 356:
#line 621 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 4961 "grammar.c"
    break;

  case 357:
#line 623 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|16|8); }
#line 4967 "grammar.c"
    break;

  case 358:
#line 624 "grammar.y"
                                                       { outCode(2,0xCB,0x3E); }
#line 4973 "grammar.c"
    break;

  case 359:
#line 625 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 4979 "grammar.c"
    break;

  case 360:
#line 626 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 4985 "grammar.c"
    break;

  case 361:
#line 628 "grammar.y"
                                       { outCode(1,(yyvsp[0].byte)|16|128); }
#line 4991 "grammar.c"
    break;

  case 362:
#line 629 "grammar.y"
                                  { outCode(2,0xD6,(yyvsp[0].normal)); }
#line 4997 "grammar.c"
    break;

  case 363:
#line 630 "grammar.y"
                                       { outCode(1,0x96); }
#line 5003 "grammar.c"
    break;

  case 364:
#line 631 "grammar.y"
                                                 { outCode(3,0xDD,0x96,(yyvsp[-1].normal)); }
#line 5009 "grammar.c"
    break;

  case 365:
#line 632 "grammar.y"
                                                 { outCode(3,0xFD,0x96,(yyvsp[-1].normal)); }
#line 5015 "grammar.c"
    break;

  case 366:
#line 633 "grammar.y"
                               {  outCode(2,0xDD,0x94); }
#line 5021 "grammar.c"
    break;

  case 367:
#line 634 "grammar.y"
                                   {  outCode(2,0xDD,0x95); }
#line 5027 "grammar.c"
    break;

  case 368:
#line 635 "grammar.y"
                                   {  outCode(2,0xFD,0x94); }
#line 5033 "grammar.c"
    break;

  case 369:
#line 636 "grammar.y"
                                   {  outCode(2,0xFD,0x95); }
#line 5039 "grammar.c"
    break;

  case 370:
#line 639 "grammar.y"
                                                { int k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5045 "grammar.c"
    break;

  case 371:
#line 640 "grammar.y"
                               { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5051 "grammar.c"
    break;

  case 372:
#line 641 "grammar.y"
                                           { outCode(1,0xAE); }
#line 5057 "grammar.c"
    break;

  case 373:
#line 642 "grammar.y"
                                                     { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5063 "grammar.c"
    break;

  case 374:
#line 643 "grammar.y"
                                                     { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5069 "grammar.c"
    break;

  case 375:
#line 644 "grammar.y"
                                    { outCode(2,0xDD,0xAC); }
#line 5075 "grammar.c"
    break;

  case 376:
#line 645 "grammar.y"
                                    { outCode(2,0xDD,0xAD); }
#line 5081 "grammar.c"
    break;

  case 377:
#line 646 "grammar.y"
                                    { outCode(2,0xFD,0xAC); }
#line 5087 "grammar.c"
    break;

  case 378:
#line 647 "grammar.y"
                                    { outCode(2,0xFD,0xAD); }
#line 5093 "grammar.c"
    break;

  case 379:
#line 648 "grammar.y"
                                                        { int k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5099 "grammar.c"
    break;

  case 380:
#line 649 "grammar.y"
                                       { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5105 "grammar.c"
    break;

  case 381:
#line 650 "grammar.y"
                                                   { outCode(1,0xAE); }
#line 5111 "grammar.c"
    break;

  case 382:
#line 651 "grammar.y"
                                                             { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5117 "grammar.c"
    break;

  case 383:
#line 652 "grammar.y"
                                                             { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5123 "grammar.c"
    break;

  case 384:
#line 653 "grammar.y"
                                            { outCode(2,0xDD,0xAC); }
#line 5129 "grammar.c"
    break;

  case 385:
#line 654 "grammar.y"
                                            { outCode(2,0xDD,0xAD); }
#line 5135 "grammar.c"
    break;

  case 386:
#line 655 "grammar.y"
                                            { outCode(2,0xFD,0xAC); }
#line 5141 "grammar.c"
    break;

  case 387:
#line 656 "grammar.y"
                                            { outCode(2,0xFD,0xAD); }
#line 5147 "grammar.c"
    break;

  case 388:
#line 659 "grammar.y"
                                         { p = (uint8_t *)malloc(3*sizeof(uint8_t)); p[0] = 2; p[1] = (yyvsp[0].normal)&0x00FF; p[2] = (yyvsp[0].normal)>>8; (yyval.listexpr) = p;  }
#line 5153 "grammar.c"
    break;

  case 389:
#line 660 "grammar.y"
                                         { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[p[0]+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; }
#line 5159 "grammar.c"
    break;

  case 390:
#line 661 "grammar.y"
                                              { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(int a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5165 "grammar.c"
    break;

  case 391:
#line 662 "grammar.y"
                                               {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5174 "grammar.c"
    break;

  case 392:
#line 669 "grammar.y"
                                              { p = (uint8_t *)malloc(5*sizeof(uint8_t)); p[0] = 4; p[1] = (yyvsp[0].normal)&0x000000FF; p[2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[3] = ((yyvsp[0].normal)&0x00FF0000)>>16; p[4] = ((yyvsp[0].normal)&0xFF000000)>>24; (yyval.listexpr) = p;  }
#line 5180 "grammar.c"
    break;

  case 393:
#line 670 "grammar.y"
                                         { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+4)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&&0x000000FF; p[p[0]+2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[p[0]+4] = ((yyvsp[0].normal)&0x00FF0000)>>18; p[p[0]+4] = ((yyvsp[0].normal)&0xFF000000)>>24; p[0] = p[0] + 4; (yyval.listexpr) = p; }
#line 5186 "grammar.c"
    break;

  case 394:
#line 671 "grammar.y"
                                              { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(int a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5192 "grammar.c"
    break;

  case 395:
#line 672 "grammar.y"
                                               {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5201 "grammar.c"
    break;

  case 396:
#line 679 "grammar.y"
                                             { p = (uint8_t *)malloc(2); p[0] = 1; p[1] = (yyvsp[0].normal); (yyval.listexpr) = p; }
#line 5207 "grammar.c"
    break;

  case 397:
#line 680 "grammar.y"
                                             { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(int a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5213 "grammar.c"
    break;

  case 398:
#line 681 "grammar.y"
                                        { 
	                                       if (((uint16_t)(yyvsp[0].normal)) > 255) {
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[(*p)+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; 
	                                       }
	                                       else { 
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+1)); p[p[0]+1] = (yyvsp[0].normal); p[0] = p[0] + 1; (yyval.listexpr) = p; 
	                                       }   
	                                     }
#line 5226 "grammar.c"
    break;

  case 399:
#line 689 "grammar.y"
                                              {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5235 "grammar.c"
    break;

  case 400:
#line 694 "grammar.y"
                                                 { (yyval.normal) = (yyvsp[0].normal);  }
#line 5241 "grammar.c"
    break;

  case 401:
#line 695 "grammar.y"
                                                 { (yyval.normal)=((yyvsp[0].normal)==0)?1:0; }
#line 5247 "grammar.c"
    break;

  case 402:
#line 696 "grammar.y"
                                                { (yyval.normal) = (yyvsp[-1].normal);  }
#line 5253 "grammar.c"
    break;

  case 403:
#line 697 "grammar.y"
                                                { (yyval.normal)=-(yyvsp[0].normal); }
#line 5259 "grammar.c"
    break;

  case 404:
#line 698 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) + (yyvsp[0].normal); }
#line 5265 "grammar.c"
    break;

  case 405:
#line 699 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) - (yyvsp[0].normal); }
#line 5271 "grammar.c"
    break;

  case 406:
#line 700 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) * (yyvsp[0].normal); }
#line 5277 "grammar.c"
    break;

  case 407:
#line 701 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) / (yyvsp[0].normal); }
#line 5283 "grammar.c"
    break;

  case 408:
#line 702 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) & (yyvsp[0].normal); }
#line 5289 "grammar.c"
    break;

  case 409:
#line 703 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) | (yyvsp[0].normal); }
#line 5295 "grammar.c"
    break;

  case 410:
#line 704 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) << (yyvsp[0].normal); }
#line 5301 "grammar.c"
    break;

  case 411:
#line 705 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) >> (yyvsp[0].normal); }
#line 5307 "grammar.c"
    break;

  case 412:
#line 706 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 0; } else { (yyval.normal) = 1;  } }
#line 5313 "grammar.c"
    break;

  case 413:
#line 707 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5319 "grammar.c"
    break;

  case 414:
#line 708 "grammar.y"
                                                { if ( (yyvsp[-2].normal) >= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5325 "grammar.c"
    break;

  case 415:
#line 709 "grammar.y"
                                                { if ( (yyvsp[-2].normal) > (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5331 "grammar.c"
    break;

  case 416:
#line 710 "grammar.y"
                                                { if ( (yyvsp[-2].normal) <= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5337 "grammar.c"
    break;

  case 417:
#line 711 "grammar.y"
                                                { if ( (yyvsp[-2].normal) < (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5343 "grammar.c"
    break;

  case 418:
#line 712 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) && (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5349 "grammar.c"
    break;

  case 419:
#line 713 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) || (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5355 "grammar.c"
    break;

  case 420:
#line 715 "grammar.y"
                                        { int k; 
	                                 if (getLabelValue((yyvsp[0].literal),&k) < 0)   { labelUndefinedError((yyvsp[0].literal)); (yyval.normal)=0; }                                  
	                                 else { (yyval.normal)=k; }
	                                }
#line 5364 "grammar.c"
    break;

  case 421:
#line 719 "grammar.y"
                                    { (yyval.normal) = (yyvsp[0].normal); }
#line 5370 "grammar.c"
    break;

  case 422:
#line 720 "grammar.y"
                                    { (yyval.normal) = (yyvsp[0].byte); }
#line 5376 "grammar.c"
    break;

  case 423:
#line 721 "grammar.y"
                                    { (yyval.normal) = prepc; }
#line 5382 "grammar.c"
    break;

  case 424:
#line 722 "grammar.y"
                                    { (yyval.normal) = (LookupTableLabels((yyvsp[0].literal))<0)?0:1; }
#line 5388 "grammar.c"
    break;

  case 425:
#line 726 "grammar.y"
                        { (yyval.byte) = 7; }
#line 5394 "grammar.c"
    break;

  case 426:
#line 727 "grammar.y"
                    { (yyval.byte) = 0; }
#line 5400 "grammar.c"
    break;

  case 427:
#line 728 "grammar.y"
                    { (yyval.byte) = 1; }
#line 5406 "grammar.c"
    break;

  case 428:
#line 729 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5412 "grammar.c"
    break;

  case 429:
#line 730 "grammar.y"
                    { (yyval.byte) = 3; }
#line 5418 "grammar.c"
    break;

  case 430:
#line 731 "grammar.y"
                    { (yyval.byte) = 4; }
#line 5424 "grammar.c"
    break;

  case 431:
#line 732 "grammar.y"
                    { (yyval.byte) = 5; }
#line 5430 "grammar.c"
    break;

  case 432:
#line 734 "grammar.y"
                    { (yyval.normal) = 0xDD; }
#line 5436 "grammar.c"
    break;

  case 433:
#line 735 "grammar.y"
                    { (yyval.normal) = 0xFD; }
#line 5442 "grammar.c"
    break;

  case 434:
#line 737 "grammar.y"
                        { (yyval.byte) = 0; }
#line 5448 "grammar.c"
    break;

  case 435:
#line 738 "grammar.y"
                     { (yyval.byte) = 1; }
#line 5454 "grammar.c"
    break;

  case 436:
#line 739 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5460 "grammar.c"
    break;

  case 437:
#line 740 "grammar.y"
                     { (yyval.byte) = 3; }
#line 5466 "grammar.c"
    break;

  case 438:
#line 742 "grammar.y"
                        { (yyval.byte) = 0; }
#line 5472 "grammar.c"
    break;

  case 439:
#line 743 "grammar.y"
                     { (yyval.byte) = 1; }
#line 5478 "grammar.c"
    break;

  case 440:
#line 744 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5484 "grammar.c"
    break;

  case 441:
#line 745 "grammar.y"
                     { (yyval.byte) = 3; }
#line 5490 "grammar.c"
    break;

  case 442:
#line 748 "grammar.y"
                       { (yyval.byte) = 4; }
#line 5496 "grammar.c"
    break;

  case 443:
#line 749 "grammar.y"
                     { (yyval.byte) = 5; }
#line 5502 "grammar.c"
    break;

  case 444:
#line 751 "grammar.y"
                       { (yyval.byte) = 4; }
#line 5508 "grammar.c"
    break;

  case 445:
#line 752 "grammar.y"
                     { (yyval.byte) = 5; }
#line 5514 "grammar.c"
    break;

  case 446:
#line 754 "grammar.y"
                  { (yyval.byte) = 0; }
#line 5520 "grammar.c"
    break;

  case 447:
#line 755 "grammar.y"
                 { (yyval.byte) = 1; }
#line 5526 "grammar.c"
    break;

  case 448:
#line 756 "grammar.y"
                  { (yyval.byte) = 2; }
#line 5532 "grammar.c"
    break;

  case 449:
#line 757 "grammar.y"
                 { (yyval.byte) = 3; }
#line 5538 "grammar.c"
    break;

  case 450:
#line 758 "grammar.y"
                  { (yyval.byte) = 4; }
#line 5544 "grammar.c"
    break;

  case 451:
#line 759 "grammar.y"
                   { (yyval.byte) = 5; }
#line 5550 "grammar.c"
    break;

  case 452:
#line 760 "grammar.y"
                  { (yyval.byte) = 6; }
#line 5556 "grammar.c"
    break;

  case 453:
#line 761 "grammar.y"
                 { (yyval.byte) = 7; }
#line 5562 "grammar.c"
    break;

  case 454:
#line 763 "grammar.y"
                         { (yyval.byte) = 0; }
#line 5568 "grammar.c"
    break;

  case 455:
#line 764 "grammar.y"
                 { (yyval.byte) = 1; }
#line 5574 "grammar.c"
    break;

  case 456:
#line 765 "grammar.y"
                  { (yyval.byte) = 2; }
#line 5580 "grammar.c"
    break;

  case 457:
#line 766 "grammar.y"
                 { (yyval.byte) = 3; }
#line 5586 "grammar.c"
    break;


#line 5590 "grammar.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
