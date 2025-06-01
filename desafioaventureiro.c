// Posicionar Quatro Navios: dois navios horizontal ou vertical e dois navios na diagonal

#include <stdio.h>

#define linhas 10
#define colunas 10

int main()
{
    int matriz[10][10] = {0}; // O valor 0 representa a água

    int linhaHorizontal = 5; // Dando inicio a localização do navio horizontal
    int colunaHorizontalInicio = 2;

    int colunaVertical = 7; // Dando inicio a localização do navio vertical
    int linhaVerticalInicio = 4;

    for (int j = colunaHorizontalInicio; j < colunaHorizontalInicio + 3; j++) // Acrescentando o mesmo ao tabuleiro (horizontal)
    {
        if (j >= 0 && j < colunas) // Verificando se esta dentro da matriz
        {
            matriz[linhaHorizontal][j] = 3; // Dando o valor que representa o navio (3)
        }
    }

    for (int i = linhaVerticalInicio; i < linhaVerticalInicio + 3; i++) // Acrescentando o mesmo ao tabuleiro (vertical)
    {
        if (i >= 0 && i < linhas) // Verificando se esta dentro da matriz
        {
            matriz[i][colunaVertical] = 3;
        }
    }

    // Primeiro Navio na Diagonal
    int linhaDiagonal1 = 1; // Decidindo onde ele vai ficar
    int colunaDiagonal1 = 1;
    for (int k = 0; k < 3; k++) // Variavel K para ser uma variavel auxiliar
    {
        if ((linhaDiagonal1 + k) < linhas && (colunaDiagonal1 + k) < colunas) // Mesma verificação anterior se encontra-se dentro da matriz
        {
            matriz[linhaDiagonal1 + k][colunaDiagonal1 + k] = 3; // Dando o valor ao Navio (3)
        }
    }

    // Segundo Navio na Diagonal
    int linhaDiagonal2 = 8;
    int colunaDiagonal2 = 1;
    for (int k = 0; k < 3; k++) // Usando decremento
    {
        if ((linhaDiagonal2 - k) >= 0 && (colunaDiagonal2 + k) < colunas)
        {
            matriz[linhaDiagonal2 - k][colunaDiagonal2 + k] = 3;
        }
    }

    // Imprimindo o Tabuleiro na tela
    printf("### Tabuleiro de Batalha Naval ###\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}