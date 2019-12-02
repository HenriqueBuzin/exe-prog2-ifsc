#include <stdio.h>
#include <stdlib.h>


int main(){

    int amostra;
	float temperatura;
    char data[64];

    FILE *fp = fopen("camera_temp.csv","r");

    if (fp == NULL){
        perror("Erro em main: fopen");
        exit(-1);
    }

    fseek(fp, 19, SEEK_SET);

    while (fscanf(fp, "%d, %f, %63[^\n]", &amostra, &temperatura, data) == 3){

    	printf("%d, %f, %s \n", amostra, temperatura, data);

    }

    fclose(fp);
}
