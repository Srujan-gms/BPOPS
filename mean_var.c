
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    float x[20], sum, mean;
    float variance, deviation;

    // clrscr();  // (commented or ignored in modern compilers)

    printf("Enter the value of n \n");
    scanf("%d", &n);

    printf("enter %d real values \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);//(x+i)
    }

    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + x[i];//*(x + i);
    }

    printf("sum = %f\n", sum);
    mean = sum / n;

    sum = 0;
    for (i = 0; i < n; i++)
    {
        //sum = sum + (*(x + i) - mean) * (*(x + i) - mean);
        sum+=(x[i]-mean)*(x[i]-mean);
    }

    variance = sum / n;
    deviation = sqrt(variance);

    printf("mean (Average) = %f\n", mean);
    printf("variance = %f\n", variance);
    printf("standard deviation = %f\n", deviation);

    return 0;
}