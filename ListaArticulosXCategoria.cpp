#include "ListaArticulosXCategoria.h"
#include "iostream"
using namespace std;

ListaArticulosXCategoria::ListaArticulosXCategoria(){
    this->nodoI = NULL;
    this->largo = 0;
};
ListaArticulosXCategoria::~ListaArticulosXCategoria(){
};
ListaArticulosXCategoria::ListaArticulosXCategoria(NodoIntermedio* nodoI){
    this->nodoI = nodoI;
    this->largo = 0;
};

bool ListaArticulosXCategoria::esVacia(){
    bool esVacia = false;
    if(getLargo() == 0){
        esVacia = true;
    }
    return esVacia;
}


int ListaArticulosXCategoria::getLargo(){
    return this->largo;
}
void ListaArticulosXCategoria::setLargo(int largo){
    this->largo = largo;
}

NodoIntermedio* ListaArticulosXCategoria::getNodoI(){
    return this->nodoI;
}
void ListaArticulosXCategoria::setNodoI(NodoIntermedio* nodoI){
    this->nodoI = nodoI;
}

void ListaArticulosXCategoria::agregarArticulo(NodoArticulo* nodoA){
    NodoIntermedio* nuevoNodoI = new NodoIntermedio(nodoA);
    if(esVacia())
        this->setNodoI(nuevoNodoI);
    else{
        NodoIntermedio* aux = this->getNodoI();
        while (aux->getSgte() != NULL) {
            aux = aux->getSgte();
        }
        aux->setSgte(nuevoNodoI);
    }
    largo++;
}

void ListaArticulosXCategoria::desplegar(){
    NodoIntermedio* aux = this->getNodoI();
    while(aux != NULL){
        aux->getNodoArticulo()->getArticulo()->toString();
        aux = aux ->getSgte();
    }
}