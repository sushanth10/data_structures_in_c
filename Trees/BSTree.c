#include <stdio.h>
#include<stdlib.h> 
typedef struct BSTree
{
    int marks;
    struct BSTree *right;
    struct BSTree *left;
}BSTree;

//Prototype / Forward declarion of the functions
BSTree *createBSTree(BSTree *, int);
void Inorder(BSTree *);
void Preorder(BSTree *);
void Postorder(BSTree *);

int main()
{
    BSTree *root = NULL;
    int choice, value, n, i;
    printf("\n\nBinary Search Tree Operations\n");
    printf("\n1. Creation of BST");
    printf("\n2. Traverse in Inorder");
    printf("\n3. Traverse in Preorder");
    printf("\n4. Traverse in Postorder");
    printf("\n5. Exit\n");
    printf("\nEnter Choice : ");
    scanf("%d",&choice);
     while(1){        
        switch(choice)
        {
            case 1:
                root = NULL;
                printf("\nEnter number of nodes : ");
                scanf("%d",&n);
                for(i = 1; i <= n; i++)
                {
                    printf("\nEnter data for node %d : ", i);
                    scanf("%d",&value);
                    root = createBSTree(root,value);
                }
                printf("BST with %d nodes created\n", n);
                break;
            case 2:
                printf("\nBST Traversal in INORDER \n");
                Inorder(root);
                break;
            case 3:
                printf("\nBST Traversal in PREORDER \n");
                Preorder(root);
                break;
            case 4:
                printf("\nBST Traversal in POSTORDER \n");
                Postorder(root);
                break;
            case 5:
                printf("\nTerminating");
                exit(0);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
    }
    return 0;
}

BSTree *createBSTree(BSTree *root, int value)
{
    if(root == NULL)
    {
        root = ( BSTree *)malloc(sizeof(BSTree));
        root->left = root->right = NULL;
        root->marks = value;
        return root;
    }
    else
    {
        //BST hence the new node created must be correctly put to the right or left
        if(value < root->marks )
            root->left = createBSTree(root->left,value);
        else if(value > root->marks )
            root->right = createBSTree(root->right,value);
        else
            //Ensures that duplicate values are not allowed to be entered in the BST
            printf("Duplicate element error.");
        
        return(root);
    }
}


void Inorder( BSTree *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->marks);
        Inorder(root->right);
    }
}

void Preorder(BSTree *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->marks);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(BSTree *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->marks);
    }
}
