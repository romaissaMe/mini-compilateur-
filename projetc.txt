%{
#include<stdio.h>
#include<string.h>
#include "tableau.h"
extern int ligne;
extern int col;
char tempVal[20];
char sauvType[20];
char sauvIdf[20];
char sauvnature[20];
char sauvType1[20];
char sauvType2[20];
char sauvdiv[20];
char sauvval[20];
int yyparse();
int yylex();
int yyerror(char *s);
%}

%union {
int num;
char *str;
float fl;
} 
%start S
%type <str>val  
%type <str>operand
%type <str>expressionAr
%token <str>mc_Pint <str>mc_Pfloat <str>nompg
%token mc_program mc_pdec mc_int mc_begin mc_end twop  pvg defc aff  
%token mc_for mc_do mc_while egal mc_endfor mc_if mc_else pov pfe 
%token pls moins mul mc_division sup inf comp_egal diff supeg infeg et ou neg %token cm deb_cm end_cm 
%token <num>Pint <fl>Pfloat <str>IDF
%left ou
%left et
%left neg
%left sup inf egl diff supeg infeg 
%left pls moins
%left mul mc_division
%%
S:mc_program IDF mc_pdec pdeclaration mc_int mc_begin pinstruction mc_end { printf ("programme syntaxiquement juste");YYACCEPT ;}
;
pdeclaration:DEC pdeclaration |DEC
;
DEC: dec_var pvg  
|dec_const pvg
;
dec_var: IDF twop type { if(doubleDeclaration($1)==0){
    strcpy(sauvnature,"variable"); 
    inserer($1,sauvType,sauvnature);
                        }else printf("Erreur Semantique: double declaration  a la ligne %d , position %d\n",ligne,col);}
|IDF ou dec_var{
    {if(doubleDeclaration($1)==0){
    strcpy(sauvnature,"variable");
    inserer($1,sauvType,sauvnature);
    }
    else printf("Erreur Semantique: double declaration  a la ligne %d , position %d\n",ligne,col);}
}   
;



dec_const: defc type IDF egal val {
      if(doubleDeclaration($3)==0){
           strcpy(sauvnature,"constante");
           int x= compatible_type(sauvType,sauvType1);
           if(x==0){
           inserer($3,sauvType,sauvnature);
           insererVal($3,tempVal);}
            else printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$3,ligne,col);
      }
 else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$3,ligne,col);}
;
type: mc_Pint {strcpy(sauvType,"Pint");}
| mc_Pfloat {strcpy(sauvType,"Pfloat");}
;

val: Pint { strcpy(sauvType1,"Pint");
            sprintf(tempVal,"%d",$1);
               $$ = tempVal;
                 }
| Pfloat {strcpy(sauvType1,"Pfloat");
           sprintf(tempVal,"%f",$1);
               $$ = tempVal;}
pinstruction : inst pvg  pinstruction|inst pvg
;
inst: paff|pcondition|pboucle
;
paff:IDF aff expressionAr {
if(nonDeclare($1) == -1){printf("Erreur Semantique: idf non declare  de %s a la ligne %d , position %d\n",$1,ligne,col);}
else{
    if(cst($1)==0){printf("Erreur Semantique:impossible de modifier une constante  de %s a la ligne %d , position %d\n",$1,ligne,col);}
    }
}
|IDF aff operand {
if(nonDeclare($1)== -1) printf("Erreur Semantique: idf non declare  de %s a la ligne %d , position %d\n",$1,ligne,col);
else{
    if(cst($1)==0){printf("Erreur Semantique:impossible de modifier une constante  de %s a la ligne %d , position %d\n",$1,ligne,col);}
    else{
         int y=recherche($1);
         int x= compatible_type(ts[y].TypeEntite,sauvType1);
           if(x==0){
           insererVal($1,sauvval);}
            else printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$3,ligne,col);
    }
    }
    }
;

pboucle: mc_for paff mc_while val mc_do pinstruction mc_endfor
;
pcondition: mc_do pinstruction twop mc_if pov condition pfe |mc_do pinstruction twop mc_if  pov condition pfe  mc_else pinstruction 
;
condition:expressionLog |expressionComp
;


