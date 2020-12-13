#pragma once
#include <stdlib.h>
#include <iostream>
#include "NodoArticulo.h"
#include "NodoIntermedio.h"
using namespace std;
#ifndef LISTAARTICULOSXCATEGORIA_H
#define LISTAARTICULOSXCATEGORIA_H

class ListaArticulosXCategoria
{
	private:
        int largo;
		NodoIntermedio* nodoI;

	public:
		ListaArticulosXCategoria();
		~ListaArticulosXCategoria();
		ListaArticulosXCategoria(NodoIntermedio* nodoI);

		int getLargo();
		void setLargo(int);

		
		bool esVacia();

		NodoIntermedio* getNodoI();
		void setNodoI(NodoIntermedio*);

		void agregarArticulo(NodoArticulo*);
	
		void desplegar();
};
#endif