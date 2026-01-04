#include <stdio.h>
#include <string.h>
#include <math.h>

int st[50], top=-1;

int main(){
    char p[50];
    int a,b,i;
    printf("Enter postfix expression: ");
    scanf("%s", p);

    for(i=0; p[i]; i++){
        if(p[i] >= '0' && p[i] <= '9') st[++top] = p[i]-'0';
        else {
            b = st[top--];
            a = st[top--];
            switch(p[i]) {
                case '+': st[++top] = a+b; break;
                case '-': st[++top] = a-b; break;
                case '*': st[++top] = a*b; break;
                case '/': st[++top] = a/b; break;
                case '^': st[++top] = pow(a,b);
            }
        }
    }

    printf("%d\n", st[top]);
    return 0;
}
