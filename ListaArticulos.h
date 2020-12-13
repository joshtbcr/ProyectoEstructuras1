#pragma once
#include "NodoArticulo.h"
class ListaArticulos
{
private:
	NodoArticulo* cab;
	int largo;
public:
	ListaArticulos();
	int getLargo();
	void setLargo(int largo);
	NodoArticulo* getCab();
	void setCab(NodoArticulo* cab);
	void desplegar();
	void agregarInicio(Articulo* articulo);
	bool agregarAntesDe(Articulo* articulo, Articulo* articulo2);
	bool esVacia();
	void agregarFinal(Articulo * articulo);
	void precioInventario();
	int cantidadEnCero();
	void listaAgotados();
	void listaNoAgotados();
	void cambiarPrecios(int porcentaje);
	bool eliminar(int codigo);
	NodoArticulo* dirNodo(int codigo);
	NodoArticulo* dirAnterior(int codigo);
	void buscarNombre(string nombre);
	void buscarCodigo(int codigo);


	
};

