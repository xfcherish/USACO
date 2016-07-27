/*
ID: messifo2
PROG: combo
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool dist(int a, int b)
{
	int d = (a-b>=0 ? (a-b):(b-a) );
	if(d <=2) return true;
	if(d >= n-2) return true;
	return false;
}
bool judge(int a[],int b[])
{
	for(int i =0; i<3; i++) {
		if(dist(a[i],b[i]) == false)
			return false;
	}
	return true;
}
int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int a[3],b[3],c[3];
	cin >> n;
	for(int i = 0; i<3; i++) cin >> a[i];
	for(int i = 0; i<3; i++) cin >> b[i];
	int ans = 0;
	for(c[0]=1; c[0]<=n; c[0]++)
		for(c[1]=1; c[1]<=n; c[1]++)
			for(c[2]=1; c[2]<=n; c[2]++) {
				if( judge(a,c) || judge(b,c) )
					ans ++;
			}
	cout << ans << endl;
}
