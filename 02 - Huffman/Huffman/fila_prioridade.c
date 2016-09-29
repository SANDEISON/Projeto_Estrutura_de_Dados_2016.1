#include <stdlib.h>
#include <stdio.h>
#include <fila_prioridade.h>

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

unsigned char value_of(FilaPrio *heap, unsigned int i){
    return heap->dados[i]->item;
}

unsigned int Size_fila_priori(FilaPrio *heap){
   return heap->size;
}



void enqueue(FilaPrio *heap,unsigned char carac,unsigned int value){
    if (heap->size > heap->qtd) {
        printf("Heap is full!");
    } else {
        Node *new_Node = (Node*) malloc(sizeof(Node));
        new_Node->item = carac;
        new_Node->prio = value;
        new_Node->left = NULL;
        new_Node->right = NULL;
        heap->size ++;
        heap->dados[heap->size] = new_Node;
        //printf("Inserindo %c  %d\n",heap->dados[heap->size]->item, heap->dados[heap->size]->prio );
        //Ordeno a heap com o novo valor
        sort_fila_priori(heap);

    }
}



 Node* dequeue(FilaPrio *heap){

    /* Para Remover o elemento de maior valor
    Node* value = heap->dados[1];
    heap->dados[1] = heap->dados[heap->size];
    heap->size--;
    max_heapify(heap, 1);    
    */
    //Removendo o item de menor valor
    Node* value = heap->dados[heap->size];
    heap->size--;
    return value;
}


void sort_fila_priori(FilaPrio *heap){

    unsigned int tamanho = heap->size;

    //Ordeno
    if(tamanho > 1){

        while(tamanho > 1 && heap->dados[tamanho]->prio > heap->dados[tamanho - 1]->prio ){
            Node* temp = heap->dados[tamanho];
            heap->dados[tamanho] = heap->dados[tamanho-1];
            heap->dados[tamanho-1] = temp;
            tamanho--;
        }

        if(tamanho>1){
            if(heap->dados[tamanho]->prio == heap->dados[tamanho-1]->prio){
                unsigned int compara1 = heap->dados[tamanho]->item ;
                unsigned int compara2 = heap->dados[tamanho-1]->item;
               if( compara1 < compara2 ){
                  Node* temp = heap->dados[tamanho];
                  heap->dados[tamanho] = heap->dados[tamanho-1];
                  heap->dados[tamanho-1] = temp;
               }

             }
        }
    }
}




void print_fila_priori(FilaPrio* heap){
   if(heap == NULL)
        return;
   unsigned int i;
   for(i=1; i <= heap->size ; i++){
      printf("%d) Prio: %d \tNome: %c\n",i,heap->dados[i]->prio,heap->dados[i]->item);
   }
}






void create_tree(FilaPrio *heap){
    unsigned int tamanho = heap->size;

    if(tamanho > 0){
       Node* temp = (Node*) malloc(sizeof(Node));;
       if(tamanho > 2){
           temp->prio = heap->dados[tamanho]->prio + heap->dados[tamanho-1]->prio;
           temp->item = '*';
           temp->left = heap->dados[tamanho];
           temp->right = heap->dados[tamanho-1];
           heap->size--;
           //Insere o NO na fila de prioridade
           heap->dados[heap->size] = temp;

          //Ordeno os dados
           sort_fila_priori(heap);

          // Chamo a função par acriar a arvore
          create_tree(heap);

       }else{
          if(tamanho > 1){
              temp->prio = heap->dados[tamanho]->prio + heap->dados[tamanho-1]->prio;
              temp->item = '*';
              temp->left = heap->dados[tamanho];
              temp->right = heap->dados[tamanho-1];
              heap->size--;
              heap->dados[heap->size] = temp;

              print_fila_priori(heap);
              printf("Fim da Arvore * \n\n");
          }
       }
       free(temp);
    }

}
