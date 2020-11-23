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



nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stCliente dato);
nodoArbol* insertarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo);
void mostrarNodoArbol(nodoArbol* nodo);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);
nodoArbol* buscarNMI(nodoArbol* arbol);
nodoArbol* buscarNMD(nodoArbol* arbol);
nodoArbol* borrarNodoArbol(nodoArbol* arbol, int idCliente);
int esHoja(nodoArbol* arbol);

#endif // ARBOL_H_INCLUDED
