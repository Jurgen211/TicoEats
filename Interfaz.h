#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "User.h"
#include "Repartidor.h"
#include "Restaurante.h"
#include "Combo.h"
#include "Lista.h"

#include <windows.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "string"
#include "sstream"

class Interfaz {
private:
	Lista *listaUser;
	Lista *listaRepartidor;
	Lista *listaCombo;
	Lista *listaRestaurante;
	
public:
	void setListaUser(Lista *);
	Lista * getListaUser();
	
	void setListaRepartidor(Lista *);
	Lista * getListaRepartidor();
	
	void setListaCombo(Lista *);
	Lista * getListaCombo();
	
	void setListaRestaurante(Lista *);
	Lista * getListaRestaurante();
	
	void Titulo();
	void Pantalla_Carga();
	void Adios();
	
	void Launcher();
	void Menu_SubMenu();
	void Menu_Main();
	void Menu_Login();
	void Menu_Signup();
	
	void Dibujar_Interfaz();
	void gotoxy(int, int);
	void cuadro(int, int, int, int);
	string hora();

	void Inicializar_Variables();
	int Actualizar_Contadores();
	void Actualizar_User();
	void Actualizar_Repartidor();
	void Actualizar_Restaurante();
	void Actualizar_Desarrollador();
	void Actualizar_Combo(int);
	
	int Extraer_Contador(ifstream&);
	
//	void Actualizar_Pedido();
	
};

#endif

