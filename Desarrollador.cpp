#include "Desarrollador.h"

Desarrollador::Desarrollador() {
	Codigo = new string();
	Password = new string();
}

Desarrollador::Desarrollador (string *codigo, string *password) {
	Codigo = codigo;
	Password = password;
}

Desarrollador::~Desarrollador ( ) {
	delete Codigo;
	delete Password;
}

void Desarrollador::setCodigo(string *codigo){
	Codigo = codigo;
}

void Desarrollador::setPassword(string *password){
	Password = Password;
}

string Desarrollador::getCodigo(){
	return *Codigo;
}

string Desarrollador::getPassword(){
	return *Password;
}
//
//void Desarrollador::autoGuardarRestaurante(ofstream& archivo){
//	archivo << *Codigo << endl;
//	archivo << *Password << endl;
//}

Desarrollador * Desarrollador::autoLeerDesarrollador (ifstream &archivo) {
	string *_codigo = new string();
	string *_password = new string();
	
	if(!(archivo >> *_codigo)){ return NULL;}
	if(!(archivo >> *_password)){ return NULL;} 
	
	return new Desarrollador(_codigo, _password);
}

