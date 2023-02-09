//Acconcia simone contatore doppio

#include<iostream>
using namespace std;

class Contatore 
{
	private:
	int valore;		//valore che gli viene assegnato
	int passo;		//passo di quanto aumento ogni volta
	
	public:
	Contatore()
	{
		valore=1;
		passo=1;
	}
	
	Contatore(int v,int p)
	{
		valore=v;
		passo=p;
	}
	
	void incrementa()
	{
		valore=valore+passo;
	}
	
	/*void visualizza ()
	{
		cout<<"il valore:"<<getValore()<<endl;
		cout <<"il passo"<<getPasso()<<endl;
		cout <<"contatore incrementato di:"<<incrementa()<<endl;
		
	}*/
	
	int getValore()
	{
		return valore;
	}
	int getPasso()
	{
		return passo;
	}
	void setPasso(int p)
	{
		passo=p;
	}
	void setValore(int v)
	{
		valore=v;
	}
		
};

class ContatoreDoppio :public Contatore
{
	public :
	ContatoreDoppio() : Contatore(){};
	void incrementa()
	{
		Contatore ::incrementa();
		Contatore ::incrementa();
	}
	
	
};

int main()
{
	
	Contatore  cont1(10,2);
	ContatoreDoppio cont2;
	
	cout<<"il valore del primo contatore:"<<cont1.getValore()<<endl;
	cout<<"il valore del secondo contatore:"<<cont2.getValore()<<endl;
	cout <<"il contatore ha un passo di:"<<cont1.getPasso()<<endl;
	cout <<"il contatore ha un passo di:"<<cont2.getPasso()<<endl;
	cont1.incrementa();
	cont2.incrementa();
	cout<<"contatore incrementato:"<<cont1.getValore()<<endl;
	cout<<"il valore del secondo contatore incrementato:"<<cont2.getValore()<<endl;

	

	
}
