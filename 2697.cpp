#include <iostream>
#include <vector>

using namespace std;

#define DEBUG
#undef DEBUG

#ifdef DEBUG
#include <fstream>
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif

int x,y,a,b,ans = -1;
int used[1001000];
vector < pair<int, int> > vect;

void check(int ind, int len){
    if (ind > 0 && ind < 1001000 && !used[ind]){
        vect.push_back(make_pair(ind, len));
        used[ind] = true;
    }
}

int main(){
    cin >> x >> y >> a >> b;
    check(x,0);
         
    for (int i = 0; i<vect.size(); i++){
        if (vect[i].first == y){
            ans = vect[i].second;
            break;
        }
        check(vect[i].first+a, vect[i].second+1);
        check(vect[i].first-b, vect[i].second+1);
    }
    cout << ans << endl;
}