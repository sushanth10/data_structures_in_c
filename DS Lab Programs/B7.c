#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

Node * head = NULL;
Node * tail = NULL;

Node * createnewNode(Node * prev, Node * next){
    Node * new = (Node *)malloc(sizeof(Node));
    new->next = next;
    new->prev = prev;
    return new;
}

Node * search(int data){
    Node * sptr = head;
    if(head==NULL){
        printf("No elements inserted.\n");
        return NULL;
    }
    while(sptr!=NULL){
        if(data<sptr->data)
            return sptr;
        sptr = sptr->next; 
        }      
}

Node * insert(){
    int data;
    printf("Enter data to be inserted : ");
    scanf("%d", &data);
    if(head==NULL){
        Node * new = createnewNode(NULL, NULL);
        new->data = data;
        head = new;
        tail = new;
    }
    else{
        if(search(data)==head){
            Node * new = createnewNode(NULL, head);
            new->data = data;
            head->prev = new;
            head = new;
        }
        else if(search(data)==NULL){
            Node * new = createnewNode(tail, NULL);
            tail->next = new;
            new->data = data;
            tail = new;
        }
        else{
            Node * sptr = search(data);
            
            Node * new = createnewNode(sptr->prev, sptr);
            new->data = data;
            sptr->prev->next = new;
            sptr->prev = new;
        }
    }
    printf("%d was inserted\n", data);
    return head;
}

Node * display(){
    Node * ptr = head;
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() //Driver Code
{
    head = NULL;
    int command;

    printf("Press 1 for inserting record, 2 for Printing records : ");
    scanf("%d", &command);

    while (command == 1)
    {

        head = insert();
            display();


        printf("Press 1 for inserting record, 2 for Printing records : ");
        scanf("%d", &command);
    }

    display();

    return 0;
}
