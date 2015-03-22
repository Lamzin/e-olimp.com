#include <iostream>
using namespace std;
typedef long long LL;
#define SIZE 31
LL N;
LL F_tmp[SIZE], A_tmp[SIZE];
LL A(LL tmp);
LL F(LL tmp);

int main()
{
	cin >> N;
	for (LL i = 0; i<SIZE; i++) 
	{
		F_tmp[i] = 0;
		A_tmp[i] = 0;
	}
	F_tmp[2] = 4;
	A_tmp[2] = 2;
	if (N == 1) cout << "2\n";
	else cout << F(N) << endl;
}

LL A(LL tmp)
{
	if (A_tmp[tmp] != 0) 
	{
		return A_tmp[tmp];
	}
	else 
	{
		A_tmp[tmp] = F(tmp-1) - A(tmp-1);
		return A_tmp[tmp];
	}
}

LL F(LL tmp)
{
	if (F_tmp[tmp] != 0) 
	{
		return F_tmp[tmp];
	}
	else 
	{
		F_tmp[tmp] = F(tmp-1)*2 - A(tmp-1);
		return F_tmp[tmp];
	}
}
