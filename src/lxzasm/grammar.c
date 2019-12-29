/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "defs.h"
 
int yyparse();
int yylex();

void includebin(const char * includefile);

extern int setLabelAddress(const char * label, const int pc);
extern int setLabelValue(const char * label, const int val);
extern int LookupTableLabels(const char * label);
extern void labelUndefinedError(const char * label);
extern void warningError(const char *str);
extern void fatalError(const char *str);
extern int getLabelValue(const char * label, uint * k);
extern int outCode( int num, ... );
extern void outDirective();
extern void setLimit(uint16_t limit);
extern void includebinTooBigError(const char * includefile);
void directiveError(const char * msg);
extern void setStart(uint16_t org);

extern void yyerror(const char *str);
extern int yylineno;
extern int pc;
extern int previouspc;
extern int pass;
extern int condStatus;


char msg[200];
uint k;
uint a;
uint8_t * p;

int yywrap()
{
        return 1;
} 
  
  
void includebin(const char * includefile) {
 FILE * fi;
 uint8_t buffer[MAX_SIZE_CODE_LINE];
 uint16_t nbread;
 int a;
        
     if ( !condStatus ) { return; }
     
        fi = fopen(includefile, "r");
		if (fi == NULL) { perror("ERROR INCLUDE:"); exit(1); }
        nbread = fread(buffer, sizeof(char), MAX_SIZE_CODE_LINE, fi);
        if ( nbread == MAX_SIZE_CODE_LINE ) { includebinTooBigError(includefile); }
        for(a=0;a<nbread;a++) { outCode(1,buffer[a]); }       
        fclose(fi);
        
}



#line 132 "grammar.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    TITLE = 284,
    FNAME = 285,
    INCLUDE = 286,
    INCLUDEBIN = 287,
    DEFINED = 288,
    NEWLINE = 289,
    ERROR = 290,
    LIMIT = 291,
    DOLAR = 292,
    ALIGN = 293,
    COMMA = 294,
    ASEG = 295,
    CHAR = 296,
    LDDR = 297,
    CALL = 298,
    RRCA = 299,
    OTDR = 300,
    OTIR = 301,
    OUTI = 302,
    OUTD = 303,
    RETI = 304,
    RETN = 305,
    PUSH = 306,
    ORG = 307,
    END = 308,
    EQU = 309,
    DEC = 310,
    AND = 311,
    SBC = 312,
    OUT = 313,
    ADC = 314,
    LDD = 315,
    LDI = 316,
    ADD = 317,
    RRA = 318,
    RRC = 319,
    SRA = 320,
    SRL = 321,
    SLL = 322,
    RRD = 323,
    POP = 324,
    CCF = 325,
    RET = 326,
    XOR = 327,
    BIT = 328,
    SCF = 329,
    NOP = 330,
    SET = 331,
    JP = 332,
    DJNZ = 333,
    HALT = 334,
    INDR = 335,
    INIR = 336,
    IND = 337,
    LDIR = 338,
    SLA = 339,
    NEG = 340,
    LD = 341,
    AF = 342,
    HL = 343,
    SP = 344,
    BC = 345,
    DE = 346,
    IX = 347,
    IY = 348,
    IXH = 349,
    IXL = 350,
    IYH = 351,
    IYL = 352,
    OR = 353,
    AFPLUS = 354,
    SUB = 355,
    CP = 356,
    RES = 357,
    CPD = 358,
    CPDR = 359,
    CPI = 360,
    CPIR = 361,
    CPL = 362,
    RLA = 363,
    RLC = 364,
    RLCA = 365,
    DAA = 366,
    RL = 367,
    RLD = 368,
    DI = 369,
    EI = 370,
    EX = 371,
    JR = 372,
    RR = 373,
    EXX = 374,
    RST = 375,
    IM = 376,
    IN = 377,
    INI = 378,
    INC = 379,
    NC = 380,
    NZ = 381,
    PO = 382,
    PE = 383,
    Z = 384,
    P = 385,
    M = 386,
    A = 387,
    B = 388,
    C = 389,
    D = 390,
    E = 391,
    H = 392,
    L = 393,
    R = 394,
    I = 395,
    F = 396,
    NOLIST = 397,
    STRING = 398,
    LITERAL = 399,
    LABEL = 400,
    INTEGER = 401,
    UMINUS = 402
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
#define TITLE 284
#define FNAME 285
#define INCLUDE 286
#define INCLUDEBIN 287
#define DEFINED 288
#define NEWLINE 289
#define ERROR 290
#define LIMIT 291
#define DOLAR 292
#define ALIGN 293
#define COMMA 294
#define ASEG 295
#define CHAR 296
#define LDDR 297
#define CALL 298
#define RRCA 299
#define OTDR 300
#define OTIR 301
#define OUTI 302
#define OUTD 303
#define RETI 304
#define RETN 305
#define PUSH 306
#define ORG 307
#define END 308
#define EQU 309
#define DEC 310
#define AND 311
#define SBC 312
#define OUT 313
#define ADC 314
#define LDD 315
#define LDI 316
#define ADD 317
#define RRA 318
#define RRC 319
#define SRA 320
#define SRL 321
#define SLL 322
#define RRD 323
#define POP 324
#define CCF 325
#define RET 326
#define XOR 327
#define BIT 328
#define SCF 329
#define NOP 330
#define SET 331
#define JP 332
#define DJNZ 333
#define HALT 334
#define INDR 335
#define INIR 336
#define IND 337
#define LDIR 338
#define SLA 339
#define NEG 340
#define LD 341
#define AF 342
#define HL 343
#define SP 344
#define BC 345
#define DE 346
#define IX 347
#define IY 348
#define IXH 349
#define IXL 350
#define IYH 351
#define IYL 352
#define OR 353
#define AFPLUS 354
#define SUB 355
#define CP 356
#define RES 357
#define CPD 358
#define CPDR 359
#define CPI 360
#define CPIR 361
#define CPL 362
#define RLA 363
#define RLC 364
#define RLCA 365
#define DAA 366
#define RL 367
#define RLD 368
#define DI 369
#define EI 370
#define EX 371
#define JR 372
#define RR 373
#define EXX 374
#define RST 375
#define IM 376
#define IN 377
#define INI 378
#define INC 379
#define NC 380
#define NZ 381
#define PO 382
#define PE 383
#define Z 384
#define P 385
#define M 386
#define A 387
#define B 388
#define C 389
#define D 390
#define E 391
#define H 392
#define L 393
#define R 394
#define I 395
#define F 396
#define NOLIST 397
#define STRING 398
#define LITERAL 399
#define LABEL 400
#define INTEGER 401
#define UMINUS 402

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "grammar.y" /* yacc.c:355  */

  uint32_t normal;
  uint8_t byte;
  uint16_t word;
  uint16_t address;
  uint8_t * listexpr;
  char literal[64];
  

#line 476 "grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 493 "grammar.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  336
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3761

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  474
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  889

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   404

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   212,   213,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     327,   329,   330,   332,   334,   336,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   372,   373,
     374,   375,   376,   377,   378,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   394,   395,
     396,   397,   402,   403,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   432,   435,
     436,   437,   438,   439,   441,   449,   450,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     466,   467,   468,   469,   470,   472,   473,   474,   475,   476,
     477,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     512,   514,   518,   522,   528,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   589,   590,   592,
     593,   594,   596,   597,   598,   601,   602,   603,   604,   607,
     608,   611,   612,   613,   614,   616,   617,   618,   619,   621,
     622,   623,   624,   626,   627,   628,   629,   631,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   651,   652,
     653,   654,   657,   658,   659,   660,   662,   663,   664,   665,
     667,   668,   669,   670,   672,   673,   674,   675,   677,   678,
     679,   680,   681,   682,   683,   684,   685,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   708,   709,   710,   711,   718,
     719,   720,   721,   728,   729,   730,   738,   743,   744,   745,
     746,   747,   748,   749,   750,   751,   752,   753,   754,   755,
     756,   757,   758,   759,   760,   761,   762,   764,   768,   769,
     770,   771,   775,   776,   777,   778,   779,   780,   781,   783,
     784,   786,   787,   788,   789,   791,   792,   793,   794,   797,
     798,   800,   801,   803,   804,   805,   806,   807,   808,   809,
     810,   812,   813,   814,   815
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
  "ENDIF", "TITLE", "FNAME", "INCLUDE", "INCLUDEBIN", "DEFINED", "NEWLINE",
  "ERROR", "LIMIT", "DOLAR", "ALIGN", "COMMA", "ASEG", "CHAR", "LDDR",
  "CALL", "RRCA", "OTDR", "OTIR", "OUTI", "OUTD", "RETI", "RETN", "PUSH",
  "ORG", "END", "EQU", "DEC", "AND", "SBC", "OUT", "ADC", "LDD", "LDI",
  "ADD", "RRA", "RRC", "SRA", "SRL", "SLL", "RRD", "POP", "CCF", "RET",
  "XOR", "BIT", "SCF", "NOP", "SET", "JP", "DJNZ", "HALT", "INDR", "INIR",
  "IND", "LDIR", "SLA", "NEG", "LD", "AF", "HL", "SP", "BC", "DE", "IX",
  "IY", "IXH", "IXL", "IYH", "IYL", "OR", "AFPLUS", "SUB", "CP", "RES",
  "CPD", "CPDR", "CPI", "CPIR", "CPL", "RLA", "RLC", "RLCA", "DAA", "RL",
  "RLD", "DI", "EI", "EX", "JR", "RR", "EXX", "RST", "IM", "IN", "INI",
  "INC", "NC", "NZ", "PO", "PE", "Z", "P", "M", "A", "B", "C", "D", "E",
  "H", "L", "R", "I", "F", "NOLIST", "STRING", "LITERAL", "LABEL",
  "INTEGER", "UMINUS", "\"word\"", "\"sequence\"", "$accept", "program",
  "lines", "line", "directive", "instruction", "directivedefc",
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
static const yytype_uint16 yytoknum[] =
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
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404
};
# endif

#define YYPACT_NINF -252

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-252)))

