#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class User {
private:
	string *Cedula;
	string *Password;
	char *Estado;
	string *Nombre;
	string *Apellido;
	string *Correo;
	string *Numero_Telefono;
	string *Numero_Tarjeta;
	string *Direccion;
	
	int *Cantidad_Pedidos;
	
public:
	User();
	User(string *, string *, char *, string *, string *, string *, string *, string *, string *, int *);
	~User();

	void setCedula(string *);
	void setPassword(string *);
	void setEstado(char *);
	void setNombre(string *);
	void setApellido(string *);
	void setCorreo(string *);
	void setNumero_Telefono(string *);
	void setNumero_Tarjeta(string *);
	void setDireccion(string *);
	
	void setCantidad_Pedidos(int *);
	
	string getCedula();
	string getPassword();
	char getEstado();
	string getNombre();
	string getApellido();
	string getCorreo();
	string getNumero_Telefono();
	string getNumero_Tarjeta();
	string getDireccion();
	
	int getCantidad_Pedidos();
	
	string toString();
	
	void autoGuardarUser(ofstream&, ofstream&);
	static User *autoLeerUser(ifstream&);
};

#endif

