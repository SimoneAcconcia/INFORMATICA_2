/** ****************************************************************************************
* \mainpage <nome del progetto>
*
* @brief <inserire una breve descrizione del progetto>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <autore>
* @date <data> 
* @version 1.0 26/1/23 versione iniziale
* @version 1.1 26/1/23 aggiungiamo il metodo test
*/

#include <iostream>	
#include <math.h>
#include "rettangolo.h"		
using namespace std;

int main()
{
	Rettangolo r1;
	r1.test(1);
	
	r1.SetAltezza(5);
	r1.SetBase(12);
	cout<<"base del primo rettangolo:"<<r1.GetBase()<<endl;
	cout<<"altezza del primo rettangolo:"<<r1.GetAltezza()<<endl;
	cout<<"calcolo area primo rettangolo:"<<r1.CalcolaArea()<<endl;
	cout<<"calcolo perimetro primo rettangolo :"<<r1.CalcolaPerimetro()<<endl;
	cout<<"calcolo diagonale obliquo primo rettangolo: "<<r1.calcolaDiagonale()<<endl;
	
	
	//secondo oggetto
	double b;
	double a;

	cout<<"inserisci base:"<<endl;
	cin>>b;
	cout<<"inserisci altezza"<<endl;
	cin>>a;
	Rettangolo r2(b,a);
	cout<<"base del secondo  rettangolo:"<<r2.GetBase()<<endl;
	cout <<"altezza del secondo rettangolo"<<r2.GetAltezza()<<endl;
	cout<<"calcolo area secondo rettangolo"<<r2.CalcolaArea()<<endl;
	cout<<"calcolo perimetro secondo rettangolo"<<r2.CalcolaPerimetro()<<endl;
	cout<<"calcolo diagonale obliquo secondo rettangolo"<<r2.calcolaDiagonale()<<endl;	
}
