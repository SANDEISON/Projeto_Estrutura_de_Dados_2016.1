#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "fila_prioridade.h"



struct element {
  unsigned char key;
  unsigned int value;
  Element *next_element;
};

struct hashtable {
  int TABLE_SIZE;
  struct Element **table;
};

unsigned int hash(unsigned char key, unsigned int TABLE_SIZE) {
  return key % TABLE_SIZE;
}

HashTable* createHashtable(unsigned int TABLE_SIZE){
  HashTable* ht = (HashTable*) malloc(sizeof(HashTable));
  if(ht != NULL){
   unsigned int i;
   ht->TABLE_SIZE = TABLE_SIZE;
   ht->table = (struct Element**) malloc(TABLE_SIZE * sizeof(struct Element*));
   if(ht->table == NULL){
      free(ht);
      return NULL;
   }

   for(i=0; i < TABLE_SIZE; i++)
     ht->table[i] = NULL;
   }
   return ht;

}


void liberaHash(HashTable* ht){
    if(ht != NULL){
        unsigned int i;
        for(i=0; i < ht->TABLE_SIZE ; i++){
            if(ht->table[i] != NULL)
                free(ht->table[i]);
        }
        free(ht->table);
        free(ht);
    }
}


void putFrequencia(HashTable *ht, unsigned char key, unsigned int t) {
  unsigned int h = hash(key, t);
  if(ht->table[h] != NULL) {
    int veri = 0;
    Element *element = ht->table[h];
    while(element != NULL) {
      if(element->key == key){
         element->value+=1;
         veri = 1;
         break;
      }

      element = element->next_element;
    }

    if(!veri){
      Element *new_element = (Element*) malloc(sizeof(Element));
      new_element->key = key;
      new_element->value = 1;
      new_element->next_element = NULL;
      new_element->next_element = ht->table[h];
      ht->table[h] = new_element;

    }
  }else{

    Element *new_element = (Element*) malloc(sizeof(Element));
    new_element->key = key;
    new_element->value = 1;
    new_element->next_element = NULL;
    ht->table[h] = new_element;
  }
}


char get(HashTable *ht, unsigned char key, unsigned int t) {
  unsigned int h = hash(key, t);

  if(ht->table[h] != NULL) {
    Element *element = ht->table[h];

    while(element != NULL) {
      if(element->key == key) return element->value;

      element = element->next_element;
    }
  }

  return NULL;
}



void delet(HashTable *ht, unsigned char key, unsigned int t) {
  unsigned int h = hash(key, t);

  if(ht->table[h] != NULL) {
    Element *element = ht->table[h];
    Element *prev_element;

    while(element != NULL && element->key != key) {
      prev_element = element;
      element = element->next_element;
    }

    if(element != NULL) {
      if(prev_element == NULL) ht->table[h] = element->next_element;
      else prev_element->next_element = element->next_element;
    }

    free(element);
  }
}




unsigned int contains_key(HashTable *ht, unsigned char key, unsigned int t) {
  unsigned int h = hash(key, t);

  if(ht->table[h] != NULL) {
    Element *element = ht->table[h];

    while(element != NULL) {
      if(element->key == key) return 1;

      element = element->next_element;
    }
  }

  return 0;
}



void print_elements(Element *element) {
  if(element == NULL) return;

  printf("%c - %d  ", element->key, element->value);

  print_elements(element->next_element);
}

void print_hash_table(HashTable *ht, unsigned int TABLE_SIZE) {
  unsigned int i;

  for(i = 0; i < TABLE_SIZE; ++i) {
    if(ht->table[i] != NULL){
        print_elements(ht->table[i]);
        printf("\n");
    }

  }
}



void elements_Para_Fila(Element *element, Fila* fp) {
    if(element != NULL){
      //printf("%c - %d  ", element->key, element->value);
      insere_FilaPrio(fp, element->key, element->value);
      elements_Para_Fila(element->next_element,fp);
    }
}



void hash_Para_Fila(HashTable *ht , unsigned int TABLE_SIZE , Fila *fp){
    unsigned int i;

    for(i = 0; i < TABLE_SIZE; ++i) {
      if(ht->table[i] != NULL){
          elements_Para_Fila(ht->table[i],fp);
      }
    }
}
