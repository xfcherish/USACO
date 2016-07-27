/*
ID: messifo2
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct one{
    int start,end;
};
vector<one> milk;
vector<one> ans;
bool cmp(const one & s1, const one & s2 )
{
    if(s1.start != s2.start)
        return (s1.start < s2.start) ;
    else
        return (s1.end < s2.end) ;
}
int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n,i;
    one tmp;
    cin >> n;
    for(i = 0; i < n; i++ ) {
        cin >> tmp.start >> tmp.end ;
        milk.push_back(tmp);
    }
    sort(milk.begin(), milk.end(), cmp) ;
    tmp.start = milk[0].start;
	tmp.end = milk[0].end;
    for(i = 1 ; i < n; i++ ) {
        if(tmp.end >= milk[i].start )
			tmp.end = max( milk[i].end , tmp.end) ; 
		else {
			ans.push_back(tmp) ;
			tmp.start = milk[i].start;
			tmp.end = milk[i].end;
		}
    }
	ans.push_back(tmp) ;
	int max_milk = 0;
	int max_interval = 0;
//	for(int i = 0; i < ans.size () ; i++ ) {
//		cout << "ans" << i << " start = " << ans[i].start << " "
//			<< "end = " << ans[i].end << endl;
//	}
	for(int i = 0 ; i < ans.size(); i++ ) {
		max_milk = max(max_milk, ans[i].end - ans[i].start) ;
		if(i != ans.size() - 1 )
			max_interval = max(max_interval, ans[i+1].start - ans[i].end);
	}
	cout << max_milk << " " << max_interval << endl;
    return 0;

}
