#include <stdio.h>

#define max 3

int somavetor(int v[], int tam){
    if(tam == 0) return 0;
    else return v[tam-1] + somavetor(v, tam-1);
}

int 
main(){
    int v[max];
    for (int i = 0; i < max; i++){
        scanf("%d", &v[i]);
    }
    printf("A soma do vetor é %d\n", somavetor(v, max));

    return 0;
}
