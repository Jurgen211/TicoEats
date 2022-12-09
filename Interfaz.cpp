#include "Interfaz.h"

int Bandera = 1;
int Menu = 1;
int Factura = 1532;
string cedulaUsuarioActual = "";
string cedulaRepartidorActual = "";

ifstream entradaUser;
ifstream entradaRepartidor;
ifstream entradaRestaurante;
ifstream entradaCombo;
ifstream entradaDesarrollador;
ifstream entradaPedido;
ifstream entradaContadores;
ifstream entradaCostos;
ifstream entradaFactura;

ofstream salidaUser;
ofstream salidaRepartidor;
ofstream salidaRestaurante;
ofstream salidaCombo;
ofstream salidaDesarrollador;
ofstream salidaSugerencia;
ofstream salidaPedido;
ofstream salidaContadores;
ofstream salidaCostos;
ofstream salidaFactura;

Lista * _listaUser = NULL;
Lista * _listaRepartidor = NULL;
Lista * _listaRestaurante = NULL;
Lista * _listaCombo = NULL;
Lista * _listaPedido = NULL;
Lista * _listaDesarrollador = NULL;
Lista * _listaSugerencia = NULL;

void Interfaz::setListaUser (Lista *_listaUser) { listaUser = _listaUser;}
Lista * Interfaz::getListaUser ( ) { return listaUser;}
void Interfaz::setListaRepartidor (Lista *_listaRepartidor) { listaRepartidor = _listaRepartidor;}
Lista * Interfaz::getListaRepartidor ( ) { return listaRepartidor;}
void Interfaz::setListaCombo (Lista *_listaCombo) { listaCombo = _listaCombo;}
Lista * Interfaz::getListaCombo ( ) { return listaCombo;}
void Interfaz::setListaRestaurante(Lista *_listaRestaurante) { listaRestaurante = _listaRestaurante;}
Lista * Interfaz::getListaRestaurante( ) { return listaRestaurante;}

string *nombre;
string *apellido;
string *cedula;
string *correo;
string *password;
string *direccion;
string *numero_Telefono;
string *numero_Tarjeta;
char *estado;
string *tipo_comida;
string *combos;
int *pedidos;
double *vendido;

void Interfaz::Inicializar_Variables(){
	nombre = new string(); 
	apellido = new string(); 
	cedula = new string(); 
	correo = new string(); 
	password = new string(); 
	direccion = new string();
	numero_Telefono = new string();
	numero_Tarjeta = new string(); 
	estado = new char; 
	tipo_comida = new string();
	combos = new string();
	pedidos = new int;
	vendido = new double;
}

void Interfaz::Dibujar_Interfaz(){
	system ("cls"); if (Bandera%2 == 1){ system ("color f0");} else { system ("color 0f");} 	
	cuadro(2,2,100,28); cuadro(1,1,99,27); Titulo(); cout << hora(); string modo;
	
	switch(Menu){
	case 1: { modo = "Modo Usuario"; gotoxy(89-modo.size(), 5); cout << modo << endl; break;}
	case 2: { modo = "Modo Repartidor"; gotoxy(89-modo.size(), 5); cout << modo << endl; break;}
	case 3: { modo = "Modo Restaurante"; gotoxy(89-modo.size(), 5); cout << modo << endl; break;}
	case 4: { modo = "Modo Desarrollador"; gotoxy(89-modo.size(), 5); cout << modo << endl; break;}
	}
}

void Interfaz::gotoxy(int x,int y){  
	HANDLE hcon; 
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y = y;  
	SetConsoleCursorPosition(hcon, dwPos);  
}

void Interfaz::cuadro(int x1, int y1, int x2, int y2){
	int i;
	char izqarr = 218;
	char hori = 196;
	char derarr = 191;
	char vert = 179;
	char deraba = 217;
	char izqaba = 192;
	
	for (i=y1;i<y2;i++){	
		gotoxy(x1+1, i); cout << " " << endl;
		gotoxy(x1, i); cout << vert << endl;
		gotoxy(x2, i); cout << vert << endl;
	} gotoxy (x1, y1); cout << deraba << endl; 
	
	for (i=x1;i<x2;i++){	
		if (i < x2-1){
			gotoxy(i+1, y1+1); cout << " " << endl;
		}
		gotoxy(i, y1); cout << hori << endl;
		gotoxy(i, y2); cout << hori << endl;
	}
	
	gotoxy(x1,y1); cout << izqarr << endl;
	gotoxy(x1,y2); cout << izqaba << endl;
	gotoxy(x2,y1); cout << derarr << endl;
	gotoxy(x2,y2); cout << deraba << endl;
}

