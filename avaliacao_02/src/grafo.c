#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "fila.h"

struct vertices {
	int id;
    int pai;
	int grupo;
};

struct arestas {
	int adj;
};

struct grafos{
	int n_vertices;
	vertice_t *vertices;
	aresta_t **matriz_adj;
};

void componentes_conexos(grafo_t *grafo){

		int id_grupo = 0;

		int i;
		for(i = 0; i < grafo->n_vertices; i++){
			// -1 representa que ainda n�o tem grupo
			grafo->vertices[i].grupo = -1;
			// 0 significa NULL
			grafo->vertices[i].pai = 0;
		}


		for(i = 0; i < grafo->n_vertices; i++){
			if(grafo->vertices[i].grupo == -1){
				bfs(grafo, i, id_grupo);
				id_grupo++;
			}

		}

}


void bfs(grafo_t *g, int vertice, int grupo){

	fila_t * Q = cria_fila();

	g->vertices[vertice].grupo = grupo;
	enqueue((void*)(long)vertice, Q);

	while (!fila_vazia(Q)){
		int u = (int) (long) dequeue(Q);
		for(int i = 0; i < g->n_vertices; i++){
			if(adjacente(g, u, i)){
				if(g->vertices[i].grupo == -1){
					g->vertices[i].grupo = grupo;
					g->vertices[i].pai = u;
					enqueue((void*)(long)i, Q);
				}
			}
		}
	}

	libera_fila(Q);

}

void imprimir(grafo_t *g){
	printf("[v] - [grupo]\n");
	for(int i = 0; i < g->n_vertices; i++){
		printf("%d - %d\n", g->vertices[i].id, g->vertices[i].grupo);
	}
}

grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda número total de vértices */
	g->n_vertices = vertices;
    /* Aloca vértices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de vértices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));
    
    /* Inicializa ID */
    for ( i = 0; i < vertices; i++ ){
        g->vertices[i].id = i;
    }    

    /* Aloca 1a dimensão da matriz de adjacência */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimensão da matriz de adjacência */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

void export_grafo_dot(const char *filename, grafo_t *g){
	int i,j;
	FILE *file;

	file = fopen(filename, "w");

	if (file == NULL){
		perror(__func__);
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	/* Exporta os vértices */
	for (i=0; i < g->n_vertices; i++){
		fprintf(file, "\t%d [label = \"%d (%d)\"]\n", i, i, i);
	}

	/* Exporta todas as arestas */
	for (i=0; i < g->n_vertices; i++){
		for (j=i; j < g->n_vertices;j++) {

			if (adjacente(g,i,j))
				fprintf(file, "\t%d -- %d\n", i, j);
		}
	}
	fprintf(file, "}\n");

	fclose(file);
}
