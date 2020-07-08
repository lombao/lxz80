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
  

#line 349 "grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */
