/*
ID: messifo2
PROG: buylow
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn = 5005;
const int inf = (1e9)+10;
int n,a[maxn],c[maxn],dp[maxn];
int ans,results;

struct node {
	int val,pos;
};

vector<node> end_num[maxn];

void search(int depth, int now_order, int now_val, int ret) {
	// cout << "depth = " << depth << endl;
	// cout << "now_order  = " << now_order << endl;
	// cout << "now_val = " << now_val << endl;
	if(depth == ans+1) {
		// cout << "ret = " << ret << endl;
		results += ret;
		return;
	}
	set<int> my_sets;
	for(int i = 0; i < end_num[depth].size(); i++) {
		int new_order = end_num[depth][i].pos;
		int new_val = end_num[depth][i].val;
		if(new_order > now_order && new_val > now_val) {
			if(my_sets.find(new_val) == my_sets.end())
				my_sets.insert(new_val);
			else continue;
		   	search(depth+1, new_order, new_val, ret);
		} 
	}
}

int main()
{
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	c[i] = inf;
    }
    memset(dp,0,sizeof(dp));
    ans = 0;
    reverse(a+1, a+1+n);
    for(int i = 1; i <= n; i++) {
    	int k = lower_bound(c+1, c+1+n, a[i]) - c;
    	c[k] = a[i];
    	dp[i] = k;
    	ans = max(ans,dp[i]);
    	node tmp;
    	tmp.pos = i;
    	tmp.val = a[i];
    	end_num[k].push_back(tmp);
    }
  	search(1,0,0,1);
   	cout << ans << " " << results << endl;
    return 0;
}
