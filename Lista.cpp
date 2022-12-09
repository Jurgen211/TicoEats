#include "Lista.h"

Lista::Lista() {
	Cabeza = Actual = NULL;
}

Lista::~Lista(){
	while (Cabeza != NULL){
		Actual = Cabeza;
		Cabeza = Cabeza->getSiguiente();
		delete Actual;
	}
}
	
bool Lista::Empty(){
	return  (Cabeza == NULL) ? true : false;
}	

void Lista::gotoxy(int x,int y){  
	HANDLE hcon; hcon = GetStdHandle(STD_OUTPUT_HANDLE); COORD dwPos; dwPos.X = x; dwPos.Y = y; SetConsoleCursorPosition(hcon, dwPos);  
}

int Lista::Contar_Nodos(){
	int Cantidad = 0;
	Actual = Cabeza;
	while(Actual != NULL){
		Cantidad++;
		Actual = Actual -> getSiguiente();
	}
	return Cantidad;
}

// +===============================================+
//					USERS
// +===============================================+

void Lista::Insertar_User(User *user){
	Nodo *Auxiliar = new Nodo(user);
	
	if(Empty()){
		Cabeza = Auxiliar;
	}
	else{
		Actual = Cabeza;
		while(Actual->getSiguiente() != NULL){
			Actual = Actual->getSiguiente();
		}
		Actual->setSiguiente(Auxiliar);
	}
}

string Lista::Mostrar_User(string *id){
	if (Cabeza == NULL){
		return "0";
	}
	else{
		Actual = Cabeza;
		
		bool Bandera = true;
		
		while ((Actual != NULL) && (Bandera == true)){ 
			if (Actual -> getUser() -> getCedula() == *id){
				Bandera = false;
				cout << Actual -> getUser() -> toString();
			}
			
			Actual = Actual -> getSiguiente();
		}
		
		if(Bandera == true){
			return "-1";
		}
	}
}

string Lista::Mostrar_ListaUser(){
	stringstream s;
	
	Actual = Cabeza;
	while (Actual != NULL){
		s << Actual -> toStringUser();
		Actual = Actual->getSiguiente();
	}
	
	return s.str();
}

string Lista::Eliminar_User(string *id){
	if (Cabeza == NULL){
		return "0";
	}
	else {
		Actual = Cabeza;
		
		Nodo *Auxiliar = Cabeza; 
		if (Cabeza -> getUser() -> getCedula() == *id){ 
			Cabeza = Cabeza -> getSiguiente(); 
			delete Auxiliar; 
			
			return "1";
		}
		else{
			bool Bandera = true;
			for (int i = 0; (Actual != NULL) && (Bandera == true); i++){
				if (Actual -> getSiguiente() -> getUser() -> getCedula() == *id){ 
					Auxiliar = Actual -> getSiguiente(); 
					Actual -> setSiguiente(Auxiliar -> getSiguiente()); 
					Bandera = false;
					
					return "1";
				}
				else{
					Actual = Actual -> getSiguiente();
				}
			}
			if (Actual -> getSiguiente() == NULL){
				return "-1";
			}
			delete Auxiliar; 
		}
	}
}

string Lista::Extraer_NombreUsuario(string ced){
	string nombre;
	
	Actual = Cabeza;
	while ((Actual != NULL)){ 
		if (Actual -> getUser() -> getCedula() == ced){
			nombre = Actual -> getUser() -> getNombre();
		}
		Actual = Actual -> getSiguiente();
	}
	
	return nombre;
}

bool Lista::User_Repetido(string *ced){
	char Suspendido = 'S';
	
	Actual = Cabeza;
	while ((Actual != NULL)){ 
		if(Actual -> getUser() -> getEstado() == Suspendido){
			return false;
		}
		else if (Actual -> getUser() -> getCedula() == *ced){
			return true;
		}
		
		Actual = Actual -> getSiguiente();
	}
	
	return false;
}

// +===============================================+
//					REPARTIDORES
// +===============================================+

void Lista::Insertar_Repartidor(Repartidor *repartidor){
	Nodo *Auxiliar = new Nodo(repartidor);
	
	if(Empty()){
		Cabeza = Auxiliar;
	}
	else{
		Actual = Cabeza;
		while(Actual->getSiguiente() != NULL){
			Actual = Actual->getSiguiente();
		}
		Actual->setSiguiente(Auxiliar);
	}
}

string Lista::Mostrar_Repartidor(string *id){
	if (Cabeza == NULL){
		return "0";
	}
	else{
		Actual = Cabeza;
		
		bool Bandera = true;
		
		while ((Actual != NULL) && (Bandera == true)){ 
			if (Actual -> getRepartidor() -> getCedula() == *id){
				Bandera = false;
				cout << Actual -> getRepartidor() -> toString();
			}
			
			Actual = Actual -> getSiguiente();
		}
		
		if(Bandera == true){
			return "-1";
		}
	}
}

