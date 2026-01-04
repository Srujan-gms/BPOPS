#include <stdio.h>

void hanoi(int n, char A, char C, char B) {
    if(n==1){
        printf("Move 1 from %c to %c\n", A, C);
        return;
    }
    hanoi(n-1, A, B, C);
    printf("Move %d from %c to %c\n", n, A, C);
    hanoi(n-1, B, C, A);
}

int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    hanoi(n,'A','C','B');
    return 0;
}
