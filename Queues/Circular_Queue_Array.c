#include<stdio.h>

#define MAXSIZE 4

int cq[MAXSIZE];
int f=0, r=-1;
int count = 0;

int cqfull(int count){
    return (count==MAXSIZE) ? 1 : 0;
}

int cqempty(int count){
    return (count==0) ? 1 : 0;
} 

void insert_rear(int cq[], int * r, int * count){
    if(cqfull(*count)){
        printf("Queue overflow condition.\n");
        return;
    }
    int m;
    printf("Enter element to be added to the queue : ");
    scanf("%d", &m);
    *r = (*r+1)%MAXSIZE;
    cq[*r]=m;
    *count = *count +1;
}

void delete(int cq[], int *f, int *count){
    if(cqempty(*count)){
        printf("Queue is empty\n");
        return;
    }
    printf("The deleted element is %d\n", cq[*f]);
    *f = (*f+1)%MAXSIZE;
    *count = *count - 1;
}

void display(int cq[], int *f, int *count){
    int i, c=(*count);
    if(cqempty(*count)){
        printf("Queue is empty.\n");
        return;
    }
    for(i=(*f) ; c>0 ; i=(i+1)%MAXSIZE){
        printf("%d\t",cq[i]);
        c--;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int ch;
    printf("Press 0 to exit the program, 1 to Insert to Rear, 2 to Delete, 3 to Display the elements\n");
    scanf("%d", &ch);
    while(ch>0){
        if(ch==1){
            insert_rear(cq, &r, &count);
        }
        else if(ch==2){
            delete(cq, &f, &count);
        }
        else if(ch==3){
            display(cq, &f, &count);
        }
        else{
            printf("Invalid Choice.\n");
        }
        printf("Enter choice : ");
        scanf("%d", &ch);
    }
    return 0;
}
