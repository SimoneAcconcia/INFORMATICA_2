/**************************************************************************************************************
* @brief GESTIONE DEI FILE BINARI                                                                             *
* <specifiche del progetto>                                                                                   *
* <specifiche del collaudo>                                                                                   *
*                                                                                                             *
* @author SIMONE ACCONCIA 4^H                                                                                 *
* @date 18/12/2022									                                                          *
* @version 1.0 <15/12/2022> <inserita la prima funzione: void inserisciRecord>                                *
* @version 1.1 <18/12/2022> <inserita funzione:stampaFile,ricercaRecord,stampaRecord,correggiRecord>          *                                                                                                      *
*														                                                      *
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

void stampaFile(char fileName[]);                     /*stampa su monitor (una riga per record) tutte le 
                                                        informazioni contenute nel file; */            

int ricercaRecord(char fileName[], char cognome[]);  /*per ogni record che ha il contenuto del 
                                                       campo cognome uguale al parametro, stampa cognome,
                                                       età e media dei voti. 
                                                       La funzione restituisce la posizione 
                                                       del primo record trovato. 
                                                       */
                                                       

int stampaRecord(char fileName[], int posizione);

int correggiRecord(char fileName[], int posizione); 

int numeroRecord(char fileName[]);

                                    


int main()
{
    FILE *f1;                                   //puntatore al file

    char NomeFile[MAX] ={"file.txt"};           //stringa usata per contenere il nome del file 

    inserisciRecord(NomeFile,1);                //richiamo della funzione inserisciRecord
    
    int r;

	char stringa [S];
    
    //stampaFile(NomeFile); 
    
	//r=correggiRecord(NomeFile, 3);
	
	printf("inserisci il cognome per effetuare la ricerca\n");
	
	scanf("%s",stringa);
	
	printf("\n");
	
	r=ricercaRecord(NomeFile,stringa);
	
	printf("posizione primo record trovato:%d",r);

 	//r=stampaRecord(NomeFile, 3);
    
   // printf("%d",r);

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
                    printf("stampa  voti: %d\n",buffer.voti[j]);
                    printf("\n");
                    
                }

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

    int j=0;                           //variabile usata per scorrrere array voti

    if(f1!=0)                          //controllo degli errori sull apertura file
    {
               
         r=fseek(f1,posizione*sizeof(struct studente),SEEK_SET);    //uso fseek per posizionarmi 

            if(r==0)
                {
                    fread(&buffer,sizeof(struct studente),1,f1);
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
