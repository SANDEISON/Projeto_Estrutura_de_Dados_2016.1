#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "adt.h"
#include "compressao.h"
#include "bitop.h"

//STRUCTS
struct node
{
    int v;
    unsigned char c;
    node *nextnode;
};

struct pnode
{
    int v;
    unsigned char c;
    pnode *nextpnode;
    pnode *left;
    pnode *right;
};
//EndSTRUCTS

//FUNCTIONS
//NODE

// INICIA UMA VARIAVEL DO TIPO NODE
node *createnode()
{
    return NULL;
}

//VERIFICA SE UMA VARIAVEL DO TIPO NODE EH VAZIA
int isEmpty(node *first)
{
    return (first == NULL);
}

// INSERE UMA VARIAVEL DO TIPO NODE EM UMA LISTA DE NODES
node *insertnode( node *first, int value, unsigned char character )
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode -> v = value;
    newnode -> c = character;
    newnode -> nextnode = first;
    return newnode;
}

//IMPRIME UMA LISTA DO TIPO NODE
void printlist(node *first)
{
    if(!isEmpty(first))
    {
        //printf("Letra %c com frequencia %d\n", first -> c, first -> v);
        printf("%d",first -> v);
        printlist(first -> nextnode);
    }
}
//EndNODE

//PNODE
//INICIA UMA VARIAVEL DO TIPO PNODE
pnode *startpnode()
{
    return NULL;
}

//VERIFICA SE O ELEMENTO DO TIPO PNODE EH VAZIO
int ispEmpty(pnode *first)
{
    return (first == NULL);
}

//CRIA UMA VARIAVEL DO TIPO PNODE
pnode *createpnode(int value, char character, pnode *left, pnode *right)
{
    pnode *aux;
    aux = (pnode*)malloc(sizeof(pnode));
    aux -> v = value;
    aux -> c = character;
    aux -> left = left;
    aux -> right = right;
    aux -> nextpnode = NULL;
    return aux;
}

//INSERE UM PNODE EM UMA FILA DE PRIORIDADE
pnode *insertpnode(pnode *first, pnode *insert)
{
    if(ispEmpty(first) || insert -> v <= first -> v)
    {
        insert -> nextpnode = first;
        return insert;
    }
    else{
        first -> nextpnode = insertpnode(first -> nextpnode, insert);
        return first;
    }
}

//CALCULA A ALTURA DE UMA ARVORE DO TIPO PNODE
int h_tree(pnode *root)
{
    if (ispEmpty(root))
    {
       return -1;
    }
    else
    {
        int h;
        int hleft;
        int hright;

        hleft = h_tree(root->left);
        hright = h_tree(root->right);
        h = hleft + 1;
        if (hleft < hright)
        {
            h = hright + 1;
        }
        return h;
    }
}

//CRIA UMA LISTA DE PRIORIDADE DO TIPO PNODE A PARTIR DE UMA LISTA DO TIPO INT
pnode *plista(int *p)
{
    int i;
    pnode *pn;
    pnode *aux;
    pn = startpnode();
    aux = startpnode();
    for( i = 0; i <= 255; i++)
    {
        if(p[i] != 0)
        {
            aux = createpnode(p[i], i, NULL, NULL);
            pn = insertpnode(pn, aux);
        }
    }
    return pn;
}

//EndPNODE
//HUFFMAN_TREE:
//CRIA UMA ARVORE DE HUFFMAN(RECURSIVA)
pnode *makeHtree(pnode *first)
{
    if(!ispEmpty(first))
    {
        int value;
        pnode *root;
        root = startpnode();
        if(!ispEmpty(first -> nextpnode))
        {
            value = (first -> v) + (first -> nextpnode -> v);
            root = createpnode( value, '*', first, first -> nextpnode);
            first = insertpnode(first -> nextpnode -> nextpnode, root);
            first = makeHtree(first);
        }
        else if(h_tree(first) == 0)
        {
            value = first -> v;
            first = createpnode( value, '*', first, first -> nextpnode);
        }
    }
    return first;
}

//VERIFICA SE O NO DA ARVORE EH UMA FOLHA
int isLeaf(pnode *root)
{
    return (ispEmpty(root -> left) && ispEmpty(root -> right));
}

