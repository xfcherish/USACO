/*
ID: messifo2
PROG: comehome 
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = (1e8)+100;
const int maxn = 100;
int dist[maxn][maxn];

int tran(char c)
{
	if(c<='z' && c>='a')
		return (c-'a');
	else return (c-'A'+26);
}
int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	int P,dis;
	char x,y;
	cin >> P;
	for(int i = 0; i < 52; i++) {
		for(int j = 0; j < 52; j++){
			dist[i][j] = INF;
		}
	}
	for(int i = 1; i <= P; i++) {
		cin >> x >> y >> dis;
		int xx = tran(x);
		int yy = tran(y);
		dist[xx][yy] = min(dist[xx][yy],dis);
		dist[yy][xx] = dist[xx][yy];
	}
	for(int k = 0; k < 52; k++) {
		for(int i = 0; i < 52; i++) {
			for(int j = 0; j < 52; j++) {
				if(dist[i][j] > dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	char ans = 'A';
	int ansdist = INF;
	for(char start = 'A' ; start < 'Z'; start++) {
		if(dist[tran(start)][tran('Z')] < ansdist) {
			ansdist = dist[tran(start)][tran('Z')];
			ans = start;
		}
	}
	cout << ans << " " << ansdist << endl;
	return 0;
}
