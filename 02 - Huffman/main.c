#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compressao.h"
#include "descompressao.h"

// Definição para limpar a tela
#define LIMPA_TELA system("cls || clear")
// Definição para Aguardar uma tecla
#define ESPERA_TECLA getch()

int main()
{
    //Recebe o Endereço do arquivo
    char endereco[999];
    //Variavel para manipular o arquivo
    FILE *arquivo = NULL;
    //Seleção da opção
    int opcao = 0;


    printf("DIGITE O ENDERECO DO ARQUIVO: \n");
    scanf("%[^\n]",endereco);
    //Abre o arquivo em Binario
    arquivo = fopen(endereco, "rb");
    //Verifica se o arquivo foi aberto com sucesso
    if(arquivo == NULL){
      printf("ERRO: não foi possível ler o arquivo!\n");
      LIMPA_TELA;
    }

    while( opcao < 1 || opcao > 3 )
    {
       printf("\n");
       printf("1 - COMPRESSAO\n");
       printf("2 - DESCOMPRESSAO\n");
       printf("3 - SAIR\n");
       printf("ESCOLHA UMA OPCAO: ");
       scanf("%d",&opcao);
       if(opcao == 1){
         // Executa a função de Compressão
         compress(arquivo,endereco);
       }
       else if(opcao == 2){
          int tam = strlen(endereco);
          tam--;
          //verifica a extenção do arquivo
          if((endereco[tam-4]='.')  && (endereco[tam-3]='h')  && (endereco[tam-2]=='u') && (endereco[tam-1]=='f') && (endereco[tam]=='f')){
            // Executa a função de Descompressão
            descompress(arquivo,endereco);
          }else{
           printf("Arquivo Invalido!\n");
           printf("Selecione um arquivo com a extensao .huff\n");
           ESPERA_TECLA;
           LIMPA_TELA;
          }
       }
       else if(opcao == 3){
         return 0;
       }else{
        printf("Opção Invalida!\n");
        ESPERA_TECLA;
        LIMPA_TELA;
       }
    }
    //Fecha o arquivo
    fclose (arquivo);
    return 0;
}
