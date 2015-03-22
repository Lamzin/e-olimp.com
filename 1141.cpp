#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <int> vect;
pair <int, int> ct;
int n, tmp, middle = -1;
bool push, med = true;

ifstream in("input.txt", ios::in);
ofstream out("output.txt", ios::out);

int main()
{
	
	do
	{
		in >> tmp;
		if (in)
		{
			vect.push_back(tmp);
		}		
	} while (in);

	for (int i = 0; i < vect.size(); i++)
	{
		ct.first = 0;
		ct.second = 0;
		for (int j = 0; j < vect.size(); j++)
		{
			if (vect[j] < vect[i]) ct.first++;
			else if (vect[j] > vect[i]) ct.second++;
		}
		if (ct.first == ct.second)
		{
			middle = vect[i];
			break;
		}
	}
	out << middle << endl;	
}