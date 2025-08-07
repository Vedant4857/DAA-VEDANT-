#include<stdio.h>
void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ShellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {  // keep reducing gap
        for (int i = gap; i < size; i++) {
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

    ShellSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}

