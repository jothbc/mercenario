// mercenario.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Carro {
	string nome;
	float velocidade;
	string cor;
	float percorrido;
};
struct Pista {
	Carro carros[5];
	float TamanhoPista;
	void CriarPistaComCarros() {
		cout << "Digite o tamanho da pista em Km: " << endl;
		cin >> TamanhoPista;
		TamanhoPista *= 1000;
		for (int x = 0; x < 5; x++) {
			cout << "Digite o nome do carro:" << endl;
			cin>>carros[x].nome;
			cout << "Digite a cor do carro: " << endl;
			cin >> carros[x].cor;
			cout << "Digite a velocidade do carro em Km/h: " << endl;
			cin >> carros[x].velocidade;
			carros[x].velocidade /= 3.6;
			carros[x].percorrido = 0;
		}
	}
	void SimularCorrida() {
		int cont = 1;
		for (int x = 0; x <TamanhoPista; x++) {
			if (cont > 5) {
				x = TamanhoPista;
			}
			for (int i = 0; i < 5; i++) {
				if (carros[i].velocidade!=0) {
					carros[i].percorrido += carros[i].velocidade;
				}
				if (carros[i].percorrido >= TamanhoPista && carros[i].velocidade!=0) {
					cout << "O " << cont << " colocado foi o carro " << carros[i].nome <<" de cor "<<carros[i].cor<<"."<< endl;
					carros[i].velocidade = 0;
					cont++;
				}
			}
		}
	}
	void SimularTempo() {
		int tempo;
		cout << "Digite o tempo em Minutos a ser simulada:" << endl;
		cin >> tempo;
		tempo *= 60;
		for (int x = 0; x < tempo; x++) {
			for (int i = 0; i < 5; i++) {
				carros[i].percorrido += carros[i].velocidade;
			}
		}
		for (int i = 0; i < 5; i++) {
			cout << "O carro " << carros[i].nome << " percorreu aproximadamente " << carros[i].percorrido /1000<< " km." << endl;
		}
	}
};
int main()
{
	Pista nascar;
	
	nascar.CriarPistaComCarros();
	//nascar.SimularCorrida();
	nascar.SimularTempo();
	system("pause");
	
    return 0;
}

