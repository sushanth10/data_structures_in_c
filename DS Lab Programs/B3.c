#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * head = NULL;
Node * tail = NULL;

Node * createnewNode(Node * next){
    Node * new = (Node *)malloc(sizeof(Node));
    int data;
    printf("Enter data : ");
    scanf("%d",&data);
    new->data = data;
    new->next = next;
    return new;
}

Node * insertBeg(){
    if(head==NULL){
        head = createnewNode(NULL);
        return head;
    }
    Node * new = createnewNode(head);
    head = new;
    return head;
}

Node * insertEnd(){
    if(head==NULL){
        head = createnewNode(NULL);
        return head;
    }
    Node * ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    Node * new = createnewNode(NULL);
    ptr->next = new;
    tail = new;
    return head;
}

Node * search(int data){
    Node * sptr = head;
    while(head!=NULL && sptr!=NULL){
        if(sptr->data==data) return sptr;
        sptr=sptr->next;
    }
    return NULL;
}

Node * insertMid(){
    int ch;
    printf("1. To insert before a particular node\n2. To insert After a particular Node\n");
    printf("Enter option : ");
    scanf("%d",&ch);
    if(ch==1){
        int srcdata;
        printf("Enter node before which you want to insert : ");
        scanf("%d", &srcdata);
        Node * sptr = search(srcdata);
        if(sptr==NULL){
            printf("Node not found.\n"); return NULL;
        }
        if(sptr==head){
            head = insertBeg(head);
            return head;
        }
        Node * prevptr = head;
        while(prevptr->next!=sptr){
            prevptr = prevptr->next;
        }
        Node * new = createnewNode(sptr);
        prevptr->next = new;
        return head;
    }
    else if(ch==2){
        int srcdata;
        printf("Enter node after which you want to insert : ");
        scanf("%d",&srcdata);
        Node * sptr = search(srcdata);
        if(sptr==NULL){
            printf("Node not found.\n"); return NULL;
        }
        if(sptr==tail){
            head = insertEnd();
            return head;
        }
        Node * new = createnewNode(sptr->next);
        sptr->next = new;
        return head;
    }
}

void display(){
    Node * ptr = head;
    if(head==NULL){
        printf("No elements to display.\n");
        return;
    }
    printf("Displaying List : ");
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void delete(int data){
    if(head==NULL){
        printf("No elements. Nothing tod delete.\n");
        return;
    }
    Node * temp = search(data);
    if(temp==NULL){
        printf("No such Node found.\n");
        return;
    }
    if(temp==head){
        head = head->next;
        free(temp);
        return;
    }
    if(temp==tail){
        Node * prevptr = head;
        while(prevptr->next!=tail){
            prevptr = prevptr->next;
        }
        tail = prevptr;
        tail->next=NULL;
        free(temp);
        return;
    }
    Node * prevptr = head;
    while(prevptr!=NULL){
        if(prevptr->next->data == data) break;
        prevptr = prevptr->next;
    }
    prevptr->next = temp->next;
    free(temp);
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