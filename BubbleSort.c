#include<stdio.h>

void bubblesort(int size,int arr[]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int size;
    printf("Enter the size of array:");
    scanf("%d",&size);
    int arr[size];

    printf("Enter the elements in the array:");
    for (int i = 0;i<size;i++) {
        scanf("%d",&arr[i]);
    }
    bubblesort(size,arr);
    printf("Sorted array:");
    for (int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }
}