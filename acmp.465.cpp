#include <iostream>
#include <fstream>

using namespace std;

long long n,k,res;
long long dn[1800][1800];

long long rec(long long pos, long long prev)
{
	/*if (pos == 1)
	{
		return (k-1) * rec(2, 0);
	}
	else*/ if (pos == n) 
	{
		if (prev == 1) return k-1;
		else return k;
	}
	else if (pos > n) return 1;
	else
	{
		/*if (dn[pos][prev] != -1)
			return dn[pos][prev];*/
		if (prev == 1)
		{
			return dn[pos][prev] = (k-1) * rec(pos+1, 0);
		}
		else
		{
			return dn[pos][prev] = (k-1) * rec(pos + 1, 0) + rec(pos + 1, 1);
		}
		
	}
}

void memorySet()
{
	for (int i = 0; i<1800; i++)
	for (int j = 0; j<1800; j++) dn[i][j] = -1;
}

int main()
{
	ifstream in("input.txt", ios::in);

	ofstream out("output.txt", ios::out);

	memorySet();

	in >> n;

	k = 2;

	out << rec(1, 0) << endl;
}