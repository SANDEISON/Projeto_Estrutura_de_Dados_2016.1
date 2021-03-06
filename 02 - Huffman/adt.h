typedef struct node node;
typedef struct pnode pnode;
//FUNCTIONS
//NODE
/**
 * DEF: INICIA UMA VARIAVEL DO TIPO NODE
 *
 * @return NULL
 */
node *createnode();
/**
 * DEF: VERIFICA SE UMA VARIAVEL DO TIPO NODE EH VAZIA
 *
 * @param first --- VARIAVEL DO TIPO NODE A SER VERIFICADA
 * @return INT --- O RETORNO SERA VERDADEIRO SE A VARIAVEL FOR VAZIA
 */
int isEmpty(node *first);
/**
 * DEF: INSERE UMA VARIAVEL DO TIPO NODE EM UMA LISTA DE NODES
 *
 * @param first --- CABECA DA LISTA
 * @param value --- VALOR DO TIPO INT PARA SER ADICIONADO NA LISTA
 * @param character --- VALOR DO TIPO UNSIGNED CHAR PARA SER ADICIONADO NA LISTA
 * @return NODE --- RETORNA A CABECA DA LISTA
 */
node *insertnode( node *first, int value, unsigned char character );
/**
 * DEF: IMPRIME UMA LISTA DO TIPO NODE
 *
 * @param first --- CABECA DA LISTA
 * @return VOID
 */
void printlist(node *first);
//EndNODE
//PNODE
/**
 * DEF: INICIA UMA VARIAVEL DO TIPO PNODE
 *
 * @return PNODE
 */
pnode *startpnode();
/**
 * DEF: CRIA UMA VARIAVEL DO TIPO PNODE
 *
 * @param value --- VALOR DO TIPO INT PARA SER ADICIONADO NA LISTA DE PRIORIDADE
 * @param character --- VALOR DO TIPO CHAR PARA SER ADICIONADO NA LISTA DE PRIORIDADE
 * @param left --- PONTEIRO PARA UMA VARIAVEL DO TIPO PNODE
 * @param right --- PONTEIRO PARA UMA VARIAVEL DO TIPO PNODE
 * @return PNODE --- RETORNA A CABECA DA LISTA DE PRIORIDADE
 */
pnode *createpnode(int value, char character, pnode *left, pnode *right);
/**
 * DEF: VERIFICA SE O ELEMENTO DO TIPO PNODE EH VAZIO
 *
 * @param first --- ELEMENTO A SER VERIFICADO
 * @return INT --- O RETORNO SERA VERDADEIRO SE A VARIAVEL FOR VAZIA
 */
int ispEmpty(pnode *first);
/**
 * DEF: INSERE UM PNODE EM UMA FILA DE PRIORIDADE
 *
 * @param first --- CABECA ATUAL DA LISTA
 * @param insert --- PNODE A SER INSERIDO
 * @return PNODE --- RETORNA A NOVA CABECA DA LISTA
 */
pnode *insertpnode( pnode *first, pnode *insert );
/**
 * DEF: CALCULA A ALTURA DE UMA ARVORE DO TIPO PNODE
 *
 * @param root ---
 * @return INT ---
 */
int h_tree(pnode *root);
/**
 * DEF: CRIA UMA LISTA DE PRIORIDADE DO TIPO PNODE A PARTIR DE UMA LISTA DO TIPO INT
 *
 * @param p --- CABECA DA LISTA DO TIPO INT
 * @return PNODE --- RETORNA A CABECA DE UMA LISTA DE PRIORIDADE DO TIPO PNODE
 */
pnode *plista(int *p);
//EndPNODE
//HUFFMAN_TREE
/**
 * DEF: CRIA UMA ARVORE DE HUFFMAN(RECURSIVA)
 *
 * @param first --- CABECA DA LISTA DE PRIORIDADE DO TIPO PNODE
 * @return PNODE --- RETORNA A RAIZ DA ARVORE
 */
pnode *makeHtree(pnode *first);
/**
 * DEF: VERIFICA SE O NO DA ARVORE EH UMA FOLHA
 *
 * @param root --- NO A SER VERIFICADO
 * @return INT --- RETORNA VERDADEIRO CASO SEJA UMA FOLHA
 */
int isLeaf(pnode *root);
/**
 * DEF: IMPRIME NA TELA UMA ARVORE(RECURSIVA)
 * @param root --- RAIZ DA ARVORE
 * @return VOID
 */
void printHtree(pnode *root);
/**
 * DEF: IMPRIME NO ARQUIVO UMA ARVORE DE HUFFMAN DO TIPO PNODE
 *
 * @param Writeoutput --- ARQUIVO QUE RECEBERA A ARVORE
 * @param root --- RAIZ DA ARVORE
 * @return VOID
 */
void putHtree(FILE *Writeoutput, pnode *root);
/**
 * DEF: CALCULA A QUANTIDADE DE ELEMENTOS QUE TEM NA ARVORE
 *
 * @param root --- RAIZ DA ARVORE
 * @return INT --- RETORNA A QUANTIDADE DE NOS DA ARVORE
 */
int qtnodes(pnode *root);
//EndHUFFMAN_TREE
//HASH
/**
 * DEF: ADICIONA O CAMINHO DA FOLHA NA HASHTABLE
 *
 * @param first --- RAIZ DA ARVORE
 * @param posi --- INDICE NA TABELA
 * @param h --- PONTEIRO PARA UMA HASHTABLE
 * @param bitschar -- CAMINHO
 * @return VOID
 */
