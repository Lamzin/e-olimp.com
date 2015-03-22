#include <stdio.h>

int main()
{
	unsigned char temp, ch[260];
	int len = 0;
	do 
	{
		scanf("%c", &temp);
		if (temp != '\n') (ch[len] = temp, len++);
	}
	while (temp != '\n');
	for (int i = 0; i<len; i++)
		switch (ch[i])
		{
		//case '=': printf("-"); break;
		//case '-': printf("0"); break;
		case '0': printf("9"); break;
		case '9': printf("8"); break;
		case '8': printf("7"); break;
		case '7': printf("6"); break;
		case '6': printf("5"); break;
		case '5': printf("4"); break;
		case '4': printf("3"); break;
		case '3': printf("2"); break;
		case '2': printf("1"); break;
		case '1': printf("`"); break;

		//case '\\': printf("]"); break;
		//case ']': printf("["); break;
		case '[': printf("P"); break;
		case 'P': printf("O"); break;
		case 'O': printf("I"); break;
		case 'I': printf("U"); break;
		case 'U': printf("Y"); break;
		case 'Y': printf("T"); break;
		case 'T': printf("R"); break;
		case 'R': printf("E"); break;
		case 'E': printf("W"); break;
		case 'W': printf("Q"); break;

		case '\'': printf(";"); break;
		case ';': printf("L"); break;
		case 'L': printf("K"); break;
		case 'K': printf("J"); break;
		case 'J': printf("H"); break;
		case 'H': printf("G"); break;
		case 'G': printf("F"); break;
		case 'F': printf("D"); break;
		case 'D': printf("S"); break;
		case 'S': printf("A"); break;

		case '/': printf("."); break;
		case '.': printf(","); break;
		case ',': printf("M"); break;
		case 'M': printf("N"); break;
		case 'N': printf("B"); break;
		case 'B': printf("V"); break;
		case 'V': printf("C"); break;
		case 'C': printf("X"); break;
		case 'X': printf("Z"); break;

		default : printf("%c", ch[i]);
		}
		printf("\n");
}