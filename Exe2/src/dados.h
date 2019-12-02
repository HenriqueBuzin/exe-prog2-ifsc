#ifndef DADO_H_INCLUDED

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
  
dado_t* insere_dado(int amostra, float temperatura, char * timestamp);

void libera(dado_t *dado);

void exibe(dado_t * dado);

#endif
