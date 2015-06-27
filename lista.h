#ifndef _LISTA_H
#define _LISTA_H

typedef struct punteroLista puntero;
typedef struct listaDEnlazada lista;

struct punteroLista{
	lista *inicio;
	lista *fin;
};
struct listaDEnlazada{
	char *string;
	lista *ant;
	lista *sig;
};

puntero *newLista ();
int addOrdenado(puntero *lis, char *buffer);
int addFinal(puntero *lis,char *buffer);
int addPrincipio (puntero *lis, char *buffer);
int eliminarFinal(puntero *lis);
int eliminarPrimero(puntero *lis);
int eliminarLista(puntero *lis);
int mostrar(puntero *lis);

#endif
