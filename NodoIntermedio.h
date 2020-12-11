#pragma once
#include <stdlib.h>
#include "iostream"
using namespace std;
#ifndef NODOINTERMEDIO_H
#define NODOINTERMEDIO_H

class NodoIntermedio
{
	private:
        NodoIntermedio* sgte;
	public:
		NodoIntermedio();
		~NodoIntermedio();

};
#endif