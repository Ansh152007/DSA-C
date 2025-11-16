// Write a C program to implement Sequential search.
// This program works for first occurance of element only

#include <stdio.h>

void LinearSearch(int arr[], int size, int key){
    int flag = 0;
    for(int i=0; i < size; i++)
    {
        if(arr[i]==key)
        {
        printf("Element found on index : %d", i);
        return;
        }
    }
    printf("Element not found!");
}

int main() {
    int arr[] = {2,4,5,7,9,3};
    printf("Array elements are: ");
    for(int i=0; i<6; i++){
        printf("%d ", arr[i]);
    }
    printf("\nEnter element to be searched: ");
    int key;
    scanf("%d", &key);
    LinearSearch(arr, 6, key);
    return 0;
}