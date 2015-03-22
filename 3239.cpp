#include <iostream>

using namespace std;

#define SIZE 10000001

char mobius[SIZE];
int answer[SIZE], n, t;

void mobius_function()
{
    mobius[0] = answer[0] = 0;
    mobius[1] = answer[1] = 1;
    
    for (int i = 2; i<SIZE; i++)
    {
        mobius[i]--;
        
        if (mobius[i])
        {
            for (int j = 2*i; j<SIZE; j+=i) mobius[j]-=mobius[i];
        }
        
        answer[i] = mobius[i] + answer[i-1];
    }
}

int main()
{
    mobius_function();
    
    cin >> n;
    
    for(int i = 0; i<n; i++)
    {
        cin >> t;
        
        cout << answer[t] << endl;
    }
}
       