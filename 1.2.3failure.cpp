/*
D: messifo2
PROG:
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int tran[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0 };
bool equal(string s1, string s2)
{
	if( s1 == "GREG" ) {
		cout << s2.length()  << endl;
		cout << s1.length() << endl;
		cout << "what the fuck " << endl;
	}
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2) return false;
	for(int i = 0 ; i < len1 ; i++ ) {
		if( s1 == "GREG" ) {
			cout << "i = " << i << endl;
			cout << tran[s1[i] - 'A'] << endl;
			cout << (s2[i] - '0') << endl;
		}
		if( tran[s1[i]-'A'] != ( s2[i]-'0') )
			return false;
	}
	return true;
}
int main()
{
	 freopen("dict.txt","r",stdin);
	 vector<string> dict;
	 int i,j,n;
	 string s;
	 while(cin >> s ) {
		dict.push_back(s);
	 }
	 cout << "dict.size() = " << dict.size() << endl;
	 freopen("namenum.in","r",stdin);
	// freopen("namenum.out","w",stdout);
	 string input;
	 while( cin >> input)
		 cout << "input = " << input << endl;
	 for(i = 0 ; i < dict.size(); i++) {
		if(equal(dict[i], input)) {
			cout << dict[i] << endl;
		}
	 }
	 return 0;
}

