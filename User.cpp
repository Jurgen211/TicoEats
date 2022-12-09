#include "User.h"

User::User(){	
	Cedula = new string();
	Password = new string();
	Estado = new char; *Estado = 'A';
	Nombre = new string();
	Apellido = new string();
	Correo = new string();
	Numero_Telefono = new string();
	Numero_Tarjeta = new string();
	Direccion = new string();
	
	Cantidad_Pedidos = new int;
}

User::User(string *cedula, string *password, char *estado, string *nombre, string *apellido, string *correo, 
		   string *num_telefono, string *num_tarjeta, string *direccion, int *cant_pedidos){
	Cedula = cedula;
	Password = password;
	Estado = estado;
	Apellido = apellido;
	Nombre = nombre;
	Correo = correo;
	Numero_Telefono = num_telefono;
	Numero_Tarjeta = num_tarjeta;
	Direccion = direccion;
	Cantidad_Pedidos = cant_pedidos;
}

User::~User(){
	delete Cedula;
	delete Password;
	delete Estado;
	delete Nombre;
	delete Apellido;
	delete Correo;
	delete Numero_Telefono;
	delete Numero_Tarjeta;
	delete Direccion;
	delete Cantidad_Pedidos;
}

void User::setCedula(string *cedula){
	Cedula = cedula;
}

void User::setPassword(string *password){
	Password = password;
}
	
void User::setEstado(char *estado){
	Estado = estado;
}

void User::setNombre(string *nombre){
	Nombre = nombre;
}

void User::setApellido(string *apellido){
	Apellido = apellido;
}

void User::setCorreo(string *correo){
	Correo = correo;
}

void User::setNumero_Telefono(string *num_telefono){
	Numero_Telefono = num_telefono;
}

void User::setNumero_Tarjeta(string *num_tarjeta){
	Numero_Tarjeta = num_tarjeta;
}

void User::setDireccion(string *direccion){
	Direccion = direccion;
}

void User::setCantidad_Pedidos(int *cant_pedidos){
	Cantidad_Pedidos = cant_pedidos;
}

string User::getCedula(){
	return *Cedula;
}

string User::getPassword(){
	return *Password;
}

char User::getEstado(){
	return *Estado;
}

string User::getNombre(){
	return *Nombre;
}

string User::getApellido(){
	return *Apellido;
}

string User::getCorreo(){
	return *Correo;
}

string User::getNumero_Telefono(){
	return *Numero_Telefono;
}

string User::getNumero_Tarjeta(){
	return *Numero_Tarjeta;
}

string User::getDireccion(){
	return *Direccion;
}

int User::getCantidad_Pedidos(){
	return *Cantidad_Pedidos;
}

string User::toString ( ) {
	stringstream a;
	
	a << endl;
	a << "+======= USUARIO =======+" << endl << endl;
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

void User::autoGuardarUser(ofstream& archivo, ofstream& archivocontador){ 
	archivo << *Cedula << endl;
	archivo << *Password << endl;
	archivo << *Estado << endl;
	archivo << *Nombre << endl;
	archivo << *Apellido << endl;
	archivo << *Correo << endl;
	archivo << *Numero_Telefono << endl;
	archivo << *Numero_Tarjeta << endl;
	archivo << *Direccion + '#' << endl;
	archivocontador << *Cantidad_Pedidos << endl;
}

User *User::autoLeerUser(ifstream& archivo){
	string *_cedula = new string();
	string *_password = new string();
	char *_estado = new char;
	string *_nombre = new string();
	string *_apellido = new string();
	string *_correo = new string();
	string *_numero_Telefono = new string();
	string *_numero_Tarjeta = new string();
	string *_direccion = new string();
	int *_pedidos = new int;
	
	if(!(archivo >> *_cedula)){ return NULL;}
	if(!(archivo >> *_password)){ return NULL;}
	if(!(archivo >> *_estado)){ return NULL;}
	if(!(archivo >> *_nombre)){ return NULL;}
	if(!(archivo >> *_apellido)){ return NULL;}
	if(!(archivo >> *_correo)){ return NULL;}
	if(!(archivo >> *_numero_Telefono)){ return NULL;}
	if(!(archivo >> *_numero_Tarjeta)){ return NULL;} archivo.ignore();
	if(!(getline(archivo, *_direccion, '#'))){ return NULL;}
	
	string nombreArchivo = "Contador " + *_cedula + ".txt";
	ifstream archivocontador; archivocontador.open("Archivos/Usuarios/Contadores/" + nombreArchivo);
	archivocontador.clear(); archivocontador.seekg(0, ios::beg);
	
	while (!archivocontador.eof()){ 
		archivocontador >> *_pedidos;
	}
	
	return new User(_cedula, _password, _estado, 
					_nombre, _apellido, _correo, 
					_numero_Telefono, _numero_Tarjeta, _direccion, _pedidos);
	
}
