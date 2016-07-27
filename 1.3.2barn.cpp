/*
ID: messifo2
PROG: barn1
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct one{
	bool tag;
	int val;
};
bool cmp(const one & s1, const one & s2)
{
	return s1.val > s2.val ;
}
int main()
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int m,s,c,i;
	cin >> m >> s  >> c;
	int a[205];
	for(i=1;i<=c;i++)
		cin >> a[i];
	sort(a+1,a+1+c);
	vector<one> v;
	int total = a[c] - a[1] ;
	for(i=1;i<c;i++){
		one tmp;
		tmp.tag = true;
		tmp.val = a[i+1]-a[i];
		v.push_back(tmp);
	}
	int num = 1;
	while(m > num ) {
		int maxval = 0;
		int maxpos = -1;
		for(i=0;i<v.size();i++){
			if(v[i].tag){
				if(maxval <  v[i].val) {
					maxval = v[i].val;
					maxpos = i;
				}
			}
		}
		if(maxpos == -1) break;
		else {
			v[maxpos].tag = false;
			total -= v[maxpos].val;
			num ++;
		}
	}
	cout << total+num << endl;
	return 0;
}
