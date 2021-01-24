//Binary Tree 
#include<stdio.h>
#include<stdlib.h>

typedef struct BSTree{
    int data;
    struct BSTree * right;
    struct BSTree * left;
}BSTree;

BSTree * root = NULL;

BSTree * createTree(BSTree * root, int value){
    if(root==NULL){
        root = (BSTree *)malloc(sizeof(BSTree));
        root->left=root->right=NULL;
        root->data = value;
        return root;
    }
    else if(value<root->data){
        root->left = createTree(root->left, value);
    }
    else if(value>root->data){
        root->right = createTree(root->right, value);
    }
    else 
        printf("Duplcate error\n");
    return root;
}

void Preorder(BSTree * root){
    if(root!=NULL){
        printf("%d\t", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(BSTree * root){
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\t", root->data);
    }
}

void Inorder(BSTree * root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d\t", root->data);
        Inorder(root->right);
    }
}

int main(){
    printf("Choices\n1. Create Tree\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder Traversal\n5. Exit");
    int ch,i, value, n;
    printf("Enter choice : ");
    scanf("%d", &ch);
    while(1){

        switch(ch){
            case 1 : root=NULL;
            printf("Enter number of nodes : ");
            scanf("%d", &n);
            for(i=1; i<=n; i++){
                printf("Enter node data : ");
                scanf("%d", &value);
                root = createTree(root, value);
            }
            printf("BSTree with %d is created.", n);
            break;
            case 2 : Inorder(root);
            break;
            case 3 : Preorder(root);
            break;
            case 4 : Postorder(root);
            break;
            case 5 : printf("Terminating Program.\n");
            exit(0);
            break;
            default: printf("Invalid choice.\n");
            break;
        }
        printf("\nEnter choice : ");
        scanf("%d", &ch);
    }
}