#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define SIZE 50

int stack[SIZE];
int top=-1;

void push(int data){
    stack[++top]=data;
}

int pop(){
    return stack[top--];
}

int main(){
    char x;
    int m, n;
    printf("Enter a valid postfix expression : ");
    while((x=getchar()) != '\n'){
        if(isdigit(x)){
            push(x-'0');
        }
        else{
            m = pop();
            n = pop();
            switch (x){
                case '+' : push(n+m);
                break;
                case '-' : push(n-m);
                break;
                case '*' : push(n*m);
                break;
                case '/' : 
                if(m==0){
                    printf("Division by zero error\n");
                    return 0;
                }
                push(n/m);
                break;
                case '%' : push(n%m);
                break;
                case '^' : push(pow(n,m));
                break;
            }
        }
    }
    printf("\nThe result of the postfix expression is %d",pop());
    return 0;
}