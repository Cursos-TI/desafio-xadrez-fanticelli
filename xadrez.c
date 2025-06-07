#include <stdio.h>
#include <stdlib.h> //para system("clear");

//função para limpar buffer de entrada.
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
};

int main() {
    int escolhaPeca; // Para 1, 2, 3
    char escolhaMovimento; // Para 'A', 'B', 'C', 'D'

    //menu interativo para escolha da peça.
    printf("\n---- Bem vindo ao jogo MateXeque ----\n");
   
    printf(" Escolha sua peça: \n");
    printf("|| 1. Bispo\n");
    printf("|| 2. Torre\n");
    printf("|| 3. Rainha\n");
    
    printf("\n"); //pular linha - espaçamento.
    
    printf(" --> ");
    scanf("%d", &escolhaPeca); //escolha do usuário. 
    getchar();//limpar buffer.

    system("clear"); //limpar terminal.

    //menu interativo para 1 escolha da direção.
    printf(" Escolha a direção do movimento da sua peça: \n");
    printf("|| A. Cima \n");
    printf("|| B. Baixo \n");
    printf("|| C. Esquerda \n");
    printf("|| D. Direita \n");

    printf("\n"); //pular linha - espaçamento.
    
    printf(" --> ");
    scanf(" %c", &escolhaMovimento); //escolha do usuário.

    system("clear"); //limpar terminal.

    printf("--------------------------");
    printf("\n Simulando movimentos...\n");
    printf("--------------------------");

    //Movimento.
    switch (escolhaPeca){
    //Movimentação do Bispo.
    case 1:
        for (int i = 0; i < 5; i++)
        {
        printf(" + 1 casa para %s...");
        }
    break;

    //Movimentação da Torre.
    case 2:
        while (escolhaPeca <= 5)
        {
            printf(" + 1 casa para %s...");
        }
    break;

    //Movimentação da Rainha.
    case 3:
        do{
        printf(" + 1 casa para %s...");
        }while (escolhaPeca < 8);
    break;

    //else.
    default:
        printf(" Opção Inválida! Volte para o menu...");
        break;
    };

    //Direção.
    switch (escolhaMovimento){
    
    //Movimentação do Bispo.
    case 'A':
        for (int i = 0; i < 5; i++)
        {
        printf(" + 1 casa para %s...");
        }
    break;

    //Movimentação da Torre.
    case 'B':
        while (escolhaPeca <= 5)
        {
           printf(" + 1 casa para %s...");
        }
    break;

    //Movimentação da Rainha.
    case 'C':
        do{
            printf(" + 1 casa para %s...");
        }while (escolhaPeca < 8);
    break;

    case 'D':

    break;

    //else.
    default:
        printf(" Opção Inválida! Volte para o menu...");
        break;
    };
    return 0;
}
