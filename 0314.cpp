#include <iostream>
#include <string>

using namespace std;

string a,b,c,str;
char tmp;
int n;
bool bsum = false;

void revolution(string &str)
{
	int length = str.length();
	char tmp;
	for (int i = 0; i < length / 2; i++)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
	}
}

void sum()
{
	revolution(a);
	revolution(b);
	int lengthA = a.length(), lengthB = b.length(), length = (lengthA > lengthB) ? lengthA : lengthB, ost = 0;
	for (int i = 0; i < length; i++)
	{
		if (i < lengthA) ost += a[i] - 48;
		if (i < lengthB) ost += b[i] - 48;

		c += ((ost % 10) +48);
		ost /= 10;
	}
	if (ost) c += "1";

	revolution(c);
}

void minus()
{
	if (a == b)
	{
		c = "0";
	}
	else
	{
		bool swap = false;
		if ((a.length() < b.length()) || (a.length() == b.length() && a < b))
		{
			c = a;
			a = b;
			b = c;
			c.clear();
			swap = true;
		}
		revolution(a);
		revolution(b);
		c = a;
		int length = b.length();

		for (int i = 0 ; i < length; i++)
		{
			if (c[i] >= b[i])
			{
				c[i] = c[i] - b[i] + 48;
			}
			else
			{
				c[i] = c[i] + 10 - b[i] + 48;
				{
					int j = i+1;
					while (c[j] == '0' && j < c.length())
					{
						c[j] = '9';
						j++;
					}
					c[j]--;
				}
			}
		}
		while (c[c.length() - 1] == '0') c.erase(c.length() - 1, c.length() - 1);

		if (swap) c+="-";
		revolution(c);
	}
}

int main()
{
	cin >> n;
	for (int i = 0 ; i < n; i++)
	{
		a.clear();
		b.clear();
		c.clear();
		bsum = true;

		cin >> c;

		int j = 0, lengthC = c.length();
		while (true) 
		{
				if(c[j] == '-') 
				{
						bsum = false;
						break;
				}
				else if (c[j] == '+') break;
				a += c[j++];
		}
		j++;
		while (j < lengthC) b += c[j++];

		c.clear();
		
		if (bsum) sum();
			else minus();

		cout << c << endl;
	}
}
