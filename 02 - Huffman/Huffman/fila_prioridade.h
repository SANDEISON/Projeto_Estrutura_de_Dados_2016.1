typedef struct node Node;
typedef struct fila_prioridade FilaPrio;

FilaPrio* create_fila_priori(unsigned int SIZE);

unsigned char value_of(FilaPrio *heap, unsigned int i);

unsigned int Size_fila_priori(FilaPrio *heap);

void enqueue(FilaPrio *heap, unsigned char carac, unsigned int value);

Node *dequeue(FilaPrio *heap);

void sort_fila_priori(FilaPrio *heap);

void print_fila_priori(FilaPrio* heap);

void create_tree(FilaPrio *heap);
