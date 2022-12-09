#include "Repartidor.h"

Repartidor::Repartidor(){
	Cedula = new string();
	Password = new string();
	Estado = new char; *Estado = 'D';
	Nombre = new string();
	Apellido = new string();
	Correo = new string();
	Numero_Telefono = new string();
	Numero_Tarjeta = new string();
	Direccion = new string();
	
	Distancia_Pedido = new int;
	Costo_DiaHabil = new double; *Costo_DiaHabil = 1000;
	Costo_DiaFeriado = new double; *Costo_DiaFeriado = 1500;
	Cantidad_Amonestaciones = new int; *Cantidad_Amonestaciones = 0;
}

Repartidor::Repartidor(string *cedula, string *password, char *estado, string *nombre, string *apellido, string *correo, 
					   string *num_telefono, string *num_tarjeta, string *direccion){
	Cedula = cedula;
	Password = password;
	Estado = estado;
	Apellido = apellido;
	Nombre = nombre;
	Correo = correo;
	Numero_Telefono = num_telefono;
	Numero_Tarjeta = num_tarjeta;
	Direccion = direccion;
	
	Distancia_Pedido = new int;
	Costo_DiaHabil = new double; *Costo_DiaHabil = 1000;
	Costo_DiaFeriado = new double; *Costo_DiaFeriado = 1500;
	Cantidad_Amonestaciones = new int; *Cantidad_Amonestaciones = 0;
}

Repartidor::~Repartidor(){
	delete Cedula;
	delete Password;
	delete Estado;
	delete Nombre;
	delete Apellido;
	delete Correo;
	delete Numero_Telefono;
	delete Numero_Tarjeta;
	delete Direccion;

	delete Distancia_Pedido;
	delete Costo_DiaHabil;
	delete Costo_DiaFeriado;
	delete Cantidad_Amonestaciones;
}

void Repartidor::setCedula(string *cedula){
	Cedula = cedula;
}

void Repartidor::setPassword(string *password){
	Password = password;
}

void Repartidor::setEstado(char *estado){
	Estado = estado;
}

void Repartidor::setNombre(string *nombre){
	Nombre = nombre;
}

void Repartidor::setApellido(string *apellido){
	Apellido = apellido;
}

void Repartidor::setCorreo(string *correo){
	Correo = correo;
}

void Repartidor::setNumero_Telefono(string *num_telefono){
	Numero_Telefono = num_telefono;
}

void Repartidor::setNumero_Tarjeta(string *num_tarjeta){
	Numero_Tarjeta = num_tarjeta;
}

void Repartidor::setDireccion(string *direccion){
	Direccion = direccion;
}
	
void Repartidor::setDistancia_Pedido(int *distancia){
	Distancia_Pedido = distancia;
}

void Repartidor::setCosto_DiaHabil(double *costo_habil){
	Costo_DiaHabil = costo_habil;
}

void Repartidor::setCosto_DiaFeriado(double *costo_feriado){
	Costo_DiaFeriado = costo_feriado;
}

void Repartidor::setCantidad_Amonestaciones(int *cant_amonestaciones){
	Cantidad_Amonestaciones = cant_amonestaciones;
}

string Repartidor::getCedula(){
	return *Cedula;
}

string Repartidor::getPassword(){
	return *Password;
}

char Repartidor::getEstado(){
	return *Estado;
}

string Repartidor::getNombre(){
	return *Nombre;
}

string Repartidor::getApellido(){
	return *Apellido;
}

string Repartidor::getCorreo(){
	return *Correo;
}

string Repartidor::getNumero_Telefono(){
	return *Numero_Telefono;
}

string Repartidor::getNumero_Tarjeta(){
	return *Numero_Tarjeta;
}

string Repartidor::getDireccion(){
	return *Direccion;
}

int Repartidor::getDistancia_Pedido(){
	return *Distancia_Pedido;
}

double Repartidor::getCosto_DiaHabil(){
	return *Costo_DiaHabil;
}

double Repartidor::getCosto_DiaFeriado(){
	return *Costo_DiaFeriado;
}

int Repartidor::getCantidad_Amonestaciones(){
	return *Cantidad_Amonestaciones;
}

string Repartidor::toString ( ) {
	stringstream a;
	
	a << endl;
	a << "+======= REPARTIDOR =======+" << endl << endl;
	a << "Nombre: " << getNombre() << endl;
	a << "Apellido: " << getApellido() << endl;
	a << "Cedula: " << getCedula() << endl;
	a << "Correo: " << getCorreo() << endl;
	a << "Direccion: " << getDireccion() << endl;
	a << "Numero de telefono: " << getNumero_Telefono() << endl;
	a << "Numero de tarjeta: " << getNumero_Tarjeta() << endl;
	a << "Estado: " << getEstado() << endl;
	a << endl;
	
	return a.str();
}

void Repartidor::autoGuardarRepartidor(ofstream& archivo){
	archivo << *Cedula << endl;
	archivo << *Password << endl;
	archivo << *Estado << endl;
	archivo << *Nombre << endl;
	archivo << *Apellido << endl;
	archivo << *Correo << endl;
	archivo << *Numero_Telefono << endl;
	archivo << *Numero_Tarjeta << endl;
	archivo << *Direccion + '#' << endl;
}

Repartidor *Repartidor::autoLeerRepartidor(ifstream& archivo){
	string *_cedula = new string();
	string *_password = new string();
	char *_estado = new char;
	string *_nombre = new string();
	string *_apellido = new string();
	string *_correo = new string();
	string *_numero_Telefono = new string();
	string *_numero_Tarjeta = new string();
	string *_direccion = new string();
	
	if(!(archivo >> *_cedula)){ return NULL;}
	if(!(archivo >> *_password)){ return NULL;}
	if(!(archivo >> *_estado)){ return NULL;}
	if(!(archivo >> *_nombre)){ return NULL;}
	if(!(archivo >> *_apellido)){ return NULL;}
	if(!(archivo >> *_correo)){ return NULL;}
	if(!(archivo >> *_numero_Telefono)){ return NULL;}
	if(!(archivo >> *_numero_Tarjeta)){ return NULL;} archivo.ignore();
	if(!(getline(archivo, *_direccion, '#'))){ return NULL;}
	
	return new Repartidor(_cedula, _password, _estado, 
					_nombre, _apellido, _correo, 
					_numero_Telefono, _numero_Tarjeta, _direccion);
	
}
