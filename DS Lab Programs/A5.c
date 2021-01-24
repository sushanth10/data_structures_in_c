#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int cq[SIZE];
int f=0, r=-1, count=0;

void enqueue(int data){
    if(count==SIZE){
        printf("Queue overflow condition.\n");
        return;
    }
    r = (r+1)%SIZE;
    cq[r] = data;
    count++;
    printf("Inserted data into the queue\n");
}

void dequeue(){
    if(count==0){
        printf("Queue underflow condition\n");
        return;
    }
    int m = cq[f];
    f = (f+1)%SIZE;
    count--;
    printf("%d was dequeued from the queue\n", m);
}

void display(){
    int c = count;
    if(count==0){
        printf("No elements to display.\n");
        return;
    }
    printf("Displaying Queue : ");
    for(int i=f; c>0; i=(i+1)%SIZE){
        c--;
        printf("%d\t",cq[i]);
    }
    printf("\n");
}

void main(){
    printf("Enter\n1. Enqueue\n2. Dequeue\n3. Display\n4. EXIT\n");
    printf("Enter choice : ");
    int ch, data;
    scanf("%d", &ch);
    while(1){
        switch (ch){
        case 1 : printf("Enter data : ");
                scanf("%d", &data);
                enqueue(data);
        break;
        case 2 : dequeue();
        break;
        case 3 : display();
        break;
        case 0 : printf("Terminating Program.....\n");
                exit(0);
                break;
        default : printf("Invalid Choice\n");
        break;
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }
}