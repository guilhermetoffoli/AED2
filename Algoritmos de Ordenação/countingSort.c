#include <stdio.h>
#include <stdlib.h>

#define MAX 7
#define K 100

void countingSort(int *v, int N){
    int i, j, k;
    int baldes[K];

    for (i = 0; i < K; i++)
        baldes[i] = 0;
    
    for (i = 0; i < N; i++)
        baldes[v[i]]++;
    
    for (i = 0, j = 0; j < K; j++)
        for (k = baldes[j]; k > 0; k--)
            v[i++] = j;
}

int main(int argc, char const *argv[])
{
    int v[MAX] = {23,4,67,5,90,54,21};
    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    countingSort(v, MAX);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}