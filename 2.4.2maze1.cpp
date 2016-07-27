/*
ID: messifo2
PROG: maze1
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 250;
const int INF = 10000000;
char wall[maxn][maxn];
int f[maxn][maxn];
bool vis[maxn][maxn];
int H,W,final_ans;

struct one{
	int first,second,value;
};

one temp(int x, int y, int value) {
	one res;
	res.first = x;
	res.second = y;
	res.value = value;
	return res;
}

void solve(int i, int j)
{
	queue<one> que;
	one t;
	que.push(temp(i,j,1));
	while(!que.empty()) {
		t = que.front();
		que.pop();
		int ii = t.first;
		int jj = t.second;
	//	cout << "ii= " << ii << " jj = " << jj << endl;
		int x = 2*ii-1;
		int y = 2*jj-1;
		int v = t.value + 1;
		if(f[ii][jj] != -1) {
			f[ii][jj] = min(f[ii][jj],t.value);
		}
		else f[ii][jj] = t.value;
		if(wall[x-1][y] ==' ' && !vis[ii-1][jj] && ii-1 >= 1) {
			que.push(temp(ii-1,jj,v));
			vis[ii-1][jj] = true;
		}
		if(wall[x+1][y] ==' ' && !vis[ii+1][jj] && ii+1 <= H) {
			que.push(temp(ii+1,jj,v));
			vis[ii+1][jj] = true;
		}
		if(wall[x][y-1] ==' ' && !vis[ii][jj-1] && jj-1 >= 1) {
			que.push(temp(ii,jj-1,v));
			vis[ii][jj-1] = true;
		}
		if(wall[x][y+1] ==' ' && !vis[ii][jj+1] && jj+1 <= W){
			que.push(temp(ii,jj+1,v));
			vis[ii][jj+1] = true;
		}
	}
}
void search(int i, int j)
{
	int x = 2*i-1;
	int y = 2*j-1;
//	cout << "i=" << i<<" j =" << j << endl;
	if(i == 1) if(wall[x-1][y] == ' ') {
	//	cout << "hehe i = " << i << " j = " << j << endl;
		memset(vis,false,sizeof(vis));
		solve(i,j);
	}
	if(i == H) if(wall[x+1][y] == ' ') {
	//	cout << "hehe i = " << i << " j = " << j << endl;
		memset(vis,false,sizeof(vis));
		solve(i,j);
	}
	if(j == 1) if(wall[x][y-1] == ' ') {
	//	cout << "hehe i = " << i << " j = " << j << endl;
		memset(vis,false,sizeof(vis));
		solve(i,j);
	}
	if(j == W) if(wall[x][y+1] == ' ') {
	//	cout << "hehe i = " << i << " j = " << j << endl;
		memset(vis,false,sizeof(vis));
		solve(i,j);
	}
}
int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	int i,j;
	cin >> W >> H;
	for(i=0; i<2*H+1; i++) {
	//	scanf("\n");
		getchar();
		for(j=0; j<2*W+1; j++) {
			scanf("%c",&wall[i][j]);
		}
	//	scanf("\n");
	}
	final_ans = 0;
	memset(f,-1,sizeof(f));
	memset(vis,false,sizeof(vis));
	for(i = 1, j = 1; j <= W; j++) search(i,j);
	for(j--; i <= H; i++ ) search(i,j);
	for(i--; j >= 1; j-- ) search(i,j);
	for(j++; i >= 1; i--) search(i,j);
	for(i=1; i<=H; i++) {
		for(j=1; j<=W; j++) {
			//cout << "f[" << i << "][" << j << "]=" << f[i][j] << endl;
			final_ans = max(final_ans,f[i][j]);
		}
	}
	cout << final_ans << endl;
	return 0;
}
