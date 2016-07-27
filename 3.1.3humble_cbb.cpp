/*
ID: messifo2
PROG: humble
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>



using namespace std;

const int INF = (1e9)+10;
const int maxn = (1e5)+10;
int p[105],numbers[105],counts[105];
int a[maxn];

int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    int k,n,i,j;
    cin >> k >> n;
    for(i = 1; i <= k; i++) {
    	scanf("%d",&p[i]);
        numbers[i] = p[i];
    }
    memset(counts,0,sizeof(counts));
    for(int i = 1; i <= n; i++) {
        a[i] = INF;
        for(int j = 1; j <= k; j++) {
            a[i] = min(a[i],numbers[i]);
        }
        for(int j = 1; j <= k; j++) {
            if(a[i] == numbers[j]) {
                numbers[j] = p[j]*a[++counts[j]];
            }
        }
    }
    cout << a[n] << endl;
    return 0;
}
