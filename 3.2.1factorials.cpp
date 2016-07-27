/*
ID: messifo2
PROG: fact4
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    int n ;
    cin >> n;
    int num_5 = 0;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
    	int tmp = i;
    	while(tmp % 5 == 0) {
    		tmp /= 5;
    		num_5++;
    	}
    }
    for(int i = 1; i <= n; i++) {
    	int tmp = i;
    	while(tmp % 5 == 0) 
    		tmp /= 5;
    	while(tmp % 2 == 0 && num_5 > 0) {
    		tmp /= 2;
    		num_5 -- ;
    	}
    	ans = (ans*tmp)%10;
    }
    cout << ans << endl;
    return 0;
}
