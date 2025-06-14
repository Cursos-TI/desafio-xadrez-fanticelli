#include <stdio.h> // biblioteca padrão.
#include <stdlib.h> //para a função de limpar terminal.
#include <ctype.h> // Para uso do toupper.

// Função para limpar buffer de entrada.
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    int escolhaPeca; // Para 1, 2, 3 (Bispo/Rainha/Torre).
    char escolhaDirecaoBispo, escolhaDirecaoTorre, escolhaDirecaoRainha; // Para A, B, C, D.
    
    //ponteiro para string.
    char* direcaoBispoTexto = "";
    char* direcaoTorreTexto = "";
    char* direcaoRainhaTexto = "";

    //menu interativo para escolha da peça.
    printf("---- Bem vindo ao jogo MateCheck ----\n");
   
    printf("\n Escolha sua peça: \n");
    printf("|| 1. Bispo\n");
    printf("|| 2. Torre\n");
    printf("|| 3. Rainha\n");
    
    printf(" --> ");
    scanf("%d", &escolhaPeca);
    limparBuffer();

    if (escolhaPeca == 1){ // Se o usuario escolher Bispo.
        printf("\n Escolha a direção: \n");
        printf("|| A. Cima e Esquerda\n");
        printf("|| B. Cima e Direita\n");
        printf("|| C. Baixo e Esquerda\n");
        printf("|| D. Baixo e Direita\n");

        printf(" --> ");
        scanf(" %c", &escolhaDirecaoBispo);
        
        escolhaDirecaoBispo = toupper(escolhaDirecaoBispo); // Convertendo em maiusculo.

        system("clear");
    
        // Atribui o texto da direção.
        switch (escolhaDirecaoBispo) {
            case 'A':
                direcaoBispoTexto = "cima e esquerda";
            break;

            case 'B':
                direcaoBispoTexto = "cima e direita";
            break;
            
            case 'C':
                direcaoBispoTexto = "baixo e esquerda";
            break;
           
            case 'D':
                direcaoBispoTexto = "baixo e direita";
            break;
        }

    } else if (escolhaPeca == 2){ // Se o usuario escolher Torre.
        printf("\n Escolha a direção:\n");
        printf("|| A. Direita\n");
        printf("|| B. Cima\n");

        printf(" --> ");
        scanf(" %c", &escolhaDirecaoTorre);

        escolhaDirecaoTorre = toupper(escolhaDirecaoTorre); // convertendo em maiusculo. 

        system("clear");

        switch (escolhaDirecaoTorre){
            case 'A':
                direcaoTorreTexto = "direita";
            break;

            case 'B':
                direcaoTorreTexto = "cima";
            break;
        }
    } else if (escolhaPeca == 3){ // Se o usuario escolher Rainha.
        printf("\n Escolha a direção:\n");
        printf("|| A. Cima\n");
        printf("|| B. Baixo\n");
        printf("|| C. Esquerda\n");
        printf("|| D. Direita\n");

        printf(" --> ");
        scanf(" %c", &escolhaDirecaoRainha);

        escolhaDirecaoRainha = toupper(escolhaDirecaoRainha); //Convertendo em maiusculo. 

        system("clear");

        switch (escolhaDirecaoRainha){
            case 'A':
                direcaoRainhaTexto = "cima";
            break;
            
            case 'B':
                direcaoRainhaTexto = "baixo";
            break;

            case 'C':
                direcaoRainhaTexto = "esquerda";
            break;

            case 'D':
                direcaoRainhaTexto = "direita";
            break;
        }
    } else{
        printf("Opção Inválida..");
        return 1; // Boa prática para indicar erro.
    }

    // Escolha da peça.
    switch (escolhaPeca){

    // Bispo (while).
    case 1:{
        int i = 0;
        printf("---- Simulando movimentos ----\n");
        printf("\n");
            while (i < 5) {
                printf(" + 1 casa para %s...\n", direcaoBispoTexto);
                i++;
            }
        printf("\n Você andou um total de 5 casas para %s\n", direcaoBispoTexto);
        printf("\n---- Fim da simulação ----\n");
        }
    break;

    // Torre (for).
    case 2:{
        printf("---- Simulando movimentos ----\n");
        printf("\n");
            for (int j = 0; j < 5; j++) {
                printf(" + 1 casa para %s...\n", direcaoTorreTexto);
            }
        printf("\n Você andou um total de 5 casas para %s\n", direcaoTorreTexto);
        printf("\n---- Fim da simulação ----\n");
        }
    break;

    // Rainha (do-while).
    case 3:{
        int count = 0;
        printf("---- Simulando movimentos ----\n");
        printf("\n");
            do {
                printf(" + 1 casa para %s\n", direcaoRainhaTexto);
                count++;
            } while (count < 8);
        printf("\n Você andou um total de 8 casas para %s\n", direcaoRainhaTexto);
        printf("\n---- Fim da simulação ----\n");
        }
    break;
    
    default:
        printf("Opção Inválida.. ");
    break;
    }

    return 0; 
}