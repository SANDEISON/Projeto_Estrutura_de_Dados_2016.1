/*cp.h*/

/**
* Arvore Binaria */
typedef struct BinaryTree Binarytree;

/**
* Cria um nó novo para inserir na arvore binaria*/
Binarytree* createNewNode(int value);

/**
* Insere o nó novo na arvore binaria passada com argumento */
Binarytree* insertNode(Binarytree *bt, Binarytree *newNode);

/**
* imprime a arvore binaria em pre-ordem */
void printBinaryTree(Binarytree *bt);

/**
* procura o valor desejado no na arvore e retorna o numeros de
* comparacoes realizadas */
int searchNode (Binarytree *bt, int value, int *x);





