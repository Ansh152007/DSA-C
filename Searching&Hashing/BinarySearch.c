// Write a C program to implement Binary search.
// This program works for first occurance of element only

#include <stdio.h>

void BinarySearch(int arr[], int size, int key)
{
    int start,mid,end;
    start = 0;
    end = size - 1;

    while (start<=end)
    {
        mid = (start + end)/2;

        if (arr[mid]==key)
        {
            printf("Element found at index :%d" ,mid);
            return;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    printf("Element not found!");
}

int main() {
    int arr[] = {2,4,5,7,9};
    printf("Array elements are: ");
    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\nEnter element to be searched: ");
    int key;
    scanf("%d", &key);
    BinarySearch(arr, 5, key);
    return 0;
}