string Interfaz::hora(){
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output, 128, "%d/%m/%y %H:%M", tlocal);
	gotoxy (84, 26); 
	return output;
}

void Interfaz::Titulo ( ) { cuadro(11,2,89,4);
	gotoxy (45, 3);  cout << "CLETA EATS" << endl;
}

void Interfaz::Pantalla_Carga(){
	cout << "Loading" << endl;
}

void Interfaz::Adios(){

	cout << "Adios" << endl;
}

void Interfaz::Actualizar_User(){ 
	entradaUser.open("Archivos/Usuarios/Usuarios.txt"); User* user = NULL;
	
	entradaUser.clear(); entradaUser.seekg(0, ios::beg);
	while (entradaUser.good()){ 
		user = User::autoLeerUser(entradaUser);
		if (user != NULL) { 
			_listaUser->Insertar_User(user); 
		}
	} 
}

void Interfaz::Actualizar_Repartidor(){ 
	entradaRepartidor.open("Archivos/Repartidores/Repartidores.txt"); Repartidor* repartidor = NULL;
	
	entradaRepartidor.clear(); entradaRepartidor.seekg(0, ios::beg);
	while (entradaRepartidor.good()){
		repartidor = Repartidor::autoLeerRepartidor(entradaRepartidor);
		if (repartidor != NULL) { 
			_listaRepartidor->Insertar_Repartidor(repartidor); 
		}
	} 
}

void Interfaz::Actualizar_Restaurante(){ 
	entradaRestaurante.open("Archivos/Restaurantes/Restaurantes.txt"); Restaurante* restaurante = NULL;
	
	entradaRestaurante.clear(); entradaRestaurante.seekg(0, ios::beg);
	while (entradaRestaurante.good()){
		restaurante = Restaurante::autoLeerRestaurante(entradaRestaurante); 
		if (restaurante != NULL) { 
			_listaRestaurante->Insertar_Restaurante(restaurante); 
		}
	} 
}

void Interfaz::Actualizar_Desarrollador(){ 
	entradaDesarrollador.open("Archivos/Desarrolladores/Desarrolladores.txt"); Desarrollador* desarrollador = NULL;
	
	entradaDesarrollador.clear(); entradaDesarrollador.seekg(0, ios::beg);
	while (entradaDesarrollador.good()){
		desarrollador = Desarrollador::autoLeerDesarrollador(entradaDesarrollador); 
		if (desarrollador != NULL) { 
			_listaDesarrollador->Insertar_Desarrollador(desarrollador); 
		}
	} 
}

void Interfaz::Actualizar_Combo(int posicion){ entradaRestaurante.open("Archivos/Restaurantes/Restaurantes.txt");
	entradaRestaurante.clear(); entradaRestaurante.seekg(0, ios::beg);
	string _cedula, _password, _nombre, _tipo_Comida, _direccion;
	
	string nombreArchivo = ""; bool bandera = true; int contador = 1;
	while (entradaRestaurante.good() && (bandera == true)){
		entradaRestaurante >> _cedula; 
		entradaRestaurante >> _password; entradaRestaurante.ignore(); 
		getline(entradaRestaurante, _nombre, '%'); entradaRestaurante.ignore(); 
		getline(entradaRestaurante, _tipo_Comida, '&'); entradaRestaurante.ignore(); 
		getline(entradaRestaurante, _direccion, '#');
		
		if (contador == posicion){ bandera = false; 
			nombreArchivo += "Combo " + _nombre + ".txt";
			entradaCombo.open("Archivos/Restaurantes/Combos/" + nombreArchivo); Combo* combo = NULL;
			
			entradaCombo.clear(); entradaCombo.seekg(0, ios::beg);
			while (entradaCombo.good()){ 
				combo = Combo::autoLeerCombo(entradaCombo); 
				if (combo != NULL) { 
					_listaCombo->Insertar_Combo(combo); 
				}
			} 
		}
		contador++; 
	} 
}

int Interfaz::Extraer_Contador(ifstream& archivoContador){ 
	int contador = 69; 
	
	while (!archivoContador.eof()){
		archivoContador >> contador;
	}
	
	return contador;
}

