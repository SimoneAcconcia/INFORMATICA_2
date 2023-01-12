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
using namespace std;			//per funzioni coute cin

class Frazione					//classe frazione contiene gli attributi numeratore e denominatore
{
	private:					//attributi privati

	//definizione attributi di classe
	
	int numeratore;
	int denominatore;
	
	public : 					//attributi pubblici
	
	Frazione ()
	{
		
	}
	
	
		void setNumeratore (int n)	//serve per avvalorare il campo numeratore 
		{
			numeratore=n;	
		}
	
		void setDenominatore (int d)
		{
			denominatore = d; 
		}
		
		void getNumeratore ()
		{
			return numeratore;
		}
	
		void getDenominatore ()
		{
			return denominatore;
		}
		
		void stampa ()
		{
			cout<<numeratore<<"/"<<denominatore;
		}
	

	
	
};

int main ()
{
	frazione f1 ;			//definizione oggetto
	f1.setNumeratore(12);
	f1.setDenominatore(3);
	f1.stampa();
	
	
}
