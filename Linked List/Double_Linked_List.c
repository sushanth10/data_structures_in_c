#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
}Node;

Node * head  = NULL;
Node * tail = NULL;

Node * createNewNode(Node * prev, Node * next){
    int m;
    printf("Enter Node data : ");
    scanf("%d", &m);
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = m;
    new->next = next;
    new->prev = prev;
    return new;
}

Node * insertBegin(Node * prev, Node * next){
    if(head==NULL){
        Node * new = createNewNode(prev, next);
        head = new;
        tail = new;
        return head;
    }
    Node * new = createNewNode(prev, head);
    head->prev = new;
    head = new;
    return head;
}

Node * insertEnd(Node * prev, Node * next){
    if(head == NULL){
        Node * new = createNewNode(prev, next);
        head = new;
        tail = new;
        return head;
    }
    Node * new = createNewNode(prev, next);
    tail->next = new;
    tail = new;
    return head;
}

Node * insertMid(Node * prev, Node * next){
    if(head==NULL){
        Node * new = createNewNode(prev, next);
        head = new;
        tail = new;
        return head;
    }
    Node * new = createNewNode(prev, next);
    new->prev->next = new;
    new->next->prev = new;
    return head;
}

void display(Node * head){
    Node * ptr = head;
    printf("\n");
    printf("------DISPLAYING LINKED LIST-----\n");
    while(ptr!=NULL){
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n-----END OF LINKED LIST-----\n");
}

Node * search(int data){
    Node * ptr = head;
    while(ptr!=NULL){
        if(ptr->data==data){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}


void delete(int data){
    Node * ptr = search(data);
    if(ptr==head){
        head = ptr->next;
        printf("The element remove from the list is %d\n",ptr->data);
        free(ptr);
    }
    else if(ptr==tail){
        tail = ptr->prev;
        tail->next = NULL;        
        printf("The element remove from the list is %d\n",ptr->data);
        free(ptr);
    }
    else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        printf("The element remove from the list is %d\n",ptr->data);
        free(ptr);
    }
}

int main(){
    int ch;
    printf("----------STARTING PROGRAM----------\n\n");
    printf("Press 1 to Insert in Beginning, 2 to Insert at end, 3 to Insert Middle, 4 to display Linked List, 5 to delete, 0 to exit : ");
    scanf("%d", &ch);
    while(ch>0){
        if(ch==1){
            head  =  insertBegin(NULL, head);
        }
        else if(ch==2){
            head = insertEnd(tail, NULL);
        }
        else if(ch==3){
            int m;
            printf("Enter 1 for inserting after a specific node, 2 to insert before a specific node. \n");
            scanf("%d", &m);
            if(m==1){
                int n;
                printf("After which node do you want to insert?");
                scanf("%d", &n);
                Node * ptr = search(n);
                head = insertMid(ptr, ptr->next);
            }
            else{
                int n;
                printf("Before which node do you want to insert?");
                scanf("%d", &n);
                Node * ptr = search(n);
                head = insertMid(ptr->prev, ptr);
            }
        }
        else if(ch==4){
            display(head);
        }
        else if(ch==5){
            int data;
            printf("Enter element you want to delete : ");
            scanf("%d", &data);
            delete(data);
        }
        else if(ch==0){
            break;
        }
        else{
            printf("INVALID CHOICE\n");
        }
        printf("Press 1 to Insert in Beginning, 2 to Insert at end, 3 to Insert Middle, 4 to display Linked List, 5 to Exit program : ");
        scanf("%d", &ch);
    }
    printf("\n\n");
    printf("----------END OF PROGRAM----------");
}