//IMPRIME NA TELA UMA ARVORE(RECURSIVA)
void printHtree(pnode *root)
{
    if(!ispEmpty(root))
    {
        printf("%c",root -> c);
        printHtree(root -> left);
        printHtree(root -> right);
    }
}

//IMPRIME NO ARQUIVO UMA ARVORE DE HUFFMAN DO TIPO PNODE
void putHtree(FILE *Writeoutput, pnode *root)
{
    if(!ispEmpty(root))
    {
        if(isLeaf(root))
        {
            if(root -> c == '\\' ||  root -> c == '*')
            {
                fputc('\\', Writeoutput);
            }
        }

        fputc(root -> c, Writeoutput);
        putHtree(Writeoutput,root -> left);
        putHtree(Writeoutput,root -> right);
    }
}

// CALCULA A QUANTIDADE DE ELEMENTOS QUE TEM NA ARVORE
int qtnodes(pnode *root)
{
    int qt = 0;
    if(!ispEmpty(root))
    {
        qt = 1;
        qt += qtnodes(root -> left);
        qt += qtnodes(root -> right);
    }
    return qt;
}

//EndHUFFMAN_TREE
//HUFFMAN_HASH

//ADICIONA O CAMINHO DA FOLHA NA HASHTABLE
void hashvalue(pnode* first, int posi,char **h,char *bitschar)
{
    if(!ispEmpty(first))
    {
        if((first->left==NULL )&& (first->right==NULL))
        {
            int i, local;
            local=first->c;
            for(i=0;i<posi;i++)
            {
                h[local][i]=bitschar[i];
            }
            h[local][posi]='\0';
        }else{
            int lef = posi;
            bitschar[lef]='0';
            lef++;
            hashvalue(first->left, lef, h , bitschar);

            int rig = posi;
            bitschar[rig]='1';
            rig++;
            hashvalue(first->right, rig, h , bitschar);
         }
    }
}

//CRIA UMA HASHTABLE COM OS CAMINHOS DE SUAS RESPECTIVAS FOLHAS
char **hasharvore(pnode* first)
{
    int posi=0, i;
    char *bitschar ;
    char **has;

    bitschar = (char*)malloc(256*sizeof(char));
    pnode* no = first;
    //Aloco memoria para a has
    has = (char**)malloc(256*sizeof(char*));
    for(i=0;i<256;i++)
    {
        has[i] = (char*)malloc(256*sizeof(char));
    }

    hashvalue(no, posi, has, bitschar);
    return has;
}

//EndHUFFMAN_HASH
//TEMPFUNCTIONS

//CRIA UM ARQUIVO TEMPORARIO(temp.txt)
void maketempfile(FILE *f, char **hash)
{
    setlocale(LC_ALL,"");
    unsigned char x;
    int i;
    FILE *temp;

    temp = fopen("temp.txt","w");
    rewind(f);

    //HEADERBINARYTEMP
    for(i = 0; i < 16; i++)
    {
        fputc('0',temp);
    }
    while(1)
    {
        x = fgetc(f);
        if(feof(f))
        {
            break;
        }
        fputs(hash[x],temp);
    }
    fclose(temp);
}

//CALCULA O LIXO E COLOCA NO ARQUIVO TEMPORARIO(temp.txt)
int getnputtempTrash()
{
    int auxtrash, resto, i, trash, x = 0;
    FILE *temp;
    node *TRASHLIST;

    TRASHLIST = createnode();
    temp = fopen("temp.txt","r+");
    fseek(temp,16,SEEK_SET);
    while(fgetc(temp) != EOF)
    {
        x++;
    }
    printf("Tamanho Total %d\n", x);
    trash = 8-(x%8);
    printf("Tamanho Lixo %d\n", trash);

    if(trash == 8)
    {
        trash = 0;
    }
    auxtrash = trash;
    for(i = 0; i < 3; i++){
        resto = auxtrash%2;
        auxtrash = auxtrash/2;
        TRASHLIST = insertnode(TRASHLIST,resto,0);
    }
    fseek(temp,0,SEEK_SET);
    while(!isEmpty(TRASHLIST))
    {
        fputc('0' + TRASHLIST -> v,temp);
        TRASHLIST = TRASHLIST -> nextnode;
    }
    fclose(temp);
    return trash;
}

