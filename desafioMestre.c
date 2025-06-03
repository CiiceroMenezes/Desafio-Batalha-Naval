// Aplicar habilidades no tabuleiro criado anteriormente
// Cone, Cruz e Octaedro
// Àgua = 0, Navío = 3, Habilidades = 5

#include <stdio.h>
#include <stdlib.h> // Necessário para abs()

#define linhas 10
#define colunas 10
#define tamanhoHabilidade 5 // 5x5

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[linhas][colunas], int habilidade[tamanhoHabilidade][tamanhoHabilidade], int origemLinha, int origemColuna)
{
    int offset = tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++)
    {
        for (int j = 0; j < tamanhoHabilidade; j++)
        {
            if (habilidade[i][j] == 1)
            {
                int linhaTabuleiro = origemLinha + (i - offset);
                int colunaTabuleiro = origemColuna + (j - offset);

                if (linhaTabuleiro >= 0 && linhaTabuleiro < linhas && colunaTabuleiro >= 0 && colunaTabuleiro < colunas)
                {
                    // Se não for um navio, aplica o efeito da habilidade
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3)
                    {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }
}

int main()
{
    int matriz[linhas][colunas] = {0}; // Inicializa o tabuleiro com água (0)

    // Inserindo os navios

    // Navio Horizontal
    int linhaHorizontal = 5;
    int colunaHorizontalInicio = 2;
    for (int j = colunaHorizontalInicio; j < colunaHorizontalInicio + 3; j++)
    {
        if (j >= 0 && j < colunas)
        {
            matriz[linhaHorizontal][j] = 3;
        }
    }

    // Navio Vertical
    int colunaVertical = 7;
    int linhaVerticalInicio = 4;
    for (int i = linhaVerticalInicio; i < linhaVerticalInicio + 3; i++)
    {
        if (i >= 0 && i < linhas)
        {
            matriz[i][colunaVertical] = 3;
        }
    }

    // Navio Diagonal 1 (↘)
    int linhaDiagonal1 = 1, colunaDiagonal1 = 1;
    for (int k = 0; k < 3; k++)
    {
        if ((linhaDiagonal1 + k) < linhas && (colunaDiagonal1 + k) < colunas)
        {
            matriz[linhaDiagonal1 + k][colunaDiagonal1 + k] = 3;
        }
    }

    // Navio Diagonal 2 (↗)
    int linhaDiagonal2 = 8, colunaDiagonal2 = 1;
    for (int k = 0; k < 3; k++)
    {
        if ((linhaDiagonal2 - k) >= 0 && (colunaDiagonal2 + k) < colunas)
        {
            matriz[linhaDiagonal2 - k][colunaDiagonal2 + k] = 3;
        }
    }

    // Criando as Matrizes de Habilidade

    int cone[tamanhoHabilidade][tamanhoHabilidade] = {0};
    int cruz[tamanhoHabilidade][tamanhoHabilidade] = {0};
    int octaedro[tamanhoHabilidade][tamanhoHabilidade] = {0};

    // Cone (apontando para baixo)
    for (int i = 0; i < tamanhoHabilidade; i++)
    {
        for (int j = 0; j < tamanhoHabilidade; j++)
        {
            if (j >= (tamanhoHabilidade / 2) - i && j <= (tamanhoHabilidade / 2) + i && i <= tamanhoHabilidade / 2)
            {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz
    for (int i = 0; i < tamanhoHabilidade; i++)
    {
        for (int j = 0; j < tamanhoHabilidade; j++)
        {
            if (i == tamanhoHabilidade / 2 || j == tamanhoHabilidade / 2)
            {
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < tamanhoHabilidade; i++)
    {
        for (int j = 0; j < tamanhoHabilidade; j++)
        {
            if (abs(i - tamanhoHabilidade / 2) + abs(j - tamanhoHabilidade / 2) <= tamanhoHabilidade / 2)
            {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicando habilidades no tabuleiro

    aplicarHabilidade(matriz, cone, 2, 7);     // Cone na posição (2,7)
    aplicarHabilidade(matriz, cruz, 6, 3);     // Cruz na posição (6,3)
    aplicarHabilidade(matriz, octaedro, 7, 7); // Octaedro na posição (7,7)

    // Imprimindo o Tabuleiro

    printf("\n### Tabuleiro de Batalha Naval com Habilidades ###\n\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]); // Exibe diretamente os valores 0, 3 ou 5
        }
        printf("\n");
    }

    return 0;
}