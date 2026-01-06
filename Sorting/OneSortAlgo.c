#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Utility Functions ---------- */

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

/* ---------- Bubble Sort ---------- */

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

/* ---------- Selection Sort ---------- */

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(&arr[minIdx], &arr[i]);
    }
}

/* ---------- Insertion Sort ---------- */

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* ---------- Shell Sort ---------- */

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

/* ---------- Quick Sort (Lomuto Partition) ---------- */

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSortRec(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortRec(arr, low, pi - 1);
        quickSortRec(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortRec(arr, 0, n - 1);
}

/* ---------- Radix Sort (Handles only positive integers) ---------- */

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

/* ---------- Menu ---------- */

void menu() {
    printf("\n===== SORTING MENU =====\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Radix Sort (Positive numbers only)\n");
    printf("6. Quick Sort\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

/* ---------- MAIN ---------- */

int main() {

    int original[] = {10, 7, 8, 9, 1, 5, 23, 4, 11};
    int n = sizeof(original) / sizeof(original[0]);

    int arr[50]; // temp array for sorting
    int choice;

    printf("Original Array:\n");
    printArray(original, n);

    do {
        menu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting...\n");
            break;
        }

        // Copy original array before each sort
        copyArray(arr, original, n);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Bubble Sorted: ");
                break;
            case 2:
                selectionSort(arr, n);
                printf("Selection Sorted: ");
                break;
            case 3:
                insertionSort(arr, n);
                printf("Insertion Sorted: ");
                break;
            case 4:
                shellSort(arr, n);
                printf("Shell Sorted: ");
                break;
            case 5:
                radixSort(arr, n);
                printf("Radix Sorted: ");
                break;
            case 6:
                quickSort(arr, n);
                printf("Quick Sorted: ");
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printArray(arr, n);

    } while (choice != 0);

    return 0;
}
