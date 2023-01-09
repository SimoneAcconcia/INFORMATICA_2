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
* @brief <la funzione inserisciRecord inserisce le informazioni all'interno del record e le scrive su file>
* @param  <una stringa (il nome del file) e un intero (quanti record inserire)>
* @retval <restituisce 0 se la funzione è andata a buon fine , -1 se  ci siono errori>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
*******************************************************************************************/
int inserisciRecord(char fileName[], int numRecord);



/******************************************************************************************
* @brief<la funzione stampaFile visualizza sul monitor le informazioni di tutti i  record del file>
* @param  <una stringa (nome del file)>
* @retval <restituisce 0 se la funzione è andata a buon fine , -1 se  ci siono errori>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
*******************************************************************************************/
int stampaFile(char fileName[]); 


         

/** ****************************************************************************************
* @brief<la funzione ricercaRecord trova il record con il campo cognome uguale al  secocondo parametro, stampando in seguito età e media voti>
* @param  <1° stringa (nome del file), 2° stringa ( cognome da cercare)>
* @retval < restituisce la posizione del record trovato; -2 se non trovato;-1 se errore su apertura file>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
* @version 1.1 <19/12/2022>
* @@version 1.2 <20/12/2022>
*******************************************************************************************/
int ricercaRecord(char fileName[], char cognome[]); 



 

/** ****************************************************************************************
* @brief< la funzione stampaRecord visualizza su monitor le informazioni presenti nel record specificato dal parametro posizione>
* @param  <1° stringa (nome del file),  un intero (posizione del record da stampare) >
* @retval <restituisce 0 se la funzione se il record è stato trovato , -1  se errore su apertura file; -2 se non è stato trovato il record>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
* @version 1.1 <20/12/2022>
*******************************************************************************************/
int stampaRecord(char fileName[], int posizione);  


 

/** ****************************************************************************************
* @brief<la funzione correggiRecord visualizza le informazioni del record richiamando la funzione stampaRecord e corregge l’intero record, con i nuovi dati richiesti all’utente>
* @param  <una stringa (nome del file) e un intero (posizione del record da corregere)>
* @retval <restituisce 0 se la funzione è andata a buon fine  , -1  se ci sono errori >
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <18/12/2022> 
* @version 1.1 <19/12/2022>
* @version 1.2 <20/12/2022>
*******************************************************************************************/
int correggiRecord(char fileName[], int posizione); 




/** ****************************************************************************************
* @brief< numeroRecord restituisce il numero di record presenti nel file.>
* @param  <una stringa (nome del file) >
* @retval <restituisce quanti record ci sono nel file; -1 se errori su apertura file>
* @see <>
* @author <Simone Acconcia>
* @version 1.0 <20/12/2022>
*******************************************************************************************/
int numeroRecord(char fileName[]);

                                    
