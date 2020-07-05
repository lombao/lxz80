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
extern void includebinTooBigError(const char * includefile);
void directiveError(const char * msg);


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



#line 135 "grammar.c"

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
    FNAME = 284,
    INCLUDE = 285,
    INCLUDEBIN = 286,
    DEFINED = 287,
    NEWLINE = 288,
    ERROR = 289,
    DOLAR = 290,
    ALIGN = 291,
    COMMA = 292,
    ASEG = 293,
    CHAR = 294,
    LDDR = 295,
    CALL = 296,
    RRCA = 297,
    OTDR = 298,
    OTIR = 299,
    OUTI = 300,
    OUTD = 301,
    RETI = 302,
    RETN = 303,
    PUSH = 304,
    END = 305,
    EQU = 306,
    DEC = 307,
    AND = 308,
    SBC = 309,
    OUT = 310,
    ADC = 311,
    LDD = 312,
    LDI = 313,
    ADD = 314,
    RRA = 315,
    RRC = 316,
    SRA = 317,
    SRL = 318,
    SLL = 319,
    RRD = 320,
    POP = 321,
    CCF = 322,
    RET = 323,
    XOR = 324,
    BIT = 325,
    SCF = 326,
    NOP = 327,
    SET = 328,
    JP = 329,
    DJNZ = 330,
    HALT = 331,
    INDR = 332,
    INIR = 333,
    IND = 334,
    LDIR = 335,
    SLA = 336,
    NEG = 337,
    LD = 338,
    AF = 339,
    HL = 340,
    SP = 341,
    BC = 342,
    DE = 343,
    IX = 344,
    IY = 345,
    IXH = 346,
    IXL = 347,
    IYH = 348,
    IYL = 349,
    OR = 350,
    AFPLUS = 351,
    SUB = 352,
    CP = 353,
    RES = 354,
    CPD = 355,
    CPDR = 356,
    CPI = 357,
    CPIR = 358,
    CPL = 359,
    RLA = 360,
    RLC = 361,
    RLCA = 362,
    DAA = 363,
    RL = 364,
    RLD = 365,
    DI = 366,
    EI = 367,
    EX = 368,
    JR = 369,
    RR = 370,
    EXX = 371,
    RST = 372,
    IM = 373,
    IN = 374,
    INI = 375,
    INC = 376,
    NC = 377,
    NZ = 378,
    PO = 379,
    PE = 380,
    Z = 381,
    P = 382,
    M = 383,
    A = 384,
    B = 385,
    C = 386,
    D = 387,
    E = 388,
    H = 389,
    L = 390,
    R = 391,
    I = 392,
    F = 393,
    STRING = 394,
    LITERAL = 395,
    LABEL = 396,
    INTEGER = 397,
    UMINUS = 398
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
#define FNAME 284
#define INCLUDE 285
#define INCLUDEBIN 286
#define DEFINED 287
#define NEWLINE 288
#define ERROR 289
#define DOLAR 290
#define ALIGN 291
#define COMMA 292
#define ASEG 293
#define CHAR 294
#define LDDR 295
#define CALL 296
#define RRCA 297
#define OTDR 298
#define OTIR 299
#define OUTI 300
#define OUTD 301
#define RETI 302
#define RETN 303
#define PUSH 304
#define END 305
#define EQU 306
#define DEC 307
#define AND 308
#define SBC 309
#define OUT 310
#define ADC 311
#define LDD 312
#define LDI 313
#define ADD 314
#define RRA 315
#define RRC 316
#define SRA 317
#define SRL 318
#define SLL 319
#define RRD 320
#define POP 321
#define CCF 322
#define RET 323
#define XOR 324
#define BIT 325
#define SCF 326
#define NOP 327
#define SET 328
#define JP 329
#define DJNZ 330
#define HALT 331
#define INDR 332
#define INIR 333
#define IND 334
#define LDIR 335
#define SLA 336
#define NEG 337
#define LD 338
#define AF 339
#define HL 340
#define SP 341
#define BC 342
#define DE 343
#define IX 344
#define IY 345
#define IXH 346
#define IXL 347
#define IYH 348
#define IYL 349
#define OR 350
#define AFPLUS 351
#define SUB 352
#define CP 353
#define RES 354
#define CPD 355
#define CPDR 356
#define CPI 357
#define CPIR 358
#define CPL 359
#define RLA 360
#define RLC 361
#define RLCA 362
#define DAA 363
#define RL 364
#define RLD 365
#define DI 366
#define EI 367
#define EX 368
#define JR 369
#define RR 370
#define EXX 371
#define RST 372
#define IM 373
#define IN 374
#define INI 375
#define INC 376
#define NC 377
#define NZ 378
#define PO 379
#define PE 380
#define Z 381
#define P 382
#define M 383
#define A 384
#define B 385
#define C 386
#define D 387
#define E 388
#define H 389
#define L 390
#define R 391
#define I 392
#define F 393
#define STRING 394
#define LITERAL 395
#define LABEL 396
#define INTEGER 397
#define UMINUS 398

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "grammar.y"

  uint32_t normal;
  uint8_t byte;
  uint16_t word;
  uint16_t address;
  uint8_t * listexpr;
  char literal[64];
  

#line 483 "grammar.c"

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
#define YYFINAL  328
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  146
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  470
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  880

#define YYUNDEFTOK  2
#define YYMAXUTOK   400


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
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   206,   206,   208,   209,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   320,   322,   323,   325,
     327,   329,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   365,   366,   367,   368,   369,   370,
     371,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   387,   388,   389,   390,   395,   396,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   425,   428,   429,   430,   431,   432,
     434,   442,   443,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   459,   460,   461,   462,
     463,   465,   466,   467,   468,   469,   470,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   505,   507,   511,   515,
     521,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   582,   583,   585,   586,   587,   589,   590,
     591,   594,   595,   596,   597,   600,   601,   604,   605,   606,
     607,   609,   610,   611,   612,   614,   615,   616,   617,   619,
     620,   621,   622,   624,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   644,   645,   646,   647,   650,   651,
     652,   653,   655,   656,   657,   658,   660,   661,   662,   663,
     665,   666,   667,   668,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   701,   702,   703,   704,   711,   712,   713,   714,   721,
     722,   723,   731,   736,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   755,   757,   761,   762,   763,   764,   768,   769,
     770,   771,   772,   773,   774,   776,   777,   779,   780,   781,
     782,   784,   785,   786,   787,   790,   791,   793,   794,   796,
     797,   798,   799,   800,   801,   802,   803,   805,   806,   807,
     808
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
  "ENDIF", "FNAME", "INCLUDE", "INCLUDEBIN", "DEFINED", "NEWLINE", "ERROR",
  "DOLAR", "ALIGN", "COMMA", "ASEG", "CHAR", "LDDR", "CALL", "RRCA",
  "OTDR", "OTIR", "OUTI", "OUTD", "RETI", "RETN", "PUSH", "END", "EQU",
  "DEC", "AND", "SBC", "OUT", "ADC", "LDD", "LDI", "ADD", "RRA", "RRC",
  "SRA", "SRL", "SLL", "RRD", "POP", "CCF", "RET", "XOR", "BIT", "SCF",
  "NOP", "SET", "JP", "DJNZ", "HALT", "INDR", "INIR", "IND", "LDIR", "SLA",
  "NEG", "LD", "AF", "HL", "SP", "BC", "DE", "IX", "IY", "IXH", "IXL",
  "IYH", "IYL", "OR", "AFPLUS", "SUB", "CP", "RES", "CPD", "CPDR", "CPI",
  "CPIR", "CPL", "RLA", "RLC", "RLCA", "DAA", "RL", "RLD", "DI", "EI",
  "EX", "JR", "RR", "EXX", "RST", "IM", "IN", "INI", "INC", "NC", "NZ",
  "PO", "PE", "Z", "P", "M", "A", "B", "C", "D", "E", "H", "L", "R", "I",
  "F", "STRING", "LITERAL", "LABEL", "INTEGER", "UMINUS", "\"word\"",
  "\"sequence\"", "$accept", "program", "lines", "line", "directive",
  "instruction", "directivedefc", "directivedefs", "directivedefb",
  "directivedefw", "directivedefd", "opcodeadc", "opcodeadd", "opcodeand",
  "opcodebit", "opcodecall", "opcodecp", "opcodedec", "opcodedjnz",
  "opcodeex", "opcodeim", "opcodein", "opcodeinc", "opcodejp", "opcodejr",
  "opcodeld", "opcodeor", "opcodeout", "opcodepop", "opcodepush",
  "opcoderes", "opcoderet", "opcoderl", "opcoderlc", "opcoderr",
  "opcoderrc", "opcoderst", "opcodesbc", "opcodeset", "opcodesla",
  "opcodesll", "opcodesra", "opcodesrl", "opcodesub", "opcodexor",
  "listexprw", "listexprd", "listexpr", "expr", "expritem", "reg8",
  "regixiy", "reg16", "reg16af", "undocregix", "undocregiy", "cc",
  "ccreduced", YY_NULLPTR
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
     395,   396,   397,   398,   399,   400
};
# endif

