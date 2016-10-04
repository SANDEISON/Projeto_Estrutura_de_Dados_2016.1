

/**
* AVL */
typedef struct AVL AVL;


/**
* Insere um valor na arvore AVL passado com argumento */
AVL* insert( int value, AVL *tree );

/**
* procura o valor desejado  na AVL e retorna o numeros de
* comparacoes realizadas */
int searchAVL(int value, AVL *tree, int *comparacoes);


/**
* imprime a arvore AVL */
void printAVL(AVL *tree);
