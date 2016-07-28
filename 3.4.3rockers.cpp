/*
ID: messifo2
PROG: rockers
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,T,M,ans;
int length[25];
int vis[25];

int solve(vector<int> a) {
	int cnt = 1;
	int cost[25];
	memset(cost,0,sizeof(cost));
	for(int i = 0; i < a.size(); i++) {
		if(cnt > M) return -1;
		if(a[i] + cost[cnt] <= T) {
			cost[cnt] += a[i];
		}
		else {
			cnt++;
			i--;
		}
	}
	if(cnt > M) return -1;
	return a.size();
}
void dfs(int depth) {
	if(depth == N+1) {
		vector<int> a;
		int sum = 0;
		for(int i = 1; i <=N; i++) {
			if(vis[i]) {
				a.push_back(length[i]);
				sum += length[i];
			}
		}
		if(sum <= T*M && sum > 0)
			ans = max(ans, solve(a));
		return;
	}
	dfs(depth+1);
	vis[depth] = 1;
	dfs(depth+1);
	vis[depth] = 0;
}

int main()
{
    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
    cin >> N >> T >> M;
    for(int i = 1; i <= N; i++)
    	cin >> length[i];
    memset(vis,0,sizeof(vis));
    ans = 0;
    dfs(1);
    cout << ans << endl;
    return 0;
}
