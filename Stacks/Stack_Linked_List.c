#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * head = NULL;

Node * createNewNode(Node * next){
    int m;
    Node * new = (Node *)malloc(sizeof(Node));
    printf("Enter Node data : ");
    scanf("%d",&m);
    new->data = m;
    new->next = next;
    return new;
}

void display(){
    if(head == NULL){
        printf("Stack Underflow condition.\n");
        return;
    }
    Node * ptr= head;
    printf("-----DISPLAYING STACK-----\n");
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n-----END OF STACK-----\n");
}

void push(){
    if(head == NULL){
        Node * new = createNewNode(NULL);
        head = new;
        printf("First node created.\n");
    }
    else{
        Node * new = createNewNode(head);
        head = new;
        printf("Inserted element.\n");
    }
    
}

void pop(){
    if(head==NULL){
        printf("Stack Underflow Condition\n");
        return;
    }
    else{
        Node * temp = head;
        printf("%d was popped out of the stack.\n",temp->data);
        head = head->next;
        free(temp);
    }
}

int main(){
    int ch;
    printf("-----STARTING PROGRAM EXECUTION-----\n");
    printf("Press 1 to push into stack, 2 to pop element out, 3 to display, 0 to exit program : ");
    scanf("%d", &ch);
    while(1){
        if(ch==1){
            push();
        }
        else if(ch==2){
            pop();
        }
        else if(ch==3){
            display();
        }
        else if(ch==0){
            break;
        }
        else{
            printf("INVALID INPUT\n");
        }
        printf("Press 1 to push into stack, 2 to pop element out, 3 to display, 0 to exit program : ");
        scanf("%d", &ch);
    }
    printf("-----END OF PROGRAM EXECUTION-----\n");
}