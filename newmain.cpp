//Declaración de librerías para usar con el ahorco
#include <iostream>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <locale>
#include <fstream>
#include <ctime>

//Declaración de espacios de nombres
using namespace std;

//Estructura de variables para el ahorcado
struct libreria{
	string lineasPalabra;
	string palabra;
	string letra, estadoAnterior, estatusJuego;
	int intento = 5;
	int nivel = 1; 
};

//Declaración de llamada a estructuras
libreria banco;

//Declaración de funciones para el ahorcado
void filtroPalabra(int caracterCadena);
void palabraAleatoria();
void tecladoES_LA();
void longitudLineas();
void verificarLetra();
void contarLetra();
void conteoIntentos();
void proximoNivel();
void finJuego();
int victoriaNivel(); 

//Función principal de ejecución del código
int main() {
	
	srand(time(NULL));
	tecladoES_LA();
	palabraAleatoria();
	
	while(banco.nivel <= 6 && banco.intento > 0) {
		cout<<banco.lineasPalabra<<endl;
		cout<<"Nivel "<<banco.nivel<<endl;
		while (victoriaNivel() == 0 && banco.intento > 0) {
			cout<<"Tiene "<<banco.intento<<" intentos"<<endl;
			cout<<"Digite letra: "<<endl;
			banco.letra = tolower(getch());
			contarLetra();
		}
		if(victoriaNivel() == 1) {
			proximoNivel();
		}
		system("Cls");
	}
	
	finJuego();
}

//Función para configurar para localizar a Español Latinoamerica 
void tecladoES_LA() {
	setlocale(LC_ALL, "spanish");	
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
}

//Función para obtener una palabra aleatoria
void palabraAleatoria() {
	string recorridoPalabras;	
	int valorAleatorio = 1 + rand() % 1634;	
	ifstream archivoPalabras("Palabras.txt");
	if(archivoPalabras.is_open()) {
		for (int r = 0; r < valorAleatorio; r++) {	
			archivoPalabras >> recorridoPalabras;
			if (recorridoPalabras.length() == (banco.nivel + 4)) {						
				banco.palabra = recorridoPalabras;			
			}			
		}			
		archivoPalabras.close();		
	}
	longitudLineas();
}

void longitudLineas() {
	banco.lineasPalabra = "____";
	for(int t = 0; t < banco.nivel; t++) {
		banco.lineasPalabra += "_";
	}
}

void filtroPalabra(int caracterCadena) {
	switch(banco.palabra[caracterCadena]) {
		case 'á':
			if(banco.letra[0] == 'a') {
				banco.lineasPalabra[caracterCadena] = banco.palabra[caracterCadena];
			}
			break;
		case 'é':
			if(banco.letra[0] == 'e') {
				banco.lineasPalabra[caracterCadena] = banco.palabra[caracterCadena];
			}
			break;
		case 'í':
			if(banco.letra[0] == 'i') {
				banco.lineasPalabra[caracterCadena] = banco.palabra[caracterCadena];
			}
			break;
		case 'ó':
			if(banco.letra[0] == 'o') {
				banco.lineasPalabra[caracterCadena] = banco.palabra[caracterCadena];
			}
			break;
		case 'ú':
			if(banco.letra[0] == 'u') {
				banco.lineasPalabra[caracterCadena] = banco.palabra[caracterCadena];
			}
			break;
	}
}

//Función para verificar el caracter ingresado como letra
void verificarLetra() {
	while(!isalpha(banco.letra[0])) {
		cout<<endl<<"No se permiten caracteres que no sean alfabéticos."<<endl;
		banco.letra = getch();
	}
}

//Función para verificar si la letra está en la palabra
void contarLetra() {
	verificarLetra();
	banco.estadoAnterior = banco.lineasPalabra;
	for(int i = 0; i < banco.palabra.size(); i++) {
		banco.palabra[i] = tolower(banco.palabra[i]);
		if(banco.palabra[i] == banco.letra[0]) {
			banco.lineasPalabra[i] = banco.letra[0];
		}
		else
		{
			filtroPalabra(i);
		}
	}
	conteoIntentos();
	cout<<endl<<banco.lineasPalabra<<endl;
}

//Función para verificar el conteo de intentos
void conteoIntentos() {
	if(banco.estadoAnterior == banco.lineasPalabra) {
		banco.intento--;
	}
}

//Función para verificar si se ha logrado adivinar la palabra
int victoriaNivel() {
	if(banco.palabra == banco.lineasPalabra) {
		return 1;
	}
	else
	{
		return 0;	
	}
} 

//Función para avanzar nivel de dificultad
void proximoNivel() {
	banco.nivel++;
	palabraAleatoria();
}

//Función para indicar la finalización del juego (Derrota o victoria)
void finJuego() {
	banco.estatusJuego = (banco.nivel == 7) ? "Has ganado el juego" : "Has perdido el juego";
	cout<<banco.estatusJuego<<endl;
	cout<<banco.palabra<<endl;
}
