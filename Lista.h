#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

#include <stdlib.h>
#include <windows.h>
class Lista {
private:
	
public:
	Nodo *Cabeza;
	Nodo *Actual;
	
	Lista();
	~Lista();
	bool Empty();
	int Contar_Nodos();
	void gotoxy(int, int);
	
	void Insertar_User(User *);
	string Mostrar_User(string *);
	string Mostrar_ListaUser();
	string Eliminar_User(string *);
	bool User_Repetido(string *);
	string Extraer_NombreUsuario(string);
	
	void Insertar_Repartidor(Repartidor *);
	string Mostrar_Repartidor(string *);
	string Mostrar_ListaRepartidor();
	string Eliminar_Repartidor(string *);
	bool Repartidor_Repetido(string *);
	string Primer_Repartidor();
	string Extraer_NombreRepartidor(string);
	
	void Insertar_Restaurante(Restaurante *);
	string Mostrar_Restaurante(string *);
	string Mostrar_ListaRestaurante();
	string Eliminar_Restaurante(string *);
	bool Restaurante_Repetido(string *);
	void Listar_Restaurante(int, int);
	string Buscar_Restaurante(int);
	
	void Insertar_Combo(Combo *);
	string Mostrar_Combo(int *);
	string Mostrar_ListaCombo();
	string Eliminar_Combo(int *);
	int Obtener_IDCombo(int);
	string Obtener_NombreCombo(int);
	double Obtener_PrecioCombo(int);
	
//	void Hacer_Factura();
	
	void Insertar_Desarrollador(Desarrollador *);
	string Mostrar_Desarrollador(string *);
	string Mostrar_ListaDesarrollador();
	string Eliminar_Desarrollador(string *);
	bool Desarrollador_Repetido(string *);
	
	void Insertar_Sugerencia(Sugerencia *);
	string Mostrar_Sugerencia(string *);
	string Mostrar_ListaSugerencia();
	string Eliminar_Sugerencia(string *);

};

#endif

