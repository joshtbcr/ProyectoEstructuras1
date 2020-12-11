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

//Indice inicia en 1
void CategoriaLista::modificarCat(int indice, string descripcion){
    NodoCategoria* aux = this->getNodoS();
    for(int i = 1;i<=indice && aux!=NULL;i++){
        if(i==indice)
            aux->getCategoria()->setDescripcion(descripcion);
        else
            aux = aux->getSgte();
    }
}

//Indice inicia en 1
void CategoriaLista::eliminar(int indice){
    NodoCategoria* aux = this->getNodoS();
    NodoCategoria* ant;
    for(int i = 1;i<=indice && aux!=NULL;i++){
        if(i==indice){
            indice==1 ? setNodoS(aux->getSgte()) : ant->setSgte(aux->getSgte());
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

void CategoriaLista::desplegarArticulos(int indice){
    NodoCategoria* aux = this->getNodoS();
    while(aux != NULL){
        cout<< aux->getCategoria()->getDescripcion() << endl;
        aux = aux ->getSgte();
    }
};