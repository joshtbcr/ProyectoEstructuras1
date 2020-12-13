#include <iostream>
#include <stdlib.h>
#include "CategoriaLista.h"
#include "Articulo.h"
#include "Categoria.h"
#include "ListaArticulos.h"
using namespace std;

void pauseSystem(){
    string pause;
    do {
        puts("Desea cerrar? [S]");
        cin >> pause;
    }while(pause != "S");
}

int main()
{
    cout <<"--------------------------"<<endl;
    CategoriaLista* catLista = new CategoriaLista();

    catLista->agregar("Comida");
    catLista->agregar("Deporte");
    catLista->agregar("Oficina");
    //catLista->desplegarCategorias();
    cout <<"--------Probando Articulos:"<<endl;
    ListaArticulos* artLista = new ListaArticulos();

    Articulo* tortilla = new Articulo("Tortilla",10,"Tortilla con queso",2000,"Disponible",1);
    Articulo* silla = new Articulo("Silla",20,"Silla Ergonomica",15000,"Disponible",5);
    Articulo* laptop = new Articulo("Laptop",30,"Laptop Toshiba",300000,"Disponible",6);
    Articulo* tennis = new Articulo("Tennis",40,"Tennis NewBalance",30000,"Disponible",10);

    artLista->agregarInicio(tortilla);
    artLista->agregarInicio(silla);
    artLista->agregarInicio(laptop);
    artLista->agregarInicio(tennis);

    //artLista->desplegar();

    catLista->agregarArticuloCategoria(artLista->dirNodo(tortilla->getCodigo()),"Comida");
    catLista->agregarArticuloCategoria(artLista->dirNodo(silla->getCodigo()),"Oficina");
    catLista->agregarArticuloCategoria(artLista->dirNodo(laptop->getCodigo()),"Oficina");
    catLista->agregarArticuloCategoria(artLista->dirNodo(tennis->getCodigo()),"Deporte");

    cout<<"=======Articulos de Comida: "<< endl;
    catLista->desplegarArticulos("Comida");
    cout<<"=======Articulos de Oficina: "<< endl;
    catLista->desplegarArticulos("Oficina");
    cout<<"=======Articulos de Deporte: "<< endl;
    catLista->desplegarArticulos("Deporte");

    //pauseSystem();
}
