#include <iostream>
#include <math.h>

int main()
 {
    long long n;
    std :: cin >> n;
    for (int d = (sqrtf(8*n+1)-1) / 2; ; d--)
        if (2*n % d == 0)
			{
				std :: cout << d << std :: endl; 
				return 0;
			}
 }