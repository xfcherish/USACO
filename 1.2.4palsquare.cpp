/*
ID: messifo2
PROG: palsquare
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string tran(int num, int base) 
{
	string s = "";
	while( num !=0 ) {
		int tmp = num % base;
		num /= base;
		if(tmp <= 9) s += (char) ( tmp+'0');
		else s += (char) (tmp - 10 + 'A') ;
	}
	reverse(s.begin(), s.end());
	return s;
}
bool judge(int num, int base ) 
{
	string s = tran( num , base) ;
	int i = 0;
	int j = s.length() - 1;
	for( ; i<=j; i++,j-- ) {
		if( s[i] != s[j] )
			return false;
	}
	return true;
}
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=300 ; i++ ) {
		if(judge( i*i, n )) 
			cout << tran(i,n) << " " << tran(i*i, n ) << endl;
	}
}
 
