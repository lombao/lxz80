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
extern void includebinTooBigError(const char * includefile);


extern void yyerror(const char *str);
extern int yylineno;
extern int pc;
extern int prepc;
extern int pass;
extern int condStatus;


char msg[200];
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



#line 131 "grammar.c"

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
    INCLUDE = 284,
    INCLUDEBIN = 285,
    DEFINED = 286,
    NEWLINE = 287,
    ERROR = 288,
    DOLAR = 289,
    ALIGN = 290,
    COMMA = 291,
    CHAR = 292,
    LDDR = 293,
    CALL = 294,
    RRCA = 295,
    OTDR = 296,
    OTIR = 297,
    OUTI = 298,
    OUTD = 299,
    RETI = 300,
    RETN = 301,
    PUSH = 302,
    END = 303,
    EQU = 304,
    DEC = 305,
    AND = 306,
    SBC = 307,
    OUT = 308,
    ADC = 309,
    LDD = 310,
    LDI = 311,
    ADD = 312,
    RRA = 313,
    RRC = 314,
    SRA = 315,
    SRL = 316,
    SLL = 317,
    RRD = 318,
    POP = 319,
    CCF = 320,
    RET = 321,
    XOR = 322,
    BIT = 323,
    SCF = 324,
    NOP = 325,
    SET = 326,
    JP = 327,
    DJNZ = 328,
    HALT = 329,
    INDR = 330,
    INIR = 331,
    IND = 332,
    LDIR = 333,
    SLA = 334,
    NEG = 335,
    LD = 336,
    AF = 337,
    HL = 338,
    SP = 339,
    BC = 340,
    DE = 341,
    IX = 342,
    IY = 343,
    IXH = 344,
    IXL = 345,
    IYH = 346,
    IYL = 347,
    OR = 348,
    AFPLUS = 349,
    SUB = 350,
    CP = 351,
    RES = 352,
    CPD = 353,
    CPDR = 354,
    CPI = 355,
    CPIR = 356,
    CPL = 357,
    RLA = 358,
    RLC = 359,
    RLCA = 360,
    DAA = 361,
    RL = 362,
    RLD = 363,
    DI = 364,
    EI = 365,
    EX = 366,
    JR = 367,
    RR = 368,
    EXX = 369,
    RST = 370,
    IM = 371,
    IN = 372,
    INI = 373,
    INC = 374,
    NC = 375,
    NZ = 376,
    PO = 377,
    PE = 378,
    Z = 379,
    P = 380,
    M = 381,
    A = 382,
    B = 383,
    C = 384,
    D = 385,
    E = 386,
    H = 387,
    L = 388,
    R = 389,
    I = 390,
    F = 391,
    STRING = 392,
    LITERAL = 393,
    LABEL = 394,
    INTEGER = 395,
    UMINUS = 396
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
#define INCLUDE 284
#define INCLUDEBIN 285
#define DEFINED 286
#define NEWLINE 287
#define ERROR 288
#define DOLAR 289
#define ALIGN 290
#define COMMA 291
#define CHAR 292
#define LDDR 293
#define CALL 294
#define RRCA 295
#define OTDR 296
#define OTIR 297
#define OUTI 298
#define OUTD 299
#define RETI 300
#define RETN 301
#define PUSH 302
#define END 303
#define EQU 304
#define DEC 305
#define AND 306
#define SBC 307
#define OUT 308
#define ADC 309
#define LDD 310
#define LDI 311
#define ADD 312
#define RRA 313
#define RRC 314
#define SRA 315
#define SRL 316
#define SLL 317
#define RRD 318
#define POP 319
#define CCF 320
#define RET 321
#define XOR 322
#define BIT 323
#define SCF 324
#define NOP 325
#define SET 326
#define JP 327
#define DJNZ 328
#define HALT 329
#define INDR 330
#define INIR 331
#define IND 332
#define LDIR 333
#define SLA 334
#define NEG 335
#define LD 336
#define AF 337
#define HL 338
#define SP 339
#define BC 340
#define DE 341
#define IX 342
#define IY 343
#define IXH 344
#define IXL 345
#define IYH 346
#define IYL 347
#define OR 348
#define AFPLUS 349
#define SUB 350
#define CP 351
#define RES 352
#define CPD 353
#define CPDR 354
#define CPI 355
#define CPIR 356
#define CPL 357
#define RLA 358
#define RLC 359
#define RLCA 360
#define DAA 361
#define RL 362
#define RLD 363
#define DI 364
#define EI 365
#define EX 366
#define JR 367
#define RR 368
#define EXX 369
#define RST 370
#define IM 371
#define IN 372
#define INI 373
#define INC 374
#define NC 375
#define NZ 376
#define PO 377
#define PE 378
#define Z 379
#define P 380
#define M 381
#define A 382
#define B 383
#define C 384
#define D 385
#define E 386
#define H 387
#define L 388
#define R 389
#define I 390
#define F 391
#define STRING 392
#define LITERAL 393
#define LABEL 394
#define INTEGER 395
#define UMINUS 396

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 63 "grammar.y"

  uint32_t normal;
  uint8_t byte;
  uint16_t word;
  uint16_t address;
  uint8_t * listexpr;
  char literal[64];
  

#line 475 "grammar.c"

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
#define YYFINAL  314
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3670

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  461
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  852

#define YYUNDEFTOK  2
#define YYMAXUTOK   398


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
     135,   136,   137,   138,   139,   140,   141,   142,   143
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   200,   200,   202,   203,   205,   206,   207,   208,   209,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   303,   305,   306,
     308,   310,   312,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   348,   349,   350,   351,   352,
     353,   354,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   370,   371,   372,   373,   378,
     379,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   408,   411,   412,   413,   414,
     415,   417,   425,   426,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   442,   443,   444,
     445,   446,   448,   449,   450,   451,   452,   453,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   488,   490,   494,
     498,   504,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   565,   566,   568,   569,   570,   572,
     573,   574,   577,   578,   579,   580,   583,   584,   587,   588,
     589,   590,   592,   593,   594,   595,   597,   598,   599,   600,
     602,   603,   604,   605,   607,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   627,   628,   629,   630,   633,
     634,   635,   636,   638,   639,   640,   641,   643,   644,   645,
     646,   648,   649,   650,   651,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   684,   685,   686,   687,   694,   695,   696,   697,
     704,   705,   706,   714,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   740,   744,   745,   746,   747,   751,
     752,   753,   754,   755,   756,   757,   759,   760,   762,   763,
     764,   765,   767,   768,   769,   770,   773,   774,   776,   777,
     779,   780,   781,   782,   783,   784,   785,   786,   788,   789,
     790,   791
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
  "ENDIF", "INCLUDE", "INCLUDEBIN", "DEFINED", "NEWLINE", "ERROR", "DOLAR",
  "ALIGN", "COMMA", "CHAR", "LDDR", "CALL", "RRCA", "OTDR", "OTIR", "OUTI",
  "OUTD", "RETI", "RETN", "PUSH", "END", "EQU", "DEC", "AND", "SBC", "OUT",
  "ADC", "LDD", "LDI", "ADD", "RRA", "RRC", "SRA", "SRL", "SLL", "RRD",
  "POP", "CCF", "RET", "XOR", "BIT", "SCF", "NOP", "SET", "JP", "DJNZ",
  "HALT", "INDR", "INIR", "IND", "LDIR", "SLA", "NEG", "LD", "AF", "HL",
  "SP", "BC", "DE", "IX", "IY", "IXH", "IXL", "IYH", "IYL", "OR", "AFPLUS",
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
     395,   396,   397,   398
};
# endif

