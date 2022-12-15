/***********************
Acconcia Simone        *       
4H                     *
05/10/2022
gestione array di struct*
**********************/

//dichiarazione librerie
#include <stdio.h>   	//libreria di input/output	
#include <stdlib.h> 

//definizione costanti
   
#define V 3 	    // V = numero di voti da inserire per ogni studente
#define S 50       //S = numero di caratteri disponibili per ogni singola stringa
#define N 2	      // N= numero di record dell' array
#define MAX 10   //MAX = numero massimo 10
#efine MIN  0   //MIN = numero minimo 0
//definizione struct

struct s_data
{
	int giorno;
	char mese[S];
	int anno;
	
	
	
}typedef s_data;




struct s_alunno     
{
	int matricola;     		
	char cognome[S];  	   //dichiarazione stringa che contiene cognome
	int voti[V];          //dichiarazione array
	s_data nascita;
	
}typedef s_alunno;

void carica(s_alunno []);  // funzione che carica s_alunno; parametri array di struct

void stampa(s_alunno []); //funzione che stampa s_alunno, parametri: array di struct

void media( s_alunno []); //funzione che stampa la media dei voti inseriti,


void carica(s_alunno st [])
{
	int i,j,media=1,s=0;

	for(i=0;i<N;i++)
	{
		
		printf("inserisci numero matricola\n");
		scanf("%d",&st[i].matricola);
		printf("\n\n");
		printf("inserisci il cognome\n");
		scanf("%s",st[i].cognome);
		printf("\n\n");
		
		printf("inserisci tre voti\n");
		
		for(j=0;j<V;j++)
		{	
			
			scanf("%d",&st[i].voti[j]);
		
		}
		
		
		printf("\n\n");
		printf("il giorno di nascita\n");
		scanf("%d",&st[i].nascita.giorno);
		printf("\n\n");
		printf("il mese\n");
		scanf("%s",st[i].nascita.mese);
		printf("\n\n");
		printf("l'anno\n"),
		scanf("%d",&st[i].nascita.anno);
		
	}
	
	
}


void stampa(s_alunno st [])
{
	int i,j;

	for(i=0;i<N;i++)
	{
		printf("numero matricola:");
		printf("\n\n");
		printf("%d",st[i].matricola);
		printf("\n\n");
		for(j=0;j<V;j++)
		{	
			printf("voti");
			printf("%d\n",st[i].voti[j]);
		
		}
		printf("inserisci il giorno di nascita");
		printf("%d\n",st[i].nascita.giorno);
		printf("\n\n");
		printf("inserisci il mese\n");
		printf("%s\n",st[i].nascita.mese);
		printf("\n\n");
		printf("inserisci l'anno\n"),
		printf("%d\n",st[i].nascita.anno);
		printf("\n\n");
			
	}
	
}

void media( s_alunno  st [])
{
	int s,media=0,i,m=0,j;

	for(i=0;i<N;i++) 		//scorro array studenti
	{
			s=0;
			for(j=0;j<V;j++)
			{
				s=s+st[i].voti[j];
				
			}
			media=s/V;

		printf("la media:%d\n",media);
		
			
	}
	
	
	
	
}

int main()
 {
 	int i=0;
 	s_alunno studenti[N];
 	carica(studenti);
 	system("cls");
 	stampa(studenti);
 	media(studenti);
 	
 
 	
 	
 }
