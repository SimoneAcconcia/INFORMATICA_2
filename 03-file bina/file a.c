/**************************************************************************************************************
* @brief GESTIONE DEI FILE BINARI                                                                             *
* <specifiche del progetto>                                                                                   *
* <specifiche del collaudo>                                                                                   *
*                                                                                                             *
* @author SIMONE ACCONCIA 4^H                                                                                 *
* @date 18/12/2022									                                                          *
* @version 1.0 <15/12/2022> <inserita la prima funzione: void inserisciRecord>                                *                                                       *
														                                                      *
/*************************************************************************************************************/


//inclusione delle librerie

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



void inserisciRecord(char fileName[], int numRecord); /*inserisce in coda n record con i dati 
                                                        richiesti all’utente. 
                                                        Se il file non  esiste va creato 
                                                        e quindi effettuare l’inserimento. */ 

void stampaFile(char fileName[]);       /*stampa su monitor (una riga per record) tutte le 
                                          informazioni contenute nel file; */            

int ricercaRecord(char fileName[], char cognome[]);  /*per ogni record che ha il contenuto del 
                                                       campo cognome uguale al parametro, stampa cognome,
                                                       età e media dei voti. 
                                                       La funzione restituisce la posizione 
                                                       del primo record trovato. 
                                                       */
                                                       

int stampaRecord(char fileName[], int posizione);

int correggiRecord(char fileName[], int posizione); 

                                    


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


void stampaFile(char fileName[])
{
     FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;

    if(f1!=0)                           //controllo degli errori sull apertura file
    {
        while(!feof(f1))
         {   

            //stampa di tutti i campi di struct data e studente
            printf("numero matricola: %d\n",buffer.matricola);

            printf("cognome: %s\n",buffer.cognome);

            for(j=0;j<V;j++)
            {
                printf("stampa  voti: %d\n",buffer.voti[j]);
                

            }

            printf("inserisci giorno: %d\n",buffer.nascita.giorno);

            printf("inserisci mese: %s\n",buffer.nascita.mese);

            printf("inserisci anno: %d\n",buffer.nascita.anno);

            fread(&buffer,sizeof(struct studente),1,f1);
            
            }




		fclose(f1);
    }

    else
    {
        printf("impossibile aprire");
    }


}


int ricercaRecord(char fileName[], char cognome[]) //manca il return del record non capito
 {
    FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;

    int s;                              //variabile per sommare i voti e fare la media

    int m=0;                            //variabile per fare la media

    if(f1!=0)                           //controllo degli errori sull apertura file
    {
        while(!feof(f1))
         {
            if(strcpm(buffer.cognome,cognome)==0)       //controlla che il contenuto nello struct cognome sia uguale alla variabile cognome
            {
                printf("cognome: %s\n",buffer.cognome);
                s=0;
              

                for(j=0;j<V;j++)
                {
                    s=s+buffer.voti[j];
                    
                }

                media=s/V;
                printf("la media dei voti :%d\n",media);

                printf("inserisci giorno: %d\n",buffer.nascita.giorno);

                printf("inserisci mese: %s\n",buffer.nascita.mese);

                printf("inserisci anno: %d\n",buffer.nascita.anno);

                fread(&buffer,sizeof(struct studente),1,f1);
            }
            
            
         }




		fclose(f1);
    }

    else
    {
        printf("impossibile aprire");
    }

    return 

 }

int stampaRecord(char fileName[], int posizione) //chiedi spiegazione 
{
    FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;

    if(f1!=0)                           //controllo degli errori sull apertura file
    {
        while(!feof(f1))
         {
                if(buffer==posizione) 
                {
                   
                    printf("numero matricola: %d\n",buffer.matricola);

                    printf("cognome: %s\n",buffer.cognome);

                    for(j=0;j<V;j++)
                    {
                        printf("stampa  voti: %d\n",buffer.voti[j]);
                        

                    }

                    printf("inserisci giorno: %d\n",buffer.nascita.giorno);

                    printf("inserisci mese: %s\n",buffer.nascita.mese);

                    printf("inserisci anno: %d\n",buffer.nascita.anno);

                    fread(&buffer,sizeof(struct studente),1,f1);
                }
            
            
            
        }




		fclose(f1);
    }

    else
    {
        printf("impossibile aprire");
    }



}



int correggiRecord(char fileName[], int posizione)
{

     FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;

    if(f1!=0)                           //controllo degli errori sull apertura file
    {
       stampaRecord(FileName,acconcia);

        fclose(f1);
    }

    else
    {
        printf("impossibile aprire");
    }



}