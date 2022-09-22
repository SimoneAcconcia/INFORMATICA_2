/***********************
Acconcia Simone        *       
4H                     *
15/09/2022             *
**********************/
//dichiarazione librerie e costanti

#include <stdio.h> 		       // libreria input/output
#include <stdlib.h>           //
#include <time.h>  		     // libreria per generare numeri casuali
#include <limits.h> 	    // contiene  due costanti INT_MAX, INT_MIN
#define R 3 			   // costante per le righe della matrice
#define C 3 	 	  //costante per le colonne della matrice
#define max 100  	  	 // costante per generare il massimo numero casuale 
#define min 0			// costante per generare il minimo numero casuale 


//funzione che carica il vettore con numeri casuali
void carica_randomvettore(int vet[],int dim); //parametri: vettore e dimensione vettore

//richiama la funzione carica vettore per caricare la matrice											
void carica_randommat(int mat[][C], int colonne);//parametri: matrice e dimensione colonne

//funzione stampa
void stampa(int mat[][C],int r,int c); //parametri: matrice e dimensione righe e colonne

//funzione che carica il vettore da tastiera
void carica_manualevet(int vet[],int dim); //parametri: vettore e dimensione vettore

//funzione che richiama la carica da tastiera del vettore
void carica_manualemat(int mat[][C] ,int colonne);  //parametri: matrice e dimensione colonne

//ordina in ordine crescente il vettore
void ordinamento_vettore(int vet[],int dim);//parametri: vettore e dimensione vettore

//ordina le righe della riga chiesta dall'utente della matrice
void ordinamento_conriga(int mat[][C] ,int r,int c); //parametri: matrice e dimensione righe e colonne

//ricerca maggiore
int maggiore(int mat[][C],int riga,int colonne); //parametri: matrice e dimensione righe e colonne

//ricerca minore
int minore(int mat[][C],int riga,int colonne); //parametri: matrice e dimensione righe e colonne

//inserimento ordinato ogni volta che si inserisce un numero il vettore è ordinato
void inserimento_ordinato(int vet[],int r); //parametri: vettore e dimensione vettore

//ricerca un numero all'interno del vettore la riga è scelta dall'utente
int ricercaingenua(int vet[],int dim,int x); //parametri: vettore ,dimensione vettore ,numero da ricercare all'interno del vettore

//funzioni colonne

void caricaColrandom(int mat[][C],int r,int x); //carica colonna

void caricaColtastiera(int mat[][C],int r,int x); // carica tastiera

void stampaCol(int mat[][C],int r,int x); // stampa colonna

int ricercaCol(int mat[][C],int r,int x,int y); // funzione ricerca su una colonna indicata 

int main()
{

	int matrice[R][C],a,b,r;
	
    // carica randon   
	srand(time(NULL));
	printf("\n\n");
    printf("generazione numeri casuali matrice\n\n");
    carica_randommat(matrice,C);
    stampa(matrice,R,C);
    
    // carica manuale   
    printf("inserisci dei numeri\n\n");
    carica_manualemat(matrice,C);
    stampa(matrice,R,C);
    
    // ricerca ingenua su riga
    printf("inserisci la riga su cui vuoi ricercare l'elemento\n");
    scanf("%d\n",&a);
    printf("inserisci il numero da cercare\n");
    scanf("%d\n",&b);
    r=ricercaingenua(matrice[a],R,b);
    printf("%d\n",r);
    
    
    //ordinamento per riga
    printf("inserisci la riga su cui vuoi riordinare\n'");
    scanf("%d\n",&a);
    ordinamento_conriga(matrice,a,C); 
    stampa(matrice,R,C);
    
    //ricerca maggiore e minore nella matrice
    r=maggiore(matrice,R,C);
  	printf(" il maggiore:%d\n",r);
  	r=minore(matrice,R,C),
    printf(" il minore:%d\n",r);
    
    // caricamento su colonna
    printf("inserisci la colonna su cui vuoi caricare la matrice\n");
    scanf("%d\n",&a);
    caricaColrandom( matrice,R,a);
    stampa(matrice,R,C);
    
    //carica colonna da tastiera
    printf("inserisci la colonna su cui vuoi caricare la matrice\n");
    scanf("%d\n",&a);
    caricaColtastiera(matrice,R,a);
    stampa(matrice,R,C);
    
    //stampa colonna 
	printf("inserisci la colonna che vuoi stampare\n");
	scanf("%d",&a);
	stampaCol(matrice,R,a);
	
	// ricerca ingenua su colonna
	printf("inserisci la colonna dove effettuare la ricerca\n e il numero da cercare\n");
	scanf("%d\n%d\n",&a,&b);
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
	 	printf("%d ",mat[i][j]);
	 } printf("\n");
		
	}
	
}
void carica_randommat(int mat[][C], int colonne)
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
	
	for(i=0;i<dim;i++)
	{
		
		scanf("%d\n",&vet[i]);
		
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

