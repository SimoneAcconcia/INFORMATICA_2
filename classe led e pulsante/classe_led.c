// Classe LED
class LED {
  private:
    int pin; // Pin del LED
  	int stato; //stato del led 
     
  public:
    // Costruttore: imposta la modalità del pin del LED come output
    LED(int p) 
    {
      pin = p;
      pinMode(pin, OUTPUT);
      stato=0;   
    }

    // Metodo per accendere il LED
    void accendi() 
    {
      digitalWrite(pin, HIGH);
      stato=1;
    }

    // Metodo per spegnere il LED
    void spegni() 
    {
      digitalWrite(pin, LOW);
      stato=0;
    }
  
  	void inverti()
    {
      if(stato==1) {
      	spegni();
      } else {
      	accendi();
      }
    }
  
    void lampeggio(int nr) 
    {
      //esegue nr lampeggi
      for(int i=0;i<nr;i++)
      {
        accendi();
        delay(500);
        spegni();
        delay(500);
      }
    }

	void test(int nr) 
    {
      //se nr==0 fa tre lampeggio
      if(nr==0)
      {
        accendi();
        delay(800);
        inverti();
      } 
      else if(nr==1) 
      {
        lampeggio(3);
      }
    }
};

// Crea un oggetto LED sulla porta 13
LED led(11);

void setup() 
{
	led.test(0);
	led.test(1);
}

void loop() 
{ 
}
