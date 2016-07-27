/*
ID: messifo2
PROG: contact
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	string s;
	int fre;
	/* data */
};

map<string,int> M;
vector<Node> v;

bool cmp(const Node & s1 , const Node & s2) {
	if(s1.fre != s2.fre) 
		return (s1.fre > s2.fre) ;
	else{
		if(s1.s.length() != s2.s.length())
			return s1.s.length() < s2.s.length();
		else 
			return s1.s < s2.s;
	}
}

int main()
{
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    int i,j,a,b,n;
	string str,seq;
	str = "";
	cin >> a >> b >> n;
	while(cin >> seq) {
		str += seq;
	}
	int len = str.length();
	for(i = 0; i < len ; i++) {
		string tmp = ""; 
		for(j = i ; j <= i+b-1 && j < len ; j++) {
			tmp += str[j];
			if(tmp.length() >= a){
				M[tmp] ++;
			}
		}
	}
	map<string,int>::iterator it = M.begin();
	for(it = M.begin(); it != M.end(); it++ ) {
		Node cur;
		cur.s = it->first;
		cur.fre = it->second;
		v.push_back(cur);
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 0;
	vector<string> res;
	for(i = 0; i < v.size(); i++) {
		cnt++;
		if(cnt > n) 
			break;
		cout << v[i].fre << endl;
		res.clear();
		for(j = i ; j < v.size() ; j++) {
			if(v[j].fre == v[i].fre)
				res.push_back(v[j].s);
			else break;
		}
		i = j-1;
		for(j = 0; j < res.size(); j++) {
			if( j == res.size()-1 || ( j % 6 == 5))
				cout << res[j] << endl;
			else cout << res[j] << " ";
		}
	}
    return 0;
}
