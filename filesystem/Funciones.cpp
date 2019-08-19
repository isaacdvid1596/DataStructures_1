#include "pch.h"
#include "Funciones.h"
#include <string.h>

void funciones::CreateDisk(char name[20]) {

	fstream archivo("DiscoVirtual.bin", ios::out | ios::app | ios::binary);
	if (!archivo) {

		cout << "Archivo Incorrecto!" << endl;
	}
	else {

		//Metadata
		int num;
		int espacioT;
		cout << "Ingrese el total de directorios a crear: " << endl;
		cin >> num;
		espacioT = (num * 28) * 4096;
		espacioT = espacioT / 1024 / 1024;

		MetaData inf;
		strcpy_s(inf.nombreD, name);
		inf.EspacioTotal = espacioT;
		inf.EspacioVacio = 0;
		inf.totalEntradas = num;
		archivo.write(reinterpret_cast<const char *>(&inf), sizeof(MetaData));

		//Bitmap
		bitMap bit;
		bit.bitmap = inicializarBitmap(num * 28);
		bit.entries = num * 28;
		bit.bitmapI1 = inicializarBitmap(num * 28);
		archivo.write(reinterpret_cast<const char *>(&bit), (sizeof(bitMap)));

		//FileEntry
		FileEntry root;
		strcpy_s(root.fileName, "root");
		root.FileType = 'd';
		root.hijoderecho = -1;
		root.hijoultimo = -1;
		root.padre = -1;
		root.primerhijo = -1;
		root.ocupada = true;

		archivo.write(reinterpret_cast<const char *>(&root), sizeof(FileEntry));

		for (int i = 0; i < num - 1; i++) {
			FileEntry nuevo;
			archivo.write(reinterpret_cast<const char *>(&nuevo), sizeof(FileEntry));
		}

		//Bloques de datos
		DataBlock_Direct tmp;
		DataBlock_I1 tmp1;

		for (int i = 0; i < num*(28); i++) {
			archivo.write(reinterpret_cast<const char *>(&tmp), sizeof(DataBlock_Direct));
		}

		for (int i = 0; i < num; i++) {
			archivo.write(reinterpret_cast<const char *>(&tmp1), sizeof(DataBlock_I1));
		}

		archivo.close();
	}
}

void funciones::InfoDisco(int padre, char name[30]) {

	ifstream archivo("DiscoVirtual.bin", ios::in | ios::binary);

	if (!archivo) {

		cout << "Archivo Incorrecto!" << endl;

	}
	else {

		archivo.seekg(0, ios::beg);

		int Vacio = -1;
		int Padre = -1;

		bool esPrimerHijo = false;
		bool primerom = false;
		MetaData inf;

		archivo.read(reinterpret_cast<char *>(&inf), sizeof(MetaData));
		
		FileEntry as;
		int size = sizeof(MetaData) + sizeof(bitMap);
		archivo.seekg(size);
		archivo.read(reinterpret_cast<char *>(&as), sizeof(FileEntry));
		
		int totalE = inf.totalEntradas;

		for (int i = 0; i < totalE; i++) {
		
			archivo.seekg(size + (sizeof(FileEntry)*i));
			archivo.read(reinterpret_cast<char *>(&as), sizeof(FileEntry));
			
			if (i == padre && (as.FileType == 'd')) {

				if (as.primerhijo == -1) {

					esPrimerHijo = true;

				}

				if (as.primerhijo != -1) {
					esPrimerHijo = false;

				}


			}
			if (as.ocupada == false && Vacio == -1) {

				Vacio = i;

			}

		}

		archivo.close();

		if (Vacio != -1) {
			mkdir(Vacio, padre, esPrimerHijo, name);
		}
		else {
			cout << "El disco esta lleno!\a" << endl;
		}
	}

}

