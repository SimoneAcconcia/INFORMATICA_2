/***********************
Acconcia Simone        *       
4H                     *
15/09/2022             *
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define R 3
#define C 3
#define max 100
#define min 0


//funzione che carica il vettore con numeri casuali
void carica_randomvettore(int vet[],int dim);

//richiama la funzione carica vettore per caricare la matrice											
void carica_randommat(int mat[][C], int righe,int colonne);

//funzione stampa
void stampa(int mat[][C]);

//funzione che carica il vettore da tastiera
void carica_manualevet(int vet[],int dim);

//funzione che richiama la carica da tastiera del vettore
void carica_manualemat(int mat[][C] ,int colonne);

//ordina in ordine crescente il vettore
void ordinamento_vettore(int vet[],int dim);

//ordina le righe della riga chiesta dall'utente della matrice
void ordinamento_conriga(int mat[][C] ,int righe,int colonne);

//ricerca maggiore
int maggiore(int mat[][C],int riga,int colonne);

//ricerca minore
int minore(int mat[][C],int riga,int colonne);

//ricerca un numero all'interno del vettore la riga è scelta dall'utente
int ricercaingenua(int vet[],int dim,int x);
//funzioni colonne
void caricaColrandom(int vet[],int dim);
void caricaColtastiera(int vet[],int dim);
void stampaCol(int vet[],int dim);

int main()
{

	int matrice[R][C],a,b,r;
	srand(time(NULL));
    printf("\n\n");
    printf("generazione numeri casuali matrice\n\n");
    carica_randommat(matrice,R,C);
    stampa(matrice);
    //carica_manualemat(matrice,C);
    //stampa(matrice);
    printf("inserisci la riga su cui vuoi ricercare l'elemento\n'");
    scanf("%d",&a);
    printf("inserisci il numero da cercare\n");
    scanf("%d",&b);
    r=ricercaingenua(matrice[a],R,b);
    printf("%d",r);
   printf("inserisci la riga su cui vuoi riordinare\n'");
    scanf("%d",&a);
    ordinamento_conriga(matrice,a,C); 
    stampa(matrice);
  
  	r=maggiore(matrice,R,C);
  	printf(" il maggiore:%d\n",r);
  	r=minore(matrice,R,C),
    printf(" il minore:%d\n",r);
   
}

void carica_randomvettore(int vet[], int dim)
{
	int i;
	for(i=0;i<dim;i++)
	{
		vet[i]=rand()%(max-min+1)+min;
	}
}
void stampa(int mat[][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
	 for(j=0;j<C;j++)
	 {
	 	printf("%d\n",mat[i][j]);
	 }
		
	}
	
}
void carica_randommat(int mat[][C], int righe,int colonne)
{
	int i;
	for(i=0;i<colonne;i++)
	{
		carica_randomvettore(mat[i],colonne);
		
	}
	
}

void carica_manualevet(int vet[],int dim)
{
	int  i;
	printf("inserisci un numero");
	for(i=0;i<dim;i++)
	{
		
		scanf("%d",&vet[i]);
		
	}
}
void  carica_manualemat(int mat[][C] ,int colonne)
{
	int i;
		for(i=0;i<colonne;i++)
		{
			carica_manualevet(mat[i],colonne);
		}
	
}

void ordinamento_vettore(int vet[],int dim)
{
	int app=0,scambio,i;
	do{
		scambio=0;
		for(i=0;i<dim-1;i++)
		{
			if(vet[i]>vet[i+1])
			{
				app=vet[i];
				vet[i]=vet[i+1];
				vet[i+1]=app;
				scambio=1;
			}
			
		}
		
	  }while(scambio==1);
	
	
}

void ordinamento_conriga(int mat[][C] ,int righe ,int colonne)
{
	int i;
	for(i=0;i<colonne;i++)
	{
		ordinamento_vettore(mat[righe],i);
	}
	
}




int ricercaingenua(int vet[],int dim,int x)
{
	int i,indice=-1;
	for(i=0;i<dim;i++)
	{
		if(vet[i]==x)	
		{
			indice=i;
		}
		
	}
	
	return indice;
}

int maggiore(int mat[][C],int riga,int colonne)
{
	int i,j,m=INT_MIN;
	for(i=0;i<riga;i++)
	{
		for(j=0;j<colonne;j++)
		{
			if(mat[i][j]>m)
			{
				m=mat[i][j];
			}
		}
	}
	
	return m;
}

int minore(int mat[][C],int riga,int colonne)
{
	int i,j,m=INT_MAX;
	for(i=0;i<riga;i++)
	{
		for(j=0;j<colonne;j++)
		{
			if(mat[i][j]<m)
			{
				m=mat[i][j];
			}
		}
	}
	
	return m;
}

