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
#line 50 "grammar.y"

  uint32_t 	normal;
  uint8_t 	byte;
  uint16_t 	word;
  uint16_t 	address;
  uint8_t * listexpr;
  char 		literal[64];
  

#line 347 "grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */
