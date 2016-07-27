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
    for(k = 1 ; k <= num_pastures; k++) {
      for(i = 1; i <= num_pastures; i++ ) {
        for(j = i+1 ; j <= num_pastures; j++ ) {
  				  dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            dist[j][i] = dist[i][j];
      	}
  		}
  	}
  	int ans = inf;
  	for(i = 1 ; i <= num_pastures; i++) {
  		int temp_result = 0 ;
  		for(j = 1; j <= num_cow; j++) {
  			 temp_result += dist[i][position[j]];
  		}
  		ans = min(temp_result,ans);
  	}
  	cout << ans << endl;
    return 0;
}





