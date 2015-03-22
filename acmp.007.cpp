#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <string> vect;
string tmp;

bool func(string a, string b)
{
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else return a < b;
}

int main()
{
	fstream in("input.txt", ios::in), out("output.txt", ios::out);

	for (int i = 0; i < 3; i++)
	{
		in >> tmp;
		vect.push_back(tmp);
	}

	sort(vect.begin(), vect.end(), func);

	out << vect[2];
}