/*
ID: messifo2
PROG: shuttle
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 30;
int a[30],n,len;
vector<int> ans;

bool dfs(int pos) {
	if(pos > 2 && a[pos-1] == 0
	 && a[pos-2] == 1) {
		a[pos-2] = -1;
		a[pos] = 1;
		ans.push_back(pos-2);
		if(dfs(pos-2))
			return true;
		ans.pop_back();
		a[pos-2] = 1;
		a[pos] = -1; 
	}
	if(pos > 1 && a[pos-1] == 1) {
		a[pos] = 1;
		a[pos-1] = -1;
		ans.push_back(pos-1);
		if(dfs(pos-1))	
			return true;
		ans.pop_back();
		a[pos] = -1;
		a[pos-1] = 1; 
	}
	if(pos + 1 <= len && a[pos+1] == 0) {
		a[pos] = 0;
		a[pos+1] = -1;
		ans.push_back(pos+1);
		if(dfs(pos+1))
			return true;
		ans.pop_back();
		a[pos] = -1;
		a[pos+1] = 0;
	}
	if(pos + 2 <= len && a[pos+1] == 1
		&& a[pos+2] == 0) {
		a[pos+2] = -1;
		a[pos] = 0;
		ans.push_back(pos+2);
		if(dfs(pos+2))
			return true;
		ans.pop_back();
		a[pos] = -1;
		a[pos+2] = 0;
	}
	if(pos != n+1) return false;
	for(int i = 1; i <= n; i++) 
		if(a[i] == 1) return false;
	for(int i = n+2; i <= len; i++)
		if(a[i] == 0) return false;
	return true;
}

int main()
{
    freopen("shuttle.in","r",stdin);
    freopen("shuttle.out","w",stdout);
    cin >> n ;
    len = 2*n+1;
    for(int i = 1; i <= n; i++)
    	a[i] = 1;
    a[n+1] = -1;
    dfs(n+1);
    for(int i = 0 ; i < ans.size(); i++) {
    	if(i % 20 == 19) cout << ans[i] << endl;
    	else { 
    		if(i == ans.size()-1)
    			cout << ans[i] << endl;
    		else cout << ans[i] << " ";
    	}
    }
    return 0;
}
