#include <stdio.h>
#include <stdlib.h>
#include "frequencia.h"

unsigned int *freq(FILE *arquivo){
    unsigned int x;
    unsigned int i;
    unsigned int tamanho;
    unsigned int *countsort;

    //Calcular o tamanho em Bytes do arquivo
    // movimenta a posição corrente de leitura no arquivo para o fim
    fseek(arquivo, 0, SEEK_END);
    // pega a posição corrente de leitura no arquivo
    tamanho = ftell(arquivo);
    // imprime o tamanho do arquivo
    //printf("O arquivo possui %d bytes", tamanho);


    countsort = (unsigned int*)malloc(tamanho*sizeof(unsigned int));
    // Inserindo em cada posição o valor 0
    for ( i = 0; i < tamanho; i++ ){
        countsort[i] = 0;
    }

    while(1){
        x = fgetc(arquivo);
        //Verifica se o arquivo chegou ao fim
        if(feof(arquivo)){
            break;
        }
        // Imcrementa
        countsort[x]++;
    }

    return countsort;
}
