#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int toint(string s){
	int res = 0;
	for (int i = 0; i<s.size(); i++) res = res * 10 + s[i] - 48;
	return res;
}

string tostr(int a){
	string res = "";
	while(a){
		res += a%10+48;
		a/=10;
	}
 	reverse(res.begin(), res.end());
	return res;
}



int n,k,tmp,st,fin,i;
map <int, int> dist;
vector <int> que1,que2;
string ss, sstmp;

void check(int x, int val){
	if (!dist[x]){
		dist[x] = val;
		que2.push_back(x);	
	}
}

int main(){
	while(cin){
		cin >> n >> k;
		if (cin){
			st = fin = 0;
			for (i = 0; i<n; i++) {
				cin >> tmp;
				st = st * 10 + tmp;
				fin = fin * 10 + i + 1;
			}

			dist.clear();
			que1.clear();
			que2.clear();
			check(st,1);
			swap(que1, que2);
			bool ans_found = false;

			while(!que1.empty() && !ans_found){
				for (i = 0; i<que1.size(); i++){
					if (que1[i] == fin){
						cout << dist[fin]-1 << endl;
						ans_found = true;
						break;
					}
					ss = tostr(que1[i]);
					for (int j = 0; j<n-k+1; j++){
						sstmp = ss;
						reverse(sstmp.begin()+j, sstmp.begin()+j+k);
						check(toint(sstmp), dist[que1[i]]+1);			
					}
				}	
				que1.clear();
				swap(que1, que2);
			}
			if (!ans_found) cout << "-1\n";
		}
	}
	return 0;
}