void funciones::mkdir(int Vacio, int Padre, bool esPrimerHijo, char name[30]) {

	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);

	int size = sizeof(MetaData) + sizeof(bitMap);
	if (!archivo) {
		cout << "Archivo Incorrecto!" << endl;

	}
	else {

		FileEntry as;
		
		as.ocupada = true;
		int c = size + (sizeof(FileEntry)*Vacio);
		archivo.seekg(c);
		archivo.read((char*)(&as), sizeof(FileEntry));
		strcpy_s(as.fileName, name);
		as.padre = Padre;
		as.ocupada = true;
		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		as.FileType = 'd';
		archivo.write(reinterpret_cast<const char *>(&as), sizeof(FileEntry));
		archivo.seekg(c);
		archivo.read((char*)(&as), sizeof(FileEntry));
		
		if (esPrimerHijo == true) {

			FileEntry pp;
			archivo.seekg(sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*Padre));
			archivo.read(reinterpret_cast<char *>(&pp), sizeof(FileEntry));
			cout << "El padre es: " << pp.fileName << endl;
			archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
			pp.primerhijo = Vacio;
			pp.hijoultimo = Vacio;
			archivo.write(reinterpret_cast<const char *>(&pp), sizeof(FileEntry));

		}
		else {

			FileEntry pp;
			archivo.seekg(sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*Padre));
			archivo.read(reinterpret_cast<char *>(&pp), sizeof(FileEntry));
			cout << "El padre es: " << pp.fileName << endl;
			archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
			int z = pp.hijoultimo;
			pp.hijoultimo = Vacio;
			archivo.write(reinterpret_cast<const char *>(&pp), sizeof(FileEntry));

			// Cambio de numero a hermano
			FileEntry hp;
			archivo.seekg(sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*z));
			archivo.read(reinterpret_cast<char *>(&hp), sizeof(FileEntry));
			hp.hijoderecho = Vacio;
			archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
			archivo.write(reinterpret_cast<const char *>(&hp), sizeof(FileEntry));

		}

	}
	archivo.close();


}

string funciones::sN(int n) {
	FileEntry as;
	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);
	archivo.seekg(sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*n));
	archivo.read(reinterpret_cast<char *>(&as), sizeof(FileEntry));

	return as.fileName;


}

void funciones::rm(int pos) {

	FileEntry actual;
	FileEntry p;
	
	fstream archivo("DiscoVirtual.bin", ios::in | ios::out | ios::binary);
	
	int size = sizeof(MetaData) + sizeof(bitMap);
	archivo.seekg(size + (sizeof(FileEntry)*pos));
	archivo.read(reinterpret_cast<char *>(&actual), sizeof(FileEntry));
	
	bool ing = true;
	
	if (actual.primerhijo == -1 && actual.hijoderecho == -1) {

		archivo.seekg(size + (sizeof(FileEntry)*pos));
		archivo.read(reinterpret_cast<char *>(&actual), sizeof(FileEntry));
		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&p), sizeof(FileEntry));

	}
	else if (actual.primerhijo != -1) {

		rm1(actual.primerhijo);
		archivo.seekg(size + (sizeof(FileEntry)*pos));
		archivo.read(reinterpret_cast<char *>(&actual), sizeof(FileEntry));
		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&p), sizeof(FileEntry));
		ing = false;

	}
	else if (actual.hijoderecho != -1) {

		rm(actual.hijoderecho);
		archivo.seekg(size + (sizeof(FileEntry)*pos));
		archivo.read(reinterpret_cast<char *>(&actual), sizeof(FileEntry));
		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&p), sizeof(FileEntry));
		ing = false;

	}

}

void funciones::rm1(int pos) {

	FileEntry actual;
	FileEntry p;

	fstream archivo("DiscoVirtual.bin", ios::in | ios::out | ios::binary);
	
	int size = sizeof(MetaData) + sizeof(bitMap);
	archivo.seekg(size + (sizeof(FileEntry)*pos));
	archivo.read(reinterpret_cast<char *>(&actual), sizeof(FileEntry));
	
	if (actual.primerhijo != -1) {

		rm(actual.primerhijo);

		archivo.seekg(size + (sizeof(FileEntry)*pos));
		archivo.read(reinterpret_cast<char *>(&actual), sizeof(FileEntry));
		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&p), sizeof(FileEntry));


	}else {

		archivo.seekg(size + (sizeof(FileEntry)*pos));
		archivo.read(reinterpret_cast<char *>(&actual), sizeof(FileEntry));
		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&p), sizeof(FileEntry));

	}
}

