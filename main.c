#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pila.h"
#include <windows.h>

#define arCliente "cliente.dat"
#define arConsumos "consumos.dat"
const char ESC = 27;

typedef struct
{
    int  id; /// campo único y autoincremental probando github
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[35];
    char domicilio[45];
    char movil[11];
    int baja; /// 0 si está activo - 1 si está eliminado
} stCliente;

typedef struct
{
    int id;  /// campo único y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos;  /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumos;

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

stCliente cargaUnCliente()
{
    stCliente c;
    char opcion = 0;
    c.id = buscaUltimoId();
    c.id++;
    int DNIexiste = 0;
    do
    {
        printf("\n       Ingrese el DNI.....................: ");
        fflush(stdin);
        scanf("%d", &c.dni);
        DNIexiste = verificarDniCliente(c.dni);
        //printf("%d", DNIexiste);//se prueba para ver que funcione la funcion de validación
    }
    while(DNIexiste == 1);
    do
    {
        printf("\n       Ingrese el nro de Cliente..........: ");
        fflush(stdin);
        scanf("%d",&c.nroCliente);
    }
    while((c.nroCliente<0 || c.nroCliente>9999999));
    printf("\n       Ingrese el Nombre..................: ");
    fflush(stdin);
    gets(c.nombre);
    printf("\n       Ingrese el Apellido................: ");
    fflush(stdin);
    gets(c.apellido);


    do
    {
        printf("\n       Ingrese el e-mail...................: ");
        fflush(stdin);
        gets(c.email);
    }
    while(!validaEmail(c.email));
    printf("\n       Ingrese el Numero de celular...........: ");
    fflush(stdin);
    gets(c.movil);
    printf("\n       Ingrese el Domicilio...................: ");
    fflush(stdin);
    gets(c.domicilio);
    c.baja = 0;
    guardaUnCliente(c);
    return c;

}



void guardaUnCliente(stCliente c)
{
    FILE *pArchClientes = fopen(arCliente, "ab");
    if(pArchClientes != NULL)
    {
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void guardaUnConsumo(stConsumos c)
{
    FILE *pArchConsumos = fopen(arConsumos, "ab");
    if(pArchConsumos != NULL)
    {
        fwrite(&c,sizeof(stConsumos),1,pArchConsumos);
        fclose(pArchConsumos);
    }
}


int buscarConsumo (int mes, int idCliente)
{
    stConsumos consumo;
    int consumoDelMes;
    FILE *pArchConsumos = fopen(arConsumos,"rb");
    while(pArchConsumos)
    {
        fread(&consumo,sizeof(stConsumos),1,pArchConsumos);
        while(consumo.idCliente == idCliente)
        {
            if(consumo.mes == mes)
            {
                consumoDelMes += consumo.datosConsumidos;
            }
        }


        fclose(pArchConsumos);
        return consumoDelMes;
    }
}


void pasarConsumoArchivo(stConsumos c[])
{
    int i = 0;
    for(i; i<1000; i++)
    {
        guardaUnConsumo(c[i]);
    }
}

void muestraArchClientes()
{
    stCliente c;
    FILE *pArchClientes = fopen(arCliente,"rb");

    if(pArchClientes)
    {
        while(fread(&c,sizeof(stCliente),1,pArchClientes) > 0)
        {
            mostrarUnCliente(c);
        }
    }
    printf("\n");
}

void mostrarUnCliente(stCliente c)
{
    if(c.baja == 0)
    {
        printf("\n  ________________________________________________");
        printf("\n  Id.........................: %d\n",c.id);
        printf("\n  Nro de Cliente.............: %d\n",c.nroCliente);
        printf("\n  Nombre usuario.............: %s\n",c.nombre);
        printf("\n  Apellido usuario...........: %s\n",c.apellido);
        printf("\n  Dni........................: %d\n",c.dni);
        printf("\n  Domicilio..................: %s\n",c.domicilio);
        printf("\n  Movil......................: %s\n",c.movil);
        printf("\n  Email......................: %s\n",c.email);
        printf("\n  _______________________________________________");
    }

}



int verificarDniCliente (int dniCliente) /// VALIDACION DEL INGRESO DE LOS DATOS ///
{
    int flag = 0;
    stCliente c;
    FILE *pArchCliente = fopen(arCliente,"rb");
    if (pArchCliente)
    {
        while ((flag == 0) && fread(&c,sizeof(stCliente),1,pArchCliente)>0)
        {
            if (c.dni == dniCliente)
            {
                flag = 1;
            }
        }
        fclose(pArchCliente);
    }
    return flag;
}

int validaEmail(char email[])
{
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0)
    {
        if(email[i]==64)  /// =='@'
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

int buscaUltimoId()
{
    stCliente c;
    int id = -1;
    FILE *pArchCliente = fopen(arCliente, "rb");
    if(pArchCliente)
    {
        fseek(pArchCliente, sizeof(stCliente)*(-1), SEEK_END);
        if(fread(&c, sizeof(stCliente), 1, pArchCliente)>0)
        {
            id = c.id;
        }
        fclose(pArchCliente);
    }
    return id;
}

int buscaUltimoIdConsumos()
{
    stConsumos c;
    int id = -1;
    FILE *pArchConsumos = fopen(arConsumos, "rb");
    if(pArchConsumos)
    {
        fseek(pArchConsumos, sizeof(stConsumos)*(-1), SEEK_END);
        if(fread(&c, sizeof(stConsumos), 1, pArchConsumos)>0)
        {
            id = c.id;
        }
        fclose(pArchConsumos);
    }
    return id;
}


void bajaCliente(int idCliente)
{

    stCliente c;
    char eleccion;
    FILE *pArchCliente=fopen(arCliente,"r+b");
    if(pArchCliente!=NULL)
    {
        fseek(pArchCliente,sizeof(stCliente)*idCliente,SEEK_SET);
        fread(&c,sizeof(stCliente),1,pArchCliente);
        mostrarUnCliente(c);
        printf("\n ESTA SEGURO QUE DESEA ELIMINAR EL ESTADO DE ESTE USUARIO ? S/N");
        eleccion=getch();
        if(eleccion==115)
        {
            if(c.baja == 0)
            {
                c.baja = 1;
            }
            else
            {
                c.baja=0;
            }
        }
        fseek(pArchCliente,sizeof(stCliente)*idCliente,SEEK_SET);
        fwrite(&c,sizeof(stCliente),1,pArchCliente);
        fclose(pArchCliente);
    }
}

int buscaPosicion(int id)
{
    int pos = -1;
    int bandera = 0;
    stCliente c;
    FILE *pArchClientes = fopen(arCliente,"rb");
    if(pArchClientes)
    {
        while((bandera==0)&&(fread(&c,sizeof(stCliente),1,pArchClientes)>0))
        {

            if(c.id == id)
            {
                /// si los id son iguales entoces cambio el valor de la bandera
                /// para que no siga recorriendo el archivo sin necesidad
                bandera = 1;
                pos = ftell (pArchClientes) / sizeof(stCliente)-1;
            }
        }
        fclose(pArchClientes);
    }
    return pos;
}

void modificarCliente(int id) /// MODIFICACION ///
{
    stCliente c;
    char eleccion;
    FILE *pArchCliente = fopen(arCliente,"r+b");
    if (pArchCliente != NULL)
    {
        fseek(pArchCliente,sizeof(stCliente)*id,SEEK_SET);
        fread(&c,sizeof(stCliente),1,pArchCliente);

        mostrarUnCliente(c);
        printf("\n ESTA SEGURO QUE DESEA MODIFICAR EL ESTADO DE ESTE USUARIO ? S/N");
        eleccion=getch();
        if(eleccion==115)
        {
            c = subMenu(c);
        }

        fseek(pArchCliente,sizeof(stCliente)*id,SEEK_SET);
        fwrite(&c,sizeof(stCliente),1,pArchCliente);// carga un cliente nuevamente desde
        fclose(pArchCliente);
    }
}

int modificarDatoCliente()
{
    int seleccion;
    system("cls");
    printf("______");
    printf("\nQue dato desea modificar: \n");
    printf("\n1- Nro de Cliente");
    printf("\n2- Nombre usuario");
    printf("\n3- Apellido usuario");
    printf("\n4- Dni");
    printf("\n5- Domicilio");
    printf("\n6- Movil");
    printf("\n7- Email");
    printf("\n0 para Salir");
    printf("\nElija un dato que desea modificar: \n");
    scanf("%d", &seleccion);
    printf("______");
    return seleccion;
}

stCliente subMenu(stCliente cliente)
{
    int seleccion;
    stCliente c = cliente;
    do
    {
        seleccion = modificarDatoCliente();
        switch(seleccion)
        {
        case 1:
            printf("\nIngrese Nuevo Numero de Cliente: \n");
            int NuevoNumeroCliente;
            scanf("%d", &NuevoNumeroCliente);
            c.nroCliente = NuevoNumeroCliente;
            break;
        case 2:
            printf("\nIngrese Nuevo Nombre: \n");
            char NuevoNombreCliente[30];
            fflush(stdin);
            scanf("%s", &NuevoNombreCliente);
            strcpy(c.nombre, NuevoNombreCliente);
            break;
        case 3:
            printf("\nIngrese Nuevo Apellido: \n");
            char NuevoApellidoCliente[30];
            fflush(stdin);
            scanf("%s", &NuevoApellidoCliente);
            strcpy(c.apellido, NuevoApellidoCliente);
            break;
        case 4:
            printf("\nIngrese Nuevo Numero DNI: \n");
            int NuevoNumeroDNI;
            fflush(stdin);
            scanf("%d", &NuevoNumeroDNI);
            c.dni = NuevoNumeroDNI;
            break;
        case 5:
            printf("\nIngrese Nuevo Domicilio: \n");
            char NuevoDomicilioCliente[45];
            fflush(stdin);
            scanf("%s", &NuevoDomicilioCliente);
            strcpy(c.domicilio, NuevoDomicilioCliente);
            break;
        case 6:
            printf("\nIngrese Nuevo Numero de Movil: \n");
            char NuevoMovilCliente[11];
            fflush(stdin);
            gets(NuevoMovilCliente);
            strcpy(c.movil, NuevoMovilCliente);
            break;
        case 7:
            printf("\nIngrese Nuevo direccion de Email: \n");
            char NuevoEmailCliente;
            fflush(stdin);
            scanf("%s", &NuevoEmailCliente);
            strcpy(c.email, NuevoEmailCliente);
            break;
        }

    }
    while(seleccion!=0);

    system("pause");
    return c;
}

void consultarCliente(int id)
{
    stCliente c;
    char eleccion;
    FILE *pArchCliente = fopen(arCliente,"r+b");
    if (pArchCliente != NULL)
    {
        fseek(pArchCliente,sizeof(stCliente)*id,SEEK_SET);
        fread(&c,sizeof(stCliente),1,pArchCliente);
        mostrarUnCliente(c);
        fclose(pArchCliente);
    }
}

void consultarClienteParaCargarConsumo(int id)
{
    stCliente c;
    char eleccion;

    printf("\nDesea cargar un consumo? S/N\n");
    eleccion=getch();
    if(eleccion==115)
    {
        cargarConsumos(id);
    }

}



void cargarConsumos(int id)
{
    stConsumos c;
    char opcion = 0;
    int maximoDias = 0;
    c.id = buscaUltimoIdConsumos();
    c.id++;
    c.idCliente = id;

    printf("\n Ingrese el Anio..................: ");
    fflush(stdin);
    scanf(" %d", &c.anio);
    do
    {
        printf("\n Ingrese el Mes (1 a 12)................: ");
        fflush(stdin);
        scanf("%d",&c.mes);
    }
    while((c.mes<1 || c.mes>12));
    maximoDias = verificarDiasMes(c.mes,c.anio);
    do
    {
        printf("\n Ingrese el Dia.....................: ");
        scanf(" %d", &c.dia);
    }
    while(c.dia < 1 || c.dia > maximoDias);

    printf("\n Ingrese datos consumidos...................: ");
    fflush(stdin);
    scanf("%d",&c.datosConsumidos);/// HACER QUE LOS DATOS CONSUMIDOS SEAN AUTOINCREMENTALES ///
    c.baja = 0;
    guardaUnConsumo(c);
    return c;
}

int verificarDiasMes(int mes, int anio)
{
    int dias;
    switch(mes)
    {
    case  1 :
        dias = 31;
        break;
    case  3 :
        dias = 31;
        break;
    case  5 :
        dias = 31;
        break;
    case  7 :
        dias = 31;
        break;
    case  8 :
        dias = 31;
        break;
    case 10 :
        dias = 31;
        break;
    case 12 :
        dias = 31;
        break;
    case  4 :
        dias = 30;
        break;
    case  6 :
        dias = 30;
        break;
    case  9 :
        dias = 30;
        break;
    case 11 :
        dias = 30;
        break;
    case 2:
        if(anio %4 == 0 && anio %100 != 0)
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }
    return dias;
}

void muestraArchConsumos()
{
    stConsumos c;
    FILE *pArchConsumos = fopen(arConsumos,"rb");

    if(pArchConsumos)
    {
        while(fread(&c,sizeof(stConsumos),1,pArchConsumos) > 0)
        {
            mostrarUnConsumo(c);
        }
    }
    printf("\n");
}

void mostrarUnConsumo(stConsumos c)
{
    if(c.baja == 0)
    {
        printf("\nId ........................: %d \n",c.id);
        printf("\nId cliente.................: %d \n",c.idCliente);
        printf("\nAnio.......................: %d \n",c.anio);
        printf("\nMes........................: %d \n",c.mes);
        printf("\nDia........................: %d \n",c.dia);
        printf("\nConsumo....................: %d MB\n",c.datosConsumidos);
        printf("______________");
    }
}

void bajaConsumos(int id)
{

    stConsumos c;
    char eleccion;
    FILE *pArchConsumos=fopen(arConsumos,"r+b");
    if(pArchConsumos!=NULL)
    {
        while (fread(&c,sizeof(stConsumos),1,pArchConsumos)>0)
        {
            if(c.idCliente == id)
            {
                mostrarUnConsumo(c);
                printf("\n ESTA SEGURO QUE DESEA ELIMINAR EL CONSUMO DE ESTE USUARIO ? S/N");
                eleccion=getch();
                if(eleccion==115)
                {
                    if(c.baja == 0)
                    {
                        c.baja = 1;
                    }
                    else
                    {
                        c.baja=0;
                    }
                }
            }
        }
        fseek(pArchConsumos,sizeof(stConsumos)*c.id,SEEK_SET);
        fwrite(&c,sizeof(stConsumos),1,pArchConsumos);
        fclose(pArchConsumos);
    }
}

void modificarConsumo(int id) /// MODIFICACION ///
{
    stConsumos c;
    char eleccion;
    FILE *pArchConsumos = fopen(arConsumos,"r+b");
    if (pArchConsumos != NULL)
    {
        fseek(pArchConsumos,sizeof(stConsumos)*id,SEEK_SET);
        fread(&c,sizeof(stConsumos),1,pArchConsumos);

        mostrarUnConsumo(c);
        printf("\n ESTA SEGURO QUE DESEA MODIFICAR EL ESTADO DE ESTE CONSUMO ? S/N");
        eleccion=getch();
        if(eleccion==115)
        {
            c = subMenuConsumo(c);
        }

        fseek(pArchConsumos,sizeof(stConsumos)*id,SEEK_SET);
        fwrite(&c,sizeof(stConsumos),1,pArchConsumos);
        fclose(pArchConsumos);
    }
}

int modificarDatoConsumo(stConsumos c)
{
    int seleccion;
    system("cls");
    printf("______");
    printf("\nQue dato desea modificar: \n");
    printf("\n1- ID Cliente");
    printf("\n2- Anio");
    printf("\n3- Mes");
    printf("\n4- Dia");
    printf("\n5- Consumo");
    printf("\n0 para Salir");
    printf("\nElija un dato que desea modificar: \n");
    scanf("%d", &seleccion);
    printf("______");
    mostrarUnConsumo(c);
    return seleccion;
}

stConsumos subMenuConsumo(stConsumos consumo)
{
    int seleccion;
    stConsumos c = consumo;
    do
    {
        seleccion = modificarDatoConsumo(c);
        switch(seleccion)
        {
        case 1:
            printf("\nIngrese Nuevo Id de Cliente: \n");
            int NuevoIdCliente;
            scanf("%d", &NuevoIdCliente);
            c.idCliente = NuevoIdCliente;
            break;
        case 2:
            printf("\nIngrese Nuevo Anio: \n");
            int nuevoAnioConsumo;
            fflush(stdin);
            scanf("%d", &nuevoAnioConsumo);
            c.anio = nuevoAnioConsumo;
            break;
        case 3:
            printf("\nIngrese Nuevo Mes de consumo: \n");
            int nuevoMesConsumo;
            fflush(stdin);
            scanf("%d", &nuevoMesConsumo);
            c.mes = nuevoMesConsumo;
            break;
        case 4:
            printf("\nIngrese Nuevo dia de consumo: \n");
            int nuevoDiaConsumo;
            fflush(stdin);
            scanf("%d", &nuevoDiaConsumo);
            c.dia = nuevoDiaConsumo;
            break;
        case 5:
            printf("\nIngrese Nuevo Consumo: \n");
            int nuevoConsumo;
            fflush(stdin);
            scanf("%d", &nuevoConsumo);
            c.datosConsumidos = nuevoConsumo;
            break;
        }

    }
    while(seleccion!=0);

    system("pause");
    return c;
}

int generarRandomConsumo()
{
    int numero = rand()%500;
    return numero;
}

int generarRandomCliente()
{

    int numero = buscaUltimoId();
    int numeroCreado = numero++;
    return numeroCreado;
}
int generarRandomMes()
{

    int mes = 0;
    mes = rand()%(12-1+1)+1;

    return mes;
}
int generarRandomDia(int mes, int anio)
{

    int maximo = verificarDiasMes(mes,anio);
    int dia = rand()% (maximo-1+1)+1;

    return dia;
}
void cargarMilConsumos(stConsumos c[])
{

    int i = 0;
    for(i; i<1000; i++)
    {
        c[i].idCliente = generarRandomCliente();

        c[i].anio = 2020;

        c[i].mes = generarRandomMes();

        c[i].dia = generarRandomDia(c[i].mes,c[i].anio);

        c[i].datosConsumidos = generarRandomConsumo();

        c[i].id = i;

        mostrarUnConsumo(c[i]);


    }
}



/*char fechaActual()
{

    time_t tiempo = time(0);// asigna el tiempo de la maquina a cero
    struct tm *tlocal = localtime(&tiempo);//
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);//output es el str donde lo guarda, 128 la cant de cacarcteres que tiene output en el arreglo, mes dia y anio, tlocal
    printf("%s\n",output);

    return ;
}

char diaActual()
{
    time_t tiempo = time(0);

    struct tm *tlocal = localtime(&tiempo);

    char output;

    strftime(output,1,"%m",tlocal);
    printf("%c", output);

    return output;
}

void fGetNow(char date[])
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(date,128,"%Y-%m-%d %H:%M",tlocal);
}*/

