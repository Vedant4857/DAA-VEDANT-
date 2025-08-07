#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapf(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int knapsack(int objects, int capacity, int value[], int weight[]) {
    float ratio[objects];
    float totalvalue = 0.0;


    for (int i = 0; i < objects; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Sort items by ratio (descending)
    for (int i = 0; i < objects - 1; i++) {
        for (int j = 0; j < objects - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swapf(&ratio[j], &ratio[j + 1]);
                swap(&value[j], &value[j + 1]);
                swap(&weight[j], &weight[j + 1]);
            }
        }
    }

    // Greedy selection
    for (int i = 0; i < objects; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalvalue += value[i];
        } else {
            totalvalue += ratio[i] * capacity;
            break;
        }
    }

    printf("\nMaximum value in knapsack = %.2f\n", totalvalue);
    return 0;
}

int main() {
    int objects, capacity;
    printf("Enter the number of objects: ");
    scanf("%d", &objects);

    printf("Enter the Capacity of the bag: ");
    scanf("%d", &capacity);

    int value[objects], weight[objects];

    for (int i = 0; i < objects; i++) {
        printf("Enter the value of %dst object: ", i + 1);
        scanf("%d", &value[i]);
        printf("Enter the weight of %dst object: ", i + 1);
        scanf("%d", &weight[i]);
    }

    knapsack(objects, capacity, value, weight);
    return 0;
}
