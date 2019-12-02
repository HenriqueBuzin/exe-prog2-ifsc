/*
 * main.c
 *
 *  Created on: Sep 10, 2019
 *      Author: Renan Augusto Starke
 * Programa que exibe na tela dados formatados
 * de um arquivo CSV conforme o padrão:
 *         Series;Value;Time
 *         <int>;<float>;<string>
 *         <int>;<float>;<string>
 */

#include <stdio.h>
#include "dados.h"
#include "lista_enc.h"


// -> prova: tabela de complexidade
// -> implementação das funções maximo, média, e liberação de memória

int main(){
    lista_enc_t *lista = ler_dados_csv("data.csv");

    imprimir_dados(lista);

    printf("Temperatura media: %f\n", temperatura_media(lista));
    printf("Temperatura max: %f\n", temperatura_max(lista));


    liberar_dados(lista);

    return 0;
}