#define YYPACT_NINF (-237)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-407)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     842,    64,     0,   424,  -119,   652,     0,  -113,  -110,  -237,
    -102,    71,  -237,   -93,     0,  -237,   645,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,   106,     0,   841,   133,   -73,    50,
     -60,  -237,  -237,   -71,  -237,   -10,    49,   104,   232,  -237,
     299,  -237,   576,   153,     0,  -237,  -237,     0,   715,     0,
    -237,  -237,  -237,  -237,  -237,   501,  -237,   447,   346,   461,
     479,     0,  -237,  -237,  -237,  -237,  -237,  -237,   700,  -237,
    -237,   915,  -237,  -237,  -237,   -14,  1146,   954,  -237,     0,
       0,    87,  -237,  1664,     2,   959,    74,   842,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
       0,     0,     0,   -58,  -237,  -237,  -237,  -237,  -237,    46,
    3561,  -237,  1792,  -237,    51,  3561,    73,  -237,    70,  3561,
    3561,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  3561,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  3561,    90,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  3561,    47,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  1401,  -237,  -237,
    -237,  -237,   100,  3590,  -237,   105,   107,  1441,   121,   123,
     135,   147,   150,   160,    85,  -237,   112,  -237,   163,  -237,
     171,  -237,  -237,  -237,  -237,  -237,  1415,  -237,  -237,  -237,
    -237,   167,  3561,  -237,  1821,  1850,  1422,  3561,   169,  3561,
     187,  -237,   420,   185,  -237,  -237,   190,   192,   193,   194,
     202,   211,   212,   220,   221,   233,  1436,  -237,  -237,  -237,
    -237,   242,  3590,  -237,  1459,  -237,  -237,  -237,  -237,  3561,
    -237,  1495,  -237,  -237,  -237,  -237,  3561,  -237,  1879,   189,
    -237,   209,  -237,    44,   243,   262,  -237,  -237,   264,   266,
    -237,   274,   279,  -237,  3561,   281,   225,  -237,  3561,  3561,
     282,   258,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
       0,  -237,     0,  -237,  -237,  -237,  -237,  1908,  -237,  -237,
    1120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1632,     0,
    1650,     0,   149,    10,    12,   322,    25,    30,   672,   204,
     686,   323,  1937,   204,  1070,   204,   363,   290,  1084,   324,
     286,   340,   331,   344,   361,   334,   364,   385,   374,   391,
     392,   381,   397,   401,  1101,  1214,  1598,   404,   405,   406,
       0,   408,   426,   431,   423,   432,   436,  1966,    95,     0,
    1228,  1242,   176,  1269,   285,   313,     0,    18,   218,  1506,
     443,   456,   463,  1115,   449,   464,   472,   465,    33,    61,
    1647,   467,   473,   481,   470,   483,   485,   474,   350,   413,
       0,     0,     0,     0,     0,   477,   491,   494,   641,   484,
      68,    69,  3561,  3561,  -237,  -237,  3561,  3633,  3633,  3646,
    3646,   629,   629,   629,   629,   142,   142,   188,   188,  -237,
    -237,  3590,  3590,  3561,  -237,  3561,  3590,  -237,  3561,  3561,
    -237,     0,  -237,     0,  -237,  -237,     0,  -237,     0,  -237,
    1527,  -237,  -237,  -237,  -237,  3561,  -237,  -237,  1535,  -237,
    -237,  -237,  -237,  3561,  -237,   489,   490,  -237,  1564,  -237,
    -237,  -237,  -237,  3561,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  1595,  -237,  -237,  -237,  -237,  3561,
    -237,  -237,     0,     0,  -237,     0,     0,  -237,     0,     0,
    -237,     0,     0,  -237,     0,     0,  1603,  -237,  -237,  -237,
    -237,  3561,  -237,   283,  -237,   320,  -237,  -237,  -237,  -237,
    3561,  -237,     0,     0,   492,   504,   507,   508,     0,     0,
    3561,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  3561,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  3561,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  3561,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  3561,  -237,  -237,  3561,  1302,  -237,  -237,  -237,
    -237,  -237,  -237,  3561,  -237,  -237,  -237,     0,  3561,     0,
    -237,  3561,  -237,  -237,     0,     0,  1627,  -237,  -237,  -237,
    -237,  3561,  -237,  -237,     0,     0,  -237,     0,  -237,     0,
    -237,   328,  -237,  -237,     0,     0,  -237,     0,     0,   509,
    -237,  -237,  3561,  3561,  3561,  3561,  3561,  -237,     0,     0,
    1685,  3561,  -237,     0,  -237,     0,  -237,  1995,  2024,  2053,
    2082,   499,   519,   538,   529,   546,   547,    87,   382,   536,
      76,    82,   537,    92,   124,  2111,  2140,  2169,  2198,  2227,
    2256,  2285,  2314,  2343,  2372,   539,   555,   557,   552,   558,
     559,   553,   578,   579,  2401,  2430,  1288,   457,   468,   -22,
    2459,  2488,   577,   580,   582,  2517,   597,  2546,  2575,  2604,
    2633,   595,   612,   613,  2662,  2691,  2720,  2749,   602,   617,
     627,  2778,  2807,  2836,  2865,   330,  2894,  2923,   616,  2952,
    2981,  -237,  -237,  -237,  -237,  -237,     0,     0,  -237,     0,
       0,  -237,  -237,  -237,     0,  -237,     0,  -237,  -237,     0,
    -237,     0,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,     0,     0,  -237,     0,     0,  -237,
       0,     0,  -237,  -237,  3561,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,   603,   604,  -237,  -237,  -237,
    3618,     0,  3618,  3618,  -237,  -237,  -237,     0,     0,  -237,
    -237,  -237,  -237,  -237,     0,     0,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  3010,  3039,
    3068,  3097,  3126,  3155,  3184,  3213,  3242,  3271,  3300,  3329,
    3358,  3387,  1288,  1288,  3416,  3445,  3474,  3503,  3532,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  3561,  -237,  3561,  -237,  -237,  -237,  -237,
    -237,  -237
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     6,     0,     0,    79,     0,    94,    84,    85,
      87,    86,    88,    89,     0,    18,     0,     0,     0,     0,
       0,    78,    80,     0,    93,     0,     0,     0,     0,    95,
       0,    63,   316,     0,     0,    96,    83,     0,     0,     0,
      73,    75,    77,    74,    81,     0,    82,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    90,     0,    91,
      69,     0,    92,    70,    71,     0,     0,     0,    72,     0,
       0,     0,    76,     0,     0,     0,     0,     2,     3,     5,
      10,    23,    21,    20,    22,    24,    31,    32,    30,    41,
      36,    42,    39,    34,    43,    44,    45,    46,    37,    38,
      29,    47,    35,    48,    49,    50,    33,    51,    52,    53,
      54,    55,    56,    57,    58,    61,    59,    60,    62,    40,
       0,     0,     0,     0,   427,   426,   401,   424,   425,   100,
     400,   404,    98,   394,   101,   392,     0,   398,   102,   396,
      13,    14,    15,    27,    28,    11,    12,    17,    26,   452,
     450,   454,   455,   451,   456,   457,   453,   159,     0,   445,
     444,   442,   443,   310,   311,   309,    19,     0,   440,   441,
     438,   439,   179,   180,   181,   182,   183,   184,   429,   430,
     431,   432,   433,   434,   435,   172,   178,     0,   142,   143,
     144,   145,   429,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   330,     0,   357,     0,   361,
       0,   353,   307,   308,   306,   317,     0,   379,   380,   381,
     382,   429,   375,   374,     0,     0,     0,   207,     0,   185,
       0,   349,     0,     0,   436,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   292,   293,
     294,   429,   286,   287,     0,   370,   371,   372,   373,   366,
     365,     0,   168,   169,   170,   171,   161,   162,     0,     0,
     322,     0,   318,     0,     0,     0,   460,   458,     0,     0,
     459,     0,     0,   461,   213,     0,     0,   326,   334,   191,
       0,     0,   201,   202,   203,   204,   205,   206,   194,   195,
       0,     8,     0,     7,     1,     4,   407,     0,   405,   428,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     9,   406,   403,   402,   408,   409,   410,
     411,   419,   418,   421,   420,   413,   412,   414,   415,   416,
     417,   422,   423,    99,   395,   393,    97,   399,   397,   160,
     173,     0,   176,     0,   177,   137,     0,   140,     0,   141,
       0,   151,   152,   153,   154,   146,   147,   340,     0,   341,
     342,   343,   344,   336,   335,     0,     0,   110,     0,   111,
     112,   113,   114,   103,   104,   122,   126,   123,   124,   125,
     130,   127,   128,   129,     0,   131,   132,   133,   134,   115,
     116,   331,     0,     0,   358,     0,     0,   362,     0,     0,
     354,     0,     0,   376,     0,     0,     0,   388,   389,   390,
     391,   384,   383,     0,   158,     0,   345,   209,   210,   211,
     208,   350,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   256,   257,   258,   252,   253,   254,   255,   283,   263,
     264,   265,   259,   260,   261,   262,   281,   270,   271,   272,
     266,   267,   268,   269,   282,   277,   278,   279,   273,   274,
     275,   276,   280,   243,   241,   284,     0,   446,   447,   448,
     449,   242,   240,   220,   218,   250,   251,     0,   245,     0,
     248,   247,   249,   288,     0,     0,     0,   300,   301,   302,
     303,   295,   296,   367,     0,     0,   163,     0,   166,     0,
     167,     0,   312,   323,     0,     0,   319,     0,     0,     0,
     186,   187,   217,   216,   215,   214,   212,   327,     0,     0,
       0,   193,   196,     0,   199,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   175,   138,   139,   148,     0,     0,   337,     0,
       0,   305,   304,   105,     0,   108,     0,   109,   117,     0,
     120,     0,   121,   332,   333,   359,   360,   363,   364,   355,
     356,   377,   378,   385,     0,     0,   155,     0,     0,   346,
       0,     0,   351,   352,   225,   226,   223,   224,   235,   234,
     232,   233,   236,   237,   231,     0,     0,   222,   238,   239,
     219,     0,   244,   246,   289,   290,   297,     0,     0,   368,
     369,   164,   165,   313,     0,     0,   324,   325,   320,   321,
     188,   189,   190,   328,   329,   192,   197,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,   338,   339,   106,   107,   118,   119,   386,   387,   156,
     157,   347,   348,   227,   228,   229,   230,   221,   298,   299,
     314,   315
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -237,  -237,  -237,   554,   564,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,    -1,  -237,
      56,  -236,   -54,   611,  -237,  -237,   -34,  -237
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   144,   148,   139,   317,   141,
     195,   254,   196,   175,   595,   596,   168,   295
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   142,   145,   255,   149,   150,   388,   283,   225,   130,
     205,   214,   210,   158,   238,   167,   211,   212,   461,   146,
     463,   131,   132,   208,   176,   151,   203,   130,   152,   309,
     462,   133,   464,   466,   134,   153,   154,   135,   468,   586,
     132,   617,   232,   234,   157,   467,   235,   237,   239,   133,
     469,   310,   134,   618,   206,   135,   213,   262,   269,   276,
     278,   768,   769,   770,   771,   772,   773,   209,   284,   619,
     216,   207,   285,   130,   314,   294,   643,   645,   298,   299,
     319,   620,   320,   204,   734,   131,   132,   338,   644,   646,
     736,   215,   217,   219,   221,   133,   735,   339,   134,   233,
     739,   135,   737,   548,   549,   774,   340,   587,   588,   589,
     590,   241,   740,   253,   263,   270,   277,   188,   189,   190,
     191,   192,   193,   194,   280,   218,   341,   282,   417,   316,
     342,   318,   741,   297,   343,   344,   348,   300,   137,   308,
     138,   349,   130,   350,   742,   188,   189,   190,   191,   192,
     193,   194,   591,   592,   197,   132,   137,   353,   138,   354,
     331,   332,   130,   602,   133,   333,   334,   134,   359,   460,
     135,   355,   360,   361,   226,   132,   188,   189,   190,   191,
     192,   193,   194,   356,   133,   130,   357,   134,   169,   170,
     135,   171,   172,   173,   174,   362,   358,   131,   132,   363,
     364,   136,   137,   374,   138,   380,   352,   133,   155,   156,
     134,   333,   334,   135,   188,   189,   190,   191,   192,   193,
     194,   389,   198,   199,   200,   201,   390,   130,   391,   392,
     393,   188,   189,   190,   191,   192,   193,   194,   394,   597,
     132,   387,   227,   228,   229,   230,   365,   395,   396,   133,
     366,   367,   134,   220,   368,   135,   397,   398,   369,   370,
     202,   189,   190,   191,   192,   193,   194,   567,   568,   399,
     381,   137,   411,   138,   382,   383,   412,   413,   403,   418,
     231,   189,   190,   191,   192,   193,   194,   178,   179,   180,
     181,   137,   414,   138,   512,   477,   415,   416,   419,   487,
     420,   495,   421,   569,   570,   571,   572,   573,   425,   432,
     422,   433,   426,   427,   137,   423,   138,   424,   428,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   455,   456,   458,
     459,   429,   465,   485,   511,   430,   431,   475,   513,   483,
     696,   514,   515,   493,   517,   130,   137,   509,   138,   188,
     189,   190,   191,   192,   193,   194,   678,   256,   132,   516,
     679,   680,   518,   531,   500,   501,   502,   133,   503,   540,
     134,   169,   170,   135,   171,   172,   222,   223,   550,   558,
     566,   574,   582,   519,   520,   585,   593,   598,   601,   521,
     522,   523,   611,   681,   476,   524,   484,   682,   683,   525,
     494,   708,   583,   800,   510,   709,   710,   801,   802,   632,
     633,   634,   635,   636,   537,   538,   539,   641,   541,   130,
     532,   534,   536,   130,   542,   257,   258,   259,   260,   543,
     584,   131,   132,   544,   630,   131,   132,   496,   497,   498,
     499,   133,   545,   594,   134,   133,   546,   135,   134,   612,
     647,   135,   648,   603,   604,   649,   622,   650,   242,   613,
     130,   605,   614,   261,   189,   190,   191,   192,   193,   194,
     615,   624,   264,   132,   137,   616,   138,   623,   130,   625,
     626,   627,   133,   628,   629,   134,   631,   637,   135,   638,
     271,   132,   639,   384,   642,   385,   386,   244,   245,   732,
     133,   665,   666,   134,   667,   668,   135,   669,   670,   725,
     671,   672,   240,   673,   674,   657,   658,   726,   686,   243,
     178,   179,   180,   181,   244,   245,   246,   247,   248,   249,
     687,   684,   685,   688,   689,   715,   727,   690,   691,   728,
     265,   266,   267,   268,   729,   730,   733,   738,   137,   753,
     138,   143,   137,   754,   138,   755,   757,   758,   272,   273,
     274,   275,   756,   759,   188,   189,   190,   191,   192,   193,
     194,   250,   251,   252,   766,   695,   760,   761,   188,   189,
     190,   191,   192,   193,   194,   767,   697,   777,   698,   137,
     778,   138,   779,   699,   700,   781,   188,   189,   190,   191,
     192,   193,   194,   704,   705,   786,   706,   137,   707,   138,
     787,   788,   793,   711,   712,   794,   713,   714,   188,   189,
     190,   191,   192,   193,   194,   795,   805,   716,   717,   822,
     823,   315,   719,     0,   720,   329,   330,   331,   332,   313,
     130,   224,   333,   334,   130,     0,     0,     0,     0,     0,
       0,   130,   640,   132,     0,     0,   131,   132,     0,     0,
       0,     0,   133,   131,   132,   134,   133,     0,   135,   134,
       0,   130,   135,   133,     0,   764,   134,     0,     0,   135,
       0,     0,     0,   470,   132,   130,   159,   160,   161,   162,
     163,   164,   165,   133,     0,   166,   134,   478,   132,   135,
       0,     0,     0,   731,     0,     0,     0,   133,     0,     0,
     134,   279,     0,   135,   130,   808,   809,     0,   810,   811,
       0,     0,     0,   812,     0,   813,   236,   132,   814,     0,
     815,     0,   765,     0,     0,     0,   133,     0,     0,   134,
       0,     0,   135,   816,   817,     0,   818,   819,     0,   820,
     821,   471,   472,   473,   474,   159,   160,   161,   162,   163,
     164,   165,     0,     0,   166,   479,   480,   481,   482,   137,
     824,   138,     0,   137,     0,   138,   825,   826,     0,   147,
     137,     0,   138,   827,   828,     0,     0,     0,     0,   188,
     189,   190,   191,   192,   193,   194,     0,     0,     0,     0,
     137,     0,   138,   188,   189,   190,   191,   192,   193,   194,
       0,   843,   845,     0,   137,     0,   138,   188,   189,   190,
     191,   192,   193,   194,     0,   159,   160,   161,   162,   163,
     164,   165,     0,     0,   166,     1,     2,     3,     4,     5,
       0,     0,     0,   137,     0,   138,     0,     0,     0,     0,
       0,     0,   177,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,   844,   846,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,    58,   281,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     1,     2,     3,     4,     5,     0,   188,   189,
     190,   191,   192,   193,   194,   296,     0,     0,     0,     0,
      84,    85,     0,     0,     6,     7,     8,     9,    10,    11,
       0,   311,    13,     0,    14,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   312,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,   188,   189,   190,   191,   192,   193,   194,     0,
       0,     0,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,   130,
       0,   188,   189,   190,   191,   192,   193,   194,     0,     0,
       0,   488,   132,   130,     0,     0,     0,    84,     0,     0,
       0,   133,     0,     0,   134,   504,   132,   135,     0,     0,
     130,     0,     0,     0,     0,   133,     0,     0,   134,     0,
       0,   135,   526,   132,   130,     0,     0,     0,     0,   130,
       0,     0,   133,     0,     0,   134,   606,   132,   135,     0,
       0,   131,   132,     0,     0,     0,   133,     0,     0,   134,
       0,   133,   135,     0,   134,   130,     0,   135,     0,   489,
     490,   491,   492,     0,     0,     0,     0,   131,   132,     0,
       0,     0,     0,   505,   506,   507,   508,   133,     0,     0,
     134,     0,     0,   135,     0,     0,     0,     0,     0,     0,
     527,   528,   529,   530,     0,     0,     0,   188,   189,   190,
     191,   192,   193,   194,   607,   608,   609,   610,   137,     0,
     138,   188,   189,   190,   191,   192,   193,   194,     0,     0,
       0,     0,   137,     0,   138,     0,     0,     0,   188,   189,
     190,   191,   192,   193,   194,   533,     0,   130,     0,   137,
       0,   138,   188,   189,   190,   191,   192,   193,   194,   131,
     132,   130,     0,   137,     0,   138,     0,   435,   137,   133,
     138,     0,   134,   131,   132,   135,   286,   287,   288,   289,
     290,   291,   292,   133,     0,   293,   134,     0,   130,   135,
       0,     0,     0,     0,   137,     0,   138,     0,     0,     0,
     131,   132,     0,     0,     0,     0,     0,   130,     0,     0,
     133,     0,     0,   134,     0,     0,   135,     0,     0,   131,
     132,   130,     0,     0,     0,     0,     0,   551,   552,   133,
       0,     0,   134,   131,   132,   135,     0,     0,     0,     0,
       0,   559,   560,   133,     0,     0,   134,     0,     0,   135,
       0,   188,   189,   190,   191,   192,   193,   194,     0,     0,
       0,     0,     0,     0,     0,   553,   554,   555,   556,   557,
     575,   576,     0,     0,     0,     0,   137,     0,   138,   561,
     562,   563,   564,   565,     0,     0,     0,     0,     0,     0,
     137,     0,   138,     0,     0,   692,     0,   693,   694,   244,
     245,     0,     0,     0,     0,     0,   577,   578,   579,   580,
     581,     0,     0,     0,     0,     0,     0,   137,     0,   138,
     130,     0,     0,     0,     0,   188,   189,   190,   191,   192,
     193,   194,   131,   132,   130,     0,   137,     0,   138,     0,
       0,   130,   133,     0,     0,   134,   131,   132,   135,     0,
     137,     0,   138,   131,   132,   130,   133,     0,     0,   134,
     130,     0,   135,   133,     0,     0,   134,   131,   132,   135,
       0,     0,   131,   132,     0,     0,     0,   133,   130,     0,
     134,     0,   133,   135,     0,   134,     0,     0,   135,     0,
     131,   132,     0,     0,   345,     0,     0,     0,   346,   347,
     133,     0,     0,   134,     0,     0,   135,     0,   371,     0,
       0,     0,   372,   373,   130,   377,     0,     0,     0,   378,
     379,     0,     0,     0,     0,   130,   131,   132,     0,   400,
       0,     0,     0,   401,   402,     0,   133,   599,   132,   134,
       0,     0,   135,     0,     0,     0,   130,   133,     0,   137,
     134,   138,   404,   135,   130,     0,   405,   406,   131,   132,
       0,     0,     0,   137,     0,   138,   131,   132,   133,     0,
     137,   134,   138,     0,   135,     0,   133,     0,     0,   134,
     351,     0,   135,   130,   137,     0,   138,     0,   407,   137,
       0,   138,   408,   409,     0,   131,   132,     0,     0,   600,
       0,     0,     0,   244,   245,   133,     0,   137,   134,   138,
       0,   135,     0,     0,   130,     0,     0,     0,     0,     0,
     651,     0,   130,     0,   652,   653,   131,   132,   654,   535,
       0,     0,   655,   656,   131,   132,   133,     0,     0,   134,
       0,     0,   135,   137,   133,   138,   130,   134,     0,     0,
     135,   130,     0,     0,   137,     0,   138,   659,   131,   132,
       0,   660,   661,   131,   132,     0,     0,     0,   133,   130,
       0,   134,     0,   133,   135,   137,   134,   138,   621,   135,
       0,   131,   132,   137,     0,   138,     0,     0,   662,     0,
       0,   133,   663,   664,   134,   301,   675,   135,     0,     0,
     676,   677,     0,     0,   130,     0,     0,     0,     0,     0,
       0,     0,   137,     0,   138,     0,   131,   132,     0,     0,
     701,     0,     0,     0,   702,   703,   133,     0,     0,   134,
       0,     0,   135,     0,     0,   188,   189,   190,   191,   192,
     193,   194,     0,   137,     0,   138,     0,     0,     0,     0,
       0,   137,     0,   138,     0,     0,     0,   178,   179,   180,
     181,   302,   303,   304,   305,   306,   307,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,   138,     0,   454,
     137,     0,   138,     0,   188,   189,   190,   191,   192,   193,
     194,     0,     0,     0,     0,     0,     0,   457,   137,     0,
     138,   188,   189,   190,   191,   192,   193,   194,     0,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,     0,     0,   718,   333,   334,     0,     0,     0,
       0,     0,     0,   137,     0,   138,     0,     0,   337,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,     0,     0,   335,   333,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   375,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
       0,     0,   335,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,   376,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,     0,
       0,   335,   333,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,   410,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   434,     0,
     335,   333,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   486,     0,   335,
     333,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   547,     0,   335,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   721,     0,   335,   333,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   722,     0,   335,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   723,     0,   335,   333,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   724,     0,   335,   333,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   743,     0,   335,   333,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     744,     0,   335,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   745,
       0,   335,   333,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   746,     0,
     335,   333,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   747,     0,   335,
     333,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   748,     0,   335,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   749,     0,   335,   333,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   750,     0,   335,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   751,     0,   335,   333,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   752,     0,   335,   333,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   762,     0,   335,   333,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     763,     0,   335,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   775,
       0,   335,   333,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   776,     0,
     335,   333,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   780,     0,   335,
     333,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   782,     0,   335,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   783,     0,   335,   333,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   784,     0,   335,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   785,     0,   335,   333,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   789,     0,   335,   333,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   790,     0,   335,   333,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     791,     0,   335,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   792,
       0,   335,   333,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   796,     0,
     335,   333,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   797,     0,   335,
     333,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   798,     0,   335,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   799,     0,   335,   333,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   803,     0,   335,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   804,     0,   335,   333,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   806,     0,   335,   333,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   807,     0,   335,   333,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     829,     0,   335,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   830,
       0,   335,   333,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   831,     0,
     335,   333,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   832,     0,   335,
     333,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   833,     0,   335,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   834,     0,   335,   333,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   835,     0,   335,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   836,     0,   335,   333,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   837,     0,   335,   333,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   838,     0,   335,   333,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     839,     0,   335,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   840,
       0,   335,   333,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   841,     0,
     335,   333,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   842,     0,   335,
     333,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   847,     0,   335,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   848,     0,   335,   333,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   849,     0,   335,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   850,     0,   335,   333,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   851,     0,   335,   333,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,     0,     0,   335,   333,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
       0,     0,   335,   333,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   336,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,     0,     0,
       0,  -406,  -406,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,     0,   336,     0,   333,   334,   325,   326,
     327,   328,   329,   330,   331,   332,     0,     0,     0,   333,
     334
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    57,     5,     6,   242,    21,    42,     9,
      83,    21,    83,    14,    48,    16,    87,    88,     8,   138,
       8,    21,    22,    83,    25,   138,    27,     9,   138,    83,
      20,    31,    20,     8,    34,   137,   138,    37,     8,    21,
      22,     8,    43,    44,   137,    20,    47,    48,    49,    31,
      20,    49,    34,    20,   127,    37,   127,    58,    59,    60,
      61,    83,    84,    85,    86,    87,    88,   127,    82,     8,
      21,    21,    86,     9,     0,    76,     8,     8,    79,    80,
     138,    20,    36,    27,     8,    21,    22,    36,    20,    20,
       8,    35,    36,    37,    38,    31,    20,    24,    34,    43,
       8,    37,    20,     8,     9,   127,    36,    89,    90,    91,
      92,    55,    20,    57,    58,    59,    60,   127,   128,   129,
     130,   131,   132,   133,    68,    21,    36,    71,    84,   130,
      83,   132,     8,    77,    87,    88,    36,    81,   138,    83,
     140,    36,     9,    36,    20,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    21,    22,   138,    36,   140,    36,
      18,    19,     9,   399,    31,    23,    24,    34,    83,    20,
      37,    36,    87,    88,    21,    22,   127,   128,   129,   130,
     131,   132,   133,    36,    31,     9,    36,    34,    82,    83,
      37,    85,    86,    87,    88,    83,    36,    21,    22,    87,
      88,   137,   138,    36,   140,    36,   207,    31,   137,   138,
      34,    23,    24,    37,   127,   128,   129,   130,   131,   132,
     133,    36,    89,    90,    91,    92,    36,     9,    36,    36,
      36,   127,   128,   129,   130,   131,   132,   133,    36,    21,
      22,   242,    89,    90,    91,    92,    83,    36,    36,    31,
      87,    88,    34,    21,    83,    37,    36,    36,    87,    88,
     127,   128,   129,   130,   131,   132,   133,    91,    92,    36,
      83,   138,    83,   140,    87,    88,    87,    88,    36,    36,
     127,   128,   129,   130,   131,   132,   133,    83,    84,    85,
      86,   138,    83,   140,     8,   349,    87,    88,    36,   353,
      36,   355,    36,   127,   128,   129,   130,   131,    83,   310,
      36,   312,    87,    88,   138,    36,   140,    36,    36,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,    83,    20,    20,    20,    87,    88,   348,     8,   350,
     586,    20,     8,   354,    20,     9,   138,   358,   140,   127,
     128,   129,   130,   131,   132,   133,    83,    21,    22,     8,
      87,    88,     8,   374,    84,    85,    86,    31,    88,   380,
      34,    82,    83,    37,    85,    86,    87,    88,   389,   390,
     391,   392,   393,     8,    20,   396,   397,   398,   399,     8,
       8,    20,   403,    83,   348,     8,   350,    87,    88,     8,
     354,    83,   127,    83,   358,    87,    88,    87,    88,   420,
     421,   422,   423,   424,    20,    20,    20,   428,    20,     9,
     374,   375,   376,     9,     8,    89,    90,    91,    92,     8,
     127,    21,    22,    20,    94,    21,    22,    84,    85,    86,
      87,    31,    20,   397,    34,    31,    20,    37,    34,   403,
     461,    37,   463,    20,     8,   466,   410,   468,    21,    20,
       9,     8,     8,   127,   128,   129,   130,   131,   132,   133,
       8,     8,    21,    22,   138,    20,   140,    20,     9,     8,
      20,     8,    31,     8,    20,    34,    83,    20,    37,     8,
      21,    22,     8,    83,    20,    85,    86,    87,    88,   127,
      31,   512,   513,    34,   515,   516,    37,   518,   519,    20,
     521,   522,    21,   524,   525,    36,    36,     8,    36,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      36,   542,   543,    36,    36,    36,     8,   548,   549,    20,
      89,    90,    91,    92,     8,     8,    20,    20,   138,    20,
     140,   137,   138,     8,   140,     8,     8,     8,    89,    90,
      91,    92,    20,    20,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   127,   586,     8,     8,   127,   128,
     129,   130,   131,   132,   133,   127,   597,    20,   599,   138,
      20,   140,    20,   604,   605,     8,   127,   128,   129,   130,
     131,   132,   133,   614,   615,    20,   617,   138,   619,   140,
       8,     8,    20,   624,   625,     8,   627,   628,   127,   128,
     129,   130,   131,   132,   133,     8,    20,   638,   639,    36,
      36,    87,   643,    -1,   645,    16,    17,    18,    19,    85,
       9,    40,    23,    24,     9,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    21,    22,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    31,    21,    22,    34,    31,    -1,    37,    34,
      -1,     9,    37,    31,    -1,   686,    34,    -1,    -1,    37,
      -1,    -1,    -1,    21,    22,     9,   120,   121,   122,   123,
     124,   125,   126,    31,    -1,   129,    34,    21,    22,    37,
      -1,    -1,    -1,   657,    -1,    -1,    -1,    31,    -1,    -1,
      34,    21,    -1,    37,     9,   726,   727,    -1,   729,   730,
      -1,    -1,    -1,   734,    -1,   736,    21,    22,   739,    -1,
     741,    -1,   686,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    37,   754,   755,    -1,   757,   758,    -1,   760,
     761,    89,    90,    91,    92,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,   129,    89,    90,    91,    92,   138,
     781,   140,    -1,   138,    -1,   140,   787,   788,    -1,   137,
     138,    -1,   140,   794,   795,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,   140,   127,   128,   129,   130,   131,   132,   133,
      -1,   822,   823,    -1,   138,    -1,   140,   127,   128,   129,
     130,   131,   132,   133,    -1,   120,   121,   122,   123,   124,
     125,   126,    -1,    -1,   129,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    -1,    35,   822,   823,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    93,    21,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     3,     4,     5,     6,     7,    -1,   127,   128,
     129,   130,   131,   132,   133,    21,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    93,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     9,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    21,    22,     9,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    31,    -1,    -1,    34,    21,    22,    37,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    37,    21,    22,     9,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    31,    -1,    -1,    34,    21,    22,    37,    -1,
      -1,    21,    22,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    31,    37,    -1,    34,     9,    -1,    37,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    31,    -1,    -1,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    -1,    -1,    -1,   127,   128,   129,
     130,   131,   132,   133,    89,    90,    91,    92,   138,    -1,
     140,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,   140,    -1,    -1,    -1,   127,   128,
     129,   130,   131,   132,   133,    21,    -1,     9,    -1,   138,
      -1,   140,   127,   128,   129,   130,   131,   132,   133,    21,
      22,     9,    -1,   138,    -1,   140,    -1,   137,   138,    31,
     140,    -1,    34,    21,    22,    37,   120,   121,   122,   123,
     124,   125,   126,    31,    -1,   129,    34,    -1,     9,    37,
      -1,    -1,    -1,    -1,   138,    -1,   140,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      31,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    21,
      22,     9,    -1,    -1,    -1,    -1,    -1,    89,    90,    31,
      -1,    -1,    34,    21,    22,    37,    -1,    -1,    -1,    -1,
      -1,    89,    90,    31,    -1,    -1,    34,    -1,    -1,    37,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      91,    92,    -1,    -1,    -1,    -1,   138,    -1,   140,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
       9,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
     132,   133,    21,    22,     9,    -1,   138,    -1,   140,    -1,
      -1,     9,    31,    -1,    -1,    34,    21,    22,    37,    -1,
     138,    -1,   140,    21,    22,     9,    31,    -1,    -1,    34,
       9,    -1,    37,    31,    -1,    -1,    34,    21,    22,    37,
      -1,    -1,    21,    22,    -1,    -1,    -1,    31,     9,    -1,
      34,    -1,    31,    37,    -1,    34,    -1,    -1,    37,    -1,
      21,    22,    -1,    -1,    83,    -1,    -1,    -1,    87,    88,
      31,    -1,    -1,    34,    -1,    -1,    37,    -1,    83,    -1,
      -1,    -1,    87,    88,     9,    83,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,     9,    21,    22,    -1,    83,
      -1,    -1,    -1,    87,    88,    -1,    31,    21,    22,    34,
      -1,    -1,    37,    -1,    -1,    -1,     9,    31,    -1,   138,
      34,   140,    83,    37,     9,    -1,    87,    88,    21,    22,
      -1,    -1,    -1,   138,    -1,   140,    21,    22,    31,    -1,
     138,    34,   140,    -1,    37,    -1,    31,    -1,    -1,    34,
     129,    -1,    37,     9,   138,    -1,   140,    -1,    83,   138,
      -1,   140,    87,    88,    -1,    21,    22,    -1,    -1,    83,
      -1,    -1,    -1,    87,    88,    31,    -1,   138,    34,   140,
      -1,    37,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      83,    -1,     9,    -1,    87,    88,    21,    22,    83,    21,
      -1,    -1,    87,    88,    21,    22,    31,    -1,    -1,    34,
      -1,    -1,    37,   138,    31,   140,     9,    34,    -1,    -1,
      37,     9,    -1,    -1,   138,    -1,   140,    83,    21,    22,
      -1,    87,    88,    21,    22,    -1,    -1,    -1,    31,     9,
      -1,    34,    -1,    31,    37,   138,    34,   140,    21,    37,
      -1,    21,    22,   138,    -1,   140,    -1,    -1,    83,    -1,
      -1,    31,    87,    88,    34,    21,    83,    37,    -1,    -1,
      87,    88,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,    -1,    21,    22,    -1,    -1,
      83,    -1,    -1,    -1,    87,    88,    31,    -1,    -1,    34,
      -1,    -1,    37,    -1,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,   140,    -1,   137,
     138,    -1,   140,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    -1,
     140,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,   129,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,   140,    -1,    -1,    36,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    36,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    36,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    51,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    51,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    51,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    51,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    51,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    51,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    51,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    51,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    51,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    51,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    51,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    51,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    51,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    51,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    51,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    51,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    51,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    51,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    51,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    51,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    51,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    51,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    51,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    51,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    51,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      51,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    51,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    51,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    51,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    51,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    51,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    51,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    51,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    23,    24,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    93,    -1,    23,    24,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    25,    26,    27,    28,
      29,    30,    32,    33,    35,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    93,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   138,   139,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       9,    21,    22,    31,    34,    37,   137,   138,   140,   191,
     192,   193,   192,   137,   189,   192,   138,   137,   190,   192,
     192,   138,   138,   137,   138,   137,   138,   137,   192,   120,
     121,   122,   123,   124,   125,   126,   129,   192,   200,    82,
      83,    85,    86,    87,    88,   197,   192,    21,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   127,   128,
     129,   130,   131,   132,   133,   194,   196,    21,    89,    90,
      91,    92,   127,   192,   194,    83,   127,    21,    83,   127,
      83,    87,    88,   127,    21,   194,    21,   194,    21,   194,
      21,   194,    87,    88,   197,   200,    21,    89,    90,    91,
      92,   127,   192,   194,   192,   192,    21,   192,   200,   192,
      21,   194,    21,    82,    87,    88,    89,    90,    91,    92,
     134,   135,   136,   194,   195,   196,    21,    89,    90,    91,
      92,   127,   192,   194,    21,    89,    90,    91,    92,   192,
     194,    21,    89,    90,    91,    92,   192,   194,   192,    21,
     194,    21,   194,    21,    82,    86,   120,   121,   122,   123,
     124,   125,   126,   129,   192,   201,    21,   194,   192,   192,
     194,    21,    87,    88,    89,    90,    91,    92,   194,   196,
      49,    32,    49,   148,     0,   147,   192,   192,   192,   138,
      36,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    23,    24,    51,    93,    36,    36,    24,
      36,    36,    83,    87,    88,    83,    87,    88,    36,    36,
      36,   129,   192,    36,    36,    36,    36,    36,    36,    83,
      87,    88,    83,    87,    88,    83,    87,    88,    83,    87,
      88,    83,    87,    88,    36,    36,    36,    83,    87,    88,
      36,    83,    87,    88,    83,    85,    86,   192,   195,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      83,    87,    88,    36,    83,    87,    88,    83,    87,    88,
      36,    83,    87,    88,    83,    87,    88,    84,    36,    36,
      36,    36,    36,    36,    36,    83,    87,    88,    36,    83,
      87,    88,   192,   192,    20,   137,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   137,   192,   192,   137,   192,   192,
      20,     8,    20,     8,    20,    20,     8,    20,     8,    20,
      21,    89,    90,    91,    92,   192,   194,   196,    21,    89,
      90,    91,    92,   192,   194,    20,    20,   196,    21,    89,
      90,    91,    92,   192,   194,   196,    84,    85,    86,    87,
      84,    85,    86,    88,    21,    89,    90,    91,    92,   192,
     194,    20,     8,     8,    20,     8,     8,    20,     8,     8,
      20,     8,     8,    20,     8,     8,    21,    89,    90,    91,
      92,   192,   194,    21,   194,    21,   194,    20,    20,    20,
     192,    20,     8,     8,    20,    20,    20,    20,     8,     9,
     192,    89,    90,   127,   128,   129,   130,   131,   192,    89,
      90,   127,   128,   129,   130,   131,   192,    91,    92,   127,
     128,   129,   130,   131,   192,    91,    92,   127,   128,   129,
     130,   131,   192,   127,   127,   192,    21,    89,    90,    91,
      92,   134,   135,   192,   194,   198,   199,    21,   192,    21,
      83,   192,   195,    20,     8,     8,    21,    89,    90,    91,
      92,   192,   194,    20,     8,     8,    20,     8,    20,     8,
      20,    21,   194,    20,     8,     8,    20,     8,     8,    20,
      94,    83,   192,   192,   192,   192,   192,    20,     8,     8,
      21,   192,    20,     8,    20,     8,    20,   192,   192,   192,
     192,    83,    87,    88,    83,    87,    88,    36,    36,    83,
      87,    88,    83,    87,    88,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,    83,    87,    88,    83,    87,
      88,    83,    87,    88,   192,   192,    36,    36,    36,    36,
     192,   192,    83,    85,    86,   192,   195,   192,   192,   192,
     192,    83,    87,    88,   192,   192,   192,   192,    83,    87,
      88,   192,   192,   192,   192,    36,   192,   192,   129,   192,
     192,    20,    20,    20,    20,    20,     8,     8,    20,     8,
       8,   194,   127,    20,     8,    20,     8,    20,    20,     8,
      20,     8,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,     8,     8,    20,     8,     8,    20,
       8,     8,    20,    20,   192,   194,   127,   127,    83,    84,
      85,    86,    87,    88,   127,    20,    20,    20,    20,    20,
      20,     8,    20,    20,    20,    20,    20,     8,     8,    20,
      20,    20,    20,    20,     8,     8,    20,    20,    20,    20,
      83,    87,    88,    20,    20,    20,    20,    20,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,    36,    36,   192,   192,   192,   192,   192,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,   192,   194,   192,   194,    20,    20,    20,
      20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   144,   145,   146,   146,   147,   147,   147,   147,   147,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   151,   151,
     152,   153,   154,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   158,   158,   158,   158,   159,
     159,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   162,   163,   163,   163,   163,
     163,   164,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   167,   167,   167,
     167,   167,   168,   168,   168,   168,   168,   168,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   171,   171,   172,   172,   172,   173,
     173,   173,   174,   174,   174,   174,   175,   175,   176,   176,
     176,   176,   177,   177,   177,   177,   178,   178,   178,   178,
     179,   179,   179,   179,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   182,   182,   182,   182,   183,
     183,   183,   183,   184,   184,   184,   184,   185,   185,   185,
     185,   186,   186,   186,   186,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   189,   189,   189,   189,   190,   190,   190,   190,
     191,   191,   191,   191,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   193,   193,   193,   193,   193,   194,
     194,   194,   194,   194,   194,   194,   195,   195,   196,   196,
     196,   196,   197,   197,   197,   197,   198,   198,   199,   199,
     200,   200,   200,   200,   200,   200,   200,   200,   201,   201,
     201,   201
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     2,     3,
       1,     2,     2,     2,     2,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     4,
       2,     2,     2,     4,     4,     6,     8,     8,     6,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     8,     8,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     2,     4,     6,     6,
       4,     4,     2,     2,     2,     2,     4,     4,     6,     8,
       8,     4,     4,     4,     4,     6,     8,     8,     4,     2,
       4,     2,     2,     4,     6,     6,     4,     4,     2,     2,
       2,     2,     2,     4,     6,     6,     4,     4,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     4,     6,     6,
       6,     2,     6,     4,     2,     2,     4,     6,     6,     4,
       4,     2,     2,     2,     2,     2,     2,     2,     4,     4,
       4,     4,     4,     2,     4,     4,     4,     4,     4,     6,
       4,     8,     6,     6,     6,     6,     6,     8,     8,     8,
       8,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       4,     4,     4,     4,     6,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     2,     4,     6,
       6,     2,     2,     2,     2,     4,     4,     6,     8,     8,
       4,     4,     4,     4,     6,     6,     2,     2,     2,     2,
       2,     2,     4,     6,     8,     8,     1,     2,     2,     4,
       6,     6,     2,     4,     6,     6,     2,     4,     6,     6,
       2,     4,     6,     6,     2,     4,     4,     6,     8,     8,
       4,     4,     4,     4,     4,     4,     6,     8,     8,     2,
       4,     6,     6,     2,     4,     6,     6,     2,     4,     6,
       6,     2,     4,     6,     6,     2,     2,     4,     6,     6,
       2,     2,     2,     2,     2,     2,     4,     6,     6,     2,
       2,     2,     2,     4,     4,     6,     8,     8,     4,     4,
       4,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 200 "grammar.y"
                     {  }
