/*
ID: messifo2
PROG: zerosum
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

int n;
vector<string> ans;
int a[10];
bool judge()
{
	int res = 0;
	vector<int> num;
	vector<int> op;
	int tmp = 0;
	for(int i =1; i< n; i++) {
		tmp *= 10;
		tmp += i;
		if(a[i] !=2) {
			num.push_back(tmp);
			op.push_back(a[i]);
			tmp = 0;
		}
	}
	tmp *= 10;
	tmp += n;
	num.push_back(tmp);
	res += num[0];
	for(int i = 1; i < num.size(); i++) {
		if(op[i-1] == 0) res += num[i];
		else if(op[i-1] == 1) res -= num[i];
	}
	if(res == 0) return true;
	else return false;
}
void dfs(int dep)
{
	if(dep == n) {
	//	for(int i = 1; i<dep; i++)
	//		cout << a[i];
	//	cout << endl;
		if(judge()){
		   string s;
		   for(int i = 1; i<dep; i++) { 
			   if(a[i] == 0) s += '+';
			   else if(a[i]==1) s += '-';
			   else s += ' ';
		   }
		   ans.push_back(s);
		}
		return ;
	}
	for(int i= 0; i <=2 ; i++) {
		a[dep] = i;
		dfs(dep+1);
	}
}
int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	cin >> n;
	memset(a,0,sizeof(a));
	dfs(1);
	sort(ans.begin(),ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << 1;
		for(int j = 0; j < ans[i].length();j++) {
			cout << ans[i][j]  << j+2;
		}
		cout << endl;
	}
	return 0;
}
