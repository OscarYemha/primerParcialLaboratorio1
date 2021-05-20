/*
 * recaudacion.h
 *
 *  Created on: 18 may. 2021
 *      Author: oscar
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_

typedef struct
{
	int idTipoRecaudacion;
	char descripcion[21];
	int isEmpty;
}eTipoRecaudacion;

typedef struct
{
	int idRecaudacion;
	int mes;
	int tipo;
	float importe;
	int isEmpty;
	int estado;
	int idContribuyente;
}eRecaudacion;

void IniciarListaRecaudaciones(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones);
int BuscarLugarParaRecaudacion(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones);
void AltaRecaudacion(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones, int index, int *idRecaudacion, eTipoRecaudacion listaTipoRecaudaciones[], int cantidadTipoRecaudaciones);
int ImprimirTipoRecaudaciones(eTipoRecaudacion listaTipoRecaudaciones[], int cantidadTipoRecaudaciones);
void ImprimirUnTipoRecaudacion(eTipoRecaudacion listaTipoRecaudaciones);
//int ChequeaListaVacia(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones);
int ImprimirRecaudaciones(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones);
void ImprimirUnaRecaudacion(eRecaudacion listaRecaudaciones);

#endif /* RECAUDACION_H_ */
