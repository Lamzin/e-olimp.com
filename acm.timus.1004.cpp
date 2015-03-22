#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector <pair<int, pair<int, int>>> vect;
int n, m, k, tmp_a, tmp_b, tmp_c;
vector <int> mas;
deque <int> qq;

void write()
{


}

void push_all(int param)
{
	qq.push_back(param);
	mas[param] = 1;
}

bool check_beg(int param)
{
	if (param == qq.begin && mas[param] == -1)  
	{
		push_all(param);
		return true;
	}

	return false;
}

void func()
{
	for (int i = 0; i < n; i++) mas.push_back(-1);

	int index = 0;
	push_all(vect[0].second.first);
	push_all(vect[0].second.second);

	while (qq.size() != n)	
	{
		index++;
		if (index >= m) break;

		if (vect[index].second.first == qq.begin && mas[vect[index].second.first] == -1)  

		else if (vect[index].second.first == qq.end && mas[vect[index].second.first] == -1)

		else if (vect[index].second.second == qq.begin && mas[vect[index].second.second] == -1) 
		else if (vect[index].second.second == qq.end && mas[vect[index].second.second] == -1)
		
		
	}
}

int main()
{
	do
	{
		cin >> n;
		if (n != -1)
		{
			vect.clear();
			mas.clear();

			cin >> m;

			for (int i = 0; i < m; i++)
			{
				cin >> tmp_a >> tmp_b >> tmp_c;
				vect.push_back(make_pair(tmp_c, make_pair(tmp_a, tmp_b)));
			}

			sort(vect.begin(), vect.end());

			func();

			write();
		}
	}
	while(n != -1);
}