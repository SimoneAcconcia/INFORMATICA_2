#include <iostream>
#include <math.h>
#include "rettangolo.h"

using namespace std;

Rettangolo::Rettangolo()	//inizializza gli attributi privati ad uno
{
	base=1;
	altezza=1;
}

Rettangolo::Rettangolo(double b ,double a)
{
	base=b;
	altezza=a;
}

//metodi get e setter

void  Rettangolo::SetAltezza(double a)
{
	altezza =a;
}

void  Rettangolo::SetBase(double b)
{
	base = b;
}


double  Rettangolo::GetAltezza ()
{
	return altezza;
}

double  Rettangolo::GetBase ()
{
	return base; 
}

//metodi per calcolare area,perimetro,diagonale

double  Rettangolo::CalcolaPerimetro() //USO GLI ATTRIBUTI E NON PARAMETRI  perchè lavoro sugli oggetti
{
	return (altezza)*2+(base)*2;
}

double  Rettangolo::CalcolaArea()
{
	return (base*altezza);
}

double  Rettangolo::calcolaDiagonale()
{
	return sqrt(base*base+altezza*altezza);
}
void Rettangolo::test(int numero)
{
	
}

void Rettangolo::stampa()
