/*
ID: messifo2
PROG: ditch
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int inf = (1e9)+10;
const int maxn = 200 + 10;
const int maxm = 200 + 10;

struct Edge {
	int v,f,nxt;
};

int n,m,src,sink;
int g[maxn];
int nume;
Edge e[maxm*2];

void addedge(int u, int v, int c) {
	e[++nume].v = v;
	e[nume].f = c;
	e[nume].nxt = g[u];
	g[u] = nume;
	e[++nume].v = u;
	e[nume].f = 0;
	e[nume].nxt = g[v];
	g[v] = nume;
}

void init() {
	memset(g, 0, sizeof(g));
	nume = 1;
}

queue<int> que;
int vis[maxn],dist[maxn];

void bfs() {
	memset(dist, 0, sizeof(dist));
	while(!que.empty()) que.pop();
	vis[src] = 1;
	que.push(src);
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		for(int i = g[u]; i; i = e[i].nxt) 
			if(e[i].f && !vis[e[i].v]) {
				que.push(e[i].v);
				dist[e[i].v] = dist[u] + 1;
				vis[e[i].v] = 1;
			}
	}
}

int dfs(int u, int delta) {
	if(u == sink) {
		return delta;
	} else {
		int ret = 0;
		for(int i = g[u]; delta && i; i = e[i].nxt)
			if(e[i].f && dist[e[i].v] == dist[u] + 1) {
				int dd = dfs(e[i].v, min(e[i].f, delta));
				e[i].f -= dd;
				e[i^1].f += dd;
				delta -= dd;
				ret += dd;
			}
		return ret;
	}
}

int maxflow() {
	int ret = 0;
	while(true) {
		memset(vis, 0, sizeof(vis));
		bfs();
		if (!vis[sink]) return ret;
		ret += dfs(src,inf);
	}
	return ret;
}
int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    int u,v,c;
    cin >> m >> n;
    init();
    for(int i = 1; i <= m; i++) {
    	cin >> u >> v >> c;
    	addedge(u,v,c);
    }
    src = 1;
    sink = n;
    cout << maxflow() << endl;
    return 0;
}