#define YYPACT_NINF (-245)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-256)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     160,     2,   448,   550,  -127,   570,   448,  -122,  -120,     3,
    -106,    29,    44,  -245,  -100,   448,    24,  -245,    31,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,   295,   448,    17,   545,
     -78,    53,   -73,  -245,  -245,   -60,  -245,   -11,   118,   153,
     161,  -245,   306,  -245,   340,   565,   448,  -245,  -245,   448,
     396,   448,  -245,  -245,  -245,  -245,  -245,   174,  -245,  1838,
     590,   706,  1052,   448,  -245,  -245,  -245,  -245,  -245,  -245,
     485,  -245,  -245,   641,  -245,  -245,  -245,   -13,  1118,   821,
    -245,   448,   448,   198,  -245,  1816,   820,   939,    65,   160,
    -245,    58,    97,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,   448,   448,   448,    -5,  -245,  -245,  -245,  -245,
    -245,   106,  3435,  -245,  1969,  -245,   108,  3435,   137,  -245,
     133,  3435,  2000,   148,   164,  -245,   166,   221,   223,   256,
     266,  -245,  3435,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  3435,   265,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  3435,   -17,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  1558,  -245,  -245,  -245,  -245,   277,  3435,  -245,
     282,   284,  1133,   286,   288,   297,   332,   335,   337,    -7,
    -245,    47,  -245,   319,  -245,   349,  -245,  -245,  -245,  -245,
    -245,  1573,  -245,  -245,  -245,  -245,   338,  3435,  -245,  2026,
    2057,  1589,  3435,   341,  3435,   351,  -245,  1514,   350,  -245,
    -245,   355,   361,   363,   364,   370,   373,   374,   386,   387,
     388,  1614,  -245,  -245,  -245,  -245,   393,  3435,  -245,  1629,
    -245,  -245,  -245,  -245,  3435,  -245,  1648,  -245,  -245,  -245,
    -245,  3435,  -245,  2074,   423,  -245,   425,  -245,   230,   395,
     405,  -245,  -245,   419,   437,  -245,   438,   442,  -245,  3435,
     444,   440,  -245,  3435,  3435,   447,   443,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,   448,  -245,   434,   435,
     353,   458,  -245,   448,  -245,   434,   459,   461,  -245,  -245,
    -245,  -245,  -245,  2120,  -245,  -245,   770,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,  1263,   448,  1278,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,   448,   491,     1,     7,   496,
      11,    27,  1067,    90,  1083,   497,  2147,    90,  1199,    90,
      10,   362,  1215,   506,   523,   526,   515,   529,   533,   524,
     539,   542,   535,   554,   555,   544,   557,   560,  1230,   834,
     895,   553,   558,   561,   448,   563,   585,   586,   575,   576,
     578,  2166,   236,   448,  1360,  1365,  1389,  1410,   376,   472,
     448,   367,  1819,  1685,   601,   598,   602,  1345,   610,   625,
     626,   615,    34,    35,   936,   620,   635,   637,   627,   640,
     642,   629,   564,   568,   448,   448,   448,   448,   448,   643,
     653,   656,  1856,   647,    38,    56,  3435,  -245,  -245,  3435,
    -245,  -245,  -245,  -245,  3435,  2089,  2089,   344,   344,   294,
     294,   294,   294,   454,   454,   103,   103,  -245,  -245,  3454,
    3454,  3435,  -245,  3435,  3435,  -245,  3435,  3435,  -245,   448,
    -245,   448,  -245,  -245,   448,  -245,   448,  -245,  1713,  -245,
    -245,  -245,  -245,  3435,  -245,  -245,  1741,  -245,  -245,  -245,
    -245,  3435,  -245,   631,   632,  -245,  1757,  -245,  -245,  -245,
    -245,  3435,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  1772,  -245,  -245,  -245,  -245,  3435,  -245,  -245,
     448,   448,  -245,   448,   448,  -245,   448,   448,  -245,   448,
     448,  -245,   448,   448,  1778,  -245,  -245,  -245,  -245,  3435,
    -245,   468,  -245,   471,  -245,  -245,  -245,  -245,  3435,  -245,
     448,   448,   634,   636,   649,   651,   448,   448,  3435,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  3435,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  3435,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  3435,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    3435,  -245,  -245,  3435,  1542,  -245,  -245,  -245,  -245,  -245,
    -245,  3435,  -245,  -245,  -245,   448,  3435,   448,  -245,  3435,
    -245,  -245,   448,   448,  1797,  -245,  -245,  -245,  -245,  3435,
    -245,  -245,   448,   448,  -245,   448,  -245,   448,  -245,   518,
    -245,  -245,   448,   448,  -245,   448,   448,   654,  -245,  -245,
    3435,  3435,  3435,  3435,  3435,  -245,   448,   448,  1813,  3435,
    -245,   448,  -245,   448,  -245,  2193,  2212,  2239,  2258,   673,
     693,   694,   683,   696,   698,   198,   579,   691,    59,    93,
     697,   152,   172,  2285,  2304,  2331,  2350,  2377,  2396,  2423,
    2442,  2469,  2488,   709,   708,   710,   711,   718,   725,   714,
     727,   728,  2515,  2534,  1426,   608,   613,     0,  2561,  2580,
     719,   723,   724,  2607,   738,  2626,  2653,  2672,  2699,   729,
     739,   740,  2718,  2745,  2764,  2791,   730,   743,   744,  2810,
    2837,  2856,  2883,   538,  2902,  2929,   735,  2948,  2975,  -245,
    -245,  -245,  -245,  -245,   448,   448,  -245,   448,   448,  -245,
    -245,  -245,   448,  -245,   448,  -245,  -245,   448,  -245,   448,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,   448,   448,  -245,   448,   448,  -245,   448,   448,
    -245,  -245,  3435,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,   677,   721,  -245,  -245,  -245,   726,   448,
     731,   732,  -245,  -245,  -245,   448,   448,  -245,  -245,  -245,
    -245,  -245,   448,   448,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  2994,  3021,  3040,  3067,
    3086,  3113,  3132,  3159,  3178,  3205,  3224,  3251,  3270,  3297,
    1426,  1426,  3316,  3343,  3362,  3389,  3408,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  3435,  -245,  3435,  -245,  -245,  -245,  -245,  -245,  -245
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,    88,     0,   103,
      93,    94,    96,    95,    97,    98,     0,    28,     0,     0,
       0,     0,     0,    87,    89,     0,   102,     0,     0,     0,
       0,   104,     0,    72,   325,     0,     0,   105,    92,     0,
       0,     0,    82,    84,    86,    83,    90,     0,    91,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    99,
       0,   100,    78,     0,   101,    79,    80,     0,     0,     0,
      81,     0,     0,     0,    85,     0,     0,     0,     0,     2,
       3,     0,     0,    33,    31,    30,    32,    34,    40,    41,
      39,    50,    45,    51,    48,    43,    52,    53,    54,    55,
      46,    47,    38,    56,    44,    57,    58,    59,    42,    60,
      61,    62,    63,    64,    65,    66,    67,    70,    68,    69,
      71,    49,     0,     0,     0,     0,   436,   435,   410,   433,
     434,   109,   409,   413,   107,   403,   110,   401,     0,   407,
     111,   405,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    27,    37,    18,   461,   459,   463,   464,   460,   465,
     466,   462,   168,     0,   454,   453,   451,   452,   319,   320,
     318,    29,     0,   449,   450,   447,   448,   188,   189,   190,
     191,   192,   193,   438,   439,   440,   441,   442,   443,   444,
     181,   187,     0,   151,   152,   153,   154,   438,   144,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     339,     0,   366,     0,   370,     0,   362,   316,   317,   315,
     326,     0,   388,   389,   390,   391,   438,   384,   383,     0,
       0,     0,   216,     0,   194,     0,   358,     0,     0,   445,
     446,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   300,   301,   302,   303,   438,   295,   296,     0,
     379,   380,   381,   382,   375,   374,     0,   177,   178,   179,
     180,   170,   171,     0,     0,   331,     0,   327,     0,     0,
       0,   469,   467,     0,     0,   468,     0,     0,   470,   222,
       0,     0,   335,   343,   200,     0,     0,   210,   211,   212,
     213,   214,   215,   203,   204,    10,     0,    25,     0,     0,
       0,     0,     9,     0,    24,    26,     0,     0,     1,     4,
      15,     5,   416,     0,   414,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
      19,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    16,     7,    36,
      17,     6,   415,   412,   411,   417,   418,   419,   420,   428,
     427,   430,   429,   422,   421,   423,   424,   425,   426,   431,
     432,   108,   404,   402,   106,   408,   406,   169,   182,     0,
     185,     0,   186,   146,     0,   149,     0,   150,     0,   160,
     161,   162,   163,   155,   156,   349,     0,   350,   351,   352,
     353,   345,   344,     0,     0,   119,     0,   120,   121,   122,
     123,   112,   113,   131,   135,   132,   133,   134,   139,   136,
     137,   138,     0,   140,   141,   142,   143,   124,   125,   340,
       0,     0,   367,     0,     0,   371,     0,     0,   363,     0,
       0,   385,     0,     0,     0,   397,   398,   399,   400,   393,
     392,     0,   167,     0,   354,   218,   219,   220,   217,   359,
       0,     0,     0,     0,     0,     0,     0,     0,   294,   265,
     266,   267,   261,   262,   263,   264,   292,   272,   273,   274,
     268,   269,   270,   271,   290,   279,   280,   281,   275,   276,
     277,   278,   291,   286,   287,   288,   282,   283,   284,   285,
     289,   252,   250,   293,     0,   455,   456,   457,   458,   251,
     249,   229,   227,   259,   260,     0,   254,     0,   257,   256,
     258,   297,     0,     0,     0,   309,   310,   311,   312,   304,
     305,   376,     0,     0,   172,     0,   175,     0,   176,     0,
     321,   332,     0,     0,   328,     0,     0,     0,   195,   196,
     226,   225,   224,   223,   221,   336,     0,     0,     0,   202,
     205,     0,   208,     0,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,   147,   148,   157,     0,     0,   346,     0,     0,   314,
     313,   114,     0,   117,     0,   118,   126,     0,   129,     0,
     130,   341,   342,   368,   369,   372,   373,   364,   365,   386,
     387,   394,     0,     0,   164,     0,     0,   355,     0,     0,
     360,   361,   234,   235,   232,   233,   244,   243,   241,   242,
     245,   246,   240,     0,     0,   231,   247,   248,   415,     0,
     415,   415,   298,   299,   306,     0,     0,   377,   378,   173,
     174,   322,     0,     0,   333,   334,   329,   330,   197,   198,
     199,   337,   338,   201,   206,   207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   159,   347,
     348,   115,   116,   127,   128,   395,   396,   165,   166,   356,
     357,   236,   237,   238,   239,   230,   307,   308,   323,   324
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,  -245,   671,   211,   279,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,    -1,  -245,
      55,  -244,   -53,   720,  -245,  -245,   -28,  -245
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   146,   150,   141,   333,   143,
     200,   259,   201,   180,   623,   624,   173,   300
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     142,   144,   147,   412,   151,   152,   260,   210,   288,   489,
     219,   132,   213,   148,   162,   491,   230,   172,   153,   494,
     154,   490,   243,   133,   134,   215,   181,   492,   208,   216,
     217,   495,   314,   156,   135,   496,   155,   136,   182,   161,
     132,   137,   645,   647,   237,   239,   671,   497,   240,   242,
     244,   211,   133,   134,   646,   648,   214,   163,   672,   267,
     274,   281,   283,   135,   673,   328,   136,   762,   366,   218,
     137,   289,   367,   368,   212,   290,   674,   299,   383,   763,
     303,   304,   384,   385,   209,   796,   797,   798,   799,   800,
     801,   330,   220,   222,   224,   226,   524,   525,   526,   527,
     238,   764,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   246,   765,   258,   268,   275,   282,   193,   194,
     195,   196,   197,   198,   199,   285,   349,   350,   287,   802,
     331,   332,   386,   334,   302,   335,   387,   388,   305,   221,
     313,   138,   139,   336,   140,   354,   193,   194,   195,   196,
     197,   198,   199,   164,   165,   166,   167,   168,   169,   170,
     767,   355,   171,     1,     2,     3,     4,     5,   157,   158,
     356,   139,   768,   140,   223,   183,   184,   185,   186,   630,
     769,   358,   225,   159,   160,     6,     7,     8,     9,    10,
      11,    12,   770,    13,    14,   245,    15,   359,    16,   360,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   376,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   576,   577,   411,   193,   194,   195,
     196,   197,   198,   199,   361,    60,   362,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   193,   194,   195,   196,   197,   198,   199,   363,
     193,   194,   195,   196,   197,   198,   199,   320,   326,   364,
      86,    87,   365,   193,   194,   195,   196,   197,   198,   199,
     345,   346,   347,   348,   372,   456,   441,   349,   350,   373,
     505,   374,   459,   377,   515,   378,   523,   193,   194,   195,
     196,   197,   198,   199,   379,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   483,   484,   486,   341,   342,   343,   344,
     345,   346,   347,   348,   487,   321,   327,   349,   350,   380,
     724,   503,   381,   511,   382,   398,   132,   521,   404,   174,
     175,   537,   176,   177,   178,   179,   457,   413,   614,   134,
     174,   175,   414,   176,   177,   227,   228,   559,   415,   135,
     416,   417,   136,   568,   389,   132,   137,   418,   390,   391,
     419,   420,   578,   586,   594,   602,   610,   241,   134,   613,
     621,   626,   629,   421,   422,   423,   639,   504,   135,   512,
     427,   136,   442,   522,   392,   137,   405,   538,   393,   394,
     406,   407,   443,   660,   661,   662,   663,   664,   528,   529,
     530,   669,   531,   560,   562,   564,   444,   132,   615,   616,
     617,   618,   164,   165,   166,   167,   168,   169,   170,   133,
     134,   171,   347,   348,   445,   446,   622,   349,   350,   447,
     135,   448,   640,   136,   452,   316,   323,   137,   675,   650,
     676,   458,   460,   677,   461,   678,   193,   194,   195,   196,
     197,   198,   199,   619,   620,   611,   284,   139,   435,   140,
     438,   488,   436,   437,   439,   440,   493,   513,   164,   165,
     166,   167,   168,   169,   170,   449,   539,   171,   453,   450,
     451,   540,   454,   455,   541,   542,   139,   543,   140,   693,
     694,   544,   695,   696,   545,   697,   698,   546,   699,   700,
     547,   701,   702,   706,   132,   548,   709,   707,   708,   132,
     710,   711,   549,   550,   551,   552,   202,   134,   553,   712,
     713,   133,   134,   565,   132,   718,   719,   135,   566,   132,
     136,   567,   135,   569,   137,   136,   231,   134,   139,   137,
     140,   133,   134,   570,   571,   572,   573,   135,   574,   132,
     136,   612,   135,   736,   137,   136,   632,   737,   738,   137,
     633,   261,   134,   723,   193,   194,   195,   196,   197,   198,
     199,   631,   135,   828,   725,   136,   726,   829,   830,   137,
     641,   727,   728,   642,   643,   644,   203,   204,   205,   206,
     651,   732,   733,   652,   734,   653,   735,   654,   655,   657,
     656,   739,   740,   659,   741,   742,   232,   233,   234,   235,
     658,   666,   286,   665,   667,   744,   745,   670,   685,   686,
     747,   714,   748,   715,   207,   194,   195,   196,   197,   198,
     199,   262,   263,   264,   265,   139,   716,   140,   717,   145,
     139,   743,   140,   753,   236,   194,   195,   196,   197,   198,
     199,   754,   755,   756,   757,   139,   758,   140,   760,   149,
     139,   761,   140,   792,   850,   132,   782,   766,   783,   266,
     194,   195,   196,   197,   198,   199,   785,   269,   134,   781,
     139,   784,   140,   786,   787,   788,   789,   794,   135,   805,
     759,   136,   795,   806,   807,   137,   809,   815,   816,   814,
     821,   822,   823,   836,   837,   833,   838,   839,   851,  -228,
     329,   840,   229,   841,  -253,  -255,   842,     0,   843,   793,
     193,   194,   195,   196,   197,   198,   199,     0,     0,   132,
       0,   844,   845,     0,   846,   847,     0,   848,   849,     0,
       0,   133,   134,     0,     0,     0,     0,   270,   271,   272,
     273,     0,   135,     0,     0,   136,     0,     0,   852,   137,
       0,     0,     0,     0,   853,   854,     0,     0,     0,     0,
       0,   855,   856,     1,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   301,     0,     0,     0,   139,     0,   140,   871,
     873,     0,     0,   315,    14,   561,    15,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   316,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,   872,   874,     0,     0,   463,
     139,     0,   140,     0,     0,    60,   563,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     1,     2,     3,     4,     5,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   649,     0,   317,
     318,   319,     0,   193,   194,   195,   196,   197,   198,   199,
       0,     0,   322,    14,     0,    15,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     323,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,   193,   194,   195,   196,   197,   198,
     199,     0,     0,     0,    60,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   132,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,     0,   276,   134,     0,   132,     0,   324,   325,
     319,     0,     0,     0,   135,     0,     0,   136,   498,   134,
       0,   137,   132,     0,     0,     0,     0,     0,     0,   135,
       0,     0,   136,     0,   506,   134,   137,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,     0,   136,     0,
       0,     0,   137,     0,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
     134,     0,   132,   277,   278,   279,   280,     0,     0,     0,
     135,     0,     0,   136,   133,   134,     0,   137,   499,   500,
     501,   502,     0,     0,     0,   135,     0,     0,   136,     0,
       0,     0,   137,     0,   507,   508,   509,   510,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,     0,     0,
       0,     0,   139,     0,   140,     0,   193,   194,   195,   196,
     197,   198,   199,     0,     0,     0,     0,   139,   132,   140,
       0,     0,   193,   194,   195,   196,   197,   198,   199,     0,
     516,   134,     0,   139,   132,   140,     0,     0,     0,     0,
       0,   135,     0,     0,   136,     0,   532,   134,   137,   132,
     291,   292,   293,   294,   295,   296,   297,   135,     0,   298,
     136,   554,   134,     0,   137,     0,     0,     0,   139,     0,
     140,     0,   135,     0,   375,   136,     0,     0,     0,   137,
       0,     0,   132,   139,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,   133,   134,     0,   132,     0,     0,
     517,   518,   519,   520,     0,   135,     0,     0,   136,   133,
     134,     0,   137,     0,     0,     0,   533,   534,   535,   536,
     135,     0,     0,   136,     0,     0,     0,   137,     0,     0,
       0,   555,   556,   557,   558,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,     0,     0,     0,     0,   139,
       0,   140,     0,     0,   193,   194,   195,   196,   197,   198,
     199,     0,     0,     0,   132,   139,     0,   140,     0,   193,
     194,   195,   196,   197,   198,   199,   634,   134,     0,   132,
     139,     0,   140,     0,   132,     0,     0,   135,     0,     0,
     136,   133,   134,     0,   137,     0,   133,   134,     0,     0,
       0,     0,   135,     0,     0,   136,     0,   135,   132,   137,
     136,     0,   482,   139,   137,   140,     0,     0,     0,     0,
     133,   134,     0,     0,     0,     0,     0,   485,   139,   132,
     140,   135,     0,     0,   136,     0,     0,     0,   137,     0,
       0,   133,   134,     0,     0,   132,   635,   636,   637,   638,
       0,     0,   135,     0,     0,   136,     0,   133,   134,   137,
       0,   579,   580,     0,     0,     0,   587,   588,   135,     0,
       0,   136,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   198,
     199,     0,   595,   596,     0,   139,     0,   140,     0,   581,
     582,   583,   584,   585,   589,   590,   591,   592,   593,     0,
     139,     0,   140,   603,   604,   139,     0,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   597,   598,
     599,   600,   601,   132,     0,     0,     0,     0,     0,   139,
       0,   140,     0,     0,     0,   133,   134,     0,     0,   605,
     606,   607,   608,   609,     0,     0,   135,     0,     0,   136,
     139,   132,   140,   137,     0,   193,   194,   195,   196,   197,
     198,   199,     0,   133,   134,     0,   139,   132,   140,     0,
       0,     0,     0,     0,   135,     0,     0,   136,     0,   133,
     134,   137,   132,     0,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   136,   133,   134,     0,   137,   132,   408,
       0,   409,   410,   249,   250,   135,     0,     0,   136,     0,
     133,   134,   137,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   132,   136,     0,     0,   720,   137,   721,
     722,   249,   250,     0,     0,   133,   134,     0,   132,     0,
       0,     0,     0,   369,     0,     0,   135,   370,   371,   136,
     133,   134,     0,   137,   139,     0,   140,   132,   395,     0,
       0,   135,   396,   397,   136,     0,     0,     0,   137,   133,
     134,     0,     0,     0,   401,     0,     0,     0,   402,   403,
     135,     0,   139,   136,   140,     0,     0,   137,     0,     0,
       0,     0,     0,     0,   132,     0,     0,     0,   139,   424,
     140,     0,     0,   425,   426,     0,   627,   134,     0,     0,
       0,     0,     0,   139,   428,   140,     0,   135,   429,   430,
     136,     0,   132,     0,   137,     0,     0,     0,     0,   139,
       0,   140,     0,   431,   133,   134,     0,   432,   433,     0,
       0,     0,     0,     0,     0,   135,     0,     0,   136,     0,
     132,     0,   137,     0,   139,     0,   140,     0,     0,     0,
       0,     0,   133,   134,     0,     0,   132,     0,     0,   139,
     628,   140,     0,   135,   249,   250,   136,     0,   133,   134,
     137,   132,     0,     0,     0,     0,     0,   132,   139,   135,
     140,     0,   136,   133,   134,     0,   137,     0,   679,   133,
     134,     0,   680,   681,   135,     0,   132,   136,     0,     0,
     135,   137,     0,   136,     0,     0,     0,   137,   133,   134,
       0,     0,   132,     0,     0,   139,   682,   140,   132,   135,
     683,   684,   136,     0,   133,   134,   137,   306,     0,     0,
     625,   134,   687,     0,     0,   135,   688,   689,   136,     0,
       0,   135,   137,   139,   136,   140,     0,   690,   137,   247,
       0,   691,   692,   703,     0,   132,     0,   704,   705,     0,
       0,     0,     0,     0,     0,     0,     0,   668,   134,     0,
       0,   139,   729,   140,     0,     0,   730,   731,   135,     0,
       0,   136,     0,     0,     0,   137,     0,   139,     0,   140,
       0,   183,   184,   185,   186,   307,   308,   309,   310,   311,
     312,     0,   139,     0,   140,     0,     0,     0,   139,     0,
     140,     0,   248,   183,   184,   185,   186,   249,   250,   251,
     252,   253,   254,     0,     0,     0,     0,   139,     0,   140,
       0,     0,     0,     0,   746,   193,   194,   195,   196,   197,
     198,   199,     0,   139,     0,   140,     0,     0,     0,   139,
       0,   140,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   255,   256,   257,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,   349,   350,     0,     0,   139,     0,   140,     0,
       0,     0,     0,     0,     0,     0,   353,     0,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,   351,   349,   350,     0,     0,     0,     0,     0,
       0,     0,     0,   357,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,   349,
     350,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,   352,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,   351,
     349,   350,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   400,   352,     0,   349,   350,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
     351,   434,   349,   350,     0,     0,     0,     0,     0,     0,
       0,   352,     0,     0,     0,     0,     0,   351,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     462,     0,     0,   349,   350,     0,     0,     0,     0,     0,
       0,     0,   352,     0,     0,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   514,     0,   352,
     349,   350,     0,   351,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   575,     0,     0,   349,
     350,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     351,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   749,     0,   352,   349,   350,     0,   351,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   750,     0,     0,   349,   350,     0,     0,     0,
       0,     0,   352,     0,     0,     0,   351,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   751,
       0,   352,   349,   350,     0,   351,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   752,     0,
       0,   349,   350,     0,     0,     0,     0,     0,   352,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   771,     0,   352,   349,   350,
       0,   351,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   772,     0,     0,   349,   350,     0,
       0,     0,     0,     0,   352,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   773,     0,   352,   349,   350,     0,   351,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     774,     0,     0,   349,   350,     0,     0,     0,     0,     0,
     352,     0,     0,     0,   351,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   775,     0,   352,
     349,   350,     0,   351,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   776,     0,     0,   349,
     350,     0,     0,     0,     0,     0,   352,     0,     0,     0,
     351,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   777,     0,   352,   349,   350,     0,   351,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   778,     0,     0,   349,   350,     0,     0,     0,
       0,     0,   352,     0,     0,     0,   351,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   779,
       0,   352,   349,   350,     0,   351,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   780,     0,
       0,   349,   350,     0,     0,     0,     0,     0,   352,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   790,     0,   352,   349,   350,
       0,   351,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   791,     0,     0,   349,   350,     0,
       0,     0,     0,     0,   352,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   803,     0,   352,   349,   350,     0,   351,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     804,     0,     0,   349,   350,     0,     0,     0,     0,     0,
     352,     0,     0,     0,   351,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   808,     0,   352,
     349,   350,     0,   351,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   810,     0,     0,   349,
     350,     0,     0,     0,     0,     0,   352,     0,     0,     0,
     351,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   811,     0,   352,   349,   350,     0,   351,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   812,     0,     0,   349,   350,     0,     0,     0,
       0,     0,   352,     0,     0,     0,   351,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   813,
       0,   352,   349,   350,     0,   351,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   817,     0,
       0,   349,   350,     0,     0,     0,     0,     0,   352,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   818,     0,   352,   349,   350,
       0,   351,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   819,     0,     0,   349,   350,     0,
       0,     0,     0,     0,   352,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   820,     0,   352,   349,   350,     0,   351,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     824,     0,     0,   349,   350,     0,     0,     0,     0,     0,
     352,     0,     0,     0,   351,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   825,     0,   352,
     349,   350,     0,   351,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   826,     0,     0,   349,
     350,     0,     0,     0,     0,     0,   352,     0,     0,     0,
     351,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   827,     0,   352,   349,   350,     0,   351,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   831,     0,     0,   349,   350,     0,     0,     0,
       0,     0,   352,     0,     0,     0,   351,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   832,
       0,   352,   349,   350,     0,   351,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   834,     0,
       0,   349,   350,     0,     0,     0,     0,     0,   352,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   835,     0,   352,   349,   350,
       0,   351,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   857,     0,     0,   349,   350,     0,
       0,     0,     0,     0,   352,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   858,     0,   352,   349,   350,     0,   351,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     859,     0,     0,   349,   350,     0,     0,     0,     0,     0,
     352,     0,     0,     0,   351,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   860,     0,   352,
     349,   350,     0,   351,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   861,     0,     0,   349,
     350,     0,     0,     0,     0,     0,   352,     0,     0,     0,
     351,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   862,     0,   352,   349,   350,     0,   351,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   863,     0,     0,   349,   350,     0,     0,     0,
       0,     0,   352,     0,     0,     0,   351,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   864,
       0,   352,   349,   350,     0,   351,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   865,     0,
       0,   349,   350,     0,     0,     0,     0,     0,   352,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   866,     0,   352,   349,   350,
       0,   351,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   867,     0,     0,   349,   350,     0,
       0,     0,     0,     0,   352,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   868,     0,   352,   349,   350,     0,   351,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     869,     0,     0,   349,   350,     0,     0,     0,     0,     0,
     352,     0,     0,     0,   351,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   870,     0,   352,
     349,   350,     0,   351,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   875,     0,     0,   349,
     350,     0,     0,     0,     0,     0,   352,     0,     0,     0,
     351,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   876,     0,   352,   349,   350,     0,   351,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   877,     0,     0,   349,   350,     0,     0,     0,
       0,     0,   352,     0,     0,     0,   351,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   878,
       0,   352,   349,   350,     0,   351,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   879,     0,
       0,   349,   350,     0,     0,     0,     0,     0,   352,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,   352,   349,   350,
       0,   351,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,   349,   350,     0,
       0,     0,     0,     0,   352,     0,     0,     0,   351,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     352
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,   247,     5,     6,    59,    85,    21,     8,
      21,     9,    85,   140,    15,     8,    44,    18,   140,     8,
     140,    20,    50,    21,    22,    85,    27,    20,    29,    89,
      90,    20,    85,   139,    32,     8,    33,    35,    21,   139,
       9,    39,     8,     8,    45,    46,     8,    20,    49,    50,
      51,   129,    21,    22,    20,    20,   129,    33,    20,    60,
      61,    62,    63,    32,     8,     0,    35,     8,    85,   129,
      39,    84,    89,    90,    21,    88,    20,    78,    85,    20,
      81,    82,    89,    90,    29,    85,    86,    87,    88,    89,
      90,    33,    37,    38,    39,    40,    86,    87,    88,    89,
      45,     8,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    57,    20,    59,    60,    61,    62,   129,   130,
     131,   132,   133,   134,   135,    70,    23,    24,    73,   129,
      33,   132,    85,   134,    79,   140,    89,    90,    83,    21,
      85,   139,   140,    37,   142,    37,   129,   130,   131,   132,
     133,   134,   135,   122,   123,   124,   125,   126,   127,   128,
       8,    24,   131,     3,     4,     5,     6,     7,   139,   140,
      37,   140,    20,   142,    21,    85,    86,    87,    88,   423,
       8,    33,    21,   139,   140,    25,    26,    27,    28,    29,
      30,    31,    20,    33,    34,    21,    36,    33,    38,    33,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   212,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     8,     9,   247,   129,   130,   131,
     132,   133,   134,   135,    33,    95,    33,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   129,   130,   131,   132,   133,   134,   135,    33,
     129,   130,   131,   132,   133,   134,   135,    86,    87,    33,
     140,   141,    37,   129,   130,   131,   132,   133,   134,   135,
      16,    17,    18,    19,    37,   316,    86,    23,    24,    37,
     373,    37,   323,    37,   377,    37,   379,   129,   130,   131,
     132,   133,   134,   135,    37,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,    12,    13,    14,    15,
      16,    17,    18,    19,   365,    86,    87,    23,    24,    37,
     614,   372,    37,   374,    37,    37,     9,   378,    37,    84,
      85,   382,    87,    88,    89,    90,    33,    37,    21,    22,
      84,    85,    37,    87,    88,    89,    90,   398,    37,    32,
      37,    37,    35,   404,    85,     9,    39,    37,    89,    90,
      37,    37,   413,   414,   415,   416,   417,    21,    22,   420,
     421,   422,   423,    37,    37,    37,   427,   372,    32,   374,
      37,    35,    37,   378,    85,    39,    85,   382,    89,    90,
      89,    90,    37,   444,   445,   446,   447,   448,    86,    87,
      88,   452,    90,   398,   399,   400,    37,     9,    91,    92,
      93,    94,   122,   123,   124,   125,   126,   127,   128,    21,
      22,   131,    18,    19,    37,    37,   421,    23,    24,    37,
      32,    37,   427,    35,    37,    51,    51,    39,   489,   434,
     491,    33,    33,   494,    33,   496,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   129,    21,   140,    85,   142,
      85,    20,    89,    90,    89,    90,    20,    20,   122,   123,
     124,   125,   126,   127,   128,    85,    20,   131,    85,    89,
      90,     8,    89,    90,     8,    20,   140,     8,   142,   540,
     541,     8,   543,   544,    20,   546,   547,     8,   549,   550,
       8,   552,   553,    85,     9,    20,    85,    89,    90,     9,
      89,    90,     8,     8,    20,     8,    21,    22,     8,   570,
     571,    21,    22,    20,     9,   576,   577,    32,    20,     9,
      35,    20,    32,    20,    39,    35,    21,    22,   140,    39,
     142,    21,    22,     8,     8,    20,    20,    32,    20,     9,
      35,   129,    32,    85,    39,    35,     8,    89,    90,    39,
       8,    21,    22,   614,   129,   130,   131,   132,   133,   134,
     135,    20,    32,    85,   625,    35,   627,    89,    90,    39,
      20,   632,   633,     8,     8,    20,    91,    92,    93,    94,
      20,   642,   643,     8,   645,     8,   647,    20,     8,    20,
       8,   652,   653,    85,   655,   656,    91,    92,    93,    94,
      96,     8,    21,    20,     8,   666,   667,    20,    37,    37,
     671,    37,   673,    37,   129,   130,   131,   132,   133,   134,
     135,    91,    92,    93,    94,   140,    37,   142,    37,   139,
     140,    37,   142,    20,   129,   130,   131,   132,   133,   134,
     135,     8,     8,    20,     8,   140,     8,   142,   129,   139,
     140,    20,   142,   714,    37,     9,     8,    20,     8,   129,
     130,   131,   132,   133,   134,   135,     8,    21,    22,    20,
     140,    20,   142,     8,    20,     8,     8,   129,    32,    20,
     685,    35,   129,    20,    20,    39,     8,     8,     8,    20,
      20,     8,     8,   754,   755,    20,   757,   758,    37,    33,
      89,   762,    42,   764,    33,    33,   767,    -1,   769,   714,
     129,   130,   131,   132,   133,   134,   135,    -1,    -1,     9,
      -1,   782,   783,    -1,   785,   786,    -1,   788,   789,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    32,    -1,    -1,    35,    -1,    -1,   809,    39,
      -1,    -1,    -1,    -1,   815,   816,    -1,    -1,    -1,    -1,
      -1,   822,   823,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,    21,    -1,    -1,    -1,   140,    -1,   142,   850,
     851,    -1,    -1,    33,    34,    21,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,   850,   851,    -1,    -1,   139,
     140,    -1,   142,    -1,    -1,    95,    21,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     129,   130,   131,   132,   133,   134,   135,    21,    -1,   139,
     140,   141,    -1,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    33,    34,    -1,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    95,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     9,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,    -1,    21,    22,    -1,     9,    -1,   139,   140,
     141,    -1,    -1,    -1,    32,    -1,    -1,    35,    21,    22,
      -1,    39,     9,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    -1,    21,    22,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,     9,    91,    92,    93,    94,    -1,    -1,    -1,
      32,    -1,    -1,    35,    21,    22,    -1,    39,    91,    92,
      93,    94,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,
      -1,    -1,    39,    -1,    91,    92,    93,    94,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,   140,    -1,   142,    -1,   129,   130,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,   140,     9,   142,
      -1,    -1,   129,   130,   131,   132,   133,   134,   135,    -1,
      21,    22,    -1,   140,     9,   142,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    35,    -1,    21,    22,    39,     9,
     122,   123,   124,   125,   126,   127,   128,    32,    -1,   131,
      35,    21,    22,    -1,    39,    -1,    -1,    -1,   140,    -1,
     142,    -1,    32,    -1,   131,    35,    -1,    -1,    -1,    39,
      -1,    -1,     9,   140,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,     9,    -1,    -1,
      91,    92,    93,    94,    -1,    32,    -1,    -1,    35,    21,
      22,    -1,    39,    -1,    -1,    -1,    91,    92,    93,    94,
      32,    -1,    -1,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    -1,    -1,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,   140,
      -1,   142,    -1,    -1,   129,   130,   131,   132,   133,   134,
     135,    -1,    -1,    -1,     9,   140,    -1,   142,    -1,   129,
     130,   131,   132,   133,   134,   135,    21,    22,    -1,     9,
     140,    -1,   142,    -1,     9,    -1,    -1,    32,    -1,    -1,
      35,    21,    22,    -1,    39,    -1,    21,    22,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    32,     9,    39,
      35,    -1,   139,   140,    39,   142,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,   139,   140,     9,
     142,    32,    -1,    -1,    35,    -1,    -1,    -1,    39,    -1,
      -1,    21,    22,    -1,    -1,     9,    91,    92,    93,    94,
      -1,    -1,    32,    -1,    -1,    35,    -1,    21,    22,    39,
      -1,    91,    92,    -1,    -1,    -1,    91,    92,    32,    -1,
      -1,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,   134,
     135,    -1,    93,    94,    -1,   140,    -1,   142,    -1,   129,
     130,   131,   132,   133,   129,   130,   131,   132,   133,    -1,
     140,    -1,   142,    93,    94,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,     9,    -1,    -1,    -1,    -1,    -1,   140,
      -1,   142,    -1,    -1,    -1,    21,    22,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    32,    -1,    -1,    35,
     140,     9,   142,    39,    -1,   129,   130,   131,   132,   133,
     134,   135,    -1,    21,    22,    -1,   140,     9,   142,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,    21,
      22,    39,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    21,    22,    -1,    39,     9,    85,
      -1,    87,    88,    89,    90,    32,    -1,    -1,    35,    -1,
      21,    22,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,     9,    35,    -1,    -1,    85,    39,    87,
      88,    89,    90,    -1,    -1,    21,    22,    -1,     9,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    32,    89,    90,    35,
      21,    22,    -1,    39,   140,    -1,   142,     9,    85,    -1,
      -1,    32,    89,    90,    35,    -1,    -1,    -1,    39,    21,
      22,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    90,
      32,    -1,   140,    35,   142,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,   140,    85,
     142,    -1,    -1,    89,    90,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,   140,    85,   142,    -1,    32,    89,    90,
      35,    -1,     9,    -1,    39,    -1,    -1,    -1,    -1,   140,
      -1,   142,    -1,    85,    21,    22,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,
       9,    -1,    39,    -1,   140,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    21,    22,    -1,    -1,     9,    -1,    -1,   140,
      85,   142,    -1,    32,    89,    90,    35,    -1,    21,    22,
      39,     9,    -1,    -1,    -1,    -1,    -1,     9,   140,    32,
     142,    -1,    35,    21,    22,    -1,    39,    -1,    85,    21,
      22,    -1,    89,    90,    32,    -1,     9,    35,    -1,    -1,
      32,    39,    -1,    35,    -1,    -1,    -1,    39,    21,    22,
      -1,    -1,     9,    -1,    -1,   140,    85,   142,     9,    32,
      89,    90,    35,    -1,    21,    22,    39,    21,    -1,    -1,
      21,    22,    85,    -1,    -1,    32,    89,    90,    35,    -1,
      -1,    32,    39,   140,    35,   142,    -1,    85,    39,    21,
      -1,    89,    90,    85,    -1,     9,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,
      -1,   140,    85,   142,    -1,    -1,    89,    90,    32,    -1,
      -1,    35,    -1,    -1,    -1,    39,    -1,   140,    -1,   142,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,   140,    -1,   142,    -1,    -1,    -1,   140,    -1,
     142,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    -1,    -1,   140,    -1,   142,
      -1,    -1,    -1,    -1,   131,   129,   130,   131,   132,   133,
     134,   135,    -1,   140,    -1,   142,    -1,    -1,    -1,   140,
      -1,   142,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,   140,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    53,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    95,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    53,
      23,    24,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    37,    95,    -1,    23,    24,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      53,    37,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    53,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    95,
      23,    24,    -1,    53,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    95,    23,    24,    -1,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    53,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    95,    23,    24,    -1,    53,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    53,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    95,    23,    24,
      -1,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    53,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    95,    23,    24,    -1,    53,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    53,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    95,
      23,    24,    -1,    53,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      53,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    95,    23,    24,    -1,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    53,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    95,    23,    24,    -1,    53,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    53,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    95,    23,    24,
      -1,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    53,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    95,    23,    24,    -1,    53,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    53,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    95,
      23,    24,    -1,    53,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      53,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    95,    23,    24,    -1,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    53,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    95,    23,    24,    -1,    53,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    53,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    95,    23,    24,
      -1,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    53,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    95,    23,    24,    -1,    53,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    53,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    95,
      23,    24,    -1,    53,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      53,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    95,    23,    24,    -1,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    53,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    95,    23,    24,    -1,    53,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    53,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    95,    23,    24,
      -1,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    53,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    95,    23,    24,    -1,    53,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    53,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    95,
      23,    24,    -1,    53,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      53,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    95,    23,    24,    -1,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    53,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    95,    23,    24,    -1,    53,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    53,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    95,    23,    24,
      -1,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    53,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    95,    23,    24,    -1,    53,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    53,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    95,
      23,    24,    -1,    53,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      53,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    95,    23,    24,    -1,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    53,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    95,    23,    24,    -1,    53,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    53,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    95,    23,    24,
      -1,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    25,    26,    27,    28,
      29,    30,    31,    33,    34,    36,    38,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      95,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   140,   141,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     9,    21,    22,    32,    35,    39,   139,   140,
     142,   193,   194,   195,   194,   139,   191,   194,   140,   139,
     192,   194,   194,   140,   140,    33,   139,   139,   140,   139,
     140,   139,   194,    33,   122,   123,   124,   125,   126,   127,
     128,   131,   194,   202,    84,    85,    87,    88,    89,    90,
     199,   194,    21,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,   129,   130,   131,   132,   133,   134,   135,
     196,   198,    21,    91,    92,    93,    94,   129,   194,   196,
      85,   129,    21,    85,   129,    85,    89,    90,   129,    21,
     196,    21,   196,    21,   196,    21,   196,    89,    90,   199,
     202,    21,    91,    92,    93,    94,   129,   194,   196,   194,
     194,    21,   194,   202,   194,    21,   196,    21,    84,    89,
      90,    91,    92,    93,    94,   136,   137,   138,   196,   197,
     198,    21,    91,    92,    93,    94,   129,   194,   196,    21,
      91,    92,    93,    94,   194,   196,    21,    91,    92,    93,
      94,   194,   196,   194,    21,   196,    21,   196,    21,    84,
      88,   122,   123,   124,   125,   126,   127,   128,   131,   194,
     203,    21,   196,   194,   194,   196,    21,    89,    90,    91,
      92,    93,    94,   196,   198,    33,    51,   139,   140,   141,
     150,   151,    33,    51,   139,   140,   150,   151,     0,   149,
      33,    33,   194,   194,   194,   140,    37,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    23,
      24,    53,    95,    37,    37,    24,    37,    33,    33,    33,
      33,    33,    33,    33,    33,    37,    85,    89,    90,    85,
      89,    90,    37,    37,    37,   131,   194,    37,    37,    37,
      37,    37,    37,    85,    89,    90,    85,    89,    90,    85,
      89,    90,    85,    89,    90,    85,    89,    90,    37,    37,
      37,    85,    89,    90,    37,    85,    89,    90,    85,    87,
      88,   194,   197,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    85,    89,    90,    37,    85,    89,
      90,    85,    89,    90,    37,    85,    89,    90,    85,    89,
      90,    86,    37,    37,    37,    37,    37,    37,    37,    85,
      89,    90,    37,    85,    89,    90,   194,    33,    33,   194,
      33,    33,    20,   139,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   139,   194,   194,   139,   194,   194,    20,     8,
      20,     8,    20,    20,     8,    20,     8,    20,    21,    91,
      92,    93,    94,   194,   196,   198,    21,    91,    92,    93,
      94,   194,   196,    20,    20,   198,    21,    91,    92,    93,
      94,   194,   196,   198,    86,    87,    88,    89,    86,    87,
      88,    90,    21,    91,    92,    93,    94,   194,   196,    20,
       8,     8,    20,     8,     8,    20,     8,     8,    20,     8,
       8,    20,     8,     8,    21,    91,    92,    93,    94,   194,
     196,    21,   196,    21,   196,    20,    20,    20,   194,    20,
       8,     8,    20,    20,    20,    20,     8,     9,   194,    91,
      92,   129,   130,   131,   132,   133,   194,    91,    92,   129,
     130,   131,   132,   133,   194,    93,    94,   129,   130,   131,
     132,   133,   194,    93,    94,   129,   130,   131,   132,   133,
     194,   129,   129,   194,    21,    91,    92,    93,    94,   136,
     137,   194,   196,   200,   201,    21,   194,    21,    85,   194,
     197,    20,     8,     8,    21,    91,    92,    93,    94,   194,
     196,    20,     8,     8,    20,     8,    20,     8,    20,    21,
     196,    20,     8,     8,    20,     8,     8,    20,    96,    85,
     194,   194,   194,   194,   194,    20,     8,     8,    21,   194,
      20,     8,    20,     8,    20,   194,   194,   194,   194,    85,
      89,    90,    85,    89,    90,    37,    37,    85,    89,    90,
      85,    89,    90,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,    85,    89,    90,    85,    89,    90,    85,
      89,    90,   194,   194,    37,    37,    37,    37,   194,   194,
      85,    87,    88,   194,   197,   194,   194,   194,   194,    85,
      89,    90,   194,   194,   194,   194,    85,    89,    90,   194,
     194,   194,   194,    37,   194,   194,   131,   194,   194,    20,
      20,    20,    20,    20,     8,     8,    20,     8,     8,   196,
     129,    20,     8,    20,     8,    20,    20,     8,    20,     8,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,     8,     8,    20,     8,     8,    20,     8,     8,
      20,    20,   194,   196,   129,   129,    85,    86,    87,    88,
      89,    90,   129,    20,    20,    20,    20,    20,    20,     8,
      20,    20,    20,    20,    20,     8,     8,    20,    20,    20,
      20,    20,     8,     8,    20,    20,    20,    20,    85,    89,
      90,    20,    20,    20,    20,    20,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
      37,    37,   194,   194,   194,   194,   194,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,   194,   196,   194,   196,    20,    20,    20,    20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   146,   147,   148,   148,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   152,   153,   153,   154,
     155,   156,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   160,   160,   161,   161,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   164,   165,   165,   165,   165,   165,
     166,   167,   167,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   169,
     169,   170,   170,   170,   170,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   173,   174,   174,   174,   175,   175,
     175,   176,   176,   176,   176,   177,   177,   178,   178,   178,
     178,   179,   179,   179,   179,   180,   180,   180,   180,   181,
     181,   181,   181,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   185,   185,
     185,   185,   186,   186,   186,   186,   187,   187,   187,   187,
     188,   188,   188,   188,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   191,   191,   191,   191,   192,   192,   192,   192,   193,
     193,   193,   193,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   195,   195,   195,   195,   195,   196,   196,
     196,   196,   196,   196,   196,   197,   197,   198,   198,   198,
     198,   199,   199,   199,   199,   200,   200,   201,   201,   202,
     202,   202,   202,   202,   202,   202,   202,   203,   203,   203,
     203
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     3,     1,     2,
       2,     3,     3,     3,     3,     2,     3,     3,     2,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     4,     2,
       2,     2,     4,     4,     6,     8,     8,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     6,     8,     8,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     2,     2,     4,     6,     6,     4,
       4,     2,     2,     2,     2,     4,     4,     6,     8,     8,
       4,     4,     4,     4,     6,     8,     8,     4,     2,     4,
       2,     2,     4,     6,     6,     4,     4,     2,     2,     2,
       2,     2,     4,     6,     6,     4,     4,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     4,     6,     6,     6,
       2,     6,     4,     2,     2,     4,     6,     6,     4,     4,
       2,     2,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     4,     2,     4,     4,     4,     4,     4,     6,     4,
       8,     6,     6,     6,     6,     6,     8,     8,     8,     8,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     4,
       4,     4,     4,     6,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     2,     4,     6,     6,
       2,     2,     2,     2,     4,     4,     6,     8,     8,     4,
       4,     4,     4,     6,     6,     2,     2,     2,     2,     2,
       2,     4,     6,     8,     8,     1,     2,     2,     4,     6,
       6,     2,     4,     6,     6,     2,     4,     6,     6,     2,
       4,     6,     6,     2,     4,     4,     6,     8,     8,     4,
       4,     4,     4,     4,     4,     6,     8,     8,     2,     4,
       6,     6,     2,     4,     6,     6,     2,     4,     6,     6,
       2,     4,     6,     6,     2,     2,     4,     6,     6,     2,
       2,     2,     2,     2,     2,     4,     6,     6,     2,     2,
       2,     2,     4,     4,     6,     8,     8,     4,     4,     4,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     3,     3,     1,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 206 "grammar.y"
                     {  }
