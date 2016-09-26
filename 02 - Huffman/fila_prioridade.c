#include <stdlib.h>
#include <stdio.h>
#include <fila_prioridade.h>

struct node {
    unsigned int item;
    unsigned int prio;
    Node *next;
    Node *left;
    Node *right;
};

struct fila_prioridade{
    unsigned int qtd;
    Node **dados;
};

FilaPrio* cria_FilaPrio(unsigned int SIZE){
    FilaPrio* fp = (FilaPrio*) malloc(sizeof(FilaPrio));
    if(fp != NULL){
         unsigned int i;
         fp->dados = (struct Node**) malloc(SIZE * sizeof(struct Node*));

         if(fp->dados == NULL){
            free(fp);
            return NULL;
         }
         for(i=0; i < SIZE; i++)
           fp->dados[i] = NULL;
     }
     return fp;
}

void libera_FilaPrio(FilaPrio* fp){
    if(fp == NULL || fp->qtd > 0){
     free(fp);
    }
}



