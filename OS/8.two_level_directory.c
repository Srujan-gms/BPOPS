#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
char dname[10];
char fname[10][10];
int fcnt;
} dir[10];

int main() {
int i, ch, dcnt = 0, k;
char f[30], d[30];

while (1) {
printf("\n\n1. Create Directory");
printf("\n2. Create File");
printf("\n3. Delete File");
printf("\n4. Search File");
printf("\n5. Display");
printf("\n6. Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);

switch (ch) {
case 1:
if (dcnt < 10) {
printf("Enter name of directory: ");
scanf("%s", dir[dcnt].dname);
dir[dcnt].fcnt = 0;
dcnt++;
printf("Directory created.\n");
} else {
printf("Directory limit reached.\n");
}
break;

case 2:
printf("Enter name of the directory: ");
scanf("%s", d);
for (i = 0; i < dcnt; i++) {
if (strcmp(d, dir[i].dname) == 0) {
if (dir[i].fcnt < 10) {
printf("Enter name of the file: ");
scanf("%s", dir[i].fname[dir[i].fcnt]);
dir[i].fcnt++;
printf("File created.\n");
} else {
printf("File limit reached in directory %s.\n", d);
}
break;
}
}
if (i == dcnt)
printf("Directory %s not found.\n", d);
break;

case 3:
printf("Enter name of the directory: ");
scanf("%s", d);
for (i = 0; i < dcnt; i++) {
if (strcmp(d, dir[i].dname) == 0) {
printf("Enter name of the file: ");
scanf("%s", f);
for (k = 0; k < dir[i].fcnt; k++) {
if (strcmp(f, dir[i].fname[k]) == 0) {
printf("File %s deleted.\n", f);
strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt - 1]);
dir[i].fcnt--;
goto done_delete;
}
}
printf("File %s not found.\n", f);
goto done_delete;
}
}
printf("Directory %s not found.\n", d);
done_delete:
break;

case 4:
printf("Enter name of the directory: ");
scanf("%s", d);
for (i = 0; i < dcnt; i++) {
if (strcmp(d, dir[i].dname) == 0) {
printf("Enter name of the file: ");
scanf("%s", f);
for (k = 0; k < dir[i].fcnt; k++) {
if (strcmp(f, dir[i].fname[k]) == 0) {
printf("File %s found in directory %s.\n", f, d);
goto done_search;
}
}
printf("File %s not found in directory %s.\n", f, d);
goto done_search;
}
}
printf("Directory %s not found.\n", d);
done_search:
break;

case 5:
if (dcnt == 0)
printf("No directories found.\n");
else {
printf("\nDirectory\tFiles\n");
for (i = 0; i < dcnt; i++) {
printf("%s\t\t", dir[i].dname);
for (k = 0; k < dir[i].fcnt; k++)
printf("%s\t", dir[i].fname[k]);
printf("\n");
}
}
break;

case 6:
exit(0);

default:
printf("Invalid choice.\n");
getchar();
}
}

return 0;
}