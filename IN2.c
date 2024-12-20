#include <stdio.h>

int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0; 

    int uniqueIndex = 0; 

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    return uniqueIndex + 1; 
}

int main() {
    int size;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];

   
    printf("Enter %d elements of the sorted array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }


    int newSize = removeDuplicates(arr, size);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
