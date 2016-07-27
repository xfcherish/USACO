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
int a[maxn][maxn],sum[maxn][maxn];
int f[maxn];

bool judge(int i, int j, int k) {
    int i_last = i + k - 1;
    int j_last = j + k - 1;
    if(i_last > n || j_last > n) 
        return false;
    int temp = sum[i_last][j_last] - sum[i-1][j_last]
              - sum[i_last][j-1] + sum[i-1][j-1];
    if(temp == k*k) return true;
    return false;
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
        for(int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] 
                        - sum[i-1][j-1] + a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int k = 2;
            while(judge(i,j,k)) {
                f[k]++;
                k += 1;
            }
        }
    }
    for(int i = 2 ; i <= n; i++) 
        if(f[i] != 0)
            cout << i << " " << f[i] << endl;
    return 0;
}