expressionAr: IDF operateurAr IDF{
    if((nonDeclare($1)== -1)|((nonDeclare($3)== -1))){printf("Erreur Semantique: idf non declare a la ligne %d , position %d\n",ligne,col);}
    else{int pos =recherche($1);
    strcpy(sauvType,ts[pos].TypeEntite);
    pos=recherche($3);
    strcpy(sauvType2,ts[pos].TypeEntite); 
         int x= compatible_type(sauvType1,sauvType2);
           if(x==-1){
         printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$3,ligne,col);
    }
     else {if (strcmp(sauvdiv,"mc_division")==0){
            if(strcmp(ts[pos].valeur,"0")==0){
 printf("Erreur Semantique: devision par zero a la ligne %d , position %d\n",ligne,col);
    }}
    }
    }
}
| IDF operateurAr val 
{
    if(nonDeclare($1)== -1){printf("Erreur Semantique: idf non declare a la ligne %d , position %d\n",ligne,col);}
    else{
        int pos =recherche($1);
        strcpy(sauvType2,ts[pos].TypeEntite); 
        int x= compatible_type(sauvType2,sauvType1);
           if(x==-1){
            printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$3,ligne,col);
           }
          else {if (strcmp(sauvdiv,"mc_division")==0){
                 if(strcmp(tempVal,"0")==0){
                    printf("Erreur Semantique: devision par zero a la ligne %d , position %d\n",ligne,col);
                  }}
    }
    }
}
|IDF operateurAr expressionAr
|pov IDF operateurAr IDF pfe{
    if((nonDeclare($2)== -1)|((nonDeclare($4)== -1))){printf("Erreur Semantique: idf non declare a la ligne %d , position %d\n",ligne,col);}
    else{int pos =recherche($2);
    strcpy(sauvType,ts[pos].TypeEntite);
    pos=recherche($4);
    strcpy(sauvType2,ts[pos].TypeEntite); 
         int x= compatible_type(sauvType1,sauvType2);
           if(x==-1){
         printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$4,ligne,col);
    }
     else {if (strcmp(sauvdiv,"mc_division")==0){
            if(strcmp(ts[pos].valeur,"0")==0){
 printf("Erreur Semantique: devision par zero a la ligne %d , position %d\n",ligne,col);
    }}
    }
    }
}
| pov IDF operateurAr val pfe
{
    if(nonDeclare($2)== -1){printf("Erreur Semantique: idf non declare a la ligne %d , position %d\n",ligne,col);}
    else{
        int pos =recherche($2);
        strcpy(sauvType2,ts[pos].TypeEntite); 
        int x= compatible_type(sauvType2,sauvType1);
           if(x==-1){
            printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$4,ligne,col);
           }
          else {if (strcmp(sauvdiv,"mc_division")==0){
                 if(strcmp(tempVal,"0")==0){
                    printf("Erreur Semantique: devision par zero a la ligne %d , position %d\n",ligne,col);
                  }}
    }
    }
}
;


operateurAr:pls {strcpy(sauvdiv,"pls");}
|moins {strcpy(sauvdiv,"min");}
|mc_division {strcpy(sauvdiv,"mc_division");}
|mul {strcpy(sauvdiv,"mul");}
;
operand:IDF {
if(nonDeclare($1)== -1) {printf("Erreur Semantique: idf non declare  de %s a la ligne %d , position %d\n",$1,ligne,col);}else{int pos =recherche($1);
    strcpy(sauvType1,ts[pos].TypeEntite);
    int y=recherche($1);
    strcpy(sauvval,ts[y].valeur);
    }
}
|val{
    strcpy(sauvval,$1);
   
}
;


expressionComp:pov IDF operateurComp  operand pfe {
if(nonDeclare($2)== -1) printf("Erreur Semantique: idf non declare  de %s a la ligne %d , position %d\n",$2,ligne,col);
else{
         int y=recherche($2);
         int x= compatible_type(ts[y].TypeEntite,sauvType1);
         if(x==-1){
         printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$2,ligne,col);
    }
    }
}
|IDF operateurComp operand {
if(nonDeclare($1)== -1) printf("Erreur Semantique: idf non declare  de %s a la ligne %d , position %d\n",$1,ligne,col);
else{
         int y=recherche($1);
         int x= compatible_type(ts[y].TypeEntite,sauvType1);
         if(x==-1){
         printf("Erreur Semantique: incompatible type de %s a la ligne %d , position %d\n",$1,ligne,col);
    }
    }
}
|IDF operateurComp expressionAr{
if(nonDeclare($1)== -1) printf("Erreur Semantique: idf non declare  de %s a la ligne %d , position %d\n",$1,ligne,col);
}
;
operateurComp: sup| inf| supeg| infeg| comp_egal|diff
;
expressionLog:pov expressionComp operateurLog expressionComp pfe
;
operateurLog: et | ou
;
%%

int yyerror(char* msg)
{printf("%s ligne %d et colonne %d",msg,ligne,col);
return 0;
}
int main()
{      
 yyparse();
 afficher();
 return 0;
}
yywrap(){}



