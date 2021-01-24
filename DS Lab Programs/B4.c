#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
}Node;

Node * head=NULL;

Node * createnewNode(Node * prev, Node * next){
    Node * new = (Node *)malloc(sizeof(Node));
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    new->data = data;
    new->next = next;
    new->prev = prev;
    return new;
}

Node * insertBeg(){
    if(head==NULL){
        head = createnewNode(NULL, NULL);
        head->next=head;
        head->prev=head;
        return head;
    }
    Node * end = head;
    while(end->next!=head){
            end=end->next;
    }
    Node * new = createnewNode(end, head);
    end->next = new;
    head->prev = new;
    head = new;
    return head;
}

Node * insertEnd(){
    if(head==NULL){
        Node * new = createnewNode(NULL, NULL);
        head->next=head;
        head->prev=head;
        return head;
    }
    Node * ptr = head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    Node * new = createnewNode(ptr, head);
    ptr->next = new;
    head->prev = new;
    return head;
}

Node * search(int data){
    Node * ptr = head;
    while(ptr!=NULL){
        if(ptr->data==data) 
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Node * insertMid(){
    int ch, srcdata;
    printf("1. Insert before a specific node\n2. Insert after a specific node\n");
    printf("Enter option : ");
    scanf("%d", &ch);
    if(ch==1){
        printf("Enter node before which you want to insert : ");
        scanf("%d",&srcdata);
        Node * sptr = search(srcdata);
        if(sptr==NULL){
            printf("No such node found.\n");
            return NULL;
        }
        if(sptr==head){
            head = insertBeg(head);
            return head;
        }
        Node * new = createnewNode(sptr->prev, sptr);
        sptr->prev->next = new;
        sptr->prev = new;
        return head;
    }
    else{
        printf("Enter node after which you wanna insert : ");
        scanf("%d", &srcdata);
        Node * sptr = search(srcdata);
        if(sptr==NULL){
            printf("No such node found.\n");
            return NULL;
        }
        Node * end = head;
        while(end->next!=head){
            end=end->next;
        }
        if(sptr==end){
            head = insertEnd();
            return head;
        }
        Node * new = createnewNode(sptr, sptr->next);
        sptr->next->prev = new;
        sptr->next = new;
        return head;
    }
}

void delete(int data){
    Node * delptr = search(data);
    if(delptr==NULL){
        printf("No such node exists.\n");
        return;
    }
    if(delptr==head)
        head= head->next; 
    delptr->prev->next = delptr->next;
    delptr->next->prev = delptr->prev;
    printf("%d deleted.\n", delptr->data);
    free(delptr);
}

void display(){
    Node * ptr = head;
    if(head==NULL){
        printf("No elements to display.\n");
        return;
    }
    printf("Displaying List : ");
    if(head->next==head){
        printf("%d\t", head->data);
        printf("\n");
        return;
    }
    while(ptr->next!=head){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
}

int main(){
    printf("Choices\n1. Insert Beginning\n2. Insert End\n3. Insert Middle\n4. Delete\n5. Display\n6. Exit\n");
    printf("Enter choice : ");
    int ch, del;
    scanf("%d", &ch);
    while(1){
        switch(ch){
            case 1 : insertBeg();
            break;
            case 2 : insertEnd();
            break;
            case 3 : insertMid();
            break;
            case 4 : printf("Enter data to be deleted : ");
            scanf("%d",&del);
            delete(del);
            break;
            case 5 : display();
            break;
            case 6 : printf("Terminating Program...\n");
            exit(0);
            break;
            default :  printf("Invalid Choice\n");
            break;
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }
}