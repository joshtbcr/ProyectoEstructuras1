#include "Categoria.h"
#include "ListaArticulosXCategoria.h"
#include <iostream>
using namespace std;

Categoria::Categoria()
{
	this->lista = new ListaArticulosXCategoria();
	this->descripcion = "";
}


Categoria::Categoria(string descripcion)
{
	this->descripcion = descripcion;
	this->lista = new ListaArticulosXCategoria();
}
Categoria::Categoria(string descripcion, ListaArticulosXCategoria* lista)
{
	this->descripcion = descripcion;
	this->lista = lista;
}
Categoria::~Categoria()
{

}	
string Categoria::getDescripcion(){
	return this->descripcion;
}
void Categoria::setDescripcion(string pdescripcion){
	this->descripcion = pdescripcion;
}

ListaArticulosXCategoria* Categoria::getLista(){
	return this->lista;
}

void Categoria::setLista(ListaArticulosXCategoria* lista){
	this->lista = lista;
}