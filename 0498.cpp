#include <iostream>
#include <vector>

using namespace std;

struct node{ 
    int x,y;
    node(int xx, int yy) : x(xx), y(yy){}
    node() : x(0), y(0){}
} start, finish;

bool operator ==(node &a, node &b){
    return a.x == b.x && a.y == b.y;
}

int n, ans, used[9][9], xxx, yyy;
char xx, yy;
vector <pair<node, int > > vect;

void check(int x, int y, int len){
    if (x>=0 && x < 9 && y >= 0 && y < 9 && !used[x][y]){
        vect.push_back(make_pair(node(x,y), len));
        used[x][y] = true;
    }
}

int main(){
    cin >> n;
    
    for (int i=0 ; i<n; i++){
        cin >> xx >> yy;
        start = node(xx-'A', yy-'1');

        cin >> xx >> yy;
        finish = node(xx-'A', yy-'1');
        
        for (int ii = 0; ii < 9; ii++)
            for (int jj = 0; jj < 9; jj++) used[ii][jj] = false;
        vect.clear();
        check(start.x, start.y, 0);
        
        bool found = false;
        for (int ii = 0; ii < vect.size(); ii++){
            if (vect[ii].first == finish){
                cout << vect[ii].second << endl;
                found = true;
                break;
            }
            xxx = vect[ii].first.x;
            yyy = vect[ii].first.y;
            if ((xxx + yyy) % 2){
                check(xxx-1, yyy-2, vect[ii].second+1);
                check(xxx-1, yyy+2, vect[ii].second+1);
                check(xxx+1, yyy-2, vect[ii].second+1);
                check(xxx+1, yyy+2, vect[ii].second+1);
                check(xxx-2, yyy-1, vect[ii].second+1);
                check(xxx-2, yyy+1, vect[ii].second+1);
                check(xxx+2, yyy-1, vect[ii].second+1);
                check(xxx+2, yyy+1, vect[ii].second+1);
            }
            else{
                for (int jj = 1; jj < 10; jj++){
                    check(xxx+jj, yyy+jj, vect[ii].second+1);
                    check(xxx+jj, yyy-jj, vect[ii].second+1);
                    check(xxx-jj, yyy+jj, vect[ii].second+1);
                    check(xxx-jj, yyy-jj, vect[ii].second+1);
                }
            }
        }
        if (!found) cout << -1 << endl;
    }
}