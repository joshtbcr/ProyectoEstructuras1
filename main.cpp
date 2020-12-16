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

int volver();

Articulo *nodoArt;
Categoria *nodoCat;
ListaArticulos *listaArticulos = new ListaArticulos();
CategoriaLista * categoriaLista = new CategoriaLista();

int incrementalArt = 1;
int incrementalCat = 1;

int main() {
    opciones();
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
    while (numero != 7) {
        menuArticulo();
        cin >> numero;
        switch (numero) {
            case 1:
                agregarArt();
                numero = volver();
                break;
            case 2:
                modifArt();
                numero = volver();
                break;
            case 3:
                modifExis();
                numero = volver();
                break;
            case 4:
                eliminarArt();
                numero = volver();
                break;
            case 5:
                desplegarArt();
                numero = volver();
                break;
            case 6:
                actPrecios();
                numero = volver();
                break;
            case 7:
                //Salida de este menu
                break;
            default:
                break;
        }
    }
}

int volver() {
    int opcion = 0;
    cout << "Presione 0 para volver al menu o 7 para salir" << endl;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

void actPrecios() {

    if (!listaArticulos->esVacia()) {
        int porcentaje = 0;
        cout << "Por favor indique el nuevo porcentaje"<<endl;
        cin >> porcentaje;
        listaArticulos->cambiarPrecios(porcentaje);
    } else {
        cout << "La lista esta vacia, por favor registre un articulo" << endl;
    }

}

void desplegarArt() {
    if (!listaArticulos ->esVacia()) {
        cout << "Articulos en inventarios" << endl;
        cout << "\n" << endl;
        listaArticulos ->desplegar();
    } else {
        cout << "La lista esta vacia, por favor registre un articulo" << endl;
    }

}

void eliminarArt() {

    if (!listaArticulos ->esVacia()) {
        int codigo = 0;
        listaArticulos ->desplegar();
        cout << "Por favor digite el codigo del articulo a eliminar" << endl;
        cin >> codigo;
        listaArticulos ->eliminar(codigo);
    } else {
        cout << "La lista está vacia, por favor, registre articulos primero" << endl;
    }

}

void modifExis() {

    if (!listaArticulos ->esVacia()) {
        int codigo;
        int cantidad;
        cout << "Por favor digite el codigo del producto" <<endl;
        cout << "\n" << endl;
        listaArticulos ->desplegar();
        cin >> codigo;
        NodoArticulo *aux = listaArticulos ->dirNodo(codigo);
        cout << "Digite la nueva cantidad del articulo"<<endl;
        cin >> cantidad;
        aux ->getArticulo()->setCantidad(cantidad);
    } else {
        cout << "La lista está vacia, por favor, registre articulos primero" << endl;
    }

}

void modifArt() {

    string nombre;
    int codigo;
    string descripcion;
    float precio;
    string estatus;
    int cantidad;
    int opcion = 0;

    if (!listaArticulos ->esVacia()){
        cout << "Por favor digite el codigo del producto" <<endl;
        cout << "\n" << endl;
        listaArticulos ->desplegar();
        cin >> codigo;
        NodoArticulo *aux = listaArticulos ->dirNodo(codigo);
        cout << "Que desea modificar, por favor, seleccione la opcion con el atributo correspondiente" <<endl;
        cout << "\n" <<endl;
        cout << "1. nombre" <<endl;
        cout << "2. descripcion" <<endl;
        cout << "3. precio" <<endl;
        cout << "4. estatus" <<endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Digite el nuevo nombre del articulo"<<endl;
                cin >> nombre;
                aux ->getArticulo()->setNombre(nombre);
                break;
            case 2:
                cout << "Digite la nueva descripcion del articulo"<<endl;
                cin >> descripcion;
                aux ->getArticulo()->setDescripcion(descripcion);
                break;
            case 3:
                cout << "Digite el nuevo precio del articulo"<<endl;
                cin >> precio;
                aux ->getArticulo()->setPrecio(precio);
                break;
            case 4:
                cout << "Digite el nuevo estatus del articulo"<<endl;
                cin >> estatus;
                aux ->getArticulo()->setEstatus(estatus);
                break;
            default:
                cout << "Entrada no valida"<<endl;
                break;
        }
    } else{
        cout << "No existen articulos, porfavor, registre uno primero"<<endl;
    }
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
        listaArticulos ->agregarInicio(nodoArt);
    } else {
        nodoArt = new Articulo(nombre,codigo,descripcion,precio,estatus,cantidad);
        listaArticulos ->agregarFinal(nodoArt);
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
    if (!categoriaLista->esVacia()) {
        cout << "Categorias" << endl;
        cout << "\n" << endl;
        categoriaLista->desplegarCategorias();
    } else {
        cout << "La lista esta vacia, por favor registre una categoria" << endl;
    }
}

void eliminarCat() {
    if (!categoriaLista ->esVacia()) {
        string txt = "";
        categoriaLista ->desplegarCategorias();
        cout << "Por favor digite la descripcion de la categoria a eliminar" << endl;
        cin >> txt;
        categoriaLista ->eliminar(txt);
    } else {
        cout << "La lista está vacia, por favor, registre articulos primero" << endl;
    }
}

void agregarArtCat() {

}

void modifNomCat() {

    string descripcion;

    if (!categoriaLista->esVacia()){
        cout << "Por favor digite la descripcion de la categoria" <<endl;
        cout << "\n" << endl;
        categoriaLista ->desplegarCategorias();
        cin >> descripcion;
        NodoCategoria *aux = categoriaLista->dirNodo(descripcion);
        cout << "Por favor digite la nueva descripcion de la categoria" <<endl;
        cin >> descripcion;
        cout << "Digite la nueva descripcion del articulo"<<endl;
        cin >> descripcion;
        aux->getCategoria()->setDescripcion(descripcion);
    }else {
        cout << "La lista esta vacia, por favor agregue primero categorias" << endl;
    }

}

void agregarCat() {

    string descripcion;

    cout << "Porfavor escriba la descripcion de la categoria" << endl;
    cin >> descripcion;

    if (categoriaLista->esVacia()){
        nodoCat = new Categoria(descripcion);
        categoriaLista->agregar(descripcion);
    } else {
        nodoCat = new Categoria(descripcion);
        categoriaLista->agregar(descripcion);
    }

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
    cout << "Los articulos no agotados son los siguientes" << endl;
    cout << "\n" << endl;
    listaArticulos->listaNoAgotados();
}

void artAgotado() {
    cout << "Los articulos agotados son los siguientes" << endl;
    cout << "\n" << endl;
    listaArticulos->listaAgotados();
}

void cantArtCero() {
    listaArticulos->cantidadEnCero();
}

void precioInv() {
    listaArticulos->precioInventario();
}
