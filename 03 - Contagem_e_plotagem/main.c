#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cp.h"
#define DEBUG if(0)
//#define INTERV 400
//#define QTEST 200

int main()
{
    int i, x, interv, qtest;
    int ins1=0, ins2=0, ins3=0, esc=0;
    int busc1=0, busc2=0, busc3=0, busc4=0, escXBusc, contador=1;
    //printf("intervalo da rand: [0,%d]\n", RAND_MAX);
    srand( (unsigned)time(NULL) );

    Binarytree *newNode = NULL;
    Binarytree *bt = NULL;
    AVL *treeAVL = NULL;
    Node *list = NULL;


    FILE *f = fopen("inR.txt", "w");
    if(f == NULL)
    {
        printf("ERRO AO TENTAR CRIAR ARQUIVO\n");
        exit(1);
    }

    printf("Intervalo de sorteio( 1 ~ N )\nN: ");
    scanf("%d", &interv);
    printf("Quantidade de teste(Q): ");
    scanf("%d", &qtest);

    printf("\nEscolha o caso de teste de insercao abaixo:\n\n");
    printf("1 - Inserir numeros aleatorio do intervalo (1 ~ N) com insercao de quantidade (somatorio de (1 ~ Q))\n");
    printf("2 - Inserir numeros no padrao [1], [1,2], [1,2,3], ... ate Q\n");
    printf("3 - Inserir caso extremo [1],[2],[3],[4]... ate Q\n");
    printf("\n--> ");
    scanf("%d", &esc);
    while(esc < 1 || esc > 3)
    {
    	scanf("%d", &esc);
    }
    if(esc == 1)
    {
    	ins1 = 1;
    }else if(esc == 2)
    {
    	ins2 = 1;
    } else
    {
    	ins3 = 1;
    }

    printf("\nEscolha o caso de teste de busca abaixo:\n\n");
    printf("1 - Buscar numero aleatorio sorteado dentro do intervalo\n");
    printf("2 - Buscar numero inserido manualmente a cada teste\n");
    printf("3 - Buscar numero fora do intervalo de insercao (caso extremo de busca)\n");
    printf("4 - Buscar 1 numero inserido manualmente em todos testes\n");
    printf("\n--> ");
    scanf("%d", &esc);
        while(esc < 1 || esc > 3)
        {
        	scanf("%d", &esc);
        }
        if(esc == 1)
        {
        	busc1 = 1;
        }
        else if(esc == 2)
        {
        	busc2 = 1;
        }
        else if(esc == 3)
        {
        	busc3 = 1;
        }
        else
        {
        	busc4 = 1;
        	printf("Numero a ser buscado: ");
        	scanf("%d", &escXBusc);
        }


    int j;
    for(j=1; j <= qtest; j++ )
    {

        for(i=1 ; i <= j ; i++)
        {
            if(ins1) x = 1 + rand() % interv ;
        	if(ins2) x = i;
        	if(ins3) x = j; //caso extremo

            newNode = createNewNode(x);
            bt = insertNode(bt, newNode);
            treeAVL = insert(x, treeAVL);
            list = insertNodeList(list, x);
        }

    DEBUG printf("\nBinaria\n");
    DEBUG printBinaryTree(bt);
    DEBUG printf("\n\nAVL\n");
    DEBUG printAVL(treeAVL);
    DEBUG printf("\n\nLista\n");
    DEBUG printLinkedList(list);
    DEBUG printf("\n");


		if(busc1)
			{
			x = (1 + rand() % interv) ;
			}
        if(busc2)
        {
        	printf("digite o numero a ser buscado(%d): ", contador++);
        	scanf("%d", &escXBusc);
        	DEBUG printf("\nNumero buscado: %d\n", escXBusc);
        	x = escXBusc;
        }
		if(busc3) x = interv + 10;
		if(busc4) x = escXBusc;

		int s = 1, q = 1, r = 0;

		s = searchNode(bt, x, &s);
		q = searchAVL(x, treeAVL, &q);
		r = search(list, x);

		fprintf(f, "%d %d %d %d\n", j, s, q, r);
		DEBUG if(!busc2) printf("\nNumero buscado: %d\n", x);
		DEBUG printf("comparacoes BinaryTree: %d\n", s);
		DEBUG printf("comparacoes AVL: %d\n", q);
		DEBUG printf("comparacoes linkedList: %d\n", r);


    }

    printf("Arquivo gerado com sucesso!...\n");
    return 0;
}
