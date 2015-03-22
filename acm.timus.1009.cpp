#include <iostream>

using namespace std;

long long n,k,res;

long long rec(long long pos, long long prev)
{
	if (pos == 1)
	{
		return (k-1) * rec(2, 0);
	}
	else if (pos == n) 
	{
		if (prev == 1) return k-1;
		else return k;
	}
	else if (pos > n) return 1;
	else
	{
		if (prev == 1)
		{
			return (k-1) * rec(pos+1, 0);
		}
		else
		{
			return (k-1) * rec(pos + 1, 0) + rec(pos + 1, 1);
		}
		
	}
}


int main()
{
	cin >> n >> k;
	cout << rec(1, 0) << endl;
}