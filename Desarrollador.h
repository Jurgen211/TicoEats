#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H
//#include "User.h"
//#include "Repartidor.h"
//#include "Restaurante.h"
//#include "Combo.h"
//#include "Lista.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Desarrollador {
private:
	string *Codigo;
	string *Password;
	
public:
	Desarrollador();
	Desarrollador(string *, string *);
	~Desarrollador();
	
	void setCodigo(string *);
	void setPassword(string *);
	
	string getCodigo();
	string getPassword();
	
	
	//Reportes
//	void autoGuardarUser(ofstream&);
	static Desarrollador * autoLeerDesarrollador(ifstream&);
	

};

#endif

