#include <iostream>
using namespace std;

int n, answer = 0;
char S[100];

int main()
{
	cin >> n;
	gets(S);
	for (int i = 0; i<n; i++)
	{
		gets(S);
		if (S[0] == S[3]) answer++;
	}
	cout << answer << endl;
}