#define YYTABLE_NINF -260

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     164,    34,   295,   702,  -134,   711,   295,  -130,  -119,    -7,
    -107,  -103,   -84,   -65,  -252,   -98,   295,   295,    43,  -252,
    1302,  -252,  -252,  -252,  -252,  -252,  -252,  -252,   247,   295,
     295,  1934,   374,   -66,    64,   -64,  -252,  -252,   -75,  -252,
      -9,   123,   158,   165,  -252,   301,  -252,   351,   492,   295,
    -252,  -252,   295,  1402,   295,  -252,  -252,  -252,  -252,  -252,
     233,  -252,  1924,   571,   705,  1067,   295,  -252,  -252,  -252,
    -252,  -252,  -252,   430,  -252,  -252,   437,  -252,  -252,  -252,
     -15,  1438,   482,  -252,   295,   295,   402,  -252,  1988,    97,
     829,   951,   118,   164,  -252,    98,   104,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,   295,   295,   295,     4,
    -252,  -252,  -252,  -252,  -252,   119,  3663,  -252,  2078,  -252,
     120,  3663,   138,  -252,   127,  3663,  2095,   142,   148,  -252,
     150,   151,   163,   167,   169,   171,  -252,  3663,  3663,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  3663,   212,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  3663,  3663,    48,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,   661,
    -252,  -252,  -252,  -252,   213,  3663,  -252,   224,   250,  1106,
     266,   268,   271,   272,   279,   282,    54,  -252,    72,  -252,
      95,  -252,   286,  -252,  -252,  -252,  -252,  -252,  1650,  -252,
    -252,  -252,  -252,   283,  3663,  -252,  2129,  2147,  1672,  3663,
     285,  3663,   325,  -252,   453,   287,  -252,  -252,   290,   302,
     303,   336,   337,   338,   342,   345,   346,   348,  1689,  -252,
    -252,  -252,  -252,   366,  3663,  -252,  1750,  -252,  -252,  -252,
    -252,  3663,  -252,  1764,  -252,  -252,  -252,  -252,  3663,  -252,
    2196,   344,  -252,   354,  -252,   236,   371,   375,  -252,  -252,
     377,   380,  -252,   381,   387,  -252,  3663,   388,   357,  -252,
    3663,  3663,   394,   396,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,   295,  -252,   310,   389,   400,   423,
    -252,   295,  -252,   310,   425,   427,  -252,  -252,  -252,  -252,
    -252,  2245,  -252,  -252,  1136,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,  1150,   295,  1416,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,   295,   443,     0,     1,   447,     3,
      22,  1084,    84,  1101,   452,  2262,    84,  1220,    84,   511,
     505,  1237,   463,   465,   484,   478,   497,   507,   496,   518,
     519,   508,   522,   524,   527,   534,   542,  1254,   510,   555,
     533,   536,   539,   295,   563,   582,   583,   585,   586,   587,
    2296,    79,   295,  1443,  1479,  1583,  1600,   477,   479,   295,
      17,  1825,  1767,   590,   605,   613,  1373,   603,   623,   624,
     614,    24,    26,   650,   617,   631,   641,   632,   646,   648,
     637,   559,   574,   295,   295,   295,   295,   295,   639,   664,
     665,  1929,   649,    29,    53,  3663,  -252,  -252,  3663,  -252,
    -252,  -252,  -252,  3663,  1068,  1068,   385,   385,   296,   296,
     296,   296,    83,    83,    80,    80,  -252,  -252,   952,   952,
    3663,  -252,  3663,  3663,  -252,  3663,  3663,  -252,   295,  -252,
     295,  -252,  -252,   295,  -252,   295,  -252,  1789,  -252,  -252,
    -252,  -252,  3663,  -252,  -252,  1828,  -252,  -252,  -252,  -252,
    3663,  -252,   638,   645,  -252,  1854,  -252,  -252,  -252,  -252,
    3663,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  1864,  -252,  -252,  -252,  -252,  3663,  -252,  -252,   295,
     295,  -252,   295,   295,  -252,   295,   295,  -252,   295,   295,
    -252,   295,   295,  1893,  -252,  -252,  -252,  -252,  3663,  -252,
     403,  -252,   429,  -252,  -252,  -252,  -252,  3663,  -252,   295,
     295,   647,   656,   657,   658,   295,   295,  3663,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  3663,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  3663,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  3663,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  3663,
    -252,  -252,  3663,  1452,  -252,  -252,  -252,  -252,  -252,  -252,
    3663,  -252,  -252,  -252,   295,  3663,   295,  -252,  3663,  -252,
    -252,   295,   295,  1903,  -252,  -252,  -252,  -252,  3663,  -252,
    -252,   295,   295,  -252,   295,  -252,   295,  -252,   431,  -252,
    -252,   295,   295,  -252,   295,   295,   660,  -252,  -252,  3663,
    3663,  3663,  3663,  3663,  -252,   295,   295,  1623,  3663,  -252,
     295,  -252,   295,  -252,  2313,  2362,  2389,  2411,   680,   668,
     670,   681,   672,   677,   402,   578,   692,    61,    62,   693,
      66,    88,  2438,  2460,  2487,  2509,  2536,  2558,  2585,  2607,
    2634,  2656,   696,   710,   713,   699,   717,   720,   709,   722,
     723,  2683,  2705,  1617,   602,   604,     2,  2732,  2754,   721,
     725,   727,  2781,   729,  2803,  2830,  2852,  2879,   730,   732,
     747,  2901,  2928,  2950,  2977,   736,   749,   750,  2999,  3026,
    3048,  3075,   489,  3097,  3124,   739,  3146,  3173,  -252,  -252,
    -252,  -252,  -252,   295,   295,  -252,   295,   295,  -252,  -252,
    -252,   295,  -252,   295,  -252,  -252,   295,  -252,   295,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,   295,   295,  -252,   295,   295,  -252,   295,   295,  -252,
    -252,  3663,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,   728,   734,  -252,  -252,  -252,   726,   295,   735,
     737,  -252,  -252,  -252,   295,   295,  -252,  -252,  -252,  -252,
    -252,   295,   295,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  3195,  3222,  3244,  3271,  3293,
    3320,  3342,  3369,  3391,  3418,  3440,  3467,  3489,  3516,  1617,
    1617,  3538,  3565,  3587,  3614,  3636,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    3663,  -252,  3663,  -252,  -252,  -252,  -252,  -252,  -252
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,    92,
       0,   107,    97,    98,   100,    99,   101,   102,     0,     0,
      31,     0,     0,     0,     0,     0,    91,    93,     0,   106,
       0,     0,     0,     0,   108,     0,    76,   329,     0,     0,
     109,    96,     0,     0,     0,    86,    88,    90,    87,    94,
       0,    95,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,   103,     0,   104,    82,     0,   105,    83,    84,
       0,     0,     0,    85,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     2,     3,     0,     0,    36,    34,    33,
      35,    37,    44,    45,    43,    54,    49,    55,    52,    47,
      56,    57,    58,    59,    50,    51,    42,    60,    48,    61,
      62,    63,    46,    64,    65,    66,    67,    68,    69,    70,
      71,    74,    72,    73,    75,    53,     0,     0,     0,     0,
     440,   439,   414,   437,   438,   113,   413,   417,   111,   407,
     114,   405,     0,   411,   115,   409,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,    30,    41,    40,    19,
     465,   463,   467,   468,   464,   469,   470,   466,   172,     0,
     458,   457,   455,   456,   323,   324,   322,    29,    32,     0,
     453,   454,   451,   452,   192,   193,   194,   195,   196,   197,
     442,   443,   444,   445,   446,   447,   448,   185,   191,     0,
     155,   156,   157,   158,   442,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   343,     0,   370,
       0,   374,     0,   366,   320,   321,   319,   330,     0,   392,
     393,   394,   395,   442,   388,   387,     0,     0,     0,   220,
       0,   198,     0,   362,     0,     0,   449,   450,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
     305,   306,   307,   442,   299,   300,     0,   383,   384,   385,
     386,   379,   378,     0,   181,   182,   183,   184,   174,   175,
       0,     0,   335,     0,   331,     0,     0,     0,   473,   471,
       0,     0,   472,     0,     0,   474,   226,     0,     0,   339,
     347,   204,     0,     0,   214,   215,   216,   217,   218,   219,
     207,   208,    18,    10,     0,    27,     0,     0,     0,     0,
       9,     0,    26,    28,     0,     0,     1,     4,    15,     5,
     420,     0,   418,   441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    20,    21,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    16,     7,    39,    17,
       6,   419,   416,   415,   421,   422,   423,   424,   432,   431,
     434,   433,   426,   425,   427,   428,   429,   430,   435,   436,
     112,   408,   406,   110,   412,   410,   173,   186,     0,   189,
       0,   190,   150,     0,   153,     0,   154,     0,   164,   165,
     166,   167,   159,   160,   353,     0,   354,   355,   356,   357,
     349,   348,     0,     0,   123,     0,   124,   125,   126,   127,
     116,   117,   135,   139,   136,   137,   138,   143,   140,   141,
     142,     0,   144,   145,   146,   147,   128,   129,   344,     0,
       0,   371,     0,     0,   375,     0,     0,   367,     0,     0,
     389,     0,     0,     0,   401,   402,   403,   404,   397,   396,
       0,   171,     0,   358,   222,   223,   224,   221,   363,     0,
       0,     0,     0,     0,     0,     0,     0,   298,   269,   270,
     271,   265,   266,   267,   268,   296,   276,   277,   278,   272,
     273,   274,   275,   294,   283,   284,   285,   279,   280,   281,
     282,   295,   290,   291,   292,   286,   287,   288,   289,   293,
     256,   254,   297,     0,   459,   460,   461,   462,   255,   253,
     233,   231,   263,   264,     0,   258,     0,   261,   260,   262,
     301,     0,     0,     0,   313,   314,   315,   316,   308,   309,
     380,     0,     0,   176,     0,   179,     0,   180,     0,   325,
     336,     0,     0,   332,     0,     0,     0,   199,   200,   230,
     229,   228,   227,   225,   340,     0,     0,     0,   206,   209,
       0,   212,     0,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   188,
     151,   152,   161,     0,     0,   350,     0,     0,   318,   317,
     118,     0,   121,     0,   122,   130,     0,   133,     0,   134,
     345,   346,   372,   373,   376,   377,   368,   369,   390,   391,
     398,     0,     0,   168,     0,     0,   359,     0,     0,   364,
     365,   238,   239,   236,   237,   248,   247,   245,   246,   249,
     250,   244,     0,     0,   235,   251,   252,   419,     0,   419,
     419,   302,   303,   310,     0,     0,   381,   382,   177,   178,
     326,     0,     0,   337,   338,   333,   334,   201,   202,   203,
     341,   342,   205,   210,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   163,   351,   352,
     119,   120,   131,   132,   399,   400,   169,   170,   360,   361,
     240,   241,   242,   243,   234,   311,   312,   327,   328
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -252,  -252,  -252,   671,    19,    25,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,    -1,  -252,
      57,  -251,   -55,   716,  -252,  -252,   -12,  -252
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   150,   154,   145,   341,   147,
     207,   266,   208,   186,   632,   633,   179,   307
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     146,   148,   151,   421,   155,   156,   295,   267,   498,   500,
     152,   503,   226,   222,   157,   167,   168,   223,   224,   178,
     499,   501,   217,   504,   220,   158,   136,   159,   187,   188,
     505,   215,   654,   321,   656,   237,   160,   680,   623,   138,
     161,   250,   506,   136,   655,   166,   657,   244,   246,   681,
     139,   247,   249,   251,   140,   137,   138,   225,   141,   162,
     163,   682,   274,   281,   288,   290,   218,   139,   221,   771,
     773,   140,   296,   683,   776,   141,   297,   169,   164,   165,
     306,   772,   774,   310,   311,   219,   777,   585,   586,   216,
     805,   806,   807,   808,   809,   810,   778,   227,   229,   231,
     233,   355,   356,   357,   358,   245,   357,   358,   779,   328,
     334,   624,   625,   626,   627,   329,   335,   253,   336,   265,
     275,   282,   289,   200,   201,   202,   203,   204,   205,   206,
     292,   322,   338,   294,   811,   340,   375,   342,   339,   309,
     376,   377,   392,   312,   228,   320,   393,   394,   343,   200,
     201,   202,   203,   204,   205,   206,   628,   629,   344,   362,
     395,   143,   363,   144,   396,   397,   364,     1,     2,     3,
       4,     5,   190,   191,   192,   193,   366,   142,   143,   230,
     144,   639,   367,   398,   368,   369,   232,   399,   400,     6,
       7,     8,     9,    10,    11,    12,    13,   370,    14,    15,
      16,   371,    17,   372,    18,   373,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   385,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   374,   381,   420,   252,   200,   201,   202,   203,   204,
     205,   206,    63,   382,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   383,
     200,   201,   202,   203,   204,   205,   206,   200,   201,   202,
     203,   204,   205,   206,   136,   386,    89,   387,    90,    91,
     388,   389,   353,   354,   355,   356,   137,   138,   390,   357,
     358,   391,   407,   465,   413,   450,   422,   514,   139,   423,
     468,   524,   140,   532,   180,   181,   141,   182,   183,   184,
     185,   424,   425,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   492,   493,   495,   324,   200,   201,   202,   203,   204,
     205,   206,   733,   496,   401,   426,   427,   428,   402,   403,
     512,   429,   520,   136,   430,   431,   530,   432,   180,   181,
     546,   182,   183,   234,   235,   209,   138,   349,   350,   351,
     352,   353,   354,   355,   356,   436,   568,   139,   357,   358,
     451,   140,   577,   414,   452,   141,   453,   415,   416,   454,
     455,   587,   595,   603,   611,   619,   456,   457,   622,   630,
     635,   638,   444,   461,   466,   648,   445,   446,   513,   143,
     521,   144,   447,   331,   531,   458,   448,   449,   547,   459,
     460,   291,   669,   670,   671,   672,   673,   467,   293,   469,
     678,   470,   136,   497,   569,   571,   573,   502,   210,   211,
     212,   213,   522,   549,   137,   138,   170,   171,   172,   173,
     174,   175,   176,   548,   462,   177,   139,   631,   463,   464,
     140,   715,   550,   649,   141,   716,   717,   684,   551,   685,
     659,   136,   686,   308,   687,   552,   214,   201,   202,   203,
     204,   205,   206,   238,   138,   553,   554,   718,   143,   745,
     144,   719,   720,   746,   747,   139,   555,   556,   557,   140,
     558,   570,   559,   141,   200,   201,   202,   203,   204,   205,
     206,   417,   561,   418,   419,   256,   257,   560,   702,   703,
     562,   704,   705,   574,   706,   707,   575,   708,   709,   576,
     710,   711,   200,   201,   202,   203,   204,   205,   206,   200,
     201,   202,   203,   204,   205,   206,   572,   837,   721,   722,
     136,   838,   839,   578,   727,   728,   239,   240,   241,   242,
     579,   580,   268,   138,   537,   538,   539,   143,   540,   144,
     533,   534,   535,   536,   139,   581,   582,   583,   140,   620,
     640,   621,   141,   641,   200,   201,   202,   203,   204,   205,
     206,   642,   732,   650,   243,   201,   202,   203,   204,   205,
     206,   651,   652,   734,   653,   735,   143,   660,   144,   661,
     736,   737,   200,   201,   202,   203,   204,   205,   206,   662,
     741,   742,   663,   743,   664,   744,   665,   666,   667,   674,
     748,   749,   668,   750,   751,   269,   270,   271,   272,   679,
     136,   658,   675,   676,   753,   754,   763,   694,   764,   756,
     766,   757,   137,   138,   695,   767,   723,   200,   201,   202,
     203,   204,   205,   206,   139,   724,   725,   726,   140,   752,
     762,   765,   141,   273,   201,   202,   203,   204,   205,   206,
     769,   136,   770,   775,   136,   143,   790,   144,   791,   793,
     136,   792,   801,   137,   138,   794,   276,   138,   795,   796,
     797,   798,   137,   138,   803,   139,   804,   818,   139,   140,
     824,   814,   140,   141,   139,   815,   141,   816,   140,   378,
     823,   768,   141,   379,   380,   825,   830,   831,   832,   842,
    -232,   236,   845,   846,   337,   847,   848,   859,     0,  -257,
     849,  -259,   850,   860,     0,   851,     0,   852,     0,     0,
     802,     0,   200,   201,   202,   203,   204,   205,   206,     0,
     853,   854,     0,   855,   856,     0,   857,   858,     0,   277,
     278,   279,   280,     0,     0,   143,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   861,     0,     0,
       0,     0,     0,   862,   863,     0,     0,     0,     0,     0,
     864,   865,     1,     2,     3,     4,     5,   200,   201,   202,
     203,   204,   205,   206,     0,   149,   143,     0,   144,   143,
       0,   144,     0,     0,   153,   143,     0,   144,   880,   882,
       0,     0,     0,   323,    15,    16,     0,    17,     0,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   324,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   881,   883,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     1,     2,     3,     4,     5,     0,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   325,   326,   327,   357,   358,     0,     0,     0,
       0,     0,     0,     0,     0,   330,    15,    16,     0,    17,
       0,     0,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   331,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   136,     0,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   283,   138,
       0,   357,   358,   136,   332,   333,   327,     0,     0,     0,
     139,     0,     0,     0,   140,   507,   138,     0,   141,     0,
     136,     0,     0,     0,     0,   136,     0,   139,     0,     0,
       0,   140,   515,   138,     0,   141,     0,   137,   138,     0,
       0,     0,     0,     0,   139,     0,     0,     0,   140,   139,
       0,     0,   141,   140,     0,   136,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,   136,
       0,   284,   285,   286,   287,     0,     0,     0,     0,   139,
       0,   137,   138,   140,     0,     0,     0,   141,   508,   509,
     510,   511,     0,   139,     0,     0,     0,   140,     0,     0,
       0,   141,     0,     0,     0,   516,   517,   518,   519,   200,
     201,   202,   203,   204,   205,   206,     0,     0,     0,     0,
       0,   143,     0,   144,     0,     0,   200,   201,   202,   203,
     204,   205,   206,     0,     0,     0,     0,     0,   143,   136,
     144,     0,     0,   200,   201,   202,   203,   204,   205,   206,
     384,   525,   138,     0,     0,   143,   136,   144,     0,     0,
     143,     0,   144,   139,     0,     0,     0,   140,   541,   138,
       0,   141,     0,   136,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,   140,   563,   138,     0,   141,   472,
     143,     0,   144,     0,     0,     0,     0,   139,     0,     0,
       0,   140,     0,   491,   143,   141,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,   526,   527,   528,   529,     0,     0,
       0,     0,     0,   137,   138,     0,     0,     0,     0,     0,
       0,   542,   543,   544,   545,   139,     0,     0,     0,   140,
       0,     0,     0,   141,     0,     0,     0,     0,   564,   565,
     566,   567,   200,   201,   202,   203,   204,   205,   206,     0,
       0,     0,     0,     0,   143,     0,   144,     0,     0,   200,
     201,   202,   203,   204,   205,   206,     0,     0,     0,     0,
       0,   143,   136,   144,     0,     0,   200,   201,   202,   203,
     204,   205,   206,     0,   643,   138,     0,     0,   143,     0,
     144,     0,     0,     0,     0,     0,   139,     0,     0,     0,
     140,   136,     0,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   138,   136,     0,   170,   171,   172,
     173,   174,   175,   176,     0,   139,   177,   137,   138,   140,
       0,     0,     0,   141,     0,     0,   143,   136,   144,   139,
       0,     0,   136,   140,     0,     0,     0,   141,     0,   137,
     138,   136,     0,     0,   137,   138,     0,   644,   645,   646,
     647,   139,     0,   137,   138,   140,   139,     0,     0,   141,
     140,     0,     0,     0,   141,   139,     0,     0,   136,   140,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
     137,   138,     0,     0,     0,   200,   201,   202,   203,   204,
     205,   206,   139,     0,     0,     0,   140,   143,     0,   144,
     141,     0,     0,     0,     0,     0,     0,   170,   171,   172,
     173,   174,   175,   176,     0,     0,   177,   588,   589,     0,
     729,     0,   730,   731,   256,   257,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
     143,     0,   144,   298,   299,   300,   301,   302,   303,   304,
       0,     0,   305,   596,   597,   590,   591,   592,   593,   594,
       0,     0,   143,     0,   144,     0,     0,   143,     0,   144,
       0,     0,   136,     0,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,   137,   138,     0,     0,     0,   136,
       0,   598,   599,   600,   601,   602,   139,     0,     0,     0,
     140,   137,   138,   143,   141,   144,   136,     0,     0,     0,
       0,     0,   136,   139,     0,     0,     0,   140,   137,   138,
       0,   141,     0,     0,   137,   138,     0,     0,     0,     0,
     139,     0,     0,     0,   140,     0,   139,     0,   141,   136,
     140,     0,     0,     0,   141,     0,     0,     0,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,     0,   604,
     605,   136,     0,   139,     0,     0,     0,   140,     0,     0,
       0,   141,     0,   137,   138,     0,   612,   613,   136,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,   140,
     137,   138,     0,   141,     0,   606,   607,   608,   609,   610,
       0,     0,   139,     0,     0,     0,   140,   143,     0,   144,
     141,     0,   614,   615,   616,   617,   618,     0,   404,     0,
       0,     0,   405,   406,   143,     0,   144,     0,     0,   200,
     201,   202,   203,   204,   205,   206,     0,   755,     0,   136,
     410,   143,     0,   144,   411,   412,     0,   143,     0,   144,
       0,   137,   138,   136,     0,     0,   136,   433,     0,     0,
       0,   434,   435,   139,     0,   137,   138,   140,   636,   138,
       0,   141,     0,     0,   143,     0,   144,   139,   136,     0,
     139,   140,     0,     0,   140,   141,     0,     0,   141,     0,
     137,   138,     0,     0,     0,     0,   143,     0,   144,     0,
       0,     0,   139,     0,     0,     0,   140,     0,     0,     0,
     141,     0,     0,   143,   136,   144,     0,   136,   437,     0,
       0,     0,   438,   439,     0,     0,   634,   138,     0,   137,
     138,     0,   440,     0,     0,   637,   441,   442,   139,   256,
     257,   139,   140,   136,     0,   140,   141,     0,     0,   141,
       0,     0,     0,   136,     0,   137,   138,   688,     0,     0,
       0,   689,   690,     0,     0,   137,   138,   139,     0,     0,
       0,   140,     0,     0,   143,   141,   144,   139,     0,     0,
       0,   140,   136,     0,     0,   141,     0,     0,   143,     0,
     144,   143,   136,   144,   137,   138,   691,     0,     0,     0,
     692,   693,     0,     0,   137,   138,   139,     0,     0,     0,
     140,     0,     0,   143,   141,   144,   139,     0,   136,     0,
     140,     0,   696,     0,   141,   254,   697,   698,     0,     0,
     677,   138,   699,     0,     0,   189,   700,   701,     0,     0,
       0,     0,   139,     0,     0,     0,   140,     0,     0,   143,
     141,   144,   143,     0,   144,     0,     0,     0,     0,     0,
       0,   712,     0,     0,     0,   713,   714,     0,     0,     0,
       0,   738,     0,     0,     0,   739,   740,     0,   143,     0,
     144,     0,     0,     0,     0,     0,     0,     0,   143,   313,
     144,   255,   190,   191,   192,   193,   256,   257,   258,   259,
     260,   261,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,     0,     0,     0,     0,   143,     0,   144,
       0,     0,     0,     0,     0,     0,     0,   143,     0,   144,
       0,     0,     0,     0,     0,     0,   200,   201,   202,   203,
     204,   205,   206,   262,   263,   264,   200,   201,   202,   203,
     204,   205,   206,   143,     0,   144,   190,   191,   192,   193,
     314,   315,   316,   317,   318,   319,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,   357,   358,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,   361,   357,   358,
     200,   201,   202,   203,   204,   205,   206,     0,     0,   365,
       0,     0,     0,     0,   359,     0,     0,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,   359,   357,   358,     0,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,   408,     0,
     357,   358,     0,     0,     0,     0,   360,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   409,     0,     0,     0,
       0,     0,     0,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,   357,
     358,     0,     0,     0,     0,     0,     0,   360,     0,     0,
       0,     0,     0,     0,     0,   443,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,     0,     0,     0,     0,
       0,     0,   359,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   471,     0,     0,   357,   358,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   523,     0,     0,   357,   358,     0,     0,     0,
       0,     0,     0,     0,   360,     0,     0,     0,     0,     0,
       0,   359,     0,     0,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   584,     0,   359,   357,
     358,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   758,     0,     0,   357,   358,     0,     0,
       0,     0,     0,   360,     0,     0,     0,     0,     0,     0,
       0,     0,   359,     0,     0,     0,     0,     0,     0,     0,
     360,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   759,     0,     0,   357,   358,     0,     0,     0,
       0,     0,     0,     0,   360,     0,     0,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   760,
       0,   360,   357,   358,     0,     0,     0,     0,   359,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   761,     0,     0,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   780,     0,
     360,   357,   358,     0,     0,     0,     0,   359,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     781,     0,     0,   357,   358,     0,     0,   360,     0,     0,
       0,     0,     0,     0,   359,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   782,     0,   360,
     357,   358,     0,     0,     0,     0,   359,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   783,
       0,     0,   357,   358,     0,     0,   360,     0,     0,     0,
       0,     0,     0,   359,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   784,     0,   360,   357,
     358,     0,     0,     0,     0,   359,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   785,     0,
       0,   357,   358,     0,     0,   360,     0,     0,     0,     0,
       0,     0,   359,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   786,     0,   360,   357,   358,
       0,     0,     0,     0,   359,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   787,     0,     0,
     357,   358,     0,     0,   360,     0,     0,     0,     0,     0,
       0,   359,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   788,     0,   360,   357,   358,     0,
       0,     0,     0,   359,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   789,     0,     0,   357,
     358,     0,     0,   360,     0,     0,     0,     0,     0,     0,
     359,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   799,     0,   360,   357,   358,     0,     0,
       0,     0,   359,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   800,     0,     0,   357,   358,
       0,     0,   360,     0,     0,     0,     0,     0,     0,   359,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   812,     0,   360,   357,   358,     0,     0,     0,
       0,   359,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   813,     0,     0,   357,   358,     0,
       0,   360,     0,     0,     0,     0,     0,     0,   359,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   817,     0,   360,   357,   358,     0,     0,     0,     0,
     359,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   819,     0,     0,   357,   358,     0,     0,
     360,     0,     0,     0,     0,     0,     0,   359,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     820,     0,   360,   357,   358,     0,     0,     0,     0,   359,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   821,     0,     0,   357,   358,     0,     0,   360,
       0,     0,     0,     0,     0,     0,   359,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   822,
       0,   360,   357,   358,     0,     0,     0,     0,   359,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   826,     0,     0,   357,   358,     0,     0,   360,     0,
       0,     0,     0,     0,     0,   359,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   827,     0,
     360,   357,   358,     0,     0,     0,     0,   359,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     828,     0,     0,   357,   358,     0,     0,   360,     0,     0,
       0,     0,     0,     0,   359,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   829,     0,   360,
     357,   358,     0,     0,     0,     0,   359,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   833,
       0,     0,   357,   358,     0,     0,   360,     0,     0,     0,
       0,     0,     0,   359,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   834,     0,   360,   357,
     358,     0,     0,     0,     0,   359,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   835,     0,
       0,   357,   358,     0,     0,   360,     0,     0,     0,     0,
       0,     0,   359,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   836,     0,   360,   357,   358,
       0,     0,     0,     0,   359,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   840,     0,     0,
     357,   358,     0,     0,   360,     0,     0,     0,     0,     0,
       0,   359,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   841,     0,   360,   357,   358,     0,
       0,     0,     0,   359,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   843,     0,     0,   357,
     358,     0,     0,   360,     0,     0,     0,     0,     0,     0,
     359,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   844,     0,   360,   357,   358,     0,     0,
       0,     0,   359,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   866,     0,     0,   357,   358,
       0,     0,   360,     0,     0,     0,     0,     0,     0,   359,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   867,     0,   360,   357,   358,     0,     0,     0,
       0,   359,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   868,     0,     0,   357,   358,     0,
       0,   360,     0,     0,     0,     0,     0,     0,   359,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   869,     0,   360,   357,   358,     0,     0,     0,     0,
     359,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   870,     0,     0,   357,   358,     0,     0,
     360,     0,     0,     0,     0,     0,     0,   359,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     871,     0,   360,   357,   358,     0,     0,     0,     0,   359,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   872,     0,     0,   357,   358,     0,     0,   360,
       0,     0,     0,     0,     0,     0,   359,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   873,
       0,   360,   357,   358,     0,     0,     0,     0,   359,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   874,     0,     0,   357,   358,     0,     0,   360,     0,
       0,     0,     0,     0,     0,   359,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   875,     0,
     360,   357,   358,     0,     0,     0,     0,   359,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     876,     0,     0,   357,   358,     0,     0,   360,     0,     0,
       0,     0,     0,     0,   359,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   877,     0,   360,
     357,   358,     0,     0,     0,     0,   359,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   878,
       0,     0,   357,   358,     0,     0,   360,     0,     0,     0,
       0,     0,     0,   359,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   879,     0,   360,   357,
     358,     0,     0,     0,     0,   359,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   884,     0,
       0,   357,   358,     0,     0,   360,     0,     0,     0,     0,
       0,     0,   359,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   885,     0,   360,   357,   358,
       0,     0,     0,     0,   359,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   886,     0,     0,
     357,   358,     0,     0,   360,     0,     0,     0,     0,     0,
       0,   359,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   887,     0,   360,   357,   358,     0,
       0,     0,     0,   359,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   888,     0,     0,   357,
     358,     0,     0,   360,     0,     0,     0,     0,     0,     0,
     359,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,   360,   357,   358,     0,     0,
       0,     0,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   360,     0,     0,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   360,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,   254,     5,     6,    21,    62,     8,     8,
     144,     8,    21,    88,   144,    16,    17,    92,    93,    20,
      20,    20,    88,    20,    88,   144,     9,    34,    29,    30,
       8,    32,     8,    88,     8,    47,   143,     8,    21,    22,
     143,    53,    20,     9,    20,   143,    20,    48,    49,    20,
      33,    52,    53,    54,    37,    21,    22,   132,    41,   143,
     144,     8,    63,    64,    65,    66,   132,    33,   132,     8,
       8,    37,    87,    20,     8,    41,    91,    34,   143,   144,
      81,    20,    20,    84,    85,    21,    20,     8,     9,    32,
      88,    89,    90,    91,    92,    93,     8,    40,    41,    42,
      43,    18,    19,    23,    24,    48,    23,    24,    20,    90,
      91,    94,    95,    96,    97,    90,    91,    60,     0,    62,
      63,    64,    65,   132,   133,   134,   135,   136,   137,   138,
      73,    34,    34,    76,   132,   136,    88,   138,    34,    82,
      92,    93,    88,    86,    21,    88,    92,    93,   144,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    39,    39,
      88,   144,    24,   146,    92,    93,    39,     3,     4,     5,
       6,     7,    88,    89,    90,    91,    34,   143,   144,    21,
     146,   432,    34,    88,    34,    34,    21,    92,    93,    25,
      26,    27,    28,    29,    30,    31,    32,    34,    34,    35,
      36,    34,    38,    34,    40,    34,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,   219,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    39,    39,   254,    21,   132,   133,   134,   135,   136,
     137,   138,    98,    39,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    39,
     132,   133,   134,   135,   136,   137,   138,   132,   133,   134,
     135,   136,   137,   138,     9,    39,   142,    39,   144,   145,
      39,    39,    16,    17,    18,    19,    21,    22,    39,    23,
      24,    39,    39,   324,    39,    89,    39,   382,    33,    39,
     331,   386,    37,   388,    87,    88,    41,    90,    91,    92,
      93,    39,    39,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,    54,   132,   133,   134,   135,   136,
     137,   138,   623,   374,    88,    39,    39,    39,    92,    93,
     381,    39,   383,     9,    39,    39,   387,    39,    87,    88,
     391,    90,    91,    92,    93,    21,    22,    12,    13,    14,
      15,    16,    17,    18,    19,    39,   407,    33,    23,    24,
      39,    37,   413,    88,    39,    41,    39,    92,    93,    39,
      39,   422,   423,   424,   425,   426,    39,    39,   429,   430,
     431,   432,    88,    39,    34,   436,    92,    93,   381,   144,
     383,   146,    88,    54,   387,    88,    92,    93,   391,    92,
      93,    21,   453,   454,   455,   456,   457,    34,    21,    34,
     461,    34,     9,    20,   407,   408,   409,    20,    94,    95,
      96,    97,    20,     8,    21,    22,   125,   126,   127,   128,
     129,   130,   131,    20,    88,   134,    33,   430,    92,    93,
      37,    88,     8,   436,    41,    92,    93,   498,    20,   500,
     443,     9,   503,    21,   505,     8,   132,   133,   134,   135,
     136,   137,   138,    21,    22,     8,    20,    88,   144,    88,
     146,    92,    93,    92,    93,    33,     8,     8,    20,    37,
       8,    21,     8,    41,   132,   133,   134,   135,   136,   137,
     138,    88,     8,    90,    91,    92,    93,    20,   549,   550,
       8,   552,   553,    20,   555,   556,    20,   558,   559,    20,
     561,   562,   132,   133,   134,   135,   136,   137,   138,   132,
     133,   134,   135,   136,   137,   138,    21,    88,   579,   580,
       9,    92,    93,    20,   585,   586,    94,    95,    96,    97,
       8,     8,    21,    22,    89,    90,    91,   144,    93,   146,
      89,    90,    91,    92,    33,    20,    20,    20,    37,   132,
      20,   132,    41,     8,   132,   133,   134,   135,   136,   137,
     138,     8,   623,    20,   132,   133,   134,   135,   136,   137,
     138,     8,     8,   634,    20,   636,   144,    20,   146,     8,
     641,   642,   132,   133,   134,   135,   136,   137,   138,     8,
     651,   652,    20,   654,     8,   656,     8,    20,    99,    20,
     661,   662,    88,   664,   665,    94,    95,    96,    97,    20,
       9,    21,     8,     8,   675,   676,     8,    39,     8,   680,
       8,   682,    21,    22,    39,     8,    39,   132,   133,   134,
     135,   136,   137,   138,    33,    39,    39,    39,    37,    39,
      20,    20,    41,   132,   133,   134,   135,   136,   137,   138,
     132,     9,    20,    20,     9,   144,    20,   146,     8,    20,
       9,     8,   723,    21,    22,     8,    21,    22,     8,    20,
       8,     8,    21,    22,   132,    33,   132,     8,    33,    37,
       8,    20,    37,    41,    33,    20,    41,    20,    37,    88,
      20,   694,    41,    92,    93,     8,    20,     8,     8,    20,
      34,    45,   763,   764,    93,   766,   767,    39,    -1,    34,
     771,    34,   773,    39,    -1,   776,    -1,   778,    -1,    -1,
     723,    -1,   132,   133,   134,   135,   136,   137,   138,    -1,
     791,   792,    -1,   794,   795,    -1,   797,   798,    -1,    94,
      95,    96,    97,    -1,    -1,   144,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   818,    -1,    -1,
      -1,    -1,    -1,   824,   825,    -1,    -1,    -1,    -1,    -1,
     831,   832,     3,     4,     5,     6,     7,   132,   133,   134,
     135,   136,   137,   138,    -1,   143,   144,    -1,   146,   144,
      -1,   146,    -1,    -1,   143,   144,    -1,   146,   859,   860,
      -1,    -1,    -1,    34,    35,    36,    -1,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   859,   860,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     3,     4,     5,     6,     7,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   143,   144,   145,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     9,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    21,    22,
      -1,    23,    24,     9,   143,   144,   145,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    37,    21,    22,    -1,    41,    -1,
       9,    -1,    -1,    -1,    -1,     9,    -1,    33,    -1,    -1,
      -1,    37,    21,    22,    -1,    41,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    37,    33,
      -1,    -1,    41,    37,    -1,     9,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,     9,
      -1,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    33,
      -1,    21,    22,    37,    -1,    -1,    -1,    41,    94,    95,
      96,    97,    -1,    33,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    94,    95,    96,    97,   132,
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,   144,    -1,   146,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,   144,     9,
     146,    -1,    -1,   132,   133,   134,   135,   136,   137,   138,
     134,    21,    22,    -1,    -1,   144,     9,   146,    -1,    -1,
     144,    -1,   146,    33,    -1,    -1,    -1,    37,    21,    22,
      -1,    41,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    37,    21,    22,    -1,    41,   143,
     144,    -1,   146,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    37,    -1,   143,   144,    41,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    33,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,   132,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,   144,    -1,   146,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,   144,     9,   146,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,    21,    22,    -1,    -1,   144,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      37,     9,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,     9,    -1,   125,   126,   127,
     128,   129,   130,   131,    -1,    33,   134,    21,    22,    37,
      -1,    -1,    -1,    41,    -1,    -1,   144,     9,   146,    33,
      -1,    -1,     9,    37,    -1,    -1,    -1,    41,    -1,    21,
      22,     9,    -1,    -1,    21,    22,    -1,    94,    95,    96,
      97,    33,    -1,    21,    22,    37,    33,    -1,    -1,    41,
      37,    -1,    -1,    -1,    41,    33,    -1,    -1,     9,    37,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,   132,   133,   134,   135,   136,
     137,   138,    33,    -1,    -1,    -1,    37,   144,    -1,   146,
      41,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,    94,    95,    -1,
      88,    -1,    90,    91,    92,    93,   144,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,   146,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,    94,    95,   132,   133,   134,   135,   136,
      -1,    -1,   144,    -1,   146,    -1,    -1,   144,    -1,   146,
      -1,    -1,     9,    -1,    -1,    -1,   144,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,     9,
      -1,   132,   133,   134,   135,   136,    33,    -1,    -1,    -1,
      37,    21,    22,   144,    41,   146,     9,    -1,    -1,    -1,
      -1,    -1,     9,    33,    -1,    -1,    -1,    37,    21,    22,
      -1,    41,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    37,    -1,    33,    -1,    41,     9,
      37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,     9,    -1,    33,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    41,    -1,    21,    22,    -1,    96,    97,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    37,
      21,    22,    -1,    41,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    33,    -1,    -1,    -1,    37,   144,    -1,   146,
      41,    -1,   132,   133,   134,   135,   136,    -1,    88,    -1,
      -1,    -1,    92,    93,   144,    -1,   146,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,   134,    -1,     9,
      88,   144,    -1,   146,    92,    93,    -1,   144,    -1,   146,
      -1,    21,    22,     9,    -1,    -1,     9,    88,    -1,    -1,
      -1,    92,    93,    33,    -1,    21,    22,    37,    21,    22,
      -1,    41,    -1,    -1,   144,    -1,   146,    33,     9,    -1,
      33,    37,    -1,    -1,    37,    41,    -1,    -1,    41,    -1,
      21,    22,    -1,    -1,    -1,    -1,   144,    -1,   146,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    -1,    -1,   144,     9,   146,    -1,     9,    88,    -1,
      -1,    -1,    92,    93,    -1,    -1,    21,    22,    -1,    21,
      22,    -1,    88,    -1,    -1,    88,    92,    93,    33,    92,
      93,    33,    37,     9,    -1,    37,    41,    -1,    -1,    41,
      -1,    -1,    -1,     9,    -1,    21,    22,    88,    -1,    -1,
      -1,    92,    93,    -1,    -1,    21,    22,    33,    -1,    -1,
      -1,    37,    -1,    -1,   144,    41,   146,    33,    -1,    -1,
      -1,    37,     9,    -1,    -1,    41,    -1,    -1,   144,    -1,
     146,   144,     9,   146,    21,    22,    88,    -1,    -1,    -1,
      92,    93,    -1,    -1,    21,    22,    33,    -1,    -1,    -1,
      37,    -1,    -1,   144,    41,   146,    33,    -1,     9,    -1,
      37,    -1,    88,    -1,    41,    21,    92,    93,    -1,    -1,
      21,    22,    88,    -1,    -1,    21,    92,    93,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    37,    -1,    -1,   144,
      41,   146,   144,    -1,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    92,    93,    -1,   144,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    21,
     146,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   132,   133,   134,   135,
     136,   137,   138,   144,    -1,   146,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    23,    24,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    39,    23,    24,
     132,   133,   134,   135,   136,   137,   138,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    56,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    56,    23,    24,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    39,    -1,
      23,    24,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    56,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    23,    24,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    56,    23,
      24,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    98,    23,    24,    -1,    -1,    -1,    -1,    56,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      98,    23,    24,    -1,    -1,    -1,    -1,    56,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    98,
      23,    24,    -1,    -1,    -1,    -1,    56,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    98,    23,
      24,    -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    56,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    98,    23,    24,
      -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      23,    24,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    56,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    98,    23,    24,    -1,
      -1,    -1,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      56,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    98,    23,    24,    -1,    -1,
      -1,    -1,    56,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    23,    24,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    56,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    98,    23,    24,    -1,    -1,    -1,
      -1,    56,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    56,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    98,    23,    24,    -1,    -1,    -1,    -1,
      56,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    56,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    98,    23,    24,    -1,    -1,    -1,    -1,    56,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    56,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    98,    23,    24,    -1,    -1,    -1,    -1,    56,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    23,    24,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      98,    23,    24,    -1,    -1,    -1,    -1,    56,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    98,
      23,    24,    -1,    -1,    -1,    -1,    56,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    98,    23,
      24,    -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    56,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    98,    23,    24,
      -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      23,    24,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    56,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    98,    23,    24,    -1,
      -1,    -1,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      56,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    98,    23,    24,    -1,    -1,
      -1,    -1,    56,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    23,    24,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    56,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    98,    23,    24,    -1,    -1,    -1,
      -1,    56,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    56,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    98,    23,    24,    -1,    -1,    -1,    -1,
      56,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    56,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    98,    23,    24,    -1,    -1,    -1,    -1,    56,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    56,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    98,    23,    24,    -1,    -1,    -1,    -1,    56,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    23,    24,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      98,    23,    24,    -1,    -1,    -1,    -1,    56,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    98,
      23,    24,    -1,    -1,    -1,    -1,    56,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    98,    23,
      24,    -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    56,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    98,    23,    24,
      -1,    -1,    -1,    -1,    56,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      23,    24,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    56,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    98,    23,    24,    -1,
      -1,    -1,    -1,    56,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      56,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    98,    23,    24,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    25,    26,    27,    28,
      29,    30,    31,    32,    34,    35,    36,    38,    40,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    98,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   142,
     144,   145,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     9,    21,    22,    33,
      37,    41,   143,   144,   146,   197,   198,   199,   198,   143,
     195,   198,   144,   143,   196,   198,   198,   144,   144,    34,
     143,   143,   143,   144,   143,   144,   143,   198,   198,    34,
     125,   126,   127,   128,   129,   130,   131,   134,   198,   206,
      87,    88,    90,    91,    92,    93,   203,   198,   198,    21,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     132,   133,   134,   135,   136,   137,   138,   200,   202,    21,
      94,    95,    96,    97,   132,   198,   200,    88,   132,    21,
      88,   132,    88,    92,    93,   132,    21,   200,    21,   200,
      21,   200,    21,   200,    92,    93,   203,   206,    21,    94,
      95,    96,    97,   132,   198,   200,   198,   198,    21,   198,
     206,   198,    21,   200,    21,    87,    92,    93,    94,    95,
      96,    97,   139,   140,   141,   200,   201,   202,    21,    94,
      95,    96,    97,   132,   198,   200,    21,    94,    95,    96,
      97,   198,   200,    21,    94,    95,    96,    97,   198,   200,
     198,    21,   200,    21,   200,    21,    87,    91,   125,   126,
     127,   128,   129,   130,   131,   134,   198,   207,    21,   200,
     198,   198,   200,    21,    92,    93,    94,    95,    96,    97,
     200,   202,    34,    34,    54,   143,   144,   145,   154,   155,
      34,    54,   143,   144,   154,   155,     0,   153,    34,    34,
     198,   198,   198,   144,    39,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    23,    24,    56,
      98,    39,    39,    24,    39,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    39,    88,    92,    93,    88,    92,
      93,    39,    39,    39,   134,   198,    39,    39,    39,    39,
      39,    39,    88,    92,    93,    88,    92,    93,    88,    92,
      93,    88,    92,    93,    88,    92,    93,    39,    39,    39,
      88,    92,    93,    39,    88,    92,    93,    88,    90,    91,
     198,   201,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    88,    92,    93,    39,    88,    92,    93,
      88,    92,    93,    39,    88,    92,    93,    88,    92,    93,
      89,    39,    39,    39,    39,    39,    39,    39,    88,    92,
      93,    39,    88,    92,    93,   198,    34,    34,   198,    34,
      34,    20,   143,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   143,   198,   198,   143,   198,   198,    20,     8,    20,
       8,    20,    20,     8,    20,     8,    20,    21,    94,    95,
      96,    97,   198,   200,   202,    21,    94,    95,    96,    97,
     198,   200,    20,    20,   202,    21,    94,    95,    96,    97,
     198,   200,   202,    89,    90,    91,    92,    89,    90,    91,
      93,    21,    94,    95,    96,    97,   198,   200,    20,     8,
       8,    20,     8,     8,    20,     8,     8,    20,     8,     8,
      20,     8,     8,    21,    94,    95,    96,    97,   198,   200,
      21,   200,    21,   200,    20,    20,    20,   198,    20,     8,
       8,    20,    20,    20,    20,     8,     9,   198,    94,    95,
     132,   133,   134,   135,   136,   198,    94,    95,   132,   133,
     134,   135,   136,   198,    96,    97,   132,   133,   134,   135,
     136,   198,    96,    97,   132,   133,   134,   135,   136,   198,
     132,   132,   198,    21,    94,    95,    96,    97,   139,   140,
     198,   200,   204,   205,    21,   198,    21,    88,   198,   201,
      20,     8,     8,    21,    94,    95,    96,    97,   198,   200,
      20,     8,     8,    20,     8,    20,     8,    20,    21,   200,
      20,     8,     8,    20,     8,     8,    20,    99,    88,   198,
     198,   198,   198,   198,    20,     8,     8,    21,   198,    20,
       8,    20,     8,    20,   198,   198,   198,   198,    88,    92,
      93,    88,    92,    93,    39,    39,    88,    92,    93,    88,
      92,    93,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,    88,    92,    93,    88,    92,    93,    88,    92,
      93,   198,   198,    39,    39,    39,    39,   198,   198,    88,
      90,    91,   198,   201,   198,   198,   198,   198,    88,    92,
      93,   198,   198,   198,   198,    88,    92,    93,   198,   198,
     198,   198,    39,   198,   198,   134,   198,   198,    20,    20,
      20,    20,    20,     8,     8,    20,     8,     8,   200,   132,
      20,     8,    20,     8,    20,    20,     8,    20,     8,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,     8,     8,    20,     8,     8,    20,     8,     8,    20,
      20,   198,   200,   132,   132,    88,    89,    90,    91,    92,
      93,   132,    20,    20,    20,    20,    20,    20,     8,    20,
      20,    20,    20,    20,     8,     8,    20,    20,    20,    20,
      20,     8,     8,    20,    20,    20,    20,    88,    92,    93,
      20,    20,    20,    20,    20,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,    39,
      39,   198,   198,   198,   198,   198,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
     198,   200,   198,   200,    20,    20,    20,    20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   150,   151,   152,   152,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   157,   157,   158,   159,   160,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   164,   164,
     164,   164,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   168,   169,
     169,   169,   169,   169,   170,   171,   171,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     173,   173,   173,   173,   173,   174,   174,   174,   174,   174,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   177,   177,   178,
     178,   178,   179,   179,   179,   180,   180,   180,   180,   181,
     181,   182,   182,   182,   182,   183,   183,   183,   183,   184,
     184,   184,   184,   185,   185,   185,   185,   186,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   188,   188,
     188,   188,   189,   189,   189,   189,   190,   190,   190,   190,
     191,   191,   191,   191,   192,   192,   192,   192,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   195,   195,   195,   195,   196,
     196,   196,   196,   197,   197,   197,   197,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   199,   199,   199,
     199,   199,   200,   200,   200,   200,   200,   200,   200,   201,
     201,   202,   202,   202,   202,   203,   203,   203,   203,   204,
     204,   205,   205,   206,   206,   206,   206,   206,   206,   206,
     206,   207,   207,   207,   207
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     3,     1,     2,
       2,     3,     3,     3,     3,     2,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     4,     2,     2,     2,     4,     4,     6,     8,
       8,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       6,     8,     8,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     2,
       4,     6,     6,     4,     4,     2,     2,     2,     2,     4,
       4,     6,     8,     8,     4,     4,     4,     4,     6,     8,
       8,     4,     2,     4,     2,     2,     4,     6,     6,     4,
       4,     2,     2,     2,     2,     2,     4,     6,     6,     4,
       4,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       4,     6,     6,     6,     2,     6,     4,     2,     2,     4,
       6,     6,     4,     4,     2,     2,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     2,     4,     4,     4,
       4,     4,     6,     4,     8,     6,     6,     6,     6,     6,
       8,     8,     8,     8,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     4,     4,     4,     4,     6,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       2,     4,     6,     6,     2,     2,     2,     2,     4,     4,
       6,     8,     8,     4,     4,     4,     4,     6,     6,     2,
       2,     2,     2,     2,     2,     4,     6,     8,     8,     1,
       2,     2,     4,     6,     6,     2,     4,     6,     6,     2,
       4,     6,     6,     2,     4,     6,     6,     2,     4,     4,
       6,     8,     8,     4,     4,     4,     4,     4,     4,     6,
       8,     8,     2,     4,     6,     6,     2,     4,     6,     6,
       2,     4,     6,     6,     2,     4,     6,     6,     2,     2,
       4,     6,     6,     2,     2,     2,     2,     2,     2,     4,
       6,     6,     2,     2,     2,     2,     4,     4,     6,     8,
       8,     4,     4,     4,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     3,     3,     1,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 210 "grammar.y" /* yacc.c:1646  */
    {  }
