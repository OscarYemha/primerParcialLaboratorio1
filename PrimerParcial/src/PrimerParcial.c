/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Contribuyente.h"
#include "UTN.h"
#define CANTIDADCONTRIBUYENTES 50

int main(void) {

	setbuf(stdout, NULL);
	int respuesta;
	int opcion;
	int index;
	eContribuyente listaContribuyentes[CANTIDADCONTRIBUYENTES];

	IniciarListaContribuyentes(listaContribuyentes, CANTIDADCONTRIBUYENTES);

			do
		    {
		        respuesta = utn_getNumero(&opcion, "Bienvenido. Ingrese una opci�n\n1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja del contribuyente\n4.Recaudaci�n\n5.Refinanciar Recaudaci�n\n6.Saldar Recaudaci�n\n7.Imprimir contribuyentes\n8.Imprimir Recaudaci�n\n9.Salir\n","Opci�n no v�lida\n", 1, 9, 3);

		        if(respuesta == 1)
		        {
		            switch(opcion)
		            {
		                case 1:
		                    index = BuscarLugarParaContribuyente(listaContribuyentes, CANTIDADCONTRIBUYENTES);
		                    ChequearLugarVacioContribuyente(listaContribuyentes, CANTIDADCONTRIBUYENTES, index);
		                break;
		                case 2:
	                        ModificaDatosContribuyente(listaContribuyentes, CANTIDADCONTRIBUYENTES);
		                break;
		                case 3:

		                break;
		                case 4:

		                break;
		                case 5:

		                break;
		                case 6:

		                break;
		                case 7:
	                        ImprimirContribuyentes(listaContribuyentes, CANTIDADCONTRIBUYENTES);
		                break;
		                case 8:

		                break;
		            }
		        }
		    }while(opcion != 9);

	    printf("\nGracias por utilizar este programa.");

	return EXIT_SUCCESS;
}
