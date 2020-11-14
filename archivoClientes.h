#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#define arCliente "cliente.dat"
#include "archivoConsumos.h"

typedef struct
{
    int  id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[35];
    char domicilio[45];
    char movil[11];
    int baja; /// 0 si está activo - 1 si está eliminado
} stCliente;


stCliente cargaUnCliente();
void guardaUnCliente(stCliente c);
void muestraArchClientes();
void mostrarUnCliente(stCliente c);
int verificarDniCliente (int dniCliente); /// VALIDACION DEL INGRESO DE LOS DATOS ///
int validaEmail(char email[]);
int buscaUltimoId();
void bajaCliente(int idCliente);
int buscaPosicion(int id);
void modificarCliente(int id); /// MODIFICACION ///
int modificarDatoCliente();
stCliente subMenu(stCliente cliente);
void consultarCliente(int id);
int generarRandomCliente();
///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////
void agregarRegistro(stCliente c);
void getNombre(char n[]);
void getApellido(char a[]);
void getDNI(int dni);
void getEmail(char email[], char nombre[], char apellido[]);
void getDomicilio(char c[]);
void getTelefono(char tel[]);
void getNumeroDeCliente(int nroCliente);
int getTipo();
stCliente cargoRegistroArchivoRandom();
void guardaRegistroArchivo(char archivo[], stCliente c);
void generaArchivoRandom(int cantidad);
int cuentaRegistros(char archivo[], stCliente c[]);
void espera();
int buscaDNI(int dni);

#endif // ARCHIVOCLIENTES_H_INCLUDED