//void Interfaz::Actualizar_Pedido(){ 
//	entradaPedido.open("Archivos/Usuarios/Usuarios.txt"); Combo* combo = NULL;
//	
//	entradaPedido.clear(); entradaPedido.seekg(1, ios::beg);
//	while (entradaPedido.good()){
//		combo = Combo::autoLeerCombo(entradaPedido);
//		if (combo != NULL) { 
//			_listaCombo->Insertar_Combo(combo); 
//		}
//	} 
//}

void Interfaz::Menu_Login ( ) {
	switch(Menu){
	case 1: { Dibujar_Interfaz(); entradaRepartidor.open("Archivos/Usuarios/Usuarios.txt");
	_listaUser = new Lista(); Inicializar_Variables(); Actualizar_User(); char Caracter;
		
		gotoxy(30, 8); cout << "Ingrese su cedula" << endl; cuadro(35, 9, 65, 11); 
		gotoxy(30, 13); cout << "Ingrese su clave de inicio" << endl; cuadro(35, 14, 65, 16);
		
		gotoxy(38, 10); cin >> *cedula;
		gotoxy(38, 15); Caracter = getch();
		
		while(Caracter != 13){
			if (Caracter != 8){
				password->push_back(Caracter); cout << "*";}
			
			else {
				if (password->length() > 0){
					cout << "\b \b";
					*password = password->substr(0, password->length()-1);}}
			Caracter = getch();}
		
		if (_listaUser -> User_Repetido(cedula)){
			cedulaUsuarioActual = *cedula;
			Pantalla_Carga();
			system ("pause");
			Menu_Main();
		}
		
		else{
			gotoxy (51-19, 19); cout << "La clave o la cedula es incorrecta" << endl;
			system("pause");
		}
		
		delete _listaUser;
		entradaUser.close();
		break;
	}
	
	case 2:{ Dibujar_Interfaz(); entradaRepartidor.open("Archivos/Repartidores/Repartidores.txt"); 
	_listaRepartidor = new Lista();Inicializar_Variables(); Actualizar_Repartidor(); char Caracter;
		
		gotoxy(30, 8); cout << "Ingrese su cedula" << endl; cuadro(35, 9, 65, 11); 
		gotoxy(30, 13); cout << "Ingrese su clave de inicio" << endl; cuadro(35, 14, 65, 16);
		
		gotoxy(38, 10); cin >> *cedula;
		gotoxy(38, 15); Caracter = getch();
		
		while(Caracter != 13){
			if (Caracter != 8){
				password->push_back(Caracter); cout << "*";}
			
			else {
				if (password->length() > 0){
					cout << "\b \b";
					*password = password->substr(0, password->length()-1);}}
			Caracter = getch();}
		
		if (_listaRepartidor -> Repartidor_Repetido(cedula)){
			cedulaRepartidorActual = *cedula;
			Pantalla_Carga();
			system ("pause");
			Menu_Main();
		}
		
		else{
			gotoxy (51-19, 19); cout << "La clave o la cedula es incorrecta" << endl;
			system("pause");
		}
		
		delete _listaRepartidor;
		entradaRepartidor.close();
		break;
	}
	
	case 3:{ Dibujar_Interfaz(); entradaRestaurante.open("Archivos/Restaurantes/Restaurantes.txt"); 
	_listaRestaurante = new Lista(); Inicializar_Variables(); Actualizar_Restaurante(); char Caracter;
		
		gotoxy(30, 8); cout << "Ingrese la cedula juridica" << endl; cuadro(35, 9, 65, 11); 
		gotoxy(30, 13); cout << "Ingrese su clave de inicio" << endl; cuadro(35, 14, 65, 16);
		
		gotoxy(38, 10); cin >> *cedula;
		gotoxy(38, 15); Caracter = getch();
		
		while(Caracter != 13){
			if (Caracter != 8){
				password->push_back(Caracter); cout << "*";}
			
			else {
				if (password->length() > 0){
					cout << "\b \b";
					*password = password->substr(0, password->length()-1);}}
			Caracter = getch();}
		
		if (_listaRestaurante -> Restaurante_Repetido(cedula)){
			Pantalla_Carga();
			system ("pause");
			Menu_Main();
		}
		
		else{
			gotoxy (51-19, 19); cout << "La clave o la cedula es incorrecta" << endl;
			system("pause");
		}
		
		delete _listaRestaurante;
		entradaRestaurante.close();
		break;	
	}
	
	case 4:{ Dibujar_Interfaz(); entradaDesarrollador.open("Archivos/Desarrolladores/Desarrolladores.txt"); 
	_listaDesarrollador = new Lista(); Inicializar_Variables(); Actualizar_Desarrollador(); char Caracter;
		
		gotoxy(30, 8); cout << "Ingrese el codigo " << endl; cuadro(35, 9, 65, 11); 
		gotoxy(30, 13); cout << "Ingrese su clave de inicio" << endl; cuadro(35, 14, 65, 16);
		
		gotoxy(38, 10); cin >> *cedula;
		gotoxy(38, 15); Caracter = getch();
		
		while(Caracter != 13){
			if (Caracter != 8){
				password->push_back(Caracter); cout << "*";}
			
			else {
				if (password->length() > 0){
					cout << "\b \b";
					*password = password->substr(0, password->length()-1);}}
			Caracter = getch();}
		
		if (_listaDesarrollador -> Desarrollador_Repetido(cedula)){
			Pantalla_Carga();
			system ("pause");
			Menu_Main();
		}
		
		else{
			gotoxy (51-19, 19); cout << "La clave o la cedula es incorrecta" << endl;
			system("pause");
		}
		
		delete _listaDesarrollador;
		entradaDesarrollador.close();
		break;
		}
	break;
	}
}