string Lista::Mostrar_ListaRepartidor(){
	Actual = Cabeza;
	stringstream s;
	
	while (Actual != NULL){
		s << Actual -> toStringRepartidor();
		Actual = Actual->getSiguiente();
	}
	
	return s.str();
}

string Lista::Eliminar_Repartidor(string *id){
	if (Cabeza == NULL){
		return "0";
	}
	else {
		Actual = Cabeza;
		
		Nodo *Auxiliar = Cabeza; 
		if (Cabeza -> getRepartidor() -> getCedula() == *id){ 
			Cabeza = Cabeza -> getSiguiente(); 
			delete Auxiliar; 
			
			return "1";
		}
		else{
			bool Bandera = true;
			for (int i = 0; (Actual != NULL) && (Bandera == true); i++){
				if (Actual -> getSiguiente() -> getRepartidor() -> getCedula() == *id){ 
					Auxiliar = Actual -> getSiguiente(); 
					Actual -> setSiguiente(Auxiliar -> getSiguiente()); 
					Bandera = false;
					
					return "1";
				}
				else{
					Actual = Actual -> getSiguiente();
				}
			}
			if (Actual -> getSiguiente() == NULL){
				return "-1";
			}
			delete Auxiliar; 
		}
	}
}

bool Lista::Repartidor_Repetido(string *ced){
	int Suspendido = 4;
	
	Actual = Cabeza;
	while ((Actual != NULL)){ 
		if(Actual -> getRepartidor() -> getCantidad_Amonestaciones() == Suspendido){
			return false;
		}
		else if (Actual -> getRepartidor() -> getCedula() == *ced){
			return true;
		}
		
		Actual = Actual -> getSiguiente();
	}
	
	return false;
}


string Lista::Extraer_NombreRepartidor(string ced){
	string nombre;
	
	Actual = Cabeza;
	while ((Actual != NULL)){ 
		if (Actual -> getRepartidor() -> getCedula() == ced){
			nombre = Actual -> getRepartidor() -> getNombre();
		}
		Actual = Actual -> getSiguiente();
	}
	
	return nombre;
}

string Lista::Primer_Repartidor(){
	string ced;
	char Ocupado = 'O';
	
	Actual = Cabeza;
	bool bandera = true;
	while ((Actual != NULL)&&(bandera == true)){ 
		if (Actual -> getRepartidor() -> getEstado() != Ocupado){
			ced = Actual -> getRepartidor() -> getCedula();
			bandera = false;
		}
		Actual = Actual -> getSiguiente();
	}
	
	return ced;
}

// +===============================================+
//					RESTAURANTES
// +===============================================+

void Lista::Insertar_Restaurante(Restaurante *restaurante){
	Nodo *Auxiliar = new Nodo(restaurante);
	
	if(Empty()){
		Cabeza = Auxiliar;
	}
	else{
		Actual = Cabeza;
		while(Actual->getSiguiente() != NULL){
			Actual = Actual->getSiguiente();
		}
		Actual->setSiguiente(Auxiliar);
	}
}

string Lista::Mostrar_Restaurante(string *id){
	if (Cabeza == NULL){
		return "0";
	}
	else{
		Actual = Cabeza;
		
		bool Bandera = true;
		
		while ((Actual != NULL) && (Bandera == true)){ 
			if (Actual -> getRestaurante() -> getCedula() == *id){
				Bandera = false;
				cout << Actual -> getRestaurante() -> toString();
			}
			
			Actual = Actual -> getSiguiente();
		}
		
		if(Bandera == true){
			return "-1";
		}
	}
}

string Lista::Mostrar_ListaRestaurante(){
	Actual = Cabeza;
	stringstream s;
	
	while (Actual != NULL){ 
		s << Actual -> toStringRestaurante();
//		s << Actual -> getRestaurante() -> getCombos();
		Actual = Actual->getSiguiente();
	}
	
	return s.str();
}

string Lista::Eliminar_Restaurante(string *id){
	if (Cabeza == NULL){
		return "0";
	}
	else {
		Actual = Cabeza;
		
		Nodo *Auxiliar = Cabeza; 
		if (Cabeza -> getRestaurante() -> getCedula() == *id){ 
			Cabeza = Cabeza -> getSiguiente(); 
			delete Auxiliar; 
			
			return "1";
		}
		else{
			bool Bandera = true;
			for (int i = 0; (Actual != NULL) && (Bandera == true); i++){
				if (Actual -> getSiguiente() -> getRestaurante() -> getCedula() == *id){ 
					Auxiliar = Actual -> getSiguiente(); 
					Actual -> setSiguiente(Auxiliar -> getSiguiente()); 
					Bandera = false;
					
					return "1";
				}
				else{
					Actual = Actual -> getSiguiente();
				}
			}
			if (Actual -> getSiguiente() == NULL){
				return "-1";
			}
			delete Auxiliar; 
		}
	}
}