#line 2818 "grammar.c"
    break;

  case 3:
#line 208 "grammar.y"
                         {  }
#line 2824 "grammar.c"
    break;

  case 4:
#line 209 "grammar.y"
                                     {  }
#line 2830 "grammar.c"
    break;

  case 5:
#line 212 "grammar.y"
                                             { yylineno++; previouspc = pc; }
#line 2836 "grammar.c"
    break;

  case 6:
#line 213 "grammar.y"
                                             { setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2842 "grammar.c"
    break;

  case 7:
#line 214 "grammar.y"
                                             { setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2848 "grammar.c"
    break;

  case 8:
#line 215 "grammar.y"
                                             { yylineno++; previouspc = pc; }
#line 2854 "grammar.c"
    break;

  case 9:
#line 216 "grammar.y"
                                             { setLabelAddress((yyvsp[-1].literal),pc); outDirective(); yylineno++; previouspc = pc; }
#line 2860 "grammar.c"
    break;

  case 10:
#line 217 "grammar.y"
                                             { setLabelAddress((yyvsp[-1].literal),pc); outDirective(); yylineno++; previouspc = pc; }
#line 2866 "grammar.c"
    break;

  case 11:
#line 218 "grammar.y"
                                         { yylineno++; warningError("Include feature has not yet being implemented. Ignoring this line"); }
#line 2872 "grammar.c"
    break;

  case 12:
#line 219 "grammar.y"
                                         { yylineno++; warningError("Include feature has not yet being implemented. Ignoring this line"); }
#line 2878 "grammar.c"
    break;

  case 13:
#line 220 "grammar.y"
                                         {  includebin((yyvsp[-1].literal)); yylineno++; }
#line 2884 "grammar.c"
    break;

  case 14:
#line 221 "grammar.y"
                                         {  includebin((yyvsp[-1].literal)); yylineno++; }
#line 2890 "grammar.c"
    break;

  case 15:
#line 222 "grammar.y"
                                         {  yylineno++; previouspc = pc; }
#line 2896 "grammar.c"
    break;

  case 16:
#line 223 "grammar.y"
                                         {  setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2902 "grammar.c"
    break;

  case 17:
#line 224 "grammar.y"
                                         {  setLabelAddress((yyvsp[-2].literal),previouspc); yylineno++; previouspc = pc; }
#line 2908 "grammar.c"
    break;

  case 18:
#line 225 "grammar.y"
                                         { yylineno++; /* MISSING Absolute segment directive mode. Not yet implemented */ }
#line 2914 "grammar.c"
    break;

  case 19:
#line 226 "grammar.y"
                                         { yylineno++; /* nothing happens, I've foudn this directive around, probably alias to TITLE */ }
#line 2920 "grammar.c"
    break;

  case 20:
#line 227 "grammar.y"
                                         { yylineno++; condStatus = ((yyvsp[-1].normal)==0)?0:1; }
#line 2926 "grammar.c"
    break;

  case 21:
#line 228 "grammar.y"
                                         { yylineno++; condStatus = (LookupTableLabels((yyvsp[-1].literal))<0)?0:1; }
#line 2932 "grammar.c"
    break;

  case 22:
#line 229 "grammar.y"
                                         { yylineno++; condStatus = (LookupTableLabels((yyvsp[-1].literal))<0)?1:0; }
#line 2938 "grammar.c"
    break;

  case 23:
#line 230 "grammar.y"
                                         { if (condStatus < 0) { fatalError("Syntax error. Detected ENDIF without IF"); } condStatus = -1; yylineno++; }
#line 2944 "grammar.c"
    break;

  case 24:
#line 231 "grammar.y"
                                         { fatalError("Syntax error: I do not understand this line"); }
#line 2950 "grammar.c"
    break;

  case 25:
#line 232 "grammar.y"
                                         { fatalError("Syntax error: I do not understand this line"); }
#line 2956 "grammar.c"
    break;

  case 26:
#line 233 "grammar.y"
                                         { fatalError("Syntax error: I do not understand this line"); }
#line 2962 "grammar.c"
    break;

  case 27:
#line 235 "grammar.y"
                                        { directiveError((yyvsp[0].literal)); }
#line 2968 "grammar.c"
    break;

  case 28:
#line 236 "grammar.y"
                                        { return 0; /* we should stop here compilation */}
#line 2974 "grammar.c"
    break;

  case 29:
#line 237 "grammar.y"
                                                { return 0; /* MISSING, in order to allow entry point definition */ }
#line 2980 "grammar.c"
    break;

  case 30:
#line 238 "grammar.y"
                                        { }
#line 2986 "grammar.c"
    break;

  case 31:
#line 239 "grammar.y"
                                        { }
#line 2992 "grammar.c"
    break;

  case 32:
#line 240 "grammar.y"
                                        { }
#line 2998 "grammar.c"
    break;

  case 33:
#line 241 "grammar.y"
                                        { }
#line 3004 "grammar.c"
    break;

  case 34:
#line 242 "grammar.y"
                                        { }
#line 3010 "grammar.c"
    break;

  case 35:
#line 243 "grammar.y"
                                           { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal));  }
#line 3016 "grammar.c"
    break;

  case 36:
#line 244 "grammar.y"
                                           { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal));  }
