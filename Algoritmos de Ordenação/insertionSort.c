#include <stdio.h>
//#define MAX 7

void insertionSort(int *v, int N){ //Move as "cartas" maiores pra frente
    int i, j, aux;
    for (i = 0; i < N; i++){
        aux = v[i];
        for (j = i; (j > 0) && (aux < v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    } 
}
/*
int main(int argc, char const *argv[])
{
    int v[MAX] = {23,4,67,-8,90,54,21};
    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    insertionSort(v,MAX);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}*/