#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_enc_t;

lista_enc_t *criar_lista_enc(void);

void add_cauda(lista_enc_t *lista, no_t* elemento);

no_t *obter_cabeca(lista_enc_t *lista);

#endif // LISTA_ENC_H_INCLUDED
