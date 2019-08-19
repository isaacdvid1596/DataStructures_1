#pragma once
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct FileEntry {

	char fileName[30] = "root";
	char FileType;
	int padre;
	int primerhijo = -1;
	int hijoderecho = -1;

	int hijoultimo = -1;
	bool ocupada = false;
	bool arch = false;
	unsigned int Size = 0;
	unsigned int DB_Directs[12];
	unsigned int DB_Indirects[3];
};

struct DataBlock_Direct { char data[4096]; };

struct DataBlock_I1 { int pointers[16]; };

struct DataBlock_I2 { DataBlock_Direct points[32]; };

struct DataBlock_I3 { DataBlock_Direct points[64]; };

struct MetaData {

	char nombreD[20];
	double EspacioTotal, EspacioVacio;
	int totalEntradas;
};

struct bitMap {

	int entries;
	char * bitmap;
	char * bitmapI1;

};

#endif // !ESTRUCTURAS_H
