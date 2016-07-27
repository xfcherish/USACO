/*
ID: messifo2
PROG: ariprog
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 62500*2+10;
bool vis[maxn];
bool judge(int a,int b,int n)
{
//	cout << "a = " << a << " b = " << b << endl;
	for(int i = 0; i < n; i++) {
//		cout << "a+b*i=" << a+b*i << endl;
		if(!vis[a+b*i]) return false;
	}
	return true;
}
int main()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	int n,m,i,j,a,b;
	cin >> n >> m;
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++){
		//	cout << "tmp=" << i*i + j*j << endl;
			int tmp = i*i + j*j;
			vis[tmp] = 1;
		}
	}
	bool tag = true;
	for(b = 1; (n-1)*b <= 2*m*m; b++ ) {
		for(a = 0; a+(n-1)*b <= 2*m*m; a++) {
			if(judge(a,b,n)) { 
				cout << a << " " << b << endl;
				tag = false;
			}
		}
	}
	if(tag) cout << "NONE" << endl;
	return 0;
}
