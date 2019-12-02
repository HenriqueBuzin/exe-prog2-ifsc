#include <stdio.h>
#include "dados.h"


int main(){
    int n_linhas = 0;

    dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

    /* Imprima os dados:*/
    for (int i=0; i < n_linhas; i++){
    	 exibe(dados[i]);
    }

    liberar_dados(dados, n_linhas);

    return 0;
}
