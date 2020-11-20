#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int num;
    char str_data[30];
    struct Node * next;
}Node;

Node * head;

Node * createNewNode(Node * next){
    Node * new = (Node *)malloc(sizeof(Node));
    printf("Enter number : ");
    scanf("%d",&new->num);
    printf("Enter String Data : ");
    scanf("%s", new->str_data);
    new->next = next;
    return new;
}

Node * insertBegin(Node * next){
    Node * new = createNewNode(next);
    if(head==NULL){
        head = new;
        printf("Very first Node created.\n");
        return new;
    }
    else{
        new->next = head;
        head = new;
    }
    return head;
}

Node * insertEnd(Node * next){
    Node * sptr = head;
    while(sptr->next!=NULL){
        sptr=sptr->next;
    }
    Node * new = createNewNode(sptr->next);
    sptr->next = new;
    return head;    
}

Node * insertMiddle(Node * next){
    int i=0;
    printf("Enter the position index of the new node: ");
    scanf("%d",&i);
    Node * sptr = head;
    while(i>2){
        sptr = sptr->next;
        i--;
    }
    Node * new = createNewNode(sptr->next);
    sptr->next = new;
    return head;
}

void display(){
    Node * sptr = head;
    if(head==NULL){
        printf("No Nodes present.\n");
    }
    else{
        while(sptr!=NULL){
        printf("Number : %d \t String Data : %s\n", sptr->num, sptr->str_data);
        sptr = sptr->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int c;
    printf("Enter 0 to Exit the program, 1 to Insert in beginning, 2 to Insert in End, 3 to Insert in middle, 5 to Display Nodes\n");
    scanf("%d", &c);
    while(c!=1 && c!=5){
        printf("No nodes present yet.\n");
        printf("Enter 0 to Exit the program, 1 to Insert in beginning, 2 to Insert in End, 3 to Insert in middle, 5 to Display Nodes\n");
        scanf("%d", &c);
        continue;
    }
    head = insertBegin(NULL);

    while(c>0){
        printf("Enter 0 to Exit the program, 1 to Insert in beginning, 2 to Insert in End, 3 to Insert in middle, 5 to Display Nodes\n");
        scanf("%d", &c);
        if(c==1){
            head = insertBegin(NULL);
        }
        else if(c==2){
            head = insertEnd(head);
        }
        else if(c==3){
            head = insertMiddle(head);
        }
        else if(c==5){
            display();
        }
        else if(c==0){
            break;
        }
        else{
            printf("Invalid Choice.\n");
        }
        
    }
    return 0;
}

