#include <stdio.h>

int main()
{
	int mas[11][3][3] =
	// " " - 0; "|" - 1; "_" - 2
	{
		{
			{0,0,0},
			{0,2,0},
			{0,0,0},
		},//-
		{
			{0,2,0},
			{1,0,1},
			{1,2,1},

		},//0
		{
			{0,0,0},
			{0,0,1},
			{0,0,1},
		},//1
		{
			{0,2,0},
			{0,2,1},
			{1,2,0},
		},//2
		{
			{0,2,0},
			{0,2,1},
			{0,2,1},
		},//3
		{
			{0,0,0},
			{1,2,1},
			{0,0,1},
		},//4
		{
			{0,2,0},
			{1,2,0},
			{0,2,1},
		},//5
		{
			{0,2,0},
			{1,2,0},
			{1,2,1},
		},//6
		{
			{0,2,0},
			{0,0,1},
			{0,0,1},
		},//7
		{
			{0,2,0},
			{1,2,1},
			{1,2,1},
		},//8
		{
			{0,2,0},
			{1,2,1},
			{0,2,1},
		},//9
	};
	char temp,ch[20];
	int len = 0,a;
	do
	{
		scanf("%c",&temp);
		if (temp != '\n')
		{
			ch[len] = temp;
			len++;
		}
	}
	while (temp != '\n');
	for (int b = 0; b < 3; b++)
	{
		for (int i = 0; i < len; i++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (ch[i] == '-') a = 0;
				else a = ch[i] - 47;
				switch (mas[a][b][c])
				{
				case 0:printf(" ");break;
				case 1:printf("|");break;
				case 2:printf("_");break;
				}
			}
		}
		printf("\n");
	}
}