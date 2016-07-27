/*
ID: messifo2
PROG: milk3
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int vis[20];
int v[20][20][20];
int A,B,C;

void dfs(int a,int b,int c)
{

	if(v[a][b][c]) return;
	v[a][b][c] = 1;
//	cout << "a ="<< a<<" b="<<b<< " c="<<c<<endl;
	if(a == 0) vis[c] = 1;
	
	if(b+c > B) dfs(a,B,b+c-B);
	else dfs(a,b+c,0);
	
	if(c+a > A) dfs(A,b,a+c-A);
	else dfs(a+c,b,0);

	if(b+a > A) dfs(A,a+b-A,c);
	else dfs(a+b,0,c);

	if(b+c > C) dfs(a,b+c-C,C);
	else dfs(a,0,b+c);

	if(a+b > B) dfs(a+b-B,B,c);
	else dfs(0,a+b,c);

	if(a+c > C) dfs(a+c-C,b,C);
	else dfs(0,b,a+c);
}
int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	cin >> A >> B >> C;
	memset(v,0,sizeof(v));
	memset(vis,0,sizeof(vis));
	dfs(0,0,C);
	for(int i = 0; i < C; i++ ) { 
//		cout << "vis["<<i<<"]="<<vis[i] << endl;
		if(vis[i]) cout<<i<<" ";
	}
	cout << C << endl;
	return 0;
}
