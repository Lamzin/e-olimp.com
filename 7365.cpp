#include <iostream>

using namespace std;

int n,cnt;
double tmp;

int main(){
	cin >> n;

	for (int i = 0; i<n; i++){
		cin >> tmp;
		cnt+=(tmp < 30.0f) ? 1 : 0;
	}

	cout << (2*cnt+8) / 9 << " " << cnt << endl;
}