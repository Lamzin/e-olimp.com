#include <iostream>
#include <algorithm>

using namespace std;

long long dn[100][100], arr[100][100];
long long n, _count, tmp_a, tmp_b, tmp;
pair <short int, short int> up[100];
bool mas_checker_point[100];

long long rec(short int index, short int free_count)
{
	if (free_count <= 0) return 0;
	else if (dn[index][free_count] != -1) return dn[index][free_count];
	else
	{
		long long tmp_result = 0;

		//if (up[index].first != -1 && up[index].second != -1) tmp_result = rec(up[index].first, free_count-2) + rec(up[index].second, free_count-2) + arr[index][up[index].first] + arr[index][up[index].second];
		
		if (up[index].first != -1) 
			tmp_result = max(
						tmp_result, 
						rec(up[index].first, free_count-1) + arr[index][up[index].first]);
		if (up[index].second != -1) 
			tmp_result = max(
						tmp_result, 
						rec(up[index].second, free_count-1) + arr[index][up[index].second]);

		if (up[index].first != -1 && up[index].second != -1)
		{
			for (int i = 0; i <= free_count-2; i++)
			{
				tmp_result = max(rec(up[index].first, free_count-2-i) + rec(up[index].second, i) + arr[index][up[index].first] + arr[index][up[index].second], tmp_result);
			}
		}

		return dn[index][free_count] = tmp_result;
	}
}

void make_up_arr(short int index)
{
	mas_checker_point[index] = true;
	bool tmpbool = false;
	
	for (int i = 0; i< n; i++)
		if (arr[index][i]!=-1 && !mas_checker_point[i]) 
		{
			if (tmpbool == false) up[index].first = i;
			else up[index].second = i;

			tmpbool = true;
			mas_checker_point[i] = true;

			make_up_arr(i);
		}
}


int main()
{
	cin >> n >> _count;

	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) arr[i][j] = dn[i][j] = -1;

	for (int i = 0; i<n; i++) up[i].first = up[i].second = -1;

	for (int i = 0; i < n-1; i++)
	{
		cin >> tmp_a >> tmp_b >> tmp;
		arr[tmp_a-1][tmp_b-1] = arr[tmp_b-1][tmp_a-1] = tmp;
	}

	make_up_arr(0);

	cout << rec(0, _count);
}