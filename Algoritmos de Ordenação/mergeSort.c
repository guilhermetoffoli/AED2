#include <stdio.h>
#include <stdlib.h>
//#define MAX 7

void merge(int *v, int ini, int meio, int fim){
    int *temp, p1,p2,tam,i,j,k;
    int fim1 = 0, fim2 = 0;
    tam = fim-ini+1;
    p1 = ini; //Vetor 1 
    p2 = meio+1; //Vetor 2 
    temp = (int *)malloc(tam*sizeof(int)); //Combinação dos 2 vetores
    if (temp != NULL){
        for (i = 0; i < tam; i++){ //percorrer o vetor temp
            if(!fim1 && !fim2){
                if (v[p1] < v[p2])      //
                    temp[i] = v[p1++];  //  Comparo as primeiras posições de p1 e p2 
                else                    //para colocar em temp ordenadamente   
                    temp[i] = v[p2++];  //

                if(p1>meio) fim1 = 1; //  Verifica se um dos vetores já acabou
                if(p2>fim)fim2 = 1;   //para só copiar o restante do outro  
            }
            else{
                if (!fim1)              //
                    temp[i] = v[p1++];  // Copia o que sobrar
                else                    //
                    temp[i] = v[p2++];  //
            }
        }
        for (j = 0,k = ini; j < tam; j++,k++){ //Copiar do auxiliar para o original
            v[k] = temp[j];
        }
    free(temp);    
    }   
}

void mergeSort(int *v, int ini, int fim){ //Dividir para conquistar
    int meio;
    if (ini < fim){
        meio = (ini+fim)/2; //Divide o vetor em 2
        mergeSort(v,ini,meio); //1ª metade
        mergeSort(v,meio+1,fim); //2ª metade
        merge(v,ini,meio,fim);  //Combina as 2 metades de forma ordenada
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
    mergeSort(v,0,MAX-1);

    for (int i = 0; i < MAX-1; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}*/