#line 2827 "grammar.c"
    break;

  case 3:
#line 202 "grammar.y"
                         {  yylineno++; }
#line 2833 "grammar.c"
    break;

  case 4:
#line 203 "grammar.y"
                                     {  yylineno++; }
#line 2839 "grammar.c"
    break;

  case 5:
#line 205 "grammar.y"
                                                { prepc = pc; }
#line 2845 "grammar.c"
    break;

  case 6:
#line 206 "grammar.y"
                                                { prepc = pc; }
#line 2851 "grammar.c"
    break;

  case 7:
#line 207 "grammar.y"
                                        { setLabelAddress((yyvsp[-1].literal),prepc); prepc = pc;}
#line 2857 "grammar.c"
    break;

  case 8:
#line 208 "grammar.y"
                                        { setLabelAddress((yyvsp[-1].literal),prepc); prepc = pc;}
#line 2863 "grammar.c"
    break;

  case 9:
#line 209 "grammar.y"
                                        { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal));  }
#line 2869 "grammar.c"
    break;

  case 10:
#line 212 "grammar.y"
                                                { }
#line 2875 "grammar.c"
    break;

  case 11:
#line 213 "grammar.y"
                                                        {  includebin((yyvsp[0].literal));  }
#line 2881 "grammar.c"
    break;

  case 12:
