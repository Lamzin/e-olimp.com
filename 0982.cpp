#include <iostream>
using namespace std;
#define SIZE 100

bool mas[SIZE][SIZE], used[SIZE];
int N,M,x,y, Sum = 0;

void f(int X)
{
	used[X] = true;
	Sum++;
	for (int i = 0; i<N; i++)
	if (mas[X][i])
		if (!used[i])
			f(i);
}
int main()
{
	cin >> N >> M;
	memset(used, false, sizeof(used));
	memset(mas, false, sizeof(mas));
	for (int i = 0; i<M; i++)
	{
		cin >> x >> y;
		mas[x-1][y-1] = mas[y-1][x-1] = true;
	}
	f(0);
	if (Sum == N) cout << "YES\n";
	else cout << "NO\n";
}