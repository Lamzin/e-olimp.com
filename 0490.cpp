#include <stdio.h>

int main()
{
	bool mas[101] = {0};
	char temp;
	int len = 1;
	do
	{
		scanf("%c",&temp);
		if (temp-13)
			if (temp == '1') mas[++len] = true;
			else mas[++len] = false;
	}
	while (temp != '\n');
	for (int i = 2; i<len; i++)
		if ((mas[i] && !mas[i-1]) || (!mas[i] && mas[i-1])) printf("1");
		else printf("0");
	printf("\n");
}