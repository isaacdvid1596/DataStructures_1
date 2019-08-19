
#include "pch.h"
#include <iostream>
#include "Funciones.h"
using namespace std;

int main(){

	funciones funcion;

	int pos = 0;
	cout << "Bienvenido a la Terminal" << endl;
	bool ing = true;
	bool crea = false;
	char nombre[30];
	char path[30];

	do {

		if (crea) { 
			cout << "cd: " << funcion.sN(pos) << endl;
		}

		char comand[30];
		cout << "Commando: ";
		cin >> comand;

		if (strcmp(comand, "disk") == 0) {
			crea = true;
			cout << "Nombre del disco: " << endl;
			cin >> nombre;
			funcion.CreateDisk(nombre);
		}

		if (strcmp(comand, "mkdir") == 0) {

			cout << "mkdir: ";
			cin >> nombre;
			funcion.InfoDisco(pos, nombre);

		}

		if (strcmp(comand, "ls") == 0) {
			funcion.ls(pos);
		}

		if (strcmp(comand, "cd") == 0) {

			cout << "cd:";
			cin >> nombre;

			if (strcmp(nombre, "..") == 0) {
				pos = funcion.cdRegreso(pos);
			}
			else {
				pos = funcion.cd(nombre, pos);
			}

		}

		if (strcmp(comand, "rm") == 0) {
			int pos1 = pos;
			pos = funcion.cdRegreso(pos);
			funcion.rm1(pos1);
		}

		if (strcmp(comand, "import") == 0) {
			cout << "Ingresa el nombre del archivo que quieres importar: ";
			cin >> path;
			bool holi = true;
			if (holi == true) {
				funcion.importar(path, pos);
			}
			else {
				cout << "Opcion incorrecta!" << endl;
			}

		}

		if (strcmp(comand, "export") == 0) {

			funcion.exportar(pos);
			
		}

		if (strcmp(comand, "bit") == 0) {
			funcion.printbit();
		}

		if (strcmp(comand, "exit") == 0) {
			ing = false;
		}

	} while (ing == true);
	
	system("pause > null");
	return 0;

}
