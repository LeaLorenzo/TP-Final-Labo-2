#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "archivoClientes.h"
#include "lista.h"

typedef struct _nodoArbol
{
    stCliente dato;
    nodoLista* consumos;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;


#endif // ARBOL_H_INCLUDED
