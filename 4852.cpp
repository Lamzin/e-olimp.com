#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int> >  vect;
int used[1000], n, x, index;
int mas[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    
    cin >> n >> x;
    x--;
    
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            cin >> mas[i][j];
    
    vect.push_back(make_pair(x, 1));
    used[x] = 1;
    index = 0;
    
    while(index < vect.size())
    {
        for (int i = 0; i<n; i++)
            if (mas[vect[index].first][i] && !used[i])
            {
                used[i] = vect[index].second + 1;
                vect.push_back(make_pair(i, used[i]));
            }
        index++;
    }
    
    cout << used[0]-1;
    for (int i = 1; i<n; i++)
        cout << " " << used[i]-1;
    cout << endl;
    
    return 0;
}