#line 3022 "grammar.c"
    break;

  case 37:
#line 245 "grammar.y"
                                           { k = (((pc/(yyvsp[0].normal))+1)*(yyvsp[0].normal)); for(a=pc; a < k; a++) { outCode(1,0x0); } }
#line 3028 "grammar.c"
    break;

  case 38:
#line 249 "grammar.y"
                                    {  }
#line 3034 "grammar.c"
    break;

  case 39:
#line 250 "grammar.y"
                                    {  }
#line 3040 "grammar.c"
    break;

  case 40:
#line 251 "grammar.y"
                                    {  }
#line 3046 "grammar.c"
    break;

  case 41:
#line 252 "grammar.y"
                                    {  }
#line 3052 "grammar.c"
    break;

  case 42:
#line 253 "grammar.y"
                                    {  }
#line 3058 "grammar.c"
    break;

  case 43:
#line 254 "grammar.y"
                                    {  }
#line 3064 "grammar.c"
    break;

  case 44:
#line 255 "grammar.y"
                                    {  }
#line 3070 "grammar.c"
    break;

  case 45:
#line 256 "grammar.y"
                                {  }
#line 3076 "grammar.c"
    break;

  case 46:
#line 257 "grammar.y"
                                {  }
#line 3082 "grammar.c"
    break;

  case 47:
