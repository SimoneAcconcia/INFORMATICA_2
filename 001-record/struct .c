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

void inserimento(s_alunno*st1);
void stampa(s_alunno*st1);
int main()
{
	s_alunno st1        //spazio allocato sulla ram con più campi
	inserimento(&st1);
	stampa(st1);
	
}


void inserimento(s_alunno*st1)
{	int i=0;;
	printf("inserisci il numero della matricola\n\n");
	scanf("%d",&st1->matricola);
	scanf("%s",st1->cognome);
	printf("inserisci un voto");
	for(i=0;i<V;i++)
	{
		scanf("%d",&st1->voti[i]);
	}
	
	
}
void stampa(s_alunno*st1)
{
	int i=0;;
	printf("numero matricola:%d\n");
	printf("%d\n",st1->matricola);
	printf("%s\n",st1->cognome);
	printf("stampa dei voti\n");
	for(i=0;i<V;i++)
	{
		scanf("%d\n",&st1->voti[i]);
	}
	
	
}
