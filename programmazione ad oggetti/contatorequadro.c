	
//contatore quadro
#include <iostream>
using namespace std;

class Contatore
{
	private:
	int passo;		//di quanto incremento
	int valore;		//valore contatore
	
	public:
	Contatore()
	{
		passo=1;
		valore=1;
	}
	
	Contatore (int v,int p)
	{
		valore=v;
		passo=p;
		
	}
	
	void Setpasso(int p)
	{
		passo=p;
	}
	
	void Setvalore(int v)
	{
		valore=v;
	}
	
	void incrementa()
	{
		valore=valore+passo;
	}
	
	int GetPasso()
	{
		return passo;
	}
	
		int GetValore()
	{
		return valore;
	}
	
	
	
};

class ContatoreDoppio: public Contatore 	//contatore doppio sottoclasse di contatore
{
	public:
	ContatoreDoppio():Contatore(){}  	//richiama metodo costruttore superclasse		
	void incrementa()
	{
		Contatore::incrementa();		//richiama il metodo incrementa ereditato da classe 1
		Contatore::incrementa();
	}
	
};

class ContatoreQuadruplo: public ContatoreDoppio
{
	public:
	ContatoreQuadruplo():ContatoreDoppio( ){}
	void incrementa()
	{
		ContatoreDoppio::incrementa();
		ContatoreDoppio::incrementa();
	
	}
	
};

int main()
{
	Contatore c1 ;
	ContatoreDoppio c2 ;
	ContatoreQuadruplo c3;
	c1.Setvalore(1);
	c1.Setpasso(1);
	c1.incrementa();
	
	cout<<"il valore post incremento"<<c1.GetValore()<<endl;
	c2.Setvalore(1);
	c2.Setpasso(1);
	c2.incrementa();
	cout<<"il valore post incremento"<<c2.GetValore()<<endl;
	c3.Setvalore(1);
	c3.incrementa();
	cout<<"il valore post incremento"<<c3.GetValore()<<endl;

}
	
	
