/*
ID: messifo2
PROG: fence9
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long n,m,p;

long long f1(long long x) {
	long long y = m*x/n;
	if(m*x % n == 0) y --;
	return y;
}

long long f2(long long x) {
	if(n == p) return -1;
	long long y = (m*(x-p))/(n-p);
	if(m*(x-p)%(n-p) == 0 && x!= p)
    	y --;
    return y;
}

int main()
{
    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
    long long y1,y2,y;
    cin >> n >> m >> p;
    long long max_x = max(n,p);
    long long ans = 0;
    if(n > p) {
    	for(long long x = 1 ; x <= p; x++) 
    		ans += f1(x);
    	for(long long x = p+1; x <= n; x++) {
    		ans += (f1(x) - f2(x));
    		if(m*(x-p)%(n-p) == 0 && (f1(x)!=f2(x)))
    			ans --;
    	}
    }
    else if(n < p) {
    	for(long long x = 1; x <= n; x++) 
    		ans += f1(x);
    	for(long long x = n+1; x <= p; x++)
    		ans += f2(x);	
    }
    else {
    	for(long long x = 1 ; x < p; x++) 
    		ans += f1(x);
    }
    cout << ans << endl;
    return 0;
}
