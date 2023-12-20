/*
4) WAP to fill a square matrix with value 0(zero) on the diagonals,
value 1 on the upper right triangle and value -1 on the lower left triangle.
*/

#include <stdio.h>

void fillMatrix(int n, int matrix[][n]) {
    // Fill diagonals with 0
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
    }

    // Fill upper right triangle with 1
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            matrix[i][j] = 1;
        }
    }

    // Fill lower left triangle with -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            matrix[i][j] = -1;
        }
    }
}

void displayMatrix(int n, int matrix[][n]) {
    printf("Filled Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    fillMatrix(n, matrix);
    displayMatrix(n, matrix);

    return 0;
}
