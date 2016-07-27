/*
ID: messifo2
PROG: wormhole
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct one{
	int x,y;
};
bool cmp(const one & s1, const one & s2)
{
	return s1.y < s2.y;
}
one a[15];
int n,ans;
int near[15];

bool judge(int cp[])
{
//	for(int i = 1; i <= n; i++)
//		cout << cp[i] << " ";
//	cout << endl;
	for(int i = 1; i <= n; i++) {
		int s = i; 
		int e = s;
//		cout << "s = " << s << endl;
		//cout << "e = " << e << endl;
		cp[0] = 0;
		while(1) {
			e = near[e];
		//	cout << "e = " << e << endl;
			e = cp[e];
		//	cout << "e = " << e << endl;
			if(e == s) return true;
			if(e == 0) break;
		}
/*	    e= cp[s];
		while(1) {
			if(s == e) return true;
			if(e == 0) break;
			e = near[e];
			if(s == e) return true;
			if(e == 0) break;
			e = cp[e];
		}
		*/
	}
//	cout << "bingo" << endl << endl;
	//	for(int i = 1; i <= n; i++)
//		cout << cp[i] << " ";
//	cout << endl;
	return false;
}
void dfs(int cp[]) 
{
	bool tag = true;
	for(int i = 1; i <= n; i++) {
		if(cp[i] == 0) {
			tag = false;
		}
	}
	if(tag) {
		if(judge(cp)) ans++;
		return ;
	}
	for(int i = 1; i <=n; i++) {
		if(cp[i] == 0) {
			for(int j = i+1; j <=n; j++) {
				if(cp[j] == 0) {
					int num[15];
					for(int k = 1; k<=n ; k++) {
						num[k] = cp[k];
					}
					num[i] = j;
					num[j] = i;
					dfs(num);
				}
			}
			break;
		}
	}
}
int main()
{
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	int i,j;
	cin >> n;
	for(i=1;i<=n;i++) {
		cin >> a[i].x >> a[i].y;
	}
	memset(near,0,sizeof(near));
	for(i=1;i<=n;i++) {
		int tmp  = 0;
		for(j=1;j<=n;j++) {
			if(a[j].y == a[i].y && a[j].x > a[i].x) {
				if(tmp == 0) tmp = j;
				if(a[j].x < a[tmp].x ) {
					 tmp = j;
				}
			}
		}
		near[i] = tmp;
	}
//	for(i=1; i<=n; i++) printf("near[%d] = %d\n",i,near[i]);
	int cp[15] = {0};
	ans = 0;
	dfs(cp);
	cout << ans << endl;
}
