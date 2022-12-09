#include "Combo.h"

Combo::Combo() {
	Identificador = new int;
	Nombre = new string();
	Precio = new double;
}

Combo::Combo (int *id, string *nombre, double *precio) {
	Identificador = id;
	Nombre = nombre;
	Precio = precio;
}

Combo::~Combo() {
	delete Identificador;
	delete Nombre;
	delete Precio;
}

void Combo::setIdentificador (int *identificador ) {
	Identificador = identificador;
}

void Combo::setNombre (string *nombre ) {
	Nombre = nombre;
}

void Combo::setPrecio (double *precio ) {
	Precio = precio;
}

int Combo::getIdentificador ( ) {
	return *Identificador;
}

string Combo::getNombre ( ) {
	return *Nombre; 
}

double Combo::getPrecio ( ) {
	return *Precio;
}

string Combo::toString(){
	stringstream a;
	a << endl;
	a << "+======= COMBO #" << getIdentificador() << " =======+" << endl << endl;
	a << "Nombre: " << getNombre() << endl;
	a << "Precio: " << getPrecio() << endl;
	a << endl;
	
	return a.str();
}

void Combo::autoGuardarCombo(ofstream &archivo ) {
	archivo << *Identificador << endl;
	archivo << *Nombre << endl;
	archivo << *Precio << endl;
}

Combo * Combo::autoLeerCombo(ifstream &archivo) {
	string *_identificador = new string();
	string *_nombre = new string();
	string *_precio = new string();
	int *_id = new int; 
	double *_prec = new double; 
	
	if (!(archivo >> *_identificador)) { return NULL; } archivo.ignore(); 
	if (!(getline(archivo, *_nombre))) { return NULL; }
	if (!(archivo >> *_precio)) { return NULL; } 
	
	*_id = atoi(_identificador->c_str()); 
	*_prec = stod(_precio->c_str());
	
	return new Combo(_id, _nombre, _prec);
}