int funciones::cdRegreso(int n) {

	FileEntry regreso;
	
	ifstream archivo("DiscoVirtual.bin", ios::in | ios::out | ios::binary);
	
	int size = sizeof(MetaData) + sizeof(bitMap);
	archivo.seekg(size + (sizeof(FileEntry)*n));
	archivo.read(reinterpret_cast<char *>(&regreso), sizeof(FileEntry));

	if (regreso.padre != -1) {

		return regreso.padre;
	}
	else {

		cout << "Estas en la carpeta principal!" << endl;
		return 0;

	}
}

int funciones::cd(char name[30], int padre) {


	ifstream archivo("DiscoVirtual.bin", ios::in | ios::binary);

	if (!archivo) {
		cout << "Archivo Incorrecto!" << endl;
		return padre;
	}else {
	
		archivo.seekg(0, ios::beg);

		MetaData inf;

		archivo.read(reinterpret_cast<char *>(&inf), sizeof(MetaData));
		int totalE = inf.totalEntradas;
		FileEntry as;
		int size = sizeof(MetaData) + sizeof(bitMap);
		archivo.seekg(size);
		archivo.read(reinterpret_cast<char *>(&as), sizeof(FileEntry));
		
		for (int i = 0; i < totalE; i++) {
			
			archivo.seekg(size + (sizeof(FileEntry)*i));
			archivo.read(reinterpret_cast<char *>(&as), sizeof(FileEntry));

			if (strcmp(as.fileName, name) == 0 && as.padre == padre) {
				cout << "Nombre:" << as.fileName << endl;
				return i;
			}

		}

		if (strcmp(as.fileName, name) != 0) {
			cout << "Folder Not Found 404!" << endl;
		}


	}
	return padre;
}

void funciones::importar(char name[100], int padre) {
	
	ifstream crear(name, ios::out | ios::in | ios::binary);
	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);
	
	if (!crear || !archivo) {
		cout << "Archivo Incorrecto!" << endl;
	}
	else {

		MetaData inf1;
		bitMap bit;
		DataBlock_Direct tmp;
		DataBlock_Direct read;
		DataBlock_I1 ps;

		archivo.seekg(0, ios::beg);
		archivo.read(reinterpret_cast<char *>(&inf1), sizeof(MetaData));
		int totalE = inf1.totalEntradas;

		archivo.seekg(sizeof(MetaData));
		archivo.read(reinterpret_cast<char*>(&bit), sizeof(bitMap));

		int size = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*totalE);

		int pos = 0, pos2 = 0;
		int con1 = 0, con2 = 0;
		int tam = 0;
		FileEntry jc;
		archivo.seekg(0, ios::beg);
		archivo.seekg(sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*padre));		

		archivo.read(reinterpret_cast<char *>(&jc), sizeof(FileEntry));

		int size2 = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*inf1.totalEntradas) + ((sizeof(DataBlock_Direct)*(inf1.totalEntradas * 28)));
		pos2 = revisarBits(bit.bitmapI1, totalE * 28);
		archivo.seekg(size2 + (sizeof(DataBlock_I1)*pos2));
		archivo.read(reinterpret_cast<char*>(&ps), sizeof(DataBlock_I1));

		if (jc.arch == false) {
			crear.seekg(0, ios::end);
			jc.Size = crear.tellg();
			cout << "Size: " << jc.Size << endl;

			crear.seekg(0, ios::beg);
			jc.arch = true;
			pos = revisarBits(bit.bitmap, bit.entries);
			con2 = 0;
			while (!crear.eof() && con2 < 16) {
				archivo.seekg(sizeof(MetaData));

				archivo.read(reinterpret_cast<char*>(&bit), sizeof(bitMap));
				pos = revisarBits(bit.bitmap, bit.entries);

				crear.read(reinterpret_cast<char*>(&read), sizeof(DataBlock_Direct));
				guardarDirectos(pos, read);

				if (con1 > 11) {

					if (con2 == 0) {
						bit.bitmapI1 = setOf(bit.bitmapI1, pos2);
						jc.DB_Indirects[0] = pos2;
					}
					ps.pointers[con2] = pos;

					cout << "Con" << con2 << endl;
					cout << "Con" << pos2 << endl;
					cout << "DB1:" << ps.pointers[con2] << endl;
					con2 = con2 + 1;
				
				}
				else if (con1 < 12) {

					jc.DB_Directs[con1] = pos;
					cout << "Con" << con1 << endl;
					cout << "DB:" << jc.DB_Directs[con1] << endl;
					con1 = con1 + 1;
				
				}

				guardarBits(bit);
				bit.bitmap = setO(bit.bitmap, pos);
				printBitMap(bit.bitmap, bit.entries);
				pos = pos + 1;

			}

			cout << "Se importo exitosamente!" << endl;

			guardarIndirectos(pos2, ps);
			guardarArchivo(padre, jc);
			guardar(padre, jc.Size);
			guardarBits(bit);


		}else {

			cout << "Ya hay un archivo importado en este directorio!" << endl;

		}

	}

}

