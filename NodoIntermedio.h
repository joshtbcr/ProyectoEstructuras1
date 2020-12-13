#pragma once
#include <stdlib.h>
#include <iostream>
#include "NodoArticulo.h"
using namespace std;
#ifndef NODOINTERMEDIO_H
#define NODOINTERMEDIO_H

class NodoIntermedio
{
	private:
        NodoIntermedio* sgte;
		NodoArticulo* link;
	public:
		NodoIntermedio();
		NodoIntermedio(int codigo);
		NodoIntermedio(NodoArticulo* nodoArticulo);
		~NodoIntermedio();
	
        NodoIntermedio* getSgte();
        void setSgte(NodoIntermedio* nodoIntermedio);

        NodoArticulo* getNodoArticulo();
        void setNodoArticulo(NodoArticulo* nodoArticulo);
};
#endif