#line 2780 "grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 212 "grammar.y" /* yacc.c:1646  */
    {  }
#line 2786 "grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 213 "grammar.y" /* yacc.c:1646  */
    {  }
#line 2792 "grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 216 "grammar.y" /* yacc.c:1646  */
    { yylineno++; previouspc = pc; }
#line 2798 "grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 217 "grammar.y" /* yacc.c:1646  */
    { setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2804 "grammar.c" /* yacc.c:1646  */
    break;

  case 7:
#line 218 "grammar.y" /* yacc.c:1646  */
    { setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2810 "grammar.c" /* yacc.c:1646  */
    break;

  case 8:
#line 219 "grammar.y" /* yacc.c:1646  */
    { yylineno++; previouspc = pc; }
#line 2816 "grammar.c" /* yacc.c:1646  */
    break;

  case 9:
#line 220 "grammar.y" /* yacc.c:1646  */
    { setLabelAddress((yyvsp[-1].literal),pc); outDirective(); yylineno++; previouspc = pc; }
#line 2822 "grammar.c" /* yacc.c:1646  */
    break;

  case 10:
#line 221 "grammar.y" /* yacc.c:1646  */
    { setLabelAddress((yyvsp[-1].literal),pc); outDirective(); yylineno++; previouspc = pc; }
#line 2828 "grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 222 "grammar.y" /* yacc.c:1646  */
    { yylineno++; warningError("Include feature has not yet being implemented. Ignoring this line"); }
#line 2834 "grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 223 "grammar.y" /* yacc.c:1646  */
    { yylineno++; warningError("Include feature has not yet being implemented. Ignoring this line"); }
#line 2840 "grammar.c" /* yacc.c:1646  */
    break;

  case 13:
#line 224 "grammar.y" /* yacc.c:1646  */
    {  includebin((yyvsp[-1].literal)); yylineno++; }
#line 2846 "grammar.c" /* yacc.c:1646  */
    break;

  case 14:
#line 225 "grammar.y" /* yacc.c:1646  */
    {  includebin((yyvsp[-1].literal)); yylineno++; }
#line 2852 "grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 226 "grammar.y" /* yacc.c:1646  */
    {  yylineno++; previouspc = pc; }
#line 2858 "grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 227 "grammar.y" /* yacc.c:1646  */
    {  setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2864 "grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 228 "grammar.y" /* yacc.c:1646  */
    {  setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2870 "grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 229 "grammar.y" /* yacc.c:1646  */
    { yylineno++; /* MISSING !!!! */ }
#line 2876 "grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 230 "grammar.y" /* yacc.c:1646  */
    { yylineno++; /* MISSING Absolute segment directive mode. Not yet implemented */ }
#line 2882 "grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 231 "grammar.y" /* yacc.c:1646  */
    { yylineno++; /* nothing happens, perhaps to add this to a .lst file */ }
#line 2888 "grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 232 "grammar.y" /* yacc.c:1646  */
    { yylineno++; /* nothing happens, I've foudn this directive around, probably alias to TITLE */ }
#line 2894 "grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 233 "grammar.y" /* yacc.c:1646  */
    { yylineno++; condStatus = ((yyvsp[-1].normal)==0)?0:1; }
#line 2900 "grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "grammar.y" /* yacc.c:1646  */
    { yylineno++; condStatus = (LookupTableLabels((yyvsp[-1].literal))<0)?0:1; }
#line 2906 "grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "grammar.y" /* yacc.c:1646  */
    { yylineno++; condStatus = (LookupTableLabels((yyvsp[-1].literal))<0)?1:0; }
#line 2912 "grammar.c" /* yacc.c:1646  */
    break;

  case 25:
#line 236 "grammar.y" /* yacc.c:1646  */
    { if (condStatus < 0) { fatalError("Syntax error. Detected ENDIF without IF"); } condStatus = -1; yylineno++; }
#line 2918 "grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 237 "grammar.y" /* yacc.c:1646  */
    { fatalError("Syntax error: I do not understand this line"); }
#line 2924 "grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 238 "grammar.y" /* yacc.c:1646  */
    { fatalError("Syntax error: I do not understand this line"); }
#line 2930 "grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 239 "grammar.y" /* yacc.c:1646  */
    { fatalError("Syntax error: I do not understand this line"); }
#line 2936 "grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 241 "grammar.y" /* yacc.c:1646  */
    { setStart((yyvsp[0].normal)); outDirective();  }
#line 2942 "grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 242 "grammar.y" /* yacc.c:1646  */
    { directiveError((yyvsp[0].literal)); }
#line 2948 "grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 243 "grammar.y" /* yacc.c:1646  */
    { return 0; /* we should stop here compilation */}
#line 2954 "grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "grammar.y" /* yacc.c:1646  */
    { return 0; /* MISSING, in order to allow entry point definition */ }
#line 2960 "grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 245 "grammar.y" /* yacc.c:1646  */
    { }
#line 2966 "grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 246 "grammar.y" /* yacc.c:1646  */
    { }
#line 2972 "grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 247 "grammar.y" /* yacc.c:1646  */
    { }
#line 2978 "grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 248 "grammar.y" /* yacc.c:1646  */
    { }
#line 2984 "grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "grammar.y" /* yacc.c:1646  */
    { }
#line 2990 "grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 250 "grammar.y" /* yacc.c:1646  */
    { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal));  }
#line 2996 "grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 251 "grammar.y" /* yacc.c:1646  */
    { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal));  }
