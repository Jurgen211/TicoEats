#include"Interfaz.h"
#include<iostream>
using namespace std;

int main () {
	Interfaz *I = new Interfaz;
	
	I -> Launcher();
//	I -> Menu_Main();
	
	return 0;
}

/*
int contadorFactura;
ifstream entradaContFactura; entradaContFactura.open("Archivos/Facturas/Contador Facturas.txt", ios::in);
contadorFactura = Extraer_Contador(entradaContFactura); entradaContFactura.close(); 

cout << "contador: " << contadorFactura << endl; system ("pause");

std::stringstream contador; contador << contadorFactura; 

string nombreArchivo = "Factura " + contador.str() + ".txt"; salidaFactura.open("Archivos/Facturas/" + nombreArchivo);

contadorFactura++;
ofstream salidaContFactura; salidaContFactura.open("Archivos/Facturas/Contador Facturas.txt", ios::out);
salidaContFactura << contadorFactura; salidaContFactura.close();

*/
