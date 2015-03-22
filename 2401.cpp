#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define SIZE 100

int g[SIZE][SIZE], dist[SIZE];
int n,s,f;
vector <int> que;

int main(){
	cin >> n >> s >> f;
	memset(dist, -1, sizeof(dist));
	s--;
	f--;

	for (int i = 0; i<n; i++) for (int j = 0; j<n; j++) cin >> g[i][j];

	dist[s] = 0;
	que.push_back(s);
	for (int i = 0; i<que.size(); i++){
		if (que[i] == f){
			cout << dist[f] << endl;
			return 0;
		}
		for (int j = 0; j<n; j++)
			if (g[que[i]][j] && dist[j] == -1)
			{
				dist[j] = dist[que[i]]+1;
				que.push_back(j);
			}
	}

	cout << "0\n";
	return 0;
}