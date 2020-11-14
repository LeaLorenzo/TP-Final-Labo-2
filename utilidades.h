#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include "archivoConsumos.h"
#include "archivoClientes.h"

void consultarClienteParaCargarConsumo(int id);
int generarRandomMes();
int generarRandomDia(int mes, int anio);
void cargarMilConsumos(stConsumos c[]);
int randomRango(int min, int max);
void replicante(char c, int n);

#endif // UTILIDADES_H_INCLUDED
