#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreBinaria.h"
#include "avl.h"

#include "menus.h"


#define DEBUG if(0)


int main()
{
    int i, x, interv, qtest;
    int ins1=0, ins2=0,esc=0;
    int busc1=0, busc2=0, escXBusc, contador=1;


    srand( (unsigned)time(NULL) );

    Binarytree *newNode = NULL;
    Binarytree *bt = NULL;
    AVL *treeAVL = NULL;



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

    menu_insert();
    scanf("%d", &esc);
    while(esc < 1 || esc > 2)
    {
        scanf("%d", &esc);
    }
    if(esc == 1)
    {
        ins1 = 1;
    }else if(esc == 2)
    {
        ins2 = 1;
    }else if(esc == 0)
     {
            printf("Saindo...\n");
            exit(0);
     }

    menu_search();
    scanf("%d", &esc);
        while(esc < 1 || esc > 2)
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
        else if(esc == 0)
        {
          printf("Saindo...\n");
          exit(0);
         }


    int j;
    for(j=1; j <= qtest; j++ )
    {

        for(i=1 ; i <= j ; i++)
        {
            if(ins1) x = 1 + rand() % interv ;
            if(ins2) x = i;
            newNode = createNewNode(x);
            bt = insertNode(bt, newNode);
            treeAVL = insert(x, treeAVL);

        }

    DEBUG printf("\nBinaria\n");
    DEBUG printBinaryTree(bt);
    DEBUG printf("\n\nAVL\n");
    DEBUG printAVL(treeAVL);


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
       int s = 1, q = 1;

        s = searchNode(bt, x, &s);
        q = searchAVL(x, treeAVL, &q);


        fprintf(f, "%d %d %d\n", j, s, q);
        DEBUG if(!busc2) printf("\nNumero buscado: %d\n", x);
        DEBUG printf("comparacoes BinaryTree: %d\n", s);
        DEBUG printf("comparacoes AVL: %d\n", q);



    }

    printf("Arquivo gerado com sucesso!...\n");
    return 0;
}
