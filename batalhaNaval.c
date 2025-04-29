#include <stdio.h>

// Define o tamanho do tabuleiro
#define TAMANHO 10

// Define o valor que representa o navio no tabuleiro
#define NAVIO 3

// Tamanho fixo dos navios
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Vetores representando os navios (valores são todos 3)
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios (pode alterar se quiser testar outras posições)
    int linha_horizontal = 2; // Linha para o navio horizontal
    int coluna_horizontal = 4; // Coluna inicial do navio horizontal

    int linha_vertical = 5; // Linha inicial do navio vertical
    int coluna_vertical = 7; // Coluna para o navio vertical

    // Validação para garantir que os navios cabem no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO && linha_vertical + TAMANHO_NAVIO <= TAMANHO) {
        
        // Posiciona o navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já tem um navio naquela posição (para evitar sobreposição)
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 0) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            } else {
                printf("Erro: sobreposição detectada ao posicionar navio horizontal!\n");
                return 1;
            }
        }

        // Posiciona o navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já tem um navio naquela posição (para evitar sobreposição)
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            } else {
                printf("Erro: sobreposição detectada ao posicionar navio vertical!\n");
                return 1;
            }
        }

    } else {
        printf("Erro: coordenadas invalidas para posicionar os navios!\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
