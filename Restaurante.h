#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include "Combo.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Restaurante {
private:
	string *Cedula;
	string *Password;
	string *Nombre;
	string *Direccion;
	string *Tipo_Comida;
	string *Combos;
	
	int *Cantidad_Pedidos;
	double *Total_Vendido;
	
public:
	Restaurante();
	Restaurante(string *, string *, string *, string *, string *, string *, int *, double *);
	~Restaurante();
	
	void setCedula(string *);
	void setPassword(string *);
	void setNombre(string *);
	void setTipo_Comida(string *);
	void setDireccion(string *);
	void setCombos(string *);
	
	void setCantidad_Pedidos(int *);
	void setTotal_Vendido(double *);
	
	string getCedula();
	string getPassword();
	string getNombre();
	string getTipo_Comida();
	string getDireccion();
	string getCombos();
	
	int getCantidad_Pedidos();
	double getTotal_Vendido();
	
	string toString();
	
	void autoGuardarRestaurante(ofstream&, ofstream&, ofstream&, ofstream&);
	static Restaurante *autoLeerRestaurante(ifstream&);
};

#endif

