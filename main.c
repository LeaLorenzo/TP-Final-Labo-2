#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pila.h"
#include <windows.h>
#include "archivoClientes.h"
#include "archivoConsumos.h"
#include "lista.h"
#include "utilidades.h"
#include "arbol.h"

const char ESC = 27;


///////////////////////////////////////////////
///////////////////////////////////////////////
/////////////////PROTOTIPADO///////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
int menuADL();
int sumarConsumoPeriodo(nodoArbol* arbol, int mes, int anio);
void muestraTicket(stConsumos c, int parcialDatos);
void muestraTicketTotal(stConsumos c, int totalDatos);
nodoArbol* buscarCliente(nodoArbol* ADL, int id);
nodoArbol* alta(nodoArbol *adl, stCliente datoCliente, stConsumos datoConsumos);
nodoArbol* insertarConsumo(nodoArbol* arbol, nodoLista* nuevo);
nodoArbol *archiToADL (nodoArbol *adl);
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

int main()
{
    system("color B0");
    srand (time(NULL));
    ///stConsumos consumosAleatorios[1000]; // NO UTILIZAR EN TP LABO2
    ///cargarMilConsumos(consumosAleatorios); // NO UTILIZAR EN TP LABO2
    ///pasarConsumoArchivo(consumosAleatorios); // NO UTILIZAR EN TP LABO2
    nodoArbol* ADL = inicArbol();
    nodoLista* lista = inicLista();

    int selected;
    int seleccion;
    int eleccion;
    do
    {
        system("cls");
        printf("\n      Que Menu desea trabajar: \n");
        printf("\n       |1| -> Clientes\n");
        printf("\n       |2| -> Consumos\n");
        printf("\n       |3| -> Arbol de Listas\n");
        printf("\n       |0| -> Salir\n");
        scanf("%d", &eleccion); /// AGREGAMOS UN DATO A "ELECCION" ///

        if(eleccion == 1)
        {
            do
            {
                selected = menuClientes();
                switch(selected)
                {
                case 1:
                    funcion1();
                    break;
                case 2:
                    funcion2();
                    break;
                case 3:
                    funcion3();
                    break;
                case 4:
                    funcion4();
                    break;
                case 5:
                    funcion5();
                    break;
                case 6:
                    printf("\nIngrese id de cliente al que desea cargar consumos:\n");
                    int id;
                    scanf("%d",&id);
                    funcion6(id);
                    break;
                case 7:
                    funcion7();
                    break;
                case 8:
                    funcion8();
                    break;
                }

            }
            while(selected!=0);
        }
        else if(eleccion == 2)
        {
            do
            {
                seleccion = menuConsumos();
                switch(seleccion)
                {
                case 1:
                    funcion6();
                    break;
                case 2:
                    funcion7();
                    break;
                case 3:
                    funcion8();
                    break;
                case 4:
                    funcion9();
                    break;
                case 5:
                    funcion5();
                    break;
                case 6:
                    funcion10();
                    break;
                default:
                    printf("\nOpcion invalida\n");
                    break;

                }
            }
            while(seleccion!=0);
        }
        else if(eleccion == 3)
        {
            do
            {
                seleccion = menuADL();
                switch(seleccion)
                {
                case 1:
                    funcion11(ADL);// Pasa del archivo de clientes y consumos al ADL //
                    break;
                case 2:
                    funcion12();// Mostrar ADL por recorrido in Order //
                    break;
                case 3:
                    funcion13(); // Factuar Periodo Consumo del Cliente //
                    break;
                case 4:
                    funcion14(); // Factuar totalidad del Cliente //
                    break;
                case 5:
                    funcion15(); // Mostrar historico de Consumos del Cliente //
                    break;
                case 6:
                    funcion16(); // borrar un cliente por id //
                    break;
                default:
                    printf("\nOpcion invalida\n");
                    break;

                }
            }
            while(seleccion!=0);
        }
    }
    while(eleccion != 0);
    printf("\nGracias por elegir nuestros servicios\n");
    system("\npause\n");
    return 0;
}

//char diaActual();


int menuClientes()
{
    int input;
    system("cls");
    printf("\n      LABORATORIO 1");
    printf("\n      -------------");
    printf("\n      MENU CLIENTES");
    printf("\n      -------------");
    printf("\n      1-Cargar Cliente Nuevo");
    printf("\n      2-Mostrar Clientes");
    printf("\n      3-Baja Clientes");
    printf("\n      4-Modificar Clientes");
    printf("\n      5-Consulta Clientes");
    printf("\n      6-Genera Clientes Random");
    printf("\n      0-Para volver al MENU PRINCIPAL\n");
    printf("\n      Ingrese el numero que desea realizar: ");
    scanf("%d",&input);
    return input;
}

