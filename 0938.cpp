#include <iostream>

int main()
{
	float xn,xm,yn,ym,a;
	std :: cin >> xn >> yn >> xm >> ym >> a;
	std :: cout.precision(2);
	std :: cout << std :: fixed << (float)((xn+a*xm)/(1+a)) << " " << (float)((yn+a*ym)/(1+a)) << std :: endl;
}