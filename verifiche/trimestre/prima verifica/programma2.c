//acconcia simone 4H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define R 10
#define C 10
int Cerca(int v[ ], int k);
int Somma (int m [ ] [ C ], int x);
int ContaMaggiori (int m [ ] [ C ], int h, int k );
void Ordina(int m [ ] [ C ]);
void carica(int m[][C]);
void stampa(int m[][C]);

int Cerca(int v[ ], int k)
{
	int i;
	for(i=0;i<C;i++) //avevi messo R ma è sbagliato
	{
		if(v[i]>=k)
		{
			return 1;
		}
	}
	return 0;
	
}

int Somma (int m [ ] [ C ], int x)
{
	int i,j,s=0;
	for(i=0;i<R;i++)
	{
		if(m[i][x]==2)  
		{
			s=s+m[i][x];
		}
	}
	return s;
}

int ContaMaggiori (int m [ ] [ C ], int h, int k )
{
	int c=0,i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(m[i][j]>=h && m[i][j]<=k)
			{
				c++;
			}
		}
	}
	
	return c;
}

void Ordina(int m [ ] [ C ]) //rivedi
{
	int v[R*C],i,j,s=0,scambio,t;
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			v[s]=m[i][j];
			s++;
		}
	}
	
	i=0;
	
	do
	{
		scambio=0;
		for(i=0;i<R*C;i++)
		{
		if(v[i]>v[i+1])
		{
		t=v[i];
		v[i]=v[i+1];
		v[i+1]=t;
		scambio=1;
		}
	    }
	}while(scambio==1);
	
	s=0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			m[i][j]=v[s];
			s++;
		}
	}
}
	
void carica(int m[][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
}

void stampa(int m[][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%d\n",m[i][j]);
		}
	}
}

int main()
{
	int mat [R][C];
	int r,a;
	carica(mat);
	stampa(mat);
	r=Cerca(mat[0],5);
	printf("%d",r)	;
	printf("inserisci la riga ");
	scanf("%d",&a);
	r=Cerca(mat[a],5);
	printf("%d",r)	;
	printf("inserisci intero ");
	scanf("%d",&a);
	r=Somma (mat,a);
	printf("%d",r);
	r=ContaMaggiori(mat,20,50);
	printf("%d",r);
//	Ordina(mat);
	
}