//COLOCA O TAMANHO DA ARVORE NO ARQUIVO TEMPORARIO(temp.txt)
void puttempSize(int qt)
{
    int i, resto;
    FILE *temp;
    node *QTLIST;

    QTLIST = createnode();
    for(i = 0; i < 13; i++)
    {
        resto = qt%2;
        qt = qt/2;
        QTLIST = insertnode(QTLIST,resto,0);
    }
    temp = fopen("temp.txt","r+");
    fseek(temp,3,SEEK_SET);
    while(!isEmpty(QTLIST))
    {
        fputc('0' + QTLIST -> v,temp);
        QTLIST = QTLIST -> nextnode;
    }
    fclose(temp);
}

//COMPLETA O ARQUIVO TEMPORARIO COM OS BITS DE LIXO
void completetempfile(int trash)
{
    FILE *temp;
    temp = fopen("temp.txt","r+");
    fseek(temp,0,SEEK_END);
    for(trash = trash; trash >= 1; trash--){
         fputc('0',temp);
    }
    fclose(temp);
}
//EndTEMPFUNCTIONS
//HEADER

//OBTEM OS 8 PRIMEIROS BITS(8 PRIMEIROS CHARS) DO ARQUIVO TEMPORARIO(temp.txt) E IMPRIME O CHAR CORRESPONDENTE AOS 8 BITS NO HEADER DO ARQUIVO COMPRIMIDO
void getnputfirstbyte(FILE *Writeoutput)
{
    int i;
    FILE *temp;
    temp = fopen("temp.txt","r");
    unsigned char ch= NULL;

    for(i = 7; i >= 0; i--){
        if(fgetc(temp) == '1'){
          // printf("IMPRIMINDO %d\n",i);
            ch = setBit(ch, i);
        }
    }
    fputc(ch,Writeoutput);
    fclose(temp);
}

//OBTEM O SEGUNDO CHAR(8 BYTES) DO ARQUIVO TEMPORARIO)(temp.txt) E IMPRIME O CHAR CORRESPONDENTE AOS 8 BITS NO HEADER DO ARQUIVO COMPRIMIDO
void getnputsecondbyte(FILE *Writeoutput){
    int i;
    FILE *temp;
    temp = fopen("temp.txt","r");
    unsigned char ch= NULL;
    fseek(temp,8,SEEK_SET);
    for(i = 7; i >= 0; i--){
        if(fgetc(temp) == '1'){
            ch = setBit(ch, i);
        }
    }
    fputc(ch,Writeoutput);
    fclose(temp);
}

//IMPRIME OS BITS COMPRIMIDOS CORRESPONDENTES AOS BITS DO ARQUIVO A SER COMPRIMIDO NO ARQUIVO DE SAIDA.
void putcodification(FILE *Writeoutput){
    FILE *temp;
    temp = fopen("temp.txt","r");

    long int size;
    int currentpos;

    currentpos = ftell(temp);
    fseek(temp,0,SEEK_END);
    size = ftell(temp);
    fseek(temp,currentpos,SEEK_SET);
    fseek(temp,16,SEEK_SET);

    while(1){
        int i, ch = 0;
        for(i = 7; i >= 0; i--){
            if(fgetc(temp) == '1'){
                ch = setBit(ch, i);
            }
        }
        fputc(ch,Writeoutput);
        if(ftell(temp) == size){
            break;
        }
    }
    fclose(Writeoutput);
    fclose(temp);
}

//FAZ UM ARQUIVO COMPRIMIDO QUE REPRESENTARA O ARQUIVO QUE FOI SELECIONADO PARA SER COMPRIMIDO
void makeOutputfile(char *filename, pnode *root){
    FILE *Writeoutput;
    strcat(filename, ".huff");
    Writeoutput = fopen(filename,"w");

    //OBTEM OS 16 PRIMEIROS BITS DO ARQUIVO TEMPORARIO E COLOCA OS CHARS EQUIVALENTES NO CONTEUDO DO PONTEIRO Writeoutput
    getnputfirstbyte(Writeoutput);
    getnputsecondbyte(Writeoutput);
    //END
    //COLOCA A REPRESENTACAO DA ARVORE NO ARQUIVO.HUFF
    putHtree(Writeoutput, root);
    //
    putcodification(Writeoutput);
    remove("temp.txt");
    fclose(Writeoutput);

}
//EndHEADER
//DESCOMPRESS