void Interfaz::Menu_Signup(){ 
	switch(Menu){
	case 1: { Dibujar_Interfaz(); salidaUser.open("Archivos/Usuarios/Usuarios.txt", ios::app); 
	_listaUser = new Lista(); Inicializar_Variables(); Actualizar_User();
		
		gotoxy(15, 8); cout << "Apellido" << endl; cuadro(20, 9, 40, 11); 
		gotoxy(15, 13); cout << "Nombre" << endl; cuadro(20, 14, 40, 16);
		gotoxy(15, 18); cout << "Cedula" << endl; cuadro(20, 19, 40, 21);
		gotoxy(15, 23); cout << "Password" << endl; cuadro(20, 24, 40, 26);
		gotoxy(45, 8); cout << "Correo" << endl; cuadro(50, 9, 89, 11); 
		gotoxy(45, 13); cout << "Numero de Telefono" << endl; cuadro(50, 14, 89, 16); 
		gotoxy(45, 18); cout << "Numero de Tarjeta" << endl; cuadro(50, 19, 89, 21); 
		gotoxy(45, 23); cout << "Direccion" << endl; cuadro(50, 24, 89, 26); 
		
		gotoxy(22, 10); cin >> *apellido;
		gotoxy(22, 15); cin >> *nombre;
		gotoxy(22, 20); cin >> *cedula;
		gotoxy(22, 25); cin >> *password;		
		gotoxy(52, 10); cin >> *correo;
		gotoxy(52, 15); cin >> *numero_Telefono;
		gotoxy(52, 20); cin >> *numero_Tarjeta;
		gotoxy(52, 25); cin.ignore(); getline(cin, *direccion);
		*estado = 'A';		
		
		if (_listaUser -> User_Repetido(cedula)){
			gotoxy (51-19, 19); cout << "Este usuario ya esta registrado" << endl;
			system("pause");
		}
		else{ *pedidos = 0;
			string nombreArchivo = "Contador " + *cedula + ".txt"; salidaContadores.open("Archivos/Usuarios/Contadores/" + nombreArchivo);
			User *user = new User(cedula, password, estado, nombre, apellido, correo, numero_Telefono, numero_Tarjeta, direccion, pedidos);
			user -> autoGuardarUser(salidaUser, salidaContadores);
			delete user;
		}
		
		Actualizar_User(); delete _listaUser; salidaUser.close(); break;
	}
	
	case 2:{ Dibujar_Interfaz(); salidaRepartidor.open("Archivos/Repartidores/Repartidores.txt", ios::app); 
	_listaRepartidor = new Lista(); Inicializar_Variables(); Actualizar_Repartidor();
	
		gotoxy(15, 8); cout << "Apellido" << endl; cuadro(20, 9, 40, 11); 
		gotoxy(15, 13); cout << "Nombre" << endl; cuadro(20, 14, 40, 16);
		gotoxy(15, 18); cout << "Cedula" << endl; cuadro(20, 19, 40, 21);
		gotoxy(15, 23); cout << "Password" << endl; cuadro(20, 24, 40, 26);
		gotoxy(45, 8); cout << "Correo" << endl; cuadro(50, 9, 89, 11); 
		gotoxy(45, 13); cout << "Numero de Telefono" << endl; cuadro(50, 14, 89, 16); 
		gotoxy(45, 18); cout << "Numero de Tarjeta" << endl; cuadro(50, 19, 89, 21); 
		gotoxy(45, 23); cout << "Direccion" << endl; cuadro(50, 24, 89, 26); 
		
		gotoxy(22, 10); cin >> *apellido;
		gotoxy(22, 15); cin >> *nombre;
		gotoxy(22, 20); cin >> *cedula;
		gotoxy(22, 25); cin >> *password;		
		gotoxy(52, 10); cin >> *correo;
		gotoxy(52, 15); cin >> *numero_Telefono;
		gotoxy(52, 20); cin >> *numero_Tarjeta;
		gotoxy(52, 25); cin.ignore(); getline(cin, *direccion);
		*estado = 'A';		
		
		if (_listaRepartidor -> Repartidor_Repetido(cedula)){
			gotoxy (51-19, 19); cout << "Este usuario ya esta registrado" << endl;
			system("pause");
		}
		else{ 
			Repartidor *repartidor = new Repartidor(cedula, password, estado, nombre, apellido, correo, numero_Telefono, numero_Tarjeta, direccion);
			repartidor -> autoGuardarRepartidor(salidaRepartidor);
			delete repartidor;
		}
		
		Actualizar_Repartidor(); delete _listaRepartidor; salidaRepartidor.close(); break;
	}
	
	case 3:{ Dibujar_Interfaz(); salidaRestaurante.open("Archivos/Restaurantes/Restaurantes.txt", ios::app); 
	_listaRestaurante = new Lista(); Inicializar_Variables(); Actualizar_Restaurante();
	
		gotoxy(15, 8); cout << "Nombre" << endl; cuadro(20, 9, 40, 11); 
		gotoxy(15, 13); cout << "Cedula Juridica" << endl; cuadro(20, 14, 40, 16);
		gotoxy(15, 18); cout << "Password" << endl; cuadro(20, 19, 40, 21);
		gotoxy(15, 23); cout << "Tipo de Comida" << endl; cuadro(20, 24, 40, 26);
		gotoxy(45, 8); cout << "Direccion" << endl; cuadro(50, 9, 89, 11);
		
		gotoxy(22, 10); cin.ignore(); getline(cin, *nombre);
		gotoxy(22, 15); cin >> *cedula;
		gotoxy(22, 20); cin >> *password;
		gotoxy(22, 25); cin.ignore(); getline(cin, *tipo_comida);		
		gotoxy(52, 10); getline(cin, *direccion);
		
		string nombreArchivo = "Combo " + *nombre + ".txt"; 
		
		if (_listaRestaurante -> Restaurante_Repetido(cedula)){
			gotoxy (51-19, 19); cout << "Este restaurante ya esta registrado" << endl;
			system("pause");
		}
		else{
			salidaCombo.open("Archivos/Restaurantes/Combos/" + nombreArchivo, ios::app);
			
			*combos = ""; string nombreCombo = ""; string auxPal = ""; int precio = 4000, contador = 0, aux = 1, total = 0;
			
			for(int i = 0; i < 9; i++){ Dibujar_Interfaz(); std::stringstream _aux; std::stringstream _total; 
				
				total = contador*1000 + precio;
				gotoxy(10, 7); cout << "Combo #" << aux << endl; 
				gotoxy(15, 8); cout << "Nombre" << endl; cuadro(18, 9, 60, 11); 
				gotoxy(63, 8); cout << "Precio" << endl; cuadro(66, 9, 86, 11); 
				gotoxy(69, 10); cout << total << " colones" << endl;
				gotoxy(22, 10); getline(cin, nombreCombo); 
				
				_aux << aux; _total << total; *combos += _aux.str() + "\n"; *combos += nombreCombo + "\n"; 
				if (i == 8) *combos += _total.str();
				else *combos += _total.str() + "\n";
				
				contador++; aux++;
			} *pedidos = 0; nombreArchivo = "Contador " + *nombre + ".txt"; salidaContadores.open("Archivos/Restaurantes/Contadores/" + nombreArchivo);
			
			*vendido = 0; nombreArchivo = "Costos " + *nombre + ".txt"; salidaCostos.open("Archivos/Restaurantes/Costos/" + nombreArchivo);
			
			Restaurante *restaurante = new Restaurante(cedula, password, nombre, tipo_comida, direccion, combos, pedidos, vendido);
			restaurante -> autoGuardarRestaurante(salidaRestaurante, salidaCombo, salidaContadores, salidaCostos);
			delete restaurante; 
		} salidaCombo.close();
		
		Actualizar_Restaurante(); delete _listaRestaurante; salidaRestaurante.close(); break;
		}
	}
}

