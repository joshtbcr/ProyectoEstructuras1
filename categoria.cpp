#include "Categoria.h"
#include "ListaArticulosXCategoria.h"
#include "iostream"
using namespace std;

Categoria::Categoria()
{
	this->lista = NULL;
	this->descripcion = "";
}

Categoria::~Categoria()
{

}	
Categoria::Categoria(string descripcion)
{
	this->descripcion = descripcion;
	this->lista = NULL;
}
Categoria::Categoria(string descripcion, ListaArticulosXCategoria* lista)
{
	this->descripcion = descripcion;
	this->lista = lista;
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