#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "freq_w.h"
#include "compressao.h"
#include "adt.h"
#include "bitop.h"

#define DEBUG 1

void compress(FILE *f,  char *h){

    setlocale(LC_ALL,"");

    //Lista
    pnode *huff;
    //Tabela Hash
    char **hash;
    //Frequencia
	int *freq;
    // Tamanho da arvore e Tamanho do lixo
    int qt, trash;
    // Frequencia recebe o valor contabilzado no arquivo
	freq = freq_w(f);
    // Inicializa a Lista
    huff = startpnode();
    // Passa a frequencia para a lista
    huff = plista(freq);
    // Cria a arvore
    huff = makeHtree(huff);
    //Tamanho da arvore
    qt = qtnodes(huff);
    printf("Tamanho da arvore%d \n",qt);
    //Tabela HASH
    hash = hasharvore(huff);
    //TempFILE
    maketempfile(f, hash);
    //Recebe o tamanho do lixo,e passa para o arquivo temporario
    trash = getnputtempTrash();




    //COLOCA O TAMANHO DA ARVORE NO ARQUIVO TEMPORARIO(temp.txt)
    puttempSize(qt);
    //COMPLETA O ARQUIVO TEMPORARIO COM OS BITS DE LIXO
    completetempfile(trash);
    //COMPRESS FINAL Output
    makeOutputfile(h, huff);

    printf("FIM DA COMPRESSAO!\n");
}
