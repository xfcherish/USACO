/*
ID: messifo2
PROG: fence
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 501;
const int maxm = 1030;

int F;
int degree[maxn];
vector<int> adj[maxn];
vector<int> circuit;

void find_circuit(int start) {
    if(adj[start].size() == 0 ) 
        circuit.push_back(start);
    else {
        while(adj[start].size()!=0) {
            sort(adj[start].begin(), adj[start].end());
            int tmp = adj[start][0];
            for(vector<int>::iterator it = adj[start].begin(); it != adj[start].end(); it++ ) {
                if((*it) == tmp) {
                     adj[start].erase(it);
                     break;
                 }
            }
            for(vector<int>::iterator it = adj[tmp].begin(); it != adj[tmp].end(); it++ ) {
                if((*it) == start) {
                    adj[tmp].erase(it);
                    break;
                }
            }
            find_circuit(tmp);
        }
        circuit.push_back(start);
    }
}

int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    int node1,node2, start, min_num;
    cin >> F;
    memset(degree, 0, sizeof(degree));
    start = min_num = 501;
    for(int i = 1; i <= F; i++) {
    	scanf("%d%d",&node1, &node2);
    	adj[node1].push_back(node2);
    	adj[node2].push_back(node1);
    	degree[node1]++;
    	degree[node2]++;
        min_num = min(min(node1,node2),min_num);
    }
    for(int i = 1; i <= 500; i++) {
        if(adj[i].size() % 2 == 1) 
            start = min(start,i);
    }
    if(start == 501)
        start = min_num;
    // circuit.push_back(start);
    find_circuit(start);
    reverse(circuit.begin(), circuit.end());
    for(int i = 0; i < circuit.size(); i++) {
        cout << circuit[i] << endl;
    }
    return 0;
}
