/***********************
Acconcia Simone        *       
4H                     *
04/10/2022			   *
**********************/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define N 2
#define S 20
#define V 8

struct s_alunno
{
	int matricola;
	char cognome[S];
	int voti [V];
	
}typedef s_alunno;

void carica(s_alunno []); // va passato  un array [] di tipo struct = s_alunno
void stampa(s_alunno []);



int main()
{
	s_alunno studenti[N] ; //stiamo dichiarando un array studente di tipo alunno
	carica(studenti);
	stampa(studenti);
}


void carica(s_alunno st [])
{
	int i,j;

	for(i=0;i<N;i++)
	{
		printf("inserisci numero matricola\n");
		scanf("%d",&st[i].matricola);
		printf("inserisci il cognome\n");
		scanf("%s",st[i].cognome);
		
		for(j=0;j<V;j++)
		{
			printf("inserisci un voto\n");
			
			scanf("%d",&st[i].voti[j]);
		}
		
	}
	
	
}


void stampa(s_alunno st [])
{
	int i,j;

	for(i=0;i<N;i++)
	{
		printf("numero matricola:\n");
		printf("%d",st[i].matricola);
		printf("\n");
		printf("cognome:\n");
		printf("%s\n",st[i].cognome);
		
		for(j=0;j<V;j++)
		{
			
			printf("%d\n",st[i].voti[j]);
		}
		
	}
	
 	
} 
