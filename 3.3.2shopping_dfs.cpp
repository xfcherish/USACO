/*
ID: messifo2
PROG: shopping
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 105;
vector<pair<int,int> > offer[maxn];
map<vector<int>,int> m;
int prices[maxn];
int single_prices[10];
int unique_code[1000],find_code[1000];
int s,b;


int dfs(vector<int> v, int depth) {
	// cout << depth << endl;
	vector<int> str = v;
	str.push_back(depth);
	if(m[str] != 0 ) 
	 	return m[str];
	int ans = 1000000000;
	if(depth == s+1) {
		int res = 0;
		for(int i = 0; i < v.size(); i++) {
			res += v[i]*single_prices[i+1];
		}
		// for(int i = 0; i < v.size(); i++)
		// 	cout << v[i] << " ";
		// cout << endl;
		// cout <<  "res = " << res << endl;
		m[str] = res;
		return res;
	}
	int num = 0;
	vector<int> u = v;
	while(1) {
		int n  = offer[depth].size();
		bool tag = true;
		u = v;
		// cout << " n = " << n  << endl;
		for(int i = 0; i < n; i++) {
			int c = offer[depth][i].first;
			int k = offer[depth][i].second;
			int order = find_code[c];
			// cout << " i = " << i << endl;
			// cout << " c = " << c << endl;
			// cout << " k = " << k << endl;
			// cout << " order =" << order << endl;
			if(v[order] < num *k ) {
				tag = false;
				break;
			}
			else {
				u[order] = v[order] - num*k;
			}
		}
		if(tag) {
			// cout << "u = " << endl;
			// for(int i = 0; i < u.size(); i++)
			// 	cout << u[i] << " ";
			// cout << endl;
			ans = min(ans, num*prices[depth]+ dfs(u,depth+1));
		}
		else break;
		num++;
	}
	m[str] = ans;
	return ans;
}
int main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    int n,c,k,p;
    cin >> s;
    for(int i = 1; i <= s ; i++) {
    	cin >> n;
    	for(int j = 1; j <= n; j++) {
    		cin >> c >> k;
    		offer[i].push_back(pair<int,int>(c,k));
    	}
    	cin >> prices[i];
    }
    cin >> b;
    vector<int> v;
    for(int i = 1; i <=b ; i++) {
    	cin >> c >> k >> p;
    	unique_code[i] = c;
    	find_code[c] = i-1;
    	single_prices[i] = p;
    	v.push_back(k);
    }
    int ans = dfs(v,1);
    cout << ans << endl;
    return 0;
}
