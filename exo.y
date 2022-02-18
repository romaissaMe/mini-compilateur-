%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int yyparse();
int yylex();
int yyerror(char s);
extern int ligne;
extern int col;
%}
%union{
    int num;
    char *str;
    float reel;
}
%start S
%token mc_code mc_start mc_end mc_const
%token <num> cstent <reel>cstreel <str>idf  <str>char <reel>Reel <str>string <str>mc_false <str>mc_true

%%
S: mc_code idf p_declaration mc_start p_instructions mc_end
p_declaration: type idf ; p_declaration|mc_const idf = constante ; p_declaration|type idf ;|mc_const idf = constante ;
type: mc_int|mc_reel|mc_bool|mc_char|mc_string
constante:cstent|cstreel
p_instructions: instruction p_instructions | instruction
instruction: boucle ;|condition ;| affectation;
boucle: mc_while cond mc_execute mc_execute p_instructions
condition: mc_when cond mc_do p_instructions mc_otherwise p_instructions
affectation:idf := operand {
     if(nonDeclare($1)==-1) printf{("erreur Semantique");}
     else(if cst($1)==-1){ printf("erreur Semantique");}
     else(if compatible_type(sauvType,sauvType1))
     
     }
operand: idf {}| char | string | int | Reel {}|mc_true{} | mc_false {
strcpy(sauvType,"boolean");
}
%%