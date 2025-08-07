#include<stdio.h>
int min(int x , int y) {
    return x<y?x:y;
}
void coinchange(int coins[],int capacity,int size) {
    int dp[size+1][capacity+1];
    int i ,j;

    for (int i = 0; i < size+1; ++i) {
        for (int j = 0; j < capacity+1; ++j) {
            if (j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = 9999; // or INT_MAX-1 if you include limits.h

            else if (j < coins[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = min((dp[i-1][j]),(1+dp[i][j-coins[i-1]]));
            }
        }

    }
    printf("%d",dp[size][capacity]);
}

int main() {
    int coins[3] = {1,2,5};
    int capacity = 6;
    int size = 3;

    coinchange(coins,capacity,size);

}