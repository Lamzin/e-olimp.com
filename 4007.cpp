#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int> >  vect;

int fin, sta, index = 0;
int used[10000], cur, tmp;

int main()
{
    cin >> fin >> sta;
    vect.push_back(make_pair(sta, -1));
    used[sta] = 1;
    
    while(vect[index].first != fin)
    {
        cur = vect[index].first;
        
        tmp = ((cur / 1000)-1) * 1000 + cur % 1000;
        if (cur / 1000 != 0 && !used[tmp]){
            vect.push_back(make_pair(tmp, index));
            used[tmp] = 1;
        }
        
        if (cur % 10 != 9 && !used[cur+1]){
            vect.push_back(make_pair(cur+1, index));
            used[cur+1] = 1;
        }
        
        tmp = (cur % 1000) * 10 + cur / 1000;
        if (!used[tmp]){
            vect.push_back(make_pair(tmp, index));
            used[tmp] = 1;
        }
            
        tmp = cur / 10 + (cur % 10)*1000;
        if (!used[tmp]){
            vect.push_back(make_pair(tmp, index));
            used[tmp] = 1;
        }
        
        index++;
    }
    
    while(index != -1){
        cout << vect[index].first << endl;
        index = vect[index].second;
    }
    
    return 0;
}