#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define SIZE 1000

int g[SIZE][SIZE], dist[SIZE];
int n,s,f;
vector <int> que;

int main(){
	memset(dist, -1, sizeof(dist));

	cin >> n;
	for (int i = 0; i<n; i++) for (int j = 0; j<n; j++) cin >> g[i][j];
	cin >> s >> f;
	s--;
	f--;

	dist[s] = 0;
	que.push_back(s);
	for (int i = 0; i<que.size(); i++){
		if (que[i] == f) break;

		for (int j = 0; j<n; j++)
			if (g[que[i]][j] && dist[j] == -1)
			{
				dist[j] = dist[que[i]]+1;
				que.push_back(j);
			}
	}

	cout << dist[f] << endl;
	return 0;
}