#include<Stdio.h>
#include<stdlib.h>
#define SIZE 10

int pq[SIZE];
int f=0, r=-1;

void enqueue(int data){
    if(r==-1){
        pq[++r]=data;
        printf("Element inserted.\n");
        return;
    }
    else if(r==SIZE-1){
        printf("Queue overflow condition\n");
        return;
    }
    int i=r;
    while(pq[i]>data && i>=f){
        pq[i+1]=pq[i];
        i--;
    }
    pq[i+1]=data;
    r = r+1;
    printf("Element inserted.\n");
}

void dequeue(){
    if(f>r){
        printf("Queue underflow condition.\n");
        printf("Reinitialising Queue for Re-Usage\n");
        f=0; r=-1;
    }
    printf("%d dequeued from the queue.\n", pq[f++]);
}

void display(){
    if(f>r || (f==0 && r==-1)){
        printf("No elements to display.\n");
        return;
    }
    printf("Displaying Queue : ");
    int i=f;
    while(i<=r){
        printf("%d\t", pq[i++]);
    }
    printf("\n");
}

int main(){
    printf("Choices\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter choice : ");
    int ch, data;
    scanf("%d", &ch);
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
            case 4 : printf("Terminating Program...\n");
            exit(0);
            break;
            default : printf("Invalid Choice\n");
            break; 
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }    
}
