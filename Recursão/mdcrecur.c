#include <stdio.h>

int mdc(int a, int b){
    if (b == 0) return a;
    else return mdc(b,a%b);
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("mdc de %d e %d é %d\n", a, b, mdc(a, b));

    return 0;
}