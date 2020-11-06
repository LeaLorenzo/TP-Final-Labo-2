#include "arbol.h"
#include <stdio.h>
nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(stCliente dato)
{
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}


