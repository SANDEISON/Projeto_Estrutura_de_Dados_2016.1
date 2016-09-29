#include <stdio.h>

int main(int argc, char *argv[])
{


    //Variavel para manipular o arquivo
    FILE *arquivo = NULL;

    FILE *novoArquivo = NULL;

    char endereco = "D:\Downloads\GitHub\Projeto_Estrutura_de_Dados_2016.1\02 - Huffman\erro_acesso_Int\test.txt";

    char enderecoSalvar = "D:\Downloads\GitHub\Projeto_Estrutura_de_Dados_2016.1\02 - Huffman\erro_acesso_Int\novo.txt";

    //Abre o arquivo em Binario
    arquivo = fopen(endereco, "rb");

    //Cria o novo arquivo Binario
    novoArquivo = fopen(enderecoSalvar, "wb");

    //Verifica se o arquivo foi aberto com sucesso
    if(arquivo == NULL){
      printf("ERRO: não foi possível ler o arquivo!\n");
    }else{

        unsigned int frequencia;

        //Le o 1 byte do arquivo
        fread(&frequencia, sizeof(unsigned int), 1, arquivo);

        while (!feof(arquivo))
        {
          //Escreve o Byte no Arquivo
          fwrite(&frequencia, sizeof(unsigned int), 1, novoArquivo);
          //Le o proxymo Byte
          fread(&frequencia, sizeof(unsigned int), 1, arquivo);
        }

    }




    //Fecha o arquivo
    fclose (arquivo);

    //Fecha o arquivo
    fclose (novoArquivo);
    return 0;
}
