#include <fstream>
#include <algorithm>

using namespace std;

#define ll unsigned long long 
#define cin in
#define cout out

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int sieve[1000000], n;
ll almostprimes[100000], size = 0, low, high;

void make_sieve()
{
   for (ll i = 2; i < 1000; i++)
       if (!sieve[i])
       {
           for (ll j = i*i; j < 1000000; j+=i)
               sieve[j] = 1;
       }
   
    ll tmp = 4;
    
    while (tmp < 1000000000000)
    {
        almostprimes[size++] = tmp;
        tmp*=2;
    }
   
    for (ll i = 3; i<1000000; i+=2)
        if (sieve[i] == 0)
        {
            tmp = i*i;

            while (tmp < 1000000000000)
            {
                almostprimes[size++] = tmp;
                tmp*=i;
            }
        }
   
    sort(almostprimes, almostprimes + size);
}

ll almost_primes(ll l, ll h)
{
   ll tmp, result = 0;
   
   result = lower_bound(almostprimes, almostprimes + size, h+1) 
           - lower_bound(almostprimes, almostprimes + size, l);
   
   
   return result;
}

int main()
{
   make_sieve();
   
   cin >> n;
   
   for (int i = 0; i<n; i++)
   {
       cin >> low >> high;
       
       cout << almost_primes(low, high) << endl;
   }
}