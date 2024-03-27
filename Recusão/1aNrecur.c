#include <stdio.h>

int UmaN(int n){
    if(n == 0) return n;
    
    else return n += UmaN(n-1);
}

int 
main(){
    int n;
    printf("Coloque um numero: ");
    scanf("%d", &n);
    printf("A soma de 1 a %d é %d\n", n, UmaN(n));

    return 0;
}