int menuConsumos()
{
    int input;
    system("cls");
    printf("\n      LABORATORIO 1");
    printf("\n      -------------");
    printf("\n      MENU CONSUMO");
    printf("\n      -------------");
    printf("\n      1-Cargar Consumos");
    printf("\n      2-Mostrar Consumos de Clientes");
    printf("\n      3-Baja Consumos de Clientes");
    printf("\n      4-Modificar Consumos de Clientes");
    printf("\n      5-Mostrar Consumo Mensual\n");
    printf("\n      0-Para volver al MENU PRINCIPAL\n");
    printf("\n      Ingrese el numero que desea realizar: ");
    scanf("%d",&input);
    return input;
}

int menuADL()
{
    int input;
    system("cls");
    printf("\n      LABORATORIO 2");
    printf("\n      -------------------------------");
    printf("\n      MENU ARBOL DE LISTAS");
    printf("\n      -------------------------------");
    printf("\n      1-Pasar del archivo Clientes y de Consumos al ADL");// pasa del archivo de clientes y consumos al ADL
    printf("\n      2-Mostrar el ADL en recorrido in Order");
    printf("\n      3-Facturar parcialidad de Consumo por Cliente");
    printf("\n      4-Facturar totalidad de Consumo del Cliente");
    printf("\n      5-Consultar consumo historico del Cliente");
    printf("\n      6-Borrar un Cliente del Arbol\n");
    printf("\n      0-Para volver al MENU PRINCIPAL\n");
    printf("\n      Ingrese el numero que desea realizar: ");
    scanf("%d",&input);
    return input;
    system("pause");
}

void funcion1()
{
    system("cls");
    printf("\n      Cargar Clientes:\n");
    cargaUnCliente();
    system("PAUSE");
    system("cls");
}

void funcion2()
{
    system("cls");
    printf("\n      Mostrar listado de clientes:\n");
    muestraArchClientes();
    system("PAUSE");
    system("cls");
}
void funcion3 ()
{
    int ultimoid=buscaUltimoId();
    int idCliente = -1;
    printf("\n      INGRESE EL  ID DEL USUARIO QUE DESEA ELIMINAR: ");
    scanf(" %d",&idCliente);
    if(idCliente<=ultimoid)
    {
        bajaCliente(idCliente);
    }
    else
    {
        printf("\n      El usuario que desea eliminar no existe");
    }
}

void funcion4 ()
{
    stCliente c;
    int ultimoid = buscaUltimoId();
    int idCliente = -1;
    printf("\n      Ingrese el id del cliente a modificar:\n");
    scanf("%d",&idCliente);
    if(idCliente <= ultimoid)
    {
        modificarCliente(idCliente);
    }
    else
    {
        printf("\n      El usuario que desea modificar no existe\n");
        system("pause");
    }
}

void funcion5()
{
    stCliente c;
    int ultimoid = buscaUltimoId();
    int idCliente = -1;
    printf("\n      Ingrese el id del cliente que desea consultar:\n");
    scanf("%d",&idCliente);
    if(idCliente <= ultimoid)
    {
        consultarCliente(idCliente);
        printf("\n");
        system("pause");
    }
    else
    {
        printf("\n      El usuario que desea consultar no existe\n");
        system("pause");
    }
}

void funcion6 ()
{
    int id;
    system("cls");
    printf("\n      Cargar Consumos Cliente:\n");
    printf("Ingrese el id del cliente a cargar: ");
    scanf("%d",&id);
    consultarClienteParaCargarConsumo(id);
    system("PAUSE");
}

void funcion7()
{
    system("cls");
    printf("\n      Mostrar consumo de clientes:\n");
    muestraArchConsumos();
    system("PAUSE");
}

void funcion8 ()
{
    int ultimoid = buscaUltimoId();
    int idCliente = -1;
    printf("\n      INGRESE EL  ID DEL CONSUMO QUE DESEA ELIMINAR: ");
    scanf("%d",&idCliente);
    if(idCliente <= ultimoid)
    {
        bajaConsumos(idCliente);
    }
    else
    {
        printf("\n      El usuario que desea eliminar no existe");
    }
}

void funcion9 ()
{
    stConsumos c;
    int ultimoid = buscaUltimoIdConsumos();
    int idConsumo = -1;
    printf("\n      Ingrese el id del consumo a modificar:\n");
    scanf("%d",&idConsumo);
    if(idConsumo <= ultimoid)
    {
        modificarConsumo(idConsumo);
    }
    else
    {
        printf("\n      El consumo que desea modificar no existe\n");
        system("pause");
    }
}

