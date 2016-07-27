/*
ID: messifo2
PROG: preface
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

int a[10];
char c[10] = {'I','V','X','L','C','D','M'};
void add(int num)
{
	while(num >= 1000) {
		 num -= 1000;
		 a[6]++;
	}
	if(num >= 900) {
		num -= 900;
		a[6]++;
		a[4]++;
	}
	if(num >= 500) {
		num -= 500;
		a[5]++;
	}
	if(num >= 400) {
		num -= 400;
		a[5] ++ ;
		a[4] ++;
	}
	while(num >= 100) {
		num -= 100;
		a[4]++;
	}
	if(num >= 90) {
		num -= 90;
		a[4]++;
		a[2]++;
	}
	if(num >= 50) {
		num -= 50;
		a[3]++;
	}
	if(num >= 40){
		num -= 40;
		a[2]++;
		a[3]++;
	}
	while(num >= 10) {
		num -= 10;
		a[2]++;
	}
	if(num >= 9) {
		num -= 9;
		a[0]++;
		a[2]++;
	}
	if(num >= 5) {
		num -= 5;
		a[1] ++;
	}
	if(num == 4) {
		num = 0;
		a[0]++;
		a[1]++;
	}
	if(num < 4) {
		a[0] += num;
	}
}
int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int n;
	cin >> n;
	memset(a,0,sizeof(a));
	for(int i = 1 ; i <= n; i++) {
		add(i);
	}
	for(int i = 0; i <= 6; i++) {
		if(a[i] != 0) {
			cout << c[i] << " " << a[i] << endl;
		}
	}
	return 0;
}
