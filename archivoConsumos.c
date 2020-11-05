#include "archivoConsumos.h"
#include <stdio.h>


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
