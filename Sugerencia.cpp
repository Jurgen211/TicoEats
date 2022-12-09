#include "Sugerencia.h"

Sugerencia::Sugerencia() {
	CedulaAutor = new string();
	NombreAutor = new string();
	//	CedulaAcusado = new string();
	//	NombreAcusado = new string();
	ContenidoSugerencia = new string();
	
}
Sugerencia::Sugerencia(string *cedulaAutor, string *nombreAutor, string *contenidosugerencia) {
	CedulaAutor = cedulaAutor;
	NombreAutor = nombreAutor;
	//	CedulaAcusado = cedulaAcusado;
	//	NombreAcusado = nombreAcusado;
	ContenidoSugerencia = contenidosugerencia;
}

void Sugerencia::setCedulaAutor(string *cedulaAutor){
	CedulaAutor = cedulaAutor;
}

void Sugerencia::setNombreAutor(string *nombreAutor){
	NombreAutor = nombreAutor;
}

/*void Sugerencia::setCedulaAcusado(string *cedulaAcusado){
CedulaAcusado = cedulaAcusado;
}

void Sugerencia::setNombreAcusado(string *nombreAcusado){
NombreAcusado = nombreAcusado;
}*/

void Sugerencia::setContenidoSugerencia(string *contenidoSugerencia){
	ContenidoSugerencia = contenidoSugerencia;
}

string Sugerencia::getCedulaAutor(){
	return *CedulaAutor;
}

string Sugerencia::getNombreAutor(){
	return *NombreAutor;
}

/*string Sugerencia::getCedulaAcusado(){
return *CedulaAcusado;
}

string Sugerencia::getNombreAcusado(){
return *NombreAcusado;
}*/

string Sugerencia::getContenidoSugerencia(){
	return *ContenidoSugerencia;
}

string Sugerencia::toString(){
	stringstream a;
	
	a << endl;
	a << "+======= Sugerencias =======+" << endl << endl;
	a << "Nombre: " << getNombreAutor() << endl;
	a << "Cedula: " << getCedulaAutor() << endl;
	//	a << "Nombre del Repartidor: " <<getNombreAcusado() << endl;
	//	a << "Cedula del Repartidor: " << getCedulaAcusado() << endl << endl;
	a << getContenidoSugerencia() <<endl;
	
	return a.str();
}

void Sugerencia::autoGuardarSugerencia(ofstream& archivoSugerencia){
	archivoSugerencia << *CedulaAutor << endl;
	archivoSugerencia << *NombreAutor << endl;
	//	archivoSugerencia << *CedulaAcusado << endl;
	//	archivoSugerencia << *NombreAcusado << endl;
	archivoSugerencia << *ContenidoSugerencia + '@'<< endl;
	
}

Sugerencia *Sugerencia::autoLeerSugerencia(ifstream& archivoSugerencia){
	string *_cedulaAutor = new string();
	string *_nombreAutor = new string();
	//	string *_cedulaAcusado = new string();
	//	string *_nombreAcusado = new string();
	string *_contenidoSugerencia = new string();
	
	if(!(archivoSugerencia >> *_cedulaAutor)){ return NULL;}
	if(!(archivoSugerencia >> *_nombreAutor)){ return NULL;}
	//	if(!(archivoSugerencia >> *_cedulaAcusado)){ return NULL;}
	//	if(!(archivoSugerencia >> *_nombreAcusado)){ return NULL;}
	archivoSugerencia.ignore();
	if(!(getline(archivoSugerencia, *_contenidoSugerencia, '@'))){ return NULL;}
	
	return new Sugerencia(_cedulaAutor, _nombreAutor, _contenidoSugerencia);
}
