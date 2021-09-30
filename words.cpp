#include <fstream>
#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>


using namespace std;

int main()
{	
	/* 
	 *Variables y otras inicializaciones
	 */
	string stLinea, stPalabra;
	int nNivel, nNumero;
	
	srand ( time(NULL) ); 			//Reinicia la semilla del prng 
	
	setlocale(LC_ALL, "spanish");	//io de ñ y tildes
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	
				
	/* 
	 *Nivel y largo de palabra
	 */
	cout << "Cual es el nivel actual?" << endl;
	cin >> nNivel;
		
	nNivel+=5;
	
	nNumero = 1 + rand() % 1634;
	
	//cout << "Lineas: " << nNumero << endl;
	
	
	/* 
	 *Lectura de archivo
	 */
	ifstream archivo("Palabras.txt");
	
	if(archivo.is_open())
	{
		for (int iii=0; iii<nNumero; iii++)
		{
			archivo >> stLinea;
			if (stLinea.length() == nNivel)
			{							
				stPalabra = stLinea;			
			}			
		}			
		archivo.close();		
	}
	else
	{
		cout << "Error, archivo de palabras cerrado o no encontrado" << endl;
	}
	
	
	/* 
	 *Regresa la palabra
	 */
	system("pause");
	system("cls");
	for (int iii=0; iii<stPalabra.length(); iii++)
	{
		stPalabra[iii] = tolower(stPalabra[iii]);	
	}
	cout << stPalabra << endl;
	
	system("pause");
	return 0;
}
