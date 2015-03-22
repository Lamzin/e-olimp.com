#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

long long a,b,c,n,x0;
long long ans = 0;

stack <long long> st;

int main()
{
    cin >> n >> a >> b >> c >> x0;
    
    for (int i = 0; i < n; i++)
    {
        x0 = (a * x0 * x0 + b * x0 + c) / 100 % 1000000;
        
        if (x0 % 5 < 2)
        {
            if (!st.empty())
            {
                st.pop();
                if (!st.empty()) ans+=st.top();
            }
        }
        else
        {
            if (st.empty()) st.push(x0);
            else st.push(min(x0, st.top()));
            ans+=st.top();
        }
        
    }
    
    cout << ans << endl;
     
}