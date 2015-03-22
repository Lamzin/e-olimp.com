#include <stdio.h>

short kchar[26], n;
bool answer[1000];
char temp;

void get_kchar(int summand, char ch)
{
	do
		{
			scanf("%c", &temp);
			if (temp != ch)
				if (temp >='A' && temp <='Z') kchar[temp - 65]+=summand;
				else if (temp >='a' && temp <='z') kchar[temp - 97]+=summand;
		}
		while (temp != ch);
}
int main()
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++) kchar[j] = 0; 
		get_kchar(1, ' ');
		get_kchar(-1, '\n');
		answer[i] = true;
		for (int j = 0; j < 26; j++) 
			if (kchar[j]) answer[i] = false;
	}
	for (int i = 0; i < n; i++)
		if (answer[i]) printf("Yes\n");
		else printf("No\n");
}