//Retorna o tamanho do lixo
int givemethetrash(FILE *f){
    int i;
    unsigned char ch, trash=NULL;
    fseek(f,0,SEEK_SET);
    ch = fgetc(f);
    for(i = 5; i <=7; i++){
        if(isBitISet(ch,i) > 0){
            trash = setBit(trash, i-5);
        }
    }
    return trash;
}



//OBTEM O TAMANHO DA ARVORE DO ARQUIVO A SER DESCOMPRIMIDO
int givemethesizeTree(FILE *f){
    int i;
    unsigned char ch , sizeTree = NULL, aux= NULL;
    fseek(f,0,SEEK_SET);
    ch = fgetc(f);
    for(i = 0; i <= 4; i++){
        if(isBitISet(ch,i) > 0){
            aux = setBit(aux, i);
        }
    }
    ch = fgetc(f);
    for(i = 0; i <= 7; i++){
        if(isBitISet(ch,i) > 0){
            sizeTree = setBit(sizeTree, i);
        }
    }
    return sizeTree;
}



//OBTEM A ARVORE DO ARQUIVO A SER DESCOMPRIMIDO(RECURSIVA)
pnode *givemeHtree(FILE *f, int *sizeTree){
    if(*sizeTree > 0){

        pnode *root;
        root = createpnode(0,0,NULL,NULL);
        unsigned char ch = 0;
        ch = fgetc(f);

        if(ch == '*'){
            --*sizeTree;
            root -> c = ch;
            root -> left = givemeHtree(f,sizeTree);
            root -> right = givemeHtree(f,sizeTree);
        }
        else{
            if(ch == '\\'){
                ch = fgetc(f);
            }
            --*sizeTree;
            root -> c = ch;
            root -> left = NULL;
            root -> right = NULL;
        }
        return root;
    }
    return NULL;




}

//INICIA A DESCOMPRESSAO DO ARQUIVO
void makedescompressOutputfile(FILE *f,FILE *Writeoutput,pnode *huff,int trash, int sizeTree){
    int ch;
    int i;
    pnode *temproot;
    long int size;
    unsigned char *buffer;
    unsigned char *buffer2;

    //APENAS UM RECEPTOR.
    buffer2 = (unsigned char*)malloc(1*sizeof(unsigned char));

    //TEMPROOT APONTA PARA A RAIZ DA ARVORE
    temproot = huff;
    size = 0;
    rewind(f);
    //LE TODO O ARQUIVO PARA DESCOBRIR O TAMANHO
    while(!feof(f)){
        fread(buffer2,1,1,f);
        size++;
    }
    buffer = (unsigned char*)malloc(size*sizeof(unsigned char));

    rewind(f);
    //COLOCANDO TODOS OS ELEMENTOS DO ARQUIVO A SER DESCOMPRIMIDO EM BUFFER.
    fread(buffer,1,size,f);
    rewind(f);
    int ind = 2 + sizeTree;
    while(1){//matar isto
        ch = buffer[ind];
        //ENQUANTO NAO CHEGA NO PENULTIMO BYTE ENTRA NO IF
        if(ind < size - 2){
            for(i = 7; i >= 0; i--){
                if(isBitISet(ch,i) != 0){
                    temproot = temproot -> right;
                }
                else{
                    temproot = temproot -> left;
                }
                if(isLeaf(temproot)){
                    fputc(temproot -> c, Writeoutput);
                    temproot = huff;
                }
            }
        }
        //ENTRA NO ELSE SE CHEGOU NO ULTIMO BYTE
        else{
            for(i = 7; i >= trash; i--){
                if(isBitISet(ch,i) != 0){
                    temproot = temproot -> right;
                }
                else{
                    temproot = temproot -> left;
                }
                if(!ispEmpty(temproot) && isLeaf(temproot)){
                    fputc(temproot -> c, Writeoutput);
                    temproot = huff;
                }
            }
            break;
        }
        ind++;
    }
    free(buffer);
    free(buffer2);
    fclose(f);
    fclose(Writeoutput);
}
//EndDESCOMPRESS
//EndFunctions
