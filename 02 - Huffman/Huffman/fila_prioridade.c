#include <stdlib.h>
#include <stdio.h>
#include "fila_prioridade.h"
#include "hash.h"

struct node {
    unsigned char item;
    unsigned int prio;
    Node *left;
    Node *right;
};

struct fila_prioridade{
    unsigned int qtd, size;
    Node **dados;
};

FilaPrio* create_fila_priori(unsigned int SIZE){
    FilaPrio* fp = (FilaPrio*) malloc(sizeof(FilaPrio));
    if(fp != NULL){
         unsigned int i;
         fp->qtd =SIZE ;
         fp->size = 0;
         fp->dados = (struct Node**) malloc(SIZE * sizeof(struct Node*));
         if(fp->dados == NULL){
            free(fp);
            return NULL;
         }

         for(i=1; i <= SIZE; i++){
           fp->dados[i] = NULL;
         }
     }

   return fp;
}

unsigned char value_of(FilaPrio *fp, unsigned int i){
    return fp->dados[i]->item;
}

unsigned int Size_fila_priori(FilaPrio *fp){
   return fp->size;
}



void enqueue(FilaPrio *fp,unsigned char carac,unsigned int value){
    if (fp->size > fp->qtd) {
        printf("Heap is full!");
    } else {
        Node *new_Node = (Node*) malloc(sizeof(Node));
        new_Node->item = carac;
        new_Node->prio = value;
        new_Node->left = NULL;
        new_Node->right = NULL;
        fp->size ++;
        fp->dados[fp->size] = new_Node;
        //printf("Inserindo %c  %d\n",heap->dados[heap->size]->item, heap->dados[heap->size]->prio );
        //Ordeno a heap com o novo valor
        sort_fila_priori(fp);

    }
}



 Node* dequeue(FilaPrio *fp){

    /* Para Remover o elemento de maior valor
    Node* value = heap->dados[1];
    heap->dados[1] = heap->dados[heap->size];
    heap->size--;
    max_heapify(heap, 1);    
    */
    //Removendo o item de menor valor
    Node* value = fp->dados[fp->size];
    fp->size--;
    return value;
}


void sort_fila_priori(FilaPrio *fp){

    unsigned int tamanho = fp->size;

    //Ordeno
    if(tamanho > 1){

        while(tamanho > 1 && fp->dados[tamanho]->prio > fp->dados[tamanho - 1]->prio ){
            Node* temp = fp->dados[tamanho];
            fp->dados[tamanho] = fp->dados[tamanho-1];
            fp->dados[tamanho-1] = temp;
            tamanho--;
        }

        if(tamanho>1){
            if(fp->dados[tamanho]->prio == fp->dados[tamanho-1]->prio){
                unsigned int compara1 = fp->dados[tamanho]->item ;
                unsigned int compara2 = fp->dados[tamanho-1]->item;
               if( compara1 < compara2 ){
                  Node* temp = fp->dados[tamanho];
                  fp->dados[tamanho] = fp->dados[tamanho-1];
                  fp->dados[tamanho-1] = temp;
               }

             }
        }
    }
}




void print_fila_priori(FilaPrio* fp){
   if(fp == NULL)
        return;
   unsigned int i;
   for(i=1; i <= fp->size ; i++){
      printf("%d) Prio: %d \tNome: %c\n",i,fp->dados[i]->prio,fp->dados[i]->item);
   }
}


void create_tree(FilaPrio *fp){
    unsigned int tamanho = fp->size;

    if(tamanho > 0){
       Node* temp = (Node*) malloc(sizeof(Node));;
       if(tamanho > 2){
           temp->prio = fp->dados[tamanho]->prio + fp->dados[tamanho-1]->prio;
           temp->item = '*';
           temp->left = fp->dados[tamanho];
           temp->right = fp->dados[tamanho-1];
           fp->size--;
           //Insere o NO na fila de prioridade
           fp->dados[fp->size] = temp;

          //Ordeno os dados
           sort_fila_priori(fp);

          // Chamo a função para acriar a arvore
          create_tree(fp);

       }else{
          if(tamanho > 1){
              temp->prio = fp->dados[tamanho]->prio + fp->dados[tamanho-1]->prio;
              temp->item = '*';
              temp->left = fp->dados[tamanho];
              temp->right = fp->dados[tamanho-1];
              fp->size--;
              fp->dados[fp->size] = temp;

          }
       }
       free(temp);
    }

}



//VERIFICA SE O ELEMENTO DO TIPO NODE E VAZIO
unsigned int ispEmpty(Node *first){
    return (first == NULL);
}


// CALCULA A QUANTIDADE DE ELEMENTOS QUE TEM NA ARVORE
unsigned int sizeTree(Node *first){
    unsigned int qt = 0;
    if(!ispEmpty(first)){
        qt = 1;
        qt += sizeTree(first->left) + sizeTree(first->right);
    }
    return qt;
}

// CALCULA A QUANTIDADE DE ELEMENTOS QUE TEM NA ARVORE
unsigned int PrioTree(FilaPrio *first){

   return sizeTree(first->dados[1]);

}



//Pasando a referencia dos bytes

//ADICIONA O CAMINHO DA FOLHA NA HASHTABLE
void hashvalue(Node* first, unsigned int posi, HashTable *ht, unsigned char *bitschar){
    if(!ispEmpty(first)){

        if((first->left==NULL )&& (first->right==NULL)){
            int i;
            unsigned char frase[posi];
            for(i=0;i<posi;i++){
                frase[i]=bitschar[i];
            }
            frase[posi]='\0';
            putNewkey(ht,  first->item , frase,  tableSize(ht));

        }else{

            int lef = posi;
            bitschar[lef]='0';
            lef++;
            hashvalue(first->left, lef, ht , bitschar);

            int rig = posi;
            bitschar[rig]='1';
            rig++;
            hashvalue(first->right, rig, ht , bitschar);
         }
    }
}

void hasharvore(FilaPrio *first, HashTable *ht){

    int posi=0;
    char bitschar[8192] ;
    hashvalue(first->dados[1], posi, ht, bitschar);
}












