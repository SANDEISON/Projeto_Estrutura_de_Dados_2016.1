/* Lista encadeada*/
typedef struct node Node;


/**
* Cria uma Lista com valor NULL*/
Node* createLinkedList();

/**
* Verifica se o no é NULL*/
int isEmpty(Node *first);

/**
* Insere um valor na lista  passado com argumento */
Node* insertNodeList(Node *node, int item);


/**
* imprime a Lista */
void printLinkedList(Node *first);

/**
* procura o valor desejado  na lista e retorna o numeros de
* comparacoes realizadas */
int search(Node *first, int item);
