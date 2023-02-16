class Rettangolo
{
	private:
		double base;
		double altezza;
	
	public: 
	
		//Costruttori
		Rettangolo();	//inizializza gli attributi privati ad uno
		Rettangolo(double b ,double a);
		
		//metodi getter e setter
		void SetAltezza(double a);
		void SetBase(double b);
		
		double GetAltezza ();
		double GetBase ();
		
		//metodi per calcolare area,perimetro,diagonale
		double CalcolaPerimetro(); //USO GLI ATTRIBUTI E NON PARAMETRI  perchè lavoro sugli oggetti
		double CalcolaArea();
		double calcolaDiagonale();
		void   stampa();
		
		/** ****************************************************************************************
 		 * @brief test della classe 
		 * @param  test da eseguire 
		 * @retval nessuno
		 *
		 * TEST #1 -  impostiamo base e altezza e calcoliamo e stampiamo area, diagonale e perimetro
		 *
		 * @author <autore>
		 * @version 1.0 26/1/23
		 */
		void test(int numero);
};

