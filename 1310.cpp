#include <stdio.h>
#define SIZE 1000000

char mas[SIZE];
long long len = 0, max_len = 0, temp_len = 0, j, i; 
int main()
{
	scanf("%s", &mas);
	while (mas[len] !='\0') len++;
	j = 1; i = 0;
	while (j < len)
	{
		if (mas[i] == mas[j])
		{
			temp_len++;
			i++;
		}
		else 
		{
			i = 0;
			if (temp_len > max_len) max_len = temp_len;
			temp_len = 0;
		}
		j++;
	}
	printf("%d\n", max_len);
}