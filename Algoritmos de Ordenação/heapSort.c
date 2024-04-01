#include <stdio.h>
#define MAX 7

void criaHeap(int *v, int i, int f){
    int aux = v[i]; //"partição"
    int j = i * 2 + 1;
    while (j <= f){
        if (j < f){
            if (v[j] < v[j+1]){ //Pai tem 2 filhos, qual o maior?
                j += 1;
            }
        }
        if (aux < v[j]){ //Filho maior q o pai? Filho se torna pai, repete o processo
            v[i] = v[j];
            i = j;
            j = 2*i+1;
        }else{
            j = f+1;
        }
    }
    v[i] = aux; //Antigo pai ocupa lugar do últ filho analisado
}

void heapSort(int *v, int N){ //Usa um vetor como uma árvore binária
    int i, aux;
    for (i = (N-1)/2; i >= 0; i--){ //cria o heap a partir dos dados
        criaHeap(v, i, N-1);
    }

    for (i = N-1; i >= 1; i--){
        aux = v[0]; //Coloca o maior el na posição correspondente(final)
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i-1); //Reconstruir heap
    }
    
}

int main(int argc, char const *argv[])
{
    int v[MAX] = {23,4,67,-8,90,54,21};
    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    heapSort(v,MAX);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}