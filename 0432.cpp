#include <iostream>
#include <vector>

using namespace std;

#define DEBUG
//#undef DEBUG

#ifdef DEBUG
#include <fstream>
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif

struct xyz{
    int x,y,z;
    xyz(int _x, int _y, int _z): x(_x), y(_y), z(_z){}
    xyz() : x(0), y(0), z(0){}
} ss, ff, cur;

bool operator ==(xyz &a, xyz &b){
    return a.x == b.x && a.y == b.y && a.z == b.z;
}


int n=1,m=1,k=1,ans=0, xx, yy, zz;
char g[30][30][30], ch;
int used[30][30][30];
vector < pair<xyz, int> > vect;

void check(int x, int y, int z, int len){
    if (x >= 0 && x < n &&
        y >= 0 && y < m &&
        z >= 0 && z < k &&
        !used[x][y][z] && g[x][y][z] != '#'){ 
        vect.push_back(make_pair(xyz(x,y,z), len+1));
        used[x][y][z] = true;
    }
}

int main(){
    while(n && m && k){
        cin >> n >> m >> k;
        if (n && m && k){
            ans = 0;
            for (int i = 0; i<30; i++)
            for (int j = 0; j<30; j++)
            for (int h = 0; h<30; h++) used[i][j][h] = false;
            
            for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
            for (int h = 0; h<k; h++){
                cin >> ch;
                g[i][j][h] = ch;
                if (ch == 'S') ss = xyz(i,j,h);
                if (ch == 'E') ff = xyz(i,j,h);
            }
            
            vect.clear();
            vect.push_back(make_pair(ss, 0));
            used[ss.x][ss.y][ss.z] = true;
            
            for (int i = 0; i<vect.size(); i++){
                if (vect[i].first == ff){
                    ans = vect[i].second;
                    break;
                }
                xx = vect[i].first.x;
                yy = vect[i].first.y;
                zz = vect[i].first.z;
                check(xx-1,yy,zz,vect[i].second);
                check(xx+1,yy,zz,vect[i].second);
                check(xx,yy-1,zz,vect[i].second);
                check(xx,yy+1,zz,vect[i].second);
                check(xx,yy,zz-1,vect[i].second);
                check(xx,yy,zz+1,vect[i].second);
            }

            if (ans) cout << "Escaped in " << ans << " minute(s).\n";
            else cout << "Trapped!\n";
        }
    }
}