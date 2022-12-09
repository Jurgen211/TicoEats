#ifndef REPARTIDOR_H
#define REPARTIDOR_H

#include <iostream>
#include <sstream>
#include<fstream>

using namespace std;

class Repartidor {
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
	
	int *Distancia_Pedido;
	double *Costo_DiaHabil;
	double *Costo_DiaFeriado;
	int *Cantidad_Amonestaciones;
	
public:
	Repartidor();
	Repartidor(string *, string *, char *, string *, string *, string *, string *, string *, string *);
	~Repartidor();
	
	void setCedula(string *);
	void setPassword(string *);
	void setEstado(char *);
	void setNombre(string *);
	void setApellido(string *);
	void setCorreo(string *);
	void setNumero_Telefono(string *);
	void setNumero_Tarjeta(string *);
	void setDireccion(string *);
	
	void setDistancia_Pedido(int *);
	void setCosto_DiaHabil(double *);
	void setCosto_DiaFeriado(double *);
	void setCantidad_Amonestaciones(int *);
	
	string getCedula();
	string getPassword();
	char getEstado();
	string getNombre();
	string getApellido();
	string getCorreo();
	string getNumero_Telefono();
	string getNumero_Tarjeta();
	string getDireccion();
	
	int getDistancia_Pedido();
	double getCosto_DiaHabil();
	double getCosto_DiaFeriado();
	int getCantidad_Amonestaciones();
	
	string toString();
	
	void autoGuardarRepartidor(ofstream&);
	static Repartidor* autoLeerRepartidor(ifstream&);
};

#endif