void funciones::exportar(int padre) {

	fstream archivo("DiscoVirtual.bin", ios::in | ios::out | ios::binary);

	FileEntry jc;
	DataBlock_Direct tmp;
	DataBlock_I1 ps;

	int tam = 0;
	if (!archivo) {

		cout << "Archivo Incorrecto!" << endl;

	}
	else {

		bitMap bit;
		archivo.seekg(sizeof(MetaData));
		archivo.read(reinterpret_cast<char*>(&bit), sizeof(bitMap));
		archivo.seekg(0, ios::beg);
		archivo.seekg(sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*padre));

		archivo.read(reinterpret_cast<char *>(&jc), sizeof(FileEntry));
		int pos = 0;

		ofstream nuevo(jc.fileName, ios::out | ios::app | ios::binary);

		if (!nuevo) {

			cout << "Archivo Incorrecto!" << endl;


		}
		else {

			MetaData inf1;
			archivo.seekg(0, ios::beg);
			archivo.read(reinterpret_cast<char *>(&inf1), sizeof(MetaData));
			int totalE = inf1.totalEntradas;

			int size = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*totalE);
			archivo.seekg(size);
			int tam = jc.Size;
			tam = tam / 4096;
			tam = tam + 1;
			cout << "size" << jc.Size << endl;
			cout << "tam:" << tam << endl;
			int con1 = 0, con2 = 0;
			int size2 = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*totalE + (sizeof(DataBlock_Direct)*(totalE * 28)));
			archivo.seekg(size2 + (sizeof(DataBlock_I1)*jc.DB_Indirects[0]));
			archivo.read(reinterpret_cast<char*>(&ps), sizeof(DataBlock_I1));

			for (int i = 0; i < tam; i++) {

				if (i < 12) {
					int pos1 = jc.DB_Directs[i];
					archivo.seekg(size + (sizeof(DataBlock_Direct)*pos1));
					//cout << jc.DB_Directs[con2] << endl;
					bit.bitmap = setOf(bit.bitmap, jc.DB_Directs[i]);
					archivo.read(reinterpret_cast<char *>(&tmp), sizeof(DataBlock_Direct));
					nuevo.write(reinterpret_cast<const char *>(&tmp), sizeof(DataBlock_Direct));
					con2 = con2 + 1;
				}
				else if (i >= 12) {
					//cout << ps.pointers[0] << endl;
					archivo.seekg(size + (sizeof(DataBlock_Direct)*ps.pointers[con1]));
					bit.bitmap = setOf(bit.bitmap, ps.pointers[con1]);
					if (con1 == 0) {
						bit.bitmapI1 = setOf(bit.bitmapI1, padre);
						jc.DB_Indirects[0] = -1;
					}
					archivo.read(reinterpret_cast<char *>(&tmp), sizeof(DataBlock_Direct));
					nuevo.write(reinterpret_cast<const char *>(&tmp), sizeof(DataBlock_Direct));
					con1 = con1 + 1;

				}

			}

			jc.arch = false;
			jc.Size = 0;
			guardarBits(bit);
			guardarArchivo(padre, jc);

		}
	}
}

