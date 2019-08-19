#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Estructuras.h"
#include <string.h>

class funciones {

public:

	//Funciones del proyecto
	void CreateDisk(char name[20]);
	void mkdir(int, int, bool, char name[30]);
	int cd(char name[30], int padre);
	int cdRegreso(int n);
	void ls(int Padre);
	void rm(int pos);
	void rm1(int pos);
	void importar(char name[100], int padre);
	void exportar(int padre);

	//Funciones Secundarias
	void InfoDisco(int padre, char name[30]);
	void guardar(int padre, int siz);				
	void guardarArchivo(int padre, FileEntry as);		
	int revisarBits(char * bitmap, int num);	
	void guardarBits(bitMap bit);					
	void guardarIndirectos(int, DataBlock_I1);			
	void guardarDirectos(int, DataBlock_Direct);			
	char* inicializarBitmap(int num);
	char* setO(char * bitmap, int num);		
	char* setOf(char * bitmap, int num);	

	//Funciones Auxiliares
	string sN(int n);
	void printBitMap(char * bitMap, int DB_Amount);
	void printbit();

};

#endif // !FUNCIONES_H
