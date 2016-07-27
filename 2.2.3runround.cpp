/*
ID: messifo2
PROG: runround
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

string tran(int num)
{
	string s;
	while(num!=0) {
		s += (char)( '0' + num%10);
		num /= 10;
	}
	reverse(s.begin(),s.end());
	return s;
}
bool judge(int num)
{
	string s = tran(num);
	int len = s.length();
	bool vis[10] = {0};
	for(int i = 0; i < len; i++ ) {
		int tmp = s[i] - '0';
		if(tmp == 0) return false;
		if(vis[tmp] == 0) vis[tmp] = 1;
		else return false;
	}
	memset(vis,0,sizeof(vis));
	int start = s[0] - '0';
	int cur = start;
	int next = 0;
	while(1) {
		next = (cur + next) % len;
		cur = next;
		next = s[cur] - '0';
		if(vis[next] == 0) vis[next] = 1;
		else return false;
		if(next == start) {
			vis[next] = 1;
			break;
		}
	}
	for(int i = 0 ; i < len; i++) {
		int tmp = s[i] - '0';
		if(vis[tmp] == 0) return false;
	}
	return true;
}
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	int n;
	cin >> n;
	for(int i = n+1; ; i++) {
		if(judge(i)) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
