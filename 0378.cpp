#include <stdio.h>

int main()
{
	//65
	int len = 0;
	unsigned char S[1000], mas[26],temp;
	do
	{
		scanf("%c",&temp);
		if (temp != '\n')
		{
			S[len] = temp;
			len++;
		}
	}
	while (temp != '\n');
	for (int i = 0; i<27; i++) scanf("%c", &mas[i]);
	for (int i = 0; i<len; i++) 
		if (S[i] == ' ') printf(" ");
		else printf("%c",mas[S[i]-65]);
		printf("\n");
}