bool Lista::Restaurante_Repetido(string *ced){
	Actual = Cabeza;
	
	while ((Actual != NULL)){ 
		if (Actual -> getRestaurante() -> getCedula() == *ced){
			return true;
		}
		
		Actual = Actual -> getSiguiente();
	}
	
	return false;
}

void Lista::Listar_Restaurante(int x, int y){
	
	Actual = Cabeza; int i = 1;
	while (Actual != NULL){ 
		gotoxy(x, y); cout.fill(' '); cout.width(22); cout << left << " | " << Actual -> getRestaurante() -> getTipo_Comida() << endl;
		gotoxy(x, y); cout << i << ") "; cout << Actual -> getRestaurante() -> getNombre();
		
		y++; i++;
		Actual = Actual->getSiguiente();
	} cout << endl;
}

string Lista::Buscar_Restaurante(int posicion){
	string combos = ""; int contador = 1;
	
	Actual = Cabeza;
	bool bandera = true;
	while ((Actual != NULL)&&(bandera == true)) {
		if (contador == posicion){
			bandera = false;
			combos = Actual -> getRestaurante() -> getCombos();
		}
		Actual = Actual -> getSiguiente();
		contador++;
	}
	return combos;
}

// +===============================================+
//					COMBOS
// +===============================================+

void Lista::Insertar_Combo(Combo *combo){
	Nodo *Auxiliar = new Nodo(combo);
	
	if(Empty()){
		Cabeza = Auxiliar;
	}
	else{
		Actual = Cabeza;
		while(Actual->getSiguiente() != NULL){
			Actual = Actual->getSiguiente();
		}
		Actual->setSiguiente(Auxiliar);
	}
}

string Lista::Mostrar_Combo(int *id){
	if (Cabeza == NULL){
		return "0";
	}
	else{
		Actual = Cabeza;
		
		bool Bandera = true;
		
		while ((Actual != NULL) && (Bandera == true)){ 
			if (Actual -> getCombo() -> getIdentificador() == *id){
				Bandera = false;
				cout << Actual -> getCombo() -> toString();
			}
			
			Actual = Actual -> getSiguiente();
		}
		
		if(Bandera == true){
			return "-1";
		}
	}
}

string Lista::Mostrar_ListaCombo(){
	Actual = Cabeza;
	stringstream s;
	
	while (Actual != NULL){
		s << Actual -> toStringCombo();
		Actual = Actual->getSiguiente();
	}
	
	return s.str();
}

string Lista::Eliminar_Combo(int *id){
	if (Cabeza == NULL){ 
		return "0";
	}
	else {
		Actual = Cabeza;
		
		Nodo *Auxiliar = Cabeza; 
		if (Cabeza -> getCombo() -> getIdentificador() == *id){ 
			Cabeza = Cabeza -> getSiguiente(); 
			delete Auxiliar; 
			
			return "1";
		}
		else{
			bool Bandera = true;
			while((Actual -> getSiguiente() != NULL) && (Bandera == true)){
				if (Actual -> getSiguiente() -> getCombo() -> getIdentificador() == *id){ 
					Auxiliar = Actual -> getSiguiente(); 
					Actual -> setSiguiente(Auxiliar -> getSiguiente()); 
					Bandera = false;
				}
				else{
					Actual = Actual -> getSiguiente();
				}
			}
			cout << "Si llego aqui, estoy bien" << endl;
			if (Actual -> getSiguiente() == NULL){
				return "-1";
			}
			else {
				return "1";
			}
		}
		delete Auxiliar;
	}
}

int Lista::Obtener_IDCombo(int posicion){
	int id = 0; int contador = 1;
	
	Actual = Cabeza;
	bool bandera = true;
	while ((Actual != NULL)&&(bandera == true)) {
		if (contador == posicion){
			bandera = false;
			id = Actual -> getCombo() -> getIdentificador();
		}
		Actual = Actual -> getSiguiente();
		contador++;
	}
	return id;
}

string Lista::Obtener_NombreCombo(int posicion){
	string nombre = ""; int contador = 1;
	
	Actual = Cabeza;
	bool bandera = true;
	while ((Actual != NULL)&&(bandera == true)) {
		if (contador == posicion){
			bandera = false;
			nombre = Actual -> getCombo() -> getNombre();
		}
		Actual = Actual -> getSiguiente();
		contador++;
	}
	return nombre;
}

