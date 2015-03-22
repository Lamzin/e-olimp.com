#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

vector <int> vect;
int n;

int main()
{
	cin >> n;
	while (n)
	{
		vect.push_back(n % 13);
		n /= 13;
	}

	for (int i = vect.size() - 1; i >= 0; i--)
	if (vect[i] < 10) cout << vect[i];
	else
		switch (vect[i])
		{
		case 10: cout << "A"; break;
		case 11: cout << "B"; break;
		case 12: cout << "C"; break;
		}
	cout << endl;
}