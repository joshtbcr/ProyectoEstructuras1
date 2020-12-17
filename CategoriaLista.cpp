#include "CategoriaLista.h"
#include "iostream"
using namespace std;

CategoriaLista::CategoriaLista(){
    this->nodoS = NULL;
    this->largo = 0;
};
CategoriaLista::~CategoriaLista(){

};

NodoCategoria* CategoriaLista::getNodoS(){
    return this->nodoS;
};
void CategoriaLista::setNodoS(NodoCategoria* nodoS){

    this->nodoS = nodoS;
};

int CategoriaLista:: getLargo(){
    return this->largo;
};
void CategoriaLista:: setLargo(int largo){
    this->largo=largo;
};

bool CategoriaLista::esVacia(){
    bool esVacia = false;
    if(getLargo() == 0){
        esVacia = true;
    }
    return esVacia;
}

NodoCategoria* CategoriaLista::dirNodo(string descripcion){
    NodoCategoria* aux = this->getNodoS();
    for(int i = 1;i<=this->getLargo() && aux!=NULL;i++){
        if(aux->getCategoria()->getDescripcion()==descripcion){
            return aux;
        }
        else{
            aux = aux->getSgte();
        }
    }
    cout <<"No existe la categoria: "<< descripcion<<endl;
    return NULL;
}



void CategoriaLista::agregar(string descripcion){
    NodoCategoria* nuevo =  new NodoCategoria(new Categoria(descripcion));
    if(esVacia())
        this->setNodoS(nuevo);
    else{
        NodoCategoria* aux = this->getNodoS();
        while (aux->getSgte() != NULL) {
            aux = aux->getSgte();
        }
        aux->setSgte(nuevo);
    }
    largo++;
}

void CategoriaLista::modificarCat(string descripcion1, string descripcion2){
    this->dirNodo(descripcion1)->getCategoria()->setDescripcion(descripcion2);
}

 // Punto c
void CategoriaLista::agregarArticuloCategoria(NodoArticulo* nodoA, string descripcion){
    NodoCategoria* cat = this->dirNodo(descripcion);

    if(cat!=NULL){
        this->dirNodo(descripcion)->getCategoria()->getLista()->agregarArticulo(nodoA);
        //Mensaje
        cout<< "Articulo '"<< nodoA->getArticulo()->getNombre()<<"' agregado exitosamente a la categoria "<<descripcion<<endl;
    }
}

void CategoriaLista::eliminar(string descripcion){
    NodoCategoria* aux = this->getNodoS();
    NodoCategoria* ant;
    for(int i = 1;i<=this->largo && aux!=NULL;i++){
        if(aux->getCategoria()->getDescripcion()==descripcion){
            aux==this->getNodoS() ? setNodoS(aux->getSgte()) : ant->setSgte(aux->getSgte());
            delete aux;
            largo--;
        }
        else{
            ant = aux;
            aux = aux->getSgte();
        }
    }
}

void CategoriaLista::desplegarCategorias(){
    NodoCategoria* aux = this->getNodoS();
    while(aux != NULL){
        cout<< aux->getCategoria()->getDescripcion() << endl;
        aux = aux ->getSgte();
    }
};

void CategoriaLista::desplegarArticulos(string descripcion){
    NodoCategoria* cat = this->dirNodo(descripcion);
    if(cat!=NULL){
        this->dirNodo(descripcion)->getCategoria()->getLista()->desplegar();
    }
};
