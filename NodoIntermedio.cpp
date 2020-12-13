#include "NodoIntermedio.h"
using namespace std;

NodoIntermedio::NodoIntermedio(){
	this->sgte = NULL;
	this->link = NULL;

}
NodoIntermedio::NodoIntermedio(int codigo){
	this->sgte = NULL;
	
}
NodoIntermedio::NodoIntermedio(NodoArticulo* nodoArticulo){
	this->sgte = NULL;
	this->link = nodoArticulo;
}
NodoIntermedio::~NodoIntermedio(){

}
NodoIntermedio* NodoIntermedio::getSgte(){
	if(this->sgte == NULL){
		return NULL;
	}else{
		return this->sgte;
	}
}
void NodoIntermedio::setSgte(NodoIntermedio* sgte){
	this->sgte=sgte;
}

NodoArticulo* NodoIntermedio::getNodoArticulo(){
	return this->link;
}
void NodoIntermedio::setNodoArticulo(NodoArticulo* nodoArticulo){
	this->link = nodoArticulo;
}