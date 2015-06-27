	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

	#include "libreria.h"
	#include "lista.h"

//Compilacion con:
//gcc test.c libreria.c lista.c -o test

int main(int argc,char*argv[]){
	
	//Para que el programa funcione necesitamos en total tres
	//argumentos: el nombre del programa, la funcion a la que
	//queremos llamar, y el número de líneas: argc = 3.

	if (argc == 3){
		char* funcion = argv[1]; 	//Funcion que vamos a usar.
		int n;
		//Comprobación de que el argumento es un entero precedido de "-".
		if (argv[2][0]=='-'){
			n = atoi(argv[2]+1);
			
			if(n>0){	//N es un valor adecuado para la llamada a funciones

		//--- Llamadas a funciones --- //

			    //HEAD(N)
			    if (strcmp("head", funcion) == 0){
				    return(head(n));
			    }
			    //TAIL(N)
			    else if (strcmp("tail", funcion) == 0){
				    return(tail(n));
			    }
			    //LONGLINES(N)
			    else if(strcmp("longlines", funcion) == 0){
				    return(longlines(n));
			    }
			    //En el caso de que la funcion no esté definida, error:
			    else{ 
				    printf("Ese método no está. Tengo 'head', 'tail' y 'longlines' y se invocan con: %s 'funcion' -N\n",argv[0]);
				    return 1;
			    }
		//--- Llamadas a funciones --- //
			
			}else{
				printf("El segundo argumento tiene que ser un número entero distinto de 0.\n");
				return 1;
			}		
		}else{
			printf("Uso: %s 'funcion' -N\n",argv[0]);
			return 1;
		}	    
    }else { //Si el numero de argumentos no es el adecuado, error:
		printf("Necesito dos argumentos, Uso: %s 'funcion' -N\n",argv[0]);
		return 1;
	}
}
