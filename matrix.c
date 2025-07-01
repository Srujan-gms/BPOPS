
#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int m, n, p, q;
    int i, j, k;

    // Input sizes
    printf("Enter the size of matrix A (rows and columns): ");
    scanf("%d %d", &m, &n);
    printf("Enter the size of matrix B (rows and columns): ");
    scanf("%d %d", &p, &q);

    // Check multiplication validity
    if (n != p) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    // Initialize result matrix C to zero
    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++)
            c[i][j] = 0;

    // Multiply matrices
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Output result
    printf("Matrix A × B =\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}