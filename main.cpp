#include <iostream>
#include <stdlib.h>
#include "CategoriaLista.h"
#include "Articulo.h"
#include "categoria.h"
#include "ListaArticulos.h"

using namespace std;

void opciones();
void menu();
void menuArticulo();
void menuCat();
void menuReportes();
void opcionesArt();
void opcionesCat();
void opcionesRep();
void agregarArt();
void modifArt();
void modifExis();
void eliminarArt();
void desplegarArt();
void actPrecios();
void agregarCat();
void modifNomCat();
void agregarArtCat();
void eliminarCat();
void desplegarCat();
void desplegarArtXCat();
void precioInv();
void cantArtCero();
void artAgotado();
void artNAgotado();

Articulo *nodoArt;
Categoria *nodoCat;
ListaArticulos *listaArticulos;
CategoriaLista * categoriaLista;
NodoArticulo *na;
NodoCategoria *nc;

int incrementalArt = 1;
int incrementalCat = 1;

int main() {


    return 0;
}

void opciones() {
    int numero = -1;
    while (numero != 5) {
        menu();
        cin >> numero;
        switch (numero) {
            case 1:
                opcionesArt();
                break;
            case 2:
                opcionesCat();
                break;
            case 3:
                opcionesRep();
                break;
            case 4:
                //Salir
                break;
            default:
                break;
        }
    }


}

void menu() {
    cout << "Bienvenidos al almacen La Luna" << endl;
    cout << "\n" << endl;
    cout << "Seleccione 1 para ir al apartado de articulos" << endl;
    cout << "Seleccione 2 para ir al apartado de categorias" << endl;
    cout << "Seleccione 3 para ir al apartado de reportes" << endl;
    cout << "Seleccione 4 para salir del programa" << endl;
}

void menuArticulo() {
    cout << "Seleccione 1 para agregar articulos" << endl;
    cout << "Seleccione 2 para modificar un articulo" << endl;
    cout << "Seleccione 3 para modificar exitencia" << endl;
    cout << "Seleccione 4 para eliminar un articulo" << endl;
    cout << "Seleccione 5 para desplegar lista de articulos" << endl;
    cout << "Seleccione 6 para actualizar precios de articulos" << endl;
    cout << "Seleccione 7 para volver al menu principal" << endl;
}

void menuCat() {
    cout << "Seleccione 1 para agregar categoria" << endl;
    cout << "Seleccione 2 para modificar el nombre de una categoria" << endl;
    cout << "Seleccione 3 para agregar articulo a una categoria" << endl;
    cout << "Seleccione 4 para eliminar una categoria" << endl;
    cout << "Seleccione 5 para desplegar lista de categorias" << endl;
    cout << "Seleccione 6 para desplegar articulos de una categoria" << endl;
    cout << "Seleccione 7 para volver al menu principal" << endl;
}

void menuReportes() {
    cout << "Seleccione 1 para ver el precio total del inventario existente" << endl;
    cout << "Seleccione 2 para ver la cantidad de articulos con existencia en cero" << endl;
    cout << "Seleccione 3 para ver la cantidad de articulos agotados" << endl;
    cout << "Seleccione 4 para ver la cantidad de articulos no agotados" << endl;
    cout << "Seleccione 5 para desplegar lista de articulos" << endl;
    cout << "Seleccione 6 para desplegar lista de categorias" << endl;
    cout << "Seleccione 7 para desplegar los articulos de una lista" << endl;
    cout << "Seleccione 8 para volver al menu principal" << endl;
}

void opcionesArt() {
    int numero = -1;
    while (numero != 5) {
        menuArticulo();
        cin >> numero;
        switch (numero) {
            case 1:
                agregarArt();
                break;
            case 2:
                modifArt();
                break;
            case 3:
                modifExis();
                break;
            case 4:
                eliminarArt();
                break;
            case 5:
                desplegarArt();
                break;
            case 6:
                actPrecios();
                break;
            case 7:
                //Salida de este menu
                break;
            default:
                break;
        }
    }
}

void actPrecios() {

}

void desplegarArt() {

}

void eliminarArt() {

}

void modifExis() {

}

void modifArt() {

}

void agregarArt() {
    string nombre;
    int codigo;
    string descripcion;
    float precio;
    string estatus;
    int cantidad;

    cout << "Porfavor escriba el nombre del articulo" << endl;
    cin >> nombre;
    cout << "Porfavor escriba la descripcion del articulo" << endl;
    cin >> descripcion;
    cout << "Porfavor escriba el precio del articulo" << endl;
    cin >> precio;
    cout << "Porfavor escriba el estatus del articulo" << endl;
    cin >> estatus;
    cout << "Porfavor escriba la cantidad del articulo" << endl;
    cin >> cantidad;
    codigo = incrementalArt;
    incrementalArt++;

    if (listaArticulos ->esVacia()) {
        nodoArt = new Articulo(nombre,codigo,descripcion,precio,estatus,cantidad);
        na = new NodoArticulo(nodoArt);
        //listaArticulos ->agregarInicio(na);
    } else {
        nodoArt = new Articulo(nombre,codigo,descripcion,precio,estatus,cantidad);
        na = new NodoArticulo(nodoArt);
        //listaArticulos ->agregarFinal(na);
    }

}

void opcionesCat() {
    int numero = -1;
    while (numero != 5) {
        menuCat();
        cin >> numero;
        switch (numero) {
            case 1:
                agregarCat();
                break;
            case 2:
                modifNomCat();
                break;
            case 3:
                agregarArtCat();
                break;
            case 4:
                eliminarCat();
                break;
            case 5:
                desplegarCat();
                break;
            case 6:
                desplegarArtXCat();
                break;
            case 7:
                // Volver menu
                break;
            default:
                break;
        }
    }
}

void desplegarArtXCat() {

}

void desplegarCat() {

}

void eliminarCat() {

}

void agregarArtCat() {

}

void modifNomCat() {

}

void agregarCat() {

}

void opcionesRep() {
    int numero = -1;
    while (numero != 5) {
        menuReportes();
        cin >> numero;
        switch (numero) {
            case 1:
                precioInv();
                break;
            case 2:
                cantArtCero();
                break;
            case 3:
                artAgotado();
                break;
            case 4:
                artNAgotado();
                break;
            case 5:
                desplegarArt();
                break;
            case 6:
                desplegarCat();
                break;
            case 7:
                desplegarArtXCat();
                break;
            case 8:
                //Menu principal
                break;
            default:
                break;
        }
    }
}

void artNAgotado() {

}

void artAgotado() {

}

void cantArtCero() {

}

void precioInv() {

}
