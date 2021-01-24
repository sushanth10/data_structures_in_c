//Stacks using Circular Linked List
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct Node {
    int data;
    struct Node * next;
}Node;

Node * top = NULL;
Node * end = NULL;
int count=0;

Node * createnewNode(Node * next){
    Node * new = (Node *)malloc(sizeof(Node));
    int m;
    printf("Enter data : ");
    scanf("%d",&m);
    new->data = m;
    new->next = next;
}

void push(){
    if(top==NULL){
        top = createnewNode(NULL);
        top->next = top;
        end=top;
        return;
    }
    Node * new = createnewNode(top);
    top = new;
    end->next = top;
}

void pop(){
    if(top==NULL){
        printf("Stack underflow condition\n");
        return;
    }
    Node * temp = top;
    top = top->next;
    printf("%d popped out of the stack\n", temp->data);
    free(temp);
}

void display(){
    if(top==NULL){
        printf("No elements to display\n");
        return;
    }
    printf("Displaying Stack : ");
    Node * ptr = top;
    while(ptr->next!=top){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
}

int main(){
    printf("Choices\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("Enter choice  : ");
    int ch;
    scanf("%d", &ch);
    while(1){
        switch(ch){
            case 1: push();
            break;
            case 2 : pop();
            break;
            case 3 :  display();
            break;
            case 4 : printf("Terminating Program....\n");
            exit(0);
            break;
            default : printf("Invalid Choice\n");
            break;
        }
        printf("Enter choice  : ");
        scanf("%d", &ch);
    }
}