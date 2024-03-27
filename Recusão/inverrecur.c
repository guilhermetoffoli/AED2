#include <stdio.h>

int revert(int num){
    if (num/10 < 1) return num;
    else return revert(num/10);
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    printf("O número %d invertido é %d\n", num, revert(num));
    return 0;
}