#line 3002 "grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 252 "grammar.y" /* yacc.c:1646  */
    { k = (((pc/(yyvsp[0].normal))+1)*(yyvsp[0].normal)); for(a=pc; a < k; a++) { outCode(1,0x0); } }
#line 3008 "grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 253 "grammar.y" /* yacc.c:1646  */
    { setLimit((yyvsp[0].normal)); outDirective();  }
#line 3014 "grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 256 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3020 "grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3026 "grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 258 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3032 "grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 259 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3038 "grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 260 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3044 "grammar.c" /* yacc.c:1646  */
    break;

  case 47:
#line 261 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3050 "grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 262 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3056 "grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 263 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3062 "grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 264 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3068 "grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 265 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3074 "grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 266 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3080 "grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 267 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3086 "grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 268 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3092 "grammar.c" /* yacc.c:1646  */
    break;

  case 55:
#line 269 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3098 "grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 270 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3104 "grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 271 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3110 "grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 272 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3116 "grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 273 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3122 "grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 274 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3128 "grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 275 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3134 "grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 276 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3140 "grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 277 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3146 "grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 278 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3152 "grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 279 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3158 "grammar.c" /* yacc.c:1646  */
    break;

  case 66:
#line 280 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3164 "grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 281 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3170 "grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 282 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3176 "grammar.c" /* yacc.c:1646  */
    break;

  case 69:
