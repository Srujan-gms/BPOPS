
#include <stdio.h>
#include <math.h>

// Function to calculate factorial of a number
int fact(int m) {
    int i, f = 1;
    for (i = 1; i <= m; i++) {
        f = f * i;
    }
    return f;
}

int main() {
    int x, n, i;
    float rad, sum = 0;

    printf("Enter angle in degrees: ");
    scanf("%d", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    // Convert degrees to radians
    rad = x * 3.14159265 / 180;

    // Calculate sine using Taylor series
    for (i = 1; i <= n; i += 2) {
        if (((i - 1) / 2) % 2 == 0) {
            sum += pow(rad, i) / fact(i);
        } else {
            sum -= pow(rad, i) / fact(i);
        }
    }

    // Display results
    printf("Calculated sin(%d) = %f\n", x, sum);
    printf("Library sin(%d)    = %f\n", x, sin(rad));

    return 0;
}