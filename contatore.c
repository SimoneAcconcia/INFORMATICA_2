//Acconcia simone contatore doppio

#include<iostream>
using namespace std;

class Contatore 
{
	private:
	int valore;		//valore che gli viene assegnato
	int passo;		//passo di quanto aumento ogni volta
	
	public:
	Contatore();
	
	Contatore(int,int);
	
	void incrementa()
	{
		valore=valore+passo;
	}
	
	void visualizza ()
	{
		cout<<"il valore:"<<getValore()<<endln;
		cout <<"il passo"<<getPasso()<<endln;
		cout <<"contatore incrementato di:"<<incrementa()<<endln;
		
	}
	
	int getValore();
	{
		return valore;
	}
	int getPasso();
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

class ContatoreDoppio :: class Contatore
{
	public :
	ContatoreDoppio(int n) : Contatore(n){};
	void incrementa()
	{
		void incrementa();
		void incrementa();
	}
	
	
}

int main()
{
	Contatore contatore(10);
	ContatoreDoppio contatore2(10) ;
	cout<<"il valore del primo contatore:"<<contatore.getValore()<<endln;
	cout<<"il valore del secondo contatoreç:"<<contatore2.getValore()<<endln;
	
	
	
	
	
}
