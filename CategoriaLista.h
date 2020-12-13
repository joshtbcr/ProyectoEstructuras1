#pragma once
#include <stdlib.h>
#include "NodoCategoria.h"
#include "NodoArticulo.h"
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

                //Para facilitar otros metodos que buscan un nodo
                NodoCategoria* dirNodo(string descripcion);
                void agregar(string);// Punto a
                void modificarCat(string, string); // Punto b
                void agregarArticuloCategoria(NodoArticulo*, string); // Punto c
                void eliminar(string); // Punto d
                void desplegarCategorias(); // Punto e
                void desplegarArticulos(string); // Punto f  


                //Categoria* getCategoria(string);
                

};
#endif