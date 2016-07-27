/*
ID: messifo2
PROG: hamming
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int B;
int dist(int a, int b)
{
	string s1,s2;
	while(a!=0) {
		s1 += (char)( '0'+a%2);
		a /= 2;
	}
	while(b!=0) {
		s2 += (char)('0' + b%2);
		b /= 2;
	}
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	while(s1.length() < B) s1 = '0' + s1;
	while(s2.length() < B) s2 = '0' + s2;
//	cout << "s1=" << s1 << endl;
//	cout << "s2=" << s2 << endl;
	int ans = 0;
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] != s2[i])
			ans++;
	}
	return ans;
}

int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	int n,d;
	cin >> n >> B >> d;
	int cnt = 1;
	vector<int> v;
	v.push_back(0);
	for(int i = 1; cnt < n ; i++ ) {
		bool tag = true;
		for(int j = 0; j < v.size(); j++) {
			if(dist(i,v[j]) < d) {
				tag = false;
				break;
			}
		}
		if(tag) {
			v.push_back(i);
			cnt ++;
		}
	}
	for(int i = 0 ; i < v.size() -1  ; i++) {
		if(i % 10 == 9) 
			cout << v[i] << endl;
		else cout << v[i] << " ";
	}
	cout << v[cnt-1] <<  endl;
	return 0;
}
