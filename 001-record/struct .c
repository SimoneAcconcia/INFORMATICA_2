#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define V 5
struct  s_alunno
{
	int matricola;
	char cognome [N] ;
	int voti [V];
	
} typedef s_alunno ;

struct s_nascita
{
	int giorno;
	char mese[N];
	int anno;
	
}typedef s_nascita;

void inserimento(s_alunno*st1,s_nascita *st2);
void stampa(s_alunno st1,s_nascita st2);
void copia_record(s_alunno st1,s_nascita st2);
int main()
{
	s_alunno st1 ;    
	s_nascita st2;	 //spazio allocato sulla ram con più campi
	inserimento(&st1,&st2);
	stampa(st1,st2);
	copia_record(st2,st);
	stampa(st1,st2);
	
	
}


void inserimento(s_alunno*st1,s_nascita *st2)
{	int i=0;
	printf("inserisci il numero della matricola\n\n");
	scanf("%d",&st1->matricola);
	printf("inserisci il cognome della matricola\n\n");
	scanf("%s",st1->cognome);
	
	for(i=0;i<V;i++)
	{	
		printf("inserisci un voto");
		scanf("%d",&st1->voti[i]);
	}
	
	/*printf("inserisci il giorno di nascita\n\n");
	scanf("%d",&st2->giorno);
	printf("inserisci il mese di nascita\n\n");
	scanf("%s",st2->mese);
	printf("inserisci l'anno di nascita\n'");
	scanf("%d",st2->anno);
*/	
	
}
void stampa(s_alunno st1,s_nascita st2)
{
	int i=0;
	printf("numero matricola:");
	printf("%d\n",st1.matricola);
	printf("cognome matricola:\n");
	printf("%s\n",st1.cognome);
	printf("stampa dei voti\n");
	for(i=0;i<V;i++)
	{
		printf("%d\n",st1.voti[i]);
	}
	
	/*printf("giorno di nascita:");
	printf("%d\n",st2.giorno);
	printf("mese di nascita matricola:\n");
	printf("%s\n",st2.mese[N]);
	printf("anno di nascita:\n");
	printf("%d",st2.anno);
*/	
}

void copia_record(s_alunno st1,s_nascita st2)
{
	st2=st1;
	
	
	
	
}

 


