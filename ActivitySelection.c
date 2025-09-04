#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

    void sort(int start[],int finish[],int index[],int n) {
        int i, j, temp;
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (finish[j] > finish[j + 1]) {
                    swap(&finish[j],&finish[j+1]);
                    swap(&start[j],&start[j+1]);
                    swap(&index[j],&index[j+1]);
                }
            }
        }
    }

void selection(int start[],int finish[],int size,int index[]) {
    sort(start,finish,index,size);
    printf("%d",index[0]);

    for (int i = 0; i < size; ++i) {
        if (start[i+1]>finish[i]) {
            printf("->%d",index[i+1]);
        }

    }


}
int main() {
    int index[] = {0,1,2,3,4,5,6};
    int start[] =  {2,7,4,1,8,6,5};
    int finish[] = {5,9,8,3,12,10,7};
    int size = sizeof(start)/sizeof(start[0]);

    selection(start,finish,size,index);
}
