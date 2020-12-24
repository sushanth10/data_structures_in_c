#include<stdio.h>

int GCD(int m, int n){
    if(n!=0){
        return GCD(n, m%n);
    }
    return m;
}

int main(int argc, char const *argv[])
{
    int a,b, gcd;
    printf("Enter the two numbers : ");
    scanf("%d%d",&a,&b);
    gcd = GCD(a,b);
    printf("The GCD of the given two numbers is %d",gcd);
    return 0;
}

