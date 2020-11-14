#include "archivoClientes.h"
#include <stdio.h>

/*********************************************************//**
*
* \brief Carga un Cliente
* \return Retorna el Cliente
*
***********************************************************/
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


/*********************************************************//**
*
* \brief Guarda un Cliente en el archivo
* \param stCliente c - un cliente
* \return void
*
***********************************************************/
void guardaUnCliente(stCliente c)
{
    FILE *pArchClientes = fopen(arCliente, "ab");
    if(pArchClientes != NULL)
    {
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}


/*********************************************************//**
*
* \brief Muestra el archivo de Clientes
* \return void
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Muestra un cliente
* \param stCliente c - un cliente
* \return void
*
***********************************************************/
void mostrarUnCliente(stCliente c)
{
    if(c.baja == 0)
    {
        printf("\n  ________________________________________________");
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


/*********************************************************//**
*
* \brief Verifica DNI Cliente
* \param Variable del tipo int dni
* \return Retorna 1 si esta cargado, 0 si no lo esta
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Verifica email
* \param Variable del tipo char email
* \return Retorna 1 si esta cargado, 0 si no lo esta
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Busca Ultimo id Cargado
* \return Retorna id validos
*
***********************************************************/
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


/*********************************************************//**
*
* \brief Da de baja al cliente
* \param Variable del tipo int idCliente para poder dar de baja
* \return No retorna nada, es void
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Busca posicion
* \param Variable del tipo int id
* \return Retorna la posicion
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Modifica el estado del cliente
* \param Variable del tipo int id
* \return No retorna nada, es del tipo void
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Modifica datos del cliente
* \return Retorna la opcion del menu seleccionada
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Sub Menu del tipo cliente
* \param Variable del tipo struct Cliente
* \return Retorna el cliente
*
***********************************************************/
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

/*********************************************************//**
*
* \brief Consulta si esta un cliente
* \param Variable del tipo int id
* \return No retorna nada, es del tipo void
*
***********************************************************/
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


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

// Se guarda un dato en un archivo
void agregarRegistro(stCliente c)
{
    FILE* archi = fopen(arCliente, "ab");
    if(archi)
    {
        fwrite(&c, sizeof(stCliente),1,archi);
        fclose(archi);
    }
}

// Función que asigna en la variable recibida un nombre al azar
void getNombre(char n[])
{
    char nombres[][20] = {"Amalia","Juan","Roberta","Antonio","Juana","Fernando","Fernanda","Anibal","Antonia","Roberto",
                          "Anastasia","Anastasio","Artura","Arturo","Maria","Mario","Tamara","Adolfo","Adolfa","Pedro","Alfredo",
                          "Alfreda","Mauro","Maura","Benicio","Benicia","Ildefonso","Ildefonsa","Cuchuflito","Cuchuflita",
                          "Remilgo"
                         };
    strcpy(n, nombres[randomRango(0,sizeof(nombres)/(sizeof(char)*30))]);
}


// Función que asigna en la variable recibida un apellido al azar
void getApellido(char a[])
{
    char apellidos[][30] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"
                           };
    strcpy(a,apellidos[randomRango(0,sizeof(apellidos)/(sizeof(char)*30))]);
}

// Función que asigna en la variable recibida un DNI al azar
void getDNI(int dni) // controlar funcion
{
    dni = randomRango(549,1982)* randomRango(549,19801);
}


// Función que asigna en las variables recibidas un email al azar
void getEmail(char email[], char nombre[], char apellido[])
{
    char nombreAux[30];
    char apellidoAux[30];
    strcpy(nombreAux, nombre);
    strcpy(apellidoAux, apellido);
    email[0]='\0';
    nombreAux[0]=tolower(nombreAux[0]);
    apellidoAux[0]=tolower(apellidoAux[0]);
    strcat(email,nombreAux);
    strcat(email,"@");
    strcat(email,apellidoAux);
    strcat(email,".com");
}

// Función que asigna en la variable recibida un domicilio al azar
void getDomicilio(char c[])
{
    char calles[][30] = {"San Juan","Funes","Gaboto","San Martin","Colon","Rivadavia", "Alsina", "Roca", "Mitre", "Belgrano",
                         "Paso", "11 de Septiembre", "3 de Febrero", "Balcarce", "Libertad", "Magallanes", "Irala", "Ayolas", "Moreno", "Brown",
                         "Bolivar", "Alberti", "Gascon", "La Rioja", "Catamarca", "Salta", "Jujuy", "XX de Septiembre", "14 de Julio", "Dorrego",
                         "Hernandarias","Don Orione","Juramento","Lanzilota","Estrada","Tierra del Fuego","Mendoza","Chubut","Rio Negro","Misiones","Edison"
                        };
    strcpy(c,calles[randomRango(0,sizeof(calles)/(sizeof(char)*30))]);
    char nro[5];
    itoa(randomRango(50,10000),nro,10);
    strcat(c," ");
    strcat(c,nro);
}

// Función que asigna en la variable recibida un telefono al azar
void getTelefono(char tel[])
{
    int nroTel = randomRango(635,19712)* randomRango(678,19801);
    itoa(nroTel,tel,10);
}

void getNumeroDeCliente(int nroCliente) // controlar funcion //
{
    nroCliente = randomRango(1,1982)* randomRango(1,50000);
}

int getTipo()
{
    return randomRango(0,10);
}


// Función que genera un registro al azar y lo retorna
stCliente cargoRegistroArchivoRandom()
{
    stCliente c;
    getApellido(c.apellido);
    getNombre(c.nombre);
    getDNI(c.dni);
    getEmail(c.email, c.nombre, c.apellido);
    getDomicilio(c.domicilio);
    getTelefono(c.movil);
    c.id = getTipo();

    return c;
}


// Función que guarda un dato de tipo stCliente en el archivo especificado
void guardaRegistroArchivo(char archivo[], stCliente c)
{
    FILE* archi = fopen(archivo, "ab");
    if(archi)
    {
        fwrite(&c, sizeof(stCliente), 1, archi);
        fclose(archi);
    }
}


// Función que llama a las funciones anteriores y genera y guarda en el archivo la cantidad de registros deseados
void generaArchivoRandom(int cantidad)
{
    stCliente c;
    int i = 0;
    int ultimo = cuentaRegistros(arCliente, sizeof(stCliente))+1;
    printf("Generando archivo de Clientes Random.. ");
    while(i<cantidad)
    {
        //(i % 100 == 0) ? espera():0;
        if(i%100 == 0)
            espera();
        c = cargoRegistroArchivoRandom();
        c.id = ultimo + i;
        int existe = buscaDNI(c.dni);
        while(existe)
        {
            getDNI(c.dni);
            if(!buscaDNI(c.dni))
            {
                existe = 0;
            }
        }
        guardaRegistroArchivo(arCliente, c);
        i++;
    }
}
/*********************************************************//**
*
* \brief Retorna la cantidad de registros de un archivo
* \param string file - el nombre del archivo
* \param int dataSize - el tamaño de la estructura
* \return int v - la cantidad de registros
*
***********************************************************/
int cuentaRegistros(char archivo[], stCliente c[])
{
    int total = 0;
    FILE* archi = fopen(arCliente, "rb");
    if(archi)
    {
        fseek(archi,0,SEEK_END);
        total = ftell(archi)/sizeof(stCliente);
        fclose(archi);
    }
    return total;
}

void espera()
{
    gotoxy(whereX()-1,whereY());
    char c[]= {196,47,179,92};
    static int i=0;
    i=(i > 3)?0:i;
    printf("%c",c[i]);
    i++;
}


int buscaDNI(int dni) // controlar funcion
{
    int existe = 0;
    stCliente c;
    FILE* archi = fopen(arCliente,"rb");
    if(archi)
    {
        while(fread(&c,sizeof(stCliente),1,archi)>0 && existe==0)
        {
            if(c.dni == dni)
            {
                existe = 1;
            }
        }
        fclose(archi);
    }
    return existe;
}
