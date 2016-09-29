typedef struct node Node;
typedef struct fila_prioridade FilaPrio;
typedef struct hashtable HashTable;

FilaPrio* create_fila_priori(unsigned int SIZE);

unsigned char value_of(FilaPrio *fp, unsigned int i);

unsigned int Size_fila_priori(FilaPrio *fp);

void enqueue(FilaPrio *fp, unsigned char carac, unsigned int value);

Node *dequeue(FilaPrio *fp);

void sort_fila_priori(FilaPrio *fp);

void print_fila_priori(FilaPrio* fp);

void create_tree(FilaPrio *fp);


//CRIA A ARVORE
unsigned int ispEmpty(Node *first);

unsigned int sizeTree(Node *first);

unsigned int PrioTree(FilaPrio *first);


// PASSA PARA A HASH O newkey

void hashvalue(Node* first, unsigned int posi, HashTable *ht, unsigned char *bitschar);

void hasharvore(FilaPrio *first, HashTable *ht);