#line 258 "grammar.y"
                                {  }
#line 3088 "grammar.c"
    break;

  case 48:
#line 259 "grammar.y"
                                {  }
#line 3094 "grammar.c"
    break;

  case 49:
#line 260 "grammar.y"
                                {  }
#line 3100 "grammar.c"
    break;

  case 50:
#line 261 "grammar.y"
                                {  }
#line 3106 "grammar.c"
    break;

  case 51:
#line 262 "grammar.y"
                                {  }
#line 3112 "grammar.c"
    break;

  case 52:
#line 263 "grammar.y"
                                {  }
#line 3118 "grammar.c"
    break;

  case 53:
#line 264 "grammar.y"
                                {  }
#line 3124 "grammar.c"
    break;

  case 54:
#line 265 "grammar.y"
                                {  }
#line 3130 "grammar.c"
    break;

  case 55:
#line 266 "grammar.y"
                                {  }
#line 3136 "grammar.c"
    break;

  case 56:
#line 267 "grammar.y"
                                {  }
#line 3142 "grammar.c"
    break;

  case 57:
#line 268 "grammar.y"
                                {  }
#line 3148 "grammar.c"
    break;

  case 58:
#line 269 "grammar.y"
                                {  }
#line 3154 "grammar.c"
    break;

  case 59:
#line 270 "grammar.y"
                                {  }
#line 3160 "grammar.c"
    break;

  case 60:
#line 271 "grammar.y"
                                {  }
#line 3166 "grammar.c"
    break;

  case 61:
#line 272 "grammar.y"
                                {  }
#line 3172 "grammar.c"
    break;

  case 62:
#line 273 "grammar.y"
                                {  }
#line 3178 "grammar.c"
    break;

  case 63:
#line 274 "grammar.y"
                                {  }
#line 3184 "grammar.c"
    break;

  case 64:
#line 275 "grammar.y"
                                {  }
#line 3190 "grammar.c"
    break;

  case 65:
#line 276 "grammar.y"
                                {  }
#line 3196 "grammar.c"
    break;

  case 66:
#line 277 "grammar.y"
                                {  }
#line 3202 "grammar.c"
    break;

  case 67:
#line 278 "grammar.y"
                                {  }
#line 3208 "grammar.c"
    break;

  case 68:
#line 279 "grammar.y"
                                {  }
#line 3214 "grammar.c"
    break;

  case 69:
#line 280 "grammar.y"
                                {  }
#line 3220 "grammar.c"
    break;

  case 70:
#line 281 "grammar.y"
                                {  }
#line 3226 "grammar.c"
    break;

  case 71:
#line 282 "grammar.y"
                                {  }
#line 3232 "grammar.c"
    break;

  case 72:
#line 283 "grammar.y"
                                { outCode(1,0x3F); }
#line 3238 "grammar.c"
    break;

  case 73:
#line 284 "grammar.y"
                                { outCode(2,0xED,0xA9); }
#line 3244 "grammar.c"
    break;

  case 74:
#line 285 "grammar.y"
                                { outCode(2,0xED,0xB9); }
#line 3250 "grammar.c"
    break;

  case 75:
#line 286 "grammar.y"
                                { outCode(2,0xED,0xA1); }
#line 3256 "grammar.c"
    break;

  case 76:
#line 287 "grammar.y"
                                { outCode(2,0xED,0xB1); }
#line 3262 "grammar.c"
    break;

  case 77:
#line 288 "grammar.y"
                                { outCode(1,0x2F); }
#line 3268 "grammar.c"
    break;

  case 78:
#line 289 "grammar.y"
                                { outCode(1,0x27); }
#line 3274 "grammar.c"
    break;

  case 79:
#line 290 "grammar.y"
                                { outCode(1,0xF3); }
#line 3280 "grammar.c"
    break;

  case 80:
#line 291 "grammar.y"
                                { outCode(1,0xFB); }
#line 3286 "grammar.c"
    break;

  case 81:
#line 292 "grammar.y"
                                { outCode(1,0xD9); }
#line 3292 "grammar.c"
    break;

  case 82:
#line 293 "grammar.y"
                                { outCode(1,0x76); }
#line 3298 "grammar.c"
    break;

  case 83:
#line 294 "grammar.y"
                                { outCode(2,0xED,0xAA); }
#line 3304 "grammar.c"
    break;

  case 84:
#line 295 "grammar.y"
                                { outCode(2,0xED,0xBA); }
#line 3310 "grammar.c"
    break;

  case 85:
#line 296 "grammar.y"
                                { outCode(2,0xED,0xA2); }
#line 3316 "grammar.c"
    break;

  case 86:
#line 297 "grammar.y"
                                { outCode(2,0xED,0xB2); }
#line 3322 "grammar.c"
    break;

  case 87:
#line 298 "grammar.y"
                                    { outCode(2,0xED,0xA8); }
#line 3328 "grammar.c"
    break;

  case 88:
#line 299 "grammar.y"
                                    { outCode(2,0xED,0xB8); }
#line 3334 "grammar.c"
    break;

  case 89:
#line 300 "grammar.y"
                                    { outCode(2,0xED,0xA0); }
#line 3340 "grammar.c"
    break;

  case 90:
#line 301 "grammar.y"
                                    { outCode(2,0xED,0xB0); }
#line 3346 "grammar.c"
    break;

  case 91:
#line 302 "grammar.y"
                                    { outCode(2,0xED,0x44); }
#line 3352 "grammar.c"
    break;

  case 92:
#line 303 "grammar.y"
                                    { outCode(1,0x00);      }
#line 3358 "grammar.c"
    break;

  case 93:
#line 304 "grammar.y"
                                    { outCode(2,0xED,0xBB); }
#line 3364 "grammar.c"
    break;

  case 94:
#line 305 "grammar.y"
                                    { outCode(2,0xED,0xB3); }
#line 3370 "grammar.c"
    break;

  case 95:
#line 306 "grammar.y"
                                    { outCode(2,0xED,0xAB); }
#line 3376 "grammar.c"
    break;

  case 96:
#line 307 "grammar.y"
                                    { outCode(2,0xED,0xA3); }
#line 3382 "grammar.c"
    break;

  case 97:
#line 308 "grammar.y"
                                    { outCode(2,0xED,0x4D); }
#line 3388 "grammar.c"
    break;

  case 98:
#line 309 "grammar.y"
                                    { outCode(2,0xED,0x45); }
#line 3394 "grammar.c"
    break;

  case 99:
#line 310 "grammar.y"
                                    { outCode(1,0x17);      }
#line 3400 "grammar.c"
    break;

  case 100:
#line 311 "grammar.y"
                                    { outCode(1,0x07);      }
#line 3406 "grammar.c"
    break;

  case 101:
#line 312 "grammar.y"
                                    { outCode(2,0xED,0x6F); }
#line 3412 "grammar.c"
    break;

  case 102:
#line 313 "grammar.y"
                                    { outCode(1,0x1F);      }
#line 3418 "grammar.c"
    break;

  case 103:
#line 314 "grammar.y"
                                    { outCode(1,0x0F);      }
#line 3424 "grammar.c"
    break;

  case 104:
#line 315 "grammar.y"
                                    { outCode(2,0xED,0x67); }
#line 3430 "grammar.c"
    break;

  case 105:
#line 316 "grammar.y"
                                    { outCode(1,0x37); }
#line 3436 "grammar.c"
    break;

  case 106:
#line 320 "grammar.y"
                                                 { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal)); }
#line 3442 "grammar.c"
    break;

  case 107:
#line 322 "grammar.y"
                                                 { for(a=0;a<abs((yyvsp[0].normal));a++) { outCode(1,0x0); } }
#line 3448 "grammar.c"
    break;

  case 108:
#line 323 "grammar.y"
                                            {  for(a=0;a<abs((yyvsp[-2].normal));a++) { outCode(1,(yyvsp[0].normal)); }  }
#line 3454 "grammar.c"
    break;

  case 109:
