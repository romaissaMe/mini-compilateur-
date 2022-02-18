
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_Pint = 258,
     mc_Pfloat = 259,
     nompg = 260,
     mc_program = 261,
     mc_pdec = 262,
     mc_int = 263,
     mc_begin = 264,
     mc_end = 265,
     twop = 266,
     pvg = 267,
     defc = 268,
     aff = 269,
     mc_for = 270,
     mc_do = 271,
     mc_while = 272,
     egal = 273,
     mc_endfor = 274,
     mc_if = 275,
     mc_else = 276,
     pov = 277,
     pfe = 278,
     pls = 279,
     moins = 280,
     mul = 281,
     mc_division = 282,
     sup = 283,
     inf = 284,
     comp_egal = 285,
     diff = 286,
     supeg = 287,
     infeg = 288,
     et = 289,
     ou = 290,
     neg = 291,
     cm = 292,
     deb_cm = 293,
     end_cm = 294,
     Pint = 295,
     Pfloat = 296,
     IDF = 297,
     egl = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 20 "projetc.y"

int num;
char *str;
float fl;



/* Line 1676 of yacc.c  */
#line 103 "projetc.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


