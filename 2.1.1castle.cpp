/*
ID: messifo2
PROG: castle
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

const int maxn = 55;

int n,m,maxsize;
int a[maxn][maxn];
struct one{
	int w[4];
};
one wall[maxn][maxn];
bool vis[maxn][maxn];

one tran(int num)
{
	one tmp;
	for(int i = 0; i < 4; i++) {
		tmp.w[i] = num % 2;
		num /= 2;
	}
	return tmp;
}
int floodfill(int i,int j)
{
	 if( i < 1 || i > n) return 0;
	 if( j < 1 || j > m) return 0;
	 if( vis[i][j] == 1) return 0;
//	 cout << " flood fill i = " <<i << " j="<<j<<endl; 
//	 for(int k = 0 ; k < 4; k++)
//		 cout << wall[i][j].w[k] << " ";
//	 cout << endl;
	 vis[i][j] = 1;
	 int ans = 1;
     if(wall[i][j].w[0] == 0)
		 ans += floodfill(i,j-1);
	 if(wall[i][j].w[1] == 0) 
		 ans += floodfill(i-1,j);
	 if(wall[i][j].w[2] == 0)
		 ans += floodfill(i,j+1);
	 if(wall[i][j].w[3] == 0)
		 ans += floodfill(i+1,j);
	 return ans;
}
int search()
{
	int ans = 0;
    maxsize = 0;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=m; j++) {
			if(vis[i][j] == 0) {
				int tmp = floodfill(i,j);
//				cout << "i="<<i<< " j="<<j << endl;
//				cout <<" tmp = " << tmp << endl;
				maxsize = max(maxsize,tmp);
				ans ++ ;
			}
		}
	}
	return ans;
}
void change(int i,int j,int k,int val)
{
	wall[i][j].w[k] = val;
	if( k == 0) 
		wall[i][j-1].w[2] = val;
	else if( k == 1) 
		wall[i-1][j].w[3] = val;
	else if( k == 2)
		wall[i][j+1].w[0] = val;
	else if( k == 3)
		wall[i+1][j].w[1] = val;
}
int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	cin >> m >> n;
	for(int i = 1 ; i<=n; i++) {
		for(int j = 1 ; j<=m; j++) {
			cin >> a[i][j];
//			cout << " i=" << i << " j="<<j << endl;
			wall[i][j] = tran(a[i][j]);
		}
	}
	memset(vis,0,sizeof(vis));
	int ans = search();
	cout << ans << endl;
	cout << maxsize << endl;
	int maxroom = maxsize;
	int tagi,tagj;
	char tag;
	for(int j = 1; j <=m; j++) {
		for(int i =n ; i>=1; i--){
			for(int kk = 0; kk<4; kk++) {
				int ada[4] = {0,3,1,2} ;
				int k = ada[kk];
				if( wall[i][j].w[k] == 1) {
					change(i,j,k,0);
					memset(vis,0,sizeof(vis));
					search();
//					cout << " i="<<i<<" j="<<j<< "dir="
//						<<k<<" maxsize="<<maxsize<<endl;
					if(maxroom < maxsize) {
						maxroom = maxsize;
						tagi = i;
						tagj = j;
						if(k == 0) tag = 'W';
						else if(k == 1) tag = 'N';
						else if(k == 2) tag = 'E';
						else if(k == 3) tag = 'S';
					}
					change(i,j,k,1);
				}
			}
		}
	}
	cout << maxroom << endl;
	cout << tagi << " " << tagj << " "<< tag << endl;
	return 0;
}
