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
int prices[maxn];
int single_prices[10];
int unique_code[1000],find_code[1000];
int f[6][6][6][6][6];
int s,b;

int dfs(vector<int> a) {
	if(f[a[0]][a[1]][a[2]][a[3]][a[4]] != 0)
		return f[a[0]][a[1]][a[2]][a[3]][a[4]];
	int ans = (1e9)+10;
	bool all_tag = false;
	for(int i = 1; i <=s; i++) {
		bool tag = true;
		vector<int> u = a;
		for(int j = 0; j < offer[i].size(); j++) {
			int c = offer[i][j].first;
			int k = offer[i][j].second;
			int order = find_code[c];
			if(a[order] < k) {
				tag = false;
				break;
			}
			else {
				u[order] = a[order] - k;
			}
		}
		if(tag) {
			ans = min(ans, prices[i]+dfs(u));
			all_tag = true;
		}
	}
	if(all_tag == false) {
		int res = 0;
		for(int i = 0; i < 5; i++) {
			res += a[i]*single_prices[i+1];
		}
		ans = res;
	}
	// cout << "f[" << a[0] << "," << a[1] << ","<< a[2]
	// 	<< "," << a[3] << "," << a[4] << "]=" << ans << endl;
	f[a[0]][a[1]][a[2]][a[3]][a[4]] = ans;
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
    vector<int> a;
    for(int i = 0; i < 5; i++)
    	a.push_back(0);
    cin >> b;
    memset(f,0,sizeof(f));
    for(int i = 1; i <=b ; i++) {
    	cin >> c >> k >> p;
    	unique_code[i] = c;
    	find_code[c] = i-1;
    	single_prices[i] = p;
    	a[i-1] = k;
    }
    int ans = dfs(a);
    cout << ans << endl;
    return 0;
}
