#include <stdio.h>
#include <stdlib.h>

int request[50];
int SIZE;
int head;
int pre;

struct track {
int up;
int down;
} kate[50];

int dist(int a, int b) {
return abs(a - b);
}

void sort(int n) {
int i, j, temp;

for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (request[j] > request[j + 1]) {
temp = request[j];
request[j] = request[j + 1];
request[j + 1] = temp;
}
}
}
}

void scan(int n) {
int i, j = 0;
int uptrack = 0, downtrack = 0;
int seekcount = 0;

sort(n);

i = 0;
while (request[i] < head)
kate[downtrack++].down = request[i++];

while (i < n)
kate[uptrack++].up = request[i++];

printf("\nSCAN Seek Sequence:\n");

if (pre < head) {
for (i = downtrack - 1; i >= 0; i--) {
printf("%d ", head);
seekcount += dist(head, kate[i].down);
head = kate[i].down;
}
for (i = 0; i < uptrack; i++) {
printf("%d ", head);
seekcount += dist(head, kate[i].up);
head = kate[i].up;
}
} else {
for (i = 0; i < uptrack; i++) {
printf("%d ", head);
seekcount += dist(head, kate[i].up);
head = kate[i].up;
}
for (i = downtrack - 1; i >= 0; i--) {
printf("%d ", head);
seekcount += dist(head, kate[i].down);
head = kate[i].down;
}
}

printf("\nTotal Head Movement = %d\n", seekcount);
}

int main() {
int n, i;

printf("Enter disk size: ");
scanf("%d", &SIZE);

printf("Enter number of requests: ");
scanf("%d", &n);

printf("Enter request sequence:\n");
for (i = 0; i < n; i++)
scanf("%d", &request[i]);

printf("Enter current head position: ");
scanf("%d", &head);

printf("Enter previous head position: ");
scanf("%d", &pre);

scan(n);

return 0;
}
