#include<stdio.h>
#define NUM_STATIONS 5
int min(int a, int b) {
    return a < b ? a : b;
}
void AssemblyLine(int a[][NUM_STATIONS],int t[][NUM_STATIONS-1],int e[],int x[]) {
    int i;
    int T1[NUM_STATIONS],T2[NUM_STATIONS];

    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

    for (i = 1; i < NUM_STATIONS; ++i) {
        T1[i] = min((T1[i-1]+a[0][i]),(T2[i-1]+t[1][i-1]+a[0][i]));
        T2[i] = min((T2[i-1]+a[1][i]),(T1[i-1]+t[0][i-1]+a[1][i]));
    }
    int Final_Time = min((T1[NUM_STATIONS-1]+x[0]),(T2[NUM_STATIONS-1]+x[1]));

    printf("Minimum time to process the assembly line: %d\n", Final_Time);
}
int main() {
    int a[2][NUM_STATIONS] ={
        {8,12,10,14,15},
        {10,9,10,20,13}
    };
    int t[2][NUM_STATIONS-1] ={
        {2,1,1,2},
        {1,3,2,1}
    };
    int e[2] = {4,6};
    int x[2] = {4,7};

    AssemblyLine(a,t,e,x);

}