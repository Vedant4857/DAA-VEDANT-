#include<stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void KS(int wt[], int val[],int n,int cap) {
    int dp[n+1][cap+1];

    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=cap; ++j) {
            if (i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if (j >= wt[i-1]) {
                dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j - wt[i-1]]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("Maximum value: %d\n", dp[n][cap]);
}
int main() {
    int wt[] = {5,2,4,3};
    int val[] = {20,30,15,10};
     int capacity = 7;

    int n = sizeof(wt)/sizeof(wt[0]);
    KS(wt,val,n,capacity);
}