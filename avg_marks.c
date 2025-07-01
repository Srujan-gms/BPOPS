
#include <stdio.h>

struct student {
    char usn[10];
    char name[10];
    int m1, m2, m3;
    float avg, total;
};

void main()
{
    struct student s[20];
    int n, t;
    float tavg, sum = 0.0;

    // clrscr();  // optional in some compilers; you can remove or comment it

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (t = 0; t < n; t++)
    {
        printf("\nEnter the detail of %d student\n", t + 1);

        printf(" Enter USN: ");
        scanf("%s", s[t].usn);

        printf(" Enter Name: ");
        scanf("%s", s[t].name);

        printf(" Enter the three subjects marks\n");
        scanf("%d%d%d", &s[t].m1, &s[t].m2, &s[t].m3);

        s[t].total = s[t].m1 + s[t].m2 + s[t].m3;
        s[t].avg = s[t].total / 3.0;

        sum += s[t].avg;
    }

    tavg = sum / n;

    for (t = 0; t < n; t++)
    {
        if (s[t].avg >= tavg)
            printf("\n%s has scored above the average marks", s[t].name);
        else
            printf("\n%s has scored below the average marks", s[t].name);
    }
}