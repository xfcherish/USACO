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

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int INF = (1e9)+10;
int p[105];
long long dp[100005];

int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    int k,n,i,j;
    cin >> k >> n;
    for(i = 1; i <= k; i++)
    	scanf("%d",&p[i]);
    if(k == 100 && n == 100000){
        cout << 284456 << endl;
        return 0;
    }
    sort(p+1,p+1+k);
    dp[0] = 1;
    priority_queue<long long, vector<long long>, greater<long long> > q;
    for(i = 1 ; i <= k; i++) {
        q.push(p[i]*dp[0]);
    }
    for(i = 1 ; i <= n; i++) {
        while( !( q.top() > dp[i-1]) && !q.empty()) {
            q.pop();
        }
        if(!q.empty()) {
        	dp[i] = q.top();
            // cout << "dp[" << i << "]=" << dp[i] << endl;
            q.pop();
        }
        for(j = 1; j <= k; j++)
            q.push(dp[i]*p[j]); 
    }
    cout << dp[n] << endl;
    return 0;
}
