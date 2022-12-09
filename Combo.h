#ifndef COMBO_H
#define COMBO_H

#include <iostream>
#include <sstream>
#include<fstream>

using namespace std;

class Combo {
private:
	int *Identificador;
	string *Nombre;
	double *Precio;
	
public:
	Combo();
	Combo(int *, string *, double *);
	~Combo();
	
	void setIdentificador(int *);
	void setNombre(string *);
	void setPrecio(double *);
	
	int getIdentificador();
	string getNombre();
	double getPrecio();

	string toString();
	
	void autoGuardarCombo(ofstream&);
	static Combo * autoLeerCombo(ifstream&);
};

#endif