#line 214 "grammar.y"
                                                        {  includebin((yyvsp[0].literal));  }
#line 2887 "grammar.c"
    break;

  case 13:
#line 215 "grammar.y"
                                                                        { condStatus = ((yyvsp[0].normal)==0)?0:1; }
#line 2893 "grammar.c"
    break;

  case 14:
#line 216 "grammar.y"
                                                                { condStatus = (LookupTableLabels((yyvsp[0].literal))<0)?0:1; }
#line 2899 "grammar.c"
    break;

  case 15:
#line 217 "grammar.y"
                                                                { condStatus = (LookupTableLabels((yyvsp[0].literal))<0)?1:0; }
#line 2905 "grammar.c"
    break;

  case 16:
#line 218 "grammar.y"
                                                                        { if (condStatus < 0) { fatalError("Syntax error. Detected ENDIF without IF"); } condStatus = -1; }
#line 2911 "grammar.c"
    break;

  case 17:
#line 219 "grammar.y"
                                                                {  fprintf(stderr,">>DIRECTIVE ERROR in line: %d ::: %s\n",yylineno,(yyvsp[0].literal)); exit(EXIT_FAILURE); }
#line 2917 "grammar.c"
    break;

  case 18:
#line 220 "grammar.y"
                                                { return 0; /* we should stop here compilation */}
#line 2923 "grammar.c"
    break;

  case 19:
#line 221 "grammar.y"
                                                        { return 0; /* MISSING, in order to allow entry point definition */ }
#line 2929 "grammar.c"
    break;

  case 20:
#line 222 "grammar.y"
                                                { }
#line 2935 "grammar.c"
    break;

  case 21:
#line 223 "grammar.y"
                                                { }
#line 2941 "grammar.c"
    break;

  case 22:
#line 224 "grammar.y"
                                                { }
#line 2947 "grammar.c"
    break;

  case 23:
#line 225 "grammar.y"
                                                { }
#line 2953 "grammar.c"
    break;

  case 24:
#line 226 "grammar.y"
                                                { }
#line 2959 "grammar.c"
    break;

  case 25:
#line 227 "grammar.y"
                                                                { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal));  }
#line 2965 "grammar.c"
    break;

  case 26:
#line 228 "grammar.y"
                                                { int k = (((pc/(yyvsp[0].normal))+1)*(yyvsp[0].normal)); for(int a=pc; a < k; a++) { outCode(1,0x0); } }
#line 2971 "grammar.c"
    break;

  case 27:
#line 229 "grammar.y"
                                                { warningError("Include feature has not yet being implemented. Ignoring this line"); }
#line 2977 "grammar.c"
    break;

  case 28:
#line 230 "grammar.y"
                                                                { warningError("Include feature has not yet being implemented. Ignoring this line"); }
#line 2983 "grammar.c"
    break;

  case 29:
#line 232 "grammar.y"
                                    {  }
#line 2989 "grammar.c"
    break;

  case 30:
#line 233 "grammar.y"
                                    {  }
#line 2995 "grammar.c"
    break;

  case 31:
#line 234 "grammar.y"
                                    {  }
#line 3001 "grammar.c"
    break;

  case 32:
#line 235 "grammar.y"
                                    {  }
#line 3007 "grammar.c"
    break;

  case 33:
#line 236 "grammar.y"
                                    {  }
#line 3013 "grammar.c"
    break;

  case 34:
#line 237 "grammar.y"
                                    {  }
#line 3019 "grammar.c"
    break;

  case 35:
#line 238 "grammar.y"
                                    {  }
#line 3025 "grammar.c"
    break;

  case 36:
#line 239 "grammar.y"
                                {  }
#line 3031 "grammar.c"
    break;

  case 37:
#line 240 "grammar.y"
                                {  }
#line 3037 "grammar.c"
    break;

  case 38:
#line 241 "grammar.y"
                                {  }
#line 3043 "grammar.c"
    break;

  case 39:
#line 242 "grammar.y"
                                {  }
#line 3049 "grammar.c"
    break;

  case 40:
#line 243 "grammar.y"
                                {  }
#line 3055 "grammar.c"
    break;

  case 41:
#line 244 "grammar.y"
                                {  }
#line 3061 "grammar.c"
    break;

  case 42:
#line 245 "grammar.y"
                                {  }
#line 3067 "grammar.c"
    break;

  case 43:
#line 246 "grammar.y"
                                {  }
#line 3073 "grammar.c"
    break;

  case 44:
#line 247 "grammar.y"
                                {  }
#line 3079 "grammar.c"
    break;

  case 45:
#line 248 "grammar.y"
                                {  }
#line 3085 "grammar.c"
    break;

  case 46:
#line 249 "grammar.y"
                                {  }
#line 3091 "grammar.c"
    break;

  case 47:
#line 250 "grammar.y"
                                {  }
#line 3097 "grammar.c"
    break;

  case 48:
#line 251 "grammar.y"
                                {  }
#line 3103 "grammar.c"
    break;

  case 49:
#line 252 "grammar.y"
                                {  }
#line 3109 "grammar.c"
    break;

  case 50:
#line 253 "grammar.y"
                                {  }
#line 3115 "grammar.c"
    break;

  case 51:
#line 254 "grammar.y"
                                {  }
#line 3121 "grammar.c"
    break;

  case 52:
#line 255 "grammar.y"
                                {  }
#line 3127 "grammar.c"
    break;

  case 53:
#line 256 "grammar.y"
                                {  }
#line 3133 "grammar.c"
    break;

  case 54:
#line 257 "grammar.y"
                                {  }
#line 3139 "grammar.c"
    break;

  case 55:
#line 258 "grammar.y"
                                {  }
#line 3145 "grammar.c"
    break;

  case 56:
#line 259 "grammar.y"
                                {  }
#line 3151 "grammar.c"
    break;

  case 57:
#line 260 "grammar.y"
                                {  }
#line 3157 "grammar.c"
    break;

  case 58:
#line 261 "grammar.y"
                                {  }
#line 3163 "grammar.c"
    break;

  case 59:
#line 262 "grammar.y"
                                {  }
#line 3169 "grammar.c"
    break;

  case 60:
#line 263 "grammar.y"
                                {  }
#line 3175 "grammar.c"
    break;

  case 61:
#line 264 "grammar.y"
                                {  }
#line 3181 "grammar.c"
    break;

  case 62:
#line 265 "grammar.y"
                                {  }
#line 3187 "grammar.c"
    break;

  case 63:
#line 266 "grammar.y"
                                { outCode(1,0x3F); }
#line 3193 "grammar.c"
    break;

  case 64:
#line 267 "grammar.y"
                                { outCode(2,0xED,0xA9); }
#line 3199 "grammar.c"
    break;

  case 65:
#line 268 "grammar.y"
                                { outCode(2,0xED,0xB9); }
#line 3205 "grammar.c"
    break;

  case 66:
#line 269 "grammar.y"
                                { outCode(2,0xED,0xA1); }
#line 3211 "grammar.c"
    break;

  case 67:
#line 270 "grammar.y"
                                { outCode(2,0xED,0xB1); }
#line 3217 "grammar.c"
    break;

  case 68:
#line 271 "grammar.y"
                                { outCode(1,0x2F); }
#line 3223 "grammar.c"
    break;

  case 69:
#line 272 "grammar.y"
                                { outCode(1,0x27); }
#line 3229 "grammar.c"
    break;

  case 70:
#line 273 "grammar.y"
                                { outCode(1,0xF3); }
#line 3235 "grammar.c"
    break;

  case 71:
#line 274 "grammar.y"
                                { outCode(1,0xFB); }
#line 3241 "grammar.c"
    break;

  case 72:
#line 275 "grammar.y"
                                { outCode(1,0xD9); }
#line 3247 "grammar.c"
    break;

  case 73:
#line 276 "grammar.y"
                                { outCode(1,0x76); }
#line 3253 "grammar.c"
    break;

  case 74:
#line 277 "grammar.y"
                                { outCode(2,0xED,0xAA); }
#line 3259 "grammar.c"
    break;

  case 75:
#line 278 "grammar.y"
                                { outCode(2,0xED,0xBA); }
#line 3265 "grammar.c"
    break;

  case 76:
#line 279 "grammar.y"
                                { outCode(2,0xED,0xA2); }
#line 3271 "grammar.c"
    break;

  case 77:
#line 280 "grammar.y"
                                { outCode(2,0xED,0xB2); }
#line 3277 "grammar.c"
    break;

  case 78:
#line 281 "grammar.y"
                                    { outCode(2,0xED,0xA8); }
#line 3283 "grammar.c"
    break;

  case 79:
#line 282 "grammar.y"
                                    { outCode(2,0xED,0xB8); }
#line 3289 "grammar.c"
    break;

  case 80:
#line 283 "grammar.y"
                                    { outCode(2,0xED,0xA0); }
#line 3295 "grammar.c"
    break;

  case 81:
