/*
ID: messifo2
PROG: msquare
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

set<string> visit;
struct node {
	string s;
	string path;
	int cnt;
	/* data */
};
string start,aim;
int ans;
string ans_path;

string tran(string str,int type) {
	string new_str = str;
	if(type == 1) {
		for(int i=0, j = 7; i < j; i++,j--) {
			new_str[i] = str[j];
			new_str[j] = str[i];
		}
	}
	else if(type == 2) {
		new_str[0] = str[3];
		new_str[7] = str[4];
		for(int i = 1; i <= 3; i++) {
			new_str[i] = str[i-1];
			new_str[3+i] = str[(3+i)+1];
		}
	}
	else if(type == 3) {
		new_str[1] = str[6];
		new_str[2] = str[1];
		new_str[5] = str[2];
		new_str[6] = str[5];
	}
	return new_str;
}

void bfs()
{
	node cur;
	cur.s = start;
	cur.cnt = 0;
	cur.path = "";

	visit.clear();

	queue<node> q;
	q.push(cur);
	visit.insert(cur.s);

	while(!q.empty()) {
		cur = q.front();
		q.pop();
		// reach the goal
		// cout << "cur string = " << cur.s <<  endl;
		if(cur.s == aim) {
			// cout << "hehe" << endl;
			ans = cur.cnt;
			ans_path = cur.path;
			return;
		}
		// insert node 
		node state;
		state.cnt = cur.cnt + 1;
		for(int i = 1; i <= 3; i++) {
			string new_s = tran(cur.s,i);
			// cout << "new_s = " << new_s << endl;
			if(visit.find(new_s) == visit.end()) {
				state.s = new_s;
				state.path = cur.path + (char)('A'+i-1);
				q.push(state);
				visit.insert(new_s);
			}
		}
	}
}

int main()
{
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    int num;
    start = "12345678";
    for(int i = 1; i <= 8; i++) {
    	cin >> num;
    	aim += (char)(num+'0');
    }
    // cout << "aim  = " << aim << endl;
    bfs();
    cout << ans << endl;
    cout << ans_path << endl;
    return 0;
}
