#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "archivoConsumos.h"
#include "archivoClientes.h"

typedef struct _nodoLista
{
    stConsumos datoConsumo;
    stCliente datoCliente;
    struct _nodoLista* siguiente;
}nodoLista;

nodoLista* inicLista();
nodoLista* crearNodo(stConsumos dato);
nodoLista* agregarPpio(nodoLista* lista, nodoLista* nuevoNodo);
nodoLista* buscarUltimo(nodoLista* lista);
nodoLista* buscarNodo(char apellido[], nodoLista* lista);
nodoLista* agregarFinal(nodoLista* lista, nodoLista* nuevoNodo);
nodoLista* borrarNodo(nodoLista* lista, char apellido[20]);
nodoLista* agregarEnOrden(nodoLista* lista, nodoLista* nuevoNodo);
nodoLista* borrarTodaLaLista(nodoLista* lista);
int sumarConsumosLista(nodoLista* lista);
nodoLista* eliminaPrimerNodo(nodoLista* lista);
nodoLista* eliminarUltimoNodo(nodoLista* lista);
void mostrarUnNodoCliente(nodoLista* aMostar);
void mostrarListaCliente(nodoLista* lista);
void mostrarUnNodoConsumo(nodoLista* aMostar);
void mostrarListaConsumo(nodoLista* lista);


#endif // LISTA_H_INCLUDED
