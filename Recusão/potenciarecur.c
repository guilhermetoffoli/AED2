#include <stdio.h>

int pot(int k, int n){
    if(n == 0) return 1;
    if(n == 1) return k;
    else return k*pot(k, n-1);
}

int 
main(){
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d elevado a %d é: %d\n", k, n, pot(k, n));

    return 0;
}
