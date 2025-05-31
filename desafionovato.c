// Representar um tabuleiro simplificado e posicionar dois navios nele: um na vertical e outro na horizontal.
// No Tabuleiro, o numero 0 representa a água e o número 3 representa o navio.
// Posição pode ser definida no código.

#include <stdio.h>
int main()
{
    int linhas = 10;          // Definindo quantas linhas
    int colunas = 10;         // Definindo quantas colunas
    int matriz[10][10] = {0}; // Criando Array Bidimensional, mas todos com o valor "0", que representam a água.

    int linhaHorizontal = 5; // Representando onde iniciará o barco Horizontal
    int colunaHorizontalInicio = 2;

    int colunaVertical = 7; // Representando onde iniciará o barco Vertical
    int linhaVerticalInicio = 4;

    for (int j = colunaHorizontalInicio; j < colunaHorizontalInicio + 3; j++) // Definindo onde ficará localizado
    {
        if (j >= 0 && j < colunas) // Verificando se esta dentro das linhas e colunas propostas
        {
            matriz[linhaHorizontal][j] = 3;
        }
    }

    for (int i = linhaVerticalInicio; i < linhaVerticalInicio + 3; i++) // Definindo onde ficará localizado
    {
        if (i >= 0 && i < colunas) // Verificando se esta dentro das linhas e colunas propostas
        {
            matriz[i][colunaVertical] = 3;
        }
    }

    printf("### Tabuleiro de Batalha Naval ###\n"); // Mensagem inicial de apresentação do tabuleiro
    for (int i = 0; i < linhas; i++)                // Criando as linhas
    {
        for (int j = 0; j < colunas; j++) // Criando as colunas
        {
            printf("%d ", matriz[i][j]); // Imprimindo na tela as colunas
        }
        printf("\n"); // Pulando a linha para as Linhas
    }

    return 0;
}