/* Juego de Adivina el Numero */

#include <iostream>
#include <stdio.h>
#include "rlutil.h"
#include <ctime>
#include <cstdlib>


using namespace rlutil;
using namespace std;

int main() {
	setColor(BLACK);
	setBackgroundColor(DARKGREY);
	cls();

	int intentos = 0;
	int n = 0, again = 0;
	int num;

	string rango;
	srand(time(NULL));
	num = 1 + rand() % 100;

	do {

		int num;

		string rango;
		srand(time(NULL));
		num = 1 + rand() % 100;
		
		

		cout << "El juego es simple, tiene que adivinar el numero en la menor cantidad de intentos posibles" << endl;
		PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
		cout << "Que numero es?" << endl;
		cin >> n;

		if (n > num) {
			cout << "Te pasaste tres pueblos" << endl;
			intentos++;
			PlaySound(TEXT("invalid.wav"), NULL, SND_ALIAS);
		}
		else {
			if (n < num){
			cout << "Falta poquito" << endl;
			intentos++;
			PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
			}
		}


		while (n != num) {

			cout << "Que numero es?" << endl;
			cin >> n;

			if (n > num) {
				cout << "Te pasaste tres pueblos" << endl;
				intentos++;
				PlaySound(TEXT("invalid.wav"), NULL, SND_ALIAS);
			}
			else {
				if (n < num) {
					cout << "Falta poquito" << endl;
					intentos++;
					PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
				}
			}
		}

		if (n == num) {
			
			cout << "Eso! Lo lograste, el numero al final era:" << num << endl;
			cout << "Segun tus numeros de intentos, tenemos una calificacion para vos!" << endl;

			PlaySound(TEXT("winner.wav"), NULL, SND_ALIAS);

			if (intentos >= 1 && intentos <= 5) {
				rango = "Brian Lara";
			}
			else if (intentos >= 6 && intentos <= 15) {
				rango = "Klosterian";
			}
			else if (intentos >= 16 && intentos <= 30) {
				rango = "Dirubezco";
			}
			else if (intentos > 30) {
				rango = "Simonirico";
			}
			cout << "Tu rango es: " << rango << "\tFelicidades! kjjj" << endl << endl << endl << endl;




		}
		cout << "Queres jugar de nuevo? Presione 0" << endl << endl;
		PlaySound(TEXT("buttonselect.wav"), NULL, SND_ALIAS);
		cin >> again;

	} while (again == 0);

	cout << "Adios adios adios adios adios" << endl;
	cout << "Adios adios adios adios adios" << endl;



	return 0;
}