#line 284 "grammar.y"
                                    { outCode(2,0xED,0xB0); }
#line 3301 "grammar.c"
    break;

  case 82:
#line 285 "grammar.y"
                                    { outCode(2,0xED,0x44); }
#line 3307 "grammar.c"
    break;

  case 83:
#line 286 "grammar.y"
                                    { outCode(1,0x00);      }
#line 3313 "grammar.c"
    break;

  case 84:
#line 287 "grammar.y"
                                    { outCode(2,0xED,0xBB); }
#line 3319 "grammar.c"
    break;

  case 85:
#line 288 "grammar.y"
                                    { outCode(2,0xED,0xB3); }
#line 3325 "grammar.c"
    break;

  case 86:
#line 289 "grammar.y"
                                    { outCode(2,0xED,0xAB); }
#line 3331 "grammar.c"
    break;

  case 87:
#line 290 "grammar.y"
                                    { outCode(2,0xED,0xA3); }
#line 3337 "grammar.c"
    break;

  case 88:
#line 291 "grammar.y"
                                    { outCode(2,0xED,0x4D); }
#line 3343 "grammar.c"
    break;

  case 89:
#line 292 "grammar.y"
                                    { outCode(2,0xED,0x45); }
#line 3349 "grammar.c"
    break;

  case 90:
#line 293 "grammar.y"
                                    { outCode(1,0x17);      }
#line 3355 "grammar.c"
    break;

  case 91:
#line 294 "grammar.y"
                                    { outCode(1,0x07);      }
#line 3361 "grammar.c"
    break;

  case 92:
#line 295 "grammar.y"
                                    { outCode(2,0xED,0x6F); }
#line 3367 "grammar.c"
    break;

  case 93:
#line 296 "grammar.y"
                                    { outCode(1,0x1F);      }
#line 3373 "grammar.c"
    break;

  case 94:
#line 297 "grammar.y"
                                    { outCode(1,0x0F);      }
#line 3379 "grammar.c"
    break;

  case 95:
#line 298 "grammar.y"
                                    { outCode(2,0xED,0x67); }
#line 3385 "grammar.c"
    break;

  case 96:
#line 299 "grammar.y"
                                    { outCode(1,0x37); }
#line 3391 "grammar.c"
    break;

  case 97:
#line 303 "grammar.y"
                                                 { setLabelValue((yyvsp[-2].literal),(yyvsp[0].normal)); }
#line 3397 "grammar.c"
    break;

  case 98:
#line 305 "grammar.y"
                                                 { for(int a=0;a<abs((yyvsp[0].normal));a++) { outCode(1,0x0); } }
#line 3403 "grammar.c"
    break;

  case 99:
#line 306 "grammar.y"
                                            {  for(int a=0;a<abs((yyvsp[-2].normal));a++) { outCode(1,(yyvsp[0].normal)); }  }
#line 3409 "grammar.c"
    break;

  case 100:
