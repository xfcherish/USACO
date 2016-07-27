/*
ID: messifo2
PROG: frac1
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

struct one {
	int x,y;
};
bool cmp(const one & s1, const one & s2)
{
	return (s1.x * s2.y) < (s1.y * s2.x);
}
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
vector<one> v;
int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			if( gcd(i,j) == 1) {
				one tmp;
				tmp.x = j;
				tmp.y = i;
				v.push_back(tmp);
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].x << "/" << v[i].y << endl;
	}
	cout << "1/1" << endl;
	return 0;
}
