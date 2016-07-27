/*
ID: messifo2
PROG: money
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

typedef long long LL;
LL  dp[10010][30];
int val[30];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,v;
	cin >> v >> n;
	for(int i=1; i<=v; i++)
		cin >> val[i];
	memset(dp,0,sizeof(dp));
	for(int i = 0; i<=v; i++)
		dp[0][i] = 1;
	for(int i = 1; i<=n; i++) { 
		for(int j = 1; j<=v; j++) {
			dp[i][j] = dp[i][j-1];
			if(i >= val[j]) {
			//	dp[i][j] += dp[i-val[j]][j-1] ;
				dp[i][j] += dp[i-val[j]][j];
			}
		//	cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j] << endl;
		}
	}
	cout << dp[n][v] << endl;
	return 0;
}




