#include "Restaurante.h"

Restaurante::Restaurante(){
	Cedula = new string();
	Password = new string();
	Nombre = new string();
	Tipo_Comida = new string();
	Direccion = new string();
	Combos = new string();
	
	Cantidad_Pedidos = new int;
	Total_Vendido = new double;
	
}

Restaurante::Restaurante(string *cedula, string *password, string *nombre, 
						string *tipo_comida, string *direccion, 
						string *combos, int *cant_pedidos, double *total_vendido) {
	Cedula = cedula;
	Password = password;
	Nombre = nombre;
	Tipo_Comida = tipo_comida;
	Direccion = direccion;	
	Combos = combos;
	
	Cantidad_Pedidos = cant_pedidos;
	Total_Vendido = total_vendido;
}

Restaurante::~Restaurante(){
	delete Cedula;
	delete Password;
	delete Nombre;
	delete Tipo_Comida;	
	delete Direccion;
	delete Combos;
	
	delete Cantidad_Pedidos;
	delete Total_Vendido;
}

void Restaurante::setCedula(string *cedula){
	Cedula = cedula;
}

void Restaurante::setPassword(string *password){
	Password = password;
}

void Restaurante::setNombre(string *nombre){
	Nombre = nombre;
}

void Restaurante::setTipo_Comida(string *tipo_Comida){
	Tipo_Comida = tipo_Comida;
}

void Restaurante::setDireccion(string *direccion){
	Direccion = direccion;
}

void Restaurante::setCombos(string *combos){
	Combos = combos;
}

void Restaurante::setCantidad_Pedidos(int *cant_pedidos){
	Cantidad_Pedidos = cant_pedidos;
}

void Restaurante::setTotal_Vendido(double *total_vendido){
	Total_Vendido = total_vendido;
}

string Restaurante::getCedula(){
	return *Cedula;
}

string Restaurante::getPassword(){
	return *Password;
}

string Restaurante::getNombre(){
	return *Nombre;
}

string Restaurante::getTipo_Comida(){
	return *Tipo_Comida;
}

string Restaurante::getDireccion(){
	return *Direccion;
}

string Restaurante::getCombos(){
	return *Combos;
}

int Restaurante::getCantidad_Pedidos(){
	return *Cantidad_Pedidos;
}

double Restaurante::getTotal_Vendido(){
	return *Total_Vendido;
}

string Restaurante::toString ( ) {
	stringstream a;
	
	a << endl;
	a << "+======= RESTAURANTE =======+" << endl << endl;
	a << "Nombre: " << getNombre() << endl;
	a << "Cedula: " << getCedula() << endl;
	a << "Tipo de Comida: " << getTipo_Comida() << endl;
	a << "Direccion: " << getDireccion() << endl << endl;
	a << getCombos();
	a << endl;
	
	return a.str();
}

void Restaurante::autoGuardarRestaurante(ofstream& archivo, ofstream& archivocombos, ofstream& archivocontador, ofstream& archivocostos){
	archivo << *Cedula << endl;
	archivo << *Password << endl;
	archivo << *Nombre + '%' << endl;
	archivo << *Tipo_Comida + '&' << endl;
	archivo << *Direccion + '#' << endl;
	archivocombos << *Combos << endl;
	archivocontador << *Cantidad_Pedidos << endl;
	archivocostos << *Total_Vendido << endl;
}

Restaurante *Restaurante::autoLeerRestaurante(ifstream& archivo){ 
	string *_cedula = new string();
	string *_password = new string();
	string *_nombre = new string();
	string *_tipo_Comida= new string();
	string *_direccion = new string();
	string *_combos = new string();
	int *_pedidos = new int;
	double *_vendido = new double;
	
	if(!(archivo >> *_cedula)){ return NULL;}
	if(!(archivo >> *_password)){ return NULL;} archivo.ignore();
	if(!(getline(archivo, *_nombre, '%'))){ return NULL;} archivo.ignore();
	if(!(getline(archivo, *_tipo_Comida, '&'))){ return NULL;} archivo.ignore();
	if(!(getline(archivo, *_direccion, '#'))){ return NULL;}
	
	string nombreArchivo = "Combo " + *_nombre + ".txt"; 
	ifstream combos; combos.open("Archivos/Restaurantes/Combos/" + nombreArchivo); 
	
	string *Texto = new string(); string codi = ""; int cont = 0; std::stringstream _comb; 
	
	while(!combos.eof()){ 
		for (int i = 0; i < 3; i++){ 
			if (i == 0){ 
				getline(combos, codi);
				*Texto += "Combo #"; *Texto += codi; *Texto += '\n';
			}
			else{
				getline(combos, *_combos);
				*Texto += *_combos + '\n';
			}
			
		}
		*Texto += '\n';
		cont++; if (cont == 9) break;
	} combos.close();
	
	nombreArchivo = "Contador " + *_nombre + ".txt";
	ifstream archivocontador; archivocontador.open("Archivos/Restaurantes/Contadores/" + nombreArchivo);
	archivocontador.clear(); archivocontador.seekg(0, ios::beg);
	while (!archivocontador.eof()){
		archivocontador >> *_pedidos;
	}
	
	nombreArchivo = "Costos " + *_nombre + ".txt";
	ifstream archivocostos; archivocostos.open("Archivos/Restaurantes/Costos/" + nombreArchivo);
	archivocostos.clear(); archivocostos.seekg(0, ios::beg);
	while (!archivocostos.eof()){
		archivocostos >> *_vendido;
	}
	
	return new Restaurante(_cedula, _password, _nombre, 
					_tipo_Comida, _direccion, Texto, _pedidos, _vendido);
	
}
