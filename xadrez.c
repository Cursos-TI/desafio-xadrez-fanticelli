#include <stdio.h>
#include <stdlib.h> //para system("clear").
#include <string.h> // Para a função de copiar string.

//função para limpar buffer de entrada.
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
};

int main() {
    int escolhaPeca; // Para 1, 2, 3
    char escolhaMovimento1, escolhaMovimento2; // Para 'A', 'B', 'C', 'D'
    char direcaoTexto[30]; // Buffer para armazenar direção.

    //menu interativo para escolha da peça.
    printf("---- Bem vindo ao jogo MateCheck ----\n");
   
    printf("\n Escolha sua peça: \n");
    printf("|| 1. Bispo\n");
    printf("|| 2. Torre\n");
    printf("|| 3. Rainha\n");
    
    printf(" --> ");
    scanf("%d", &escolhaPeca); //escolha do usuário. 
    limparBuffer();

    //menu interativo para 1 escolha da direção.
    printf("\n Escolha a direção do movimento da sua peça: \n");
    printf("|| A. Cima \n");
    printf("|| B. Baixo \n");
    printf("|| C. Esquerda \n");
    printf("|| D. Direita \n");
    
    printf(" --> ");
    scanf(" %c", &escolhaMovimento1); //escolha do usuário.

    // Se for Bispo ou Rainha, pede uma segunda escolha.
    if (escolhaPeca == 1 || escolhaPeca == 3) {
        printf("\n Escolha a segunda direção do movimento:\n");
        printf("|| A. Cima \n"); // Pode ser redundante se a primeira foi Cima/Baixo
        printf("|| B. Baixo \n"); // Pode ser redundante se a primeira foi Cima/Baixo
        printf("|| C. Esquerda \n");
        printf("|| D. Direita \n");

        printf(" --> ");
        scanf(" %c", &escolhaMovimento2); // Segunda escolha do usuário.
    } else {
        escolhaMovimento2 = '\0'; //inicializa para evitar lixo de memoria.
    }

    system("clear"); //limpar terminal.

    printf("--------------------------\n");
    printf("\n Simulando movimentos...\n");
    printf("--------------------------\n");

    // Lógica para determinar a string de direção final com base nas escolhas.
    if (escolhaPeca == 1 || escolhaPeca == 3) { // Bispo ou Rainha.
        if ((escolhaMovimento1 == 'A' || escolhaMovimento1 == 'a') && (escolhaMovimento2 == 'C' || escolhaMovimento2 == 'c')) {
            strcpy(direcaoTexto, "Cima, Esquerda");
        } else if ((escolhaMovimento1 == 'A' || escolhaMovimento1 == 'a') && (escolhaMovimento2 == 'D' || escolhaMovimento2 == 'd')) {
            strcpy(direcaoTexto, "Cima, Direita");
        } else if ((escolhaMovimento1 == 'B' || escolhaMovimento1 == 'b') && (escolhaMovimento2 == 'C' || escolhaMovimento2 == 'c')) {
            strcpy(direcaoTexto, "Baixo, Esquerda");
        } else if ((escolhaMovimento1 == 'B' || escolhaMovimento1 == 'b') && (escolhaMovimento2 == 'D' || escolhaMovimento2 == 'd')) {
            strcpy(direcaoTexto, "Baixo, Direita");
        } else if (escolhaPeca == 3) { // A Rainha pode fazer movimentos simples também
             if (escolhaMovimento1 == 'A' || escolhaMovimento1 == 'a') strcpy(direcaoTexto, "Cima");
             else if (escolhaMovimento1 == 'B' || escolhaMovimento1 == 'b') strcpy(direcaoTexto, "Baixo");
             else if (escolhaMovimento1 == 'C' || escolhaMovimento1 == 'c') strcpy(direcaoTexto, "Esquerda");
             else if (escolhaMovimento1 == 'D' || escolhaMovimento1 == 'd') strcpy(direcaoTexto, "Direita");
             else strcpy(direcaoTexto, "DIREÇÃO INVÁLIDA"); 
        } else {
             strcpy(direcaoTexto, "DIREÇÃO INVÁLIDA (Bispo)");
        }
    } else { // Torre (apenas uma escolha de direção)
        switch (escolhaMovimento1) {
            case 'A': case 'a': strcpy(direcaoTexto, "Cima"); break;
            case 'B': case 'b': strcpy(direcaoTexto, "Baixo"); break;
            case 'C': case 'c': strcpy(direcaoTexto, "Esquerda"); break;
            case 'D': case 'd': strcpy(direcaoTexto, "Direita"); break;
            default: strcpy(direcaoTexto, "DIREÇÃO INVÁLIDA (Torre)"); break;
        }
    }

    //Movimentação.
    switch (escolhaPeca){
    //Movimentação do Bispo.
    case 1:
        if (strcmp(direcaoTexto, "DIREÇÃO INVÁLIDA (Bispo)") == 0) {
            printf("Erro: Combinação de direções inválida para o Bispo. Por favor, escolha uma diagonal (ex: Cima e Esquerda).\n");
        break; // Sai do switch da peça
        }

        int i = 0;
        while (i < 5){
            printf(" + 1 casa para %s...\n", direcaoTexto);
            i++;
        }     
    break;

    //Movimentação da Torre.
    case 2:
        if (strcmp(direcaoTexto, "DIREÇÃO INVÁLIDA (Torre)") == 0) {
            printf("Erro: Direção inválida para a Torre. Escolha A, B, C ou D.\n");
        break; // Sai do switch da peça
        }

        for (int j = 0; j < 5; j++) {
            printf(" + 1 casa para %s\n", direcaoTexto);
        }
    break;

    //Movimentação da Rainha.
    case 3:
        if (strcmp(direcaoTexto, "DIREÇÃO INVÁLIDA") == 0) {
            printf("Erro: Direção inválida para a Rainha. Escolha uma combinação ou direção válida.\n");
        break; // Sai do switch da peça
        }

        int count = 0;
        do{
            printf(" + 1 casa para %s\n", direcaoTexto);
            count++;
        } while (count < 8);  
    break;

    //else.
    default:
        printf(" Opção Inválida! Volte para o menu...");
        break;
    };
    return 0;
}