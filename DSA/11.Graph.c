#include<stdio.h>
#include<stdlib.h>

int a[38][38], n, visited[38];
int q[39], front = -1, rear = -1;
int s[39], top = -1;

void bfs(int v) {
int i, cur;
visited[v] = 1;
printf("%d ", v);
q[++rear] = v;
while (front < rear) {
cur = q[++front];
for (i = 1; i <= n; i++) {
if ((a[cur][i] == 1) && (visited[i] == 0)) {
q[++rear] = i;
visited[i] = 1;
printf("%d ", i);
}
}
}
}

void dfs(int v) {
int i;
visited[v] = 1;
printf("%d ", v);
s[++top] = v;
for (i = 1; i <= n; i++) {
if (a[v][i] == 1 && visited[i] == 0) {
dfs(i);
}
}
}

int main() {
int ch, start, i, j;
printf("\nEnter number of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (i = 1; i <= n; i++)
for (j = 1; j <= n; j++)
scanf("%d", &a[i][j]);
while (1) {
front = -1; rear = -1; top = -1;
for (i = 1; i <= n; i++) visited[i] = 0;
printf("\nEnter starting vertex: ");
scanf("%d", &start);
printf("\n1. BFS\t2. DFS\t3. Exit\nChoice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
printf("\nNodes reachable: "); bfs(start);
for (i = 1; i <= n; i++) if (visited[i] == 0) printf("\nNot reachable: %d", i);
break;
case 2:
printf("\nNodes reachable: "); dfs(start); break;
case 3: exit(0);
}
}
return 0;
}
