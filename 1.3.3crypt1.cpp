/*
ID: messifo2
PROG: crypt1
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n,num[12];
int ans;
bool digit_judge(int cnt)
{
	while(cnt != 0) {
		int tmp = cnt % 10;
		bool tag = false;
		for(int i = 1 ; i<= n; i++){
			if(tmp == num[i])
				tag = true;
		}
		if(tag == false) return false; 
		cnt /= 10;
	}
	return true;
}
bool judge(int a,int b,int c,int d,int e)
{
	a = num[a];
	b = num[b];
	c = num[c];
	d = num[d];
	e = num[e];
	int num1 = 100*a + 10*b + c;
	int num2 = 10*d + e;
	if( !(num1*d <1000 && num1*d >=100)) return false;
	if( !(num1*e <1000 && num1*e >=100)) return false;
	int num3 = num1*num2;
	if( !(num3 >= 1000 && num3 <10000)) return false;
	if( digit_judge(num1*d) == false ||
	digit_judge(num1*e) == false ||
	digit_judge(num1*num2) == false) return false;
	return true;
}
void debug(int a,int b,int c,int d,int e)
{
	int num1 = 100*a+10*b+c;
	int num2 = 10*d + e;
	cout << " start " << endl;
	cout << 100*a+10*b+c << endl;
	cout << 10*d + e << endl;
	cout << "------" << endl;
	cout << num1*d << endl;
	cout << num1*e << endl;
	cout << "----" << endl;
	cout << num1*num2<< endl;
	cout << "end" << endl;
}
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> num[i];
	ans = 0;
	for(int a=1;a<=n;a++)
	for(int b=1;b<=n;b++)
	for(int c=1;c<=n;c++)
	for(int d=1;d<=n;d++)
	for(int e=1;e<=n;e++)
		if(judge(a,b,c,d,e)){
			ans++;
	//		debug(a,b,c,d,e);
		}
	cout << ans << endl;
}
