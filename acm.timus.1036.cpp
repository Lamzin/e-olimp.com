#include <iostream>
#include <string>
#define SIZE1 200
#define SIZE2 2000

using namespace std;

int n, sum;
string dn[SIZE1][SIZE2];

string sum_string(string a, string b)
{
	if (a.length() < b.length()) swap(a,b);

	string c = "";
	int tmp = 0;
	
	for (int i = 0; i < a.length(); i++)
	{
		if (i < b.length()) 
			tmp += b[i] - 48;
		tmp+=a[i] - 48;
		c+=tmp%10 + 48;
		tmp/=10;
	}
	while(tmp)
	{
		c+=tmp%10 + 48;
		tmp /= 10;
	}

	return c;
}

string rec(long long lparam, long long wparam)
{
	if (lparam > 2*n) return "0";
	else if (wparam > sum) return "0";
	else if (wparam == sum && lparam == 2*n) return "1";
	else if (lparam == n && wparam != sum / 2) return "0";
	else if (dn[lparam][wparam] != "-1") return dn[lparam][wparam];
	else
	{
		string result = "0";

		for (int ind = 0; ind < 10; ind++)
			result = sum_string(result, rec(lparam + 1, wparam + ind));
		
		return dn[lparam][wparam] = result;
	}
}

int main()
{
	cin >> n >> sum;

	if (sum % 2 == 1)
		cout << "0";
	else
	{
		for (int i = 0; i < SIZE1; i++)
		for (int j = 0; j < SIZE2; j++) dn[i][j] = "-1";

		string tmp = rec(0,0);
		for (int i = tmp.length()-1; i>=0; i--) cout << tmp[i];
	}
}