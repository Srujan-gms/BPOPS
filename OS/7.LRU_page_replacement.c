#include <stdio.h>

int findLRUVictim(int time[], int n) {
int min = time[0], pos = 0;
for (int i = 1; i < n; i++) {
if (time[i] < min) {
min = time[i];
pos = i;
}
}
return pos;
}

int main() {
int nof, nor, ref[50], frame[10], time[10];
int count = 0, flag1, flag2, pos, faults = 0;

printf("Enter number of frames: ");
scanf("%d", &nof);
printf("Enter length of reference string: ");
scanf("%d", &nor);
printf("Enter the reference string:\n");
for (int i = 0; i < nor; i++) {
scanf("%d", &ref[i]);
}

for (int i = 0; i < nof; i++) {
frame[i] = -1;
}

printf("\nRef\tFrames\n");

for (int i = 0; i < nor; i++) {
flag1 = flag2 = 0;

for (int j = 0; j < nof; j++) {
if (frame[j] == ref[i]) {
count++;
time[j] = count;
flag1 = flag2 = 1;
break;
}
}

if (flag1 == 0) {
for (int j = 0; j < nof; j++) {
if (frame[j] == -1) {
faults++;
count++;
frame[j] = ref[i];
time[j] = count;
flag2 = 1;
break;
}
}
}

if (flag2 == 0) {
pos = findLRUVictim(time, nof);
count++;
frame[pos] = ref[i];
time[pos] = count;
faults++;
}

printf("%d\t", ref[i]);
for (int j = 0; j < nof; j++) {
if (frame[j] != -1)
printf("%d ", frame[j]);
else
printf("- ");
}
printf("\n");
}

printf("\nTotal Page Faults = %d\n", faults);
return 0;
}