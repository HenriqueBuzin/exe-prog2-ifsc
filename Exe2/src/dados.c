#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dados.h"

struct dados {
	int amostra;
	float temperatura;
	char tempo[64];
};

dado_t* insere_dado(int amostra, float temperatura, char * timestamp){
	dado_t *dado = malloc(sizeof(dado_t));
	if(dado == NULL) {
		perror("Memória insuficiente");
		exit(1);
	}

	dado->amostra = amostra;
	dado->temperatura = temperatura;
	strcpy(dado->tempo, timestamp);

	return dado;
}

void libera(dado_t *dado){
	free(dado);
}

void exibe(dado_t * dado){

	printf("%d %f %s \n", dado->amostra, dado->temperatura, dado->tempo);

}
