#include <stdio.h>

int main()
 {
    unsigned char temp;
    int res = 0;
    scanf("%c",&temp);
	while (temp != '\n')
    {
        scanf("%c", &temp);
        if (temp != '\n' && (temp == '+' || temp == '-' || temp == '*')) res++;  
    }
    printf("%d\n", res);
 }