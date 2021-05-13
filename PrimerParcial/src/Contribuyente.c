/*
 * Contribuyente.c
 *
 *  Created on: 13 may. 2021
 *      Author: oscar
 */

#include <stdio.h>
#include <stdlib.h>
#include "Contribuyente.h"
#define VACIO 0
#define OCUPADO 1

void IniciarListaContribuyentes(eContribuyente listaContribuyentes[], int cantidadContribuyentes)
{
    int i;

    for(i=0; i<cantidadContribuyentes; i++)
    {
    	listaContribuyentes[i].isEmpty = VACIO;
    }
}

int BuscarLugarParaContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes)
{
	int i;
	int index;

	index = -1;

	for(i=0; i<cantidadContribuyentes; i++)
	{
		if(listaContribuyentes[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

void ChequearLugarVacioContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes, int index)
{
	if(index == -1)
	{
		printf("No hay lugar disponible para ingresar un nuevo contribuyente.\n");
	}
	else
	{
		AltaContribuyente(listaContribuyentes, cantidadContribuyentes, index);
	}
}

void AltaContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes, int index)
{
	int idContribuyente;

	idContribuyente = 1000;


		printf("Ingrese el nombre: ");
		//fflush(stdin);
		__fpurge(stdin);
		gets(&listaContribuyentes[index].nombre);
		printf("Ingrese el apellido: ");
		//fflush(stdin);
		__fpurge(stdin);
		gets(&listaContribuyentes[index].apellido);
		printf("Ingrese número de CUIL: ");
		scanf("%s",&listaContribuyentes[index].cuil);
		while(strlen(listaContribuyentes[index].cuil) != 11)
		{
		    printf("El número de CUIL no debe ser diferente a 11 dígitos. Reingrese: ");
		    scanf("%s", &listaContribuyentes[index].cuil);
		}

		listaContribuyentes[index].idContribuyente = idContribuyente;
		listaContribuyentes[index].isEmpty = OCUPADO;



		idContribuyente ++;

}
