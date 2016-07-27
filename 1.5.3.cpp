/*
ID: messifo2
PROG: sprime
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

const int maxn = 1005;

vector<int> v;
bool judge(int num)
{
	if(num <2) return false;
	for(int i = 2; i*i <= num ; i++)
		if( num % i == 0) return false;
	return true;
}
int n;
void dfs(int dep, int num)
{
	if(judge(num) == false) return;
	if(dep == n) {
		v.push_back(num);
		return;
	}
	for(int i = 1; i <= 9 ; i+=2) {
		dfs(dep+1,num*10+i);
	}
}
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	cin >> n;
	for(int i = 2; i <= 7;i++)
		if(judge(i)) dfs(1,i);
	sort(v.begin(),v.end());
	for(int i = 0; i < v.size(); i++) {
		printf("%d\n",v[i]);
	}
	return 0;
}
