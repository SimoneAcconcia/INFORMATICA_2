#include <stdio.h>                  
#include <stdlib.h>
#include <string.h>
#define S 50
#define V 3
#define MAX 50

struct data
{
    int giorno;
    char mese[S];
    int anno ;

}typedef data;




struct studente
{
    int matricola;
    char cognome[S];
    int voti[V];
    data nascita;

}typedef studente;



void inserisciRecord(char fileName[], int numRecord); /*inserisce in coda n record con i dati richiesti all’utente. Se il file non esiste va creato 
                                                        e quindi effettuare l’inserimento. 
                                                    */ 


int main()
{
    FILE *f1;
    char NomeFile[MAX] ={"file.txt"};
    inserisciRecord(NomeFile,1);
    



}

void inserisciRecord(char fileName[], int numRecord) // fwrite
{
    FILE *f1;
    struct studente buffer;
    f1=fopen(fileName,"wb");
    int j=0;
    if(f1!=0)
    {
        printf("inserisci matricola\n");
        scanf("%d",&buffer.matricola);
        printf("\n");
        printf("inserisci cognome\n");
        scanf("%s",buffer.cognome);
        for(j=0;j<V;j++)
        {
            printf("inserisci voti\n");
            scanf("%d",&buffer.voti[j]);

        }
         printf("inserisci giorno\n");
        scanf("%d",&buffer.nascita.giorno);
        printf("inserisci mese\n");
        scanf("%s",&buffer.nascita.mese);
        printf("inserisci anno\n");
        scanf("%d",&buffer.nascita.anno);
        fwrite(&buffer,sizeof(struct studente),1,f1);
		fclose(f1);
    }

    else
    {
        printf("impossibile aprire");
    }

}