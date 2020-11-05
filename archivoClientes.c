#include "archivoClientes.h"
#include <stdio.h>



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

int generarRandomCliente()
{

    int numero = buscaUltimoId();
    int numeroCreado = numero++;
    return numeroCreado;
}
