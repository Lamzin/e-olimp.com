#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool mas[10][10], damage[10][10];
int n, tmp, x, y;
vector <int> vect;
bool repeat = false;
char chtmp;

bool find_live_part(int a, int b)
{
	bool answer = false;
	static pair <int, int> vert, hor;
	vert.first = vert.second = b;
	hor.first = hor.second = a;

	damage[a][b] = true;
	while (hor.first > 0 && mas[hor.first - 1][b] == true)
	{
		hor.first--;
		if (damage[hor.first][b] == false)  answer = true;
	}

	while (hor.second < 10 && mas[hor.second + 1][b] == true)
	{
		hor.second++;
		if (damage[hor.second][b] == false)  answer = true;
	}

	while (vert.first > 0 && mas[a][vert.first-1] == true)
	{
		vert.first--;
		if (damage[a][vert.first] == false)  answer = true;
	}

	while (vert.second < 10 && mas[a][vert.second+1] == true)
	{
		vert.second++;
		if (damage[a][vert.second] == false)  answer = true;
	}

	return answer;
}

int main()
{
	cin >> n;
	for (int i = 0; i < 10; i++)
	for (int j = 0; j < 10; j++)
	{
		cin >> chtmp;
		if (chtmp == '#') mas[i][j] = true;
		else mas[i][j] = false;

		damage[i][j] = false;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		repeat = false;
		for (int j = 0; j < i; j++)
		if (vect[i] == vect[j])
		{
			repeat = true;
			break;
		}
		if (repeat)
		{
			cout << "repeated" << endl;
		}
		else
		{
			if (vect[i] % 10 == 0)
			{
				x = vect[i] / 10 - 1;
				y = 9;
			}
			else
			{
				x = vect[i] / 10;
				y = vect[i] % 10 - 1;
			}

			if (mas[x][y] == false)
			{
				cout << "missed" << endl;
			}
			else
			{
				if (find_live_part(x, y) == true)
					cout << "damaged" << endl;
				else cout << "sinked" << endl;
			}
		}
	}

}