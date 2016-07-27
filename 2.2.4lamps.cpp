/*
ID: messifo2
PROG: lamps
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

int n,c,a[4];
vector<int> on_lamps;
vector<int> off_lamps;
vector<string> ans;

bool judge()
{
	int sum = 0;
	for(int i = 0; i < 4; i++)
		sum += a[i];
	if(sum > c) return false;
	int dif = (sum > c ? sum-c : c-sum);
	if(dif % 2 == 1) return false;
	for(int i = 0 ; i < on_lamps.size(); i++) {
		int tmp = on_lamps[i];
		int cnt = a[0];
		if(tmp % 2) cnt += a[1];
		else cnt += a[2];
		if(tmp % 3 == 1) cnt += a[3];
		if(cnt % 2 !=0) return false;
	}
	for(int i = 0 ; i < off_lamps.size(); i++) {
		int tmp = off_lamps[i];
		int cnt = a[0];
		if(tmp % 2) cnt += a[1];
		else cnt += a[2];
		if(tmp % 3 == 1) cnt += a[3];
		if(cnt % 2 == 0 ) return false;
	}
	return true;
}
int main()
{
	freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
	cin >> n;
	cin >> c;
	int tmp;
	while(cin >> tmp && tmp != -1) {
		on_lamps.push_back(tmp);
	}
	while(cin >> tmp && tmp != -1) {
		off_lamps.push_back(tmp);
	}
	for(a[0] = 0; a[0] <=1; a[0]++)
	for(a[1] = 0; a[1] <=1; a[1]++)
	for(a[2] = 0; a[2] <=1; a[2]++)
	for(a[3] = 0; a[3] <=1; a[3]++) {
		if(judge()) {
			string s;
			for(int i = 0 ; i < n; i++)
				s += '1';
			if(a[0]) for(int i = 0; i < n; i++)
				s[i] = ('1' + '0' - s[i]); 
			if(a[1]) for(int i = 0; i < n; i+=2)
				s[i] = ('1' + '0' - s[i]) ;
			if(a[2]) for(int i = 1; i < n; i+=2)
				s[i] = ('1' + '0' - s[i]) ;
			if(a[3]) for(int i = 0; i < n; i+=3)
				s[i] = ('1' + '0' - s[i]) ;
			ans.push_back(s);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i = 0 ; i < ans.size(); i++)
		cout << ans[i] << endl;
	if(ans.size() == 0 )
		cout << "IMPOSSIBLE" << endl;
	return 0;
}
