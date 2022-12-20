/**************************************************************************************************************
* @brief GESTIONE DEI FILE BINARI                                                                             *
* <specifiche del progetto>                                                                                   *
* <specifiche del collaudo>                                                                                   *
*                                                                                                             *
* @author SIMONE ACCONCIA 4^H                                                                                 *
* @date 18/12/2022									                                                          *
* @version 1.0 <15/12/2022> <inserita la prima funzione: void inserisciRecord>                                *
* @version 1.1 <18/12/2022> <inserita funzione:stampaFile,ricercaRecord,stampaRecord,correggiRecord>          *                                                                                                      *
* @version 1.2 <19/12/2022> <correzione funzione: ricercaRecord>							                  *
/*************************************************************************************************************/


//inclusione delle librerie

#include <stdio.h>       //inclusione libreria per input output   

#include <stdlib.h>	    //per l'utilizzo di system

#include <string.h>     //inclusione libreria per le stringhe


//define
#define S 50            //costante  utilizzata per definire spazio delle stringhe

#define V 8             //costante usata per l'array voti contenuto in struct studente

#define MAX 50          //costante con 50 utilizzata per definire spazio delle stringhe contenenti il nome del file


//dichiarazione dei campi di struct data

struct data              //struct data contiene informazioni sulla data di nascita
{
    int giorno;
    char mese[S];
    int anno ;

}typedef data;


//dichiarazione dei campi di struct studente


struct studente        
{
    int matricola;
    char cognome[S];
    int voti[V];
    data nascita;

}typedef studente;

//dichiarazione delle funzioni

void inserisciRecord(char fileName[], int numRecord); /*inserisce in coda n record con i dati 
                                                        richiesti all’utente, i parametri della funzione 
                                                        sono: una stringa contenente il nome del file,
                                                        il numero di record in cui inserire i campi
                                                     */ 

void stampaFile(char fileName[]);                     /*stampa su monitor  tutte le 
                                                        informazioni contenute nel file
                                                        i parametri sono: 
                                                        una stringa contenente il nome del file
                                                    */            

int ricercaRecord(char fileName[], char cognome[]);  /*la funzione controlla che il record abbia il 
                                                       campo cognome uguale al parametro,in questo caso stampa cognome,
                                                       età e media dei voti. 
                                                       La funzione restituisce la posizione 
                                                       del primo record trovato. 
                                                       i suoi parametri sono:
                                                       una stringa contenente il nome del file,
                                                       una stringa contenente un cognome
                                                    */
                                                       

int stampaRecord(char fileName[], int posizione);   /* stampa le informazioni presenti nel record specificato dal parametro posizione. 
                                                       Restituisce 0 se il record è presente -1 altrimenti.
                                                       i parametri della funzione sono  una stringa contenente il nome del file,
                                                       un intero contenente la posizione del record da stampare
                                                       */


int correggiRecord(char fileName[], int posizione); /*  visualizza le informazioni del record richiamando 
                                                        la funzione stampaRecord e corregge l’intero record, 
                                                        con i nuovi dati richiesti all’utente. i parametri sono:
                                                        una stringa contenente il nome del file,
                                                        un intero contenente la posizione del record da correggere
                                                    */


int numeroRecord(char fileName[]);

                                    


int main()
{
    FILE *f1;                                   //puntatore al file

    char NomeFile[MAX] ={"file.txt"};           //stringa usata per contenere il nome del file 

    inserisciRecord(NomeFile,1);                //richiamo della funzione inserisciRecord
    
    int r;                                      //usata per richiamare funzioni di tipo int

    int pos;                                    //usata per la posizione del record

    int scelta;                                 //usata per fare una scelta all'interno del menù dello switch case

	char stringa [S];                           //usata come parametro cognome all'interno delle funzioni
    
    printf("1: inserisci record\n");

	printf("2: stampa record\n");

    printf("3: ricerca record");

    printf("4: stampa del record");

    printf("5: correzzione record");

    scanf("%d",&s);

    switch(s)
    {
        case 1:
                inserisciRecord(NomeFile,1); 
        break





    }
    


	printf("inserisci il numero di posizione del record per stamparlo\n");
	
	scanf("%d",&pos);
	
 	r=stampaRecord(NomeFile,pos);
 	
 	if(r==0)
 	{
 		printf("RECORD PRESENTE\n");
 		
 		
	}
	
    else
    {
    	printf("RECORD NON TROVATO\n");
	}
	
	
	/*printf("inserisci la posizione del record da modificare\n");
	
	scanf("%d",&pos);
	
	printf("\n");
	
	r=correggiRecord(NomeFile,pos);
	
	
	*/
	
    
    

}

