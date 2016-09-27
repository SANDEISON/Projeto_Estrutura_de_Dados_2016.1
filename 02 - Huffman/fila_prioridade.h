typedef struct node Node;
typedef struct heap Heap;

Heap* create_heap(unsigned int SIZE);

unsigned int get_parent_index(Heap *heap, unsigned int i);

unsigned int get_left_index(Heap *heap, unsigned int i);

unsigned int get_right_index(Heap *heap, unsigned int i);

unsigned char value_of(Heap *heap, unsigned int i);

void enqueue(Heap *heap, unsigned char carac, unsigned int value);

Node *dequeue(Heap *heap);

void max_heapify(Heap *heap, unsigned int i);

void heapsort(Heap *heap);

void printHeap(Heap* heap);