#line 325 "grammar.y"
                                           { for(a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3460 "grammar.c"
    break;

  case 110:
#line 327 "grammar.y"
                                           { for(a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3466 "grammar.c"
    break;

  case 111:
#line 329 "grammar.y"
                                       { for(a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3472 "grammar.c"
    break;

  case 112:
#line 331 "grammar.y"
                                      { outCode(2,0xCE,(yyvsp[0].normal)); }
#line 3478 "grammar.c"
    break;

  case 113:
#line 332 "grammar.y"
                                           { k = (((yyvsp[0].byte))|128|8); outCode(1,k); }
#line 3484 "grammar.c"
    break;

  case 114:
#line 333 "grammar.y"
                                                   { outCode(1,0x8E); }
#line 3490 "grammar.c"
    break;

  case 115:
#line 334 "grammar.y"
                                                             { outCode(3,0xDD,0x8E,(yyvsp[-1].normal)); }
#line 3496 "grammar.c"
    break;

  case 116:
#line 335 "grammar.y"
                                                             { outCode(3,0xFD,0x8E,(yyvsp[-1].normal)); }
#line 3502 "grammar.c"
    break;

  case 117:
#line 336 "grammar.y"
                                                   { outCode(3,0xDD,0x8E,0); }
#line 3508 "grammar.c"
    break;

  case 118:
#line 337 "grammar.y"
                                                   { outCode(3,0xFD,0x8E,0); }
#line 3514 "grammar.c"
    break;

  case 119:
#line 338 "grammar.y"
                                           { k = (((yyvsp[0].byte)<<4)|64|8|2); outCode(2,0xED,k); }
#line 3520 "grammar.c"
    break;

  case 120:
#line 339 "grammar.y"
                                           {  outCode(2,0xDD,0x8C); }
#line 3526 "grammar.c"
    break;

  case 121:
#line 340 "grammar.y"
                                           {  outCode(2,0xDD,0x8D); }
#line 3532 "grammar.c"
    break;

  case 122:
#line 341 "grammar.y"
                                           {  outCode(2,0xFD,0x8C); }
#line 3538 "grammar.c"
    break;

  case 123:
#line 342 "grammar.y"
                                           {  outCode(2,0xFD,0x8D); }
#line 3544 "grammar.c"
    break;

  case 124:
#line 344 "grammar.y"
                                      { outCode(2,0xC6,(yyvsp[0].normal)); }
#line 3550 "grammar.c"
    break;

  case 125:
#line 345 "grammar.y"
                                           { k = (((yyvsp[0].byte))|128); outCode(1,k); }
#line 3556 "grammar.c"
    break;

  case 126:
#line 346 "grammar.y"
                                                   { outCode(1,0x86); }
#line 3562 "grammar.c"
    break;

  case 127:
#line 347 "grammar.y"
                                                             { outCode(3,0xDD,0x86,(yyvsp[-1].normal)); }
#line 3568 "grammar.c"
    break;

  case 128:
#line 348 "grammar.y"
                                                             { outCode(3,0xFD,0x86,(yyvsp[-1].normal)); }
#line 3574 "grammar.c"
    break;

  case 129:
#line 349 "grammar.y"
                                                   { outCode(3,0xDD,0x86,0); }
#line 3580 "grammar.c"
    break;

  case 130:
#line 350 "grammar.y"
                                                   { outCode(3,0xFD,0x86,0); }
#line 3586 "grammar.c"
    break;

  case 131:
#line 351 "grammar.y"
                                           { k = (((yyvsp[0].byte)<<4)|8|1); outCode(1,k); }
#line 3592 "grammar.c"
    break;

  case 132:
#line 352 "grammar.y"
                                           { outCode(2,0xDD,0x09); }
#line 3598 "grammar.c"
    break;

  case 133:
#line 353 "grammar.y"
                                           { outCode(2,0xDD,0x19); }
#line 3604 "grammar.c"
    break;

  case 134:
#line 354 "grammar.y"
                                           { outCode(2,0xDD,0x29); }
#line 3610 "grammar.c"
    break;

  case 135:
#line 355 "grammar.y"
                                           { outCode(2,0xDD,0x39); }
#line 3616 "grammar.c"
    break;

  case 136:
#line 356 "grammar.y"
                                           { outCode(2,0xFD,0x09); }
#line 3622 "grammar.c"
    break;

  case 137:
#line 357 "grammar.y"
                                           { outCode(2,0xFD,0x19); }
#line 3628 "grammar.c"
    break;

  case 138:
#line 358 "grammar.y"
                                           { outCode(2,0xFD,0x29); }
#line 3634 "grammar.c"
    break;

  case 139:
#line 359 "grammar.y"
                                           { outCode(2,0xFD,0x39); }
#line 3640 "grammar.c"
    break;

  case 140:
#line 360 "grammar.y"
                                           {  outCode(2,0xDD,0x84); }
#line 3646 "grammar.c"
    break;

  case 141:
#line 361 "grammar.y"
                                           {  outCode(2,0xDD,0x85); }
#line 3652 "grammar.c"
    break;

  case 142:
#line 362 "grammar.y"
                                           {  outCode(2,0xFD,0x84); }
#line 3658 "grammar.c"
    break;

  case 143:
#line 363 "grammar.y"
                                           {  outCode(2,0xFD,0x85); }
#line 3664 "grammar.c"
    break;

  case 144:
#line 365 "grammar.y"
                              { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3670 "grammar.c"
    break;

  case 145:
#line 366 "grammar.y"
                                   { k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3676 "grammar.c"
    break;

  case 146:
#line 367 "grammar.y"
                                           { outCode(1,0xA6); }
#line 3682 "grammar.c"
    break;

  case 147:
#line 368 "grammar.y"
                                                     { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3688 "grammar.c"
    break;

  case 148:
#line 369 "grammar.y"
                                                     { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3694 "grammar.c"
    break;

  case 149:
#line 370 "grammar.y"
                                           { outCode(3,0xDD,0xA6,0); }
#line 3700 "grammar.c"
    break;

  case 150:
#line 371 "grammar.y"
                                           { outCode(3,0xFD,0xA6,0); }
#line 3706 "grammar.c"
    break;

  case 151:
#line 373 "grammar.y"
                                    { outCode(2,0xDD,0xA4); }
#line 3712 "grammar.c"
    break;

  case 152:
#line 374 "grammar.y"
                                    { outCode(2,0xDD,0xA5); }
#line 3718 "grammar.c"
    break;

  case 153:
#line 375 "grammar.y"
                                    { outCode(2,0xFD,0xA4); }
#line 3724 "grammar.c"
    break;

  case 154:
#line 376 "grammar.y"
                                    { outCode(2,0xFD,0xA5); }
#line 3730 "grammar.c"
    break;

  case 155:
#line 377 "grammar.y"
                                      { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3736 "grammar.c"
    break;

  case 156:
#line 378 "grammar.y"
                                           { k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3742 "grammar.c"
    break;

  case 157:
#line 379 "grammar.y"
                                                   { outCode(1,0xA6); }
#line 3748 "grammar.c"
    break;

  case 158:
#line 380 "grammar.y"
                                                             { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3754 "grammar.c"
    break;

  case 159:
#line 381 "grammar.y"
                                                             { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3760 "grammar.c"
    break;

  case 160:
#line 382 "grammar.y"
                                            { outCode(2,0xDD,0xA4); }
#line 3766 "grammar.c"
    break;

  case 161:
#line 383 "grammar.y"
                                            { outCode(2,0xDD,0xA5); }
#line 3772 "grammar.c"
    break;

  case 162:
#line 384 "grammar.y"
                                            { outCode(2,0xFD,0xA4); }
#line 3778 "grammar.c"
    break;

  case 163:
#line 385 "grammar.y"
                                            { outCode(2,0xFD,0xA5); }
#line 3784 "grammar.c"
    break;

  case 164:
#line 387 "grammar.y"
                                                      { if ((yyvsp[-4].normal) > 7) { warningError("Bit number is bigger out of range, truncating"); } outCode(2,0xCB,(((yyvsp[-4].normal)<<3)|64|6)); }
#line 3790 "grammar.c"
    break;

  case 165:
#line 388 "grammar.y"
                                                                { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xDD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3796 "grammar.c"
    break;

  case 166:
#line 389 "grammar.y"
                                                                { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xFD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3802 "grammar.c"
    break;

  case 167:
#line 390 "grammar.y"
                                   { 	if ((yyvsp[-2].normal)>7) { warningError("Bit number is bigger out of range, truncating"); }
                                            outCode(2,0xCB,(((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|64));
                                        }
#line 3810 "grammar.c"
    break;

  case 168:
#line 395 "grammar.y"
                               { outCode(3,0xCD,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3816 "grammar.c"
    break;

  case 169:
#line 396 "grammar.y"
                                       { outCode(3, (((yyvsp[-2].byte)<<3)|128|64|4),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3822 "grammar.c"
    break;

  case 170:
#line 398 "grammar.y"
                            { outCode(2,0xFE,(yyvsp[0].normal)); }
#line 3828 "grammar.c"
    break;

  case 171:
#line 399 "grammar.y"
                                  { k = (((yyvsp[0].byte))|128|32|16|8); outCode(1,k); }
#line 3834 "grammar.c"
    break;

  case 172:
#line 400 "grammar.y"
                                          { outCode(1,0xBE); }
#line 3840 "grammar.c"
    break;

  case 173:
#line 401 "grammar.y"
                                                    { outCode(3,0xDD,0xBE,(yyvsp[-1].normal)); }
#line 3846 "grammar.c"
    break;

  case 174:
#line 402 "grammar.y"
                                                    { outCode(3,0xFD,0xBE,(yyvsp[-1].normal)); }
#line 3852 "grammar.c"
    break;

  case 175:
#line 403 "grammar.y"
                                          { outCode(3,0xDD,0xBE,0); }
#line 3858 "grammar.c"
    break;

  case 176:
#line 404 "grammar.y"
                                          { outCode(3,0xFD,0xBE,0); }
#line 3864 "grammar.c"
    break;

  case 177:
#line 405 "grammar.y"
                                  {  outCode(2,0xDD,0xBC); }
#line 3870 "grammar.c"
    break;

  case 178:
#line 406 "grammar.y"
                                  {  outCode(2,0xDD,0xBD); }
#line 3876 "grammar.c"
    break;

  case 179:
#line 407 "grammar.y"
                                  {  outCode(2,0xFD,0xBC); }
#line 3882 "grammar.c"
    break;

  case 180:
#line 408 "grammar.y"
                                  {  outCode(2,0xFD,0xBD); }
#line 3888 "grammar.c"
    break;

  case 181:
#line 410 "grammar.y"
                                   { k = (((yyvsp[0].byte)<<3)|4|1); outCode(1,k); }
#line 3894 "grammar.c"
    break;

  case 182:
#line 411 "grammar.y"
                                           { outCode(1,0x35); }
#line 3900 "grammar.c"
    break;

  case 183:
#line 412 "grammar.y"
                                                     { outCode(3,0xDD,0x35,(yyvsp[-1].normal)); }
#line 3906 "grammar.c"
    break;

  case 184:
#line 413 "grammar.y"
                                                     { outCode(3,0xFD,0x35,(yyvsp[-1].normal)); }
#line 3912 "grammar.c"
    break;

  case 185:
#line 414 "grammar.y"
                                           { outCode(3,0xDD,0x35,0); }
#line 3918 "grammar.c"
    break;

  case 186:
#line 415 "grammar.y"
                                           { outCode(3,0xFD,0x35,0); }
#line 3924 "grammar.c"
    break;

  case 187:
#line 416 "grammar.y"
                                   { k = (((yyvsp[0].byte)<<4)|8|2|1); outCode(1,k); }
#line 3930 "grammar.c"
    break;

  case 188:
#line 417 "grammar.y"
                                   { outCode(2,0xDD,0x2B); }
#line 3936 "grammar.c"
    break;

  case 189:
#line 418 "grammar.y"
                                   { outCode(2,0xFD,0x2B); }
#line 3942 "grammar.c"
    break;

  case 190:
#line 419 "grammar.y"
                                { outCode(1,0xDD,0x25); }
#line 3948 "grammar.c"
    break;

  case 191:
#line 420 "grammar.y"
                                { outCode(1,0xDD,0x2D); }
#line 3954 "grammar.c"
    break;

  case 192:
#line 421 "grammar.y"
                                { outCode(1,0xFD,0x25); }
#line 3960 "grammar.c"
    break;

  case 193:
#line 422 "grammar.y"
                                { outCode(1,0xFD,0x2C); }
#line 3966 "grammar.c"
    break;

  case 194:
#line 425 "grammar.y"
                                           {  outCode(2,0x10,((yyvsp[0].normal) - pc - 2) ); }
#line 3972 "grammar.c"
    break;

  case 195:
#line 428 "grammar.y"
                                        { outCode(1,0x08); }
#line 3978 "grammar.c"
    break;

  case 196:
#line 429 "grammar.y"
                                        { outCode(1,0xEB); }
#line 3984 "grammar.c"
    break;

  case 197:
#line 430 "grammar.y"
                                                         { outCode(1,0xE3); }
#line 3990 "grammar.c"
    break;

  case 198:
#line 431 "grammar.y"
                                                         { outCode(2,0xDD,0xE3); }
#line 3996 "grammar.c"
    break;

  case 199:
#line 432 "grammar.y"
                                                         { outCode(2,0xFD,0xE3); }
#line 4002 "grammar.c"
    break;

  case 200:
#line 434 "grammar.y"
                       { switch((yyvsp[0].normal)) {
                                case 0: outCode(2,0xED,0x46); break;
                                case 1: outCode(2,0xED,0x56); break;
                                case 2: outCode(2,0xED,0x5E); break;
                                default: fatalError("Interruption mode value is out of range: Only allowed 0, 1 or 2"); break;
                               }
                             }
#line 4014 "grammar.c"
    break;

  case 201:
#line 442 "grammar.y"
                                                { outCode(2,0xED,(((yyvsp[-4].byte)<<3)|64)); }
#line 4020 "grammar.c"
    break;

  case 202:
#line 443 "grammar.y"
                                                { outCode(2,0xDB,(yyvsp[0].normal)); if ((yyvsp[-2].byte) != 7) { fatalError("IN only can use the A Register, sorry"); } }
#line 4026 "grammar.c"
    break;

  case 203:
#line 445 "grammar.y"
                                { outCode(1,((yyvsp[0].byte)<<3)|4); }
#line 4032 "grammar.c"
    break;

  case 204:
#line 446 "grammar.y"
                                { outCode(1,(((yyvsp[0].byte)<<4)|1|2));  }
#line 4038 "grammar.c"
    break;

  case 205:
#line 447 "grammar.y"
                                       { outCode(1,0x34); }
#line 4044 "grammar.c"
    break;

  case 206:
#line 448 "grammar.y"
                                                 { outCode(3,0xDD,0x34,(yyvsp[-1].normal)); }
#line 4050 "grammar.c"
    break;

  case 207:
#line 449 "grammar.y"
                                                 { outCode(3,0xFD,0x34,(yyvsp[-1].normal)); }
#line 4056 "grammar.c"
    break;

  case 208:
#line 450 "grammar.y"
                                        { outCode(3,0xDD,0x34,0); }
#line 4062 "grammar.c"
    break;

  case 209:
#line 451 "grammar.y"
                                        { outCode(3,0xFD,0x34,0); }
#line 4068 "grammar.c"
    break;

  case 210:
#line 452 "grammar.y"
                                { outCode(1,0xDD,0x23); }
#line 4074 "grammar.c"
    break;

  case 211:
#line 453 "grammar.y"
                                { outCode(1,0xFD,0x23); }
#line 4080 "grammar.c"
    break;

  case 212:
#line 454 "grammar.y"
                                { outCode(1,0xDD,0x24); }
#line 4086 "grammar.c"
    break;

  case 213:
#line 455 "grammar.y"
                                { outCode(1,0xDD,0x2C); }
#line 4092 "grammar.c"
    break;

  case 214:
#line 456 "grammar.y"
                                { outCode(1,0xFD,0x24); }
#line 4098 "grammar.c"
    break;

  case 215:
#line 457 "grammar.y"
                                { outCode(1,0xFD,0x2C); }
#line 4104 "grammar.c"
    break;

  case 216:
#line 459 "grammar.y"
                                 { outCode(3,0xC3,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4110 "grammar.c"
    break;

  case 217:
#line 460 "grammar.y"
                                 { outCode(3,(((yyvsp[-2].byte)<<3)|128|64|2),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4116 "grammar.c"
    break;

  case 218:
#line 461 "grammar.y"
                                       { outCode(1,0xE9); }
#line 4122 "grammar.c"
    break;

  case 219:
#line 462 "grammar.y"
                                       { outCode(2,0xDD,0xE9); }
#line 4128 "grammar.c"
    break;

  case 220:
#line 463 "grammar.y"
                                       { outCode(2,0xDD,0xE9); }
#line 4134 "grammar.c"
    break;

  case 221:
#line 465 "grammar.y"
                                           { outCode(2,((yyvsp[-2].byte)<<3)|32,((yyvsp[0].normal) - pc - 2)); }
#line 4140 "grammar.c"
    break;

  case 222:
#line 466 "grammar.y"
                                    { outCode(2,0x18, ((yyvsp[0].normal) - pc - 2) ); }
#line 4146 "grammar.c"
    break;

  case 223:
#line 467 "grammar.y"
                                    { fatalError("You cannot use M flag bit in JR instruction"); }
#line 4152 "grammar.c"
    break;

  case 224:
#line 468 "grammar.y"
                                    { fatalError("You cannot use P flag bit in JR instruction"); }
#line 4158 "grammar.c"
    break;

  case 225:
#line 469 "grammar.y"
                                     { fatalError("You cannot use PE flag bit in JR instruction"); }
#line 4164 "grammar.c"
    break;

  case 226:
#line 470 "grammar.y"
                                     { fatalError("You cannot use PO flag bit in JR instruction"); }
#line 4170 "grammar.c"
    break;

  case 227:
#line 473 "grammar.y"
                                                                                                { k = (((yyvsp[-2].byte) << 3)|64); k = k | (yyvsp[0].byte); outCode(1,k); }
#line 4176 "grammar.c"
    break;

  case 228:
#line 474 "grammar.y"
                                                                        { outCode(3,0x3A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");} }
#line 4182 "grammar.c"
    break;

  case 229:
#line 475 "grammar.y"
                                                                                                        { outCode(2,(((yyvsp[-2].byte) << 3)|6),(yyvsp[0].normal)); }
#line 4188 "grammar.c"
    break;

  case 230:
#line 476 "grammar.y"
                                                                        { outCode(3,(yyvsp[-3].normal),((yyvsp[-6].byte)<<3)|64|4|2,(yyvsp[-1].normal)); }
#line 4194 "grammar.c"
    break;

  case 231:
#line 477 "grammar.y"
                                                                                                { outCode(1,((yyvsp[-4].byte)<<3)|64|4|2); }
#line 4200 "grammar.c"
    break;

  case 232:
#line 478 "grammar.y"
                                                                                                { outCode(1,0x02); }
#line 4206 "grammar.c"
    break;

  case 233:
#line 479 "grammar.y"
                                                                                                { outCode(1,0x12); }
#line 4212 "grammar.c"
    break;

  case 234:
#line 480 "grammar.y"
                                                                                                { outCode(2,0x36,(yyvsp[0].normal)); }
#line 4218 "grammar.c"
    break;

  case 235:
#line 481 "grammar.y"
                                                                                                { outCode(1,(yyvsp[0].byte)|64|32|16); }
#line 4224 "grammar.c"
    break;

  case 236:
#line 482 "grammar.y"
                                                                                { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),(yyvsp[0].normal)); }
#line 4230 "grammar.c"
    break;

  case 237:
#line 483 "grammar.y"
                                                                                { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),(yyvsp[-3].normal)); }
#line 4236 "grammar.c"
    break;

  case 238:
#line 484 "grammar.y"
                                                                                { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),-(yyvsp[0].normal)); }
#line 4242 "grammar.c"
    break;

  case 239:
#line 485 "grammar.y"
                                                                                { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),-(yyvsp[-3].normal)); }
#line 4248 "grammar.c"
    break;

  case 240:
#line 486 "grammar.y"
                                                                                                { outCode(3,0x32,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4254 "grammar.c"
    break;

  case 241:
#line 487 "grammar.y"
                                                                                                { outCode(4,0xED,43,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4260 "grammar.c"
    break;

  case 242:
#line 488 "grammar.y"
                                                                                                { outCode(4,0xED,53,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4266 "grammar.c"
    break;

  case 243:
#line 489 "grammar.y"
                                                                                                { outCode(4,0xED,73,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4272 "grammar.c"
    break;

  case 244:
#line 490 "grammar.y"
                                                                                                { outCode(3,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4278 "grammar.c"
    break;

  case 245:
#line 491 "grammar.y"
                                                                                                { outCode(4,0xDD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4284 "grammar.c"
    break;

  case 246:
#line 492 "grammar.y"
                                                                                                { outCode(3,0xFD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4290 "grammar.c"
    break;

  case 247:
#line 493 "grammar.y"
                                                                                                { outCode(1,0x0A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4296 "grammar.c"
    break;

  case 248:
#line 494 "grammar.y"
                                                                                                { outCode(1,0x1A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4302 "grammar.c"
    break;

  case 249:
#line 495 "grammar.y"
                                                                                                        { outCode(2,0xED,0x57); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4308 "grammar.c"
    break;

  case 250:
#line 496 "grammar.y"
                                                                                                        { outCode(2,0xED,0x47); }
#line 4314 "grammar.c"
    break;

  case 251:
#line 497 "grammar.y"
                                                                                                        { outCode(2,0xED,0x5F); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4320 "grammar.c"
    break;

  case 252:
#line 498 "grammar.y"
                                                                                                        { outCode(2,0xED,0x4F); }
#line 4326 "grammar.c"
    break;

  case 253:
#line 499 "grammar.y"
                                                                                { outCode(4,(yyvsp[-4].normal),0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
#line 4332 "grammar.c"
    break;

  case 254:
#line 500 "grammar.y"
                                                                                        { outCode(4,(yyvsp[-2].normal),0x21,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4338 "grammar.c"
    break;

  case 255:
#line 501 "grammar.y"
                                                                                { 
																		if ((yyvsp[-4].byte) != 2) { outCode(4,0xED,0x4B,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																		else            { outCode(3,0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																	}
#line 4347 "grammar.c"
    break;

  case 256:
#line 505 "grammar.y"
                                                                                                                { outCode(3,((yyvsp[-2].byte)<<4)|1,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4353 "grammar.c"
    break;

  case 257:
#line 507 "grammar.y"
                                                                                                { 
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else { outCode(1,0xF9);  }
																	}
#line 4362 "grammar.c"
    break;

  case 258:
#line 511 "grammar.y"
                                                                                                {
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else  { outCode(2,(yyvsp[0].normal),0xF9); }
																	}
#line 4371 "grammar.c"
    break;

  case 259:
#line 515 "grammar.y"
                                                                                                        { 
		                                                                switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																			case 7: outCode(2,0xDD,(5<<3)|64|(yyvsp[0].byte)); break;
																			default: outCode(2,0xDD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	    }
																	}
#line 4382 "grammar.c"
    break;

  case 260:
#line 521 "grammar.y"
                                                                                                { switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																		case 7: outCode(2,0xFD,(5<<3)|64|(yyvsp[0].byte)); break;
																		default: outCode(2,0xFD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	  }
																	}
#line 4392 "grammar.c"
    break;

  case 261:
#line 526 "grammar.y"
                                         { outCode(2,0xDD,0x60); }
#line 4398 "grammar.c"
    break;

  case 262:
#line 527 "grammar.y"
                                         { outCode(2,0xDD,0x61); }
#line 4404 "grammar.c"
    break;

  case 263:
#line 528 "grammar.y"
                                         { outCode(2,0xDD,0x62); }
#line 4410 "grammar.c"
    break;

  case 264:
#line 529 "grammar.y"
                                         { outCode(2,0xDD,0x63); }
#line 4416 "grammar.c"
    break;

  case 265:
#line 530 "grammar.y"
                                         { outCode(2,0xDD,0x64); }
#line 4422 "grammar.c"
    break;

  case 266:
#line 531 "grammar.y"
                                         { outCode(2,0xDD,0x65); }
#line 4428 "grammar.c"
    break;

  case 267:
#line 532 "grammar.y"
                                         { outCode(2,0xDD,0x67); }
#line 4434 "grammar.c"
    break;

  case 268:
#line 533 "grammar.y"
                                         { outCode(2,0xDD,0x68); }
#line 4440 "grammar.c"
    break;

  case 269:
#line 534 "grammar.y"
                                         { outCode(2,0xDD,0x69); }
#line 4446 "grammar.c"
    break;

  case 270:
#line 535 "grammar.y"
                                         { outCode(2,0xDD,0x6A); }
#line 4452 "grammar.c"
    break;

  case 271:
#line 536 "grammar.y"
                                         { outCode(2,0xDD,0x6B); }
#line 4458 "grammar.c"
    break;

  case 272:
#line 537 "grammar.y"
                                         { outCode(2,0xDD,0x6C); }
#line 4464 "grammar.c"
    break;

  case 273:
#line 538 "grammar.y"
                                         { outCode(2,0xDD,0x6D); }
#line 4470 "grammar.c"
    break;

  case 274:
#line 539 "grammar.y"
                                         { outCode(2,0xDD,0x6F); }
#line 4476 "grammar.c"
    break;

  case 275:
#line 540 "grammar.y"
                                         { outCode(2,0xFD,0x60); }
#line 4482 "grammar.c"
    break;

  case 276:
#line 541 "grammar.y"
                                         { outCode(2,0xFD,0x61); }
#line 4488 "grammar.c"
    break;

  case 277:
#line 542 "grammar.y"
                                         { outCode(2,0xFD,0x62); }
#line 4494 "grammar.c"
    break;

  case 278:
#line 543 "grammar.y"
                                         { outCode(2,0xFD,0x63); }
#line 4500 "grammar.c"
    break;

  case 279:
#line 544 "grammar.y"
                                         { outCode(2,0xFD,0x64); }
#line 4506 "grammar.c"
    break;

  case 280:
#line 545 "grammar.y"
                                         { outCode(2,0xFD,0x65); }
#line 4512 "grammar.c"
    break;

  case 281:
#line 546 "grammar.y"
                                         { outCode(2,0xFD,0x67); }
#line 4518 "grammar.c"
    break;

  case 282:
#line 547 "grammar.y"
                                         { outCode(2,0xFD,0x68); }
#line 4524 "grammar.c"
    break;

  case 283:
#line 548 "grammar.y"
                                         { outCode(2,0xFD,0x69); }
#line 4530 "grammar.c"
    break;

  case 284:
#line 549 "grammar.y"
                                         { outCode(2,0xFD,0x6A); }
#line 4536 "grammar.c"
    break;

  case 285:
#line 550 "grammar.y"
                                         { outCode(2,0xFD,0x6B); }
#line 4542 "grammar.c"
    break;

  case 286:
#line 551 "grammar.y"
                                         { outCode(2,0xFD,0x6C); }
#line 4548 "grammar.c"
    break;

  case 287:
#line 552 "grammar.y"
                                         { outCode(2,0xFD,0x6D); }
#line 4554 "grammar.c"
    break;

  case 288:
#line 553 "grammar.y"
                                         { outCode(2,0xFD,0x6F); }
#line 4560 "grammar.c"
    break;

  case 289:
#line 554 "grammar.y"
                                    { outCode(2,0xFD,0x2E,(yyvsp[0].normal)); }
#line 4566 "grammar.c"
    break;

  case 290:
#line 555 "grammar.y"
                                    { outCode(2,0xDD,0x2E,(yyvsp[0].normal)); }
#line 4572 "grammar.c"
    break;

  case 291:
#line 556 "grammar.y"
                                    { outCode(2,0xFD,0x26,(yyvsp[0].normal)); }
#line 4578 "grammar.c"
    break;

  case 292:
#line 557 "grammar.y"
                                    { outCode(2,0xDD,0x26,(yyvsp[0].normal)); }
#line 4584 "grammar.c"
    break;

  case 293:
#line 558 "grammar.y"
                                    { fatalError("Sorry, LD option into F register is not allowed in the Z80"); }
#line 4590 "grammar.c"
    break;

  case 294:
#line 559 "grammar.y"
                                    { fatalError("Sorry, LD option into AF register is not allowed in the Z80"); }
#line 4596 "grammar.c"
    break;

  case 295:
#line 562 "grammar.y"
                             { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4602 "grammar.c"
    break;

  case 296:
#line 563 "grammar.y"
                                  { k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4608 "grammar.c"
    break;

  case 297:
#line 564 "grammar.y"
                                          { outCode(1,0xB6); }
#line 4614 "grammar.c"
    break;

  case 298:
#line 565 "grammar.y"
                                                    { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4620 "grammar.c"
    break;

  case 299:
#line 566 "grammar.y"
                                                    { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4626 "grammar.c"
    break;

  case 300:
#line 567 "grammar.y"
                                   { outCode(2,0xDD,0xB4); }
#line 4632 "grammar.c"
    break;

  case 301:
#line 568 "grammar.y"
                                   { outCode(2,0xDD,0xB5); }
#line 4638 "grammar.c"
    break;

  case 302:
#line 569 "grammar.y"
                                   { outCode(2,0xFD,0xB4); }
#line 4644 "grammar.c"
    break;

  case 303:
#line 570 "grammar.y"
                                   { outCode(2,0xFD,0xB5); }
#line 4650 "grammar.c"
    break;

  case 304:
#line 571 "grammar.y"
                                     { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4656 "grammar.c"
    break;

  case 305:
#line 572 "grammar.y"
                                          { k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4662 "grammar.c"
    break;

  case 306:
#line 573 "grammar.y"
                                                  { outCode(1,0xB6); }
#line 4668 "grammar.c"
    break;

  case 307:
#line 574 "grammar.y"
                                                            { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4674 "grammar.c"
    break;

  case 308:
#line 575 "grammar.y"
                                                            { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4680 "grammar.c"
    break;

  case 309:
#line 576 "grammar.y"
                                           { outCode(2,0xDD,0xB4); }
#line 4686 "grammar.c"
    break;

  case 310:
#line 577 "grammar.y"
                                           { outCode(2,0xDD,0xB5); }
#line 4692 "grammar.c"
    break;

  case 311:
#line 578 "grammar.y"
                                           { outCode(2,0xFD,0xB4); }
#line 4698 "grammar.c"
    break;

  case 312:
#line 579 "grammar.y"
                                           { outCode(2,0xFD,0xB5); }
#line 4704 "grammar.c"
    break;

  case 313:
#line 582 "grammar.y"
                                                      { outCode(2,0xD3,(yyvsp[-3].normal)); }
#line 4710 "grammar.c"
    break;

  case 314:
#line 583 "grammar.y"
                                                           { outCode(2,0xED,((yyvsp[0].byte)<<3)|1|64); }
#line 4716 "grammar.c"
    break;

  case 315:
#line 585 "grammar.y"
                           { outCode(1,((yyvsp[0].byte)<<4)|1|128|64); }
#line 4722 "grammar.c"
    break;

  case 316:
#line 586 "grammar.y"
                         { outCode(2,0xDD,0xE1); }
#line 4728 "grammar.c"
    break;

  case 317:
#line 587 "grammar.y"
                         { outCode(2,0xFD,0xE1); }
#line 4734 "grammar.c"
    break;

  case 318:
#line 589 "grammar.y"
                             { outCode(1,((yyvsp[0].byte)<<4)|1|4|64|128); }
#line 4740 "grammar.c"
    break;

  case 319:
#line 590 "grammar.y"
                           { outCode(2,0xDD,0xE5); }
#line 4746 "grammar.c"
    break;

  case 320:
#line 591 "grammar.y"
                           { outCode(2,0xFD,0xE5); }
#line 4752 "grammar.c"
    break;

  case 321:
#line 594 "grammar.y"
                                   { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128); }
#line 4758 "grammar.c"
    break;

  case 322:
#line 595 "grammar.y"
                                                  { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|4|2); }
#line 4764 "grammar.c"
    break;

  case 323:
#line 596 "grammar.y"
                                                            { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4770 "grammar.c"
    break;

  case 324:
#line 597 "grammar.y"
                                                            { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4776 "grammar.c"
    break;

  case 325:
#line 600 "grammar.y"
                                                           { outCode(1,0xC9); }
#line 4782 "grammar.c"
    break;

  case 326:
#line 601 "grammar.y"
                                           { outCode(1,((yyvsp[0].byte)<<3)|128|64); }
#line 4788 "grammar.c"
    break;

  case 327:
#line 604 "grammar.y"
                                                          { outCode(2,0xCB,((yyvsp[0].byte))|16); }
#line 4794 "grammar.c"
    break;

  case 328:
#line 605 "grammar.y"
                                                      { outCode(2,0xCB,16); }
#line 4800 "grammar.c"
    break;

  case 329:
#line 606 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4806 "grammar.c"
    break;

  case 330:
#line 607 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4812 "grammar.c"
    break;

  case 331:
#line 609 "grammar.y"
                                       { outCode(2,0xCB,  (yyvsp[0].byte)); }
#line 4818 "grammar.c"
    break;

  case 332:
#line 610 "grammar.y"
                                         { outCode(2,0xCB,0x06); }
#line 4824 "grammar.c"
    break;

  case 333:
#line 611 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4830 "grammar.c"
    break;

  case 334:
#line 612 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4836 "grammar.c"
    break;

  case 335:
#line 614 "grammar.y"
                                      { outCode(2,0xCB,(yyvsp[0].byte)|8|16); }
#line 4842 "grammar.c"
    break;

  case 336:
#line 615 "grammar.y"
                                      { outCode(2,0xCB,0x1E);     }
#line 4848 "grammar.c"
    break;

  case 337:
#line 616 "grammar.y"
                                                { outCode(2,0xDD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4854 "grammar.c"
    break;

  case 338:
#line 617 "grammar.y"
                                                { outCode(2,0xFD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4860 "grammar.c"
    break;

  case 339:
#line 619 "grammar.y"
                                       { outCode(2,0xCB,(yyvsp[0].byte)|8); }
#line 4866 "grammar.c"
    break;

  case 340:
#line 620 "grammar.y"
                                       { outCode(2,0xCB,0x0E); }
#line 4872 "grammar.c"
    break;

  case 341:
#line 621 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4878 "grammar.c"
    break;

  case 342:
#line 622 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4884 "grammar.c"
    break;

  case 343:
#line 624 "grammar.y"
                        { switch ((yyvsp[0].normal)) {
                                case 0x0: case 0x8:
                                case 0x10: case 0x18:
                                case 0x20: case 0x28:
                                case 0x30: case 0x38: outCode(1,((yyvsp[0].normal)<<3)|128|64|4|2|1); break;
                                default: fatalError("Wrong vector provided for RST"); break;
                               }
                             }
#line 4897 "grammar.c"
    break;

  case 344:
#line 633 "grammar.y"
                                { outCode(1,(yyvsp[0].byte)|8|16|128); }
#line 4903 "grammar.c"
    break;

  case 345:
#line 634 "grammar.y"
                                { outCode(2,0xDE,(yyvsp[0].normal)); }
#line 4909 "grammar.c"
    break;

  case 346:
#line 635 "grammar.y"
                                               { outCode(1,0x9E); }
#line 4915 "grammar.c"
    break;

  case 347:
#line 636 "grammar.y"
                                                         { outCode(3,0xDD,0x9E,(yyvsp[-1].normal)); }
#line 4921 "grammar.c"
    break;

  case 348:
#line 637 "grammar.y"
                                                         { outCode(3,0xFD,0x9E,(yyvsp[-1].normal)); }
#line 4927 "grammar.c"
    break;

  case 349:
#line 638 "grammar.y"
                                  { outCode(2,0xED,((yyvsp[0].byte)<<4)|2|64); }
#line 4933 "grammar.c"
    break;

  case 350:
#line 639 "grammar.y"
                                       {  outCode(2,0xDD,0x9C); }
#line 4939 "grammar.c"
    break;

  case 351:
#line 640 "grammar.y"
                                           {  outCode(2,0xDD,0x9D); }
#line 4945 "grammar.c"
    break;

  case 352:
#line 641 "grammar.y"
                                           {  outCode(2,0xFD,0x9C); }
#line 4951 "grammar.c"
    break;

  case 353:
#line 642 "grammar.y"
                                           {  outCode(2,0xFD,0x9D); }
#line 4957 "grammar.c"
    break;

  case 354:
#line 644 "grammar.y"
                                   { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128|64); }
#line 4963 "grammar.c"
    break;

  case 355:
#line 645 "grammar.y"
                                                  { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|64|4|2); }
#line 4969 "grammar.c"
    break;

  case 356:
#line 646 "grammar.y"
                                                            { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4975 "grammar.c"
    break;

  case 357:
#line 647 "grammar.y"
                                                            { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4981 "grammar.c"
    break;

  case 358:
#line 650 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32); }
#line 4987 "grammar.c"
    break;

  case 359:
#line 651 "grammar.y"
                                                       { outCode(2,0xCB,26); }
#line 4993 "grammar.c"
    break;

  case 360:
#line 652 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 4999 "grammar.c"
    break;

  case 361:
#line 653 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 5005 "grammar.c"
    break;

  case 362:
#line 655 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|16); }
#line 5011 "grammar.c"
    break;

  case 363:
#line 656 "grammar.y"
                                                       { outCode(2,0xCB,36); }
#line 5017 "grammar.c"
    break;

  case 364:
#line 657 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 5023 "grammar.c"
    break;

  case 365:
#line 658 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 5029 "grammar.c"
    break;

  case 366:
#line 660 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|8); }
#line 5035 "grammar.c"
    break;

  case 367:
#line 661 "grammar.y"
                                                { outCode(2,0xCB,0x2E); }
#line 5041 "grammar.c"
    break;

  case 368:
#line 662 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 5047 "grammar.c"
    break;

  case 369:
#line 663 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 5053 "grammar.c"
    break;

  case 370:
#line 665 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|16|8); }
#line 5059 "grammar.c"
    break;

  case 371:
#line 666 "grammar.y"
                                                       { outCode(2,0xCB,0x3E); }
#line 5065 "grammar.c"
    break;

  case 372:
#line 667 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 5071 "grammar.c"
    break;

  case 373:
#line 668 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 5077 "grammar.c"
    break;

  case 374:
#line 670 "grammar.y"
                                       { outCode(1,(yyvsp[0].byte)|16|128); }
#line 5083 "grammar.c"
    break;

  case 375:
#line 671 "grammar.y"
                                  { outCode(2,0xD6,(yyvsp[0].normal)); }
#line 5089 "grammar.c"
    break;

  case 376:
#line 672 "grammar.y"
                                       { outCode(1,0x96); }
#line 5095 "grammar.c"
    break;

  case 377:
#line 673 "grammar.y"
                                                 { outCode(3,0xDD,0x96,(yyvsp[-1].normal)); }
#line 5101 "grammar.c"
    break;

  case 378:
#line 674 "grammar.y"
                                                 { outCode(3,0xFD,0x96,(yyvsp[-1].normal)); }
#line 5107 "grammar.c"
    break;

  case 379:
#line 675 "grammar.y"
                               {  outCode(2,0xDD,0x94); }
#line 5113 "grammar.c"
    break;

  case 380:
#line 676 "grammar.y"
                                   {  outCode(2,0xDD,0x95); }
#line 5119 "grammar.c"
    break;

  case 381:
#line 677 "grammar.y"
                                   {  outCode(2,0xFD,0x94); }
#line 5125 "grammar.c"
    break;

  case 382:
#line 678 "grammar.y"
                                   {  outCode(2,0xFD,0x95); }
#line 5131 "grammar.c"
    break;

  case 383:
#line 681 "grammar.y"
                                                { k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5137 "grammar.c"
    break;

  case 384:
#line 682 "grammar.y"
                               { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5143 "grammar.c"
    break;

  case 385:
#line 683 "grammar.y"
                                           { outCode(1,0xAE); }
#line 5149 "grammar.c"
    break;

  case 386:
#line 684 "grammar.y"
                                                     { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5155 "grammar.c"
    break;

  case 387:
#line 685 "grammar.y"
                                                     { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5161 "grammar.c"
    break;

  case 388:
#line 686 "grammar.y"
                                    { outCode(2,0xDD,0xAC); }
#line 5167 "grammar.c"
    break;

  case 389:
#line 687 "grammar.y"
                                    { outCode(2,0xDD,0xAD); }
#line 5173 "grammar.c"
    break;

  case 390:
#line 688 "grammar.y"
                                    { outCode(2,0xFD,0xAC); }
#line 5179 "grammar.c"
    break;

  case 391:
#line 689 "grammar.y"
                                    { outCode(2,0xFD,0xAD); }
#line 5185 "grammar.c"
    break;

  case 392:
#line 690 "grammar.y"
                                                        { k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5191 "grammar.c"
    break;

  case 393:
#line 691 "grammar.y"
                                       { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5197 "grammar.c"
    break;

  case 394:
#line 692 "grammar.y"
                                                   { outCode(1,0xAE); }
#line 5203 "grammar.c"
    break;

  case 395:
#line 693 "grammar.y"
                                                             { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5209 "grammar.c"
    break;

  case 396:
#line 694 "grammar.y"
                                                             { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5215 "grammar.c"
    break;

  case 397:
#line 695 "grammar.y"
                                            { outCode(2,0xDD,0xAC); }
#line 5221 "grammar.c"
    break;

  case 398:
#line 696 "grammar.y"
                                            { outCode(2,0xDD,0xAD); }
#line 5227 "grammar.c"
    break;

  case 399:
#line 697 "grammar.y"
                                            { outCode(2,0xFD,0xAC); }
#line 5233 "grammar.c"
    break;

  case 400:
#line 698 "grammar.y"
                                            { outCode(2,0xFD,0xAD); }
#line 5239 "grammar.c"
    break;

  case 401:
#line 701 "grammar.y"
                                         { p = (uint8_t *)malloc(3*sizeof(uint8_t)); p[0] = 2; p[1] = (yyvsp[0].normal)&0x00FF; p[2] = (yyvsp[0].normal)>>8; (yyval.listexpr) = p;  }
#line 5245 "grammar.c"
    break;

  case 402:
#line 702 "grammar.y"
                                         { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[p[0]+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; }
#line 5251 "grammar.c"
    break;

  case 403:
#line 703 "grammar.y"
                                              { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5257 "grammar.c"
    break;

  case 404:
#line 704 "grammar.y"
                                               {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5266 "grammar.c"
    break;

  case 405:
#line 711 "grammar.y"
                                              { p = (uint8_t *)malloc(5*sizeof(uint8_t)); p[0] = 4; p[1] = (yyvsp[0].normal)&0x000000FF; p[2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[3] = ((yyvsp[0].normal)&0x00FF0000)>>16; p[4] = ((yyvsp[0].normal)&0xFF000000)>>24; (yyval.listexpr) = p;  }
#line 5272 "grammar.c"
    break;

  case 406:
#line 712 "grammar.y"
                                         { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+4)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&&0x000000FF; p[p[0]+2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[p[0]+4] = ((yyvsp[0].normal)&0x00FF0000)>>18; p[p[0]+4] = ((yyvsp[0].normal)&0xFF000000)>>24; p[0] = p[0] + 4; (yyval.listexpr) = p; }
#line 5278 "grammar.c"
    break;

  case 407:
#line 713 "grammar.y"
                                              { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5284 "grammar.c"
    break;

  case 408:
#line 714 "grammar.y"
                                               {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5293 "grammar.c"
    break;

  case 409:
#line 721 "grammar.y"
                                             { p = (uint8_t *)malloc(2); p[0] = 1; p[1] = (yyvsp[0].normal); (yyval.listexpr) = p; }
#line 5299 "grammar.c"
    break;

  case 410:
#line 722 "grammar.y"
                                             { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5305 "grammar.c"
    break;

  case 411:
#line 723 "grammar.y"
                                        { 
	                                       if (((uint16_t)(yyvsp[0].normal)) > 255) {
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[(*p)+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; 
	                                       }
	                                       else { 
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+1)); p[p[0]+1] = (yyvsp[0].normal); p[0] = p[0] + 1; (yyval.listexpr) = p; 
	                                       }   
	                                     }
#line 5318 "grammar.c"
    break;

  case 412:
#line 731 "grammar.y"
                                              {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5327 "grammar.c"
    break;

  case 413:
#line 736 "grammar.y"
                                                 { (yyval.normal) = (yyvsp[0].normal);  }
#line 5333 "grammar.c"
    break;

  case 414:
#line 737 "grammar.y"
                                                 { (yyval.normal)=((yyvsp[0].normal)==0)?1:0; }
#line 5339 "grammar.c"
    break;

  case 415:
#line 738 "grammar.y"
                                                { (yyval.normal) = (yyvsp[-1].normal);  }
#line 5345 "grammar.c"
    break;

  case 416:
#line 739 "grammar.y"
                                                { (yyval.normal)=-(yyvsp[0].normal); }
#line 5351 "grammar.c"
    break;

  case 417:
#line 740 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) + (yyvsp[0].normal); }
#line 5357 "grammar.c"
    break;

  case 418:
#line 741 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) - (yyvsp[0].normal); }
#line 5363 "grammar.c"
    break;

  case 419:
#line 742 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) * (yyvsp[0].normal); }
#line 5369 "grammar.c"
    break;

  case 420:
#line 743 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) / (yyvsp[0].normal); }
#line 5375 "grammar.c"
    break;

  case 421:
#line 744 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) & (yyvsp[0].normal); }
#line 5381 "grammar.c"
    break;

  case 422:
#line 745 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) | (yyvsp[0].normal); }
#line 5387 "grammar.c"
    break;

  case 423:
#line 746 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) << (yyvsp[0].normal); }
#line 5393 "grammar.c"
    break;

  case 424:
#line 747 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) >> (yyvsp[0].normal); }
#line 5399 "grammar.c"
    break;

  case 425:
#line 748 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 0; } else { (yyval.normal) = 1;  } }
#line 5405 "grammar.c"
    break;

  case 426:
#line 749 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5411 "grammar.c"
    break;

  case 427:
#line 750 "grammar.y"
                                                { if ( (yyvsp[-2].normal) >= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5417 "grammar.c"
    break;

  case 428:
#line 751 "grammar.y"
                                                { if ( (yyvsp[-2].normal) > (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5423 "grammar.c"
    break;

  case 429:
#line 752 "grammar.y"
                                                { if ( (yyvsp[-2].normal) <= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5429 "grammar.c"
    break;

  case 430:
#line 753 "grammar.y"
                                                { if ( (yyvsp[-2].normal) < (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5435 "grammar.c"
    break;

  case 431:
#line 754 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) && (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5441 "grammar.c"
    break;

  case 432:
#line 755 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) || (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5447 "grammar.c"
    break;

  case 433:
#line 757 "grammar.y"
                                        {  
	                                 if (getLabelValue((yyvsp[0].literal),&k) < 0)   { labelUndefinedError((yyvsp[0].literal)); (yyval.normal)=0; }                                  
	                                 else { (yyval.normal)=k; }
	                                }
#line 5456 "grammar.c"
    break;

  case 434:
#line 761 "grammar.y"
                                    { (yyval.normal) = (yyvsp[0].normal); }
#line 5462 "grammar.c"
    break;

  case 435:
#line 762 "grammar.y"
                                    { (yyval.normal) = (yyvsp[0].byte); }
#line 5468 "grammar.c"
    break;

  case 436:
#line 763 "grammar.y"
                                    { (yyval.normal) = previouspc; }
#line 5474 "grammar.c"
    break;

  case 437:
#line 764 "grammar.y"
                                    { (yyval.normal) = (LookupTableLabels((yyvsp[0].literal))<0)?0:1; }
#line 5480 "grammar.c"
    break;

  case 438:
#line 768 "grammar.y"
                        { (yyval.byte) = 7; }
#line 5486 "grammar.c"
    break;

  case 439:
#line 769 "grammar.y"
                    { (yyval.byte) = 0; }
#line 5492 "grammar.c"
    break;

  case 440:
#line 770 "grammar.y"
                    { (yyval.byte) = 1; }
#line 5498 "grammar.c"
    break;

  case 441:
#line 771 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5504 "grammar.c"
    break;

  case 442:
#line 772 "grammar.y"
                    { (yyval.byte) = 3; }
#line 5510 "grammar.c"
    break;

  case 443:
#line 773 "grammar.y"
                    { (yyval.byte) = 4; }
#line 5516 "grammar.c"
    break;

  case 444:
#line 774 "grammar.y"
                    { (yyval.byte) = 5; }
#line 5522 "grammar.c"
    break;

  case 445:
#line 776 "grammar.y"
                    { (yyval.normal) = 0xDD; }
#line 5528 "grammar.c"
    break;

  case 446:
#line 777 "grammar.y"
                    { (yyval.normal) = 0xFD; }
#line 5534 "grammar.c"
    break;

  case 447:
#line 779 "grammar.y"
                        { (yyval.byte) = 0; }
#line 5540 "grammar.c"
    break;

  case 448:
#line 780 "grammar.y"
                     { (yyval.byte) = 1; }
#line 5546 "grammar.c"
    break;

  case 449:
#line 781 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5552 "grammar.c"
    break;

  case 450:
#line 782 "grammar.y"
                     { (yyval.byte) = 3; }
#line 5558 "grammar.c"
    break;

  case 451:
#line 784 "grammar.y"
                        { (yyval.byte) = 0; }
#line 5564 "grammar.c"
    break;

  case 452:
#line 785 "grammar.y"
                     { (yyval.byte) = 1; }
#line 5570 "grammar.c"
    break;

  case 453:
#line 786 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5576 "grammar.c"
    break;

  case 454:
#line 787 "grammar.y"
                     { (yyval.byte) = 3; }
#line 5582 "grammar.c"
    break;

  case 455:
#line 790 "grammar.y"
                       { (yyval.byte) = 4; }
#line 5588 "grammar.c"
    break;

  case 456:
#line 791 "grammar.y"
                     { (yyval.byte) = 5; }
#line 5594 "grammar.c"
    break;

  case 457:
#line 793 "grammar.y"
                       { (yyval.byte) = 4; }
#line 5600 "grammar.c"
    break;

  case 458:
#line 794 "grammar.y"
                     { (yyval.byte) = 5; }
#line 5606 "grammar.c"
    break;

  case 459:
#line 796 "grammar.y"
                  { (yyval.byte) = 0; }
#line 5612 "grammar.c"
    break;

  case 460:
#line 797 "grammar.y"
                 { (yyval.byte) = 1; }
#line 5618 "grammar.c"
    break;

  case 461:
#line 798 "grammar.y"
                  { (yyval.byte) = 2; }
#line 5624 "grammar.c"
    break;

  case 462:
#line 799 "grammar.y"
                 { (yyval.byte) = 3; }
#line 5630 "grammar.c"
    break;

  case 463:
#line 800 "grammar.y"
                  { (yyval.byte) = 4; }
#line 5636 "grammar.c"
    break;

  case 464:
#line 801 "grammar.y"
                   { (yyval.byte) = 5; }
#line 5642 "grammar.c"
    break;

  case 465:
#line 802 "grammar.y"
                  { (yyval.byte) = 6; }
#line 5648 "grammar.c"
    break;

  case 466:
#line 803 "grammar.y"
                 { (yyval.byte) = 7; }
#line 5654 "grammar.c"
    break;

  case 467:
#line 805 "grammar.y"
                         { (yyval.byte) = 0; }
#line 5660 "grammar.c"
    break;

  case 468:
#line 806 "grammar.y"
                 { (yyval.byte) = 1; }
#line 5666 "grammar.c"
    break;

  case 469:
#line 807 "grammar.y"
                  { (yyval.byte) = 2; }
#line 5672 "grammar.c"
    break;

  case 470:
#line 808 "grammar.y"
                 { (yyval.byte) = 3; }
#line 5678 "grammar.c"
    break;


#line 5682 "grammar.c"

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
