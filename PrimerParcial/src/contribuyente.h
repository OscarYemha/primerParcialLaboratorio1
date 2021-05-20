/*
 * contribuyente.h
 *
 *  Created on: 17 may. 2021
 *      Author: oscar
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_


typedef struct
{
	int idContribuyente;
	char nombre[51];
	char apellido [51];
	char cuil[16];
	int isEmpty;
}eContribuyente;

void IniciarListaContribuyentes(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
int BuscarLugarParaContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
void AltaContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes, int index, int *idContribuyente);
int ImprimirContribuyentes(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
void ImprimirUnContribuyente(eContribuyente listaContribuyentes);
int ChequeaListaVacia(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
void ModificaDatosContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
void ImprimirContribuyentesYRecaudaciones(eContribuyente listaContribuyentes[], int cantidadContribuyentes, eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones);

#endif /* CONTRIBUYENTE_H_ */
