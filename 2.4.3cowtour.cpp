/*
ID: messifo2
PROG: cowtour
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 160;
const double INF  = 500000;
int n;
double dist[maxn][maxn];
double max_dist[maxn];
int adja[maxn][maxn];
int p[maxn][2];

double cal_dist(int i,int j)
{
    double ans = 0;
    ans += (p[i][0]-p[j][0])*(p[i][0]-p[j][0]);
    ans += (p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
    ans = sqrt(ans);
    return ans;
}
int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    int i,j,k;
    cin >> n;
    for(i = 1; i <= n; i++) {
    	scanf("%d%d",&p[i][0],&p[i][1]);
    }
    for(i = 1; i <= n; i++) {
    	for(j = 1; j <= n; j++) {
    		scanf("%1d",&adja[i][j]);
    	}
    }
    memset(dist,0,sizeof(dist));
    for(i = 1; i <= n; i++) {
        for(j = i+1; j <= n; j++) {
            if(adja[i][j] == 1) {
                dist[i][j] = cal_dist(i,j);
            }
            else{
                dist[i][j] = INF;
            }
            dist[j][i] = dist[i][j];
        }
    }
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                }
            }
        }
    }
    vector<int> v1,v2;
    for(i = 1; i <= n ; i++ ) {
        if(dist[i][1] == INF) {
            v2.push_back(i);
        } 
        else v1.push_back(i);
    }
    double diameter = 0;
    double result = INF;
    for(i = 1; i <= n; i++) {
        max_dist[i] = 0;
        for(j = 1; j <= n; j++) {
            if(dist[i][j] < INF) {
                max_dist[i] = max(max_dist[i],dist[i][j]);
            }
        }
        diameter = max(diameter,max_dist[i]);
    }
    for(i = 1; i <= n ; i++) {
        for(j = i+1; j <= n; j++) {
            if(dist[i][j] == INF) {
                double tmp = max(diameter, cal_dist(i,j)
                    +max_dist[i] + max_dist[j]);
                result = min(result,tmp);
            }
        }
    }
    printf("%.6lf\n",result);
    return 0;
}
