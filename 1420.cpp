#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct xy{
	int x,y;
	xy(int xx, int yy) : x(xx), y(yy){}
	xy() : x(0), y(0){}
};

struct horses{
	xy h1, h2;
	horses(xy hh1, xy hh2) : h1(hh1), h2(hh2){}
	horses() : h1(xy()), h2(xy()){}
} s,f;

bool operator ==(xy &a, xy &b){
	return a.x == b.x && a.y == b.y;
}

bool operator !=(xy &a, xy &b){
	return a.x != b.x || a.y != b.y;
}

bool operator ==(horses &a, horses &b){
	return a.h1 == b.h1 && a.h2 == b.h2;
}

vector<pair<horses, int> > que;
vector<horses> way;
bool used[8][8][8][8];

void getXY(xy &tmp){
	string ss;
	cin >> ss;
	tmp.x = ss[0]-'a';
	tmp.y = ss[1]-'1';
}

void check(xy h1, xy h2, int index){
	if (	h1.x >= 0 && h1.x < 8 && h1.y >= 0 && h1.y < 8 
		&& 	h2.x >= 0 && h2.x < 8 && h2.y >= 0 && h2.y < 8
	 	&& !used[h1.x][h1.y][h2.x][h2.y] && h1 != h2)
	{
		used[h1.x][h1.y][h2.x][h2.y] = true;
		que.push_back(make_pair(horses(h1, h2),index));
	}
}

int main(){
	getXY(s.h1);
	getXY(s.h2);
	getXY(f.h1);
	getXY(f.h2);

	check(s.h1,s.h2,-1);

	for (int i = 0; i<que.size(); i++){
		if (que[i].first == f){
			while(i != -1){
				way.push_back(que[i].first);
				i = que[i].second;
			}	
			break; 
		}
		int xxx1 = que[i].first.h1.x,
			xxx2 = que[i].first.h2.x, 
			yyy1 = que[i].first.h1.y, 
			yyy2 = que[i].first.h2.y;

		check(xy(xxx1-1, yyy1-2), xy(xxx2, yyy2), i);
		check(xy(xxx1-1, yyy1+2), xy(xxx2, yyy2), i);
		check(xy(xxx1+1, yyy1-2), xy(xxx2, yyy2), i);
		check(xy(xxx1+1, yyy1+2), xy(xxx2, yyy2), i);
		check(xy(xxx1-2, yyy1-1), xy(xxx2, yyy2), i);
		check(xy(xxx1-2, yyy1+1), xy(xxx2, yyy2), i);
		check(xy(xxx1+2, yyy1-1), xy(xxx2, yyy2), i);
		check(xy(xxx1+2, yyy1+1), xy(xxx2, yyy2), i);

		check(xy(xxx1, yyy1), xy(xxx2-1, yyy2-2), i);
		check(xy(xxx1, yyy1), xy(xxx2-1, yyy2+2), i);
		check(xy(xxx1, yyy1), xy(xxx2+1, yyy2-2), i);
		check(xy(xxx1, yyy1), xy(xxx2+1, yyy2+2), i);
		check(xy(xxx1, yyy1), xy(xxx2-2, yyy2-1), i);
		check(xy(xxx1, yyy1), xy(xxx2-2, yyy2+1), i);
		check(xy(xxx1, yyy1), xy(xxx2+2, yyy2-1), i);
		check(xy(xxx1, yyy1), xy(xxx2+2, yyy2+1), i);
	}

	for (int i = way.size()-2; i>=0; i--){
		if (way[i].h1 == way[i+1].h1){
			cout 	<< "2 " << char(way[i].h2.x + 'a') 
							<< char(way[i].h2.y + '1') << endl;
		}
		else{
			cout 	<< "1 " << char(way[i].h1.x + 'a') 
							<< char(way[i].h1.y + '1') << endl;	
		}
	}
	return 0;
}