/*
ID: messifo2
PROG: lgame
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

typedef pair<string,string> PSS;

const int maxn = 100;

vector<string> dict;
vector<int> scores;
vector<int> len;
vector<PSS> words;
string origi;
int cnt1[26],cnt2[26];

int tran[26] = { 2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,
				4,6,6,7,5,7} ;

int cal(string s) {
	int ret = 0;
	for(int i = 0; i < s.length(); i++)
		ret += tran[(int)(s[i]-'a')];
	return ret;
}

bool judge(int num1, int num2) {
	for(int i = 0; i < 26; i++)
		cnt2[i] = cnt1[i];
	bool tag = true;
	for(int i = 0; i < dict[num1].length(); i++) {
		cnt2[(int)(dict[num1][i]-'a')]--;
		if(cnt2[(int)(dict[num1][i]-'a')] < 0) 
			return false;
	}
	for(int i = 0; i < dict[num2].length(); i++) {
		cnt2[(int)(dict[num2][i]-'a')]--;
		if(cnt2[(int)(dict[num2][i]-'a')] < 0) 
			return false;
	}
	return true;
}

bool cmp(const PSS s1, const PSS s2) {
	if(s1.first != s2.first)
		return (s1.first < s2.first);
	return (s1.second < s2.second);
}

int main()
{
    freopen("lgame.in","r",stdin);
    freopen("lgame.out","w",stdout);
    ifstream fin("lgame.dict");
    cin >> origi;
    string tmp;
    int highest = 0;
    memset(cnt1, 0, sizeof(cnt1));
	for(int i = 0; i < origi.length(); i++)
		cnt1[(int)(origi[i]-'a')]++;

    while(fin >> tmp && tmp != "." ) {
    	for(int i = 0; i < 26; i++)
    		cnt2[i] = cnt1[i];
    	bool tag = true;
    	for(int i = 0; i < tmp.length(); i++) {
    		cnt2[(int)(tmp[i]-'a')]--;
    		if(cnt2[(int)(tmp[i]-'a')] < 0) {
    			tag = false;
    			break;
    		}
    	}
    	if(tag == false) continue;
    	dict.push_back(tmp);
    	int val = cal(tmp);
    	scores.push_back(val);
    	len.push_back(tmp.length());
    	highest = max(highest,val);
    }
    for(int i = 0; i < dict.size(); i++) {
    	for(int j = 0; j < dict.size(); j++) {
    		if(judge(i,j))
    			highest = max(highest, scores[i]+scores[j]);
    	}
    }
    for(int i = 0; i < dict.size(); i++) 
    	if(scores[i] == highest)
    		words.push_back(PSS(dict[i],""));
    for(int i = 0; i < dict.size(); i++) {
    	for(int j = i; j < dict.size(); j++) {
    		if(judge(i,j) && scores[i]+scores[j] == highest) {
    			if(dict[i] < dict[j]) 
    				words.push_back(PSS(dict[i],dict[j]));
    			else words.push_back(PSS(dict[j],dict[i]));
    		}
    	}
    }
    sort(words.begin(), words.end(), cmp);
    words.erase( unique( words.begin(), words.end() ), words.end() );
    cout << highest << endl;
    for(int i = 0 ; i < words.size(); i++) {
    	if(words[i].second == "")
    		cout << words[i].first << endl;
    	else 
    		cout << words[i].first << " " << words[i].second << endl;
    }
    return 0;
}