void inserisciRecord(char fileName[], int numRecord) // fwrite
{
    FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"wb");            //apertura del file binario in scrittura

    int j=0;
    
    int i;

    if(f1!=NULL)                           //controllo degli errori sull apertura file
    {
        for(i=0;i<numRecord;i++)

       { //inserimento di tutti i campi di struct data e studente
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
		
		printf("\n");
		
        printf("inserisci giorno\n");

        scanf("%d",&buffer.nascita.giorno);
        
        printf("\n");

        printf("inserisci mese\n");

        scanf("%s",&buffer.nascita.mese);
        
        printf("\n");

        printf("inserisci anno\n");

        scanf("%d",&buffer.nascita.anno);
        
        printf("\n");

        fwrite(&buffer,sizeof(struct studente),1,f1);
    }

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
    
    int  n;

    if(f1!=NULL)                           //controllo degli errori sull apertura file
    {
        while(!feof(f1))
         {   
                n=fread(&buffer,sizeof(struct studente),1,f1);
            
                if(n>0)                    //stampa solo una volta l'ultimo record
            {
                //stampa di tutti i campi di struct data e studente

                printf("numero matricola: %d\n",buffer.matricola);
                
                printf("\n");

                printf("cognome: %s\n",buffer.cognome);
                
                printf("\n");

                for(j=0;j<V;j++)
                {
                    printf("voti: %d\t\t",buffer.voti[j]);
                    
                    
                }
                
                printf("\n");
                
                printf("stampa giorno: %d\n",buffer.nascita.giorno);
                
                printf("\n");

                printf("stampa mese: %s\n",buffer.nascita.mese);
                
                printf("\n");

                printf("stampa anno: %d\n",buffer.nascita.anno);
                
                printf("\n");

           
            
            }
                
                fclose(f1);
    }

}
    else
    {
        printf("impossibile aprire");
    }


}


int ricercaRecord(char fileName[], char cognome[]) //se esistono più cognomi restituisco la posizione dell'ultimo trovato
 {
    FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;                            //contatore per il for voti

    int c=0;                            //contatore struct letti

    int pos=0;                          //posizione primo record trovato
    
    int n;

    int s;                              //variabile per sommare i voti e fare la media

    int m=0;                            //variabile per fare la media

    if(f1!=NULL)                           //controllo degli errori sull apertura file
    {
        while(!feof(f1))                //finnchè non finisce il primo file
         {
            n=fread(&buffer,sizeof(struct studente),1,f1);    //lettura del file di record
			
            c++;
            
            if(n>0)
            
            {
            	 if(strcmp(buffer.cognome,cognome)==0)       //controlla che il contenuto nello struct cognome sia uguale alla variabile cognome
            
		            {
		                pos=c;            
		
		                printf("cognome: %s\n",buffer.cognome);
		                
		                printf("\n");
		
		                s=0;                                    //inizializzazione variabile somma a 0 per sommare i voti e calcolare la loro media
		              
		
		                for(j=0;j<V;j++)                        //scorro vettore dei voti
		                {
		                    s=s+buffer.voti[j];
		                    
		                }
		
		                m=s/V;
		
		                printf("la media dei voti :%d\n",m);
		                
		                printf("\n");
		
		                printf("stampa giorno: %d\n",buffer.nascita.giorno);
		                
		                printf("\n");
		
		                printf("stampa mese: %s\n",buffer.nascita.mese);
		                
		                printf("\n");
		
		                printf("stampa anno: %d\n",buffer.nascita.anno);
		                
		                printf("\n");
		                
					}
			}
            
            
         }




		fclose(f1);
    }

    else
    {
        printf("impossibile aprire");
    }

    return pos;

}

int stampaRecord(char fileName[], int posizione) //chiedi spiegazione 
{
    FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int r;                              //dichiarazione variabile usata per richiamre funzione fseek

    int n;

    int j=0;                           //variabile usata per scorrrere array voti
    
  

    if(f1!=NULL)                          //controllo degli errori sull apertura file
    {
               
         r=fseek(f1,posizione*sizeof(struct studente),SEEK_SET);    //uso fseek per posizionarmi sullostruct

            if(r==0)
                {
                    n=fread(&buffer,sizeof(struct studente),1,f1);

                    if(n>0)     
                    {
                        printf("numero matricola: %d\n",buffer.matricola);

                        printf("cognome: %s\n",buffer.cognome);

                        for(j=0;j<V;j++)
                        {
                            printf("stampa  voti: %d\n",buffer.voti[j]);
                            

                        }

                        printf("stampa giorno di nascita: %d\n",buffer.nascita.giorno);

                        printf("stampa mese di nascita: %s\n",buffer.nascita.mese);

                        printf("stampa anno di nascita: %d\n",buffer.nascita.anno);

                    }
						return 0;
              	}
              	
              	  fclose(f1);

                
            
	}
	
    else
    {
        printf("impossibile aprire");
    }

	return -1;

}



int correggiRecord(char fileName[], int posizione)
{

    FILE *f1;

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;                            //variabile usata per scorrrere array voti
    
    int r;

    if(f1!=0)                           //controllo degli errori sull apertura file
    {   
        r=fseek(f1,posizione*sizeof(struct studente),SEEK_SET);

        if(r==0)
        {
            stampaRecord(fileName,'acconcia');

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

            printf("inserisci il giorno di nascita\n");

            scanf("%d",&buffer.nascita.giorno);

            printf("inserisci  il mese di nascita\n");

            scanf("%s",&buffer.nascita.mese);

            printf("inserisci anno di nascita\n");

            scanf("%d",&buffer.nascita.anno);

            r=fseek(f1,posizione*sizeof(struct studente),SEEK_SET);
            
            fwrite(&buffer,sizeof(struct studente),1,f1);
        
        }

            fclose(f1);

    }

    else

    {
        printf("impossibile aprire");
    }

}

/*int numeroRecord(char fileName[])
{





    
}
*/
