#include <stdlib.h>
#include <stdio.h>
#include "compressao.h"
#include "heap.h"
#include "hash.h"


void compress(FILE *arquivo,  char *endereco){

//Canculando quantos Bytes tem o arquivo

    //Variavel para guardar quantos bytes tem no arquivo
    unsigned int tamanho;
    // Guarda o estado antes de chamar a função fseek
    unsigned int posicaoAtual = ftell(arquivo);

    //Calcular o tamanho em Bytes do arquivo
    // movimenta a posição corrente de leitura no arquivo para o fim
    fseek(arquivo, 0, SEEK_END);

    // pega a posição corrente de leitura no arquivo
    tamanho = ftell(arquivo);

    // imprime o tamanho do arquivo
    // printf("O arquivo possui %d bytes\n", tamanho);

    // recupera o estado antigo do arquivo
    fseek(arquivo, posicaoAtual, SEEK_SET);



// Criando uma tabela hash para a frequencia dos arquivos

    HashTable* ht = createHashtable(tamanho);
    unsigned char frequencia;

    fread(&frequencia, sizeof(unsigned char), 1, arquivo);
    while (!feof(arquivo))
    {
        //printf("%c\n",frequencia);
        putFrequencia(ht,frequencia,tamanho);
        fread(&frequencia, sizeof(unsigned char), 1, arquivo);
    }

    //print_hash_table(ht, tamanho);


 // Criando a Fila de Prioridade;
    Heap* fp = create_heap(tamanho);

    //Passando a Frequencia para a Fila de prioridade
    hash_Para_Fila(ht,tamanho,fp);
    //Chamo o heapSort para deixar a heep ordenada.
    heapsort(fp);




    liberaHash(ht);
    //libera_FilaPrio(fp);

   printf("FIM DA COMPRESSAO!\n");
}
