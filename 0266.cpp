#include <iostream>
#include <string>

using namespace std;

string a,b;

int main()
{
	cin >> a >> b;

	if (a.length() > b.length()) cout << ">" << endl;
	else if (a.length() < b.length()) cout << "<" << endl;
	else if(a.length() == b.length())
	{
		if (a > b) cout << ">" << endl;
		else if (a < b) cout << "<" << endl;
		else cout << "=" << endl;
	}
}