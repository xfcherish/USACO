/*
ID: messifo2
PROG: numtri
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int a[maxn][maxn],dp[maxn][maxn];
int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int n,i,j;
	cin >> n;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			scanf("%d",&a[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	dp[1][1] = a[1][1];
	for(i=2;i<=n;i++){
		for(j=1;j<=i;j++){
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++)
		ans = max(ans,dp[n][i]);
	cout << ans << endl;
	return 0;
}
