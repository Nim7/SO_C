#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

puntero *newLista(){ // Crea la estructura de la lista, y lo inicializa a NULL
	puntero *lis;
	lis = (puntero*) malloc (sizeof(puntero));
	(*lis).inicio=NULL;
	(*lis).fin=NULL;
	return lis;
}
int addOrdenado(puntero *lis, char *buffer){ //Inserta ordenado por cabecera u orden de llegada (a igual lingitud)
	lista *punt;
	lista *aux;
	punt=(*lis).inicio;
	while((punt!=NULL) && (strlen(buffer)<=strlen((*punt).string))){ //Buscar la posicion a insertar
		punt=(*punt).sig;
	}
	if (punt==NULL){ //Al elemento le corresponde la ultima posicion, o la lista esta vacia
		addFinal(lis,buffer);
	}
	else if(punt!=NULL){
		if ((*punt).ant==NULL){ //Al elemento le corresponde la primera posicion
			addPrincipio(lis,buffer);
		}else{ //insertamos entre dos elementos
			aux=(lista *)malloc (sizeof(lista));
			(*aux).string=(char *) malloc (strlen(buffer)*sizeof(char));
			strcpy((*aux).string,buffer);
			(*aux).sig=punt;
			(*aux).ant=(*punt).ant;
			(*punt).ant=aux;
			punt=(*aux).ant;
			(*punt).sig=aux;
		}
	}
	return 0;
}

int addFinal(puntero *lis,char *buffer){ //Insertar por final
	lista *punt=(*lis).fin;
	lista *aux;
	aux=(lista *) malloc(sizeof(lista));
	(*aux).string=(char *) malloc((strlen(buffer))*sizeof(char));
	strcpy((*aux).string,buffer);
	(*aux).sig=NULL;
	if (punt!=NULL){ //La lista esta vacia
		(*aux).ant=punt;
		(*punt).sig=aux;
	}else{ //la lista tiene algun elemento
		(*aux).ant=NULL;
		(*lis).inicio=aux;
	}
	(*lis).fin=aux;
	return 0;
}

int addPrincipio (puntero *lis,char *buffer){ //Insertar por cabecera
	lista *punt=(*lis).inicio;
	lista *aux;
	aux= (lista *) malloc(sizeof(lista));
	(*aux).string=(char *) malloc(strlen(buffer)*sizeof(char));
	strcpy((*aux).string,buffer);
	(*aux).ant=NULL;
	(*lis).inicio=aux;
	if (punt==NULL){ //La lista esta vacia
		(*lis).fin=aux;
		(*aux).sig=NULL;
	}else{ //La lista no esta vacia
		(*punt).ant=aux;
		(*aux).sig=punt;
	}
	return 0;
}
int eliminarFinal(puntero *lis){ //Eliminar el ultimo elemento
	lista *aux=(*lis).fin;
	lista *punt=(*lis).fin;
	if (punt!=NULL){ //La lista no esta vacia
		punt=(*punt).ant;
		if (punt!=NULL){ //La lista tiene mas de un elemento
			(*punt).sig=NULL;
		}else{ //La lista solo contiene el elemento a borrar
			(*lis).inicio=NULL;
		}
		(*lis).fin=punt;
		//Liberar memoria
		free((*aux).string);
		free(aux);
	}
	return 0;
}
int eliminarPrimero(puntero *lis){
	lista *aux=(*lis).inicio;
	lista *punt=(*lis).inicio;
	if (punt!=NULL){ //La lista no esta vacia
		punt=(*punt).sig;
		if (punt!=NULL){ //La lista tiene mas de un elemento
			(*punt).ant=NULL;
		}else{ //La lista solo contiene el elemento a borrar
			(*lis).fin=NULL;
		}
		(*lis).inicio=punt;
		//Liberar memoria
		free((*aux).string);
		free(aux);
	}
	return 0;
}
int mostrar(puntero *lis){ //Muesta la lista por salida estandar
	lista *punt=(*lis).inicio;
	while(punt!=NULL){
		fputs((*punt).string, stdout);
		punt=(*punt).sig;
	}
	return 0;
}
int eliminarLista(puntero *lis){  //Elimina la lista, liberando la memoria
	while((*lis).inicio!=NULL){
		eliminarPrimero(lis);
	}
	free(lis); //Liberar la estructura principal de la lista
	lis = NULL;
	return 0;
}