double Lista::Obtener_PrecioCombo(int posicion){
	double precio = 0; int contador = 1;
	
	Actual = Cabeza;
	bool bandera = true;
	while ((Actual != NULL)&&(bandera == true)) {
		if (contador == posicion){
			bandera = false;
			precio = Actual -> getCombo() -> getPrecio();
		}
		Actual = Actual -> getSiguiente();
		contador++;
	}
	return precio;
}

// +===============================================+
//					DESARROLLADOR
// +===============================================+

void Lista::Insertar_Desarrollador(Desarrollador *desarrollador){
	Nodo *Auxiliar = new Nodo(desarrollador);
	
	if(Empty()){
		Cabeza = Auxiliar;
	}
	else{
		Actual = Cabeza;
		while(Actual->getSiguiente() != NULL){
			Actual = Actual->getSiguiente();
		}
		Actual->setSiguiente(Auxiliar);
	}
}

string Lista::Eliminar_Desarrollador(string *codigo){
	if (Cabeza == NULL){
		return "0";
	}
	else {
		Actual = Cabeza;
		
		Nodo *Auxiliar = Cabeza; 
		if (Cabeza -> getDesarrollador() -> getCodigo() == *codigo){ 
			Cabeza = Cabeza -> getSiguiente(); 
			delete Auxiliar; 
			
			return "1";
		}
		else{
			bool Bandera = true;
			for (int i = 0; (Actual != NULL) && (Bandera == true); i++){
				if (Actual -> getSiguiente() -> getDesarrollador() -> getCodigo() == *codigo){ 
					Auxiliar = Actual -> getSiguiente(); 
					Actual -> setSiguiente(Auxiliar -> getSiguiente()); 
					Bandera = false;
					
					return "1";
				}
				else{
					Actual = Actual -> getSiguiente();
				}
			}
			if (Actual -> getSiguiente() == NULL){
				return "-1";
			}
			delete Auxiliar; 
		}
	}
}

bool Lista::Desarrollador_Repetido(string *codigo){
	Actual = Cabeza;
	
	while ((Actual != NULL)){ 
		if (Actual -> getDesarrollador() -> getCodigo() == *codigo){
			return true;
		}
		
		Actual = Actual -> getSiguiente();
	}
	
	return false;
}

// +===============================================+
//					SUGERENCIA
// +===============================================+

void Lista::Insertar_Sugerencia(Sugerencia *sugerencia){
	Nodo *Auxiliar = new Nodo(sugerencia);
	
	if(Empty()){
		Cabeza = Auxiliar;
	}
	else{
		Actual = Cabeza;
		while(Actual->getSiguiente() != NULL){
			Actual = Actual->getSiguiente();
		}
		Actual->setSiguiente(Auxiliar);
	}
}

string Lista::Mostrar_Sugerencia(string *cedulaAutor){
	if (Cabeza == NULL){
		return "0";
	}
	else{
		Actual = Cabeza;
		
		bool Bandera = true;
		
		while ((Actual != NULL) && (Bandera == true)){ 
			if (Actual -> getSugerencia() -> getCedulaAutor() == *cedulaAutor){
				Bandera = false;
				cout << Actual -> getSugerencia() -> toString();
			}
			
			Actual = Actual -> getSiguiente();
		}
		
		if(Bandera == true){
			return "-1";
		}
	}
}

string Lista::Mostrar_ListaSugerencia(){
	Actual = Cabeza;
	stringstream s;
	
	while (Actual != NULL){
		s << Actual -> toStringSugerencia();
		Actual = Actual->getSiguiente();
	}
	
	return s.str();
}

string Lista::Eliminar_Sugerencia(string *cedulaAutor){
	if (Cabeza == NULL){
		return "0";
	}
	else {
		Actual = Cabeza;
		
		Nodo *Auxiliar = Cabeza; 
		if (Cabeza -> getSugerencia() -> getCedulaAutor() == *cedulaAutor){ 
			Cabeza = Cabeza -> getSiguiente(); 
			delete Auxiliar; 
			
			return "1";
		}
		else{
			bool Bandera = true;
			for (int i = 0; (Actual != NULL) && (Bandera == true); i++){
				if (Actual -> getSiguiente() -> getSugerencia() -> getCedulaAutor() == *cedulaAutor){ 
					Auxiliar = Actual -> getSiguiente(); 
					Actual -> setSiguiente(Auxiliar -> getSiguiente()); 
					Bandera = false;
					
					return "1";
				}
				else{
					Actual = Actual -> getSiguiente();
				}
			}
			if (Actual -> getSiguiente() == NULL){
				return "-1";
			}
			delete Auxiliar; 
		}
	}
}
