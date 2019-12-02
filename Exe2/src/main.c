#include <stdio.h>
#include <stdlib.h>

#include "dados.h"

int main(void) {

	int i;

	int n_linhas = 0;

	FILE *fp = fopen("camera_temp.csv","r");

	if(!fp){
		perror("Erro ao abrir arquivo");
		exit(-1);
	}

	fseek(fp, 19, SEEK_SET);

	char linha[99];

	while(fgets(linha, sizeof(linha), fp) != NULL){
		n_linhas++;
	}

	dado_t **dados;

	dados = malloc(sizeof(dado_t *) * n_linhas);

	rewind(fp);

	fseek(fp, 19, SEEK_SET);

	int amostra;
	float temperatura;
	char tempo[64];

	i = 0;
	while(fscanf(fp, "%d,%f,%63[^\n]", &amostra, &temperatura, tempo) == 3){
		printf("%d, %f, %s\n", amostra, temperatura, tempo);
		dados[i] = insere_dado(amostra, temperatura, tempo);
		i++;
	}

	 for (i=0; i < n_linhas; i++){
	 	 exibe(dados[i]);
	 	 libera(dados[i]);
	 }

	 free(dados);

	fclose(fp);
	return EXIT_SUCCESS;
}
