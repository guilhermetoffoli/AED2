#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.c"

#define MAX 7
#define tam 5

struct balde{
    int qtd;
    int valores[tam];
};

void bucketSort(int *v, int N){
    int i, j, maior, menor, nroBaldes, pos;
    struct balde *bd;

    maior = menor = v[0];
    for (i = 1; i < N; i++){            //Acha o maior e menor valor
        if (v[i] > maior) maior = v[i];
        if (v[i] < menor) menor = v[i];
    }

    nroBaldes = (maior - menor) / tam+1; //Inicializa os baldes
    bd = (struct balde *) malloc(nroBaldes*sizeof(struct balde));
    for (i = 0; i < nroBaldes; i++)
        bd[i].qtd = 0;

    for (i = 0; i < N; i++){            //Distribui os vlrs nos baldes
        pos = (v[i] - menor) / tam;
        bd[pos].valores[bd[pos].qtd] = v[i];
        bd[pos].qtd++;
    }
    
    pos = 0;
    for (i = 0; i < nroBaldes; i++){
        insertionSort(bd[i].valores,bd[i].qtd);
        for (j = 0; j < bd[i].qtd; j++){
            v[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
}

int main(int argc, char const *argv[])
{
    int v[MAX] = {23,4,67,5,90,54,21};
    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    bucketSort(v, MAX);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
