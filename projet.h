// Programmation de la table des symboles
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //Déclatarion de la structure
		typedef struct
		{
		char NomEntite[20];
		int TypeEntite;
		int nature;
		} TypeTS;
//Déclaration de la table des symboles sous forme de liste chainee
		typedef struct TS
		{
    		TypeTS tabS;
    		struct TS *svt;
		}TS;
//Initialisation de la table des symboles        
TS *TableSymbole=NULL,*r,*q; 
		//Declarer un compteur global
        int CompteurTS=0;
 //Definir la fonction recherche
		TS *recherche(char name[20])
		{
		int i=0;
		TS *ll=TableSymbole;
		
	     while((ll!= NULL) && (strcmp(ll->tabS.NomEntite,name) != 0)){
           ll = ll->svt;}
           return ll;
        }
/* Fonction qui insère un élément en tête de liste */
int insert(char name[20],int type,int nature){
    if (recherche(name) == NULL)
     {
//Insérer dans la table des symboles
        if(TableSymbole==NULL)
			{
				TableSymbole = (TS *) malloc(sizeof (TS));
				strcpy(TableSymbole->tabS.NomEntite,name);
                TableSymbole->tabS.TypeEntite=type; 
				TableSymbole->tabS.nature=nature;
				CompteurTS++;
				TableSymbole->svt = NULL;
				q = TableSymbole;
			}
        else
			{
				r = (TS *) malloc(sizeof (TS));
                strcpy(TableSymbole->tabS.NomEntite,name);
                TableSymbole->tabS.TypeEntite=type; 
				TableSymbole->tabS.nature=nature;
                CompteurTS++;
				r->svt = NULL;
				q->svt = r;
				q = r;
            }
        return 1;
     }
    else {
          printf("erreur semantique, idf %s deja declare ",name);   return 0;
 }  
}
   //4-définir la fonction afficher
	  void afficher ()
	{
	printf("\n/***************Table des symboles ******************/\n");
	printf("_____________________________________________________\n");
	printf("\t| NomEntite |  typeEntite | nature\n");
	printf("_____________________________________________________\n");
	    TS *ll=TableSymbole;
	  while(ll!=NULL)
	  {
		printf("\t|%10s |%12s | %12s\n",ll->tabS.NomEntite,ll->tabS.TypeEntite,ll->tabS.nature);
		 ll=ll->svt;
	   }
	}


    int compatible_type(int type1,int type2){
       if(type1 != type2) {
       printf("erreur semantique, incompatibilite de type ");
      return 0;
       }
     return 1;
    }

	
    int doubleDeclaration(char entite[])
	{
	TS *pos;
	pos=recherche(entite);
	if(pos->tabS.TypeEntite==1 ||pos->tabS.TypeEntite==0) return 0;
	   else return -1;
	}
    



