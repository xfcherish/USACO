/*
ID: messifo2
PROG: humble
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = (1e9)+10;
int p[105];
int dp[100005],num[100005];

int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
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
    		cout << "dp[" << i << "]=" << dp[i] << endl;
    		i++;
    	}
    }
    cout << dp[n] << endl;
    return 0;
}
