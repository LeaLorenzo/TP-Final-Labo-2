#include "utilidades.h"

/*********************************************************//**
/*
/* \brief  Consulta Cliente para cargar consumo.
/* \param  Una variable del tipo entero id.
/* \return No retorna nada, es de tipo void.
/*
/************************************************************/
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

/*********************************************************//**
/*
/* \brief  Genera el mes random.
/* \return Retorna el mes.
/*
/************************************************************/
int generarRandomMes()
{

    int mes = 0;
    mes = rand()%(12-1+1)+1;

    return mes;
}

/*********************************************************//**
/*
/* \brief  Genera el dia random.
/* \return Retorna el dia.
/*
/************************************************************/
int generarRandomDia(int mes, int anio)
{

    int maximo = verificarDiasMes(mes,anio);
    int dia = rand()% (maximo-1+1)+1;

    return dia;
}

/*********************************************************//**
/*
/* \brief  Carga mil consumos random.
/* \param  Una variable del tipo struct consumos.
/* \return No retorna nada, es del tipo void.
/*
/************************************************************/
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

/*********************************************************//**
/*
/* \brief  Carga el rango random.
/* \param  Una variable del tipo entero minimo.
/* \param  Una variable del tipo entero maximo.
/* \return Retorna el rango.
/*
/************************************************************/
int randomRango(int min, int max)
{
    return rand()%(max-min)+min;
}

/*********************************************************//**
/*
/* \brief  Replicante.
/* \param  Una variable del tipo char c.
/* \param  Una variable del tipo entero n.
/* \return No retorna nada, es del tipo void.
/*
/************************************************************/
void replicante(char c, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%c",c);
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

