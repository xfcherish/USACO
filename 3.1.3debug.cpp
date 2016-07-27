/*
ID: messifo2
PROG: humble
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = (1e9)+10;
int p[105];
int dp[100005],num[100005];
int dp2[100005];

int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble_debug.out","w",stdout);
    int k,n,i,j;
    cin >> k >> n;
    for(i = 1; i <= k; i++)
    	scanf("%d",&p[i]);
    sort(p+1,p+1+k);
    // cout << "k = " << k << "  n =" << n << endl;
    dp[0] = 1;
    int point = 0;
    memset(num,0,sizeof(num));
    int start = 0;
    for(i = 1 ; i <= n ; ) {
    	int tmp = INF;
    	int tmp_j = 1;
    	for(j = start; j < i; j++) {
    		int c = num[j]+1;
    		if(c > k) {
    			start = min(j+1,start);
    			continue;
    		}
    		int value = p[c]*dp[j];
    		if(tmp > value && value > 0) {
    			tmp = value;
    			tmp_j = j;
    		}
    	}
    	num[tmp_j]++;
    	if(tmp > dp[i-1]) {
    		dp[i] = tmp;
    		// cout << "dp[" << i << "]=" << dp[i] << endl;
    		i++;
    	}
    }
    dp2[0] = 1;
    priority_queue<long long, vector<long long>, greater<long long> > q;
    for(i = 1 ; i <= k; i++) {
        q.push(p[i]*dp2[0]);
    }
    for(i = 1 ; i <= n; i++) {
        while( !( q.top() > dp2[i-1])) {
            q.pop();
        }
        dp2[i] = q.top();
        q.pop();
        for(j = 1; j <= k; j++)
            q.push(dp2[i]*p[j]); 
    }    
    for(i = 1; i <= n; i++) {
        if(dp[i] != dp2[i])
            cout << "dp[" << i << "]=" << dp[i] << "   "
                << "dp2[" << i << "]=" << dp2[i] << endl;
    }
    return 0;
}
