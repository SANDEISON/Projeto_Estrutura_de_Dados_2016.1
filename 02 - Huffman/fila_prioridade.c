#include <stdlib.h>
#include <stdio.h>
#include <fila_prioridade.h>

struct node {
    unsigned char item;
    unsigned int prio;
    Node *next;
    Node *left;
    Node *right;
};

struct fila_prioridade{
    unsigned int qtd, FP_SIZE;
    Node **dados;
};

FilaPrio* cria_FilaPrio(unsigned int SIZE){
    FilaPrio* fp = (FilaPrio*) malloc(sizeof(FilaPrio));
    if(fp != NULL){
         unsigned int i;
         fp->qtd = 0;
         fp->FP_SIZE = SIZE;
         fp->dados = (struct Node**) malloc(SIZE * sizeof(struct Node*));
         if(fp->dados == NULL){
            free(fp);
            return NULL;
         }

         for(i=0; i < SIZE; i++){
           fp->dados[i] = NULL;
         }
     }

   return fp;
}

void libera_FilaPrio(FilaPrio* fp){
    if(fp == NULL || fp->qtd > 0){
     free(fp);
    }
}



void ordenaFila(FilaPrio* fp, unsigned int filho){
    unsigned int pai;
    Node* temp;
    pai = (filho - 1) / 2;
    while((filho > 0) && (fp->dados[pai]->prio <= fp->dados[filho]->prio)){
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;
        filho = pai;
        pai = (pai - 1) / 2;
    }
}


void insere_FilaPrio(FilaPrio* fp, unsigned char BYTE, unsigned int prioridade){

    Node *new_Node = (Node*) malloc(sizeof(Node));
    new_Node->item = BYTE;
    new_Node->prio = prioridade;
    new_Node->next = NULL;
    new_Node->left = NULL;
    new_Node->right = NULL;

    /* insere na primeira posição livre */
    fp->dados[fp->qtd] = new_Node;
    /* desloca elemento para posição correta */
    ordenaFila(fp,fp->qtd);
    /* incrementa número de elementos na heap */
    fp->qtd++;

}


void imprime_FilaPrio(FilaPrio* fp){
   if(fp == NULL)
        return;
   unsigned int i;
    for(i=0; i < fp->qtd ; i++){
        printf("%d) Prio: %d \tNome: %c\n",i,fp->dados[i]->prio,fp->dados[i]->item);
    }
}
