#include<stdio.h>

int bin_search(int arr[], int beg, int last, int a){
    if(last>=beg){
        int mid = (last+beg-1)/2;
        if(arr[mid]==a)
            return mid;
        else if(arr[mid]<a)
            return bin_search(arr, mid+1, last, a);
        else
            return bin_search(arr, beg, mid-1, a);
    }
    return -1;
}

void main(){
    int n, key;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted array : ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to be searched : ");
    scanf("%d", &key);
    int res = bin_search(arr, 0, n-1, key);
    if(res==-1){
        printf("The key element waws not found in the array.\n");
    }
    else{
        printf("%d was found at position index %d", key, res);
    }
}