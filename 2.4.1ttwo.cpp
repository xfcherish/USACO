/*
ID: messifo2
PROG: ttwo
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

char c[20][20];
int farmx,farmy,cowx,cowy,ans,dirf,dirc;

bool judge(int i,int j)
{
	if(i<1 || j < 1 || i>10 || j>10) return false;
	if(c[i][j] == '*') return false;
	return true;
}
void move1()
{
	int nextx,nexty;
	if(dirf == 0) {
		nextx = farmx - 1;
		nexty = farmy ;
	}
	else if(dirf == 1) {
		nextx = farmx;
		nexty = farmy + 1;
	}
	else if(dirf == 2){
		nextx = farmx + 1;
		nexty = farmy;
	}
	else if(dirf == 3){
		nextx = farmx;
		nexty = farmy - 1;
	}
	if(judge(nextx,nexty)) {
		farmx = nextx;
		farmy = nexty;
	}
	else {
		dirf = (dirf+1) % 4;
	}
}
void move2()
{
	int nextx,nexty;
	if(dirc == 0) {
		nextx = cowx - 1;
		nexty = cowy ;
	}
	else if(dirc == 1) {
		nextx = cowx;
		nexty = cowy + 1;
	}
	else if(dirc == 2){
		nextx = cowx + 1;
		nexty = cowy;
	}
	else if(dirc == 3){
		nextx = cowx;
		nexty = cowy - 1;
	}
	if(judge(nextx,nexty)) {
		cowx = nextx;
		cowy = nexty;
	}
	else {
		dirc = (dirc+1) % 4;
	}
}

int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	int i,j;
	for(i=1; i<=10; i++) {
		for(j=1; j<=10; j++) {
			scanf("%c",&c[i][j]);
			if(c[i][j] == 'F') {
				farmx = i;
				farmy = j;
			}
			else if(c[i][j] == 'C') {
				cowx = i;
				cowy = j;
			}
		}
		scanf("\n");
	}
//	cout << " farmx = " << farmx << " farmy = " << farmy << endl;
//	cout << " cowx = " << cowx << " cowy = " << cowy << endl;
	ans = 0;
	dirf = dirc = 0;
	while(1) {
		move1();
		move2();
		ans ++ ; 
		if(ans > 1000) {
			cout << 0 << endl;
			return 0;
		}
		if(farmx == cowx && farmy == cowy) 
			break;
	}
	cout << ans << endl;
	return 0;
}