#line 283 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3182 "grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 284 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3188 "grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 285 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3194 "grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 286 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3200 "grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 287 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3206 "grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 288 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3212 "grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 289 "grammar.y" /* yacc.c:1646  */
    {  }
#line 3218 "grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 290 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x3F); }
#line 3224 "grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 291 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xA9); }
#line 3230 "grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 292 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xB9); }
#line 3236 "grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 293 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xA1); }
#line 3242 "grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 294 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xB1); }
#line 3248 "grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 295 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x2F); }
#line 3254 "grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 296 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x27); }
#line 3260 "grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 297 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xF3); }
#line 3266 "grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 298 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xFB); }
#line 3272 "grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 299 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xD9); }
#line 3278 "grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 300 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x76); }
#line 3284 "grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 301 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xAA); }
#line 3290 "grammar.c" /* yacc.c:1646  */
    break;

  case 88:
#line 302 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xBA); }
#line 3296 "grammar.c" /* yacc.c:1646  */
    break;

  case 89:
#line 303 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xA2); }
#line 3302 "grammar.c" /* yacc.c:1646  */
    break;

  case 90:
#line 304 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xB2); }
#line 3308 "grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 305 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xA8); }
#line 3314 "grammar.c" /* yacc.c:1646  */
    break;

  case 92:
#line 306 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xB8); }
#line 3320 "grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 307 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xA0); }
#line 3326 "grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 308 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xB0); }
#line 3332 "grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 309 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x44); }
#line 3338 "grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 310 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x00);      }
#line 3344 "grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 311 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xBB); }
#line 3350 "grammar.c" /* yacc.c:1646  */
    break;

  case 98:
#line 312 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xB3); }
#line 3356 "grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 313 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xAB); }
#line 3362 "grammar.c" /* yacc.c:1646  */
    break;

  case 100:
#line 314 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0xA3); }
#line 3368 "grammar.c" /* yacc.c:1646  */
    break;

  case 101:
#line 315 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x4D); }
#line 3374 "grammar.c" /* yacc.c:1646  */
    break;

  case 102:
#line 316 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x45); }
#line 3380 "grammar.c" /* yacc.c:1646  */
    break;

  case 103:
#line 317 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x17);      }
#line 3386 "grammar.c" /* yacc.c:1646  */
    break;

  case 104:
#line 318 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x07);      }
#line 3392 "grammar.c" /* yacc.c:1646  */
    break;

  case 105:
#line 319 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x6F); }
#line 3398 "grammar.c" /* yacc.c:1646  */
    break;

  case 106:
#line 320 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x1F);      }
#line 3404 "grammar.c" /* yacc.c:1646  */
    break;

  case 107:
#line 321 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x0F);      }
#line 3410 "grammar.c" /* yacc.c:1646  */
    break;

  case 108:
#line 322 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x67); }
#line 3416 "grammar.c" /* yacc.c:1646  */
    break;

  case 109:
#line 323 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x37); }
#line 3422 "grammar.c" /* yacc.c:1646  */
    break;

  case 110:
#line 327 "grammar.y" /* yacc.c:1646  */
    { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal)); }
#line 3428 "grammar.c" /* yacc.c:1646  */
    break;

  case 111:
#line 329 "grammar.y" /* yacc.c:1646  */
    { for(a=0;a<abs((yyvsp[0].normal));a++) { outCode(1,0x0); } }
#line 3434 "grammar.c" /* yacc.c:1646  */
    break;

  case 112:
#line 330 "grammar.y" /* yacc.c:1646  */
    {  for(a=0;a<abs((yyvsp[-2].normal));a++) { outCode(1,(yyvsp[0].normal)); }  }
#line 3440 "grammar.c" /* yacc.c:1646  */
    break;

  case 113:
