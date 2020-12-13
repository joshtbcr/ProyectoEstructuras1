#include "Articulo.h"

Articulo::Articulo(string nombre, int codigo, string descripcion, float precio, string estatus, int cantidad)
{
	this->nombre = nombre;
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->precio = precio;
	this->estatus = estatus;
	this->cantidad = cantidad;
}

Articulo::~Articulo()
{
}

string Articulo::getNombre()
{
	return nombre;
}

void Articulo::setNombre(string nombre)
{
	this->nombre = nombre;
}

int Articulo::getCodigo()
{
	return codigo;
}

void Articulo::setCodigo(int codigo)
{
	this->codigo = codigo;
}

string Articulo::getDescripcion()
{
	return descripcion;
}

void Articulo::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}

float Articulo::getPrecio()
{
	return precio;
}

void Articulo::setPrecio(float precio)
{
	this->precio = precio;
}

string Articulo::getEstatus()
{
	return estatus;
}

void Articulo::setEstatus(string estatus)
{
	this->estatus = estatus;
}

int Articulo::getCantidad()
{
	return cantidad;
}

void Articulo::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
	if (cantidad == 0)
		setDescripcion("agotado"); 
}

void Articulo::toString()
{
	cout << "Nombre: " <<nombre<< endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Descripcion: " << descripcion << endl;
	cout << "Precio: " << precio << endl;
	if(estatus=="agotado")
		cout << "Estatus: " << estatus << endl;
	cout << "Cantidad: " << cantidad << endl;

}
