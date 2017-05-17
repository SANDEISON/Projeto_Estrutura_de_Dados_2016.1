#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include "compressao.h"
#include "descompressao.h"

#define LIMPA_TELA system("cls || clear")
#define ESPERA_TECLA getch()
#define MOSTRAR_DIRETORIO system("dir || ls")

int main()
{
    setlocale(LC_ALL,"");
    int opcao = 0;
    char h[999];//endereço completo do arquivo
    FILE *f = NULL;

    printf("LOCAL ATUAL: ");
    MOSTRAR_DIRETORIO;

    printf("DIGITE O ENDERECO DO ARQUIVO: \n");
    scanf("%[^\n]",h);
    f = fopen(h, "r");
    if(f == NULL)
    {
        LIMPA_TELA;
        printf("Arquivo invalido!\n");
        ESPERA_TECLA;
        return -1;
    }

    while(opcao < 1 || opcao > 3)
    {
        LIMPA_TELA;
        printf("Arquivo selecionado: %s\n",h);
        printf("1 - COMPRESSAO\n");
        printf("2 - DESCOMPRESSAO\n");
        printf("3 - SAIR\n");
        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d",&opcao);
    }
    if(opcao == 1)
    {
      compress(f,h);
      ESPERA_TECLA;
    }
    else if(opcao == 2)
    {
        int tam = strlen(h);
        tam--;
        //checagem se a extensão é .huff
        if((h[tam-4]='.')  && (h[tam-3]='h')  && (h[tam-2]=='u') && (h[tam-1]=='f') && (h[tam]=='f'))
        {
            descompress(f,h);
     }else
        {
            printf("Arquivo Invalido!\n");
            printf("Selecione um arquivo com a extensao .huff\n");
        }
      ESPERA_TECLA;
      return 0;
    }
    else if(opcao == 3)
    {
      return 0;
    }

    return 0;
}
