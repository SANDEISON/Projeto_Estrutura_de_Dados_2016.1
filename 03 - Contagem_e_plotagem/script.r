#script.r
#source("script.r")
#setwd("/home/marcossouza/Área de Trabalho/C-P/update13-04")

getwd()

dados <- read.table("D:\\Documents\\GitHub\\Projeto_Estrutura_de_Dados_2016.1\\build-Contagem_e_plotagem-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\inR.txt", col.names= c("w", "x", "y", "z"), header= F)
#x por y
plot(c(0,40), c(0,40), type="n", xlab=("QUANTIDADE DE TESTES"), ylab="COMPARAÇÕES REALIZADAS A CADA TESTE")



lines(dados$w, dados$x, col="black")
lines(dados$w, dados$y, col="blue")
lines(dados$w, dados$z, col="red")

legend(0,40, c('Lista Encadeada', ' A. Busca Binária ', 'AVL '), col=c('red', 'black', 'blue'), pch=c(20,20,20))

