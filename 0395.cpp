#include <iostream>
using namespace std;
long long n, mas[100];

int main()
{
	cin >> n;
	bool first = false;
	for (int i = 0; i<n; i++) cin >> mas[i];
	for (int i = 0; i<n; i++)
	{
		bool simple = true;
		for (int j = 0; j < i; j++) if (mas[i] % mas[j] == 0) simple = false; 
		for (int j = i+1; j<n; j++) if (mas[i] % mas[j] == 0) simple = false;
		if (simple && !first) cout << mas[i];
		if (simple && first) cout << " " << mas[i];
		if (simple)first = true;
	}
	cout << endl;
}