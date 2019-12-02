
/* de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string> */
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "dados.h"
  
struct dados {
    int amostra;        /*!< Identificador numérido da amostra */
    float temperatura;  /*!< Valor do dado: temperatura */
    char tempo[64];      /*!< Time stamp */
};


float temperatura_media(lista_enc_t *lista){



    /* Implemente aqui */



}



float temperatura_max(lista_enc_t *lista){

	


    /* Implemente aqui */



}


void liberar_dados(lista_enc_t *lista){
   


    /* Implemente aqui */



   
}


dado_t * criar_dado (int amostra, float temperatura, char * timestamp){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    meu_novo_dado->amostra = amostra;
    meu_novo_dado->temperatura = temperatura;
    strncpy(meu_novo_dado->tempo, timestamp, 64);
    
    return meu_novo_dado;
}



lista_enc_t *ler_dados_csv(char *nome_do_arquivo){
    char texto[64];
    int amostra;
    float temperatura;

    /* Demais Variáveis */
    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    lista = criar_lista_enc();
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */
    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        
#ifdef DEBUG
    	printf("Lido %d, %f, %s\n", amostra, temperatura, texto);
#endif
        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(amostra, temperatura, texto);
        meu_no = criar_no(dado);
        add_cauda(lista, meu_no);
    }

    fclose(fp);

    return lista;
}

void imprimir_dados(lista_enc_t *lista){

	no_t *no;

	/* Imprime dados de toda a lista */
	for (no=obter_cabeca(lista); no != NULL; no=obter_proximo(no)){
		dado_t *dado = obter_dado(no);
		printf("%d\t%f\t%s\n", dado->amostra, dado->temperatura, dado->tempo);
	}
}