/*
 * UTN.c
 *
 *  Created on: 13 may. 2021
 *      Author: oscar
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    int bufferInt;

    retorno = 0;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 1;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                printf("reintentos: %d\n", reintentos);
                reintentos --;
            }
        }while(reintentos >= 0);
    }


    return retorno;
}

int utn_getNumeroB(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    int bufferInt;

    retorno = 0;

    if(mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = bufferInt;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                printf("reintentos: %d\n", reintentos);
                reintentos --;
            }
        }while(reintentos >= 0);
    }


    return retorno;
}
