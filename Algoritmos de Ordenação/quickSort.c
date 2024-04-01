#include <stdio.h>
//#define MAX 7

int particiona(int *v, int ini, int fim){
    int esq = ini, dir = fim, pivo = v[ini], aux; //pivo é o início
    while (esq < dir){
        while (v[esq] <= pivo) //Avança e para quando achar um valor maior que o pivo
            esq++;
        while(v[dir] > pivo) //Avança e para quando achar um valor menor que o pivo
            dir--;
        if (esq < dir){ //Troca dir e esq 
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[ini] = v[dir]; //Inicio recebe último valor da direita
    v[dir] = pivo; //Posição de onde parou a direita vira o pivo
    return dir; //retorna um ponto onde todos antes são menores e todos depois são maiores    
}

void quickSort(int *v, int ini, int fim){ //Dividir para conquistar
    int pivo;
    if (ini < fim){
        pivo = particiona(v, ini, fim); //Separa os dados em duas partições
        quickSort(v,ini,pivo-1); //Chama a função para a esquerda
        quickSort(v,pivo+1,fim); //Chama a função para a direita
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
    quickSort(v,0,MAX-1);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}*/