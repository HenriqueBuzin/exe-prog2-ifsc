/*
 * grafo.h
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);

void componentes_conexos(grafo_t *grafo);
void bfs(grafo_t *g, int vertice, int grupo);

void export_grafo_dot(const char *filename, grafo_t *g);

void imprimir(grafo_t *g);

#endif /* GRAFO_H_ */
