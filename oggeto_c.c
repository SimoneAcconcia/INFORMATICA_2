/**************************************************************************************************************
* @brief scrivere un programma in c  usando un costruttore                                                    *
* <specifiche del progetto>                                                                                   *
* <specifiche del collaudo>                                                                                   *                                                                                                             *
* @author SIMONE ACCONCIA 4^H                                                                                 *
* @date   12/01/2023             								                                              *
* @version 1.0 <12/01/2023 > <scrivere un programma in c  usando un costruttore >                             *
/*************************************************************************************************************/


#include <cstdlib>
#include <iostream>				//libreria per input output 
#include <iomanip>
using namespace std;			//per funzioni cout e cin

class Frazione					//la classe per riconoscerla la scriviamo con la lettera maiuscola

{
	private : 					//dichiarazione attributi privati
	
	int numeratore;
	int denominatore;
	
	public :
	
	Frazione (){}					//metodo costruttore si riconosce perchè ha lo stesso nome della classe
	
	void Setnumeratore(int n)	//tramite  set possiamo usare attributi privati
	{
		numeratore=n;
	}
		
	void Setdenominatore(int d)	//tramite  set possiamo usare attributi privati	
	{
		denominatore = d;
	}
		
	int Getnumeratore ()		//tramite la funzione get restituiamo den e numeratore nel main
	{
		return numeratore;
	}
		
	int Getdenominatore ()
	{
		return denominatore;
	}
		
	void stampa()				//stampa a video la frazione	
	{
		cout<<"il numeratore:"<<numeratore<<endl;
		cout<<"il denominatore:"<<denominatore<<endl;
		cout<<numeratore<<"/"<<denominatore<<endl;
			
	}
		
		
	
};

int main()
{
	Frazione f1;		//definizione dell'oggetto
	
	f1.Setnumeratore(12);
	f1.Setdenominatore(5);
	f1.stampa()	;
	system ("pause");
	
	
}
