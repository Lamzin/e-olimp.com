#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

string a, b;
long long atmp = 0, btmp = 0;

int main()
{
	in >> a >> b;

	while (atmp < a.length() || btmp < b.length())
	{
		if (atmp < a.length() && btmp < b.length())
		{
			if (a[atmp] < b[btmp]) out << a[atmp++];
			else out << b[btmp++];
		}
		else if (atmp < a.length()) out << a[atmp++];
		else out << b[btmp++];
	}

}