typedef struct hashtable HashTable;
typedef struct element Element;

HashTable* criaTabela(unsigned int TABLE_SIZE);
void liberaHash(HashTable *ht);
void putFrequencia(HashTable *ht, unsigned char key, unsigned int t);
char get(HashTable *ht, unsigned char key, unsigned int t);
void delet(HashTable *ht, unsigned char key, unsigned int t);
unsigned int contains_key(HashTable *ht, unsigned char key, unsigned int t);
void print_elements(Element *element) ;
void print_hash_table(HashTable *ht,unsigned int TABLE_SIZE);



