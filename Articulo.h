#pragma once
#include <string>
#include <iostream>

using namespace std;
class Articulo
{
private:
	string nombre;
	int codigo;
	string descripcion;
	float precio;
	string estatus;
	int cantidad;

public:
	Articulo(string nombre, int codigo, string descripcion, float precio, string estatus, int cantidad);
	~Articulo();
	string getNombre();
	void setNombre(string nombre);
	int getCodigo();
	void setCodigo(int codigo);
	string getDescripcion();
	void setDescripcion(string descripcion);
	float getPrecio();
	void setPrecio(float precio);
	string getEstatus();
	void setEstatus(string estatus);
	int getCantidad();
	void setCantidad(int cantidad);
	void toString();
};

