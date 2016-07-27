/*
ID: messifo2
PROG: holstein
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int V,G;
int v[30],g[20][30];
bool vis[20];

struct one {
	int num;
	vector<int> res;
};

one ans;
bool cmp(const one s1, const one s2)
{
	if(s1.num != s2.num) 
		return s1.num < s2.num;
	else{
		for(int i = 0; i < s1.res.size(); i++) {
			if(s1.res[i] != s2.res[i])
				return s1.res[i] < s2.res[i];
		}
		return true;
	}
}
bool judge()
{
	int a[30] = {0};
	for(int i = 1; i<=G; i++) {
		if(vis[i] == true)
			for(int j = 1; j<=V; j++) {
				a[j] += g[i][j];
			}
	}
	for(int i = 1; i<=V; i++)
		if(a[i] < v[i]) return false;
	return true;
}
void dfs(int num)
{
	if( ans.num != 0 && num > ans.num)
		return ;
	one tmp;	
	tmp.num = num;
	for(int i = 1; i <= G; i++) 
		if(vis[i]) tmp.res.push_back(i);
	if(ans.num!=0 &&  cmp(ans,tmp))
		return ;
	if(judge()) {
		if(ans.num == 0) ans = tmp;
		else ans = tmp;
		return ;
	}
	for(int i = 1 ; i <= G; i++) {
		if(vis[i] == 0) {
			vis[i] = 1;
			dfs(num+1);
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	cin >> V;
	for(int i = 1; i <= V; i++) 
		cin >> v[i];
	cin >> G;
	for(int i = 1; i <= G; i++) {
		for(int j = 1; j <= V; j++) {
			cin >> g[i][j];
		}
	}
	memset(vis,0,sizeof(vis));
	ans.num = 0;
	dfs(0);
	cout << ans.num <<" ";
	for(int i = 0; i < ans.res.size() - 1; i++)
		cout << ans.res[i] << " ";
	cout << ans.res[ans.num-1] <<  endl;
	return 0;
}
