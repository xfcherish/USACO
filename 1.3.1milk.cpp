/*
ID: messifo2
PROG: milk
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5005;
struct one {
	int price,num;
};

bool cmp(const one & s1, const one & s2)
{
	if(s1.price != s2.price )
		return s1.price < s2.price;
	else return s1.num < s2.num;
}
one a[maxn];
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m,i;
	cin >> n >> m;
	for(i = 1; i <= m ; i++) {
		cin >> a[i].price >> a[i].num;
	}
	sort(a+1,a+1+m,cmp);
	int total = 0;
	for(i = 1; i <=m && n > 0 ; i++) {
		if(n >= a[i].num ) {
			n -= a[i].num;
			total += ( a[i].num * a[i].price);
		}
		else{
		//	n = 0;
			total += n * a[i].price;
			n = 0;
			break;
		}
	}
	cout << total << endl;
	return 0;
}
