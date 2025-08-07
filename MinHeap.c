#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(int arr[], int n, int i) {
    int smallest = i;       // Initialize smallest as root
    int left = 2 * i + 1;   // left child index
    int right = 2 * i + 2;  // right child index

    // If left child is smaller
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If root is not smallest
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest); // Recursively heapify the affected subtree
    }
}

// Build Min Heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Min Heap Sort
void heapSort(int arr[], int n) {
    buildMinHeap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call minHeapify on reduced heap
        minHeapify(arr, i, 0);
    }

    // After sorting using Min Heap, reverse the array for ascending order
    for (int i = 0; i < n / 2; i++)
        swap(&arr[i], &arr[n - i - 1]);
}

// Print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {12, 3, 17, 8, 34, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array (ascending):\n");
    printArray(arr, n);

    return 0;
}