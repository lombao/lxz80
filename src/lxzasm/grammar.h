/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
  

#line 353 "grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */
