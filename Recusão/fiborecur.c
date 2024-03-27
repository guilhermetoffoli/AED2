#include <stdio.h>

int fibo(int n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    else{
        int fibon = 1;
        return fibo(n-1)+fibo(n-2);
    }  
}

int 
main(){
    int n;
    scanf("%d", &n);
    
    printf("Numero da sequencia é %d\n", fibo(n));
    return 0;
}
