/*
ID: messifo2
PROG: skidesign
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1005;
int a[maxn];

int main()
{
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	int n,i,low,high;
	cin >> n;
	for(i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int total =1000000000;
	if(a[n]-a[1] <= 17) {
		cout << 0 << endl;
		return 0;
	}
	for(low = a[1]; low <= a[n]-17 ;low++) {
		high = low+17;
		int tmp = 0;
		for(i=1;i<=n;i++) {
			if(a[i] < low) tmp += (a[i]-low)*(a[i]-low);
		    if(a[i] > high) tmp += (a[i]-high)*(a[i]-high);
		}
		total = min(total,tmp);
	}
	cout << total << endl;
	return 0;
}
