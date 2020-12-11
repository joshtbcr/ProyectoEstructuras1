#pragma once
#include <stdlib.h>
#include "iostream"
#include "ListaArticulosXCategoria.h"
using namespace std;
#ifndef CATEGORIA_H
#define CATEGORIA_H

class Categoria
{
	private:
		string descripcion;
        ListaArticulosXCategoria* lista;
	public:
		Categoria();
		Categoria(string);
		Categoria(string, ListaArticulosXCategoria*);
		~Categoria();

        ListaArticulosXCategoria* getLista();
        void setLista(ListaArticulosXCategoria*);

        string getDescripcion();
        void setDescripcion(string);



};
#endif