#pragma once
#include <stdlib.h>
#include "NodoCategoria.h"
#include "Categoria.h"
#include "iostream"
using namespace std;
#ifndef CategoriaLista_H
#define CategoriaLista_H

class CategoriaLista
{
	private:    
                NodoCategoria* nodoS;
                int largo;

	public:
		CategoriaLista();
		~CategoriaLista();
                
                NodoCategoria* getNodoS();
                void setNodoS(NodoCategoria*);

                int getLargo();
                void setLargo(int);

                bool esVacia();

                void agregar(string);// Punto a
                void modificarCat(int, string); // Punto b
                //void agregarArticuloCategoria(Articulo*, string); // Punto c
                void eliminar(int); // Punto d
                void desplegarCategorias(); // Punto e
                void desplegarArticulos(); // Punto f
                

                Categoria* dirNodo();
                Categoria* dirUltimo();
                

};
#endif