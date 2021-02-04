#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * front = NULL;
Node * rear = NULL;

Node * createNewNode(Node * next){
    int m;
    Node * new = (Node *)malloc(sizeof(Node));
    printf("Enter node data : ");
    scanf("%d",&m);
    new->data = m;
    new->next = next;
}

void enqueue(){
    if(front==NULL){
        front = createNewNode(NULL);
        rear = front;
        return;
    }
    Node * new = createNewNode(NULL);
    rear->next = new;
    rear = new;
}

void dequeue(){
    if(front==NULL){
        printf("Queue underflow \n");
        return;
    }
    else{
        Node * temp = front;
        printf("Dequeued element : %d\n",temp->data);
        front = front->next;
        free(temp);
    }
}

void display(){
    Node * ptr = front;
    if(ptr==NULL){
        printf("Queue is empty\n");
        return;
    }
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    int ch;
    printf("Enter 1 to enqueue element, 2 to dequeue, 3 to display, 0 to exit.\n");
    printf("Enter choice : ");
    scanf("%d",&ch);
    while(1){
        if(ch==1)
            enqueue();
        else if(ch==2)
            dequeue();
        else if(ch==3)
            display();
        else if(ch==0)
            break;
        else
            printf("Invalid choice\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
    }
    printf("END\n");
    return 0;
}



