#include <stdio.h>
//#define MAX 7

void selectionSort(int *v, int N){ //Procura o menor elemento em rel a i
    int i, j, menor, troca;
    for (i = 0; i < N-1; i++){
        menor = i;
        for (j = i+1; j < N; j++){
            if (v[j] < v[menor])
                menor = j;
        }
        if (i != menor){  //Troca os valores da pos atual com o "menor"
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
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
    selectionSort(v,MAX);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}*/