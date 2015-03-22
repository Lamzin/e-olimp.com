#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

string str;
int sum = 0, len, ost = 0;
int mas[1000];

int main()
{
	cin >> str;
	//for (int i = 0; i<str.length(); i++)
	//	sum+=str[i]-48;

	mas[0] = 1;
	len = 1;

	for (int i = 0; i<str.length(); i++)
	{
		ost = 0;
		for (int j = 0; j<len; j++)
		{
			ost += mas[j] * (str[i] - 48 + 1);
			mas[j] = ost % 10;
			ost /= 10;
		}

		while (ost)
		{
			mas[len++] = ost % 10;
			ost /= 10;
		}
	}

	for (int i = len - 1; i >= 0; i--)
		cout << mas[i];
	cout << endl;

	return 0;
}