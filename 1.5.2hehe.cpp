/*
ID: messifo2
PROG: pprime
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

const int maxn = 1005;

vector<int> v;
bool judge(int num)
{
	if(num < 2 || num % 2 == 0) return false;
	for(int i=2; i*i <= num; i++)
		if(num % i ==0) return false;
	return true;
}
string num2s(int num)
{
	string s;
	while(num!=0) {
		s += (char)(num%10 + '0');
		num /= 10;
	}
	return s;
}
int gao(int num)
{
	string s = num2s(num);
	int ans = num;
	for(int i = 1; i < s.length(); i++ ){
		ans *= 10;
		ans += (s[i]-'0');
	}
//	cout << "num = " << num << endl;
//	cout << "ans = " << ans << endl;
	return ans;
}
void generate(int num,int cur, int dep)
{
	if(cur*2 == dep+1) {
	//	cout << "dep = " << dep << endl;
		num = gao(num);
		if(judge(num)) 
			v.push_back(num);
		return ;
	}
	if(cur*2 > dep) return ;
	for(int i = 0; i <=9; i++) {
		int tmp  = num*10 + i;
		generate(tmp,cur+1,dep);
	}
}
void solve(int dep)
{
	for(int i = 1; i<=9; i++) {
		generate(i,1,dep);	
	}
}
int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	int i,a,b;
	cin >> a >> b;
	for(i=3;i<=11;i++){
		if(judge(i))
			v.push_back(i);
	}
	for(int i = 3; i<=9; i+=2)
		solve(i);
	sort(v.begin(),v.end());
	i = 0;
	while(v[i] < a && i < v.size()) i++;
	for( ; i<v.size(); i++) {
		if(v[i] >b) break;
		printf("%d\n",v[i]);
	}
	return 0;
}

