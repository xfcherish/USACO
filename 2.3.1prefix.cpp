/*
ID: messifo2
PROG: prefix
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

#define pb push_back 

const int maxn = 200100;
int dp[maxn];
vector<string> v;
string s;

bool judge(int i,int j)
{
	string s1 = v[j];
	int len1 = s.length();
	int len2 = v[j].length();
	int p,q;
	for(p=i, q = 0; p < len1 && q < len2; p++,q++) {
		if( s[p] != s1[q]) return false;
	}
	if(q == len2) return true;
	else return false;
}
int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	string tmp;
	while(cin >> tmp && tmp != ".") { 
		v.pb(tmp);
	}
	string s1;
	while(cin >> s1) 
		s += s1;
	int len1 = s.length();
	int len2 = v.size();
	for(int i = len1-1; i>=0; i--) {
		for(int j = 0; j<len2; j++) {
			if(judge(i,j)) {
				int len3 = v[j].length();
				dp[i] = max(dp[i], dp[i+len3]+len3);
			}
		}
	}
	cout << dp[0] << endl;
	return 0;
}
