#include <stdio.h>

void merge(int array[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0, konstant = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[konstant] = L[i];
            i++;
        } else {
            array[konstant] = R[j];
            j++;
        }
        konstant++;
    }

    while (i < n1) {
        array[konstant] = L[i];
        i++;
        konstant++;
    }

    while (j < n2) {
        array[konstant] = R[j];
        j++;
        konstant++;
    } 
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);       // Sort the left subarray
        mergeSort(array, middle + 1, right);  // Sort the right subarray
        merge(array, left, middle, right);    // Merge the two sorted subarrays
    }
}

int main(void) {
    
    int array[] = {12, 15, 0, 1001, -20, 81, 94, 100, 5};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    mergeSort(array, 0, arraySize - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}