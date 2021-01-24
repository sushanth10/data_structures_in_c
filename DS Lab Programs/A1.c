#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int stack[SIZE];
int top=-1;

void push(int data){
    if(top==SIZE-1){
        printf("Stack overflow condition \n");
        return;
    }
    stack[++top] = data;
    printf("Inserted data\n");
}

void pop(){
    if(top==-1){
        printf("Stack underflow condition\n");
        return;
    }
    printf("%d is popped out of the stack\n",stack[top--]);
}

void display(){
    printf("Displaying Stack : ");
    int i=top;
    while(i>=0){
        printf("%d\t", stack[i--]);
    }
    printf("\n");
}

int main(){
    int ch, data;
    printf("Operations\n1. Push\n2. Pop\n3. Display\n0. Exit\n\n");
    printf("Enter choice : ");
    scanf("%d", &ch);
    while(1){
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            push(data);
            break;
        case 2 : pop();
            break;
        case 3 : display();
            break;
        case 0: 
            printf("Terminating Program\n"); 
            exit(0);
        break;      
        default: printf("Invalid Choice\n");
            break;
        }
        printf("Enter choice : ");
        scanf("%d", &ch);   
    }      
}