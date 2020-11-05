#include "lista.h"
#include <stdio.h>

/*********************************************************//**
/*
/* \brief  Inicializa el puntero al primer nodo de la lista con el valor NULL
/* \return Retorna NULL
/*
/************************************************************/
nodoLista* inicLista()
{
    return NULL;
}

/*********************************************************//**
/*
/* \brief  Crea un nuevo nodo para agregar a la lista
/* \param  Recibe el dato para agregar
/* \return Retorna el puntero al nodo creado
/*
/************************************************************/
nodoLista* crearNodo(stConsumos dato)
{
    nodoLista* aux = (nodoLista*) malloc(sizeof(nodoLista));
    aux->datoConsumo = dato;
    aux->siguiente = NULL;
    return aux;
}

/*********************************************************//**
/*
/* \brief  Agrega un nuevo nodo ya creado al inicio de la lista
/* \param  Una variable puntero al comienzo de la lista
/* \param  Una variable puntero a un nuevo nodo
/* \return Agrega este nuevo nodo al comienzo de la lista y retorna la nueva posición de memoria
/*
/************************************************************/
nodoLista* agregarPpio(nodoLista* lista, nodoLista* nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else

    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

/*********************************************************//**
/*
/* \brief  Busca el último nodo de la lista. Solamente se invocará si la lista no está vacía
/* \param  Una variable puntero al comienzo de la lista
/* \return Retorna seg cuando ésta apunte a NULL
/*
/************************************************************/
nodoLista* buscarUltimo(nodoLista* lista)
{
    nodoLista* seg = lista;
    if(seg!=NULL)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

/*********************************************************//**
/*
/* \brief  Busca un nodo según el valor de un campo, en este caso, por apellido
/* \param  Una variable puntero al comienzo de la lista
/* \param  Una variable tipo char con el apellido a buscar
/* \return Retorna la dirección de memoria de un nodo que contiene dato.apellido con el mismo valor que el parámetro apellido
/*
/************************************************************/
nodoLista* buscarNodo(char apellido[20], nodoLista* lista)
{
    nodoLista* seg;
    seg = lista;
    while((seg!=NULL) && (strcmp(apellido, seg->datoCliente.apellido)))
    {
        seg = seg->siguiente;
    }
    return seg;
}

/*********************************************************//**
/*
/* \brief  Agrega un nuevo nodo ya creado al final de la lista
/* \param  Una variable puntero al comienzo de la lista
/* \param  Una variable puntero a un nuevo nodo
/* \return Agrega este nuevo nodo al final de la lista y retorna la nueva posición de memoria. Si la lista está vacía, le agrega el primer nodo
/*
/************************************************************/
nodoLista* agregarFinal(nodoLista* lista, nodoLista* nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoLista* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

/*********************************************************//**
/*
/* \brief  Busca un nodo según el valor de un campo, en este caso, por apellido y lo borra.
/* \param  Una variable puntero al comienzo de la lista.
/* \param  Una variable tipo char con el apellido a buscar y borrar.
/* \return Retorna un puntero al comienzo de la lista.
/*
/************************************************************/
nodoLista* borrarNodo(nodoLista* lista, char apellido[20])
{
    nodoLista* seg;
    nodoLista* ante;
    if((lista!=NULL) && (strcmp(apellido, lista->datoCliente.apellido) == 0))
    {
        nodoLista* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        while((seg!=NULL) && (strcmp(apellido, seg->datoCliente.apellido) != 0))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg!=NULL)
        {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}


/*********************************************************//**
/*
/* \brief  Agrega un nuevo nodo manteniendo el orden.
/* \param  Una variable puntero al comienzo de la lista.
/* \param  Una variable puntero a un nuevo nodo
/* \return Retorna un puntero al primer nodo de la lista que se modifica cuando solamente cuando el nuevo nodo se inserta en la primera posición.
/*
/************************************************************/
nodoLista* agregarEnOrden(nodoLista* lista, nodoLista* nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(strcmp(nuevoNodo->datoCliente.apellido, lista->datoCliente.apellido) < 0)
        {
            lista = agregarPpio(lista, nuevoNodo);
        }
        else
        {
            nodoLista* ante = lista;
            nodoLista* seg = lista->siguiente;
            while((seg!=NULL) && (strcmp(nuevoNodo->datoCliente.apellido, seg->datoCliente.apellido)) > 0)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;
}

/*********************************************************//**
/*
/* \brief  Borra la lista entera y libera todas las direcciones de memoria ocupadas por sus nodos.
/* \param  Una variable puntero al comienzo de la lista.
/* \return Retorna NULL.
/*
/************************************************************/
nodoLista* borrarTodaLaLista(nodoLista* lista)
{
    nodoLista* proximo;
    nodoLista* seg;
    seg = lista;
    while(seg!=NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

/*********************************************************//**
/*
/* \brief  Suma el contenido de cada nodo (datos consumidos).
/* \param  Una variable puntero al comienzo de la lista.
/* \return Retorna la suma.
/*
/************************************************************/
int sumarConsumosLista(nodoLista* lista)
{
    int suma = 0;
    nodoLista* seg = lista;
    while(seg!=NULL)
    {
        suma = suma + seg->datoConsumo.datosConsumidos;
        seg = seg->siguiente;
    }
    return suma;
}

/*********************************************************//**
/*
/* \brief  Eliminia el primer nodo de una lista
/* \param  Una variable puntero al comienzo de la lista.
/* \return Retorna la lista.
/*
/************************************************************/
nodoLista* eliminaPrimerNodo(nodoLista* lista)
{
    nodoLista* aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

/*********************************************************//**
/*
/* \brief  Eliminia el ultimo nodo de una lista
/* \param  Una variable puntero al comienzo de la lista.
/* \return Retorna la lista.
/*
/************************************************************/
nodoLista* eliminarUltimoNodo(nodoLista* lista)
{
    nodoLista* aux = lista;
    nodoLista* ante;
    while(aux->siguiente)
    {
        ante = aux;
        aux = aux->siguiente;
    }
    free(aux);
    ante->siguiente = NULL;
    return lista;
}

/*********************************************************//**
/*
/* \brief  Muestra los datos de un cliente, modularizando con la función de mostrarUnCliente
/* \param  Una variable puntero aMostrar.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void mostrarUnNodoCliente(nodoLista* aMostar)
{
    printf("\n Datos Cliente: \n");
    mostrarUnCliente(aMostar->datoCliente);
}

/*********************************************************//**
/*
/* \brief  Muestra la lista Cliente. Utiliza la función mostrarUnNodoCliente modularizada.
/* \param  Una variable puntero al comienzo de la lista.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void mostrarListaCliente(nodoLista* lista) // recorrer y mostrar //
{
    nodoLista* seg = lista;
    while(seg)
    {
        mostrarUnNodoCliente(seg);
        seg = seg->siguiente;
    }
}

/*********************************************************//**
/*
/* \brief  Muestra los datos de un Consumo, modularizando con la función de mostrarUnConsumo
/* \param  Una variable puntero aMostrar.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void mostrarUnNodoConsumo(nodoLista* aMostar)
{
    printf("\n Datos Consumo: \n");
    mostrarUnConsumo(aMostar->datoConsumo);
}

/*********************************************************//**
/*
/* \brief  Muestra la lista Consumo. Utiliza la función mostrarUnNodoConsumo modularizada.
/* \param  Una variable puntero al comienzo de la lista.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
void mostrarListaConsumo(nodoLista* lista) // recorrer y mostrar //
{
    nodoLista* seg = lista;
    while(seg)
    {
        mostrarUnNodoConsumo(seg);
        seg = seg->siguiente;
    }
}
