#ifndef SUGERENCIA_H
#define SUGERENCIA_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std; 

class Sugerencia {
private:
	string *CedulaAutor;
	string *NombreAutor;
	//	string *CedulaAcusado;
	//	string *NombreAcusado;
	string *ContenidoSugerencia;
public:
	Sugerencia();
	Sugerencia(string*, string*, string*);
	
	void setCedulaAutor(string *);
	void setNombreAutor(string *);
	//	void setCedulaAcusado(string *);
	//	void setNombreAcusado(string *);
	void setContenidoSugerencia(string *);
	
	string getCedulaAutor();
	string getNombreAutor();
	//	string getCedulaAcusado();
	//	string getNombreAcusado();
	string getContenidoSugerencia();
	
	string toString();
	
	void autoGuardarSugerencia(ofstream&);
	static Sugerencia *autoLeerSugerencia(ifstream&);
};

#endif
