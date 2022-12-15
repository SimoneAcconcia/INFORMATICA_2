#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define V 5


struct data
{
	int giorno;
	char mese[N];
	int anno;
	
	
}typedef data;

struct  s_alunno
{
	int matricola;
	char cognome [N] ;
	int voti [V];
	data nascita ;
	
} typedef s_alunno ;

 /*struct s_copia
{
	
	
	
}typdef s_copia;
*/
void inserimento(s_alunno*st1);
void stampa(s_alunno st1);
//void copia_record(s_alunno st1, s_copia st2);
int main()
{
	s_alunno st1 ;     //spazio allocato sulla ram con più campi
	//s_copia st2;						
	inserimento(&st1);
	stampa(st1);
//	copia_record(st1,st2);
	

	
	
}


void inserimento(s_alunno*st1)
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
	
	printf("inserisci il giorno di nascita\n\n");
	scanf("%d",&st1->nascita.giorno);
	printf("inserisci il mese di nascita\n\n");
	scanf("%s",st1-> nascita.mese);
	printf("inserisci l'anno di nascita\n'");
	scanf("%d",&st1->nascita.anno);
	
	
}
void stampa(s_alunno st1)
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
	
	printf("giorno di nascita:");
	printf("%d\n",st1.nascita.giorno);
	printf("mese di nascita matricola:\n");
	printf("%s\n",st1.nascita.mese);
	printf("anno di nascita:\n");
	printf("%d",st1.nascita.anno);
	
}

/*void copia_record(s_alunno st1, s_copia st2)
{
	st2=st1;
	
}
*/
