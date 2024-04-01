#include <stdio.h>
//#define MAX 10000

void bubbleSort(int *v, int N){ //Carrega o maior elemento pro final
    int i, cont, aux, fim = N;
    do{
        cont = 0;
        for (i = 0; i < fim-1; i++){
            if (v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                cont = i;
            }
        }
        fim--;
    } while (cont != 0);
    
}
/*
int main(int argc, char const *argv[])
{
    int v[MAX] = {23,4,67,-8,90,54,21};
    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(v,7);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}*/
