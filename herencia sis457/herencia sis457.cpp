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
		if (validarPocision(f, c)) {
			fila = f;
			columna = c;
		}
		else {
			fila = 1;
			columna = 1;
		};
	}
	//  1)  metodos acccesores get y set
	short getFila() {return fila;}
	short getColumna() {return columna;}

	void setFila(short f) {fila = f;}
	void setColumna(short c) { columna = c;}
	// muestra graficamente el tablero con un punto en la pocision de la pieza en el metodo verInfo
	void verInfo() {
		for (int i = 8; i >= 1;i--) {
				for (int j = 1; j <= 8; j++) {
					cout <<"|";
					if (i == fila  && j == columna) {
						cout << "Pi";
					}
					else {
						cout << "__";
					}
				}
				cout <<"|"<< i << endl;
		}
		cout << "Fila: " << fila << endl;
		cout << "Columna: " << columna << endl;
	}
	// 2) metodo validar la pocision si esta dentro del tablero
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
	Peon() {
		direc = 2;
		setFila(2);
		setColumna(1);
	}
	Peon(short d, short c) {
		direc = d;
		setFila(d==2?2:7);
		setColumna(c);
	}

	//funcion que determine si la pieza se puede mover a la posicion fila,columna
	bool puedoIrA(short f, short c) {
		if (direc == 2 && getFila()<8 && getColumna()<8) {
			if (f == getFila() + 1 && c == getColumna()) {
				return true;
			}
			if (getFila() == 2 && f == getFila() + 2 && c == getColumna()) {
				return true;
			}else { return false; }
		}if (direc == 7 && getFila()<8 && getColumna()<8) {
			if (f == getFila() - 1 && c == getColumna()) {
				return true;
			}
			if (getFila() == 7 && f == getFila() - 2 && c == getColumna()) {
				return true;
			}
			else { return false; }
		}
		else {
			return false;
		}
	}
//funcion avanzarPe
	void avanzarPe(short f,short c) {
		if (puedoIrA(f, c)) {
			if (direc == 2) {
				setFila(getFila() == 2 && f == 4 ? getFila() + 2 : getFila() + 1);
			}if (direc == 7) {
				setFila(getFila() == 7 && f == 5 ? getFila() - 2 : getFila() - 1);
			}
		}
		else {
			cout << "la direccion a la que quiere avansar no es correcta" << endl;
		}
	}
};
//crear pieza torrre por herncia nro de cuadroos que puede avansar por defecto
class Torre :public Pieza {
public:
	short nCuadros,direccion;
	Torre() {
		nCuadros = 0;
		direccion = 2;
		setFila(1);
		setColumna(1);
	}
	Torre(short nc, short d,short c) {
		nCuadros = nc;
		direccion = d;

		setFila(d==2?1:8);
		setColumna(c);
	}
	//funcion que determine si la pieza se puede mover a la posicion fila,columna
	bool pudeIrA(short f, short c,short d) {
		if (d == 2) {
			if (f == getFila() + nCuadros && c == getColumna()) {
				return true;
			}
			else {
				return false;
			}
		}
		if (d == 7) {
			if (f == getFila() - nCuadros && c == getColumna()) {
				return true;
			}
			else {
				return false;
			}
		}
		if (d == 4) {
			if (f == getFila() && c == getColumna() - nCuadros) {
				return true;
			}
			else {
				return false;
			}
		}
		if (d == 5) {
			if (f == getFila() && c == getColumna() + nCuadros) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	//funcion avansar
	void avanzarTo(short nc, short d) {
		
			if (d == 2) {
				setFila(getFila() + nCuadros);
			}
			if (d == 7) {
				setFila(getFila() - nCuadros);
			}
			if (d == 4) {
				setColumna(getColumna() - nCuadros);
			}
			if (d == 5) {
				setColumna(getColumna() + nCuadros);
			}
	}
};
class tablero {
public:
//crear el tablero grafico
	void verTablero() {
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				if ((i + j) % 2 == 0) {
					cout << "B";
				}
				else {
					cout << "N";
				}
			}
			cout << endl;
		}
	}
};
//hacer la prueba todo en main
int main()
{
	short di, co, nc, d, mco,mfi,cot,mdi;
	do {
		cout << "introdusca la direccion que tendra el peon 2 para piezas blancas y 7 para piezas negras" << endl;
		cin >> di;
	} while (di !=2 && di!=7 );
	cout << "introdusca la columna en la que se encuentra el peon" << endl;
	cin >> co;
	Peon pe1(di, co);//(direc,colum))
	pe1.verInfo();
	cout << "introdusca la fila a la que quiere mover el peon" << endl;
	cin >> mfi;
	cout << "introdusca la columna a la que quiere mover el peon" << endl;
	cin >> mco;
	pe1.avanzarPe(mfi, mco);//(fila,columna)
	pe1.verInfo();
	cout << "introdusca el numero de cuadros que puede avansar la torre" << endl;
	cin >> nc;
	do {
		cout << "introdusca la fila que tendra (la torre 1 para el equipo blanco y 8 para equipo negro)" << endl;
		cin >> d;
	} while (d != 1 && d != 8);
	if (d == 1) {
		d = 2;
	}
	if (d == 8) {
		d = 7;
	}
	cout << "introdusca la columna en la que se encuentra la torre" << endl;
	cin >> cot;
	Torre to1(nc, d, cot);//(ncuadros,direccion,columna)
	to1.verInfo();
	cout << "introdusca la direccion a la que quiere mover la torre (2 para arriba 7 para abajo 4 para la izquierda y 5 para la derecha)" << endl;
	cin >> mdi;
	cout << "" << endl;
	to1.avanzarTo(nc,mdi);
	to1.verInfo();

    return 0;
}
