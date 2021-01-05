#include<stdio.h>
#include<stdlib.h>

int fibonacci(int a){
    int n = a;
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2); 
}

int main(){
    int m, i=0;
    printf("Enter the number of terms : ");
    scanf("%d",&m);
    while(i<m){
        printf("%d\t", fibonacci(i));
        i++;
    }
}