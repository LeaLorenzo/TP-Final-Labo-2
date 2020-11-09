#include "arbol.h"
#include <stdio.h>

/*********************************************************//**
/*
/* \brief  Inicializa el puntero al primer nodoArbol con el valor NULL
/* \return Retorna NULL
/*
/************************************************************/
nodoArbol* inicArbol()
{
    return NULL;
}

/*********************************************************//**
/*
/* \brief  Crea un nuevo nodoArbol para agregar a la lista
/* \param  Recibe el dato para agregar
/* \return Retorna el puntero al nodoArbol creado
/*
/************************************************************/
nodoArbol* crearNodoArbol(stCliente dato)
{
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

/*********************************************************//**
/*
/* \brief    Inserta un dato en un arbol.
/* \param    El arbol nodoArbol* puntero a arbol.
/* \param    El nodo nuevo nodoArbol* nuevo.
/* \return   Retorna el arbol.
/*
/*********************************************************/
nodoArbol* insertarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->dato.dni > arbol->dato.dni)
        {
            arbol->der = insertarNodoArbol(arbol->der, nuevo);
        }
        else
        {
            arbol->izq =insertarNodoArbol(arbol->izq, nuevo);
        }
    }
    return arbol;
}

/*********************************************************//**
/*
/* \brief  Muestra el nodoArbol.
/* \param  Una variable puntero al comienzo de la lista.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void mostrarNodoArbol(nodoArbol* nodo)
{
    printf(" %d -", nodo->dato);
}

/*********************************************************//**
/*
/* \brief  Visita la raíz, atraviesa el sub arbol izq, luego atraviesa el sub arbol der.
/* \param  Una variable puntero al comienzo de la lista.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void preOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        mostrarNodoArbol(arbol);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

/*********************************************************//**
/*
/* \brief  Atraviesa el sub arbol izq, visita la raíz, luego atraviesa el sub arbol der.
/* \param  Una variable puntero al comienzo de la lista.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void inOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        inOrder(arbol->izq);
        mostrarNodoArbol(arbol);
        inOrder(arbol->der);
    }
}

/*********************************************************//**
/*
/* \brief  Atraviesa el sub arbol izq, atraviesa el sub arbol der, luego visita la raíz.
/* \param  Una variable puntero al comienzo de la lista.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void postOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        mostrarNodoArbol(arbol);
    }
}

/*********************************************************//**
/*
/* \brief  Busca el nodoArbol mas izquierdo.
/* \param  Una variable puntero al comienzo de la lista.
/* \return Retorna la variable aux con el nodo mas izquierdo.
/*
/************************************************************/
nodoArbol* buscarNMI(nodoArbol* arbol)
{
    nodoArbol* aux = arbol;
    while((aux) && (aux->izq!=NULL))
    {
        aux = aux->izq;
    }
    return aux;
}

/*********************************************************//**
/*
/* \brief  Busca el nodoArbol mas derecho.
/* \param  Una variable puntero al comienzo de la lista.
/* \return Retorna la variable aux con el nodo mas derecho.
/*
/************************************************************/
nodoArbol* buscarNMD(nodoArbol* arbol)
{
    nodoArbol* aux = arbol;
    while((aux) && (aux->der!=NULL))
    {
        aux = aux->der;
    }
    return aux;
}


/*********************************************************//**
/*
/* \brief    Borra un nodo de un árbol binario.
/* \param    El arbol nodoArbol* puntero a arbol.
/* \param    El dato a borrar.
/* \return   Retorna el nodoArbol con el dato buscado.
/*
/*********************************************************/
nodoArbol* borrarNodoArbol(nodoArbol* arbol, int dato) // por dni
{
    if(arbol != NULL)
    {
        if(dato == arbol->dato.dni)
        {
            if(arbol->izq != NULL)
            {
                nodoArbol* masDer = buscarNMD(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = borrarNodoArbol(arbol->izq, masDer->dato.dni);
            }
            else
            {
                if(arbol->der != NULL)
                {
                    nodoArbol* masIzq = buscarNMI(arbol->der);
                    arbol->dato = masIzq->dato;
                    arbol->der = borrarNodoArbol(arbol->der, masIzq->dato.dni);
                }
                else
                {
                    free(arbol);
                    arbol = NULL;
                }
            }

        }
        if(dato > arbol->dato.dni)
        {
            arbol->der = borrarNodoArbol(arbol->der, dato);
        }
        if(dato < arbol->dato.dni)
        {
            arbol->izq = borrarNodoArbol(arbol->izq, dato);
        }
    }
    return arbol;
}
