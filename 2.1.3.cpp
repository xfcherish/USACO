/*
ID: messifo2
PROG: sort3
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int a[maxn];
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
	int n,i,j;
	cin >> n;
	for(i=1;i<=n;i++) cin >> a[i];
	int total = 0;
	int num1 = 0, num2=0, num3=0;
	for(i=1;i<=n;i++) {
		if(a[i] == 1) num1++;
		else if(a[i] == 2) num2++;
		else num3++;
	}
	for(i=1;i<=num1;i++) {
		if(a[i] == 2) {
			bool tag = true;
			for(j=num1+1; j<=num1+num2; j++) {
				if(a[j] == 1) {
					total ++ ;
					a[j] = 2;
					a[i] = 1;
					tag = false;
					break;
				}
			}
			if(tag) {
				for( ; j <=n; j++) {
					if(a[j] == 1) {
						total ++;
						a[j] = 2;
						a[i] = 1;
					}
				}
			}
		}
		else if(a[i] == 3) {
			bool tag = true;
			for(j = num1+num2+1; j<=n; j++) {
				if(a[j] == 1) {
					total ++ ;
					a[j] = 3;
					a[i] = 1;
					tag = false;
					break;
				}
			}
			if(tag) {
				for(j=num1+1; j<=num1+num2; j++) {
					if(a[j] == 1) {
						total ++;
						a[j] = 3;
						a[i] = 1;
						break;
					}
				}
			}
		}
	}
	for(i=num1+1; i <= num1+num2; i++) 
		if(a[i]==3) total++;
	cout << total << endl;
	return 0;
}
