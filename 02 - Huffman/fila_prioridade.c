#include <stdlib.h>
#include <stdio.h>
#include <fila_prioridade.h>

struct node {
    unsigned char item;
    unsigned int prio;
    Node *left;
    Node *right;
};

struct heap{
    unsigned int qtd, size;
    Node **dados;
};

Heap* create_heap(unsigned int SIZE){
    Heap* fp = (Heap*) malloc(sizeof(Heap));
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




unsigned int get_parent_index(Heap *heap, unsigned int i){
  return i/2;
}

unsigned int get_left_index(Heap *heap, unsigned int i){
    return 2*i;
}

unsigned int get_right_index(Heap *heap, unsigned int i){
    return 2*i + 1;
}

unsigned char value_of(Heap *heap, unsigned int i){
    return heap->dados[i]->item;
}

void enqueue(Heap *heap,unsigned char carac,unsigned int value){
    if (heap->size > heap->qtd) {
        printf("Heap is full!");
    } else {

        Node *new_Node = (Node*) malloc(sizeof(Node));
        new_Node->item = carac;
        new_Node->prio = value;
        new_Node->left = NULL;
        new_Node->right = NULL;

        heap->dados[++heap->size] = new_Node;
        unsigned int key_index = heap->size;
        unsigned int parent_index = get_parent_index(heap, heap->size);
        Node* temp;
        while (parent_index >= 1 &&  heap ->dados[key_index] > heap->dados[parent_index]) {
           temp = heap->dados[key_index];
           heap->dados[key_index] = heap->dados[parent_index];
           heap->dados[parent_index] = temp;
           key_index = parent_index;
           parent_index = get_parent_index(heap, key_index);
     }

    }
}

void printHeap(Heap* heap){
   if(heap == NULL)
        return;
   unsigned int i;
   for(i=1; i <= heap->size ; i++){
      printf("%d) Prio: %d \tNome: %c\n",i,heap->dados[i]->prio,heap->dados[i]->item);
   }
}

 Node* dequeue(Heap *heap){
    Node* value = heap->dados[1];
    heap->dados[1] = heap->dados[heap->size];
    heap->size--;
    max_heapify(heap, 1);
    return value;
}


void max_heapify(Heap *heap, unsigned int i){
    unsigned int largest;

    unsigned int left_index = get_left_index(heap, i);

    unsigned int right_index = get_right_index(heap, i);

    if (left_index <= heap->size && heap->dados[left_index] > heap->dados[i]) {
        largest = left_index;
    } else {
        largest = i;
    }

    if (right_index <= heap->size && heap->dados[right_index] > heap->dados[largest]) {
       largest = right_index;
    }

    if (heap->dados[i] != heap->dados[largest]) {
        Node* temp;
        temp = heap->dados[largest];
        heap->dados[largest] = heap->dados[i];
        heap->dados[i] = temp;
        max_heapify(heap, largest);
    }
}


void heapsort(Heap *heap){
    unsigned int i;
    for (i = heap->size; i >= 2; i--) {
      Node* temp;
      temp = heap->dados[1];
      heap->dados[1] = heap->dados[i];
      heap->dados[i] = temp;
      heap->size--;
      max_heapify(heap, 1);
   }
}

