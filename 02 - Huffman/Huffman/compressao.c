#include <stdlib.h>
#include <stdio.h>
#include "compressao.h"
#include "fila_prioridade.h"
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
    FilaPrio* fp = create_fila_priori(tamanho);

    //Passando a Frequencia para a Fila de prioridade
    hash_Para_Fila(ht,tamanho,fp);

    print_fila_priori(fp);
    printf("\n\n");
    create_tree(fp);







 // Cabeçalho Huffman

    //Tamanho do Lixo
    unsigned int trash;

    //Tamanho do Arvore
    unsigned int sizetree ;
    //printf("%d\n",sizetree);









    liberaHash(ht);
    //libera_FilaPrio(fp);

   printf("FIM DA COMPRESSAO!\n");
}
