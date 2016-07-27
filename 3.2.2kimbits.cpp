/*
ID: messifo2
PROG: kimbits
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
long long N,L,l;
LL dp[35][35];

void initial() {
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i = 0; i <= 31; i++)
		dp[i][0] = 1;
	for(i = 1; i <= N ; i++) {
		for(j = 1; j <= L; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	for(i = 0; i <= N; i++) {
		for(j = 1; j <= L; j++) {
			dp[i][j] += dp[i][j-1];
		}
	}
}

int main()
{
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    int i,j;
    cin >> N >> L >> l;
    initial();
    string ans;
    for(i = 1; i <= N; i++) {
    	// cout << " l = " << l << endl;
    	// cout << " dp[" << N-i << "][" << L << "] = " << dp[N-i][L] << endl;
    	if(l > dp[N-i][L]) {
    		ans += '1';
    		l -= dp[N-i][L];
    		L --;
    	}
    	else ans += '0';
    }
    cout << ans << endl;
    return 0;
}
