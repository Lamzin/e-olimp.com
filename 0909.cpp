#include <iostream>
#include <stdio.h>

char  tmp, pr = ' ';
char str [256];
int answer = 1, length;
bool start = true;

int main()
{
	gets_s(str);
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		if (start)
		{
			if (str[i] == ' ' && str[i - 1] != ' ') answer++;
		}
		if (str[i] != ' ') start = true;
	}
	printf("%d\n", answer);
}