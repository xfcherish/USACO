/*
D: messifo2
PROG: namenum
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int tran[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0 };
bool equal(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2) return false;
	for(int i = 0 ; i < len1 ; i++ ) {
		if( tran[s1[i]-'A'] != ( s2[i]-'0') )
			return false;
	}
	return true;
}
int main()
{
	 ifstream fin ("dict.txt");
	 vector<string> dict;
	 int i,j,n;
	 string s;
	 while(fin >> s ) {
		dict.push_back(s);
	 }
//	 cout << "dict.size() = " << dict.size() << endl;
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	 string input;
	 cin >> input;
//	 cout << "input = " << input << endl;
	 bool none = 1;
	 for(i = 0 ; i < dict.size(); i++) {
		if(equal(dict[i], input)) {
			cout << dict[i] << endl;
			none = 0;
		}
	 }
	 if(none) cout << "NONE" << endl;	 
	 return 0;
}