#line 308 "grammar.y"
                                           { for(int a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3415 "grammar.c"
    break;

  case 101:
#line 310 "grammar.y"
                                           { for(int a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3421 "grammar.c"
    break;

  case 102:
#line 312 "grammar.y"
                                       { for(int a=0;a<(yyvsp[0].listexpr)[0];a++)      { outCode(1,(yyvsp[0].listexpr)[a+1]);  } }
#line 3427 "grammar.c"
    break;

  case 103:
#line 314 "grammar.y"
                                      { outCode(2,0xCE,(yyvsp[0].normal)); }
#line 3433 "grammar.c"
    break;

  case 104:
#line 315 "grammar.y"
                                           { int k = (((yyvsp[0].byte))|128|8); outCode(1,k); }
#line 3439 "grammar.c"
    break;

  case 105:
#line 316 "grammar.y"
                                                   { outCode(1,0x8E); }
#line 3445 "grammar.c"
    break;

  case 106:
#line 317 "grammar.y"
                                                             { outCode(3,0xDD,0x8E,(yyvsp[-1].normal)); }
#line 3451 "grammar.c"
    break;

  case 107:
#line 318 "grammar.y"
                                                             { outCode(3,0xFD,0x8E,(yyvsp[-1].normal)); }
#line 3457 "grammar.c"
    break;

  case 108:
#line 319 "grammar.y"
                                                   { outCode(3,0xDD,0x8E,0); }
#line 3463 "grammar.c"
    break;

  case 109:
#line 320 "grammar.y"
                                                   { outCode(3,0xFD,0x8E,0); }
#line 3469 "grammar.c"
    break;

  case 110:
#line 321 "grammar.y"
                                           { int k = (((yyvsp[0].byte)<<4)|64|8|2); outCode(2,0xED,k); }
#line 3475 "grammar.c"
    break;

  case 111:
#line 322 "grammar.y"
                                           {  outCode(2,0xDD,0x8C); }
#line 3481 "grammar.c"
    break;

  case 112:
#line 323 "grammar.y"
                                           {  outCode(2,0xDD,0x8D); }
#line 3487 "grammar.c"
    break;

  case 113:
#line 324 "grammar.y"
                                           {  outCode(2,0xFD,0x8C); }
#line 3493 "grammar.c"
    break;

  case 114:
#line 325 "grammar.y"
                                           {  outCode(2,0xFD,0x8D); }
#line 3499 "grammar.c"
    break;

  case 115:
#line 327 "grammar.y"
                                      { outCode(2,0xC6,(yyvsp[0].normal)); }
#line 3505 "grammar.c"
    break;

  case 116:
#line 328 "grammar.y"
                                           { int k = (((yyvsp[0].byte))|128); outCode(1,k); }
#line 3511 "grammar.c"
    break;

  case 117:
#line 329 "grammar.y"
                                                   { outCode(1,0x86); }
#line 3517 "grammar.c"
    break;

  case 118:
#line 330 "grammar.y"
                                                             { outCode(3,0xDD,0x86,(yyvsp[-1].normal)); }
#line 3523 "grammar.c"
    break;

  case 119:
#line 331 "grammar.y"
                                                             { outCode(3,0xFD,0x86,(yyvsp[-1].normal)); }
#line 3529 "grammar.c"
    break;

  case 120:
#line 332 "grammar.y"
                                                   { outCode(3,0xDD,0x86,0); }
#line 3535 "grammar.c"
    break;

  case 121:
#line 333 "grammar.y"
                                                   { outCode(3,0xFD,0x86,0); }
#line 3541 "grammar.c"
    break;

  case 122:
#line 334 "grammar.y"
                                           { int k = (((yyvsp[0].byte)<<4)|8|1); outCode(1,k); }
#line 3547 "grammar.c"
    break;

  case 123:
#line 335 "grammar.y"
                                           { outCode(2,0xDD,0x09); }
#line 3553 "grammar.c"
    break;

  case 124:
#line 336 "grammar.y"
                                           { outCode(2,0xDD,0x19); }
#line 3559 "grammar.c"
    break;

  case 125:
#line 337 "grammar.y"
                                           { outCode(2,0xDD,0x29); }
#line 3565 "grammar.c"
    break;

  case 126:
#line 338 "grammar.y"
                                           { outCode(2,0xDD,0x39); }
#line 3571 "grammar.c"
    break;

  case 127:
#line 339 "grammar.y"
                                           { outCode(2,0xFD,0x09); }
#line 3577 "grammar.c"
    break;

  case 128:
#line 340 "grammar.y"
                                           { outCode(2,0xFD,0x19); }
#line 3583 "grammar.c"
    break;

  case 129:
#line 341 "grammar.y"
                                           { outCode(2,0xFD,0x29); }
#line 3589 "grammar.c"
    break;

  case 130:
#line 342 "grammar.y"
                                           { outCode(2,0xFD,0x39); }
#line 3595 "grammar.c"
    break;

  case 131:
#line 343 "grammar.y"
                                           {  outCode(2,0xDD,0x84); }
#line 3601 "grammar.c"
    break;

  case 132:
#line 344 "grammar.y"
                                           {  outCode(2,0xDD,0x85); }
#line 3607 "grammar.c"
    break;

  case 133:
#line 345 "grammar.y"
                                           {  outCode(2,0xFD,0x84); }
#line 3613 "grammar.c"
    break;

  case 134:
#line 346 "grammar.y"
                                           {  outCode(2,0xFD,0x85); }
#line 3619 "grammar.c"
    break;

  case 135:
#line 348 "grammar.y"
                              { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3625 "grammar.c"
    break;

  case 136:
#line 349 "grammar.y"
                                   { int k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3631 "grammar.c"
    break;

  case 137:
#line 350 "grammar.y"
                                           { outCode(1,0xA6); }
#line 3637 "grammar.c"
    break;

  case 138:
#line 351 "grammar.y"
                                                     { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3643 "grammar.c"
    break;

  case 139:
#line 352 "grammar.y"
                                                     { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3649 "grammar.c"
    break;

  case 140:
#line 353 "grammar.y"
                                           { outCode(3,0xDD,0xA6,0); }
#line 3655 "grammar.c"
    break;

  case 141:
#line 354 "grammar.y"
                                           { outCode(3,0xFD,0xA6,0); }
#line 3661 "grammar.c"
    break;

  case 142:
#line 356 "grammar.y"
                                    { outCode(2,0xDD,0xA4); }
#line 3667 "grammar.c"
    break;

  case 143:
#line 357 "grammar.y"
                                    { outCode(2,0xDD,0xA5); }
#line 3673 "grammar.c"
    break;

  case 144:
#line 358 "grammar.y"
                                    { outCode(2,0xFD,0xA4); }
#line 3679 "grammar.c"
    break;

  case 145:
#line 359 "grammar.y"
                                    { outCode(2,0xFD,0xA5); }
#line 3685 "grammar.c"
    break;

  case 146:
#line 360 "grammar.y"
                                      { outCode(2,0xE6,(yyvsp[0].normal)); }
#line 3691 "grammar.c"
    break;

  case 147:
#line 361 "grammar.y"
                                           { int k = (((yyvsp[0].byte))|128|32); outCode(1,k); }
#line 3697 "grammar.c"
    break;

  case 148:
#line 362 "grammar.y"
                                                   { outCode(1,0xA6); }
#line 3703 "grammar.c"
    break;

  case 149:
#line 363 "grammar.y"
                                                             { outCode(3,0xDD,0xA6,(yyvsp[-1].normal)); }
#line 3709 "grammar.c"
    break;

  case 150:
#line 364 "grammar.y"
                                                             { outCode(3,0xFD,0xA6,(yyvsp[-1].normal)); }
#line 3715 "grammar.c"
    break;

  case 151:
#line 365 "grammar.y"
                                            { outCode(2,0xDD,0xA4); }
#line 3721 "grammar.c"
    break;

  case 152:
#line 366 "grammar.y"
                                            { outCode(2,0xDD,0xA5); }
#line 3727 "grammar.c"
    break;

  case 153:
#line 367 "grammar.y"
                                            { outCode(2,0xFD,0xA4); }
#line 3733 "grammar.c"
    break;

  case 154:
#line 368 "grammar.y"
                                            { outCode(2,0xFD,0xA5); }
#line 3739 "grammar.c"
    break;

  case 155:
#line 370 "grammar.y"
                                                      { if ((yyvsp[-4].normal) > 7) { warningError("Bit number is bigger out of range, truncating"); } outCode(2,0xCB,(((yyvsp[-4].normal)<<3)|64|6)); }
#line 3745 "grammar.c"
    break;

  case 156:
#line 371 "grammar.y"
                                                                { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xDD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3751 "grammar.c"
    break;

  case 157:
#line 372 "grammar.y"
                                                                { if ((yyvsp[-6].normal)>7) { warningError("Bit number is bigger out of range, truncating"); } outCode(4,0xFD,0xCB,(yyvsp[-1].normal), (((yyvsp[-6].normal)<<3)|64|6)); }
#line 3757 "grammar.c"
    break;

  case 158:
#line 373 "grammar.y"
                                   { 	if ((yyvsp[-2].normal)>7) { warningError("Bit number is bigger out of range, truncating"); }
                                            outCode(2,0xCB,(((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|64));
                                        }
#line 3765 "grammar.c"
    break;

  case 159:
#line 378 "grammar.y"
                               { outCode(3,0xCD,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3771 "grammar.c"
    break;

  case 160:
#line 379 "grammar.y"
                                       { outCode(3, (((yyvsp[-2].byte)<<3)|128|64|4),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 3777 "grammar.c"
    break;

  case 161:
#line 381 "grammar.y"
                            { outCode(2,0xFE,(yyvsp[0].normal)); }
#line 3783 "grammar.c"
    break;

  case 162:
#line 382 "grammar.y"
                                  { int k = (((yyvsp[0].byte))|128|32|16|8); outCode(1,k); }
#line 3789 "grammar.c"
    break;

  case 163:
#line 383 "grammar.y"
                                          { outCode(1,0xBE); }
#line 3795 "grammar.c"
    break;

  case 164:
#line 384 "grammar.y"
                                                    { outCode(3,0xDD,0xBE,(yyvsp[-1].normal)); }
#line 3801 "grammar.c"
    break;

  case 165:
#line 385 "grammar.y"
                                                    { outCode(3,0xFD,0xBE,(yyvsp[-1].normal)); }
#line 3807 "grammar.c"
    break;

  case 166:
#line 386 "grammar.y"
                                          { outCode(3,0xDD,0xBE,0); }
#line 3813 "grammar.c"
    break;

  case 167:
#line 387 "grammar.y"
                                          { outCode(3,0xFD,0xBE,0); }
#line 3819 "grammar.c"
    break;

  case 168:
#line 388 "grammar.y"
                                  {  outCode(2,0xDD,0xBC); }
#line 3825 "grammar.c"
    break;

  case 169:
#line 389 "grammar.y"
                                  {  outCode(2,0xDD,0xBD); }
#line 3831 "grammar.c"
    break;

  case 170:
#line 390 "grammar.y"
                                  {  outCode(2,0xFD,0xBC); }
#line 3837 "grammar.c"
    break;

  case 171:
#line 391 "grammar.y"
                                  {  outCode(2,0xFD,0xBD); }
#line 3843 "grammar.c"
    break;

  case 172:
#line 393 "grammar.y"
                                   { int k = (((yyvsp[0].byte)<<3)|4|1); outCode(1,k); }
#line 3849 "grammar.c"
    break;

  case 173:
#line 394 "grammar.y"
                                           { outCode(1,0x35); }
#line 3855 "grammar.c"
    break;

  case 174:
#line 395 "grammar.y"
                                                     { outCode(3,0xDD,0x35,(yyvsp[-1].normal)); }
#line 3861 "grammar.c"
    break;

  case 175:
#line 396 "grammar.y"
                                                     { outCode(3,0xFD,0x35,(yyvsp[-1].normal)); }
#line 3867 "grammar.c"
    break;

  case 176:
#line 397 "grammar.y"
                                           { outCode(3,0xDD,0x35,0); }
#line 3873 "grammar.c"
    break;

  case 177:
#line 398 "grammar.y"
                                           { outCode(3,0xFD,0x35,0); }
#line 3879 "grammar.c"
    break;

  case 178:
#line 399 "grammar.y"
                                   { int k = (((yyvsp[0].byte)<<4)|8|2|1); outCode(1,k); }
#line 3885 "grammar.c"
    break;

  case 179:
#line 400 "grammar.y"
                                   { outCode(2,0xDD,0x2B); }
#line 3891 "grammar.c"
    break;

  case 180:
#line 401 "grammar.y"
                                   { outCode(2,0xFD,0x2B); }
#line 3897 "grammar.c"
    break;

  case 181:
#line 402 "grammar.y"
                                { outCode(1,0xDD,0x25); }
#line 3903 "grammar.c"
    break;

  case 182:
#line 403 "grammar.y"
                                { outCode(1,0xDD,0x2D); }
#line 3909 "grammar.c"
    break;

  case 183:
#line 404 "grammar.y"
                                { outCode(1,0xFD,0x25); }
#line 3915 "grammar.c"
    break;

  case 184:
#line 405 "grammar.y"
                                { outCode(1,0xFD,0x2C); }
#line 3921 "grammar.c"
    break;

  case 185:
#line 408 "grammar.y"
                                           {  outCode(2,0x10,((yyvsp[0].normal) - pc - 2) ); }
#line 3927 "grammar.c"
    break;

  case 186:
#line 411 "grammar.y"
                                        { outCode(1,0x08); }
#line 3933 "grammar.c"
    break;

  case 187:
#line 412 "grammar.y"
                                        { outCode(1,0xEB); }
#line 3939 "grammar.c"
    break;

  case 188:
#line 413 "grammar.y"
                                                         { outCode(1,0xE3); }
#line 3945 "grammar.c"
    break;

  case 189:
#line 414 "grammar.y"
                                                         { outCode(2,0xDD,0xE3); }
#line 3951 "grammar.c"
    break;

  case 190:
#line 415 "grammar.y"
                                                         { outCode(2,0xFD,0xE3); }
#line 3957 "grammar.c"
    break;

  case 191:
#line 417 "grammar.y"
                       { switch((yyvsp[0].normal)) {
                                case 0: outCode(2,0xED,0x46); break;
                                case 1: outCode(2,0xED,0x56); break;
                                case 2: outCode(2,0xED,0x5E); break;
                                default: fatalError("Interruption mode value is out of range: Only allowed 0, 1 or 2"); break;
                               }
                             }
#line 3969 "grammar.c"
    break;

  case 192:
#line 425 "grammar.y"
                                                { outCode(2,0xED,(((yyvsp[-4].byte)<<3)|64)); }
#line 3975 "grammar.c"
    break;

  case 193:
#line 426 "grammar.y"
                                                { outCode(2,0xDB,(yyvsp[0].normal)); if ((yyvsp[-2].byte) != 7) { fatalError("IN only can use the A Register, sorry"); } }
#line 3981 "grammar.c"
    break;

  case 194:
#line 428 "grammar.y"
                                { outCode(1,((yyvsp[0].byte)<<3)|4); }
#line 3987 "grammar.c"
    break;

  case 195:
#line 429 "grammar.y"
                                { outCode(1,(((yyvsp[0].byte)<<4)|1|2));  }
#line 3993 "grammar.c"
    break;

  case 196:
#line 430 "grammar.y"
                                       { outCode(1,0x34); }
#line 3999 "grammar.c"
    break;

  case 197:
#line 431 "grammar.y"
                                                 { outCode(3,0xDD,0x34,(yyvsp[-1].normal)); }
#line 4005 "grammar.c"
    break;

  case 198:
#line 432 "grammar.y"
                                                 { outCode(3,0xFD,0x34,(yyvsp[-1].normal)); }
#line 4011 "grammar.c"
    break;

  case 199:
#line 433 "grammar.y"
                                        { outCode(3,0xDD,0x34,0); }
#line 4017 "grammar.c"
    break;

  case 200:
#line 434 "grammar.y"
                                        { outCode(3,0xFD,0x34,0); }
#line 4023 "grammar.c"
    break;

  case 201:
#line 435 "grammar.y"
                                { outCode(1,0xDD,0x23); }
#line 4029 "grammar.c"
    break;

  case 202:
#line 436 "grammar.y"
                                { outCode(1,0xFD,0x23); }
#line 4035 "grammar.c"
    break;

  case 203:
#line 437 "grammar.y"
                                { outCode(1,0xDD,0x24); }
#line 4041 "grammar.c"
    break;

  case 204:
#line 438 "grammar.y"
                                { outCode(1,0xDD,0x2C); }
#line 4047 "grammar.c"
    break;

  case 205:
#line 439 "grammar.y"
                                { outCode(1,0xFD,0x24); }
#line 4053 "grammar.c"
    break;

  case 206:
#line 440 "grammar.y"
                                { outCode(1,0xFD,0x2C); }
#line 4059 "grammar.c"
    break;

  case 207:
#line 442 "grammar.y"
                                 { outCode(3,0xC3,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4065 "grammar.c"
    break;

  case 208:
#line 443 "grammar.y"
                                 { outCode(3,(((yyvsp[-2].byte)<<3)|128|64|2),0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4071 "grammar.c"
    break;

  case 209:
#line 444 "grammar.y"
                                       { outCode(1,0xE9); }
#line 4077 "grammar.c"
    break;

  case 210:
#line 445 "grammar.y"
                                       { outCode(2,0xDD,0xE9); }
#line 4083 "grammar.c"
    break;

  case 211:
#line 446 "grammar.y"
                                       { outCode(2,0xDD,0xE9); }
#line 4089 "grammar.c"
    break;

  case 212:
#line 448 "grammar.y"
                                           { outCode(2,((yyvsp[-2].byte)<<3)|32,((yyvsp[0].normal) - pc - 2)); }
#line 4095 "grammar.c"
    break;

  case 213:
#line 449 "grammar.y"
                                    { outCode(2,0x18, ((yyvsp[0].normal) - pc - 2) ); }
#line 4101 "grammar.c"
    break;

  case 214:
#line 450 "grammar.y"
                                    { fatalError("You cannot use M flag bit in JR instruction"); }
#line 4107 "grammar.c"
    break;

  case 215:
#line 451 "grammar.y"
                                    { fatalError("You cannot use P flag bit in JR instruction"); }
#line 4113 "grammar.c"
    break;

  case 216:
#line 452 "grammar.y"
                                     { fatalError("You cannot use PE flag bit in JR instruction"); }
#line 4119 "grammar.c"
    break;

  case 217:
#line 453 "grammar.y"
                                     { fatalError("You cannot use PO flag bit in JR instruction"); }
#line 4125 "grammar.c"
    break;

  case 218:
#line 456 "grammar.y"
                                                                                                { int k = (((yyvsp[-2].byte) << 3)|64); k = k | (yyvsp[0].byte); outCode(1,k); }
#line 4131 "grammar.c"
    break;

  case 219:
#line 457 "grammar.y"
                                                                        { outCode(3,0x3A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");} }
#line 4137 "grammar.c"
    break;

  case 220:
#line 458 "grammar.y"
                                                                                                        { outCode(2,(((yyvsp[-2].byte) << 3)|6),(yyvsp[0].normal)); }
#line 4143 "grammar.c"
    break;

  case 221:
#line 459 "grammar.y"
                                                                        { outCode(3,(yyvsp[-3].normal),((yyvsp[-6].byte)<<3)|64|4|2,(yyvsp[-1].normal)); }
#line 4149 "grammar.c"
    break;

  case 222:
#line 460 "grammar.y"
                                                                                                { outCode(1,((yyvsp[-4].byte)<<3)|64|4|2); }
#line 4155 "grammar.c"
    break;

  case 223:
#line 461 "grammar.y"
                                                                                                { outCode(1,0x02); }
#line 4161 "grammar.c"
    break;

  case 224:
#line 462 "grammar.y"
                                                                                                { outCode(1,0x12); }
#line 4167 "grammar.c"
    break;

  case 225:
#line 463 "grammar.y"
                                                                                                { outCode(2,0x36,(yyvsp[0].normal)); }
#line 4173 "grammar.c"
    break;

  case 226:
#line 464 "grammar.y"
                                                                                                { outCode(1,(yyvsp[0].byte)|64|32|16); }
#line 4179 "grammar.c"
    break;

  case 227:
#line 465 "grammar.y"
                                                                                { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),(yyvsp[0].normal)); }
#line 4185 "grammar.c"
    break;

  case 228:
#line 466 "grammar.y"
                                                                                { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),(yyvsp[-3].normal)); }
#line 4191 "grammar.c"
    break;

  case 229:
#line 467 "grammar.y"
                                                                                { outCode(4,(yyvsp[-5].normal),0x36,(yyvsp[-3].normal),-(yyvsp[0].normal)); }
#line 4197 "grammar.c"
    break;

  case 230:
#line 468 "grammar.y"
                                                                                { outCode(3,(yyvsp[-5].normal),((yyvsp[0].byte)|64|32|16),-(yyvsp[-3].normal)); }
#line 4203 "grammar.c"
    break;

  case 231:
#line 469 "grammar.y"
                                                                                                { outCode(3,0x32,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4209 "grammar.c"
    break;

  case 232:
#line 470 "grammar.y"
                                                                                                { outCode(4,0xED,43,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4215 "grammar.c"
    break;

  case 233:
#line 471 "grammar.y"
                                                                                                { outCode(4,0xED,53,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4221 "grammar.c"
    break;

  case 234:
#line 472 "grammar.y"
                                                                                                { outCode(4,0xED,73,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4227 "grammar.c"
    break;

  case 235:
#line 473 "grammar.y"
                                                                                                { outCode(3,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4233 "grammar.c"
    break;

  case 236:
#line 474 "grammar.y"
                                                                                                { outCode(4,0xDD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4239 "grammar.c"
    break;

  case 237:
#line 475 "grammar.y"
                                                                                                { outCode(3,0xFD,0x22,0x00FF&(yyvsp[-3].normal),(0xFF00&(yyvsp[-3].normal))>>8); }
#line 4245 "grammar.c"
    break;

  case 238:
#line 476 "grammar.y"
                                                                                                { outCode(1,0x0A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4251 "grammar.c"
    break;

  case 239:
#line 477 "grammar.y"
                                                                                                { outCode(1,0x1A); if ((yyvsp[-4].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4257 "grammar.c"
    break;

  case 240:
#line 478 "grammar.y"
                                                                                                        { outCode(2,0xED,0x57); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4263 "grammar.c"
    break;

  case 241:
#line 479 "grammar.y"
                                                                                                        { outCode(2,0xED,0x47); }
#line 4269 "grammar.c"
    break;

  case 242:
#line 480 "grammar.y"
                                                                                                        { outCode(2,0xED,0x5F); if ((yyvsp[-2].byte) != 7) {fatalError("Only A REGISTER can be used with this syntax");}}
#line 4275 "grammar.c"
    break;

  case 243:
#line 481 "grammar.y"
                                                                                                        { outCode(2,0xED,0x4F); }
#line 4281 "grammar.c"
    break;

  case 244:
#line 482 "grammar.y"
                                                                                { outCode(4,(yyvsp[-4].normal),0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
#line 4287 "grammar.c"
    break;

  case 245:
#line 483 "grammar.y"
                                                                                        { outCode(4,(yyvsp[-2].normal),0x21,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4293 "grammar.c"
    break;

  case 246:
#line 484 "grammar.y"
                                                                                { 
																		if ((yyvsp[-4].byte) != 2) { outCode(4,0xED,0x4B,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																		else            { outCode(3,0x2A,0x00FF&(yyvsp[-1].normal),(0xFF00&(yyvsp[-1].normal))>>8); }
																	}
#line 4302 "grammar.c"
    break;

  case 247:
#line 488 "grammar.y"
                                                                                                                { outCode(3,((yyvsp[-2].byte)<<4)|1,0x00FF&(yyvsp[0].normal),(0xFF00&(yyvsp[0].normal))>>8); }
#line 4308 "grammar.c"
    break;

  case 248:
#line 490 "grammar.y"
                                                                                                { 
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else { outCode(1,0xF9);  }
																	}
#line 4317 "grammar.c"
    break;

  case 249:
#line 494 "grammar.y"
                                                                                                {
																		if ( (yyvsp[-2].byte) != 3) { fatalError("Only SP Register can be used as destination with this syntax"); }
																		else  { outCode(2,(yyvsp[0].normal),0xF9); }
																	}
#line 4326 "grammar.c"
    break;

  case 250:
#line 498 "grammar.y"
                                                                                                        { 
		                                                                switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																			case 7: outCode(2,0xDD,(5<<3)|64|(yyvsp[0].byte)); break;
																			default: outCode(2,0xDD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	    }
																	}
#line 4337 "grammar.c"
    break;

  case 251:
#line 504 "grammar.y"
                                                                                                { switch ((yyvsp[-2].byte)) { case 4: case 5 : fatalError("Regs H or L not allowed in this syntax"); break;
																		case 7: outCode(2,0xFD,(5<<3)|64|(yyvsp[0].byte)); break;
																		default: outCode(2,0xFD,((yyvsp[-2].byte)<<3)|64|(yyvsp[0].byte)); break;
																	  }
																	}
#line 4347 "grammar.c"
    break;

  case 252:
#line 509 "grammar.y"
                                         { outCode(2,0xDD,0x60); }
#line 4353 "grammar.c"
    break;

  case 253:
#line 510 "grammar.y"
                                         { outCode(2,0xDD,0x61); }
#line 4359 "grammar.c"
    break;

  case 254:
#line 511 "grammar.y"
                                         { outCode(2,0xDD,0x62); }
#line 4365 "grammar.c"
    break;

  case 255:
#line 512 "grammar.y"
                                         { outCode(2,0xDD,0x63); }
#line 4371 "grammar.c"
    break;

  case 256:
#line 513 "grammar.y"
                                         { outCode(2,0xDD,0x64); }
#line 4377 "grammar.c"
    break;

  case 257:
#line 514 "grammar.y"
                                         { outCode(2,0xDD,0x65); }
#line 4383 "grammar.c"
    break;

  case 258:
#line 515 "grammar.y"
                                         { outCode(2,0xDD,0x67); }
#line 4389 "grammar.c"
    break;

  case 259:
#line 516 "grammar.y"
                                         { outCode(2,0xDD,0x68); }
#line 4395 "grammar.c"
    break;

  case 260:
#line 517 "grammar.y"
                                         { outCode(2,0xDD,0x69); }
#line 4401 "grammar.c"
    break;

  case 261:
#line 518 "grammar.y"
                                         { outCode(2,0xDD,0x6A); }
#line 4407 "grammar.c"
    break;

  case 262:
#line 519 "grammar.y"
                                         { outCode(2,0xDD,0x6B); }
#line 4413 "grammar.c"
    break;

  case 263:
#line 520 "grammar.y"
                                         { outCode(2,0xDD,0x6C); }
#line 4419 "grammar.c"
    break;

  case 264:
#line 521 "grammar.y"
                                         { outCode(2,0xDD,0x6D); }
#line 4425 "grammar.c"
    break;

  case 265:
#line 522 "grammar.y"
                                         { outCode(2,0xDD,0x6F); }
#line 4431 "grammar.c"
    break;

  case 266:
#line 523 "grammar.y"
                                         { outCode(2,0xFD,0x60); }
#line 4437 "grammar.c"
    break;

  case 267:
#line 524 "grammar.y"
                                         { outCode(2,0xFD,0x61); }
#line 4443 "grammar.c"
    break;

  case 268:
#line 525 "grammar.y"
                                         { outCode(2,0xFD,0x62); }
#line 4449 "grammar.c"
    break;

  case 269:
#line 526 "grammar.y"
                                         { outCode(2,0xFD,0x63); }
#line 4455 "grammar.c"
    break;

  case 270:
#line 527 "grammar.y"
                                         { outCode(2,0xFD,0x64); }
#line 4461 "grammar.c"
    break;

  case 271:
#line 528 "grammar.y"
                                         { outCode(2,0xFD,0x65); }
#line 4467 "grammar.c"
    break;

  case 272:
#line 529 "grammar.y"
                                         { outCode(2,0xFD,0x67); }
#line 4473 "grammar.c"
    break;

  case 273:
#line 530 "grammar.y"
                                         { outCode(2,0xFD,0x68); }
#line 4479 "grammar.c"
    break;

  case 274:
#line 531 "grammar.y"
                                         { outCode(2,0xFD,0x69); }
#line 4485 "grammar.c"
    break;

  case 275:
#line 532 "grammar.y"
                                         { outCode(2,0xFD,0x6A); }
#line 4491 "grammar.c"
    break;

  case 276:
#line 533 "grammar.y"
                                         { outCode(2,0xFD,0x6B); }
#line 4497 "grammar.c"
    break;

  case 277:
#line 534 "grammar.y"
                                         { outCode(2,0xFD,0x6C); }
#line 4503 "grammar.c"
    break;

  case 278:
#line 535 "grammar.y"
                                         { outCode(2,0xFD,0x6D); }
#line 4509 "grammar.c"
    break;

  case 279:
#line 536 "grammar.y"
                                         { outCode(2,0xFD,0x6F); }
#line 4515 "grammar.c"
    break;

  case 280:
#line 537 "grammar.y"
                                    { outCode(2,0xFD,0x2E,(yyvsp[0].normal)); }
#line 4521 "grammar.c"
    break;

  case 281:
#line 538 "grammar.y"
                                    { outCode(2,0xDD,0x2E,(yyvsp[0].normal)); }
#line 4527 "grammar.c"
    break;

  case 282:
#line 539 "grammar.y"
                                    { outCode(2,0xFD,0x26,(yyvsp[0].normal)); }
#line 4533 "grammar.c"
    break;

  case 283:
#line 540 "grammar.y"
                                    { outCode(2,0xDD,0x26,(yyvsp[0].normal)); }
#line 4539 "grammar.c"
    break;

  case 284:
#line 541 "grammar.y"
                                    { fatalError("Sorry, LD option into F register is not allowed in the Z80"); }
#line 4545 "grammar.c"
    break;

  case 285:
#line 542 "grammar.y"
                                    { fatalError("Sorry, LD option into AF register is not allowed in the Z80"); }
#line 4551 "grammar.c"
    break;

  case 286:
#line 545 "grammar.y"
                             { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4557 "grammar.c"
    break;

  case 287:
#line 546 "grammar.y"
                                  { int k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4563 "grammar.c"
    break;

  case 288:
#line 547 "grammar.y"
                                          { outCode(1,0xB6); }
#line 4569 "grammar.c"
    break;

  case 289:
#line 548 "grammar.y"
                                                    { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4575 "grammar.c"
    break;

  case 290:
#line 549 "grammar.y"
                                                    { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4581 "grammar.c"
    break;

  case 291:
#line 550 "grammar.y"
                                   { outCode(2,0xDD,0xB4); }
#line 4587 "grammar.c"
    break;

  case 292:
#line 551 "grammar.y"
                                   { outCode(2,0xDD,0xB5); }
#line 4593 "grammar.c"
    break;

  case 293:
#line 552 "grammar.y"
                                   { outCode(2,0xFD,0xB4); }
#line 4599 "grammar.c"
    break;

  case 294:
#line 553 "grammar.y"
                                   { outCode(2,0xFD,0xB5); }
#line 4605 "grammar.c"
    break;

  case 295:
#line 554 "grammar.y"
                                     { outCode(2,0xF6,(yyvsp[0].normal)); }
#line 4611 "grammar.c"
    break;

  case 296:
#line 555 "grammar.y"
                                          { int k = (((yyvsp[0].byte))|128|32|16); outCode(1,k); }
#line 4617 "grammar.c"
    break;

  case 297:
#line 556 "grammar.y"
                                                  { outCode(1,0xB6); }
#line 4623 "grammar.c"
    break;

  case 298:
#line 557 "grammar.y"
                                                            { outCode(3,0xDD,0xB6,(yyvsp[-1].normal)); }
#line 4629 "grammar.c"
    break;

  case 299:
#line 558 "grammar.y"
                                                            { outCode(3,0xFD,0xB6,(yyvsp[-1].normal)); }
#line 4635 "grammar.c"
    break;

  case 300:
#line 559 "grammar.y"
                                           { outCode(2,0xDD,0xB4); }
#line 4641 "grammar.c"
    break;

  case 301:
#line 560 "grammar.y"
                                           { outCode(2,0xDD,0xB5); }
#line 4647 "grammar.c"
    break;

  case 302:
#line 561 "grammar.y"
                                           { outCode(2,0xFD,0xB4); }
#line 4653 "grammar.c"
    break;

  case 303:
#line 562 "grammar.y"
                                           { outCode(2,0xFD,0xB5); }
#line 4659 "grammar.c"
    break;

  case 304:
#line 565 "grammar.y"
                                                      { outCode(2,0xD3,(yyvsp[-3].normal)); }
#line 4665 "grammar.c"
    break;

  case 305:
#line 566 "grammar.y"
                                                           { outCode(2,0xED,((yyvsp[0].byte)<<3)|1|64); }
#line 4671 "grammar.c"
    break;

  case 306:
#line 568 "grammar.y"
                           { outCode(1,((yyvsp[0].byte)<<4)|1|128|64); }
#line 4677 "grammar.c"
    break;

  case 307:
#line 569 "grammar.y"
                         { outCode(2,0xDD,0xE1); }
#line 4683 "grammar.c"
    break;

  case 308:
#line 570 "grammar.y"
                         { outCode(2,0xFD,0xE1); }
#line 4689 "grammar.c"
    break;

  case 309:
#line 572 "grammar.y"
                             { outCode(1,((yyvsp[0].byte)<<4)|1|4|64|128); }
#line 4695 "grammar.c"
    break;

  case 310:
#line 573 "grammar.y"
                           { outCode(2,0xDD,0xE5); }
#line 4701 "grammar.c"
    break;

  case 311:
#line 574 "grammar.y"
                           { outCode(2,0xFD,0xE5); }
#line 4707 "grammar.c"
    break;

  case 312:
#line 577 "grammar.y"
                                   { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128); }
#line 4713 "grammar.c"
    break;

  case 313:
#line 578 "grammar.y"
                                                  { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|4|2); }
#line 4719 "grammar.c"
    break;

  case 314:
#line 579 "grammar.y"
                                                            { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4725 "grammar.c"
    break;

  case 315:
#line 580 "grammar.y"
                                                            { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|4|2); }
#line 4731 "grammar.c"
    break;

  case 316:
#line 583 "grammar.y"
                                                           { outCode(1,0xC9); }
#line 4737 "grammar.c"
    break;

  case 317:
#line 584 "grammar.y"
                                           { outCode(1,((yyvsp[0].byte)<<3)|128|64); }
#line 4743 "grammar.c"
    break;

  case 318:
#line 587 "grammar.y"
                                                          { outCode(2,0xCB,((yyvsp[0].byte))|16); }
#line 4749 "grammar.c"
    break;

  case 319:
#line 588 "grammar.y"
                                                      { outCode(2,0xCB,16); }
#line 4755 "grammar.c"
    break;

  case 320:
#line 589 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4761 "grammar.c"
    break;

  case 321:
#line 590 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x16); }
#line 4767 "grammar.c"
    break;

  case 322:
#line 592 "grammar.y"
                                       { outCode(2,0xCB,  (yyvsp[0].byte)); }
#line 4773 "grammar.c"
    break;

  case 323:
#line 593 "grammar.y"
                                         { outCode(2,0xCB,0x06); }
#line 4779 "grammar.c"
    break;

  case 324:
#line 594 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4785 "grammar.c"
    break;

  case 325:
#line 595 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x06); }
#line 4791 "grammar.c"
    break;

  case 326:
#line 597 "grammar.y"
                                      { outCode(2,0xCB,(yyvsp[0].byte)|8|16); }
#line 4797 "grammar.c"
    break;

  case 327:
#line 598 "grammar.y"
                                      { outCode(2,0xCB,0x1E);     }
#line 4803 "grammar.c"
    break;

  case 328:
#line 599 "grammar.y"
                                                { outCode(2,0xDD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4809 "grammar.c"
    break;

  case 329:
#line 600 "grammar.y"
                                                { outCode(2,0xFD,0xCB,(yyvsp[-1].normal),0x1E); }
#line 4815 "grammar.c"
    break;

  case 330:
#line 602 "grammar.y"
                                       { outCode(2,0xCB,(yyvsp[0].byte)|8); }
#line 4821 "grammar.c"
    break;

  case 331:
#line 603 "grammar.y"
                                       { outCode(2,0xCB,0x0E); }
#line 4827 "grammar.c"
    break;

  case 332:
#line 604 "grammar.y"
                                                 { outCode(4,0xDD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4833 "grammar.c"
    break;

  case 333:
#line 605 "grammar.y"
                                                 { outCode(4,0xFD,0xCB,(yyvsp[-1].normal),0x0E); }
#line 4839 "grammar.c"
    break;

  case 334:
#line 607 "grammar.y"
                        { switch ((yyvsp[0].normal)) {
                                case 0x0: case 0x8:
                                case 0x10: case 0x18:
                                case 0x20: case 0x28:
                                case 0x30: case 0x38: outCode(1,((yyvsp[0].normal)<<3)|128|64|4|2|1); break;
                                default: fatalError("Wrong vector provided for RST"); break;
                               }
                             }
#line 4852 "grammar.c"
    break;

  case 335:
#line 616 "grammar.y"
                                { outCode(1,(yyvsp[0].byte)|8|16|128); }
#line 4858 "grammar.c"
    break;

  case 336:
#line 617 "grammar.y"
                                { outCode(2,0xDE,(yyvsp[0].normal)); }
#line 4864 "grammar.c"
    break;

  case 337:
#line 618 "grammar.y"
                                               { outCode(1,0x9E); }
#line 4870 "grammar.c"
    break;

  case 338:
#line 619 "grammar.y"
                                                         { outCode(3,0xDD,0x9E,(yyvsp[-1].normal)); }
#line 4876 "grammar.c"
    break;

  case 339:
#line 620 "grammar.y"
                                                         { outCode(3,0xFD,0x9E,(yyvsp[-1].normal)); }
#line 4882 "grammar.c"
    break;

  case 340:
#line 621 "grammar.y"
                                  { outCode(2,0xED,((yyvsp[0].byte)<<4)|2|64); }
#line 4888 "grammar.c"
    break;

  case 341:
#line 622 "grammar.y"
                                       {  outCode(2,0xDD,0x9C); }
#line 4894 "grammar.c"
    break;

  case 342:
#line 623 "grammar.y"
                                           {  outCode(2,0xDD,0x9D); }
#line 4900 "grammar.c"
    break;

  case 343:
#line 624 "grammar.y"
                                           {  outCode(2,0xFD,0x9C); }
#line 4906 "grammar.c"
    break;

  case 344:
#line 625 "grammar.y"
                                           {  outCode(2,0xFD,0x9D); }
#line 4912 "grammar.c"
    break;

  case 345:
#line 627 "grammar.y"
                                   { outCode(2,0xCB,((yyvsp[-2].normal)<<3)|(yyvsp[0].byte)|128|64); }
#line 4918 "grammar.c"
    break;

  case 346:
#line 628 "grammar.y"
                                                  { outCode(2,0xCB,((yyvsp[-4].normal)<<3)|128|64|4|2); }
#line 4924 "grammar.c"
    break;

  case 347:
#line 629 "grammar.y"
                                                            { outCode(3,0xDD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4930 "grammar.c"
    break;

  case 348:
#line 630 "grammar.y"
                                                            { outCode(3,0xFD,0xCB,((yyvsp[-1].normal)),((yyvsp[-6].normal)<<3)|128|64|4|2); }
#line 4936 "grammar.c"
    break;

  case 349:
#line 633 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32); }
#line 4942 "grammar.c"
    break;

  case 350:
#line 634 "grammar.y"
                                                       { outCode(2,0xCB,26); }
#line 4948 "grammar.c"
    break;

  case 351:
#line 635 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 4954 "grammar.c"
    break;

  case 352:
#line 636 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x26); }
#line 4960 "grammar.c"
    break;

  case 353:
#line 638 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|16); }
#line 4966 "grammar.c"
    break;

  case 354:
#line 639 "grammar.y"
                                                       { outCode(2,0xCB,36); }
#line 4972 "grammar.c"
    break;

  case 355:
#line 640 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 4978 "grammar.c"
    break;

  case 356:
#line 641 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x36); }
#line 4984 "grammar.c"
    break;

  case 357:
#line 643 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|8); }
#line 4990 "grammar.c"
    break;

  case 358:
#line 644 "grammar.y"
                                                { outCode(2,0xCB,0x2E); }
#line 4996 "grammar.c"
    break;

  case 359:
#line 645 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 5002 "grammar.c"
    break;

  case 360:
#line 646 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x2E); }
#line 5008 "grammar.c"
    break;

  case 361:
#line 648 "grammar.y"
                                                        { outCode(2,0xCB,((yyvsp[0].byte))|32|16|8); }
#line 5014 "grammar.c"
    break;

  case 362:
#line 649 "grammar.y"
                                                       { outCode(2,0xCB,0x3E); }
#line 5020 "grammar.c"
    break;

  case 363:
#line 650 "grammar.y"
                                                  { outCode(4,0xDD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 5026 "grammar.c"
    break;

  case 364:
#line 651 "grammar.y"
                                                  { outCode(4,0xFD,0xCB,((yyvsp[-1].normal)),0x3E); }
#line 5032 "grammar.c"
    break;

  case 365:
#line 653 "grammar.y"
                                       { outCode(1,(yyvsp[0].byte)|16|128); }
#line 5038 "grammar.c"
    break;

  case 366:
#line 654 "grammar.y"
                                  { outCode(2,0xD6,(yyvsp[0].normal)); }
#line 5044 "grammar.c"
    break;

  case 367:
#line 655 "grammar.y"
                                       { outCode(1,0x96); }
#line 5050 "grammar.c"
    break;

  case 368:
#line 656 "grammar.y"
                                                 { outCode(3,0xDD,0x96,(yyvsp[-1].normal)); }
#line 5056 "grammar.c"
    break;

  case 369:
#line 657 "grammar.y"
                                                 { outCode(3,0xFD,0x96,(yyvsp[-1].normal)); }
#line 5062 "grammar.c"
    break;

  case 370:
#line 658 "grammar.y"
                               {  outCode(2,0xDD,0x94); }
#line 5068 "grammar.c"
    break;

  case 371:
#line 659 "grammar.y"
                                   {  outCode(2,0xDD,0x95); }
#line 5074 "grammar.c"
    break;

  case 372:
#line 660 "grammar.y"
                                   {  outCode(2,0xFD,0x94); }
#line 5080 "grammar.c"
    break;

  case 373:
#line 661 "grammar.y"
                                   {  outCode(2,0xFD,0x95); }
#line 5086 "grammar.c"
    break;

  case 374:
#line 664 "grammar.y"
                                                { int k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5092 "grammar.c"
    break;

  case 375:
#line 665 "grammar.y"
                               { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5098 "grammar.c"
    break;

  case 376:
#line 666 "grammar.y"
                                           { outCode(1,0xAE); }
#line 5104 "grammar.c"
    break;

  case 377:
#line 667 "grammar.y"
                                                     { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5110 "grammar.c"
    break;

  case 378:
#line 668 "grammar.y"
                                                     { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5116 "grammar.c"
    break;

  case 379:
#line 669 "grammar.y"
                                    { outCode(2,0xDD,0xAC); }
#line 5122 "grammar.c"
    break;

  case 380:
#line 670 "grammar.y"
                                    { outCode(2,0xDD,0xAD); }
#line 5128 "grammar.c"
    break;

  case 381:
#line 671 "grammar.y"
                                    { outCode(2,0xFD,0xAC); }
#line 5134 "grammar.c"
    break;

  case 382:
#line 672 "grammar.y"
                                    { outCode(2,0xFD,0xAD); }
#line 5140 "grammar.c"
    break;

  case 383:
#line 673 "grammar.y"
                                                        { int k = (((yyvsp[0].byte))|128|32|8); outCode(1,k); }
#line 5146 "grammar.c"
    break;

  case 384:
#line 674 "grammar.y"
                                       { outCode(2,0xEE,(yyvsp[0].normal)); }
#line 5152 "grammar.c"
    break;

  case 385:
#line 675 "grammar.y"
                                                   { outCode(1,0xAE); }
#line 5158 "grammar.c"
    break;

  case 386:
#line 676 "grammar.y"
                                                             { outCode(3,0xDD,0xAE,(yyvsp[-1].normal)); }
#line 5164 "grammar.c"
    break;

  case 387:
#line 677 "grammar.y"
                                                             { outCode(3,0xFD,0xAE,(yyvsp[-1].normal)); }
#line 5170 "grammar.c"
    break;

  case 388:
#line 678 "grammar.y"
                                            { outCode(2,0xDD,0xAC); }
#line 5176 "grammar.c"
    break;

  case 389:
#line 679 "grammar.y"
                                            { outCode(2,0xDD,0xAD); }
#line 5182 "grammar.c"
    break;

  case 390:
#line 680 "grammar.y"
                                            { outCode(2,0xFD,0xAC); }
#line 5188 "grammar.c"
    break;

  case 391:
#line 681 "grammar.y"
                                            { outCode(2,0xFD,0xAD); }
#line 5194 "grammar.c"
    break;

  case 392:
#line 684 "grammar.y"
                                         { p = (uint8_t *)malloc(3*sizeof(uint8_t)); p[0] = 2; p[1] = (yyvsp[0].normal)&0x00FF; p[2] = (yyvsp[0].normal)>>8; (yyval.listexpr) = p;  }
#line 5200 "grammar.c"
    break;

  case 393:
#line 685 "grammar.y"
                                         { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[p[0]+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; }
#line 5206 "grammar.c"
    break;

  case 394:
#line 686 "grammar.y"
                                              { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(int a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5212 "grammar.c"
    break;

  case 395:
#line 687 "grammar.y"
                                               {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5221 "grammar.c"
    break;

  case 396:
#line 694 "grammar.y"
                                              { p = (uint8_t *)malloc(5*sizeof(uint8_t)); p[0] = 4; p[1] = (yyvsp[0].normal)&0x000000FF; p[2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[3] = ((yyvsp[0].normal)&0x00FF0000)>>16; p[4] = ((yyvsp[0].normal)&0xFF000000)>>24; (yyval.listexpr) = p;  }
#line 5227 "grammar.c"
    break;

  case 397:
#line 695 "grammar.y"
                                         { p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+4)*sizeof(uint8_t)); p[p[0]+1] = (yyvsp[0].normal)&&0x000000FF; p[p[0]+2] = ((yyvsp[0].normal)&0x0000FF00)>>8; p[p[0]+4] = ((yyvsp[0].normal)&0x00FF0000)>>18; p[p[0]+4] = ((yyvsp[0].normal)&0xFF000000)>>24; p[0] = p[0] + 4; (yyval.listexpr) = p; }
#line 5233 "grammar.c"
    break;

  case 398:
#line 696 "grammar.y"
                                              { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(int a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5239 "grammar.c"
    break;

  case 399:
#line 697 "grammar.y"
                                               {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5248 "grammar.c"
    break;

  case 400:
#line 704 "grammar.y"
                                             { p = (uint8_t *)malloc(2); p[0] = 1; p[1] = (yyvsp[0].normal); (yyval.listexpr) = p; }
#line 5254 "grammar.c"
    break;

  case 401:
#line 705 "grammar.y"
                                             { p = (uint8_t *)malloc(strlen((yyvsp[0].literal))+1); p[0] = strlen((yyvsp[0].literal)); for(int a=0;a<strlen((yyvsp[0].literal));a++) { p[a+1] = (yyvsp[0].literal)[a];  } (yyval.listexpr) = p; }
#line 5260 "grammar.c"
    break;

  case 402:
#line 706 "grammar.y"
                                        { 
	                                       if (((uint16_t)(yyvsp[0].normal)) > 255) {
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+2)); p[p[0]+1] = (yyvsp[0].normal)&0x00FF; p[(*p)+2] = (yyvsp[0].normal)>>8; p[0] = p[0] + 2; (yyval.listexpr) = p; 
	                                       }
	                                       else { 
	                                          p = (uint8_t *)realloc((yyvsp[-2].listexpr),((*((yyvsp[-2].listexpr)))+1)); p[p[0]+1] = (yyvsp[0].normal); p[0] = p[0] + 1; (yyval.listexpr) = p; 
	                                       }   
	                                     }
#line 5273 "grammar.c"
    break;

  case 403:
#line 714 "grammar.y"
                                              {
	                                        p = (uint8_t *)realloc((yyvsp[-2].listexpr),(yyvsp[-2].listexpr)[0]+strlen((yyvsp[0].literal))); 
	                                        strcpy((char *)&p[p[0]+1],(char *)(yyvsp[0].literal)); p[0] = p[0] + strlen((yyvsp[0].literal)); (yyval.listexpr) = p; 
	                                      }
#line 5282 "grammar.c"
    break;

  case 404:
#line 719 "grammar.y"
                                                 { (yyval.normal) = (yyvsp[0].normal);  }
#line 5288 "grammar.c"
    break;

  case 405:
#line 720 "grammar.y"
                                                 { (yyval.normal)=((yyvsp[0].normal)==0)?1:0; }
#line 5294 "grammar.c"
    break;

  case 406:
#line 721 "grammar.y"
                                                { (yyval.normal) = (yyvsp[-1].normal);  }
#line 5300 "grammar.c"
    break;

  case 407:
#line 722 "grammar.y"
                                                { (yyval.normal)=-(yyvsp[0].normal); }
#line 5306 "grammar.c"
    break;

  case 408:
#line 723 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) + (yyvsp[0].normal); }
#line 5312 "grammar.c"
    break;

  case 409:
#line 724 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) - (yyvsp[0].normal); }
#line 5318 "grammar.c"
    break;

  case 410:
#line 725 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) * (yyvsp[0].normal); }
#line 5324 "grammar.c"
    break;

  case 411:
#line 726 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) / (yyvsp[0].normal); }
#line 5330 "grammar.c"
    break;

  case 412:
#line 727 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) & (yyvsp[0].normal); }
#line 5336 "grammar.c"
    break;

  case 413:
#line 728 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) | (yyvsp[0].normal); }
#line 5342 "grammar.c"
    break;

  case 414:
#line 729 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) << (yyvsp[0].normal); }
#line 5348 "grammar.c"
    break;

  case 415:
#line 730 "grammar.y"
                                                        { (yyval.normal) = (yyvsp[-2].normal) >> (yyvsp[0].normal); }
#line 5354 "grammar.c"
    break;

  case 416:
#line 731 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 0; } else { (yyval.normal) = 1;  } }
#line 5360 "grammar.c"
    break;

  case 417:
#line 732 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) == (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5366 "grammar.c"
    break;

  case 418:
#line 733 "grammar.y"
                                                { if ( (yyvsp[-2].normal) >= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5372 "grammar.c"
    break;

  case 419:
#line 734 "grammar.y"
                                                { if ( (yyvsp[-2].normal) > (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5378 "grammar.c"
    break;

  case 420:
#line 735 "grammar.y"
                                                { if ( (yyvsp[-2].normal) <= (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5384 "grammar.c"
    break;

  case 421:
#line 736 "grammar.y"
                                                { if ( (yyvsp[-2].normal) < (yyvsp[0].normal) )  { (yyval.normal) = 1; } else { (yyval.normal) = 0;  } }
#line 5390 "grammar.c"
    break;

  case 422:
#line 737 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) && (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5396 "grammar.c"
    break;

  case 423:
#line 738 "grammar.y"
                                                        { if ( (yyvsp[-2].normal) || (yyvsp[0].normal)) { (yyval.normal)=1; } else {(yyval.normal)=0; } }
#line 5402 "grammar.c"
    break;

  case 424:
#line 740 "grammar.y"
                                        { int k; 
	                                 if (getLabelValue((yyvsp[0].literal),&k) < 0)   { labelUndefinedError((yyvsp[0].literal)); (yyval.normal)=0; }                                  
	                                 else { (yyval.normal)=k; }
	                                }
#line 5411 "grammar.c"
    break;

  case 425:
#line 744 "grammar.y"
                                    { (yyval.normal) = (yyvsp[0].normal); }
#line 5417 "grammar.c"
    break;

  case 426:
#line 745 "grammar.y"
                                    { (yyval.normal) = (yyvsp[0].byte); }
#line 5423 "grammar.c"
    break;

  case 427:
#line 746 "grammar.y"
                                    { (yyval.normal) = prepc; }
#line 5429 "grammar.c"
    break;

  case 428:
#line 747 "grammar.y"
                                    { (yyval.normal) = (LookupTableLabels((yyvsp[0].literal))<0)?0:1; }
#line 5435 "grammar.c"
    break;

  case 429:
#line 751 "grammar.y"
                        { (yyval.byte) = 7; }
#line 5441 "grammar.c"
    break;

  case 430:
#line 752 "grammar.y"
                    { (yyval.byte) = 0; }
#line 5447 "grammar.c"
    break;

  case 431:
#line 753 "grammar.y"
                    { (yyval.byte) = 1; }
#line 5453 "grammar.c"
    break;

  case 432:
#line 754 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5459 "grammar.c"
    break;

  case 433:
#line 755 "grammar.y"
                    { (yyval.byte) = 3; }
#line 5465 "grammar.c"
    break;

  case 434:
#line 756 "grammar.y"
                    { (yyval.byte) = 4; }
#line 5471 "grammar.c"
    break;

  case 435:
#line 757 "grammar.y"
                    { (yyval.byte) = 5; }
#line 5477 "grammar.c"
    break;

  case 436:
#line 759 "grammar.y"
                    { (yyval.normal) = 0xDD; }
#line 5483 "grammar.c"
    break;

  case 437:
#line 760 "grammar.y"
                    { (yyval.normal) = 0xFD; }
#line 5489 "grammar.c"
    break;

  case 438:
#line 762 "grammar.y"
                        { (yyval.byte) = 0; }
#line 5495 "grammar.c"
    break;

  case 439:
#line 763 "grammar.y"
                     { (yyval.byte) = 1; }
#line 5501 "grammar.c"
    break;

  case 440:
#line 764 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5507 "grammar.c"
    break;

  case 441:
#line 765 "grammar.y"
                     { (yyval.byte) = 3; }
#line 5513 "grammar.c"
    break;

  case 442:
#line 767 "grammar.y"
                        { (yyval.byte) = 0; }
#line 5519 "grammar.c"
    break;

  case 443:
#line 768 "grammar.y"
                     { (yyval.byte) = 1; }
#line 5525 "grammar.c"
    break;

  case 444:
#line 769 "grammar.y"
                    { (yyval.byte) = 2; }
#line 5531 "grammar.c"
    break;

  case 445:
#line 770 "grammar.y"
                     { (yyval.byte) = 3; }
#line 5537 "grammar.c"
    break;

  case 446:
#line 773 "grammar.y"
                       { (yyval.byte) = 4; }
#line 5543 "grammar.c"
    break;

  case 447:
#line 774 "grammar.y"
                     { (yyval.byte) = 5; }
#line 5549 "grammar.c"
    break;

  case 448:
#line 776 "grammar.y"
                       { (yyval.byte) = 4; }
#line 5555 "grammar.c"
    break;

  case 449:
#line 777 "grammar.y"
                     { (yyval.byte) = 5; }
#line 5561 "grammar.c"
    break;

  case 450:
#line 779 "grammar.y"
                  { (yyval.byte) = 0; }
#line 5567 "grammar.c"
    break;

  case 451:
#line 780 "grammar.y"
                 { (yyval.byte) = 1; }
#line 5573 "grammar.c"
    break;

  case 452:
#line 781 "grammar.y"
                  { (yyval.byte) = 2; }
#line 5579 "grammar.c"
    break;

  case 453:
#line 782 "grammar.y"
                 { (yyval.byte) = 3; }
#line 5585 "grammar.c"
    break;

  case 454:
#line 783 "grammar.y"
                  { (yyval.byte) = 4; }
#line 5591 "grammar.c"
    break;

  case 455:
#line 784 "grammar.y"
                   { (yyval.byte) = 5; }
#line 5597 "grammar.c"
    break;

  case 456:
#line 785 "grammar.y"
                  { (yyval.byte) = 6; }
#line 5603 "grammar.c"
    break;

  case 457:
#line 786 "grammar.y"
                 { (yyval.byte) = 7; }
#line 5609 "grammar.c"
    break;

  case 458:
#line 788 "grammar.y"
                         { (yyval.byte) = 0; }
#line 5615 "grammar.c"
    break;

  case 459:
#line 789 "grammar.y"
                 { (yyval.byte) = 1; }
#line 5621 "grammar.c"
    break;

  case 460:
#line 790 "grammar.y"
                  { (yyval.byte) = 2; }
#line 5627 "grammar.c"
    break;

  case 461:
#line 791 "grammar.y"
                 { (yyval.byte) = 3; }
#line 5633 "grammar.c"
    break;


#line 5637 "grammar.c"

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
