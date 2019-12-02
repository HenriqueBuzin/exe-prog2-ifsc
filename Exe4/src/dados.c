#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "lista_enc.h"
#include "dados.h"
#include "no.h"


struct dados {
    int amostra;
    float temperatura;
    char tempo[64];
};

dado_t * criar_dado (int amostra, float temperatura, char * timestamp){

    dado_t * dado = malloc(sizeof(struct dados));

    dado->amostra = amostra;
	dado->temperatura = temperatura;
	strcpy(dado->tempo, timestamp);

    return dado;
}

lista_enc_t *ler_dados_csv(char *nome_do_arquivo){

	char texto[64];
	int amostra;
	float temperatura;

    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    lista = criar_lista_enc();

    fgets(texto,64, fp);

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, texto);


        dado = criar_dado(amostra, temperatura, texto);

        meu_no = criar_no(dado);

        add_cauda(lista, meu_no);

    }

    return lista;
}

void liberar_dados(lista_enc_t *lista){

	no_t * no = obter_cabeca(lista);
	no_t *no_prox;

	while(no != NULL){
		free(obter_dado(no));
		no_prox = obter_proximo(no);
		free(no);
		no = no_prox;
	}
	free(lista);
}

void exibe(lista_enc_t * lista){

	no_t *no = obter_cabeca(lista);

	while(no != NULL){
		dado_t *dado = obter_dado(no);
		printf("%d %f %s \n", dado->amostra, dado->temperatura, dado->tempo);
		no = obter_proximo(no);
	}

}
