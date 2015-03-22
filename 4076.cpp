#include <fstream>
#include <math.h>
#include <memory.h>

#define SIZE 100000

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long

ll t, a, b, beg;
char prime[SIZE];

bool prime_f(ll x)
{
    if (x == 1) return false;
    
    for (ll k = 2; k*k<=x; k++)
        if (x % k == 0) return false;
    
    return true;
}

int main()
{
   in >> t;
   
   for (ll i = 0; i < t; i++)
   {
       memset(prime, 1, SIZE);

       in >> a >> b;
       
       if (i) out << endl;
       
        for (ll d = 2; d*d <= b; d++)
        {
            beg = (a % d == 0) ? a : (a/d + 1) * d;

            if (beg == d) beg += d;

            for (ll j = beg; j<=b; j+=d)
            {
                prime[j-a] = 0;
            }
        }

        if (a == 1) prime[0] = 0;

        for(ll j = a; j<b; j++)
        {
            if (prime[j-a] != 0) out << j << endl;
        }
        
       if (prime_f(b)) out << b << endl;
   }
}