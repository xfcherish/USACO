/*
ID: messifo2
PROG: nuggets
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = (256*256)+100;
int n;
int beef[15];
int f[maxn];

int main()
{
    freopen("nuggets.in","r",stdin);
    freopen("nuggets.out","w",stdout);
    int i,j,max_num;
    cin >> n;
    memset(f, 0, sizeof(f));
    for(i = 1; i <= n; i++) {
    	cin >> beef[i];
    	f[beef[i]] = 1;
    }
    sort(beef+1,beef+1+n);
    if(n ==  1) {
    	cout << 0 << endl;
    	return 0;
    }
    max_num = beef[n]*beef[n-1] - beef[n] - beef[n-1];
    max_num = max(max_num, beef[n]);
    // cout << " max_num = " << max_num << endl;
    for(i = 1 ; i <= max_num + beef[n]; i++) {
    	if(f[i] == 0) continue;
    	for(j = 1 ; j <= n; j++) 
    		f[i+beef[j]] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= max_num + beef[n]; i++) {
    	if(f[i] == 0)
    		ans = max(ans,i);
    }
    if(ans > max_num) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}
