/*
ID: messifo2
PROG: agrinet
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 105;
const int inf = 500000;
int dist[maxn][maxn];
int n;
bool vis[maxn];
int dis[maxn];

int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    int i,j;
    cin >> n;
    for(i = 1; i <= n; i++) {
    	for(j = 1; j <= n; j++) {
    		scanf("%d",&dist[i][j]);
    	}
    }
    memset(vis,0,sizeof(vis));
    for(i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0;
	int ans = 0;
	for(i = 1; i <= n; i++ ) {
		int mark = -1;
		for(j = 1; j <= n; j++ ) {
			if(vis[j] == 0) {
				if(mark == -1)
					mark = j;
				else if(dis[j] < dis[mark])
					mark = j;
			}
		}
		if(mark == -1) break;
		vis[mark] = 1;
		ans += dis[mark];
		for(j = 1; j <= n; j++) {
			if(vis[j] == 0) {
				dis[j] = min(dis[j],dist[mark][j]);
			}
		}
	}
	cout << ans << endl;
    return 0;
}
