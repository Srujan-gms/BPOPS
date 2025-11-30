#include <stdio.h>
#include <stdlib.h>

int main() {
int f[50], i, p, st, len, j, c, k, a;

for (i = 0; i < 50; i++)
f[i] = 0;

printf("Enter how many blocks already allocated: ");
scanf("%d", &p);

printf("Enter blocks already allocated:\n");
for (i = 0; i < p; i++) {
scanf("%d", &a);
f[a] = 1;
}

start:
printf("\nEnter starting block and length of file: ");
scanf("%d %d", &st, &len);

if (f[st] == 0) {
k = st;
for (j = st; j < st + len; j++) {
if (f[j] == 0) {
f[j] = 1;
printf("%d ---> %d allocated\n", j, f[j]);
} else {
printf("%d Block is already allocated\n", j);
k++;
}
}
} else {
printf("%d starting block is already allocated\n", st);
}

printf("\nDo you want to enter more files? (1-Yes, 0-No): ");
scanf("%d", &c);

if (c == 1)
goto start;

return 0;
}
