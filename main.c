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



int main()
{
    system("color B0");
    srand (time(NULL));
    stConsumos consumosAleatorios[1000];
    cargarMilConsumos(consumosAleatorios);
    pasarConsumoArchivo(consumosAleatorios);

    int selected;
    int seleccion;
    int eleccion;
    do
    {
        system("cls");
        printf("\n      Que Menu desea trabajar: \n");
        printf("\n       |1| -> Clientes\n");
        printf("\n       |2| -> Consumos\n");
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

