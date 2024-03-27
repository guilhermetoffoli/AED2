#include <stdio.h>

int fat(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else return n*fat(n-1);
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("Fat de %d é %d\n", n, fat(n));

    return 0;
}

