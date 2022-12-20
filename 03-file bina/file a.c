/**************************************************************************************************************
* @brief GESTIONE DEI FILE BINARI                                                                             *
* <specifiche del progetto>                                                                                   *
* <specifiche del collaudo>                                                                                   *
*                                                                                                             *
* @author SIMONE ACCONCIA 4^H                                                                                 *
* @date 18/12/2022									                                                          *
* @version 1.0 <15/12/2022> <inserita la prima funzione: void inserisciRecord>                                *
* @version 1.1 <18/12/2022> <inserita funzione:stampaFile,ricercaRecord,stampaRecord,correggiRecord>          *                                                                                                      *
* @version 1.2 <19/12/2022> <correzione funzione: ricercaRecord>	                                          *
*@versione 1.3 <20/12/2022>	<correzione errori,inserimento funzione NumeroRecord	                          *
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

/** ****************************************************************************************
* @brief <la funzione inserisce le informazioni all'interno del record e le scrive su file>
* @param  <una stringa e un intero(char fileName[], int numRecord)>
* @retval <>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
*******************************************************************************************/

void inserisciRecord(char fileName[], int numRecord);

/** ****************************************************************************************
* @brief<la funzione stampa sul monitorle informazioni all'interno del record leggendole da file>
* @param  <una stringa  (char fileName[])>
* @retval <>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
*******************************************************************************************/


void stampaFile(char fileName[]);          

/** ****************************************************************************************
* @brief<la funzione controlla che il record abbia il campo cognome uguale al paramtro cognome, stampando in seuito età e media voti>
* @param  <due  stringhe  (char fileName[],char cognome[])>
* @retval <>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
* @version 1.1 <19/12/2022>
* @@version 1.2 <20/12/2022>
*******************************************************************************************/
         

int ricercaRecord(char fileName[], char cognome[]);  

/** ****************************************************************************************
* @brief<stampa le informazioni presenti nel record specificato dal parametro posizione>
* @param  <una stringa e un intero  (char fileName[],int posizione)>
* @retval <>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
* @version 1.1 <20/12/2022>
*******************************************************************************************/
         
                                                       

int stampaRecord(char fileName[], int posizione);   

/** ****************************************************************************************
* @brief< visualizza le informazioni del record richiamando la funzione stampaRecord e corregge l’intero record, con i nuovi dati richiesti all’utente>
* @param  <una stringa e un intero  (char fileName[],int posizione)>
* @retval <>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
* @version 1.1 <19/12/2022>
* @version 1.2 <20/12/2022>
*******************************************************************************************/
         


int correggiRecord(char fileName[], int posizione); 

/** ****************************************************************************************
* @brief<restituisce il numero di record presenti nel file.>
* @param  <una stringa  (char fileName[])>
* @retval <>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <20/12/2022>
*******************************************************************************************/


int numeroRecord(char fileName[]);

                                    


int main()
{

    //dichiarazione variabili

    FILE *f1;                                   //puntatore al file

    char NomeFile[MAX] ={"file.txt"};           //stringa usata per contenere il nome del file 
    
    int r;                                      //usata per richiamare funzioni di tipo int

    int pos;                                    //usata per la posizione del record

    int scelta;                                 //usata per fare una scelta all'interno del menù dello switch case

	char stringa [S];                           //usata come parametro cognome all'interno delle funzioni
    
    int s;
	
    //funzione inserimento record

	printf("inserisci il numero di studenti\n");
	
	scanf("%d",&pos);
	
    inserisciRecord(NomeFile,pos); 

    //funzione stampa file
    stampaFile(NomeFile);

    //funzione ricerca record
             
    printf("inserisci il cognome per effetuare la ricerca\n");
            
    scanf("%s",stringa);
            
    printf("\n");
                        
    r=ricercaRecord(NomeFile,stringa);
                   
    printf("posizione primo record trovato:%d\n",r);

    //funzione  stampaRecord

    printf("inserisci il numero di posizione del record per stamparlo\n");
            
    scanf("%d",&pos);
                        
    r=stampaRecord(NomeFile,pos);
                        
    if(r==0)        //controllo se il record è stato trovato la funzione restituisce 0
    {

    printf("RECORD PRESENTE\n");
                         
    }
                        
    else
    {
        printf("RECORD NON TROVATO\n");
    }
                
    //funzione correggirecord        

    printf("inserisci la posizione del record da modificare\n");
            
    scanf("%d",&pos);
                                
    printf("\n");
                                
    r=correggiRecord(NomeFile,pos);

    //funzione numero record
    
    r=numeroRecord(NomeFile);

    printf("il numero di record : %d\n",r);
    
   
    

}

void inserisciRecord(char fileName[], int numRecord) // fwrite
{
    FILE *f1;                           //puntatore al file

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"wb");            //apertura del file binario in scrittura

    int j;                              //contatore ciclo for per array di voti                        
    
    int i;                              //contatore ciclo for per il numero di record

    if(f1!=NULL)                        //controllo degli errori sull apertura file
    {
        for(i=0;i<numRecord;i++)

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

            fwrite(&buffer,sizeof(struct studente),1,f1);   /*con fwrite scrivo tutti i campi richiesti sopra 
                                                             su file
                                                            */
															
		}

		fclose(f1);                                         //chiusura file
    }

    else
    {
        printf("impossibile aprire");
    }

}


