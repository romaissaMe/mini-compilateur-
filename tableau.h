#include<stdio.h>
typedef struct{
	char NomEntite[20];
	char valeur[20];
	char TypeEntite[20];
	char natureEntite[20];
}tablest;
tablest ts[100];
int cpt=0;
int i=0;
//fonction recherche d une entite
	int recherche(char entite[])
	{
	int i=0;
	while(i<=cpt)
	{
	if (strcmp(entite,ts[i].NomEntite)==0) return i;
	i++;
	}
	return -1;
	}
// inserer une entite dans la table des symboles

void inserer(char entite[],char type[],char nature[])
	{

	if ( recherche(entite)==-1)
	{
	strcpy(ts[cpt].NomEntite,entite); 
	strcpy(ts[cpt].TypeEntite,type);
	strcpy(ts[cpt].natureEntite,nature);
	cpt++;
	}
	}
	// afficher la table des symboles
	void afficher ()
	{
	printf("\n/***************Table des symboles ******************/\n");
	printf("___________________________________________________________\n");
	printf("\t| NomEntite |  NatureEntite | TypeEntite| Valeur \n");
	printf("______________________________________________________________\n");
	int i=0;
	  while(i<cpt)
	  {
		printf("\t|%10s |%12s  |%12s |%10s\n",ts[i].NomEntite,ts[i].natureEntite,ts[i].TypeEntite,ts[i].valeur);
		 i++;
	   }
	}
	//fonction inserer type
	void insererType(char entite[], char type[])
	{
       int position;
	   position =recherche(entite);
	 if(position != -1)
	{
	strcpy(ts[position].TypeEntite,type); 
	
	}
	}
	//fonction inserer nature
	void insererNature(char entite[], char nature[])
	{
       int position;
	   position =recherche(entite);
	 if(position !=-1)
	{
	strcpy(ts[position].natureEntite,nature); 
	
	}
	}
	//inserer une valeur dans la table des symboles
	void insererVal(char entite[], char val[])
	{
       int position;
	   position =recherche(entite);
	 if(position !=-1)
	{
	strcpy(ts[position].valeur,val); 
	
	}
	else printf("l'entite n'existe pas");
	}
	// detecter la double declaration
	int doubleDeclaration(char entite[]){
		 int position;
   position =recherche(entite);
   //printf("position =%d\n",position);
   if(position==-1) return 0;
   else return -1;
	}
	//verifier compatibilite
int compatible_type(char type1[20],char type2[20]){
       if(strcmp(type1,type2)==0) {
       
      return 0;
       }
     return -1;
    }
	//verifier si l idf est non declarer
 int nonDeclare(char idf[]){
	 int i;
	 i = recherche(idf);
	 if(i==-1) return -1;
   else return 0;
 }
 //modification d une cst
 int cst(char idf[]){
	 int i;
	 i = recherche(idf);
	 if(strcmp(ts[i].natureEntite,"constante")==0) return 0;
   else return -1;
 }
