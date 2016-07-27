/*
ID: messifo2
PROG: stamps
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 200*10000+10;
const int maxm = 10000;
const int inf = 1061109567;
int dp[maxm*2+10];
int nums[60];

int main()
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    int i,k,n;
    cin >> k >> n;
   	for(i = 1; i <= 2*maxm; i++) {
   		dp[i] = inf;
   	}
    for(i = 1; i <= n; i++) {
    	cin >> nums[i];
    	dp[nums[i]] = 1;
    }
    int result = -1;
    for(i = 1;  ; i++) {
    	if(i > 1 && (i-1)%maxm == 0) {
    		for(int j = 1; j <= maxm; j++) {
    			dp[j] = dp[j+maxm];
    			dp[j+maxm] = inf;
    		}
    	}
    	int ii = (i%maxm == 0 ? maxm : (i%maxm));
    	if(dp[ii] > k) {
    		result = i-1;
    		break;
    	}
    	for(int j = 1 ; j <= n; j++) {
    		int tmp = ii + nums[j];
    		dp[tmp] = min(dp[tmp],dp[ii]+1);
    	}
    }
    cout << result << endl;
    return 0;
}
