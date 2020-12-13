#pragma once
#include "Articulo.h"
class NodoArticulo
{
private:
	Articulo* articulo;
	NodoArticulo* siguiente;
public:
	NodoArticulo();
	NodoArticulo(Articulo* articulo);
	Articulo* getArticulo();
	void setArticulo(Articulo* articulo);
	NodoArticulo* getSiguiente();
	void setSiguiente(NodoArticulo* siguiente);
};

