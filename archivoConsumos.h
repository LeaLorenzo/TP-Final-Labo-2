#ifndef ARCHIVOCONSUMOS_H_INCLUDED
#define ARCHIVOCONSUMOS_H_INCLUDED
#define arConsumos "consumos.dat"
#include "archivoClientes.h"

typedef struct
{
    int id;  /// campo �nico y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a � dependiendo del mes
    int datosConsumidos;  /// expresados en mb.
    int baja; /// 0 si est� activo - 1 si est� eliminado
} stConsumos;



void guardaUnConsumo(stConsumos c);
int buscarConsumo (int mes, int idCliente);
void pasarConsumoArchivo(stConsumos c[]);
int buscaUltimoIdConsumos();
void cargarConsumos(int id);
int verificarDiasMes(int mes, int anio);
void muestraArchConsumos();
void mostrarUnConsumo(stConsumos c);
void bajaConsumos(int id);
void modificarConsumo(int id); /// MODIFICACION ///
int modificarDatoConsumo(stConsumos c);
stConsumos subMenuConsumo(stConsumos consumo);
int generarRandomConsumo();

#endif // ARCHIVOCONSUMOS_H_INCLUDED
