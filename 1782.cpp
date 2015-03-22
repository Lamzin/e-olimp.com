#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

unsigned long long n, sum = 0, tmp, d_tmp;
vector <int> d_count_max, d_count, d_n;

void check_n_d(unsigned long long d)
{
    if (n % d == 0)
    {
        d_n.push_back(d);
        d_count_max.push_back(0);
        d_count.push_back(0);
        
        while (n % d == 0)
        {
            d_count_max[d_count_max.size()-1]++;
            n/=d;
        }
    }
}

int d_count_add()
{
    int next = 1;
    
    for (int i = d_count_max.size()-1; i>=0; i--)
    {
        d_count[i] += next;
        
        if (d_count[i] > d_count_max[i])
        {
            d_count[i] = 0;
        }
        else next = 0;
    }
    
    return next;
}

int main()
{
    cin >> n;
    
    check_n_d(2);
    
    tmp = 1;
    while (n-1)
    {
        check_n_d(tmp+=2);
    }
    
    do 
    {
        d_tmp = 1;
        for (int i = 0; i<d_count.size(); i++)
            for (int j = 0; j < d_count[i]; j++)
                d_tmp*=d_n[i];
                
       sum += d_tmp;         
    }
    while (!d_count_add());
    
    cout << sum << endl;
}