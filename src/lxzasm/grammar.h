/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 68 "grammar.y" /* yacc.c:1909  */

  uint32_t normal;
  uint8_t byte;
  uint16_t word;
  uint16_t address;
  uint8_t * listexpr;
  char literal[64];
  

#line 358 "grammar.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */
