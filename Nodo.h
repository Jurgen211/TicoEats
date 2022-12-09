#ifndef NODO_H
#define NODO_H
#include "User.h"
#include "Repartidor.h"
#include "Restaurante.h"
#include "Combo.h"
#include "Desarrollador.h"
#include "Sugerencia.h"

class Nodo {
private:
	User *user;
	Repartidor *repartidor;
	Restaurante *restaurante;
	Combo *combo;
	Desarrollador *desarrollador;
	Sugerencia *sugerencia;
	Nodo *Siguiente;
	
public:
	Nodo(User *);
	Nodo(Repartidor *);
	Nodo(Restaurante *);
	Nodo(Combo *);
	Nodo(Desarrollador *);
	Nodo(Sugerencia *);
	virtual ~Nodo();
	
	void setUser(User *);
	void setRepartidor(Repartidor *);
	void setRestaurante(Restaurante *);
	void setCombo(Combo *);
	void setDesarrollador(Desarrollador*);
	void setSugerencia(Sugerencia*);
	void setSiguiente(Nodo *);
	
	User * getUser();
	Repartidor * getRepartidor();
	Restaurante * getRestaurante();
	Combo * getCombo();
	Desarrollador * getDesarrollador();
	Sugerencia * getSugerencia();
	Nodo * getSiguiente();
	
	string toStringUser();
	string toStringRepartidor();
	string toStringRestaurante();
	string toStringCombo();
	string toStringSugerencia();
};

#endif

