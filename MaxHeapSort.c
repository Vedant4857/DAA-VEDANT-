#include<stdio.h>

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[],int size,int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left<size && arr[left]>arr[largest])
        largest = left;
    if (right<size && arr[right]>arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i],&arr[largest]);
        heapify(arr,size,largest);
    }
    }
void HeapSort(int arr[],int size) {
    //For Max-Heap
    for (int i = size/2+1; i>=0; i--) {
        heapify(arr,size,i);
    }

    //Now heap sorting
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);    // Move max to end
        heapify(arr, i, 0);        // Restore heap
    }
    }
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter the elements in the array:");
    for (int i = 0; i < size; i++) {
        scanf("%d",&arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, size);

    HeapSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}