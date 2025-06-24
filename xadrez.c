#include <stdio.h> // biblioteca padrão.
#include <stdlib.h> // para a função de limpar terminal.
#include <ctype.h> // Para uso do toupper.

// Função para limpar buffer de entrada.
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para o Bispo.
void moverBispo(int totalCasas, const char* direcaoTexto) {
    int casasMovidas = 0;
    for (int i = 0; i < totalCasas; i++) {
        
        for (int j = 0; j < 1; j++) {
            printf(" + 1 casa para %s...\n", direcaoTexto);
            casasMovidas++;
            // Se quisermos parar o movimento do Bispo após um certo número de casas
            if (casasMovidas >= totalCasas) {
                break; // Sai do loop interno
            }
        }
        if (casasMovidas >= totalCasas) {
            break; // Sai do loop externo
        }
    }
}

// Função recursiva para a Torre
void moverTorre(int casasRestantes, const char* direcaoTexto) {
    if (casasRestantes > 0) {
        printf(" + 1 casa para %s...\n", direcaoTexto);
        moverTorre(casasRestantes - 1, direcaoTexto);
    }
}

// Função recursiva para a Rainha
void moverRainha(int casasRestantes, const char* direcaoTexto) {
    if (casasRestantes > 0) {
        printf(" + 1 casa para %s\n", direcaoTexto);
        moverRainha(casasRestantes - 1, direcaoTexto);
    }
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
    printf("|| 4. Cavalo\n");
    
    printf(" --> ");
    scanf("%d", &escolhaPeca);
    limparBuffer();

    // Lógica para obter a direção para o Bispo.
    if (escolhaPeca == 1){ 
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
    } else if (escolhaPeca == 4){
        system("clear");
    } else{
        printf("Opção Inválida..\n");
        return 1; // Boa prática para indicar erro.
    }

    // Escolha da peça.
    switch (escolhaPeca){

    // Bispo.
    case 1:{
        printf("---- Simulando movimentos do Bispo ----\n");
        printf("\n");
        moverBispo(5, direcaoBispoTexto);
        printf("\n Você andou um total de 5 casas para %s\n", direcaoBispoTexto);
        printf("\n");
        }
    break;

    // Torre.
    case 2:{
        printf("---- Simulando movimentos da Torre ----\n");
        printf("\n");
        moverTorre(5, direcaoTorreTexto);
        printf("\n Você andou um total de 5 casas para %s\n", direcaoTorreTexto);
        printf("\n");
        }
    break;

    // Rainha.
    case 3:{
        printf("---- Simulando movimentos da Rainha ----\n");
        printf("\n");
        moverRainha(8, direcaoRainhaTexto);
        printf("\n Você andou um total de 8 casas para %s\n", direcaoRainhaTexto);
        printf("\n");
        }
    break;

    case 4: {
        printf("---- Simulando movimento do Cavalo ----\n");
        printf("\n");
        
        int casasVerticais = 0;
        int casasHorizontais = 0;

        // Loop principal para o movimento do Cavalo
        for (int i = 0; i < 3; i++) { 
            if (casasVerticais < 2) {
                printf(" + 1 casa para cima...\n");
                casasVerticais++;
                continue; 
            }

            if (casasHorizontais < 1) {
                printf(" + 1 casa para a direita...\n");
                casasHorizontais++;
                break; 
            }
        }
        printf("\n || Você andou em L (2 casas para baixo e 1 para esquerda).\n");
        printf("\n");
    break;
    }
}

    return 0; 
}