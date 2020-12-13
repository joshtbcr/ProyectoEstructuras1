#include "NodoArticulo.h"

NodoArticulo::NodoArticulo()
{
	articulo = NULL;
	siguiente = NULL;
}

NodoArticulo::NodoArticulo(Articulo* articulo)
{
	this->articulo = articulo;
	siguiente = NULL;
}

Articulo* NodoArticulo::getArticulo()
{
	return articulo;
}

void NodoArticulo::setArticulo(Articulo* articulo)
{
	this->articulo = articulo;
}

NodoArticulo* NodoArticulo::getSiguiente()
{
	return siguiente;
}

void NodoArticulo::setSiguiente(NodoArticulo* siguiente)
{
	this->siguiente = siguiente;
}
