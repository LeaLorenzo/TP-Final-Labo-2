#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED
#define nombreArchivo "registro.dat"

typedef struct
{
    int idCliente;
    int anioConsumo;
    int mesConsumo; /// 1 a 12
    int diaConsumo; /// 1 a … dependiendo del mes
    int datosConsumidos;  /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
    int  id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[35];
    char domicilio[45];
    char movil[11];
    //int baja; /// 0 si está activo - 1 si está eliminado
} stRegistro;

#endif // REGISTRO_H_INCLUDED
