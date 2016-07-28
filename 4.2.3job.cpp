/*
ID: messifo2
PROG: job
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 50;
const int inf = 1000000;
int a[maxn],b[maxn],a_cost[maxn],b_cost[maxn];
int a_time[maxn],res_a,res_b;

int main()
{
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    for(int i = 1; i <= m1; i++)
    	cin >> a[i];
    for(int i = 1; i <= m2; i++)
    	cin >> b[i];
    memset(a_cost, 0, sizeof(a_cost));
    res_a = 0;
    res_b = 0;
    for(int i = 1; i <= n; i++) {
    	int tmp_max = inf;
    	int tmp_j  = -1;
    	for(int j = 1; j <= m1; j++) {
    		if(tmp_max > a_cost[j]+a[j]) {
    			tmp_max = a_cost[j] + a[j];
    			tmp_j = j;
    		}
    	}
    	a_cost[tmp_j] = a_cost[tmp_j] + a[tmp_j];
    	a_time[i] = a_cost[tmp_j];
    	res_a = max(res_a, a_time[i]);
    }
    // cout << " res_a = " << res_a << endl;
    for(int i = n; i >= 1; i--) {
    	int tmp_max = inf;
    	int tmp_j = -1;
    	for(int j = 1; j <= m2; j++) {
    		if(tmp_max > max(b_cost[j],a_time[i])+b[j]) {
    			tmp_max = max(b_cost[j],a_time[i]) + b[j];
    			tmp_j = j;
    		}
    	}
    	b_cost[tmp_j] = max(b_cost[tmp_j], a_time[i]) + b[tmp_j];
    	res_b = max(res_b, b_cost[tmp_j]);
    }
    // cout << " res_b = " << res_b << endl;
    cout << res_a << " " << res_b << endl;
    return 0;
}
