/*
 ============================================================================
 Name        : Primer_Parcial.c
 Author      : Yemha, Oscar Ismael
 Version     :
 Copyright   : Your copyright notice
 Description : Se necesita administrar la recaudacion de impuestos de los contribuyentes, y para ello
se deberá realizar un programa de acuerdo a lo siguiente:
Contará con el siguiente menú:

1) Alta de Contribuyente: Se da de alta un contribuyente con nombre, apellido, y c.u.i.l. Se
generará un ID único (comenzando en 1000) para este contribuyente que se imprimirá por
pantalla si el alta es correcta.

2) Modificar datos del contribuyente: Se ingresa el ID del contribuyente y se permitirá
cambiar el nombre, el apellido y el c.u.i.l.

3) Baja de contribuyente: Se ingresa el ID del contribuyente y se listarán todas las
recaudaciones de dicho contribuyente. Luego se preguntará si se quiere confirmar la
eliminación, la cual implicará la eliminación de todos las recaudaciones y del contribuyente.

4) Recaudación: Permitirá crear una nueva recaudación. Se pedirán los siguientes datos: ID
de contribuyente, mes, tipo (1-ARBA, 2-IIBB, 3-GANANCIAS) e importe. Se generará
automáticamente un identificador numérico (comenzando en 100) para la recaudación y se
imprimirá en pantalla.

5) Refinanciar Recaudación: Se pedirá el ID de la recaudación y se imprimirá la información
del contribuyente al que pertenece, luego se pedirá confirmación para cambiarse de estado y
se cambiará al estado "refinanciar".

6) Saldar Recaudación: Se pedirá el ID de la recaudación y se imprimirá la información del
contribuyente al que pertenece, luego se pedirá confirmación para cambiarse de estado y se
cambiará al estado "saldado".

7) Imprimir Contribuyentes: Se imprimirá una lista de los contribuyentes con todos sus datos
junto con las Recaudaciones que posee.

8) Imprimir Recaudación: Se imprimirá una lista de las Recaudaciones con estado
“saldadas” con todos sus datos junto con el c.u.i.l. y nombre del contribuyente
correspondiente.

Nota 0: El sistema soportará una capacidad máxima de 50 contribuyentes y 50 recaudaciones
Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja,
Modificar, etc.). Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contribuyente.h"
#include "recaudacion.h"
#include "UTN.h"
#define CANTIDADCONTRIBUYENTES 2
#define CANTIDADRECAUDACIONES 3
#define CANTIDADTIPOSRECAUDACIONES 3

int main(void) {

	setbuf(stdout, NULL);
	int respuesta;
	int opcion;
	int indexContribuyente;
	int idContribuyente;
	int indexRecaudacion;
	int idRecaudacion;

	eContribuyente listaContribuyentes[CANTIDADCONTRIBUYENTES]={{1000,"Oscar Ismael", "Yemha", "20-35256333-2",1},{1001,"Fernanda Luján", "Castillo", "20-34750987-2",1}};
	eRecaudacion listaRecaudaciones[CANTIDADRECAUDACIONES] ={{100,1,1,200,1,1000},{101,5,2,500,1,1001},{102,8,3,1050.5,1,1000}};
	eTipoRecaudacion listaTiposRecaudaciones[CANTIDADTIPOSRECAUDACIONES] = {{1,"ARBA",1},{2,"IIBB",1},{3,"GANANCIAS",1}};


	idContribuyente = 1000;
	idRecaudacion = 100;


//	IniciarListaContribuyentes(listaContribuyentes, CANTIDADCONTRIBUYENTES);
//	IniciarListaRecaudaciones(listaRecaudaciones, CANTIDADRECAUDACIONES);

	do
	    {
	        respuesta = utn_getNumero(&opcion, "Bienvenido. Ingrese una opción\n1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja del contribuyente\n4.Alta Recaudación\n5.Refinanciar Recaudación\n6.Saldar Recaudación\n7.Imprimir contribuyentes\n8.Imprimir Recaudación\n9.Salir\n","Opción no válida\n", 1, 9, 3);

	        if(respuesta == 1)
	        {
	            switch(opcion)
	            {
	                case 1:
	                	indexContribuyente = BuscarLugarParaContribuyente(listaContribuyentes, CANTIDADCONTRIBUYENTES);
	                    AltaContribuyente(listaContribuyentes, CANTIDADCONTRIBUYENTES, indexContribuyente, &idContribuyente);
	                break;
	                case 2:
                        ModificaDatosContribuyente(listaContribuyentes, CANTIDADCONTRIBUYENTES);
	                break;
	                case 3:

	                break;
	                case 4:
	                	indexRecaudacion = BuscarLugarParaRecaudacion(listaRecaudaciones, CANTIDADRECAUDACIONES);
	                	ImprimirContribuyentes(listaContribuyentes, CANTIDADCONTRIBUYENTES);
	                	AltaRecaudacion(listaRecaudaciones, CANTIDADRECAUDACIONES, indexRecaudacion, &idRecaudacion, listaTiposRecaudaciones, CANTIDADTIPOSRECAUDACIONES);
	                break;
	                case 5:

	                break;
	                case 6:

	                break;
	                case 7:
                        ImprimirContribuyentesYRecaudaciones(listaContribuyentes, CANTIDADCONTRIBUYENTES, listaRecaudaciones, CANTIDADRECAUDACIONES);
	                break;
	                case 8:

	                break;
	            }
	        }
	    }while(opcion != 9);

	    printf("\nGracias por utilizar este programa.");

	return EXIT_SUCCESS;
}

