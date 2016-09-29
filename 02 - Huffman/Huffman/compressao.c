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

    HashTable* hashT = createHashtable(tamanho);
    unsigned char frequencia;

    fread(&frequencia, sizeof(unsigned char), 1, arquivo);
    while (!feof(arquivo))
    {
        //printf("%c\n",frequencia);
        putFrequencia(hashT,frequencia,tamanho);
        fread(&frequencia, sizeof(unsigned char), 1, arquivo);
    }

    //print_hash_table(ht, tamanho);





// Criando a Fila de Prioridade;
    FilaPrio* filaP = create_fila_priori(tamanho);

    //Passando a Frequencia para a Fila de prioridade
    hash_Para_Fila(hashT,tamanho,filaP);

    //Cria a arvore
    create_tree(filaP);

    //Passa para a hash os newkey
    hasharvore(filaP,hashT);

 // Cabeçalho Huffman


   //Tamanho da Arvore
   unsigned int sizetree = PrioTree(filaP) ;


   //Tamanho do Lixo
   unsigned int trash;




    liberaHash(hashT);
    //libera_FilaPrio(fp);

   printf("FIM DA COMPRESSAO!\n");
}
