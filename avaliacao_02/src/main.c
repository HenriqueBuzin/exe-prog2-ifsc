/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacência, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void) {


	int i,j;
	grafo_t *g;

    /* Cria grafo com 13 vértices */
	g = cria_grafo(13);

	

	/* Criar adjacências */

	// 0
	cria_adjacencia(g, 0, 1);
	cria_adjacencia(g, 0, 5);
	cria_adjacencia(g, 0, 2);

	// 1
	cria_adjacencia(g, 1, 2);
	cria_adjacencia(g, 1, 3);
	cria_adjacencia(g, 1, 0);

	// 2
	cria_adjacencia(g, 2, 1);
	cria_adjacencia(g, 2, 0);
	cria_adjacencia(g, 2, 3);
	cria_adjacencia(g, 2, 5);

	// 3
	cria_adjacencia(g, 3, 4);
	cria_adjacencia(g, 3, 1);
	cria_adjacencia(g, 3, 2);

	// 4
	cria_adjacencia(g, 4, 3);
	cria_adjacencia(g, 4, 5);

	// 5
	cria_adjacencia(g, 5, 4);
	cria_adjacencia(g, 5, 2);
	cria_adjacencia(g, 5, 0);

	// 6
	cria_adjacencia(g, 6, 7);

	// 7
	cria_adjacencia(g, 7, 6);
	cria_adjacencia(g, 7, 8);

	// 8
	cria_adjacencia(g, 8, 7);

	// 9
	cria_adjacencia(g, 9, 10);
	cria_adjacencia(g, 9, 11);

	// 10
	cria_adjacencia(g, 10, 9);
	cria_adjacencia(g, 10, 11);

	// 11
	cria_adjacencia(g, 11, 10);
	cria_adjacencia(g, 11, 9);

	/* Imprime matriz */
	for (i=0; i < 12; i++){
		for (j=0; j < 20; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

	componentes_conexos(g);

	printf("\n");
	imprimir(g);

	export_grafo_dot("grafo.dot", g);

	libera_grafo(g);

	return EXIT_SUCCESS;
}
