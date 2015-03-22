#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

string str;

int main()
{
	in >> str;
	out << str;
	while (in)
	{
		in >> str;
		if (in)
		{
			out << " " << str;
		}
	}
	out << endl;
}