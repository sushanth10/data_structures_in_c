#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front=0, rear=-1;

void enqueue(int data){
    if(rear==MAXSIZE-1){
        printf("Queue overflow condition\n");
        return;
    }
    queue[++rear] = data;
    printf("Element added to the queue\n");
}

void dequeue(){
    if(front>rear || (front==0 && rear==-1)){
        printf("Queue underflow condition\n");
        return;
    }
    printf("Element dequeued is %d\n", queue[front++]);
}

void display(){
    if(front>rear || (front==0 && rear==-1)){
        printf("No elements to display\n");
        return;
    }
    int i=front;
    printf("Displaying Queue : ");
    while(i<=rear){
        printf("%d\t", queue[i++]);
    }
    printf("\n");
}

int main(){
    int ch, data;
    printf("Enter\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
    printf("Enter Choice : ");
    scanf("%d",&ch);
    while(1){
        switch(ch){
            case 1 : printf("Enter data : ");
                    scanf("%d", &data);
                    enqueue(data);
                    break;
            case 2 : dequeue();
            break;
            case 3 : display();
            break;
            case 0 : printf("Terminating Program\n");
                    exit(0);
            break;
            default : printf("Invalid Choice\n");
            break;
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }
}