#include <iostream>
#include <vector>

using namespace std;

#define SIZE_16 65536
#define SIZE_8 256

int n, tmp;
long long result;
char sieve[SIZE_16 + SIZE_8];
vector <int> prime;
vector <pair < int, pair< int, int > > > d;
 
int eiler(int x)
{
    int res = x;
    
    for (int i = 0; prime[i] <= x; i++)
    {
        if (x % prime[i] == 0) 
        {
            res -= res / prime[i];
            while (x % prime[i] == 0) x/=prime[i];
        }
        if (i == prime.size()-1 && x > prime[i])
        {
            res -= res / x;
            break;
        }
    }
    
    return res;
}

void erat()
{
    for (int i = 2; i <= SIZE_8; i++)
        if (!sieve[i])
        {
            for(int j = i*i; j <= SIZE_16; j+=i) sieve[j] = 1;
        }

    for (int i = 2; i <= SIZE_16; i++)
        if (!sieve[i]) prime.push_back(i);
}

bool d_next()
{
    int next = 1;
    
    for (int i = d.size()-1; i>=0; i--)
    {
        next += d[i].second.first;
        if (next > d[i].second.second)
        {
            d[i].second.first = 0;
            next = 1;
        }
        else
        {
            d[i].second.first = next;
            next = 0;
        }
    }
    
    return !(bool)next;
}

int main()
{
    erat();
    
    while (cin)
    {
        cin >> n;

        if (cin)
        {
            result = 0;
            d.clear();
            tmp = n;
            
            for (int i = 0; tmp - 1; i++)
            {
                if (tmp % prime[i] == 0)
                {
                    d.push_back(make_pair(prime[i], make_pair(0, 0)));
                    
                    while (tmp % prime[i] == 0)
                    {
                        d[d.size()-1].second.second++;
                        tmp /= prime[i];
                    }
                }
                
                if (i == prime.size()-1 && prime[i] < tmp) 
                {
                    d.push_back(make_pair(tmp, make_pair(0, 1)));
                    break;
                }
            }
            
            do
            {
                int w = 1;
                for (int i = 0; i<d.size(); i++)
                    for (int j = 0; j<d[i].second.first; j++) w *= d[i].first;
                
                result += eiler(n / w) * w; 
            }
            while (d_next());

            
            cout << result << endl;
        }
    }
}