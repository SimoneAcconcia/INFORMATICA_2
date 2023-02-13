// Classe LED
class LED {
  private:
    int pin; // Pin del LED
    int stato; //stato del led se acceso = 1 se spento 0

  public:
    // Costruttore: imposta la modalità del pin del LED come output
    LED(int p) 
    {
      pin = p;
      stato = 0;
      pinMode(pin, OUTPUT);      
    }

    // Metodo per accendere il LED
    void accendi() 
    {
      digitalWrite(pin, HIGH);
      stato = 1;
    }

    // Metodo per spegnere il LED
    void spegni() 
    {
      digitalWrite(pin, LOW);
      stato = 0;
    }

  	void inverti()	//se il led è acceso viene spento e viceversa
    {
      if (stato == 1)
      {
        spegni();
      }
      else 
      {
        accendi();
      }
    }

    void lampeggio(int nr) /*a lampeggiare il led per  500ms , il numero di lampeggi 
    						è specificato nel main*/
    {
      //esegue nr lampeggi
      for (int i = 0; i < nr; i++)
      {
        inverti();
        delay(500);
        inverti();
        delay(500);
      }
    }

    void test(int nr) //testa il metodo lampegggio
    {
      
     // accendi();
      lampeggio(nr);
      
    }
};

class Pulsante
{
  private:
    int pin; 		// Pin del pulsante
    int stato;		//stato pulsante

  public:
    // Costruttore: imposta la modalità del pin del LED come output
    Pulsante(int p) 
    {
      pin = p;
      pinMode(pin, INPUT_PULLUP);
    }

    
    int press() 
    {
      if (digitalRead(pin) == LOW)
      {
         return 1;
      }   
      return 0;
    } 

    int click()
    {
      if(press())
      {
        while(press()) {;}
        return 1;
      }
      else
      {
        return 0;
      }
    }
};

// creazione di oggetti : led blu e verde , pulsante
LED ledVerde(12);
LED ledBlu(13);
Pulsante pulsante(2);

void setup() {
  ledBlu.test(3);
  ledVerde.test(3); 
}

void loop() {
  if (pulsante.press()) 
    {
      ledVerde.spegni();
      ledBlu.accendi();
    }
  else 
    {
      ledVerde.accendi();
      ledBlu.spegni();
    }

  if(pulsante.click())
    { 
      ledBlu.inverti();
    }
    

}
