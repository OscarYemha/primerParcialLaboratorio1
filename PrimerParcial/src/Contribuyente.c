/*
 * Contribuyente.c
 *
 *  Created on: 13 may. 2021
 *      Author: oscar
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contribuyente.h"
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
		//fflush(stdin);
		__fpurge(stdin);
		scanf("%s",&listaContribuyentes[index].cuil);
		while(strlen(listaContribuyentes[index].cuil) != 11)
		{
		    printf("El número de CUIL no debe ser diferente a 11 dígitos. Reingrese: ");
		    scanf("%s", &listaContribuyentes[index].cuil);
		}

		listaContribuyentes[index].idContribuyente = idContribuyente;
		listaContribuyentes[index].isEmpty = OCUPADO;



		idContribuyente ++;

		printf("Carga realizada\n");

}

int ImprimirContribuyentes(eContribuyente listaContribuyentes[], int cantidadContribuyentes)
{
    int i;
    int dato;
    int retorno;

    retorno = 1;
    dato = ChequeaListaVacia(listaContribuyentes, cantidadContribuyentes);

    if(dato == 1)
    {
		printf("ID - Nombre - Apellido - CUIL\n");
		for(i=0;i<cantidadContribuyentes; i++)
		{
			if(listaContribuyentes[i].isEmpty == OCUPADO)
			{
				ImprimirUnContribuyente(listaContribuyentes[i]);
			}
		}
    }
    else
    {
    	printf("No hay contribuyentes dados de alta\n");
    	retorno = 0;
    }

    return retorno;
}

void ImprimirUnContribuyente(eContribuyente listaContribuyentes)
{
    printf("%d %s %s %s\n", listaContribuyentes.idContribuyente,
    								   listaContribuyentes.nombre,
									   listaContribuyentes.apellido,
									   listaContribuyentes.cuil
									   );
}

int ChequeaListaVacia(eContribuyente listaContribuyentes[], int cantidadContribuyentes)
{
	int i;
	int retorno;

	retorno = 0;

	for(i=0;i<cantidadContribuyentes; i++)
	{
		if(listaContribuyentes[i].isEmpty == OCUPADO)
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

void ModificaDatosContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes)
{
    int dato;
    int id;
    int i;
    char pregunta;

    dato = ImprimirContribuyentes(listaContribuyentes, cantidadContribuyentes);

    if(dato == 1)
    {
        printf("Ingrese el ID del Contribuyente a modificar: ");
        scanf("%d", &id);
        for(i=0;i<cantidadContribuyentes; i++)
        {
            if(listaContribuyentes[i].idContribuyente == id)
            {
                printf("¿Desea modificar los datos del contribuyente? S/N: \n");
                __fpurge(stdin);
                scanf("%c", &pregunta);
                pregunta = tolower(pregunta);
                if(pregunta == 's')
                {
                    printf("Ingrese nombre: ");
                    __fpurge(stdin);
                    gets(&listaContribuyentes[i].nombre);
                    __fpurge(stdin);
                    printf("Ingrese apellido: ");
                    gets(&listaContribuyentes[i].apellido);
                    printf("Ingrese cuil: ");
                    __fpurge(stdin);
                    scanf("%s", &listaContribuyentes[i].cuil);
                    printf("Modificación realizada\n");
                    break;
                }
                else
                {
                    printf("Modificación cancelada\n");
                }
            }
            else
            {
                printf("ID no encontrado \n");
            }
        }
    }


}
