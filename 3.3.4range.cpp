/*
ID: messifo2
PROG: range
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 255;
int n;
int a[maxn][maxn],b[maxn][maxn];
int f[maxn];

int expand(int x, int y, int len) {
	if(x+len-1 > n || y+len-1 > n)
		return 1; 
	bool tag = true;
	for(int i = x; i < x+len ; i++)
		if(a[i][y+len-1] == 0) {
			tag = false;
			break;
		}
	for(int i = y; i < y+len; i++) {
		if(a[x+len-1][i] == 0) {
			tag = false;
			break;
		}
	}
	if(tag == true) {
		return 1+expand(x,y,len+1);
	}
	return 1; 
}

int main()
{
    freopen("range.in","r",stdin);
    freopen("range.out","w",stdout);
    memset(f,0,sizeof(f));
    cin >> n;
    for(int i = 1 ; i <= n; i++) {
    	for(int j = 1; j <= n; j++ ) {
    		scanf("%1d", &a[i][j]);
    	}
    }
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= n; j++ ) {
    		if(a[i][j] == 1) {
    			int len  = b[i][j-1];
    			if(len < 3)
    				b[i][j] = expand(i,j,2);
    			else{
    				for(int k = 2; k < len; k++)
    					f[k]++;
    				b[i][j] = expand(i,j,len);
    			}
    		}
    	}
    }
    int total_ans = 0;
    for(int i = 2; i <= n; i++ ) {
    	total_ans += f[i];
    	if(f[i] != 0)
    		cout << i << " " << f[i] << endl;
    }
    cout << "total = " << total_ans << endl;
    return 0;
}
