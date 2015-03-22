#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100000

using namespace std;

int /*dn[SIZE], */n, tmp_a, tmp_b, answer = 0;
vector <pair<int, int>> vect;

/*int index_next(int index)
{
	int time_next = vect[index].second;

	for (int h = index+1; h < n; h++)
	{
		if (time_next < vect[h].first)
		{
			return h;
		}
	}

	return n;
}*/

/*int rec(int index)
{
	if (index >= n) return 0;

	if (dn[index] != -1) return dn[index];
	else
	{
		int result = 0;

		for (int i = index; i < n; i++)
		{
			result = max(result, rec(index_next(i)) + 1);
		}

		return dn[index] = result;
	}
}*/

void Greedy()
{
	int prev = vect[0].first, ind = 0;
	answer++;
	while (vect[++ind].first == vect[0].first);

	for (int i = ind; i < n-1; i++)
	{
		if (vect[i].first != vect[i + 1].first && vect[i].second > prev)
		{
			answer++;
			prev = vect[i].first;
		}
	}
	if (vect[n - 1].second > prev) answer++;

}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp_a >> tmp_b;
		vect.push_back(make_pair(tmp_b, tmp_a));
		//dn[i] = -1;
	}

	sort(vect.begin(), vect.end());

	//cout << rec(0);

	Greedy();

	cout << answer;
}