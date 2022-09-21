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
void stampa(int mat[][C],int r,int c);

//funzione che carica il vettore da tastiera
void carica_manualevet(int vet[],int dim);

//funzione che richiama la carica da tastiera del vettore
void carica_manualemat(int mat[][C] ,int colonne);

//ordina in ordine crescente il vettore
void ordinamento_vettore(int vet[],int dim);

//ordina le righe della riga chiesta dall'utente della matrice
void ordinamento_conriga(int mat[][C] ,int r,int c);

//ricerca maggiore
int maggiore(int mat[][C],int riga,int colonne);

//ricerca minore
int minore(int mat[][C],int riga,int colonne);

//inserimento ordinato ogni volta che si inserisce un numero il vettore è ordinato
void inserimento_ordinato(int vet[],int r);

//ricerca un numero all'interno del vettore la riga è scelta dall'utente
int ricercaingenua(int vet[],int dim,int x);
//funzioni colonne
void caricaColrandom(int mat[][C],int r,int x);
void caricaColtastiera(int mat[][C],int r,int x);
void stampaCol(int mat[][C],int r,int x);
int ricercaCol(int mat[][C],int r,int x,int y); // funzione ricerca su una colonna indicata 
int main()
{

	int matrice[R][C],a,b,r;
	srand(time(NULL));
	printf("\n\n");
    printf("generazione numeri casuali matrice\n\n");
    carica_randommat(matrice,R,C);
    stampa(matrice,R,C);
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
    stampa(matrice,R,C);
  
  	r=maggiore(matrice,R,C);
  	printf(" il maggiore:%d\n",r);
  	r=minore(matrice,R,C),
    printf(" il minore:%d\n",r);
    printf("inserisci la colonna su cui vuoi caricare la matrice\n");
    scanf("%d",&a);
    caricaColrandom( matrice,R,a);
    stampa(matrice,R,C);
    printf("inserisci la colonna su cui vuoi caricare la matrice\n");
    scanf("%d",&a);
    caricaColtastiera(matrice,R,a);
    stampa(matrice,R,C);
	printf("inserisci la colonna che vuoi stampare\n");
	scanf("%d",&a);
	stampaCol(matrice,R,a);
	printf("inserisci la colonna dove effettuare la ricerca\n e il numero da cercare\n");
	scanf("%d%d",&a,&b);
	r=ricercaCol(matrice,R,a,b);
	printf("iil numero e' in posizione :'%d",r);
	//inserimento_ordinato(matrice,R);
	
}

void carica_randomvettore(int vet[], int dim)
{
	int i;
	for(i=0;i<dim;i++)
	{
		vet[i]=rand()%(max-min+1)+min;
	}
}
void stampa(int mat[][C],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
	 for(j=0;j<c;j++)
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

void ordinamento_conriga(int mat[][C] ,int r ,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		ordinamento_vettore(mat[i],c);
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

void caricaColrandom(int mat[][C],int r,int x)
{
	int j;

		for(j=0;j<r;j++)
		{
			mat[j][x]=rand()%(max-min+1)+min;
		}
	
	
}
void caricaColtastiera(int mat[][C],int r,int x)
{	int  i,j;
	printf("inserisci un numero");
	
		for(j=0;j<r;j++)
		{
			scanf("%d",&mat[j][x])	;
		}	
	
}
void stampaCol(int mat[][C],int r, int x)
{
	int j,i;
	for(i=0;i<r;i++)
	{
		printf("%d\n",mat[i][x]);
	}
}

int ricercaCol(int mat[][C],int r,int x,int y)
{
	int i,indice=-1;
	for(i=0;i<r;i++)
	{
		if(mat[i][x]==y)
		{
			indice=i;
		}
	}
	
	return indice;
	
}

//void inserimento_ordinato(int vet[],int r)
{
		
	int i,temp=0,j=0;

	for(i=1;i<10;i++)
	{ 
            temp=vet[i]; 
            j=i-1; 
            while(j>=0 && vet[j]>temp){
		vet[j+1]=vet[j];		
		j--;		
	}
	vet[j+1]=temp;
	}

	for(i=0;i<10;i++){
		printf("%d \t", vet[i]);
	}
		
}
