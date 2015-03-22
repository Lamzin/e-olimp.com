#include <iostream>
using namespace std;
#define SIZE 100

bool mas[SIZE+1][SIZE+1], used[SIZE+1];
int N,M,x,y;

inline void f(int X)
{
	used[X] = true;
	for (int i = 0; i<N+1; i++)
		if (mas[X][i])
			if (!used[i])
			{
				cout << X << " " << i << endl;
				f(i);
			}
}

int main()
{
	memset(used, false, sizeof(used));
	memset(mas, false, sizeof(mas));
	cin >> N >> M;
	for (int i = 0; i<M; i++)
	{
		cin >> x >> y;
		mas[x][y] = mas[y][x] = true;
	}
	f(1);
}