void stampaFile(char fileName[])
{
    FILE *f1;                           //puntatore al file

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j;                              //contatore per scorrere array voti
    
    int  n;                             //variabile per controllare se il file è stato letto

    if(f1!=NULL)                        //controllo degli errori sull apertura file
    {
        while(!feof(f1))
         {   
                n=fread(&buffer,sizeof(struct studente),1,f1);      //lettura del file
            
                if(n>0)                    //controllo se il file è stato letto
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
                
                

           
            
            }
                 
    }

}
    else
    {
        printf("impossibile aprire");
    }

	fclose(f1);

}


int ricercaRecord(char fileName[], char cognome[]) //se esistono più cognomi restituisco la posizione dell'ultimo trovato
 {
    FILE *f1;                           //puntatore al file

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;                            //contatore per il scorrere array di voti

    int c=0;                            //contatore struct letti

    int pos=0;                          //posizione primo record trovato
    
    int n;                              ////variabile per controllare se il file è stato letto

    int s;                              //variabile per sommare i voti e fare la media

    int m=0;                            //variabile per fare la media

    if(f1!=NULL)                        //controllo degli errori sull apertura file
    {
        while(!feof(f1))                //finnchè non finisce il primo file
         {
            n=fread(&buffer,sizeof(struct studente),1,f1);    //lettura del file di record
			
            c++;                                              //incremento contatore
            
            if(n>0)                    //controllo che il file è stato letto
            
            {
            	 if(strcmp(buffer.cognome,cognome)==0)       //controlla che il contenuto nel buffer cognome sia uguale alla variabile cognome
            
		            {
		                pos=c;                              /*passo il valore del contatore nella variabile
                                                              pos in modo tale da saper la posizione del record
                                                            */
		
		                printf("cognome: %s\n",buffer.cognome);
		                
		                printf("\n");
		
		                s=0;                                    //inizializzazione variabile somma a 0 per sommare i voti e calcolare la loro media
		              
		
		                for(j=0;j<V;j++)                        //scorro vettore dei voti
		                {
		                    s=s+buffer.voti[j];                 //somma dei voti
		                    
		                }
		
		                m=s/V;                                  //calcolo media

                        //stampa della media e età

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

    return pos;                                         //restituisce la posizione del record

}

int stampaRecord(char fileName[], int posizione) //chiedi spiegazione 
{
    FILE *f1;                           //puntatore al file

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int r;                              //dichiarazione variabile usata per richiamre funzione fseek

    int n;                              //variabile per controllare se il file è stato letto

    int j=0;                           //variabile usata per scorrrere array voti
    
  

    if(f1!=NULL)                          //controllo degli errori sull apertura file
    {
               
         r=fseek(f1,posizione*sizeof(struct studente),SEEK_SET);    //uso fseek per posizionarmi sullo struct 

            if(r==0)                                                //controllo errori fseek
                {
                    n=fread(&buffer,sizeof(struct studente),1,f1);  //lettura file

                    if(n>0)                                         //controllo che il file è stato letto
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
						return 0;                        //return 0  se il record è stato trovato                 
              	}
              	
              	  fclose(f1);

                
            
	}
	
    else
    {
        printf("impossibile aprire");
    }

	return -1;                                      //return -1 se il record non è stato trovato

}



int correggiRecord(char fileName[], int posizione)
{

    FILE *f1;                            //puntatore al file

    struct studente buffer;             //dichiarazione della variabile buffer di tipo struct studente

    f1=fopen(fileName,"rb");            //apertura del file binario in lettura

    int j=0;                            //variabile usata per scorrrere array voti
    
    int r;                              //controllo errori

   int pos;                              //posizione record

    if(f1!=NULL)                           //controllo degli errori sull apertura file
    {   
        r=fseek(f1,posizione*sizeof(struct studente),SEEK_SET); //uso fseek per posizionarmi sullo struct 


        if(r==0)                        //controllo errori fseek
        {

            printf("inserisci la posizione del record da stampare");

            scanf("%d",&pos);

            stampaRecord(fileName,pos);

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
            
            fwrite(&buffer,sizeof(struct studente),1,f1);       //scrittura su file dei campi inseriti sopra
        
        }

            fclose(f1);

    }

    else

    {
        printf("impossibile aprire");
    }

}



int numeroRecord(char fileName[])
{
	struct studente buffer;							    //dichiarazione di un record

	int r;			                                    //variabile per controllo errori

	int n=sizeof(buffer);								/*con la funzione sizeof ho la grandezza in 
                                                          byte del buffer
                                                        */
    
	int numerorecord;								    //numero record presenti

	FILE* f1;											//puntatore al file
	
	f1=fopen(fileName,"rb");						    //apertura del file binario in lettura
	
	if(f1!=NULL)										//se il file si apre
	{
		r=fseek(f1,0,2);								//posiziona il punatore alla fine del file

		r=ftell(f1);									//restituisce un intero che é la posizione corrente del puntatore.
		
		numerorecord=r/n;								//divido r e n per trovare il numero di record
		
		fclose(f1);									    //chude il file
		
		return numerorecord;							//restituisce il numero di record
		
	}
	else													
	{
		printf("impossibile aprire il file");
		                                   
	}
}

