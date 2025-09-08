#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int smallelemindex(int arr[],int size,int index) {
    int min = index;
    for (int i = index+1; i < size; ++i) {
        if (arr[i]<arr[min]) {
            min = i;
        }
    }
    return min;
}

void selectsort(int size,int arr[]) {
    for (int i = 0; i < size-1; ++i) {
        int smalleleindex = smallelemindex(arr,size,i);
        swap(&arr[smalleleindex],&arr[i]);
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
    selectsort(size,arr);
    printf("Sorted array:");
    for (int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }
}