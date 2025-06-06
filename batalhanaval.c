#include <stdio.h>

#define TAMANHO_TABULEIRO 100 // 10x10
#define TAMANHO_NAVIO 3
#define TAMANHO_LINHA 10

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[i] = 0;
    }
}

// Função para posicionar um navio
// orientacao = 'H' (horizontal) ou 'V' (vertical)
// Retorna 1 se conseguiu posicionar, 0 se não (fora dos limites ou sobreposição)
int posicionarNavio(int tabuleiro[], int linha_inicial, int coluna_inicial, char orientacao) {
    // Verificar se cabe no tabuleiro
    if (orientacao == 'H') {
        if (coluna_inicial + TAMANHO_NAVIO > TAMANHO_LINHA)
            return 0;
    } else if (orientacao == 'V') {
        if (linha_inicial + TAMANHO_NAVIO > TAMANHO_LINHA)
            return 0;
    } else {
        return 0;
    }

    // Verificar sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linha_inicial + (orientacao == 'V' ? i : 0);
        int coluna = coluna_inicial + (orientacao == 'H' ? i : 0);
        int indice = linha * TAMANHO_LINHA + coluna;
        if (tabuleiro[indice] != 0)
            return 0;
    }

    // Posicionar o navio (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linha_inicial + (orientacao == 'V' ? i : 0);
        int coluna = coluna_inicial + (orientacao == 'H' ? i : 0);
        int indice = linha * TAMANHO_LINHA + coluna;
        tabuleiro[indice] = 3;
    }

    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[]) {
    printf("   ");
    for (int col = 0; col < TAMANHO_LINHA; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    for (int linha = 0; linha < TAMANHO_LINHA; linha++) {
        printf("%2d ", linha);
        for (int coluna = 0; coluna < TAMANHO_LINHA; coluna++) {
            int indice = linha * TAMANHO_LINHA + coluna;
            printf(" %d ", tabuleiro[indice]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Definir coordenadas dos navios
    // Navio 1: Horizontal na linha 2, coluna 3
    int linhaNavio1 = 2;
    int colunaNavio1 = 3;

    // Navio 2: Vertical na linha 5, coluna 7
    int linhaNavio2 = 5;
    int colunaNavio2 = 7;

    // Posicionar os navios
    if (!posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 'H')) {
        printf("Erro ao posicionar o navio 1!\n");
    }
    if (!posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 'V')) {
        printf("Erro ao posicionar o navio 2!\n");
    }

    // Exibir o tabuleiro
    printf("\n=== Tabuleiro ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}