#line 332 "grammar.y" /* yacc.c:1646  */
    { for(a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3446 "grammar.c" /* yacc.c:1646  */
    break;

  case 114:
#line 334 "grammar.y" /* yacc.c:1646  */
    { for(a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3452 "grammar.c" /* yacc.c:1646  */
    break;

  case 115:
#line 336 "grammar.y" /* yacc.c:1646  */
    { for(a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3458 "grammar.c" /* yacc.c:1646  */
    break;

  case 116:
#line 338 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCE,(yyvsp[0].normal)); }
#line 3464 "grammar.c" /* yacc.c:1646  */
    break;

  case 117:
#line 339 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|8); outCode(1,k); }
#line 3470 "grammar.c" /* yacc.c:1646  */
    break;

  case 118:
#line 340 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x8E); }
#line 3476 "grammar.c" /* yacc.c:1646  */
    break;

  case 119:
#line 341 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x8E,(yyvsp[-1].normal)); }
#line 3482 "grammar.c" /* yacc.c:1646  */
    break;

  case 120:
#line 342 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x8E,(yyvsp[-1].normal)); }
#line 3488 "grammar.c" /* yacc.c:1646  */
    break;

  case 121:
#line 343 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x8E,0); }
#line 3494 "grammar.c" /* yacc.c:1646  */
    break;

  case 122:
#line 344 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x8E,0); }
#line 3500 "grammar.c" /* yacc.c:1646  */
    break;

  case 123:
#line 345 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte)<<4)|64|8|2); outCode(2,0xED,k); }
#line 3506 "grammar.c" /* yacc.c:1646  */
    break;

  case 124:
#line 346 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x8C); }
#line 3512 "grammar.c" /* yacc.c:1646  */
    break;

  case 125:
#line 347 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x8D); }
#line 3518 "grammar.c" /* yacc.c:1646  */
    break;

  case 126:
#line 348 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x8C); }
#line 3524 "grammar.c" /* yacc.c:1646  */
    break;

  case 127:
#line 349 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x8D); }
#line 3530 "grammar.c" /* yacc.c:1646  */
    break;

  case 128:
#line 351 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xC6,(yyvsp[0].normal)); }
#line 3536 "grammar.c" /* yacc.c:1646  */
    break;

  case 129:
#line 352 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128); outCode(1,k); }
#line 3542 "grammar.c" /* yacc.c:1646  */
    break;

  case 130:
#line 353 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x86); }
#line 3548 "grammar.c" /* yacc.c:1646  */
    break;

  case 131:
#line 354 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x86,(yyvsp[-1].normal)); }
#line 3554 "grammar.c" /* yacc.c:1646  */
    break;

  case 132:
#line 355 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x86,(yyvsp[-1].normal)); }
#line 3560 "grammar.c" /* yacc.c:1646  */
    break;

  case 133:
#line 356 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x86,0); }
#line 3566 "grammar.c" /* yacc.c:1646  */
    break;

  case 134:
#line 357 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x86,0); }
#line 3572 "grammar.c" /* yacc.c:1646  */
    break;

  case 135:
#line 358 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte)<<4)|8|1); outCode(1,k); }
#line 3578 "grammar.c" /* yacc.c:1646  */
    break;

  case 136:
#line 359 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x09); }
#line 3584 "grammar.c" /* yacc.c:1646  */
    break;

  case 137:
#line 360 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x19); }
#line 3590 "grammar.c" /* yacc.c:1646  */
    break;

  case 138:
#line 361 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x29); }
#line 3596 "grammar.c" /* yacc.c:1646  */
    break;

  case 139:
#line 362 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x39); }
#line 3602 "grammar.c" /* yacc.c:1646  */
    break;

  case 140:
#line 363 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x09); }
#line 3608 "grammar.c" /* yacc.c:1646  */
    break;

  case 141:
#line 364 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x19); }
#line 3614 "grammar.c" /* yacc.c:1646  */
    break;

  case 142:
#line 365 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x29); }
#line 3620 "grammar.c" /* yacc.c:1646  */
    break;

  case 143:
#line 366 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x39); }
#line 3626 "grammar.c" /* yacc.c:1646  */
    break;

  case 144:
#line 367 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x84); }
#line 3632 "grammar.c" /* yacc.c:1646  */
    break;

  case 145:
#line 368 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x85); }
#line 3638 "grammar.c" /* yacc.c:1646  */
    break;

  case 146:
#line 369 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x84); }
#line 3644 "grammar.c" /* yacc.c:1646  */
    break;

  case 147:
#line 370 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x85); }
#line 3650 "grammar.c" /* yacc.c:1646  */
    break;

  case 148:
#line 372 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3656 "grammar.c" /* yacc.c:1646  */
    break;

  case 149:
#line 373 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3662 "grammar.c" /* yacc.c:1646  */
    break;

  case 150:
#line 374 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xA6); }
#line 3668 "grammar.c" /* yacc.c:1646  */
    break;

  case 151:
#line 375 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3674 "grammar.c" /* yacc.c:1646  */
    break;

  case 152:
#line 376 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3680 "grammar.c" /* yacc.c:1646  */
    break;

  case 153:
#line 377 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xA6,0); }
#line 3686 "grammar.c" /* yacc.c:1646  */
    break;

  case 154:
#line 378 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xA6,0); }
#line 3692 "grammar.c" /* yacc.c:1646  */
    break;

  case 155:
#line 380 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xA4); }
#line 3698 "grammar.c" /* yacc.c:1646  */
    break;

  case 156:
#line 381 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xA5); }
#line 3704 "grammar.c" /* yacc.c:1646  */
    break;

  case 157:
#line 382 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xA4); }
#line 3710 "grammar.c" /* yacc.c:1646  */
    break;

  case 158:
#line 383 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xA5); }
#line 3716 "grammar.c" /* yacc.c:1646  */
    break;

  case 159:
#line 384 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3722 "grammar.c" /* yacc.c:1646  */
    break;

  case 160:
#line 385 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3728 "grammar.c" /* yacc.c:1646  */
    break;

  case 161:
#line 386 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xA6); }
#line 3734 "grammar.c" /* yacc.c:1646  */
    break;

  case 162:
#line 387 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3740 "grammar.c" /* yacc.c:1646  */
    break;

  case 163:
#line 388 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3746 "grammar.c" /* yacc.c:1646  */
    break;

  case 164:
#line 389 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xA4); }
#line 3752 "grammar.c" /* yacc.c:1646  */
    break;

  case 165:
#line 390 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xA5); }
#line 3758 "grammar.c" /* yacc.c:1646  */
    break;

  case 166:
#line 391 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xA4); }
#line 3764 "grammar.c" /* yacc.c:1646  */
    break;

  case 167:
#line 392 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xA5); }
#line 3770 "grammar.c" /* yacc.c:1646  */
    break;

  case 168:
#line 394 "grammar.y" /* yacc.c:1646  */
    { if ((yyvsp[-4].normal) > 7) { warningError("Bit number is bigger out of range, truncating"); } outCode(2,0xCB,(((yyvsp[-4].normal)<<3)|64|6)); }
#line 3776 "grammar.c" /* yacc.c:1646  */
    break;

  case 169:
#line 395 "grammar.y" /* yacc.c:1646  */
    { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xDD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3782 "grammar.c" /* yacc.c:1646  */
    break;

  case 170:
#line 396 "grammar.y" /* yacc.c:1646  */
    { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xFD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3788 "grammar.c" /* yacc.c:1646  */
    break;

  case 171:
#line 397 "grammar.y" /* yacc.c:1646  */
    { 	if ((yyvsp[-2].normal)>7) { warningError("Bit number is bigger out of range, truncating"); }
                                            outCode(2,0xCB,(((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|64));
                                        }
#line 3796 "grammar.c" /* yacc.c:1646  */
    break;

  case 172:
#line 402 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xCD,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3802 "grammar.c" /* yacc.c:1646  */
    break;

  case 173:
#line 403 "grammar.y" /* yacc.c:1646  */
    { outCode(3, (((yyvsp[-2].byte)<<3)|128|64|4),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3808 "grammar.c" /* yacc.c:1646  */
    break;

  case 174:
#line 405 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFE,(yyvsp[0].normal)); }
#line 3814 "grammar.c" /* yacc.c:1646  */
    break;

  case 175:
#line 406 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|32|16|8); outCode(1,k); }
#line 3820 "grammar.c" /* yacc.c:1646  */
    break;

  case 176:
#line 407 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xBE); }
#line 3826 "grammar.c" /* yacc.c:1646  */
    break;

  case 177:
#line 408 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xBE,(yyvsp[-1].normal)); }
#line 3832 "grammar.c" /* yacc.c:1646  */
    break;

  case 178:
#line 409 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xBE,(yyvsp[-1].normal)); }
#line 3838 "grammar.c" /* yacc.c:1646  */
    break;

  case 179:
#line 410 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xBE,0); }
#line 3844 "grammar.c" /* yacc.c:1646  */
    break;

  case 180:
#line 411 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xBE,0); }
#line 3850 "grammar.c" /* yacc.c:1646  */
    break;

  case 181:
#line 412 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0xBC); }
#line 3856 "grammar.c" /* yacc.c:1646  */
    break;

  case 182:
#line 413 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0xBD); }
#line 3862 "grammar.c" /* yacc.c:1646  */
    break;

  case 183:
#line 414 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0xBC); }
#line 3868 "grammar.c" /* yacc.c:1646  */
    break;

  case 184:
#line 415 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0xBD); }
#line 3874 "grammar.c" /* yacc.c:1646  */
    break;

  case 185:
#line 417 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte)<<3)|4|1); outCode(1,k); }
#line 3880 "grammar.c" /* yacc.c:1646  */
    break;

  case 186:
#line 418 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x35); }
#line 3886 "grammar.c" /* yacc.c:1646  */
    break;

  case 187:
#line 419 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x35,(yyvsp[-1].normal)); }
#line 3892 "grammar.c" /* yacc.c:1646  */
    break;

  case 188:
#line 420 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x35,(yyvsp[-1].normal)); }
#line 3898 "grammar.c" /* yacc.c:1646  */
    break;

  case 189:
#line 421 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x35,0); }
#line 3904 "grammar.c" /* yacc.c:1646  */
    break;

  case 190:
#line 422 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x35,0); }
#line 3910 "grammar.c" /* yacc.c:1646  */
    break;

  case 191:
#line 423 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte)<<4)|8|2|1); outCode(1,k); }
#line 3916 "grammar.c" /* yacc.c:1646  */
    break;

  case 192:
#line 424 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x2B); }
#line 3922 "grammar.c" /* yacc.c:1646  */
    break;

  case 193:
#line 425 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x2B); }
#line 3928 "grammar.c" /* yacc.c:1646  */
    break;

  case 194:
#line 426 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xDD,0x25); }
#line 3934 "grammar.c" /* yacc.c:1646  */
    break;

  case 195:
#line 427 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xDD,0x2D); }
#line 3940 "grammar.c" /* yacc.c:1646  */
    break;

  case 196:
#line 428 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xFD,0x25); }
#line 3946 "grammar.c" /* yacc.c:1646  */
    break;

  case 197:
#line 429 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xFD,0x2C); }
#line 3952 "grammar.c" /* yacc.c:1646  */
    break;

  case 198:
#line 432 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0x10,((yyvsp[0].normal) - pc - 2) ); }
#line 3958 "grammar.c" /* yacc.c:1646  */
    break;

  case 199:
#line 435 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x08); }
#line 3964 "grammar.c" /* yacc.c:1646  */
    break;

  case 200:
#line 436 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xEB); }
#line 3970 "grammar.c" /* yacc.c:1646  */
    break;

  case 201:
#line 437 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xE3); }
#line 3976 "grammar.c" /* yacc.c:1646  */
    break;

  case 202:
#line 438 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xE3); }
#line 3982 "grammar.c" /* yacc.c:1646  */
    break;

  case 203:
#line 439 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xE3); }
#line 3988 "grammar.c" /* yacc.c:1646  */
    break;

  case 204:
#line 441 "grammar.y" /* yacc.c:1646  */
    { switch((yyvsp[0].normal)) {
                                case 0: outCode(2,0xED,0x46); break;
                                case 1: outCode(2,0xED,0x56); break;
                                case 2: outCode(2,0xED,0x5E); break;
                                default: fatalError("Interruption mode value is out of range: Only allowed 0, 1 or 2"); break;
                               }
                             }
#line 4000 "grammar.c" /* yacc.c:1646  */
    break;

  case 205:
#line 449 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,(((yyvsp[-4].byte)<<3)|64)); }
#line 4006 "grammar.c" /* yacc.c:1646  */
    break;

  case 206:
#line 450 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDB,(yyvsp[0].normal)); if ((yyvsp[-2].byte) != 7) { fatalError("IN only can use the A Register, sorry"); } }
#line 4012 "grammar.c" /* yacc.c:1646  */
    break;

  case 207:
#line 452 "grammar.y" /* yacc.c:1646  */
    { outCode(1,((yyvsp[0].byte)<<3)|4); }
#line 4018 "grammar.c" /* yacc.c:1646  */
    break;

  case 208:
#line 453 "grammar.y" /* yacc.c:1646  */
    { outCode(1,(((yyvsp[0].byte)<<4)|1|2));  }
#line 4024 "grammar.c" /* yacc.c:1646  */
    break;

  case 209:
#line 454 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x34); }
#line 4030 "grammar.c" /* yacc.c:1646  */
    break;

  case 210:
#line 455 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x34,(yyvsp[-1].normal)); }
#line 4036 "grammar.c" /* yacc.c:1646  */
    break;

  case 211:
#line 456 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x34,(yyvsp[-1].normal)); }
#line 4042 "grammar.c" /* yacc.c:1646  */
    break;

  case 212:
#line 457 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x34,0); }
#line 4048 "grammar.c" /* yacc.c:1646  */
    break;

  case 213:
#line 458 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x34,0); }
#line 4054 "grammar.c" /* yacc.c:1646  */
    break;

  case 214:
#line 459 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xDD,0x23); }
#line 4060 "grammar.c" /* yacc.c:1646  */
    break;

  case 215:
#line 460 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xFD,0x23); }
#line 4066 "grammar.c" /* yacc.c:1646  */
    break;

  case 216:
#line 461 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xDD,0x24); }
#line 4072 "grammar.c" /* yacc.c:1646  */
    break;

  case 217:
#line 462 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xDD,0x2C); }
#line 4078 "grammar.c" /* yacc.c:1646  */
    break;

  case 218:
#line 463 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xFD,0x24); }
#line 4084 "grammar.c" /* yacc.c:1646  */
    break;

  case 219:
#line 464 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xFD,0x2C); }
#line 4090 "grammar.c" /* yacc.c:1646  */
    break;

  case 220:
#line 466 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xC3,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4096 "grammar.c" /* yacc.c:1646  */
    break;

  case 221:
#line 467 "grammar.y" /* yacc.c:1646  */
    { outCode(3,(((yyvsp[-2].byte)<<3)|128|64|2),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4102 "grammar.c" /* yacc.c:1646  */
    break;

  case 222:
#line 468 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xE9); }
#line 4108 "grammar.c" /* yacc.c:1646  */
    break;

  case 223:
#line 469 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xE9); }
#line 4114 "grammar.c" /* yacc.c:1646  */
    break;

  case 224:
#line 470 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xE9); }
#line 4120 "grammar.c" /* yacc.c:1646  */
    break;

  case 225:
#line 472 "grammar.y" /* yacc.c:1646  */
    { outCode(2,((yyvsp[-2].byte)<<3)|32,((yyvsp[0].normal) - pc - 2)); }
#line 4126 "grammar.c" /* yacc.c:1646  */
    break;

  case 226:
#line 473 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0x18, ((yyvsp[0].normal) - pc - 2) ); }
#line 4132 "grammar.c" /* yacc.c:1646  */
    break;

  case 227:
#line 474 "grammar.y" /* yacc.c:1646  */
    { fatalError("You cannot use M flag bit in JR instruction"); }
#line 4138 "grammar.c" /* yacc.c:1646  */
    break;

  case 228:
#line 475 "grammar.y" /* yacc.c:1646  */
    { fatalError("You cannot use P flag bit in JR instruction"); }
#line 4144 "grammar.c" /* yacc.c:1646  */
    break;

  case 229:
#line 476 "grammar.y" /* yacc.c:1646  */
    { fatalError("You cannot use PE flag bit in JR instruction"); }
#line 4150 "grammar.c" /* yacc.c:1646  */
    break;

  case 230:
#line 477 "grammar.y" /* yacc.c:1646  */
    { fatalError("You cannot use PO flag bit in JR instruction"); }
#line 4156 "grammar.c" /* yacc.c:1646  */
    break;

  case 231:
#line 480 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[-2].byte) << 3)|64); k = k | (yyvsp[0].byte); outCode(1,k); }
#line 4162 "grammar.c" /* yacc.c:1646  */
    break;

  case 232:
#line 481 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0x3A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");} }
#line 4168 "grammar.c" /* yacc.c:1646  */
    break;

  case 233:
#line 482 "grammar.y" /* yacc.c:1646  */
    { outCode(2,(((yyvsp[-2].byte) << 3)|6),(yyvsp[0].normal)); }
#line 4174 "grammar.c" /* yacc.c:1646  */
    break;

  case 234:
#line 483 "grammar.y" /* yacc.c:1646  */
    { outCode(3,(yyvsp[-3].normal),((yyvsp[-6].byte)<<3)|64|4|2,(yyvsp[-1].normal)); }
#line 4180 "grammar.c" /* yacc.c:1646  */
    break;

  case 235:
#line 484 "grammar.y" /* yacc.c:1646  */
    { outCode(1,((yyvsp[-4].byte)<<3)|64|4|2); }
#line 4186 "grammar.c" /* yacc.c:1646  */
    break;

  case 236:
#line 485 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x02); }
#line 4192 "grammar.c" /* yacc.c:1646  */
    break;

  case 237:
#line 486 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x12); }
#line 4198 "grammar.c" /* yacc.c:1646  */
    break;

  case 238:
#line 487 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0x36,(yyvsp[0].normal)); }
#line 4204 "grammar.c" /* yacc.c:1646  */
    break;

  case 239:
#line 488 "grammar.y" /* yacc.c:1646  */
    { outCode(1,(yyvsp[0].byte)|64|32|16); }
#line 4210 "grammar.c" /* yacc.c:1646  */
    break;

  case 240:
#line 489 "grammar.y" /* yacc.c:1646  */
    { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),(yyvsp[0].normal)); }
#line 4216 "grammar.c" /* yacc.c:1646  */
    break;

  case 241:
#line 490 "grammar.y" /* yacc.c:1646  */
    { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),(yyvsp[-3].normal)); }
#line 4222 "grammar.c" /* yacc.c:1646  */
    break;

  case 242:
#line 491 "grammar.y" /* yacc.c:1646  */
    { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),-(yyvsp[0].normal)); }
#line 4228 "grammar.c" /* yacc.c:1646  */
    break;

  case 243:
#line 492 "grammar.y" /* yacc.c:1646  */
    { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),-(yyvsp[-3].normal)); }
#line 4234 "grammar.c" /* yacc.c:1646  */
    break;

  case 244:
#line 493 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0x32,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4240 "grammar.c" /* yacc.c:1646  */
    break;

  case 245:
#line 494 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xED,43,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4246 "grammar.c" /* yacc.c:1646  */
    break;

  case 246:
#line 495 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xED,53,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4252 "grammar.c" /* yacc.c:1646  */
    break;

  case 247:
#line 496 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xED,73,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4258 "grammar.c" /* yacc.c:1646  */
    break;

  case 248:
#line 497 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4264 "grammar.c" /* yacc.c:1646  */
    break;

  case 249:
#line 498 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4270 "grammar.c" /* yacc.c:1646  */
    break;

  case 250:
#line 499 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4276 "grammar.c" /* yacc.c:1646  */
    break;

  case 251:
#line 500 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x0A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4282 "grammar.c" /* yacc.c:1646  */
    break;

  case 252:
#line 501 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x1A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4288 "grammar.c" /* yacc.c:1646  */
    break;

  case 253:
#line 502 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x57); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4294 "grammar.c" /* yacc.c:1646  */
    break;

  case 254:
#line 503 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x47); }
#line 4300 "grammar.c" /* yacc.c:1646  */
    break;

  case 255:
#line 504 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x5F); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4306 "grammar.c" /* yacc.c:1646  */
    break;

  case 256:
#line 505 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,0x4F); }
#line 4312 "grammar.c" /* yacc.c:1646  */
    break;

  case 257:
#line 506 "grammar.y" /* yacc.c:1646  */
    { outCode(4,(yyvsp[-4].normal),0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
#line 4318 "grammar.c" /* yacc.c:1646  */
    break;

  case 258:
#line 507 "grammar.y" /* yacc.c:1646  */
    { outCode(4,(yyvsp[-2].normal),0x21,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4324 "grammar.c" /* yacc.c:1646  */
    break;

  case 259:
#line 508 "grammar.y" /* yacc.c:1646  */
    { 
																		if ((yyvsp[-4].byte) != 2) { outCode(4,0xED,0x4B,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																		else            { outCode(3,0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																	}
#line 4333 "grammar.c" /* yacc.c:1646  */
    break;

  case 260:
#line 512 "grammar.y" /* yacc.c:1646  */
    { outCode(3,((yyvsp[-2].byte)<<4)|1,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4339 "grammar.c" /* yacc.c:1646  */
    break;

  case 261:
#line 514 "grammar.y" /* yacc.c:1646  */
    { 
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else { outCode(1,0xF9);  }
																	}
#line 4348 "grammar.c" /* yacc.c:1646  */
    break;

  case 262:
#line 518 "grammar.y" /* yacc.c:1646  */
    {
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else  { outCode(2,(yyvsp[0].normal),0xF9); }
																	}
#line 4357 "grammar.c" /* yacc.c:1646  */
    break;

  case 263:
#line 522 "grammar.y" /* yacc.c:1646  */
    { 
		                                                                switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																			case 7: outCode(2,0xDD,(5<<3)|64|(yyvsp[0].byte)); break;
																			default: outCode(2,0xDD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	    }
																	}
#line 4368 "grammar.c" /* yacc.c:1646  */
    break;

  case 264:
#line 528 "grammar.y" /* yacc.c:1646  */
    { switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																		case 7: outCode(2,0xFD,(5<<3)|64|(yyvsp[0].byte)); break;
																		default: outCode(2,0xFD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	  }
																	}
#line 4378 "grammar.c" /* yacc.c:1646  */
    break;

  case 265:
#line 533 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x60); }
#line 4384 "grammar.c" /* yacc.c:1646  */
    break;

  case 266:
#line 534 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x61); }
#line 4390 "grammar.c" /* yacc.c:1646  */
    break;

  case 267:
#line 535 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x62); }
#line 4396 "grammar.c" /* yacc.c:1646  */
    break;

  case 268:
#line 536 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x63); }
#line 4402 "grammar.c" /* yacc.c:1646  */
    break;

  case 269:
#line 537 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x64); }
#line 4408 "grammar.c" /* yacc.c:1646  */
    break;

  case 270:
#line 538 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x65); }
#line 4414 "grammar.c" /* yacc.c:1646  */
    break;

  case 271:
#line 539 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x67); }
#line 4420 "grammar.c" /* yacc.c:1646  */
    break;

  case 272:
#line 540 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x68); }
#line 4426 "grammar.c" /* yacc.c:1646  */
    break;

  case 273:
#line 541 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x69); }
#line 4432 "grammar.c" /* yacc.c:1646  */
    break;

  case 274:
#line 542 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x6A); }
#line 4438 "grammar.c" /* yacc.c:1646  */
    break;

  case 275:
#line 543 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x6B); }
#line 4444 "grammar.c" /* yacc.c:1646  */
    break;

  case 276:
#line 544 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x6C); }
#line 4450 "grammar.c" /* yacc.c:1646  */
    break;

  case 277:
#line 545 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x6D); }
#line 4456 "grammar.c" /* yacc.c:1646  */
    break;

  case 278:
#line 546 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x6F); }
#line 4462 "grammar.c" /* yacc.c:1646  */
    break;

  case 279:
#line 547 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x60); }
#line 4468 "grammar.c" /* yacc.c:1646  */
    break;

  case 280:
#line 548 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x61); }
#line 4474 "grammar.c" /* yacc.c:1646  */
    break;

  case 281:
#line 549 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x62); }
#line 4480 "grammar.c" /* yacc.c:1646  */
    break;

  case 282:
#line 550 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x63); }
#line 4486 "grammar.c" /* yacc.c:1646  */
    break;

  case 283:
#line 551 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x64); }
#line 4492 "grammar.c" /* yacc.c:1646  */
    break;

  case 284:
#line 552 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x65); }
#line 4498 "grammar.c" /* yacc.c:1646  */
    break;

  case 285:
#line 553 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x67); }
#line 4504 "grammar.c" /* yacc.c:1646  */
    break;

  case 286:
#line 554 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x68); }
#line 4510 "grammar.c" /* yacc.c:1646  */
    break;

  case 287:
#line 555 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x69); }
#line 4516 "grammar.c" /* yacc.c:1646  */
    break;

  case 288:
#line 556 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x6A); }
#line 4522 "grammar.c" /* yacc.c:1646  */
    break;

  case 289:
#line 557 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x6B); }
#line 4528 "grammar.c" /* yacc.c:1646  */
    break;

  case 290:
#line 558 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x6C); }
#line 4534 "grammar.c" /* yacc.c:1646  */
    break;

  case 291:
#line 559 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x6D); }
#line 4540 "grammar.c" /* yacc.c:1646  */
    break;

  case 292:
#line 560 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x6F); }
#line 4546 "grammar.c" /* yacc.c:1646  */
    break;

  case 293:
#line 561 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x2E,(yyvsp[0].normal)); }
#line 4552 "grammar.c" /* yacc.c:1646  */
    break;

  case 294:
#line 562 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x2E,(yyvsp[0].normal)); }
#line 4558 "grammar.c" /* yacc.c:1646  */
    break;

  case 295:
#line 563 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0x26,(yyvsp[0].normal)); }
#line 4564 "grammar.c" /* yacc.c:1646  */
    break;

  case 296:
#line 564 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0x26,(yyvsp[0].normal)); }
#line 4570 "grammar.c" /* yacc.c:1646  */
    break;

  case 297:
#line 565 "grammar.y" /* yacc.c:1646  */
    { fatalError("Sorry, LD option into F register is not allowed in the Z80"); }
#line 4576 "grammar.c" /* yacc.c:1646  */
    break;

  case 298:
#line 566 "grammar.y" /* yacc.c:1646  */
    { fatalError("Sorry, LD option into AF register is not allowed in the Z80"); }
#line 4582 "grammar.c" /* yacc.c:1646  */
    break;

  case 299:
#line 569 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4588 "grammar.c" /* yacc.c:1646  */
    break;

  case 300:
#line 570 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4594 "grammar.c" /* yacc.c:1646  */
    break;

  case 301:
#line 571 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xB6); }
#line 4600 "grammar.c" /* yacc.c:1646  */
    break;

  case 302:
#line 572 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4606 "grammar.c" /* yacc.c:1646  */
    break;

  case 303:
#line 573 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4612 "grammar.c" /* yacc.c:1646  */
    break;

  case 304:
#line 574 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xB4); }
#line 4618 "grammar.c" /* yacc.c:1646  */
    break;

  case 305:
#line 575 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xB5); }
#line 4624 "grammar.c" /* yacc.c:1646  */
    break;

  case 306:
#line 576 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xB4); }
#line 4630 "grammar.c" /* yacc.c:1646  */
    break;

  case 307:
#line 577 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xB5); }
#line 4636 "grammar.c" /* yacc.c:1646  */
    break;

  case 308:
#line 578 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4642 "grammar.c" /* yacc.c:1646  */
    break;

  case 309:
#line 579 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4648 "grammar.c" /* yacc.c:1646  */
    break;

  case 310:
#line 580 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xB6); }
#line 4654 "grammar.c" /* yacc.c:1646  */
    break;

  case 311:
#line 581 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4660 "grammar.c" /* yacc.c:1646  */
    break;

  case 312:
#line 582 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4666 "grammar.c" /* yacc.c:1646  */
    break;

  case 313:
#line 583 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xB4); }
#line 4672 "grammar.c" /* yacc.c:1646  */
    break;

  case 314:
#line 584 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xB5); }
#line 4678 "grammar.c" /* yacc.c:1646  */
    break;

  case 315:
#line 585 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xB4); }
#line 4684 "grammar.c" /* yacc.c:1646  */
    break;

  case 316:
#line 586 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xB5); }
#line 4690 "grammar.c" /* yacc.c:1646  */
    break;

  case 317:
#line 589 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xD3,(yyvsp[-3].normal)); }
#line 4696 "grammar.c" /* yacc.c:1646  */
    break;

  case 318:
#line 590 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,((yyvsp[0].byte)<<3)|1|64); }
#line 4702 "grammar.c" /* yacc.c:1646  */
    break;

  case 319:
#line 592 "grammar.y" /* yacc.c:1646  */
    { outCode(1,((yyvsp[0].byte)<<4)|1|128|64); }
#line 4708 "grammar.c" /* yacc.c:1646  */
    break;

  case 320:
#line 593 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xE1); }
#line 4714 "grammar.c" /* yacc.c:1646  */
    break;

  case 321:
#line 594 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xE1); }
#line 4720 "grammar.c" /* yacc.c:1646  */
    break;

  case 322:
#line 596 "grammar.y" /* yacc.c:1646  */
    { outCode(1,((yyvsp[0].byte)<<4)|1|4|64|128); }
#line 4726 "grammar.c" /* yacc.c:1646  */
    break;

  case 323:
#line 597 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xE5); }
#line 4732 "grammar.c" /* yacc.c:1646  */
    break;

  case 324:
#line 598 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xE5); }
#line 4738 "grammar.c" /* yacc.c:1646  */
    break;

  case 325:
#line 601 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128); }
#line 4744 "grammar.c" /* yacc.c:1646  */
    break;

  case 326:
#line 602 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|4|2); }
#line 4750 "grammar.c" /* yacc.c:1646  */
    break;

  case 327:
#line 603 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4756 "grammar.c" /* yacc.c:1646  */
    break;

  case 328:
#line 604 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4762 "grammar.c" /* yacc.c:1646  */
    break;

  case 329:
#line 607 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xC9); }
#line 4768 "grammar.c" /* yacc.c:1646  */
    break;

  case 330:
#line 608 "grammar.y" /* yacc.c:1646  */
    { outCode(1,((yyvsp[0].byte)<<3)|128|64); }
#line 4774 "grammar.c" /* yacc.c:1646  */
    break;

  case 331:
#line 611 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[0].byte))|16); }
#line 4780 "grammar.c" /* yacc.c:1646  */
    break;

  case 332:
#line 612 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,16); }
#line 4786 "grammar.c" /* yacc.c:1646  */
    break;

  case 333:
#line 613 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4792 "grammar.c" /* yacc.c:1646  */
    break;

  case 334:
#line 614 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4798 "grammar.c" /* yacc.c:1646  */
    break;

  case 335:
#line 616 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,  (yyvsp[0].byte)); }
#line 4804 "grammar.c" /* yacc.c:1646  */
    break;

  case 336:
#line 617 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,0x06); }
#line 4810 "grammar.c" /* yacc.c:1646  */
    break;

  case 337:
#line 618 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4816 "grammar.c" /* yacc.c:1646  */
    break;

  case 338:
#line 619 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4822 "grammar.c" /* yacc.c:1646  */
    break;

  case 339:
#line 621 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,(yyvsp[0].byte)|8|16); }
#line 4828 "grammar.c" /* yacc.c:1646  */
    break;

  case 340:
#line 622 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,0x1E);     }
#line 4834 "grammar.c" /* yacc.c:1646  */
    break;

  case 341:
#line 623 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4840 "grammar.c" /* yacc.c:1646  */
    break;

  case 342:
#line 624 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4846 "grammar.c" /* yacc.c:1646  */
    break;

  case 343:
#line 626 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,(yyvsp[0].byte)|8); }
#line 4852 "grammar.c" /* yacc.c:1646  */
    break;

  case 344:
#line 627 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,0x0E); }
#line 4858 "grammar.c" /* yacc.c:1646  */
    break;

  case 345:
#line 628 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4864 "grammar.c" /* yacc.c:1646  */
    break;

  case 346:
#line 629 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4870 "grammar.c" /* yacc.c:1646  */
    break;

  case 347:
#line 631 "grammar.y" /* yacc.c:1646  */
    { switch ((yyvsp[0].normal)) {
                                case 0x0: case 0x8:
                                case 0x10: case 0x18:
                                case 0x20: case 0x28:
                                case 0x30: case 0x38: outCode(1,((yyvsp[0].normal)<<3)|128|64|4|2|1); break;
                                default: fatalError("Wrong vector provided for RST"); break;
                               }
                             }
#line 4883 "grammar.c" /* yacc.c:1646  */
    break;

  case 348:
#line 640 "grammar.y" /* yacc.c:1646  */
    { outCode(1,(yyvsp[0].byte)|8|16|128); }
#line 4889 "grammar.c" /* yacc.c:1646  */
    break;

  case 349:
#line 641 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDE,(yyvsp[0].normal)); }
#line 4895 "grammar.c" /* yacc.c:1646  */
    break;

  case 350:
#line 642 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x9E); }
#line 4901 "grammar.c" /* yacc.c:1646  */
    break;

  case 351:
#line 643 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x9E,(yyvsp[-1].normal)); }
#line 4907 "grammar.c" /* yacc.c:1646  */
    break;

  case 352:
#line 644 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x9E,(yyvsp[-1].normal)); }
#line 4913 "grammar.c" /* yacc.c:1646  */
    break;

  case 353:
#line 645 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xED,((yyvsp[0].byte)<<4)|2|64); }
#line 4919 "grammar.c" /* yacc.c:1646  */
    break;

  case 354:
#line 646 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x9C); }
#line 4925 "grammar.c" /* yacc.c:1646  */
    break;

  case 355:
#line 647 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x9D); }
#line 4931 "grammar.c" /* yacc.c:1646  */
    break;

  case 356:
#line 648 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x9C); }
#line 4937 "grammar.c" /* yacc.c:1646  */
    break;

  case 357:
#line 649 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x9D); }
#line 4943 "grammar.c" /* yacc.c:1646  */
    break;

  case 358:
#line 651 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128|64); }
#line 4949 "grammar.c" /* yacc.c:1646  */
    break;

  case 359:
#line 652 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|64|4|2); }
#line 4955 "grammar.c" /* yacc.c:1646  */
    break;

  case 360:
#line 653 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4961 "grammar.c" /* yacc.c:1646  */
    break;

  case 361:
#line 654 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4967 "grammar.c" /* yacc.c:1646  */
    break;

  case 362:
#line 657 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[0].byte))|32); }
#line 4973 "grammar.c" /* yacc.c:1646  */
    break;

  case 363:
#line 658 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,26); }
#line 4979 "grammar.c" /* yacc.c:1646  */
    break;

  case 364:
#line 659 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 4985 "grammar.c" /* yacc.c:1646  */
    break;

  case 365:
#line 660 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 4991 "grammar.c" /* yacc.c:1646  */
    break;

  case 366:
#line 662 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[0].byte))|32|16); }
#line 4997 "grammar.c" /* yacc.c:1646  */
    break;

  case 367:
#line 663 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,36); }
#line 5003 "grammar.c" /* yacc.c:1646  */
    break;

  case 368:
#line 664 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 5009 "grammar.c" /* yacc.c:1646  */
    break;

  case 369:
#line 665 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 5015 "grammar.c" /* yacc.c:1646  */
    break;

  case 370:
#line 667 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[0].byte))|32|8); }
#line 5021 "grammar.c" /* yacc.c:1646  */
    break;

  case 371:
#line 668 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,0x2E); }
#line 5027 "grammar.c" /* yacc.c:1646  */
    break;

  case 372:
#line 669 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 5033 "grammar.c" /* yacc.c:1646  */
    break;

  case 373:
#line 670 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 5039 "grammar.c" /* yacc.c:1646  */
    break;

  case 374:
#line 672 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,((yyvsp[0].byte))|32|16|8); }
#line 5045 "grammar.c" /* yacc.c:1646  */
    break;

  case 375:
#line 673 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xCB,0x3E); }
#line 5051 "grammar.c" /* yacc.c:1646  */
    break;

  case 376:
#line 674 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 5057 "grammar.c" /* yacc.c:1646  */
    break;

  case 377:
#line 675 "grammar.y" /* yacc.c:1646  */
    { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 5063 "grammar.c" /* yacc.c:1646  */
    break;

  case 378:
#line 677 "grammar.y" /* yacc.c:1646  */
    { outCode(1,(yyvsp[0].byte)|16|128); }
#line 5069 "grammar.c" /* yacc.c:1646  */
    break;

  case 379:
#line 678 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xD6,(yyvsp[0].normal)); }
#line 5075 "grammar.c" /* yacc.c:1646  */
    break;

  case 380:
#line 679 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0x96); }
#line 5081 "grammar.c" /* yacc.c:1646  */
    break;

  case 381:
#line 680 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0x96,(yyvsp[-1].normal)); }
#line 5087 "grammar.c" /* yacc.c:1646  */
    break;

  case 382:
#line 681 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0x96,(yyvsp[-1].normal)); }
#line 5093 "grammar.c" /* yacc.c:1646  */
    break;

  case 383:
#line 682 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x94); }
#line 5099 "grammar.c" /* yacc.c:1646  */
    break;

  case 384:
#line 683 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xDD,0x95); }
#line 5105 "grammar.c" /* yacc.c:1646  */
    break;

  case 385:
#line 684 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x94); }
#line 5111 "grammar.c" /* yacc.c:1646  */
    break;

  case 386:
#line 685 "grammar.y" /* yacc.c:1646  */
    {  outCode(2,0xFD,0x95); }
#line 5117 "grammar.c" /* yacc.c:1646  */
    break;

  case 387:
#line 688 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5123 "grammar.c" /* yacc.c:1646  */
    break;

  case 388:
#line 689 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5129 "grammar.c" /* yacc.c:1646  */
    break;

  case 389:
#line 690 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xAE); }
#line 5135 "grammar.c" /* yacc.c:1646  */
    break;

  case 390:
#line 691 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5141 "grammar.c" /* yacc.c:1646  */
    break;

  case 391:
#line 692 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5147 "grammar.c" /* yacc.c:1646  */
    break;

  case 392:
#line 693 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xAC); }
#line 5153 "grammar.c" /* yacc.c:1646  */
    break;

  case 393:
#line 694 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xAD); }
#line 5159 "grammar.c" /* yacc.c:1646  */
    break;

  case 394:
#line 695 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xAC); }
#line 5165 "grammar.c" /* yacc.c:1646  */
    break;

  case 395:
#line 696 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xAD); }
#line 5171 "grammar.c" /* yacc.c:1646  */
    break;

  case 396:
#line 697 "grammar.y" /* yacc.c:1646  */
    { k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5177 "grammar.c" /* yacc.c:1646  */
    break;

  case 397:
#line 698 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5183 "grammar.c" /* yacc.c:1646  */
    break;

  case 398:
#line 699 "grammar.y" /* yacc.c:1646  */
    { outCode(1,0xAE); }
#line 5189 "grammar.c" /* yacc.c:1646  */
    break;

  case 399:
#line 700 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5195 "grammar.c" /* yacc.c:1646  */
    break;

  case 400:
#line 701 "grammar.y" /* yacc.c:1646  */
    { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5201 "grammar.c" /* yacc.c:1646  */
    break;

  case 401:
#line 702 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xAC); }
#line 5207 "grammar.c" /* yacc.c:1646  */
    break;

  case 402:
#line 703 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xDD,0xAD); }
#line 5213 "grammar.c" /* yacc.c:1646  */
    break;

  case 403:
#line 704 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xAC); }
#line 5219 "grammar.c" /* yacc.c:1646  */
    break;

  case 404:
#line 705 "grammar.y" /* yacc.c:1646  */
    { outCode(2,0xFD,0xAD); }
#line 5225 "grammar.c" /* yacc.c:1646  */
    break;

  case 405:
#line 708 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)malloc(3*sizeof(uint8_t)); p[0] = 2; p[1] = (yyvsp[0].normal)&0x00FF; p[2] = (yyvsp[0].normal)>>8; (yyval.listexpr) = p;  }
#line 5231 "grammar.c" /* yacc.c:1646  */
    break;

  case 406:
#line 709 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[p[0]+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; }
#line 5237 "grammar.c" /* yacc.c:1646  */
    break;

  case 407:
#line 710 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5243 "grammar.c" /* yacc.c:1646  */
    break;

  case 408:
#line 711 "grammar.y" /* yacc.c:1646  */
    {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5252 "grammar.c" /* yacc.c:1646  */
    break;

  case 409:
#line 718 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)malloc(5*sizeof(uint8_t)); p[0] = 4; p[1] = (yyvsp[0].normal)&0x000000FF; p[2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[3] = ((yyvsp[0].normal)&0x00FF0000)>>16; p[4] = ((yyvsp[0].normal)&0xFF000000)>>24; (yyval.listexpr) = p;  }
#line 5258 "grammar.c" /* yacc.c:1646  */
    break;

  case 410:
#line 719 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+4)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&&0x000000FF; p[p[0]+2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[p[0]+4] = ((yyvsp[0].normal)&0x00FF0000)>>18; p[p[0]+4] = ((yyvsp[0].normal)&0xFF000000)>>24; p[0] = p[0] + 4; (yyval.listexpr) = p; }
#line 5264 "grammar.c" /* yacc.c:1646  */
    break;

  case 411:
#line 720 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5270 "grammar.c" /* yacc.c:1646  */
    break;

  case 412:
#line 721 "grammar.y" /* yacc.c:1646  */
    {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5279 "grammar.c" /* yacc.c:1646  */
    break;

  case 413:
#line 728 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)malloc(2); p[0] = 1; p[1] = (yyvsp[0].normal); (yyval.listexpr) = p; }
#line 5285 "grammar.c" /* yacc.c:1646  */
    break;

  case 414:
#line 729 "grammar.y" /* yacc.c:1646  */
    { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5291 "grammar.c" /* yacc.c:1646  */
    break;

  case 415:
#line 730 "grammar.y" /* yacc.c:1646  */
    { 
	                                       if (((uint16_t)(yyvsp[0].normal)) > 255) {
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[(*p)+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; 
	                                       }
	                                       else { 
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+1)); p[p[0]+1] = (yyvsp[0].normal); p[0] = p[0] + 1; (yyval.listexpr) = p; 
	                                       }   
	                                     }
#line 5304 "grammar.c" /* yacc.c:1646  */
    break;

  case 416:
#line 738 "grammar.y" /* yacc.c:1646  */
    {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5313 "grammar.c" /* yacc.c:1646  */
    break;

  case 417:
#line 743 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[0].normal);  }
#line 5319 "grammar.c" /* yacc.c:1646  */
    break;

  case 418:
#line 744 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal)=((yyvsp[0].normal)==0)?1:0; }
#line 5325 "grammar.c" /* yacc.c:1646  */
    break;

  case 419:
#line 745 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-1].normal);  }
#line 5331 "grammar.c" /* yacc.c:1646  */
    break;

  case 420:
#line 746 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal)=-(yyvsp[0].normal); }
#line 5337 "grammar.c" /* yacc.c:1646  */
    break;

  case 421:
#line 747 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) + (yyvsp[0].normal); }
#line 5343 "grammar.c" /* yacc.c:1646  */
    break;

  case 422:
#line 748 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) - (yyvsp[0].normal); }
#line 5349 "grammar.c" /* yacc.c:1646  */
    break;

  case 423:
#line 749 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) * (yyvsp[0].normal); }
#line 5355 "grammar.c" /* yacc.c:1646  */
    break;

  case 424:
#line 750 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) / (yyvsp[0].normal); }
#line 5361 "grammar.c" /* yacc.c:1646  */
    break;

  case 425:
#line 751 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) & (yyvsp[0].normal); }
#line 5367 "grammar.c" /* yacc.c:1646  */
    break;

  case 426:
#line 752 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) | (yyvsp[0].normal); }
#line 5373 "grammar.c" /* yacc.c:1646  */
    break;

  case 427:
#line 753 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) << (yyvsp[0].normal); }
#line 5379 "grammar.c" /* yacc.c:1646  */
    break;

  case 428:
#line 754 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[-2].normal) >> (yyvsp[0].normal); }
#line 5385 "grammar.c" /* yacc.c:1646  */
    break;

  case 429:
#line 755 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 0; } else { (yyval.normal) = 1;  } }
#line 5391 "grammar.c" /* yacc.c:1646  */
    break;

  case 430:
#line 756 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5397 "grammar.c" /* yacc.c:1646  */
    break;

  case 431:
#line 757 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) >= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5403 "grammar.c" /* yacc.c:1646  */
    break;

  case 432:
#line 758 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) > (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5409 "grammar.c" /* yacc.c:1646  */
    break;

  case 433:
#line 759 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) <= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5415 "grammar.c" /* yacc.c:1646  */
    break;

  case 434:
#line 760 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) < (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5421 "grammar.c" /* yacc.c:1646  */
    break;

  case 435:
#line 761 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) && (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5427 "grammar.c" /* yacc.c:1646  */
    break;

  case 436:
#line 762 "grammar.y" /* yacc.c:1646  */
    { if ( (yyvsp[-2].normal) || (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5433 "grammar.c" /* yacc.c:1646  */
    break;

  case 437:
#line 764 "grammar.y" /* yacc.c:1646  */
    {  
	                                 if (getLabelValue((yyvsp[0].literal),&k) < 0)   { labelUndefinedError((yyvsp[0].literal)); (yyval.normal)=0; }                                  
	                                 else { (yyval.normal)=k; }
	                                }
#line 5442 "grammar.c" /* yacc.c:1646  */
    break;

  case 438:
#line 768 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[0].normal); }
#line 5448 "grammar.c" /* yacc.c:1646  */
    break;

  case 439:
#line 769 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (yyvsp[0].byte); }
#line 5454 "grammar.c" /* yacc.c:1646  */
    break;

  case 440:
#line 770 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = previouspc; }
#line 5460 "grammar.c" /* yacc.c:1646  */
    break;

  case 441:
#line 771 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = (LookupTableLabels((yyvsp[0].literal))<0)?0:1; }
#line 5466 "grammar.c" /* yacc.c:1646  */
    break;

  case 442:
#line 775 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 7; }
#line 5472 "grammar.c" /* yacc.c:1646  */
    break;

  case 443:
#line 776 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 0; }
#line 5478 "grammar.c" /* yacc.c:1646  */
    break;

  case 444:
#line 777 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 1; }
#line 5484 "grammar.c" /* yacc.c:1646  */
    break;

  case 445:
#line 778 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 2; }
#line 5490 "grammar.c" /* yacc.c:1646  */
    break;

  case 446:
#line 779 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 3; }
#line 5496 "grammar.c" /* yacc.c:1646  */
    break;

  case 447:
#line 780 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 4; }
#line 5502 "grammar.c" /* yacc.c:1646  */
    break;

  case 448:
#line 781 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 5; }
#line 5508 "grammar.c" /* yacc.c:1646  */
    break;

  case 449:
#line 783 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = 0xDD; }
#line 5514 "grammar.c" /* yacc.c:1646  */
    break;

  case 450:
#line 784 "grammar.y" /* yacc.c:1646  */
    { (yyval.normal) = 0xFD; }
#line 5520 "grammar.c" /* yacc.c:1646  */
    break;

  case 451:
#line 786 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 0; }
#line 5526 "grammar.c" /* yacc.c:1646  */
    break;

  case 452:
#line 787 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 1; }
#line 5532 "grammar.c" /* yacc.c:1646  */
    break;

  case 453:
#line 788 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 2; }
#line 5538 "grammar.c" /* yacc.c:1646  */
    break;

  case 454:
#line 789 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 3; }
#line 5544 "grammar.c" /* yacc.c:1646  */
    break;

  case 455:
#line 791 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 0; }
#line 5550 "grammar.c" /* yacc.c:1646  */
    break;

  case 456:
#line 792 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 1; }
#line 5556 "grammar.c" /* yacc.c:1646  */
    break;

  case 457:
#line 793 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 2; }
#line 5562 "grammar.c" /* yacc.c:1646  */
    break;

  case 458:
#line 794 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 3; }
#line 5568 "grammar.c" /* yacc.c:1646  */
    break;

  case 459:
#line 797 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 4; }
#line 5574 "grammar.c" /* yacc.c:1646  */
    break;

  case 460:
#line 798 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 5; }
#line 5580 "grammar.c" /* yacc.c:1646  */
    break;

  case 461:
#line 800 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 4; }
#line 5586 "grammar.c" /* yacc.c:1646  */
    break;

  case 462:
#line 801 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 5; }
#line 5592 "grammar.c" /* yacc.c:1646  */
    break;

  case 463:
#line 803 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 0; }
#line 5598 "grammar.c" /* yacc.c:1646  */
    break;

  case 464:
#line 804 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 1; }
#line 5604 "grammar.c" /* yacc.c:1646  */
    break;

  case 465:
#line 805 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 2; }
#line 5610 "grammar.c" /* yacc.c:1646  */
    break;

  case 466:
#line 806 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 3; }
#line 5616 "grammar.c" /* yacc.c:1646  */
    break;

  case 467:
#line 807 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 4; }
#line 5622 "grammar.c" /* yacc.c:1646  */
    break;

  case 468:
#line 808 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 5; }
#line 5628 "grammar.c" /* yacc.c:1646  */
    break;

  case 469:
#line 809 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 6; }
#line 5634 "grammar.c" /* yacc.c:1646  */
    break;

  case 470:
#line 810 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 7; }
#line 5640 "grammar.c" /* yacc.c:1646  */
    break;

  case 471:
#line 812 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 0; }
#line 5646 "grammar.c" /* yacc.c:1646  */
    break;

  case 472:
#line 813 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 1; }
#line 5652 "grammar.c" /* yacc.c:1646  */
    break;

  case 473:
#line 814 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 2; }
#line 5658 "grammar.c" /* yacc.c:1646  */
    break;

  case 474:
#line 815 "grammar.y" /* yacc.c:1646  */
    { (yyval.byte) = 3; }
#line 5664 "grammar.c" /* yacc.c:1646  */
    break;


#line 5668 "grammar.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
