#include <stdio.h>
#define MAX 7

void shellSort(int *v, int N){
    int i, j, h, aux;
    while (h < N/3) // Calcula o h inicial
        h = 3*h+1; //H máximo
    
    while (h > 0){
        for (i = h; i < N; i++){
            aux = v[i]; //Guarda o n da pos inicial
            j = i;
            while (j >= h && aux < v[j-h]){ //Efetua as comparações entre elementos com dist h
                v[j] = v[j-h];
                j -= h;
            }
            v[j] = aux;
        }
        h = (h-1)/3; //Volta ao valor anterior do h
    }
}

int main(int argc, char const *argv[])
{
    int v[MAX] = {23,4,67,-8,90,54,21};
    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    shellSort(v,MAX);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}