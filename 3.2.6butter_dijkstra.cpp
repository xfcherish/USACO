/*
ID: messifo2
PROG: butter
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1500;
const int maxm = 810;
const int inf = 0x3f3f3f3f;
int dist[maxn][maxn];
int position[maxm];
int num_cow,num_pastures,num_paths;

bool vis[maxn];
void dijkstra(int source) {
    int vis[maxn];
    dist[source][source] = 0;
    memset(vis,0,sizeof(vis));
    vis[source] = 1;
    for(int i = 1; i <= num_pastures; i++ ) {
        int mark = -1;
        int min_dist = inf;
        for(int j = 1; j <= num_pastures; j++ ) {
            if(vis[j] == 0 && dist[source][j] < min_dist) {
                min_dist = dist[source][j];
                mark = j;
            }
        }
        if(mark == -1) return ;
        vis[mark] = 1;
        for(int j = 1 ; j <= num_pastures; j++ ) {
            dist[source][j] = min(dist[source][j], dist[source][mark]
                    + dist[mark][j]);
            dist[j][source] = dist[source][j];
        } 
    }
}
int main()
{
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    int i,j,k,ii,jj;
    cin >> num_cow >> num_pastures >> num_paths;
    for(i = 1; i <= num_cow; i++) 
    	 cin >> position[i];
    memset(dist,0x3f,sizeof(dist));
    for(i = 1 ; i <= num_pastures ; i++)
        dist[i][i] = 0;
    for(i = 1; i <= num_paths; i++) {
        int temp_a, temp_b, distance;
        cin >> temp_a >> temp_b >> distance;
        dist[temp_a][temp_b] = distance;
        dist[temp_b][temp_a] = distance;
    }
    for(i = 1 ; i <= num_cow ; i++) {
        int temp = position[i];
        // int temp = i;
        dijkstra(temp);
    }
  	int ans = inf;
  	for(i = 1 ; i <= num_pastures; i++) {
      int temp_result = 0 ;
      for(j = 1; j <= num_cow; j++) {
        if(dist[i][position[j]] == inf) {
           temp_result = inf;
           break;
        }
        temp_result += dist[i][position[j]];
      }
      // cout << "i = " << i << " temp_result = "
      //     << temp_result << " ans = " << ans << endl;
      ans = min(temp_result,ans);
    }
  	cout << ans << endl;
    return 0;
}





