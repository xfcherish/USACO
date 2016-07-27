/*
ID: messifo2
PROG: game1
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int dp[maxn][maxn],sum[maxn][maxn];
int a[maxn];
int n;

int dfs(int left, int right) {
	if(dp[left][right] != -1 ) 
		return dp[left][right];
	if(left == right)  {
		dp[left][right] = a[left];
		return dp[left][right];
	}
	dp[left][right]  =  max(a[left] + sum[left+1][right] - dfs(left+1,right),
			 				a[right] + sum[left][right-1] - dfs(left, right-1));
	return dp[left][right];
}

int main()
{
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    cin >> n;
    for(int i = 1;  i <= n; i++)
    	cin >> a[i];
    memset(sum,0,sizeof(sum));
    memset(dp,-1,sizeof(dp));
    for(int i = 1; i <= n; i++) {
    	for(int j = i; j <= n; j++) {
    		sum[i][j] = sum[i][j-1] + a[j];
    	}
    }
    dfs(1,n);
    cout << dp[1][n] << " " << sum[1][n] - dp[1][n] << endl;
    return 0;
}