void Interfaz::Menu_SubMenu( ) { SubMenu: int opc;
	for (;;){ Dibujar_Interfaz(); 
	
	if(Menu == 4){
		cuadro(35, 12, 65, 14); gotoxy(42, 13); cout << "1) Iniciar sesion" << endl; 
		cuadro(35, 15, 65, 17); gotoxy(43, 16); cout << "2) Atras" << endl; 
		gotoxy(3,26); cout << "Opcion: "; cin >> opc;
		
		if (opc == 2)
			opc++;
	}
	else{
		cuadro(35, 12, 65, 14); gotoxy(42, 13); cout << "1) Iniciar sesion" << endl; 
		cuadro(35, 15, 65, 17); gotoxy(43, 16); cout << "2) Registrarse" << endl; 
		cuadro(35, 18, 65, 20); gotoxy(46, 19); cout << "3) Atras" << endl;
		gotoxy(3,26); cout << "Opcion: "; cin >> opc;
	}
	switch(opc){
		case 1: 
			Menu_Login();
			break;
			
		case 2:
			Menu_Signup();
			break;
			
		case 3: 
			break;
			
		default: 
			goto SubMenu;
			break;
		}
		
		if (opc == 3)
			break;
	}
}

void Interfaz::Launcher(){ int Opcion;
	for (;;){ Dibujar_Interfaz(); 
	
	gotoxy(14, 7); cout << "Escoja una version de aplicacion" << endl; 
	cuadro(35, 9, 65, 11); gotoxy(42, 10); cout << "1) Modo usuario" << endl; 
	cuadro(35, 12, 65, 14); gotoxy(41, 13); cout << "2) Modo repartidor" << endl; 
	cuadro(35, 15, 65, 17); gotoxy(41, 16); cout << "3) Modo restaurante" << endl; 
	cuadro(35, 18, 65, 20); gotoxy(40, 19); cout << "4) Modo desarrollador" << endl; 
	cuadro(29, 22, 49, 24); gotoxy(35, 23); cout << "5) Salir" << endl;
	cuadro(51, 22, 71, 24); gotoxy(54, 23); cout << "6) Cambiar tema" << endl;
	cuadro(70, 18, 90, 20); gotoxy(74, 19); cout << "7) Ver Listas "<< endl; gotoxy(72, 21); cout <<"*Borrar antes de entregar" << endl;
	gotoxy(3,26); cout << "Opcion: "; cin >> Opcion; Menu = Opcion;
	
	if (Opcion == 1 || Opcion == 2 || Opcion == 3 || Opcion == 4){
		Menu_SubMenu();
	}
	else if (Opcion == 5){
		Adios();
		exit(0);
	}
	else if (Opcion == 6)
		Bandera++;
		
	else if (Opcion == 7){ system("cls"); int opc = 0;
		_listaUser = new Lista(); _listaRepartidor = new Lista(); _listaRestaurante = new Lista(); _listaCombo = new Lista();
		Actualizar_User(); Actualizar_Repartidor(); Actualizar_Restaurante(); system("pause"); system("cls");
		gotoxy(30, 1); cout << _listaUser -> Mostrar_ListaUser() << endl; system ("pause"); system("cls");
		gotoxy(30, 1); cout << _listaRepartidor -> Mostrar_ListaRepartidor() << endl; system ("pause"); system("cls");
		gotoxy(30, 1); cout << _listaRestaurante -> Mostrar_ListaRestaurante() << endl; 
		cout << "De que restaurante desea cargar la lista?" << endl;
		cin >> opc; int Cant_Res = _listaRestaurante -> Contar_Nodos();
		
		if (opc > 0 && opc < Cant_Res){ system ("cls"); Actualizar_Combo(opc);
			gotoxy(30, 1); cout << _listaCombo -> Mostrar_ListaCombo() << endl; system ("pause"); system("cls");
		}
		delete _listaUser; delete _listaRepartidor; delete _listaRestaurante; delete _listaCombo;
	}
	else 
		system("pause");
	}
}

