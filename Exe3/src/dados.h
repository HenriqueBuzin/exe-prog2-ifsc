#ifndef DADO_H_INCLUDED

typedef struct dados dado_t;

dado_t * criar_dado (int amostra, float temperatura, char * timestamp);

void liberar_dados(dado_t **vetor, int n_linhas);

dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas);

void exibe(dado_t * dado);

#endif
