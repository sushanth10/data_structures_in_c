#include<stdio.h>

int bsearch(int arr[], int beg, int last, int a){
    if(last>=beg){
        int mid = (beg + (last-1)) /2;
        if(arr[mid]==a)
            return mid;
        else if(arr[mid]<a)
            return bsearch(arr, mid+1, last , a);
        else
            return bsearch(arr, beg, mid-1, a);
    }
        return -1;        
}

int main(int argc, char const *argv[])
{
    int n, key;
    printf("Enter the size of the array.\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the sorted array : ");
    for( int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }    
    printf("Enter the key to searched \n");
    scanf("%d",&key);
    int res = bsearch(arr, 0 , n-1, key);
    if(res==-1){
        printf("The entered element was not found in the array.\n");
    }
    else{
        printf("Element %d found at position %d", key, res+1);
    }
    return 0;
}
