#include<stdio.h>
#include<stdlib.h>

typedef struct myBintree{
    int data;
    struct myBintree * left;
    struct yBintree * right;
}myBintree;

myBintree * root = NULL;

myBintree * createBintree(){
    int m;
    myBintree * ptr;

    printf("Enter data (-1 for no data) : ");
    scanf("%d", &m);
    if(m==-1) return NULL;

    ptr = (myBintree *)malloc(sizeof(myBintree));
    ptr->data = m;

    printf("Creating left node of %d ", m);
    ptr->left = createBintree();
    
    printf("Creating right node of %d ",m);
    ptr->right = createBintree();

    return ptr;
}

void Preorder(myBintree * temp){
    printf("Displaying Preorder traversal : ");
    if(temp!=NULL){
        printf("%d\t", temp->data);
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

void Inorder(myBintree * temp){
    printf("Displaying Inorder traversal : ");
    if(temp!=NULL){
        Inorder(temp->left);
        printf("%d\t",temp->data);
        Inorder(temp->right);
    }
}

void Postorder(myBintree * root){
    printf("Displaying Postorder traversal : ");
    if(temp!=NULL){
        Postorder(temp->left);
        Postorder(temp->right);
        printf("%d\t", temp->data);
    }
}

int main(){
    printf("1.")
}