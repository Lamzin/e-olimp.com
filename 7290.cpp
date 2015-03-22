#include <vector>
#include <algorithm>
#include <stdio.h>

#include <math.h>

using namespace std;

int main()
{
	char c;
	int counter = 0;

	for (;;)
	{
		c = getchar();
		switch (c)
		{
		case 'a':
		case 'b':
		case 'd':
		case 'e':
		case 'g':
		case 'o':
		case 'p':
		case 'q':
			counter++;
			break;

		case 10:
			printf("%d\n", counter);
			return 0;
		}
	}

	return 0;
}