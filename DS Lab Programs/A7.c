//Queues  using Singly Linked List
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * front = NULL;
Node * rear = NULL;
int count=0;

Node * createNewNode(Node * next){
    Node * new = (Node *)malloc(sizeof(Node));
    printf("Enter data : ");
    int m;
    scanf("%d", &m);
    new->data = m;
    new->next = next;
    ++count;
    return new;
}

void enqueue(){
    if(count==SIZE){
        printf("Queue Overflow Condition\n");
        return;
    }
    else if(count==0){
        front = createNewNode(NULL);
        rear = front;
        printf("Inserted element\n");
        return;
    }
    Node * new = createNewNode(NULL);
    rear->next = new;
    rear = new;
    printf("Inserted element\n");
}

void dequeue(){
    if(count==0){
        printf("Queue underflow condition\n");
        return;
    }
    Node * temp = front;
    front = front->next;
    free(temp);
    printf("Element dequeued\n");
    count--;
}

void display(){
    Node * ptr = front;
    printf("Displaying Queue : ");
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\nEnd of Queue\n");
}

int main(){
    int ch;
    printf("Choices\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter choice : ");
    scanf("%d", &ch);
    while(1){
        switch(ch){
            case 1 : enqueue();
            break;
            case 2 : dequeue();
            break;
            case 3 : display();
            break;
            case 4 : printf("Terminating program...\n");
            exit(0);
            break;
            default : printf("Invalid Choice\n");
            break;
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }
}