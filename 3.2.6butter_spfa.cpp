/*
ID: messifo2
PROG: butter
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 810;
const int inf = 0x3f3f3f3f;
int dist[maxn];
int position[maxn];
int num_cow,num_pastures,num_paths;
vector< pair<int,int> > g[maxn+10];

bool inQue[maxn];


void spfa(int src) {
    memset(dist,0x3f,sizeof(dist));
    memset(inQue, 0 , sizeof(inQue));
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    inQue[src] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < g[cur].size(); i++) {
            if(dist[cur] + g[cur][i].second < dist[g[cur][i].first]) {
                dist[g[cur][i].first] = dist[cur] + g[cur][i].second;
                if(inQue[g[cur][i].first] == 0) {
                    inQue[g[cur][i].first] = 1;
                    q.push(g[cur][i].first);
                }
            }
        }
        inQue[cur] = 0;
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
    for(i = 1; i <= num_paths; i++) {
        int temp_a, temp_b, distance;
        cin >> temp_a >> temp_b >> distance;
        g[temp_a].push_back(pair<int,int>(temp_b,distance));
        g[temp_b].push_back(pair<int,int>(temp_a,distance));
    }
    int ans = inf;
    for(i = 1 ; i <= num_pastures ; i++) {
        spfa(i);
        int temp_result = 0;
        for(j = 1; j <= num_cow; j++) {
            if(dist[position[j]] == inf) {
                temp_result = inf;
                break;
            }
            temp_result += dist[position[j]];
        }
        ans = min(temp_result,ans);
    }
  	cout << ans << endl;
    return 0;
}





