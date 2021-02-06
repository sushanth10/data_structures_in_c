#include<stdio.h>
#include<stdlib.h>

typedef struct myBintree{
    int data;
    struct myBintree * left;
    struct myBintree * right;
}myBintree;

myBintree * root = NULL;

myBintree * createBintree(){
    myBintree * ptr;
    int m;
    printf("Enter -1 for no data : ");
    scanf("%d",&m);

    printf("\n");
    if(m==-1){
        return NULL;
    }
    ptr = (myBintree *)malloc(sizeof(myBintree));
    ptr->data = m;

    printf("Enter left child of %d \n",m);
    ptr->left = createBintree();

    printf("Enter right child of %d \n",m);
    ptr->right = createBintree();
    return ptr;
}

void PreOrder(myBintree * temp){
    if(temp!=NULL){
        printf("%d\t", temp->data);
        PreOrder(temp->left);
        PreOrder(temp->right);
    }
}

void Inorder(myBintree * temp){
    if(temp!=NULL){
        Inorder(temp->left);
        printf("%d\t",temp->data);
        Inorder(temp->right);
    }
}

void Postorder(myBintree * temp){
    if(temp!=NULL){
        Postorder(temp->left);
        Postorder(temp->right);
        printf("%d\t", temp->data);
    }
}

int main(int argc, char const *argv[])
{
    root = createBintree();
    printf("The preorder traversal of the given tree is : ");
    PreOrder(root);
    printf("\n");
    printf("The post order traversal of the given tree is : ");
    Postorder(root);
    printf("\n");
    printf("The in order traversal of the given tree is : ");
    Inorder(root);
    printf("\n");
    return 0;
}
