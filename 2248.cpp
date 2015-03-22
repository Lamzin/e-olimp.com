//2248 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define cin in
#define cout out

vector <short int> vect;
short int miN;
int n,k,index;

int main()
{
    cin >> n >> k;
    
    vect.reserve(n);
    
    for (int i = 0; i<n; i++) cin >> vect[i];
    
    index = 0; miN = vect[0];
    
    index = -2;
    
    for (int i = k-1; i<n; i++)
    {
        if (i - index >= k)
        {
            miN = vect[i-k+1];
            for (int j = i-k+1; j<=i; j++) if (vect[j] <= miN) miN = vect[index = j];
        }
        
        if (vect[i] <= miN) miN = vect[index = i];
        
        cout << miN;
        if (i != n-1) cout << " ";
    }
    
    cout << endl;
}