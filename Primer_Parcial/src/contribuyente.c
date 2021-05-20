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


void AltaContribuyente(eContribuyente listaContribuyentes[], int cantidadContribuyentes, int index, int *idContribuyente)
{

	if(index == -1)
	{
		printf("No hay lugar disponible para ingresar un nuevo contribuyente.\n");
	}
	else
	{
		printf("Ingrese el nombre: ");
		__fpurge(stdin);
		fgets(listaContribuyentes[index].nombre, 51, stdin);
		printf("Ingrese el apellido: ");
		__fpurge(stdin);
		fgets(listaContribuyentes[index].apellido, 51, stdin);
		printf("Ingrese número de CUIL(xx-xxxxxxxx-xx): ");
		__fpurge(stdin);
		fgets(listaContribuyentes[index].cuil, 16, stdin);
		while(strlen(listaContribuyentes[index].cuil) != 14 || listaContribuyentes[index].cuil[2] != '-' || listaContribuyentes[index].cuil[11] != '-')
		{
		    printf("El número de CUIL debe tener el formato xx-xxxxxxxx-xx Reingrese: ");
		    fgets(listaContribuyentes[index].cuil, 16, stdin);
		}
		listaContribuyentes[index].idContribuyente = *idContribuyente;
		listaContribuyentes[index].isEmpty = OCUPADO;



		(*idContribuyente) ++;

		printf("Carga realizada. Presione enter para continuar\n");
		__fpurge(stdin);
		getchar();
	}

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
		printf(" ID -  Nombre -  Apellido-CUIL-Mes Recaudación\n");
		for(i=0;i<cantidadContribuyentes; i++)
		{
			if(listaContribuyentes[i].isEmpty == OCUPADO)
			{
				ImprimirUnContribuyente(listaContribuyentes[i]);
			}
		}
		printf("Presione Enter para continuar\n");
		__fpurge(stdin);
		getchar();
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
			printf("%d %s %s %s \n", listaContribuyentes.idContribuyente,
											   listaContribuyentes.nombre,
											   listaContribuyentes.apellido,
											   listaContribuyentes.cuil);
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

    //dato = ImprimirContribuyentes(listaContribuyentes, cantidadContribuyentes);

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
                    fgets(listaContribuyentes[i].nombre, 51, stdin);
                    __fpurge(stdin);
                    printf("Ingrese apellido: ");
                    fgets(listaContribuyentes[i].apellido, 51, stdin);
                    printf("Ingrese cuil (xx-xxxxxxxx-x): ");
                    __fpurge(stdin);
                    fgets(listaContribuyentes[i].cuil, 16, stdin);
                    while(strlen(listaContribuyentes[i].cuil) != 14 || listaContribuyentes[i].cuil[2] != '-' || listaContribuyentes[i].cuil[11] != '-')
					{
						printf("El número de CUIL debe tener el formato xx-xxxxxxxx-xx Reingrese: ");
						fgets(listaContribuyentes[i].cuil, 16, stdin);
					}
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

void ImprimirContribuyentesYRecaudaciones(eContribuyente listaContribuyentes[], int cantidadContribuyentes, eRecaudacion listaRecaudaciones[], int cantidadRecaudaciones)
{

}