int funciones::revisarBits(char *bitmap, int num) {

	for (int i = 0; i < num / 8; i++) {

		unsigned char b = bitmap[i];

		if (b == 0) {

			return (8 * i);

		}
		else if (b == 128) {

			return (8 * i) + 1;

		}
		else if (b == 192) {

			return (8 * i) + 2;

		}
		else if (b == 224) {

			return (8 * i) + 3;

		}

		else if (b == 240) {

			return (8 * i) + 4;

		}

		else if (b == 248) {

			return (8 * i) + 5;

		}
		else if (b == 252) {

			return (8 * i) + 6;

		}

		else if (b == 254) {

			return (8 * i) + 7;

		}



	}
	return -1;
}

void funciones::guardar(int padre, int siz) {
	
	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);
	if (!archivo) {
		cout << "Archivo Incorrecto!" << endl;
	}
	else {

		int size = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*padre);
		FileEntry tmp;
		archivo.seekg(size);

		archivo.read(reinterpret_cast<char *>(&tmp), sizeof(FileEntry));

		tmp.Size = siz;

		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&tmp), sizeof(FileEntry));

	}

}

void funciones::guardarArchivo(int padre, FileEntry siz) {
	
	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);
	if (!archivo) {
		cout << "Archivo Incorrecto!" << endl;
	}
	else {

		int size = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*padre);
		FileEntry tmp;
		archivo.seekg(size);

		archivo.read(reinterpret_cast<char *>(&tmp), sizeof(FileEntry));

		tmp = siz;

		archivo.seekp(-(sizeof(FileEntry) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&tmp), sizeof(FileEntry));

	}

}

void funciones::guardarBits(bitMap bit) {
	
	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);
	if (!archivo) {
		cout << "malo" << endl;
	}
	else {

		int size = sizeof(MetaData);
		bitMap tmp;
		archivo.seekg(size);

		archivo.read(reinterpret_cast<char *>(&tmp), sizeof(bitMap));

		tmp = bit;

		archivo.seekp(-(sizeof(bitMap) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&tmp), sizeof(bitMap));

	}

}

void funciones::guardarIndirectos(int pos, DataBlock_I1 bit) {
	
	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);
	if (!archivo) {
		cout << "Archivo Incorrecto!" << endl;
	}
	else {
		MetaData inf1;
		archivo.seekg(0, ios::beg);
		archivo.read(reinterpret_cast<char *>(&inf1), sizeof(MetaData));
		int size = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*inf1.totalEntradas)
			+ (sizeof(DataBlock_Direct)*(inf1.totalEntradas * 28));
		DataBlock_I1 tmp;
		archivo.seekg(size + (sizeof(DataBlock_I1)*pos));

		archivo.read(reinterpret_cast<char *>(&tmp), sizeof(DataBlock_I1));

		tmp = bit;
		//cout << bit.pointers[0] << endl;
		archivo.seekp(-(sizeof(DataBlock_I1) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&tmp), sizeof(DataBlock_I1));

	}

}

void funciones::guardarDirectos(int pos, DataBlock_Direct bit) {
	
	fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);
	if (!archivo) {
		cout << "Archivo Incorrecto!" << endl;
	}
	else {
		MetaData inf1;
		archivo.seekg(0, ios::beg);
		archivo.read(reinterpret_cast<char *>(&inf1), sizeof(MetaData));
		int size = sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)*inf1.totalEntradas);
		DataBlock_Direct tmp;
		archivo.seekg(size + (sizeof(DataBlock_Direct)*pos));

		archivo.read(reinterpret_cast<char *>(&tmp), sizeof(DataBlock_Direct));

		tmp = bit;

		archivo.seekp(-(sizeof(DataBlock_Direct) - archivo.tellp()));
		archivo.write(reinterpret_cast<const char *>(&tmp), sizeof(DataBlock_Direct));

	}

}

