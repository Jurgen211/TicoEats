#include "Nodo.h"

Nodo::Nodo(User *_user){
	setUser(_user); 
	Siguiente = NULL;
}

Nodo::~Nodo(){
}

Nodo::Nodo(Repartidor *_repartidor){
	setRepartidor(_repartidor); 
	Siguiente = NULL;
}

Nodo::Nodo(Restaurante *_restaurante){
	setRestaurante(_restaurante); 
	Siguiente = NULL;
}

Nodo::Nodo(Combo *_combo){
	setCombo(_combo); 
	Siguiente = NULL;
}
	
Nodo::Nodo(Desarrollador *_desarrollador){
	setDesarrollador(_desarrollador); 
	Siguiente = NULL;
}

Nodo::Nodo(Sugerencia *_sugerencia){
	setSugerencia(_sugerencia); 
	Siguiente = NULL;
}

void Nodo::setUser(User *_user){
	user = _user;
}	

void Nodo::setRepartidor(Repartidor *_repartidor){
	repartidor = _repartidor;
}

void Nodo::setRestaurante(Restaurante *_restaurante){
	restaurante = _restaurante;
}

void Nodo::setCombo(Combo *_combo){
	combo = _combo;
}

void Nodo::setDesarrollador(Desarrollador *_desarrollador){
	desarrollador = _desarrollador;
}

void Nodo::setSugerencia(Sugerencia *_sugerencia){
	sugerencia = _sugerencia;
}

void Nodo::setSiguiente(Nodo *siguiente){
	Siguiente = siguiente;
}

User * Nodo::getUser(){
	return user;
}

Repartidor * Nodo::getRepartidor(){
	return repartidor;
}

Restaurante * Nodo::getRestaurante(){
	return restaurante;
}

Combo * Nodo::getCombo(){
	return combo;
}

Desarrollador * Nodo::getDesarrollador(){
	return desarrollador;
}

Sugerencia * Nodo::getSugerencia(){
	return sugerencia;
}

Nodo * Nodo::getSiguiente(){
	return Siguiente;
}

string Nodo::toStringUser ( ) {
	return user -> toString();
}

string Nodo::toStringRepartidor ( ) {
	return repartidor -> toString();
}

string Nodo::toStringRestaurante ( ) {
	return restaurante -> toString();
}

string Nodo::toStringCombo ( ) {
	return combo -> toString();
}

string Nodo::toStringSugerencia ( ) {
	return sugerencia -> toString();
}
