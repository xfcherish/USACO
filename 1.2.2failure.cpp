 /*
ID: messifo2
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 15;
//char a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int n;

bool judge1(char** a, char** b ) 
{
	for(int i = 0 ; i < n ; i++ ) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != b[j][n-1-i]) 
				return false;
		}
	}
	return true;
}


bool judge2(char **a, char **b ) 
{
	for(int i = 0 ; i < n ; i++ ) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != b[n-1-i][n-1-j]) 
				return false;
		}
	}
	return true;
}

bool judge3(char** a, char** b ) 
{
	for(int i = 0 ; i < n ; i++ ) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != b[n-1-j][i]) 
				return false;
		}
	}
	return true;
}

bool isSame(char** a, char** b) 
{
	for(int i = 0; i < n; i++ ) {
		for(int j = 0; j < n; j++ ) {
			if(a[i][j] != b[i][j])
				return false;
		}
	}
	return true;
}
int main()
{
    freopen("transform.in","r",stdin);
	//freopen("transfrom.out","w",stdout);
	int i,j;
	cin >> n;
	char a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(i = 0 ; i < n; i++) {
		scanf("\n");
		for(j = 0; j < n; j++ ) {
			scanf("%c",&a[i][j]);
		}
	}
	for(i = 0 ; i < n; i++) {
		scanf("\n");
		for(j = 0; j < n; j++ ) {
			scanf("%c",&b[i][j]);
		}
	}
	for(i = 0 ; i < n; i++) {
		for(j = 0; j < n; j++ ) {
			c[i][j] = a[i][n-j];
		}
	}
	if(judge1(a,b)) cout << "1" << endl;
	else if(judge2(a,b)) cout << "2" << endl;
	else if(judge3(a,b)) cout << "3" << endl;
	else if(isSame(a,c)) cout << "4" << endl;
	else if(isSame(a,b)) cout << "6" << endl;
	else if( judge1(a,c) || judge2(a,c) || judge3(a,c) )
		cout << "5" << endl;
	else cout << "7" << endl;
	return 0;
}

