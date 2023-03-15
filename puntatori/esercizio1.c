#include <stdio.h>
#define N 5
void carica(int *array);
void stampa(int *array);
int ricerca(int *array, int x);

int main() {
    
    int array[N];
    int x;

    printf("Inserisci dei numeri:\n");
    carica(array);

    printf("\nNumeri inseriti:\n");
    stampa(array);

    printf("\nInserisci un numero da cercare:\n");
    scanf("%d", &x);
	int r;
	r=ricerca(array,x);
	if(r==-1)
	{
		printf("numero non trovato");
	}
	else
	{
		printf("numero trovato in posizione: %d\n",r);
	}
  	

    return 0;
}

void carica(int *array) {
    for (int i = 0; i < N; i++) 
	{
        scanf("%d",array + i);
    }
}

void stampa(int *array) {
    for (int i = 0; i < N; i++) {
        printf("%d ", *(array + i));
    }
}

int ricerca(int *array,  int x) {
    for (int i = 0; i < N; i++) {
        if (*(array + i) == x) {
            return i;
        }
    }
    return -1;
}
