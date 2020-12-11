#include <iostream>
#include <stdlib.h>
#include "CategoriaLista.h"
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
    catLista->desplegarCategorias();

    cout <<"Modificando indice 2:"<<endl;
    catLista->modificarCat(2,"Navidad");
    catLista->desplegarCategorias();

    cout <<"Eliminando indice 3:"<<endl;
    catLista->eliminar(3);
    catLista->desplegarCategorias();

    cout <<"Probando Articulos:"<<endl;


    pauseSystem();
}
