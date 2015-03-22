#include <iostream>
#include <math.h>
#include <vector>

#define SIZE 5000001 

using namespace std;

unsigned int divider[SIZE];
unsigned long long sum[SIZE];
int a,b;

void preprocessing()
{
    for (int i = 1; i<SIZE/2; i++)
    {
        for (int j = i; j<SIZE; j+=i)
            divider[j] += i;
        
        sum[i] = sum[i-1] + divider[i];
    }
}

int main()
{
    preprocessing();
    
    while (cin)
    {
        cin >> a >> b;

        if (cin)
        {
            cout << sum[b] - sum[a-1] << endl;
        }
    }
}