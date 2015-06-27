	#include <stdio.h>
	#include <stdlib.h>
  #include <string.h>

  #include "libreria.h"  //Include de cabecera. 
  #include "lista.h"     //Include de libreria auxiliar.

  #define LETRAS 1024 //Constante de tamaño del char[] para recoger la entrada estandar.
  
// ------ Funcion HEAD ------ //

int head(int N){
	int c=0;
	char linea [LETRAS];    
	
   	//Mientras pueda leer mas lineas, las va imprimiendo
   	//desde la 1 hasta la N (o hasta que acabe el fichero).

	while ((c < N) && ( fgets(linea, LETRAS, stdin)!=NULL)){ //Mientras no End of File.
			fputs(linea, stdout);//Imprime la linea por salida estandar.
			c++;
	}
	return 0;
}

// ------ Fin de Funcion HEAD ------ //

//-----------------------------------//

// ------ Funcion TAIL ------ //

int tail(int N){
	int c=0;
  char linea [LETRAS];
  
  puntero *list;

  list= newLista();
  while(fgets(linea, LETRAS, stdin)!=NULL){ //Mientras no EoF.
    addFinal(list, linea); // Insertamos al final. 
		c++;
    if (c>N){   //Si ya tenemos el tamaño maximo de lineas, vamos borrando por cabecera.
      eliminarPrimero(list);
    }
  }
  mostrar(list);  //Mostramos la lista, y liberamos toda la memoria.
  eliminarLista(list);
  return 0;
}
// ------ Fin de Funcion TAIL ------ //

//-----------------------------------//

// ------ Funcion LONGLINES ------ //

int longlines(int N){
  int c=0;
  char linea [LETRAS];
  
  puntero *list;

  list= newLista();
  while(fgets(linea, LETRAS, stdin)!=NULL){ //Mientras no EoF
    addOrdenado(list, linea); //Insertamos ordenado
    c++;
    if (c>N){  //Si ya tenemos el tamaño maximo de lineas, vamos borrando por final.
      eliminarFinal(list);
    }
  }
  mostrar(list);  //Mostramos la lista, y liberamos toda la memoria.
  eliminarLista(list);
  return 0;
}
// ------ Fin de Funcion LONGLINES ------ //