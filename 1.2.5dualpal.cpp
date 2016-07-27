/*
ID: messifo2
PROG: dualpal
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool isPal(int num, int base)
{
	string s;
	while(num != 0 ){
		s+= (char) ( num%base + '0');
		num /= base;
	}
	for(int i = 0, j = s.length()-1; i<=j; i++,j-- ) {
		if(s[i] != s[j] ) 
			return false;
	}
	return true;
}
bool judge(int num)
{
	int cnt = 0;
	for(int base = 2; base <= 10; base++ ) {
		if(isPal(num,base))
			cnt ++ ;
		if(cnt >=2) return true;
	}
	return false;
}
int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s,i;
	cin >> n >> s;
	int count = 0;
	for(i = s+1 ; count < n; i++ ) {
		if(judge(i)) {
			cout << i << endl;
			count++;
		}
	}
	return 0;
}
