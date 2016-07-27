/*
ID: messifo2
PROG: fracdec 
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000010;
int vis[maxn];
vector<char> ans;
vector<int> v;

int main()
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
	int N,D,remain,res;
	cin >> N >> D;
	memset(vis,-1,sizeof(vis));
	res = N/D;
	remain = N % D;
	N = remain*10;
	if(res == 0) ans.push_back('0');
	else {
		while(res) {
			ans.push_back((char)(res%10+'0'));
			res /= 10;
		}
		reverse(ans.begin(),ans.end());
	}
	ans.push_back('.');
	if(remain == 0) ans.push_back('0');
	int cnt = -1;
	int start = -1;
	while(N!=0) {
//		cout << " N = " << N << endl;
//		cout << res << endl;
		res = N/D;
		remain = N%D;
		if(vis[N] != -1) {
		//	cout << " vis[" << N << "]=" << vis[N] << endl;
			start = vis[N];
			break;
		}
		if(res > 10) { 
			cout << "you are SB " << endl;
			return 0;
		}
		v.push_back(res);
		vis[N] = ++cnt;
		N = remain * 10;
	}
	for(int i = 0 ; i < v.size(); i++) {
		if(i == start) ans.push_back('(');
		ans.push_back('0'+v[i]);
	}
    if(start != -1)	ans.push_back(')');
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if(i%76 == 75) cout << endl;
	}
	if(ans.size() % 76 != 75)cout << endl;
	return 0;
}
