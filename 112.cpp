#include <iostream>

int main()
{
	long t1,t2,t3;
	std :: cin >> t1 >> t2 >> t3;
	std :: cout.precision(2);
	std :: cout << std :: fixed << (float)(1/(1/(float)t1+1/(float)t2+1/(float)t3)) << std :: endl;
}