// herencia 
#include <iostream>
using namespace std;
class Pieza {
private:
	short fila, columna;
public:
	Pieza() {
		fila = 1;
		columna = 1;
	}
	Pieza(short f, short c) {
		fila = f;
		columna = c;
		if (validarPocision(f, c)) {
			fila = f;
			columna = c;
		}
		else {
			fila = 1;
			columna = 1;
		};
	}
	short getFila() {
		return fila;
	}
	short getColumna() {
		return columna;
	}
	void setFila(short f) {
		fila = f;
	}
	void setColumna(short c) {
		columna = c;
	}
	void verInfo() {
		cout << "Fila: " << fila << endl;
		cout << "Columna: " << columna << endl;
	}
	bool validarPocision(short fila1,short columna1){
		if (fila1 >= 1 && fila1 <= 8 && columna1 >= 1 && columna1 <= 8) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Peon :public Pieza {
public:
	short direc;
//funcion avansar
	void avanzar() {
		if (direc == 1) {
			setFila(getFila() + 1);
		}
		if(direc == 2) {
			setFila(getFila() - 1);
		}
	}
	bool puedoIrA(short f, short c) {
		if (direc == 1) {
			if (f == getFila() + 1 && c == getColumna()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (f == getFila() - 1 && c == getColumna()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};
//crear pieza torrre por herncia nro de cuadroos que puede avansar por defecto
class torre :public Pieza {
public:

};
class tablero {
	//tarea viernes 6 de septiembre  
};
int main()
{
	Pieza p1;
	Peon pe1;
	cout<<"Fila: "<< p1.getFila() << endl;
	p1.verInfo();
    return 0;
}
