#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

#define SIZE 800

char g[SIZE][SIZE], tmp;
int bee_dist[SIZE][SIZE], bear_dist[SIZE][SIZE];
int n,s,sx,sy,fx,fy;

vector <>

void check_bee(int x, int y, int dist){
	if (x>=0 && x < n && y>=0 && y<n && g[x][y]=='G' && !bee_dist[x][y]){
		bee_dist[x][y] = dist;

	}
}

int main(){
	scanf("%d %d", &n, &s);
	for (int i = 0; i<n; i++){
		scanf("%c", &tmp);
		for (int j = 0; j<n; j++){
			scanf("%c", g[i] + j);

			if (g[i][j] == "H"){

			}
		}
	}

}