#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
long long timeStart = time(NULL);
#endif

vector < pair < int, pair<int, int >> > vect;
pair <int, int> bishop, pawn;
pair <string, string> str;
vector <pair<int, int>> pawn_xyk;
int index, X, Y;
bool blackWin = false, draw = false, whiteWin = false;
bool blackWin2 = false, draw2 = false, whiteWin2 = false;

void tryadd(int xtmp, int ytmp, int value)
{
	bool add = true;
	if (value < pawn_xyk.size())
	{
		if (xtmp >= 0 && xtmp < 8 && ytmp >= 0 && ytmp < 8)
		{
			if (abs(xtmp - pawn_xyk[value].first) == 1 && ytmp - pawn_xyk[value].second == 1)
			{
				add = false;
				//whiteWin = true;
			}
			if (xtmp == pawn_xyk[value].first && ytmp == pawn_xyk[value].second)
			{
				blackWin = true;
				add = false;
			}
			if (value + 1 < pawn_xyk.size())
			if (xtmp == pawn_xyk[value + 1].first && ytmp == pawn_xyk[value + 1].second)
			{
				draw = true;
				add = false;
			}
			if (add)
			{
				vect.push_back(make_pair(value, make_pair(xtmp, ytmp)));
			}
		}
	}
}

int main()
{
	cin >> str.first >> str.second;

	pawn.first = str.first[0] - 97;
	pawn.second = str.first[1] - 49;
	bishop.first = str.second[0] - 97;
	bishop.second = str.second[1] - 49;

	whiteWin = (abs(bishop.first - pawn.first) == 1 && bishop.second - pawn.second == 1) || (pawn.second == 7);
	draw = (bishop.second - pawn.second == 1 && bishop.first == pawn.first);
	if (pawn.second == 1 && pawn.first == bishop.first && bishop.second - pawn.second == 1) draw = true;
	if (pawn.second == 1 && pawn.first == bishop.first && bishop.second - pawn.second == 2) draw = true;

	if (!draw)
	{
		if (!whiteWin)
		{
			pawn_xyk.push_back(pawn);
			if (pawn.second == 1) pawn_xyk[0].second++;
			while (pawn_xyk[pawn_xyk.size() - 1].second != 7)
				pawn_xyk.push_back(make_pair(pawn_xyk[pawn_xyk.size() - 1].first, pawn_xyk[pawn_xyk.size() - 1].second + 1));
			if (pawn.second == 1) pawn_xyk[0].second--;

			vect.push_back(make_pair(0, make_pair(bishop.first, bishop.second)));
			index = 0;
			while (vect[index].first + 1 < pawn_xyk.size())
			{
				X = vect[index].second.first;
				Y = vect[index].second.second;

				tryadd(X + 1, Y + 2, vect[index].first + 1);
				tryadd(X + 2, Y + 1, vect[index].first + 1);
				tryadd(X - 1, Y + 2, vect[index].first + 1);
				tryadd(X - 2, Y + 1, vect[index].first + 1);
				tryadd(X + 1, Y - 2, vect[index].first + 1);
				tryadd(X + 2, Y - 1, vect[index].first + 1);
				tryadd(X - 1, Y - 2, vect[index].first + 1);
				tryadd(X - 2, Y - 1, vect[index].first + 1);

				index++;
				if (index == vect.size()) break;
			}
		}
	}

	if (pawn.second == 1)
	{
		vect.clear(); pawn_xyk.clear();
		draw2 = draw; blackWin2 = blackWin; whiteWin2 = whiteWin;
		whiteWin = blackWin = draw = false;
		if (pawn.second == 1 && pawn.first == bishop.first && bishop.second - pawn.second == 1) draw = true;

		if (!draw)
		{
			pawn_xyk.push_back(pawn);
			while (pawn_xyk[pawn_xyk.size() - 1].second != 7)
				pawn_xyk.push_back(make_pair(pawn_xyk[pawn_xyk.size() - 1].first, pawn_xyk[pawn_xyk.size() - 1].second + 1));

			vect.push_back(make_pair(0, make_pair(bishop.first, bishop.second)));
			index = 0;
			while (vect[index].first + 1 < pawn_xyk.size())
			{
				X = vect[index].second.first;
				Y = vect[index].second.second;

				tryadd(X + 1, Y + 2, vect[index].first + 1);
				tryadd(X + 2, Y + 1, vect[index].first + 1);
				tryadd(X - 1, Y + 2, vect[index].first + 1);
				tryadd(X - 2, Y + 1, vect[index].first + 1);
				tryadd(X + 1, Y - 2, vect[index].first + 1);
				tryadd(X + 2, Y - 1, vect[index].first + 1);
				tryadd(X - 1, Y - 2, vect[index].first + 1);
				tryadd(X - 2, Y - 1, vect[index].first + 1);

				index++;
				if (index == vect.size()) break;
			}
		}

		if (blackWin && blackWin2)
		{

		}
		else if ((draw && !blackWin) || (draw2 && !blackWin2))
		{
			blackWin = false;
			draw = true;
		}
		else if (blackWin2 || blackWin)
		{
			blackWin = true;
		}
	}

	if (blackWin) cout << -1 << endl;
	else if (draw) cout << 0.5 << endl;
	else cout << 1 << endl;
	
	//if (pawn.second == 1 && pawn.first == 3 && bishop.first == 4 && bishop.second == 4) cout << "0.5\n";
	//if (pawn.second == 1) cout << -1 << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}