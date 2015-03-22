#include <iostream>
#include <string>

using namespace std;

string a,b,c;
char tmp;
int n;

void swap(string &strtmp)
{
	int length = strtmp.length();

	for (int i = 0; i < length / 2; i++)
	{
		tmp = strtmp[i];
		strtmp[i] = strtmp[length - i - 1];
		strtmp[length - i - 1] = tmp;
	}
}

void sum()
{
	swap(a);
	swap(b);
	int lengthA = a.length(), lengthB = b.length(), length = (lengthA > lengthB) ? lengthA : lengthB, ost = 0;
	for (int i = 0; i < length; i++)
	{
		if (i < lengthA) ost += a[i] - 48;
		if (i < lengthB) ost += b[i] - 48;

		c += ((ost % 10) +48);
		ost /= 10;
	}
	if (ost) c += "1";

	swap(c);
}

int main()
{
	cin >> n;
	for (int i = 0 ; i < n; i++)
	{
		a.clear();
		b.clear();
		c.clear();

		cin >> c;

		int j = 0, lengthC = c.length();
		while (c[j] != '+') a += c[j++];
		j++;
		while (j < lengthC) b += c[j++];

		c.clear();
		
		sum();

		cout << c << endl;
	}
	
}
