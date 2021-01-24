#include<stdio.h>
#include<stdlib.h>

int GCD(int m, int n){
    if(n!=0){
        return GCD(n, m%n);
    }
    return m;
}

void main(){
    int m, n;
    printf("GCD Calculator\n");
    printf("Enter the numbers : ");
    scanf("%d%d", &m, &n);
    int gcd = GCD(m,n);
    printf("GCD of %d and %d is %d\n",m,n, gcd); 
}