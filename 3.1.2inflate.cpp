/*
ID: messifo2
PROG: inflate
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int M = 10005;
const int N = 10005;
int dp[2][M];
int cost[N],value[N];

int main()
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    memset(dp,0,sizeof(dp));
    int max_cost,n,i,j;
    cin >> max_cost >> n;
    for(i = 1; i <= n; i++) {
    	cin >> value[i] >> cost[i];
    }
    for(i = 1; i <= n; i++) {
    	for(j = 1; j <= max_cost; j++) {
    		if(j < cost[i]) 
    			dp[i%2][j] = dp[(i-1)%2][j];
    		else
    			dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-cost[i]]+value[i]);
    		// if(dp[i%2][j] != 0 )
    			// cout << "dp["<<i<<"]["<<j<<"]="<<dp[i%2][j] << endl;
    	}
    }
    cout << dp[n%2][max_cost] << endl;
    return 0;
}
