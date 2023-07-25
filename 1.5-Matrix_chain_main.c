#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include "random.h"

int mcm_recursion(int arr[], int i, int j) {
    if(i == j) return 0;
    int answer = INT_MAX;
    
    for(int k = i; k <= j-1; k++) {
        int cost1 = mcm_recursion(arr, i, k);
        int cost2 = mcm_recursion(arr, k+1, j);
        int cost3 = arr[i-1] * arr[k] * arr[j];

        int final = cost1 + cost2 + cost3;
        answer = answer > final ? final : answer;
    }
    return answer;
} 

int main() {
    int *arr;
    int n = 5, i;
    arr = newHeader();

    clock_t begin = clock();
    mcm_recursion(arr, 1, n-1);
    clock_t end = clock();

    double time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Time: %lf", time);
    return 0;
}