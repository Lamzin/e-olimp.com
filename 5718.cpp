//5718 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long
#define cin in
#define cout out

ll n, pos = 0, cnt = 0, ans = 0;

int main()
{
    cin >> n;
    
    for(int i = 0; i<32; i++)
        if (n & (1 << i))
        {
            pos = i;
            cnt++;
        }
    
    for (int i = 0; i<cnt; i++) ans += 1 << pos-i;
    
    //cout << "a = " << ans << endl;
    //cout << "b = " << (1 << cnt) - 1 << endl;
    //cout << "ans = " << ans - (1 << cnt) + 1;
    
    cout << ans - (1 << cnt) + 1 << endl;

}