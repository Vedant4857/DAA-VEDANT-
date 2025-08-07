#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = high;
    int i = low- 1;
    for (int j = low; j < high; j++) {
        if (arr[j]<arr[pivot]) {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[high],&arr[i+1]);
    return i + 1;
}
void quicksort(int arr[], int low, int high) {
    if (low<high) {
        int pivot_index = partition(arr,low,high);
        quicksort(arr,low,pivot_index-1);
        quicksort(arr,pivot_index+1,high);
    }
}
int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements:");
    for (int i = 0; i < size; i++) {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,size-1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

}