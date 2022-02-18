%{
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "projetc.tab.h"
int ligne=1;
int col=0;
extern YYSTYPE yylval;
%}
%option noyywrap
chiffre [0-9]
lettre [a-z]
IDF {lettre}(({lettre}|{chiffre}|_)*({lettre}|{chiffre}))*
Pint [+-]?([1-9][0-9]*|0)
Pfloat  [+-]?([1-9][0-9]*|0)\.[0-9]*
comment1 "/*"([^*]|\*+[^*/])*\*+\/  
comment2 "//"[^\n]*"\n"
%%
{Pint} {if(atoi(yytext)<32767 && atoi(yytext)>-32767){yylval.num= atoi(yytext);col=col+yyleng;return Pint;}
else {printf("erreur lexical la ligne %d et colonne %d  l entier doit etre entre 32767 et -32767: ",ligne,col);col=col+yyleng;}}
{Pfloat} {yylval.fl=atof(yytext);return Pfloat;col=col+yyleng;}
{IDF} {if(yyleng<12){yylval.str=strdup(yytext);col=col+yyleng;return IDF;}
        else{printf("erreur lexical la ligne %d et colonne %d :IDF trop long ",ligne,col);col=col+yyleng;}}
{comment1} {col=col+yyleng ;}
{comment2} {col=col+yyleng; }
PROGRAM {return mc_program;col=col+yyleng;}
PDEC {return mc_pdec;col=col+yyleng;}
PINST {return mc_int;col=col+yyleng;}
BEGIN {return mc_begin;col=col+yyleng;}
End {return mc_end;col=col+yyleng;}
@define {return defc;col=col+yyleng;}
PFLOAT {yylval.str=strdup(yytext); col =col+ yyleng;return mc_Pfloat;}
PINT {yylval.str=strdup(yytext); col =col+ yyleng;return mc_Pint;printf("type Pint");}
DO {return mc_do;col=col+yyleng;}
FOR {return mc_for;col=col+yyleng;}
WHILE {return mc_while;col=col+yyleng;}
ENDFOR {return mc_endfor;col=col+yyleng;}
IF {return mc_if;col=col+yyleng;}
ELSE {return mc_else;col=col+yyleng;}
"=" {return egal;col=col+yyleng;}
";" {return pvg;col=col+yyleng;}
":" {return twop;col=col+yyleng;}
"<-" {return aff;col=col+yyleng;}
\+ {return pls;col=col+yyleng;}
\- {return moins;col=col+yyleng;}
"*" {return mul;col=col+yyleng;}
"/" {return mc_division;col=col+yyleng;} 
"(" {return pov;col=col+yyleng;}
")" {return pfe;col=col+yyleng;}
"&" {return et;col=col+yyleng;}
"|" {return ou;col=col+yyleng;}
"!" {return neg;col=col+yyleng;}
">" {return sup;col=col+yyleng;} 
"<" {return inf;col=col+yyleng;} 
"<=" {return infeg;col=col+yyleng;}
">=" {return supeg;col=col+yyleng;}
"==" {return comp_egal;col=col+yyleng;}
"!=" {return diff;col=col+yyleng;}
[ \t] {col=col+yyleng;}
\n {ligne++;col=0;}
. {printf("\n Erreur lexical la ligne %d et colonne %d",ligne,col);}
%%
