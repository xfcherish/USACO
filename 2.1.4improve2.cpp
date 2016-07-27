/*
ID: messifo2
PROG: holstein
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int V,G,minans;
int v[30],g[20][30];
int vis[20],res[20];

bool judge()
{
	int a[30] = { 0 };
	for(int i = 1 ; i<= G; i++) {
		if(vis[i]) {
			for(int j = 1; j <= V; j++)
				a[j] += g[i][j];
		}
	}
	for(int i = 1; i<=V; i++)
		if(a[i] < v[i]) return false;
	return true;
}
void dfs(int num)
{
	if( num > G) return;
	if(num == G && judge()) {
		int ans = 0;
		for(int i = 1 ; i <= G; i++)
			if(vis[i]) ans++;
		if(minans == -1) {
			minans = ans;
			for(int i = 1; i <=G; i++)
				res[i] = vis[i];
		}
		if(ans <= minans) { 
			minans = ans;
			for(int i = 1; i <=G; i++)
				res[i] = vis[i];
		}
		return ;
	}
	for(vis[num+1] = 0; vis[num+1] <= 1; vis[num+1]++) {
		dfs(num+1);
	}
}

int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	cin >> V;
	for(int i = 1; i <= V; i++) 
		cin >> v[i];
	cin >> G;
	for(int i = 1; i <= G; i++) {
		for(int j = 1; j <= V; j++) {
			cin >> g[i][j];
		}
	}
	memset(vis,0,sizeof(vis));
	minans = -1;
	dfs(0);
	cout << minans ;
	for(int i = 1; i <= G; i++)
		if(res[i]) cout << " " << i;
	cout << endl;
	return 0;
}
