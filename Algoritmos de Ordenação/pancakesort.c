#include <stdio.h>
#include <stdlib.h>

void virada(int *v, int N, int num){
    int troca;
    for (int i = 0; i < --num; i++){
        troca = v[i];
        v[i] = v[num];
        v[num] = troca;
    }
}

void pancakeSort(int *v, int tam){
    int i, a, max_num_pos;
    for (i = tam; i > 0; i--){
        max_num_pos = 0;
        for (a = 0; a < i; a++){
            if (v[a] > v[max_num_pos])
                max_num_pos = a;
        }
        if (max_num_pos == i-1)
            continue;
        if (max_num_pos)
        {
            virada(v,tam,max_num_pos+1);
        } 
        virada(v,tam,i);      
    }
}
