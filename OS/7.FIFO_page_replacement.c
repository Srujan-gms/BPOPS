#include <stdio.h>

int main() {
int i, j, k, n, no, page[50], frame[10];
int avail, count = 0;

printf("ENTER THE NUMBER OF PAGES: ");
scanf("%d", &n);
printf("ENTER THE PAGE NUMBERS:\n");
for (i = 0; i < n; i++) {
scanf("%d", &page[i]);
}
printf("ENTER THE NUMBER OF FRAMES: ");
scanf("%d", &no);

for (i = 0; i < no; i++)
frame[i] = -1;

j = 0;

printf("\nRef string\tPage frames\n");

for (i = 0; i < n; i++) {
printf("%d\t\t", page[i]);
avail = 0;

for (k = 0; k < no; k++) {
if (frame[k] == page[i]) {
avail = 1;
break;
}
}

if (avail == 0) {
frame[j] = page[i];
j = (j + 1) % no;
count++;

for (k = 0; k < no; k++) {
if (frame[k] != -1)
printf("%d ", frame[k]);
else
printf("- ");
}
}
printf("\n");
}

printf("\nTotal Page Faults = %d\n", count);
return 0;
}