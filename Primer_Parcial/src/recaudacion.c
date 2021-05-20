/*
 * recaudacion.c
 *
 *  Created on: 18 may. 2021
 *      Author: oscar
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "recaudacion.h"
#include "contribuyente.h"
#include "UTN.h"
#define VACIO 0
#define OCUPADO 1
#define SALDADO 1
#define NOSALDADO 1


void IniciarListaRecaudaciones(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones)
{
	int i;

	for(i=0; i<cantidadRecaudaciones; i++)
	{
		listaRecaudaciones[i].isEmpty = VACIO;
		listaRecaudaciones[i].estado = NOSALDADO;
	}
}

int BuscarLugarParaRecaudacion(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones)
{
	int i;
	int index;

	index = -1;

	for(i=0; i<cantidadRecaudaciones; i++)
	{
		if(listaRecaudaciones[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

void AltaRecaudacion(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones, int index, int *idRecaudacion, eTipoRecaudacion listaTipoRecaudaciones[], int cantidadTipoRecaudaciones)
{

	listaRecaudaciones[index].idRecaudacion = *idRecaudacion;
	listaRecaudaciones[index].idContribuyente = utn_getNumeroB("Ingrese el ID del contribuyente", "Error", 1000, 10000, 3);
	listaRecaudaciones[index].mes = utn_getNumeroB("Ingrese el Mes (1 a 12): ", "Error", 1, 12, 3);
	ImprimirTipoRecaudaciones(listaTipoRecaudaciones,cantidadTipoRecaudaciones);
	printf("Ingrese el número de tipo: ");
	scanf("%d", &listaRecaudaciones[index].tipo);
	listaRecaudaciones[index].isEmpty = OCUPADO;
	(*idRecaudacion)++;
}

int ImprimirTipoRecaudaciones(eTipoRecaudacion listaTipoRecaudaciones[], int cantidadTipoRecaudaciones)
{
	int i;
	//int dato;
	int retorno;

	retorno = 1;
	//dato = ChequeaListaVacia(listaRecaudaciones, cantidadRecaudaciones);

	//if(dato == 1)
	//{
		printf("ID  Tipo\n");
		for(i=0;i<cantidadTipoRecaudaciones; i++)
		{
			if(listaTipoRecaudaciones[i].isEmpty == OCUPADO)
			{
				ImprimirUnTipoRecaudacion(listaTipoRecaudaciones[i]);
			}
		}
		printf("Presione Enter para continuar\n");
		__fpurge(stdin);
		getchar();
	//}
//	else
//	{
//		printf("No hay contribuyentes dados de alta\n");
//		retorno = 0;
//	}

	return retorno;
}

void ImprimirUnTipoRecaudacion(eTipoRecaudacion listaTipoRecaudaciones)
{
	 printf("%d %s\n", listaTipoRecaudaciones.idTipoRecaudacion,
			 	 	 	 listaTipoRecaudaciones.descripcion);
}

//int ChequeaListaVacia(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones)
//{
//
//}

//int ImprimirRecaudaciones(eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones)
//{
//
//}

void ImprimirUnaRecaudacion(eRecaudacion listaRecaudaciones)
{

}
