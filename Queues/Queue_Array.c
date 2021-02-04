#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 4 

int q[MAXSIZE];
int front = 0, rear = -1;

void enqueue(){
    if(rear==MAXSIZE-1){
        printf("Queue overflow condition.\n");
    }
    else{
        int m;
        printf("Enter element : ");
        scanf("%d",&m);
        q[++rear] = m;
        printf("Element added to queue.\n");
    }
}

int dequeue(){
    if(front>rear){
        printf("Empty queue.\n");
        return 0;
    }
    else{
        return q[front++];
    }
}

void display(){
    int i=front;
    while(i<=rear)
        printf("%d\t",q[i++]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int ch;
    printf("Press 1 to enqueue, 2 to dequeue, 3 to display queue, 0 to exit program\n");
    scanf("%d", &ch);
    while(1){
        if(ch==1)
            enqueue();
        else if(ch==2){
            int rem = dequeue();
            if(rem!=0) 
            printf("Element removed from the queue is %d\n",rem);
        }
        else if (ch==3)
        {
            display();
        }
        else if(ch==0){
            break;
        }
        else{
            printf("invalid choice\n");
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }
}