void funciones::ls(int padre) {

	ifstream archivo("DiscoVirtual.bin", ios::in | ios::binary);
	MetaData inf1;
	archivo.read(reinterpret_cast<char *>(&inf1), sizeof(MetaData));
	//cout << inf1.totalEntradas << endl;
	int totalE = inf1.totalEntradas;
	FileEntry inf;
	archivo.seekg(sizeof(MetaData) + sizeof(bitMap) + (sizeof(FileEntry)* padre));
	archivo.read(reinterpret_cast<char *>(&inf), sizeof(FileEntry));
	//cout << inf.primerhijo << endl;
	//cout << padre << endl;
	if (!archivo) {

		cout << "error" << endl;

	}
	else {
		FileEntry as;
		int size = sizeof(MetaData) + sizeof(bitMap);
		archivo.seekg(size);
		archivo.read(reinterpret_cast<char *>(&as), sizeof(FileEntry));
		//cout << as.fileName << endl;


		bool coincide = true;

		for (int i = 0; i < totalE; i++) {

			archivo.seekg(size + (sizeof(FileEntry)*i));
			archivo.read(reinterpret_cast<char *>(&as), sizeof(FileEntry));

			if (as.padre == padre) {

				cout << "Nombre:" << as.fileName << endl;
				coincide = false;
			}

		}
		if (coincide == true) {

			cout << "No se encontraron registros dentro del directorio" << endl;

		}

	}
}

char * funciones::inicializarBitmap(int num) {

	char *bitmap;

	bitmap = new char[num / 8];
	
	for (int i = 0; i < num / 8; i++){

		bitmap[i] = 0;
	
	}
	
	return bitmap;

}

void funciones::printBitMap(char * bitMap, int DB_AMOUNT)
{
	const int SHIFT = 8 * sizeof(char) - 1;
	const char MASK = 1 << SHIFT;

	for (int i = 0; i < DB_AMOUNT / 8; i++)
	{
		char value;
		value = bitMap[i];
		for (int c = 1; c <= SHIFT + 1; c++)
		{
			cout << (value & MASK ? '1' : '0');
			value <<= 1;

			if (c % 8 == 0)
				cout << ' ';
		}
	}
	cout << endl;

}

void funciones::printbit() {

fstream archivo("DiscoVirtual.bin", ios::out | ios::in | ios::binary);

if (!archivo) {
	cout << "Archivo Incorrecto!" << endl;
}


	MetaData inf1;
	bitMap bit;
	DataBlock_Direct tmp;
	DataBlock_Direct read;
	DataBlock_I1 ps;

	archivo.seekg(0, ios::beg);
	archivo.read(reinterpret_cast<char *>(&inf1), sizeof(MetaData));
	int totalE = inf1.totalEntradas;

	archivo.seekg(sizeof(MetaData));
	archivo.read(reinterpret_cast<char*>(&bit), sizeof(bitMap));

	int DB_AMOUNT = 0;
	DB_AMOUNT = bit.entries;
	char* bitMap = bit.bitmap;
	const int SHIFT = 8 * sizeof(char) - 1;
	const char MASK = 1 << SHIFT;

	for (int i = 0; i < DB_AMOUNT / 8; i++)
	{
		char value;
		value = bitMap[i];
		for (int c = 1; c <= SHIFT + 1; c++)
		{
			cout << (value & MASK ? '1' : '0');
			value <<= 1;

			if (c % 8 == 0)
				cout << ' ';
		}
	}
	cout << endl;
}

char * funciones::setO(char *bitmap, int nBlock) {

	int positionByte = nBlock / 8;
	int iniPosition = (nBlock / 8) * 8;

	for (int i = iniPosition, x = 7; i < (positionByte * 8) + 8; i++, x--)
	{
		if (i == nBlock)
		{
			bitmap[positionByte] |= 1 << x;
			break;
		}
	}

	return bitmap;

}

char * funciones::setOf(char *bitmap, int num) {

	int positionByte = num / 8;
	int iniPosition = (num / 8) * 8;


	for (int i = iniPosition, x = 7; i < (positionByte * 8) + 8; i++, x--)
	{
		if (i == num)
		{
			bitmap[positionByte] &= ~(1 << x);
			break;
		}
	}return bitmap;
}
