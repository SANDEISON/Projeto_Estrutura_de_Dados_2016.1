typedef struct hashtable HashTable;
typedef struct element Element;
typedef struct FilaPrio Fila;

HashTable* criaTabela(unsigned int TABLE_SIZE);
unsigned int tableSize(HashTable* ht) ;
void liberaHash(HashTable *ht);
void putFrequencia(HashTable *ht, unsigned char key, unsigned int t);
void putNewkey(HashTable *ht, unsigned char key1 , unsigned char *newkey, unsigned int t) ;
char get(HashTable *ht, unsigned char key, unsigned int t);
void delet(HashTable *ht, unsigned char key, unsigned int t);
unsigned int contains_key(HashTable *ht, unsigned char key, unsigned int t);
void print_elements(Element *element) ;
void print_hash_table(HashTable *ht,unsigned int TABLE_SIZE);

void hash_Para_Fila(HashTable *ht , unsigned int TABLE_SIZE ,Fila* fp);



