#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * head = NULL;
int count = 0;

Node * createNewNode(Node * next){
    Node * new = (Node *)malloc(sizeof(Node));
    printf("Enter data for the node : ");
    int data;
    scanf("%d", &data);
    new->data = data;
    new->next = next;
    ++count;
    return new;
}

Node * push(){
    if(head==NULL){
        head = createNewNode(NULL);
        return head;
    }
    else if(count==SIZE){
        printf("Stack overflow condition\n");
        return head;
    }
    Node * new = createNewNode(head);
    head = new;
    return head;
}

void pop(){
    if(head==NULL){
        printf("Stack Underflow Condition\n");
        return;
    }
    Node * temp = head;
    head = head->next;
    free(temp);
    printf("Element deleted.\n");
    count--;
}

void display(){
    Node * ptr = head;
    int c=count;
    printf("Displaying Stack : ");
    while(c>0){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
        c--;
    }
    printf("\n");
}

int main(){
    printf("Enter\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    int ch;
    printf("Enter choice : ");
    scanf("%d", &ch);
    while(1){
        switch(ch){
            case 1: push();
            break;
            case 2 : pop();
            break;
            case 3 : display();
            break;
            case 4 : printf("Terminating Program....\n");
            exit(0);
            break;
            default :  printf("Invalid Choice\n");
            break;
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }
    }