void funcion10 ()
{
    int idBuscar;
    int mesBuscar, total;
    printf("\nIngrese el id Cliente que desea ver los consumos: \n");
    scanf("%d", &idBuscar);
    printf("\nIngrese el mes\n");
    scanf("%d", &mesBuscar);
    system("pause");
    total = buscarConsumo(mesBuscar, idBuscar);
    printf("\El consumo de el mes es de %d", total);

}

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
void funcion11 (nodoArbol* ADL)
{
    system("cls");
    printf("Por favor, espere un momento, estamos pasando los consumos y clientes de los archivos al ADL: \n");
    ADL = archiToADL(ADL);
    system("pause");

}
void funcion12 (nodoArbol* ADL)
{
    system("cls");
    printf("Muestra Arbol de Clientes con recorrido inOrder: \n");
    inOrder(ADL);
    //preOrder(ADL);
    //postOrder(ADL);
    system("pause");
}
void funcion13 (nodoArbol* ADL) // Mostrar ticket parcial //
{
    system("cls");
    stConsumos c;
    nodoArbol* cliente;

    int parcialDatos = 0;
    printf("\n Ingrese el id de cliente que desea facturar: \n");
    fflush(stdin);
    scanf("%d", &c.id);
    printf("\n Ingrese el mes, del 1 al 12, que desea facturar: \n");
    fflush(stdin);
    scanf("%d", &c.mes);
    printf("\n Ingrese el anio que desea facturar: \n");
    fflush(stdin);
    scanf("%d", &c.anio);
    system("pause");
    system("cls");

    cliente = buscarCliente(ADL, c.id);

    parcialDatos = sumarConsumoPeriodo(cliente, c.mes, c.anio );

    printf("Resultado de la funcion sumarConsumoPeriodo: %d Megas\n\n", parcialDatos);
    system("pause");
    system("cls");

    printf("Impresion de ticket parcial: \n");
    muestraTicket(c, parcialDatos);
    system("pause");
    system("cls");

}
void funcion14 (nodoArbol* ADL) // Mostrar Ticket Total //
{
    system("cls");
    stConsumos c;
    nodoArbol* cliente;
    int totalDatos = 0;

    printf("\n Ingrese el id de cliente que desea facturar: \n");
    fflush(stdin);
    scanf("%d", &c.id);

    system("pause");
    system("cls");

    cliente = buscarCliente(ADL, c.id);

    totalDatos = sumarConsumosLista(cliente->consumos);

    printf("Resultado de la funcion sumarConsumoLista: %d Megas\n\n", totalDatos);

    system("pause");
    system("cls");

    printf("Impresion de ticket total: \n");
    muestraTicketTotal(c, totalDatos);
    system("pause");


}
void funcion15 (nodoArbol* ADL) // Mostrar historico de Consumos del Cliente //
{

    system("cls");
    stConsumos c;
    nodoArbol* cliente;

    printf("\n Ingrese el numero de id del cliente que desea visualizar el historial de consumos: \n");
    fflush(stdin);
    scanf("%d", &c.id);

    system("pause");
    system("cls");

    printf("Cliente encontrado: \n");
    cliente = buscarCliente(ADL, c.id);
    mostrarNodoArbol(cliente);
    system("pause");
    system("cls");

}
void funcion16 (nodoArbol* ADL) // borrar cliente del arbol
{
    system("cls");
    nodoArbol* borrar;
    stCliente c;
    printf("\n Por favor, ingrese el numero de id del cliente que desea borrar del arbol: ");
    fflush(stdin);
    scanf("%d", &c.id);
    borrar = borrarNodoArbol(ADL, c.id);
    system("pause");
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//////////////////////////FUNCIONES ADL//////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*********************************************************//**
/*
/* \brief  Suma los datos consumidos en el periodo seleccionado.
/* \param  El arbol nodoArbol* puntero a arbol.
/* \param  Una variable del tipo entero mes.
/* \param  Una variable del tipo entero anio.
/* \return Retorna el resultado de la suma.
/*
/************************************************************/
int sumarConsumoPeriodo(nodoArbol* arbol, int mes, int anio)
{
    int totalMes = 0;
    nodoLista* seg = arbol->consumos;

    while(seg)
    {
        if((seg->datoConsumo.anio == anio) && (seg->datoConsumo.mes == mes))
        {
            totalMes = totalMes + seg->datoConsumo.datosConsumidos;
        }
        seg = seg->siguiente;
    }
    return totalMes;
}

/*********************************************************//**
*
* \brief Muestra el ticket con la totalidad de los megas consumidos en el mes seleccionado.
* \param Un tipo de dato del tipo stConsumos.
* \param Una variable con el total de datos consumidos.
* \return Sin retorno, es del tipo void.
*
***********************************************************/
void muestraTicket(stConsumos c, int parcialDatos)
{
    puts("\n----------------------------------------");
    puts("<<<<<<<<<<<<<<Factura>>>>>>>>>>>>>>>>>>>");
    puts("----------------------------------------\n");
    printf("\n.....El id Cliente: %d\n", c.id);
    printf("\n...............Mes: %d\n", c.mes);
    printf("\n..............Anio: %d\n", c.anio);
    printf("\n..Datos consumidos: %d Megas\n\n", parcialDatos);
    puts("\n----------------------------------------");
    puts("<<<<<<<<<<<<<<<Personal>>>>>>>>>>>>>>>>>");
    puts("----------------------------------------\n");
}
/*********************************************************//**
*
* \brief Muestra el ticket con la totalidad de los megas consumidos hasta el momento.
* \param Un tipo de dato del tipo stConsumos.
* \param Una variable con el total de datos consumidos.
* \return Sin retorno, es del tipo void.
*
***********************************************************/
void muestraTicketTotal(stConsumos c, int totalDatos)
{
    puts("\n----------------------------------------");
    puts("<<<<<<<<<<<<<<Factura>>>>>>>>>>>>>>>>>>>");
    puts("----------------------------------------\n");
    printf("\n.....El id Cliente: %d\n", c.id);
    printf("\n..Datos consumidos: %d Megas\n\n", totalDatos);
    puts("\n----------------------------------------");
    puts("<<<<<<<<<<<<<<<Personal>>>>>>>>>>>>>>>>>");
    puts("----------------------------------------\n");
}
/*********************************************************//**
*
* \brief Busca un cliente en el ADL
* \param El ADL.
* \param El apellido del Cliente a buscar
* \return Retorna el cliente buscado y si no lo encuentra, retorna NULL
*
***********************************************************/
nodoArbol* buscarCliente(nodoArbol* ADL, int id)
{
    nodoArbol* buscado = NULL;

    if (ADL != NULL)
    {
        if (ADL->dato.id == id)
        {
            buscado = ADL;
        }
        else
        {
            buscado = buscarCliente(ADL->izq, id);
            if (buscado == NULL)
            {
                buscado = buscarCliente(ADL->der, id);
            }
        }
    }

    return buscado;
}

/*********************************************************//**
*
* \brief Le da el alta a un Cliente en el ADL
* \param El ADL.
* \param Recibe un cliente con sus datos
* \param Recibe un consumo
* \return Retorna ADL
*
***********************************************************/
nodoArbol* alta(nodoArbol *adl, stCliente datoCliente, stConsumos datoConsumos)
{
    nodoLista *nuevaLista = crearNodo(datoConsumos);
    nodoArbol *busqueda = buscarCliente(adl, datoCliente.id);
    //if(busqueda)
    //    mostrarNodoArbol(busqueda); // si descomento esta funcion, muestra los clientes mientras pasa al arbol
    if (busqueda == NULL)
    {
        nodoArbol *nuevo = crearNodoArbol(datoCliente);
        nuevo->consumos = agregarFinal(nuevo->consumos, nuevaLista);
        adl = insertarNodoArbol(adl, nuevo);
    }
    else
    {
        busqueda->consumos = agregarFinal(busqueda->consumos, nuevaLista);
    }

    return adl;
}

/*********************************************************//**
*
* \brief Inserta el dato consumido
* \param Una variable del tipo nodoArbol.
* \param Una variable del tipo nodoLista nuevo.
* \return Retorna el ADL.
*
***********************************************************/
nodoArbol* insertarConsumo(nodoArbol* arbol, nodoLista* nuevo)
{
    if(!arbol)
    {
        arbol->consumos = nuevo;
    }
    else
    {
        if(nuevo->datoConsumo.idCliente > arbol->dato.id)
        {
            arbol->der = insertarConsumo(arbol->der, agregarFinal(arbol, nuevo));
        }
        else
        {
            arbol->izq = insertarConsumo(arbol->izq, agregarFinal(arbol, nuevo));
        }
    }
    return arbol;
}

/*********************************************************//**
*
* \brief Pasa los datos del archivo de Consumos al ADL
* \param El ADL.
* \return Retorna el ADL.
*
***********************************************************/
nodoArbol *archiToADL (nodoArbol *adl)
{
    FILE *archiCon = fopen(arConsumos, "rb");

    stCliente cli;
    stConsumos con;

    if (archiCon != NULL)
    {
        while (fread(&con, sizeof(stConsumos), 1, archiCon) > 0)
        {
            cli = buscaClienteEnArchivo(con.idCliente);
            adl = alta(adl, cli, con);
        }

        fclose(archiCon);
    }

    return adl;
}











