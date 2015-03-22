#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int> >  vect;

int fin, sta, index = 0;
int used[10000], cur, tmp, s;

int main()
{
    cin >> fin >> sta;
    vect.push_back(make_pair(fin, 0));
    used[fin] = 1;
    index = 0;
    
    while(vect[index].first != sta)
    {
        cur = vect[index].first;
            
        tmp = cur * 3;
        if (tmp>=0 && tmp<=9999 && !used[tmp]){
            vect.push_back(make_pair(tmp, vect[index].second+1));
            used[tmp] = 1;
        }
        tmp = cur - 2;
        if (tmp>=0 && tmp<=9999 && !used[tmp]){
            vect.push_back(make_pair(tmp, vect[index].second+1));
            used[tmp] = 1;
        }
        s = 0;
        tmp = cur;
        while(tmp)
        {
            s += tmp % 10;
            tmp/=10;
        }
        
        tmp = cur + s;
        if (tmp>=0 && tmp<=9999 && !used[tmp]){
            vect.push_back(make_pair(tmp, vect[index].second+1));
            used[tmp] = 1;
        }
        index++;
    }
    
    cout << vect[index].second << endl;
    
    return 0;
}