#include<stdio.h>
#include<stdlib.h>

int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int a;
    printf("Enter the number : ");
    scanf("%d",&a);
    printf("Factorial of %d is %d", a, fact(a));
}