void Interfaz::Menu_Main(){  int Opcion;
switch(Menu){
	case 1: { 
		for (;;){ Dibujar_Interfaz(); entradaUser.open("Archivos/Usuarios/Usuarios.txt"); 
		_listaUser = new Lista(); Inicializar_Variables(); Actualizar_User(); 
			
			cuadro(8, 8, 45, 10); gotoxy(17, 9); cout << "1) Ver Restaurantes" << endl;
			cuadro(8, 16, 28, 18); gotoxy(12, 17); cout << "2) Sugerencia" << endl;
			cuadro(8, 19, 28, 21); gotoxy(11, 20); cout << "3) Cambiar tema" << endl;
			cuadro(8, 22, 28, 24); gotoxy(10, 23); cout << "4) Cerrar sesion" << endl;
			cin >> Opcion;
			
			switch(Opcion){
			case 1: { Dibujar_Interfaz();
			_listaRestaurante = new Lista(); _listaCombo = new Lista(); _listaPedido = new Lista(); Actualizar_Restaurante(); 
			int Cant_Restaurantes = _listaRestaurante -> Contar_Nodos();
				
				gotoxy(30, 0); _listaRestaurante -> Listar_Restaurante(8, 8); 
				cin >> Opcion; int rest = Opcion; Actualizar_Combo(rest);
					
					if (Opcion > 0 && Opcion < Cant_Restaurantes){ 
						for (;;){ Dibujar_Interfaz(); 
							cout << _listaRestaurante -> Buscar_Restaurante(rest); 
							
							cuadro(35, 9, 65, 11); gotoxy(41, 10); cout << "1) Agregar Combo" << endl; 
							cuadro(35, 12, 65, 14); gotoxy(41, 13); cout << "2) Quitar Combo" << endl; 
							cuadro(35, 15, 65, 17); gotoxy(40, 16); cout << "3) Confirmar compra" << endl; 
							cuadro(35, 18, 65, 20); gotoxy(40, 19); cout << "4) Ver lista de compra" << endl; 
							cuadro(35, 21, 65, 23); gotoxy(40, 22); cout << "5) Atras" << endl; 
							gotoxy(55, 24); cout << "Opcion: "; cin >> Opcion;
							
							switch(Opcion){
								case 1: { cuadro(67, 9, 82, 11); gotoxy(70, 10); cout << "Combo: "; cin >> Opcion; cout << endl;
									
									int *idCombo = new int; *idCombo = _listaCombo -> Obtener_IDCombo(Opcion);
									string *nombreCombo = new string(); *nombreCombo = _listaCombo -> Obtener_NombreCombo(Opcion);
									double *precioCombo = new double; *precioCombo = _listaCombo -> Obtener_PrecioCombo(Opcion);
									
									Combo * Pedido = new Combo(idCombo, nombreCombo, precioCombo);
									_listaPedido -> Insertar_Combo(Pedido);
									break;
								}
								case 2: { int *comboEliminado = new int; 
									
									cuadro(67, 12, 82, 14); gotoxy(70, 13); cout << "Combo: "; cin >> *comboEliminado; cout << endl;
									
									string ValidarEliminado = _listaPedido -> Eliminar_Combo(comboEliminado);
									
									if (ValidarEliminado == "0"){
										gotoxy(47, 26); cout << "Error, lista de compra vacia" << endl; system ("pause");
									}
									else{
										if (ValidarEliminado == "-1"){
											gotoxy(47, 26); cout << "Error, el combo no esta en la lista" << endl; system ("pause");
										}
										else{ 
											gotoxy(47, 26); cout << "Combo eliminado" << endl; system ("pause");
										}
									}
									
									break;
								}
								case 3: { Dibujar_Interfaz(); _listaRepartidor = new Lista(); Actualizar_Repartidor();
									string Fecha_Hora = hora(); int Distancia; double Total_Pagar();
									string CedulaCliente = cedulaUsuarioActual; string NombreCliente = _listaUser -> Extraer_NombreUsuario(cedulaUsuarioActual);
									string CedulaRepartidor = _listaRepartidor -> Primer_Repartidor(); string NombreRepartidor = _listaRepartidor -> Extraer_NombreRepartidor(CedulaRepartidor);
									bool Feriado; char Estado = 'P'; 
									
									//Ingresar info de factura
//									_listaPedido -> Calcular_Monto(Feriado, Distancia);
//									_listaPedido -> Designar_Repartidor();
//									_listaPedido -> Hacer_Factura(CedulaCliente, NombreCliente, CedulaRepartidor, NombreRepartidor, Estado, Fecha_Hora, Distancia, Feriado, Total_Pagar);
//									
									delete _listaRepartidor;
									break;
								}
								case 4: {
									Dibujar_Interfaz();
									cout << _listaPedido -> Mostrar_ListaCombo();
									system ("pause"); break;
								}
								default:{
									break;
								}
							}
							if (Opcion == 5){
								break;
							}
						}
						
					}
				Actualizar_Restaurante(); entradaRestaurante.close(); delete _listaRestaurante; break;
			}
			case 2: { Dibujar_Interfaz();
				gotoxy(12, 17); cout << "Sugerencia" << endl; system("pause");
				
				salidaSugerencia.open("Archivos/Usuarios/Sugerencias.txt", ios::app);
				_listaSugerencia = new Lista();
				
				string *nombreAutor = new string(); string *cedulaAutor = new string(); string *comentario = new string();
				
				cout << "Nombre: " << endl;
				cin >> *nombreAutor;
				cout << "Cedula: " << endl;
				cin >> *cedulaAutor;
				cout << "f" << endl;
				cout << "Describa el comentario: ";
				cin >> *comentario;
//				cin.ignore(); getline(cin, *comentario);
				
				Sugerencia *sugerencia = new Sugerencia(nombreAutor, cedulaAutor, comentario);
				sugerencia -> autoGuardarSugerencia(salidaSugerencia);
				
				break;
			}
			case 3:{
				Bandera++; break;
			}
			case 4:{
				break;
			}
			default:
				break;
			}
			if (Opcion == 4) break;
		}
	}
	case 2:{ Dibujar_Interfaz();
		for (;;){ Dibujar_Interfaz(); entradaRepartidor.open("Archivos/Repartidores/Repartidores.txt"); 
		_listaRepartidor = new Lista(); Inicializar_Variables(); Actualizar_Repartidor(); 
		
		cuadro(8, 8, 45, 10); gotoxy(17, 9); cout << "1) Ver Restaurantes" << endl;
		cuadro(8, 16, 28, 18); gotoxy(12, 17); cout << "2) Sugerencia" << endl;
		cuadro(8, 19, 28, 21); gotoxy(11, 20); cout << "3) Cambiar tema" << endl;
		cuadro(8, 22, 28, 24); gotoxy(10, 23); cout << "4) Cerrar sesion" << endl;
		cin >> Opcion;
		
		switch(Opcion){
		
		}
		}
	break;
	}

//	case 3:{ string modo = "Modo Restaurante"; entradaRestaurante.open("Archivos/Restaurantees/Restaurantees.txt"); _listaRestaurante = new Lista();
//	gotoxy (89-modo.size(), 5); cout << modo << endl; Inicializar_Variables(); Actualizar_Restaurante(); char Caracter;
//
//	entradaRestaurante.close();
//	break;	
//	}
//
//	case 4:{ string modo = "Modo Desarrollador"; entradaDesarrollador.open("Archivos/Desarrolladores/Desarrolladores.txt"); _listaDesarrollador = new Lista();
//	gotoxy (89-modo.size(), 5); cout << modo << endl; Inicializar_Variables(); Actualizar_Desarrollador(); char Caracter;
//
//	entradaDesarrollador.close();
//	break;	
//	}
//
//	cuadro(35, 9, 65, 11); gotoxy(42, 10); cout << "1) Modo usuario" << endl; 
//	cuadro(35, 12, 65, 14); gotoxy(41, 13); cout << "2) Modo repartidor" << endl; 
//	cuadro(35, 15, 65, 17); gotoxy(41, 16); cout << "3) Modo restaurante" << endl; 
//	cuadro(35, 18, 65, 20); gotoxy(40, 19); cout << "4) Modo desarrollador" << endl; 
//	cuadro(29, 22, 49, 24); gotoxy(35, 23); cout << "5) Salir" << endl;
//	cuadro(51, 22, 71, 24); gotoxy(54, 23); cout << "6) Cambiar tema" << endl;
//	gotoxy(3,26); cout << "Opcion: "; cin >> Opcion; Menu = Opcion;
//	}
}
}
