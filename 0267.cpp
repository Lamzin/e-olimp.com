#include <iostream>
#include <string>

using namespace std;

string a, b, c;

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

void minus()
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

int main()
{
	cin >> a >> b;
	if (a == b) cout << "0" << endl;
	else
	{
		minus();
		cout << c << endl;
	}
}