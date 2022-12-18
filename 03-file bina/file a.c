#include <stdio.h>       //inclusione libreria per input output           
#include <stdlib.h>	    /*questa libreria permette l'uso delle funzioni di altre librerie
						com time.h,limits.h
                        */
#include <string.h>     //inclusione libreria per le stringhe

//define
#define S 50            //costante con 50 utilizzata per definire spazio delle stringhe

#define V 3             //costante usata per l'array voti contenuto in struct studente

#define MAX 50          //costante con 50 utilizzata per definire spazio delle stringhe

//struct

struct data              //struct data contiene informazioni sulla data di nascita
{
    int giorno;
    char mese[S];
    int anno ;

}typedef data;




struct studente         //contiene informazioni riguardanti lo studente    
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
    FILE *f1;                                   //puntatore al file

    char NomeFile[MAX] ={"file.txt"};           //stringa usata per contenere il nome del file 

    inserisciRecord(NomeFile,1);                //richiamo della funzione inserisciRecord
    



}

void inserisciRecord(char fileName[], int numRecord) // fwrite
{
    FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"wb");            //apertura del file binario in scrittura

    int j=0;

    if(f1!=0)                           //controllo degli errori sull apertura file
    {

        //inserimento di tutti i campi di struct data e studente
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
