#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

Node * head = NULL;
int count=0;

Node * creatnewNode(Node * prev, Node * next){
    int m ;
    printf("Enter data for the node : ");
    scanf("%d", &m);
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = m;
    new->prev = prev;
    new->next = next;
    count++;
    return new;
}

Node * endOfList(Node * head){
    Node * ptr = head;
    int c = count;
    while(c>1){
        ptr=ptr->next;
        c--;
    }
    return ptr;
}

Node * search(int data){
    Node * ptr = head;
    int c = count;
    while(c>0){
        if(ptr->data == data){
            return ptr;
        }
        ptr = ptr->next;
        c--;
        continue;
    }
    int dat;
    printf("\nNODE NOT FOUND. ENTER DATA AGAIN : ");
    scanf("%d", &dat);
    search(dat);
    
}

Node * insertBeg(){
    if(head==NULL){
        Node * new = creatnewNode(NULL, NULL);
        head = new;
        head->next = head;
        head->prev = head;
        return head;
    }
    Node * tail = endOfList(head);
    Node * new = creatnewNode(tail, head);
    head->prev = new;
    tail->next = new;
    head = new;
    return head;
}

Node * insertEnd(){
    if(head==NULL){
        Node * new = creatnewNode(NULL, NULL);
        head = new;
        head->next = head;
        head->prev = head;
        return head;
    }
    Node * tail = endOfList(head);
    Node * new = creatnewNode(tail, head);
    head->prev = new;
    tail->next = new;
    tail = new;
    return head;
}

Node * insertMid(){
    if(head == NULL){
        Node * new = creatnewNode(NULL, NULL);
        head = new;
        head->next = head;
        head->prev = head;
        return head;
    }
    int ch, m;
    printf("Press 1 to insert after the node  , 2 to insert before the node : ");
    scanf("%d", &ch);
    if(ch==1){
        printf("Enter node after which you want to insert : ");
        scanf("%d",&m);
        Node * ptr = search(m);
        Node * new = creatnewNode(ptr, ptr->next);
        ptr->next = new;
        ptr->next->prev = new;
        return head;
    }
    else if(ch==2){
        printf("Enter node before which you want to insert : ");
        scanf("%d",&m);
        Node * ptr = search(m);
        Node * new = creatnewNode(ptr->prev, ptr); 
        new->prev->next = new;
        new->next->prev = new;
        return head;
    }
}

void display(Node * head){
    Node * ptr = head;
    int c = count;
    printf("\n");
    printf("------DISPLAYING LINKED LIST-----\n");
    while(c>0){
        printf("%d \t", ptr->data);
        ptr = ptr->next;
        c--;
    }
    printf("\n-----END OF LINKED LIST-----\n");
}

int main(){
    int ch;
    printf("----------STARTING PROGRAM----------\n\n");
    printf("Press 1 to Insert in Beginning, 2 to Insert at end, 3 to Insert Middle, 4 to display Linked List, 5 to Exit program : ");
    scanf("%d", &ch);
    while(ch>0){
        if(ch==1){
            head  =  insertBeg();
        }
        else if(ch==2){
            head = insertEnd();
        }
        else if(ch==3){
            head = insertMid();
        }
        else if(ch==4){
            display(head);
        }
        else if(ch==5){
            break;
        }
        else{
            printf("INVALID CHOICE\n");
        }
        printf("Press 1 to Insert in Beginning, 2 to Insert at end, 3 to Insert Middle, 4 to display Linked List, 5 to Exit program : ");
        scanf("%d", &ch);
    }
    printf("\n----------END OF PROGRAM----------");
}
