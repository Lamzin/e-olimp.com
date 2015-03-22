#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <int> vect;
vector <int> vstr, answer;

int n, tmp;
bool push;

int main()
{

	for (int j = 0; j < 5; j++)
	{
		push = false;
		cin >> tmp;
		for (int h = 0; h < vstr.size(); h++)
		if (vstr[h] == tmp)
		{
			push = true;
			vect[h]++;
		}
		if (!push)
		{
			vect.push_back(1);
			vstr.push_back(tmp);
		}
	}

	sort(vect.begin(), vect.end());
	sort(vstr.begin(), vstr.end());

	if (vect[vect.size() - 1] == 5) cout << "Impossible\n";
	else if (vect[vect.size() - 1] == 4) cout << "Four of a Kind\n";
	else if (vect[vect.size() - 1] == 3 && vect[vect.size() - 2] == 2) cout << "Full House\n";
	else if (vect.size() == 5 && vstr[0] + 1 == vstr[1] && vstr[1] + 1 == vstr[2] && vstr[2] + 1 == vstr[3] && vstr[3] + 1 == vstr[4]) cout << "Straight\n";
	else if (vect[vect.size() - 1] == 3) cout << "Three of a Kind\n";
	else if (vect[vect.size() - 1] == 2 && vect[vect.size() - 2] == 2)cout << "Two Pairs\n";
	else if (vect[vect.size() - 1] == 2)cout << "One Pair\n";
	else cout << "Nothing\n";

}