/*
ID: messifo2
PROG: race3
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

# define pb push_back

using namespace std;

const int maxn = 55;
vector<int> nxt[maxn];
vector<int> unavoid,splits;
int neig[maxn][maxn];
int n,forbid;
bool state[maxn],vis[maxn];

bool route(int start) {
	if(start == n) return true;
	for(int i = 0; i < nxt[start].size(); i++) {
		int nxt_point = nxt[start][i];
		if(nxt_point == forbid) continue;
		if(vis[nxt_point] == 0) {
			vis[nxt_point] = 1;
			if(route(nxt_point))
				return true;
		}
	} 
	return false;
}

void dfs_back(int point) {
	if(point == 0 || point == n) {
		state[point] = 1;
		return;
	}
	if(state[point] == 1) return;
	state[point] = 1;
	for(int i = 0; i < nxt[point].size(); i++) {
		dfs_back(nxt[point][i]);
	}

}

int main()
{
    freopen("race3.in","r",stdin);
    freopen("race3.out","w",stdout);
    int cnt,tmp;
    vector<int> input;
    n = 0;
    while(cin >> tmp && tmp != -1) {
    	if(tmp != -2) input.pb(tmp);
    	else {
    		for(int i = 0; i < input.size(); i++) {
    			if(n != input[i]) {
	    			nxt[n].pb(input[i]);
	    			neig[n][input[i]] = 1;
    			}
    		}
    		input.clear();
    		n++;
    	}
    }
    n--;
    // cout << " n = " << n << endl;
    for(int i = 1; i < n; i++) {
    	forbid = i;
    	memset(vis,0,sizeof(vis));
    	vis[0] = 1;
    	if(route(0) == false) 
    		unavoid.pb(i);
    }
    // forbid = -1;
    for(int i = 0; i < unavoid.size(); i++) {
    	int point = unavoid[i];
    	// if(blackmail[point]) continue;
    	memset(state,0,sizeof(state));
    	dfs_back(point);
    	bool tag = true;
    	bool all_the_same = true;
    	// cout << "state[" << i << "]=" << state[i] << endl;
    	for(int j = 0; j <= n; j++) {
    		if(j == point) continue;
    		for(int k = j+1; k <= n; k++) {
    			if(k == point) continue;
    			if(state[j] != state[k]) {
    				all_the_same = false;
    				if(neig[j][k] == 1 || neig[k][j] == 1) {
    					// cout << "j = " << j << "  k = " << k << endl;
    					tag = false;
    					break;
    				}
    			}
    		}
    	}
    	if(tag && !all_the_same) {
    		splits.pb(point);
    	}
    }
    sort(unavoid.begin(), unavoid.end());
    sort(splits.begin(), splits.end());
    cout << unavoid.size();
    for(int i = 0; i < unavoid.size(); i++)
    	cout << " " << unavoid[i];
    cout << endl;
    cout << splits.size();
    for(int i = 0; i < splits.size(); i++)
    	cout << " " << splits[i];
    cout << endl;
    return 0;
}
