/*
ID: messifo2
PROG: concom
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

int a[105][105];
bool own[105][105];
int n = 100;
int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	int m;
	cin >> m;
	int i,j,k,p;
	for(k=1; k<=m; k++) {
		cin >> i >> j >> p;
		a[i][j] = p;
	}
	memset(own,0,sizeof(own));
	while(1) {
		bool completed = true;
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				if(own[i][j]) continue;
				bool pre = own[i][j];
				if(i == j) own[i][j] = true;
				else if(a[i][j] > 50) own[i][j] = true;
				else{
					int tmp = 0;
					for(k=1; k<=n; k++) {
						if(own[i][k] == true) {
							tmp += a[k][j];
						}
					}
					if(tmp > 50) own[i][j] = true;
				}
				if(pre != own[i][j]) completed = false;
			}
		}
		if(completed) break;
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++){
			if(own[i][j] && i != j)
				cout << i <<" " << j << endl;
		}
	}
	return 0;
}
