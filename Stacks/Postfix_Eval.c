#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAXSIZE 100

int st[MAXSIZE], top=-1;

void push(int m){
    if(top == MAXSIZE-1){
        printf("Stack is in overflow condition.\n");
        return;
    }
    st[++top] = m;
}

int pop(){
    if(top==-1){
        printf("Stack underflow condition.\n");
        return 0;
    }
    return st[top--];
}

int main(){
    char x;
    int m, n;
    printf("Enter the postfixx expression : \n");
    while((x=getchar()) - '\n'){
        if(isdigit(x)){
            push(x-'0');
        }
        else{
            m = pop();
            n = pop();
            switch(x){
                case '+' : push(n+m);
                break;
                case '*' : push(n*m);
                break;
                case '/' : push(n/m);
                break;
                case '-' : push(n-m);
                break;
                case '^' : push(pow(n,m));
                break;
                case '%' : push(n%m);
                break;
            }
        }
    }
    printf("Final result of the postfix expression is %d", pop());
    return 0;
}