#ifndef DADO_H_INCLUDED

#include "lista_enc.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra 
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int amostra, float temperatura, char * timestamp);


/* Outras funções aqui: fazer os comentários */
lista_enc_t *ler_dados_csv(char *nome_do_arquivo);
void imprimir_dados(lista_enc_t *lista);
void liberar_dados(lista_enc_t *lista);
float temperatura_media(lista_enc_t *lista);
float temperatura_max(lista_enc_t *lista);


#endif
