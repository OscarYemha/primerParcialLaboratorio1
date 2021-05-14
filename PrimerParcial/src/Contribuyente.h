/*
 * Contribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: oscar
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

typedef struct
{
	int idContribuyente;
	char nombre[50];
	char apellido [50];
	char cuil[50];
	int isEmpty;
}eContribuyente;

void IniciarListaContribuyentes(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
int BuscarLugarParaContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
void ChequearLugarVacioContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes, int index);
void AltaContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes, int index);
int ImprimirContribuyentes(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
void ImprimirUnContribuyente(eContribuyente listaContribuyentes);
int ChequeaListaVacia(eContribuyente listaContribuyentes[], int cantidadContribuyentes);
void ModificaDatosContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes);


#endif /* CONTRIBUYENTE_H_ */
