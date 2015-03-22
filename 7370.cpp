#include <stdio.h>

unsigned long long n;

int main()
{
    scanf("%d", &n);
    printf("%d\n", n/3*2 + (n%3==2)%2);
}