#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 50

char infix[SIZE], postfix[SIZE], st[SIZE];
int top=-1;

void push(char x){
    st[++top] = x;
}

char pop(){
    return st[top--];
}

int priority(char x){
    if(x=='(') return 0;
    else if(x=='+' || x=='-') return 1;
    else if(x=='*' || x=='/' || x=='%') return 2;
    else if(x=='^') return 3;
}

void infixtopostfix(char infix[], char postfix[]){
    int i=0, j=0;
    char symbol;
    while((symbol=infix[i++])!='\0'){
        if(isalnum(symbol)) 
            postfix[j++]=symbol;
        else if(symbol=='(')
            push(symbol);
        else if(symbol==')'){
            while(st[top]!='(')
                postfix[j++]=pop();
            pop();
        }
        else{
            while(priority(symbol) <= priority(st[top])){
                postfix[j++]= pop();
            }
            push(symbol);
        }
    }
    while(st[top]!='\0'){
        postfix[j++] = pop();
    }
}

void main(){
    printf("Enter a vaid infix expression : ");
    scanf("%s", infix);
    printf("Resulting postfix expresion : ");
    infixtopostfix(infix, postfix);
    printf("%s", postfix);
}