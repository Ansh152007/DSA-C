#include <stdio.h>

void linearSearch(int arr[], int n, int search)
{
    for ( int i = 0 ; i < n ; i++ )
    {
        if(search == arr[i])
        {
            printf("Element found at index :: %d ", i);
            return ;
        }
    }
    printf("Element not found!");
}

void binarySeach(int arr[], int n, int search)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high)/2 ;
        if (arr[mid] == search)
        {
            printf("Element found at index :: %d" , mid);
            return;
        }
        else if ( search < arr[mid])
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    printf("Element not found!");
}

int recursionBinarySearch(int arr[], int low, int high, int search)
{
    int mid = (high + low)/2;

    if(arr[mid]== search)
    {
        printf("Element found at index :: %d", mid);
        return 0;
    }
    else if(arr[mid] < search)
    {
        recursionBinarySearch(arr, mid + 1, high, search);
    }
    else if(arr[mid] > search)
    {
        recursionBinarySearch(arr, low, mid - 1, search);
    }
    else
    {
        printf("Element not found!");
        return -1;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    linearSearch(arr, n, 40);
    printf("\n");
    binarySeach(arr, n, 40);
    printf("\n");
    recursionBinarySearch(arr, 0, n - 1, 40);
    printf("\n");
    return 0;
}