#include <iostream>

using namespace std;

struct libreria{
	string lineasPalabra = "_____";
	string palabra = "carpa";
};

struct valoresAhorcado{
	string letra;
};

libreria banco;
valoresAhorcado variables;

void contarLetra(string caracter);
void verificarLetra();
int verificarVictoria();

int main() {	
	while (verificarVictoria() != 1) {
		cout<<"Digite letra: "<<endl;
		cin>>variables.letra;
		contarLetra(variables.letra);
	}
}

void verificarLetra() {
	while(variables.letra[1] != '\0') {
		cout<<"Solo 1 carácter"<<endl;
		variables.letra[0] = '\0';
		cin>>variables.letra;
	}
}

void contarLetra(string caracter) {
	verificarLetra();
	for(int i = 0; i < banco.palabra.size(); i++) {
		if(banco.palabra[i] == variables.letra[0]) {
			banco.lineasPalabra[i] = variables.letra[0];
		}
	}
	cout<<banco.lineasPalabra<<endl;
}

int verificarVictoria() {
	if(banco.palabra == banco.lineasPalabra) {
		return 1;
	}
	else
	{
		return 0;	
	}
}


