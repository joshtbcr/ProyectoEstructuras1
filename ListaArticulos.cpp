#include "ListaArticulos.h"

ListaArticulos::ListaArticulos(){
	this->cab=NULL;
	this->largo=0;
}

int ListaArticulos::getLargo()
{
	return largo;
}

void ListaArticulos::setLargo(int largo)
{
	this->largo = largo;
}

NodoArticulo* ListaArticulos::getCab()
{
	return cab;
}

void ListaArticulos::setCab(NodoArticulo* cab)
{
	this->cab = cab;
}

void ListaArticulos::desplegar()
{
	NodoArticulo* aux = cab;
	while (aux != NULL)
	{
		aux->getArticulo()->toString();
		aux = aux->getSiguiente();
	}
}

void ListaArticulos::agregarInicio(Articulo* articulo)
{
	NodoArticulo* aux = new NodoArticulo(articulo);
	aux->setSiguiente(cab);
	cab = aux;
	largo++;
}

bool ListaArticulos::agregarAntesDe(Articulo* articulo, Articulo* referencia)
{
	bool agregado = false;
	if (largo != 0) {
		if (getCab()->getArticulo() == referencia)
		{
			agregarInicio(articulo);
			agregado = true;
		}
		else
		{
			NodoArticulo* ant = cab;
			while (ant->getSiguiente() != NULL && !agregado)
			{
				if (ant->getSiguiente()->getArticulo() == referencia)
				{
					NodoArticulo* nuevo = new NodoArticulo(articulo);//Crear nodo
					nuevo->setSiguiente(ant->getSiguiente());//Enlazar nodo
					ant->setSiguiente(nuevo);//Reacomodar con nuevo nodo
					largo++;
					agregado = true;
				}
				else
				{
					ant = ant->getSiguiente();
				}
			}
		}
	}

	return agregado;
}

bool ListaArticulos::esVacia()
{
	if (largo < 1)
		return true;
	return false;
}

void ListaArticulos::agregarFinal(Articulo* articulo)
{
	NodoArticulo* nuevo = new NodoArticulo(articulo);

	if (largo == 0) {
		cab = nuevo;
		largo++;
	}
	else {
		NodoArticulo* aux = cab;

		while (aux->getSiguiente() != NULL) {

			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
		largo++;
	}
}

void ListaArticulos::precioInventario()
{
	if (!esVacia()) {
		NodoArticulo* aux = cab;
		int precioIn = 0;
		while (aux->getSiguiente() != NULL) {
			if (aux->getArticulo()->getCantidad() != 0)
				precioIn+=aux->getArticulo()->getPrecio();
			aux = aux->getSiguiente();
		}
		cout << "Precio del inventario es de: " << precioIn<<endl;
	}
}

int ListaArticulos::cantidadEnCero()
{
	if (!esVacia()) {
		NodoArticulo* aux = cab;
		int precioIn = 0;
		while (aux->getSiguiente() != NULL) {
			if (aux->getArticulo()->getCantidad() == 0)
				precioIn++;
			aux = aux->getSiguiente();
		}
		cout << "Cantidad de articulos en cero es de: " << precioIn << endl;
		return precioIn;
	}else
		return NULL;
	
}

void ListaArticulos::listaAgotados()
{
	if (!esVacia()) {
		NodoArticulo* aux = cab;
		while (aux->getSiguiente() != NULL) {
			if (aux->getArticulo()->getCantidad ()== 0)
				aux->getArticulo()->toString();
			aux = aux->getSiguiente();
		}
	}
}

void ListaArticulos::listaNoAgotados()
{
	if (!esVacia()) {
		NodoArticulo* aux = cab;
		while (aux->getSiguiente() != NULL) {
			if (aux->getArticulo()->getCantidad() != 0)
				aux->getArticulo()->toString();
			aux = aux->getSiguiente();
		}
	}
}

void ListaArticulos::cambiarPrecios(int porcentaje)
{
	float convertido = 0;
	if(porcentaje>0){
		convertido = porcentaje / 100;
		convertido += 1;
	}
	else
	{
		convertido = porcentaje + 100;
		convertido /= 100;
	}
	if (!esVacia()) {
		NodoArticulo* aux = cab;
		while (aux->getSiguiente() != NULL) {
			if (aux->getArticulo()->getCantidad() != 0)
				aux->getArticulo()->setPrecio(aux->getArticulo()->getPrecio()* convertido);
			aux = aux->getSiguiente();
		}
	}
}

bool ListaArticulos::eliminar(int codigo)
{
	bool removido = true;
	NodoArticulo* aux;
	if (!esVacia())

		if (getCab()->getArticulo()->getCodigo() == codigo) {
			aux = getCab();
			setCab(aux->getSiguiente());
			delete aux;
			largo--;
			removido = true;

		}
		else {
			NodoArticulo* ant = dirAnterior(codigo);
			if (ant != NULL) {
				aux = ant->getSiguiente();
				ant->setSiguiente(aux->getSiguiente());
				delete aux;
				largo--;
				removido = true;
			}

		}

	return removido;
}

NodoArticulo* ListaArticulos::dirNodo(int codigo)
{
	NodoArticulo* aux = getCab();
	bool encontrado = false;
	if (aux->getArticulo()->getCodigo() == codigo) {
		encontrado = true;
		return aux;
	}
	else
	{
		while (aux->getSiguiente() != NULL)
		{
			if (aux->getSiguiente()->getArticulo()->getCodigo() == codigo) {
				return aux->getSiguiente();
				encontrado = true;
			}
			aux = aux->getSiguiente();
		}
		return aux;
	}
	if (encontrado == false)
	{
		return NULL;
	}
}

NodoArticulo* ListaArticulos::dirAnterior(int codigo)
{
	bool encontrado = false;

	if (cab->getArticulo()->getCodigo() == codigo)
	{
		return NULL;
	}
	else
	{
		NodoArticulo* ant = cab;
		while (ant->getSiguiente() != NULL) {
			if (ant->getSiguiente()->getArticulo()->getCodigo() == codigo)
			{
				return ant;
				encontrado = true;
			}
			ant = ant->getSiguiente();
		}
		return NULL;
	}
	if (encontrado == false)
	{
		return NULL;
	}
}

void ListaArticulos::buscarNombre(string nombre)
{
	NodoArticulo* aux = getCab();
	bool encontrado = false;
	if (aux->getArticulo()->getNombre() == nombre) {
		encontrado = true;
		aux->getArticulo()->toString();
	}
	else
	{
		while (aux->getSiguiente() != NULL)
		{
			if (aux->getSiguiente()->getArticulo()->getNombre() == nombre) {
				aux->getArticulo()->toString();
				encontrado = true;
			}
			aux = aux->getSiguiente();
		}
	}
	if (encontrado == false)
	{
		cout << "Articulo no encontrado" << endl;
	}
}

void ListaArticulos::buscarCodigo(int codigo)
{
	NodoArticulo* aux = getCab();
	bool encontrado = false;
	if (aux->getArticulo()->getCodigo() == codigo) {
		encontrado = true;
		aux->getArticulo()->toString();
	}
	else
	{
		while (aux->getSiguiente() != NULL)
		{
			if (aux->getSiguiente()->getArticulo()->getCodigo() == codigo) {
				aux->getArticulo()->toString();
				encontrado = true;
			}
			aux = aux->getSiguiente();
		}
	}
	if (encontrado == false)
	{
		cout << "Articulo no encontrado" << endl;
	}
}
