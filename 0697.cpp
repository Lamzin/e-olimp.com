#include <iostream>

using namespace std;
int main()
{
	int n; 
	double mas[10];
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> mas[i];
	cout.precision(10);
	for (int i=0; i<n; i++)
		cout << fixed << (double)mas[i]/6 << endl;
}