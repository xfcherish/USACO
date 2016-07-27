/*
ID: messifo2
PROG: subset
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

const int maxn = 55;

long long dp[40][800];
int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	int n,i,j;
	cin >> n ;
	int sum = n*(n+1)/2;
	if( sum % 2 != 0) {
		cout << 0 << endl;
		return 0;
	}
	sum = sum /2;
	memset(dp,0,sizeof(dp));
	for(int i = 1; i<=n ;i++)
		dp[i][0] = 1;
	dp[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j =1 ; j <= sum; j++) {
			if(j < i) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j-i] + dp[i-1][j];
	//		cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j] << endl;
		}
	}
	//cout << "sum="<< sum << endl;
	cout << dp[n][sum]/2 << endl;
	return 0;
}
