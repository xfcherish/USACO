/*
ID: messifo2
PROG: nocows
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

int dp[205][105];
const int mod = 9901;
int dfs(int n,int k)
{
	if(dp[n][k] != -1) return dp[n][k];
	int ans = 0;
	for(int i = 0; i<n; i++) {
		int tmp1 = dfs(i,k-1);
		int tmp2 = dfs(n-1-i,k-1);
		ans += tmp1 * tmp2 % mod;
		ans %= mod;
	}
	dp[n][k] = ans;
	return dp[n][k];
}
int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	int n,k;
	cin >> n >> k;
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i<=k; i++) 
		dp[0][i] = 0;
	for(int i = 1; i<=n; i++)
		dp[i][0] = 0;
	for(int i = 1; i<=k; i++)
		dp[1][i] = 1;
	dfs(n,k-1);
	dfs(n,k);
	/*
	for(int i = 1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j] << endl;
		}
	}
	*/
	int ans = (dp[n][k] - dp[n][k-1] + mod) % mod;
	cout << ans << endl;
	return 0;
}