void hashvalue(pnode *first, int posi, char **h, char *bitschar);
/**
 * DEF: CRIA UMA HASHTABLE COM OS CAMINHOS DE SUAS RESPECTIVAS FOLHAS
 *
 * @param first --- RAIZ DA ARVORE
 * @return CHAR** --- RETORNA UMA HASHTRABLE(MATRIZ)
 */
char **hasharvore(pnode* first);

//TEMPFUNCTIONS
/**
 * DEF: CRIA UM ARQUIVO TEMPORARIO(temp.txt)
 *
 * @param f --- ARQUIVO QUE ESTA SENDO COMPRIMIDO
 * @param hash --- TABELA(MATRIZ) COM TODOS OS CAMINHOS DAS FOLHAS DA ARVORE
 * @return VOID
 */
void maketempfile(FILE *f, char **hash);
/**
 * DEF: CALCULA O LIXO E COLOCA NO ARQUIVO TEMPORARIO(temp.txt)
 *
 * @return INT --- RETORNA O LIXO
 */
int getnputtempTrash();
/**
 * DEF: COLOCA O TAMANHO DA ARVORE NO ARQUIVO TEMPORARIO(temp.txt)
 *
 * @param qt --- QUANTIDADE DE ELEMENTOS DA ARVORE
 * @return VOID
 */
void puttempSize(int qt);
/**
 * DEF: COMPLETA O ARQUIVO TEMPORARIO COM OS BITS DE LIXO
 *
 * @param QUANTIDADE DE LIXO
 * @return VOID
 */
void completetempfile(int trash);
//EndTEMPFUNCTIONS
//HEADER
/**
 * DEF: OBTEM OS 8 PRIMEIROS BITS(8 PRIMEIROS CHARS) DO ARQUIVO TEMPORARIO(temp.txt) E IMPRIME O CHAR CORRESPONDENTE AOS 8 BITS NO HEADER DO ARQUIVO COMPRIMIDO
 *
 * @param Writeoutput --- ARQUIVO COMPRIMIDO
 * @return VOID
 */
void getnputfirstbyte(FILE *Writeoutput);
/**
 * DEF: OBTEM O SEGUNDO CHAR(8 BYTES) DO ARQUIVO TEMPORARIO)(temp.txt) E IMPRIME O CHAR CORRESPONDENTE AOS 8 BITS NO HEADER DO ARQUIVO COMPRIMIDO
 *
 * @param Writeoutput --- ARQUIVO COMPRIMIDO
 * @return VOID
 */
void getnputsecondbyte(FILE *Writeoutput);
/**
 * DEF: IMPRIME OS BITS COMPRIMIDOS CORRESPONDENTES AOS BITS DO ARQUIVO A SER COMPRIMIDO NO ARQUIVO DE SAIDA.
 *
 * @param Writeoutput --- ARQUIVO COMPRIMIDO
 * @return VOID
 */
void putcodification(FILE *Writeoutput);
/**
 * DEF: FAZ UM ARQUIVO COMPRIMIDO QUE REPRESENTARA O ARQUIVO QUE FOI SELECIONADO PARA SER COMPRIMIDO
 *
 * @param filename --- NOME DO ARQUIVO SELECIONADO PARA SER COMPRIMIDO
 * @param root --- RAIZ DA ARVORE DE HUFFMAN
 * @return VOID
 */
void makeOutputfile(char *filename, pnode *root);


//EndHEADER
//DESCOMPRESS
/**
 * DEF: OBTEM O LIXO DO ARQUIVO A SER DESCOMPRIMIDO
 *
 * @param f --- ARQUIVO A SER DESCOMPRIMIDO
 * @return INT --- RETORNA O TAMANHO DO LIXO
 */
int givemethetrash(FILE *f);
/**
 * DEF: OBTEM O TAMANHO DA ARVORE DO ARQUIVO A SER DESCOMPRIMIDO
 *
 * @param f --- ARQUIVO A SER DESCOMPRIMIDO
 * @return INT --- RETORNA O TAMANHO DA ARVORE
 */
int givemethesizeTree(FILE *f);
/**
 * DEF: OBTEM A ARVORE DO ARQUIVO A SER DESCOMPRIMIDO(RECURSIVA)
 *
 * @param f --- ARQUIVO A SER DESCOMPRIMIDO
 * @param sizeTree --- TAMANHO DA ARVORE
 * @return PNODE --- RETORNA A ARVORE DO ARQUIVO A SER DESCOMPRIMIDO
 */
pnode *givemeHtree(FILE *f, int *sizeTree);
/**
 * DEF: INICIA A DESCOMPRESSAO DO ARQUIVO
 *
 * @param f --- ARQUIVO A SER DESCOMPRIMIDO
 * @param Writeoutput --- ARQUIVO DESCOMPRIMIDO
 * @param huff --- ARVORE DE HUFFMAN
 * @paran trash --- LIXO DO ARQUIVO
 * @return VOID
 */
void makedescompressOutputfile(FILE *f, FILE *Writeoutput, pnode *huff, int trash, int sizeTree);
//EndDESCOMPRESS
//EndFUNCTIONS

