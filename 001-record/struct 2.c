/***********************
Acconcia Simone        *       
4H                     *
04/10/2022			   *
**********************/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define N 5
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
	s_alunno studenti[N]  //stiamo dichiarando un array studente di tipo alunno
	
}


void carica(s_alunno st [])
{
	int i,j;

	for(i=0;i<N;i++)
	{
		printf("inserisci numero matricola");
		scanf("%d",&st[i].matricola);
		printf("inserisci il cognome");
		scanf("%s",st[i].cognome);
		
		for(j=0;j<V;j++)
		{
			printf("inserisci un voto"):
			scanf("%d",&st[i].voti[j]);
		}
		
	}
	
	
}


void carica(s_alunno st [])
{
	int i,j;

	for(i=0;i<N;i++)
	{
		printf("inserisci numero matricola");
		printf("%d",st[i].matricola);
		printf("inserisci il cognome");
		printf("%s",st[i].cognome[S]);
		
		for(j=0;j<V;j++)
		{
			printf("inserisci un voto"):
			scanf("%d",&st[i].voti[j]);
		}
		
	}
	
	
}
