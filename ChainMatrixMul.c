#include <stdio.h>
#include <limits.h>

void printOptimalParenthesis(int i, int j, int bracket[100][100], char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }

    printf("(");
    printOptimalParenthesis(i, bracket[i][j], bracket, name);
    printOptimalParenthesis(bracket[i][j] + 1, j, bracket, name);
    printf(")");
}

int matrixChainOrder(int p[], int n) {
    int m[n][n];              // Minimum cost matrix
    int bracket[100][100];    // Bracket position for optimal parenthesis

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int l = 2; l < n; l++) { // l is the chain length
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    printf("Optimal Parenthesization is: ");
    printOptimalParenthesis(1, n - 1, bracket, &name);
    printf("\n");

    return m[1][n - 1];
}

int main() {
    int arr[] = {3,2,4,2,5}; // A1:10x20, A2:20x30, A3:30x40, A4:40x30
    int size = sizeof(arr) / sizeof(arr[0]);

    int minCost = matrixChainOrder(arr, size);
    printf("Minimum number of multiplications is: %d\n", minCost);
    return 0;
}
