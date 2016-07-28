/*
ID: messifo2
PROG: fence6
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;
int n;
struct Node	{
	int len;
	vector<int> l1;
	vector<int> l2;
	bool tag1,tag2;
};
Node node[maxn];
int vis[maxn];
int ans; 

void bfs(int start) {
	queue<vector<int> > q;
	vector<int> v;
	for(int i =1 ; i <= n; i++) {
		node[i].tag1 = false;
		node[i].tag2 = false;
	}
	v.push_back(start);
	q.push(v);
	// cout << "start = " << start << endl;
	while(!q.empty()) {
		vector<int> cur = q.front();
		q.pop();
		int len = cur.size();
		// cout << "cur vector = " << endl;
		// for(int i = 0 ; i < cur.size(); i++) {
		// 	cout << cur[i] << " ";
		// }
		// cout << endl;
		if(len != 1 && cur[0] == cur[len-1]) {
			int total_perimeter = 0;
			for(int i = 0; i < cur.size()-1; i++)
				total_perimeter += node[cur[i]].len;
			// for(int i = 0; i < cur.size(); i++)
			// 	cout << cur[i] << " ";
			// cout << endl;
			// cout << "total_perimeter = " 
			// 	 << total_perimeter << endl;
			ans = min(ans, total_perimeter);
		}
		else {
			int last = cur[len-1];
			// cout << "last = " << last << endl;
			if(node[last].tag1 == false) {
				node[last].tag1 = true;
				for(int i = 0; i < node[last].l1.size(); i++) {
					if(vis[node[last].l1[i]] == 1) continue;
					vector<int> u = cur;
					int new_element = node[last].l1[i];
					for(int j = 0; j < node[new_element].l1.size(); j++) {
						if(node[new_element].l1[j] == last) {
							node[new_element].tag1 = true;
							break;
						}
					}
					for(int j = 0; j < node[new_element].l2.size(); j++) {
						if(node[new_element].l2[j] == last) {
							node[new_element].tag2 = true;
							break;
						}
					}
					u.push_back(new_element);
					q.push(u);
				}
			}
			else if(node[last].tag2 == false) {
				node[last].tag2 = true;
				for(int i = 0; i < node[last].l2.size(); i++) {
					if(vis[node[last].l2[i]] == 1) continue;
					vector<int> u = cur;
					int new_element = node[last].l2[i];
					for(int j = 0; j < node[new_element].l1.size(); j++) {
						if(node[new_element].l1[j] == last) {
							node[new_element].tag1 = true;
							break;
						}
					}
					for(int j = 0; j < node[new_element].l2.size(); j++) {
						if(node[new_element].l2[j] == last) {
							node[new_element].tag2 = true;
							break;
						}
					}
					u.push_back(new_element);
					q.push(u);
				}
			}
		}
	}
}

int main()
{
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
    memset(vis, 0, sizeof(vis));
    ans = 1000000000;
    int len, n1,n2, tmp, order;
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> order >> len >> n1 >> n2;
    	node[order].len = len;
    	node[order].tag1 = false;
    	node[order].tag2 = false;
    	for(int j = 1; j <= n1; j++) {
    		scanf("%d",&tmp);
    		node[order].l1.push_back(tmp);
    	}
    	for(int j = 1; j <= n2; j++) {
    		scanf("%d",&tmp);
    		node[order].l2.push_back(tmp);
    	}
    }
    for(int i = 1; i <= n; i++) {
    	bfs(i);
    	vis[i] = 1;
    }
    cout << ans << endl;
    return 0;
}
