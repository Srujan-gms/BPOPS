#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir;

int main() {
    int i, ch;
    char f[30];
    dir.fcnt = 0;

    printf("Enter name of directory: ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n\n1. Create File");
        printf("\n2. Delete File");
        printf("\n3. Search File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (dir.fcnt < 10) {
                    printf("Enter the name of the file: ");
                    scanf("%s", dir.fname[dir.fcnt]);
                    dir.fcnt++;
                } else {
                    printf("Directory is full!");
                }
                break;

            case 2:
                printf("Enter the name of the file to delete: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s deleted.\n", f);
                        strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]); // Replace with last file
                        dir.fcnt--;
                        break;
                    }
                }
                if (i == dir.fcnt)
                    printf("File %s not found.\n", f);
                break;

            case 3:
                printf("Enter the name of the file to search: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s found.\n", f);
                        break;
                    }
                }
                if (i == dir.fcnt)
                    printf("File %s not found.\n", f);
                break;

            case 4:
                if (dir.fcnt == 0)
                    printf("Directory is empty.\n");
                else {
                    printf("The files are: ");
                    for (i = 0; i < dir.fcnt; i++)
                        printf("%s\t", dir.fname[i]);
                    printf("\n");
                }
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
                getchar();
        }
    }

    return 0;
}