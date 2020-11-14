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


void color(int x);
void gotoxy(int X,int Y);
int whereX();
int whereY();
void hidecursor(int ver);
void cuadro(int x1, int y1, int x2, int y2);
stCliente cargaUnCliente();
void guardaUnCliente(stCliente c);
void mostrarUnCliente(stCliente c);
void muestraArchClientes();
int verificarDniCliente (int dniCliente);
int validaEmail(char email[]);
int buscaUltimoId();
void bajaCliente(int idCliente);
int buscaPosicion(int id);
void modificarCliente(int id);
int modificarDatoCliente();
stCliente subMenu(stCliente cliente);
void consultarCliente(int id);
void guardaUnConsumo(stConsumos c);
int verificarDiasMes(int mes, int anio);
void cargarConsumos(int id);
void consultarClienteParaCargarConsumo(int id);
void muestraArchConsumos();
void mostrarUnConsumo(stConsumos c);
void bajaConsumos(int id);
void modificarConsumo(int id);
int modificarDatoConsumo(stConsumos c);
stConsumos subMenuConsumo(stConsumos consumo);
int generarRandomCliente();
int generarRandomMes();
int generarRandomDia(int mes, int anio);
void cargarMilConsumos(stConsumos c[]);
int generarRandomConsumo();
void pasarConsumoArchivo(stConsumos c[]);
int buscarConsumo (int mes, int idCliente);
///////////////////////////////////////////////
///////////////////////////////////////////////
int menuABB();
nodoArbol* agregarCliente(nodoArbol* ADL, stCliente dato);
nodoArbol* buscarCliente(nodoArbol* ADL, char apellido[]);
nodoArbol* altaCliente(nodoArbol* ADL, nodoLista* nuevoConsumo, char apellido[]);
nodoArbol* archivo2ADL(char archivo[], nodoArbol* ADL, nodoLista* nuevoConsumo);


int main()
{
    system("color B0");
    srand (time(NULL));
    stConsumos consumosAleatorios[1000];
    //cargarMilConsumos(consumosAleatorios);
    pasarConsumoArchivo(consumosAleatorios);
    nodoArbol* ADL = inicArbol();

    int selected;
    int seleccion;
    int eleccion;
    do
    {
        system("cls");
        printf("\n      Que Menu desea trabajar: \n");
        printf("\n       |1| -> Clientes\n");
        printf("\n       |2| -> Consumos\n");
        printf("\n       |3| -> ABB\n");
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
                seleccion = menuABB();
                switch(seleccion)
                {
                case 1:
                    funcion11();
                    break;
                case 2:
                    funcion12();
                    break;
                case 3:
                    funcion13();
                    break;
                case 4:
                    funcion14();
                    break;
                case 5:
                    funcion15();
                    break;
                case 6:
                    funcion16();
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

int menuABB()
{
    int input;
    system("cls");
    printf("\n      LABORATORIO 2");
    printf("\n      -------------------------------");
    printf("\n      MENU ARBOL DE BUSQUEDA BINARIO");
    printf("\n      -------------------------------");
    printf("\n      1-Pasar del archivo al ADL");
    printf("\n      2-Mostrar el ADL");
    printf("\n      3-3RA FUNCION");
    printf("\n      4-4TA FUNCION");
    printf("\n      5-5TA FUNCION");
    printf("\n      6-6TA FUNCION\n");
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

void funcion11 (nodoArbol* ADL)
{
    system("cls");
    printf("HELLO GUORD\n");
    ADL = archivo2ADL(arCliente,ADL,100);
    system("pause");
}
void funcion12 (nodoArbol* ADL)
{
    system("cls");
    printf("Recorrer y Mostar InOrder\n");
    inOrder(ADL);
    system("pause");
}
void funcion13 ()
{

}
void funcion14 ()
{

}
void funcion15 ()
{

}
void funcion16 ()
{

}




/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*********************************************************//**
*
* \brief Agrega un Cliente al Arbol de Listas
* \param El ADL.
* \param stCliente dato - un cliente
* \return Retorna ADL
*
***********************************************************/
nodoArbol* agregarCliente(nodoArbol* ADL, stCliente dato)
{

    strcpy(ADL->dato.nombre, dato.nombre);
    strcpy(ADL->dato.apellido, dato.apellido);
    strcpy(ADL->dato.domicilio, dato.domicilio);
    strcpy(ADL->dato.email, dato.email);
    strcpy(ADL->dato.movil, dato.movil);
    ADL->dato.dni = dato.dni;
    ADL->dato.baja = dato.baja;
    ADL->dato.id = dato.id;
    ADL->dato.nroCliente = dato.nroCliente;

    ADL->consumos = inicLista();

    return ADL;
}


/*********************************************************//**
*
* \brief Busca un cliente en el ADL
* \param El ADL.
* \param El apellido del Cliente a buscar
* \return Retorna el cliente buscado y si no lo encuentra, retorna NULL
*
***********************************************************/
nodoArbol* buscarCliente(nodoArbol* ADL, char apellido[])
{
    nodoArbol* buscado = NULL;

    if (ADL != NULL)
    {
        if (strcmpi(ADL->dato.apellido, apellido) == 0)
        {
            buscado = ADL;
        }
        else
        {
            buscado = buscarCliente(ADL->izq, apellido);
            if (buscado == NULL)
            {
                buscado = buscarCliente(ADL->der, apellido);
            }
        }
    }

    return buscado;
}

/*********************************************************//**
*
* \brief Le da el alta a un Cliente en el ADL
* \param El ADL.
* \param Un Consumo para agregar al ADL
* \param El apellido del cliente
* \return Retorna ADL
*
***********************************************************/
nodoArbol* altaCliente(nodoArbol* ADL, nodoLista* nuevoConsumo, char apellido[])
{
    nodoArbol* clienteEncontrado = buscarCliente(ADL, apellido);

    if(clienteEncontrado == NULL)
    {
        stCliente c = cargaUnCliente();
        nodoArbol* nuevo = crearNodoArbol(c);
        nuevo = agregarCliente(ADL, c);
        ADL = insertarNodoArbol(ADL, nuevo);
        ADL->consumos = agregarFinal(ADL->consumos, nuevoConsumo);
    }
    else
    {
        clienteEncontrado->consumos = agregarFinal(clienteEncontrado->consumos, nuevoConsumo);
    }

    return ADL;
}


/*********************************************************//**
*
* \brief Pasa los datos del archivo al ADL
* \param El archivo de datos.
* \param El ADL.
* \param Nuevo Consumo.
* \return Retorna el ADL.
*
***********************************************************/
nodoArbol* archivo2ADL(char archivo[], nodoArbol* ADL, nodoLista* nuevoConsumo)
{
    stCliente c;
    stConsumos d;
    char apellido[30];
    int idEspecie;

    FILE* arch = fopen(archivo, "rb");

    if(arch)
    {
        while((ADL!=NULL) && (fread(&c, sizeof(stCliente), 1, arch) > 0))
        {

            strcpy(apellido, c.apellido);
            ADL = altaCliente(ADL, nuevoConsumo, apellido);

        }
        fclose(arch);
    }


    return ADL;
}




















