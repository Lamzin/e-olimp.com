#include <iostream>

using namespace std;
int main()
{
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	if (x % 2)
		cout << (x-1)*m+y-1 << endl;
	else cout << (x-1)*m+(m-y+1)-1 << endl;
}