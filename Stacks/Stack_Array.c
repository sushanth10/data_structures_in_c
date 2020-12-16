#include<stdio.h>
#include<stdlib.h>
 
#define MAXSIZE 5

int stack[MAXSIZE];
int top = -1;

void push(){
    if(top == MAXSIZE-1){
        printf("Stack overflow condition.\n");
        return;
    }
    int m;
    printf("Enter data to be pushed into the stack : ");
    scanf("%d",&m);
    stack[++top] = m;
    printf("Inserted data.\n");
}

int pop(){
    if(top == -1){
        printf("Stack Underflow condition\n");
        return -1;
    }
    return stack[top--];
}

void display(){
    int c = top;
    printf("---------------\n");
    printf("DISPLAYING STACK\n");
    while(c>-1){
        printf("%d\t", stack[c--]);
    }
    printf("\n---------------\n");
}

int main(){
    int ch;
    printf("Press 0 to exit the program, 1 to push into stack, 2 to pop out of stack, 3 to display elements : ");
    scanf("%d", &ch);
    while(1){
        if(ch==0){
            break;
        }
        else if(ch==1){
            push();
        }
        else if(ch==2){
            int m = pop();
            printf("The element popped out of the stack is %d \n", m);  
        }
        else if(ch==3){
            display();
        }
        else{
            printf("INVALID CHOICE \n");
        }
        printf("Press 0 to exit the program, 1 to push into stack, 2 to pop out of stack, 3 to display elements : ");
        scanf("%d", &ch);
    }
}