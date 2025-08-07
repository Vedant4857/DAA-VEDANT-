#include<stdio.h>
#include<string.h>
int max(int a,int b) {
    return a>b?a:b;
}
void LongestCommonSequence(char arr[],char arr1[],int x,int y) {
    int arr2[x+1][y+1];

    for (int i = 0; i <=x; ++i) {
        for (int j = 0; j <=y; ++j) {
            if (i==0 || j==0) {
                arr2[i][j] = 0;
            }else if (arr[i-1] == arr1[j-1]) {
                arr2[i][j] = arr2[i-1][j-1]+1;
            }
            else if(arr[i-1] != arr1[j-1]) {
                arr2[i][j] = max((arr2[i-1][j]),(arr2[i][j-1]));
            }
        }
    }
    printf("%d",arr2[x][y]);
}
int main() {
    char arr[] = "ACDFGIK";
    char arr1[] = "BDGIMN";
    int x = strlen(arr);
    int y = strlen(arr1);

    LongestCommonSequence(arr,arr1,x,y);
}