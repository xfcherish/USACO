/*
ID: messifo2
PROG: buylow
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn = 5005;
const int inf = (1e9)+10;
int n,a[maxn],c[maxn],dp[maxn];
int ans;

struct node {
	int val,pos;
};

vector<node> end_num[maxn];

const int maxl = 50;
const int ten[4] = {1,10,100,1000};

struct BigNumber{
    int d[maxl];
    BigNumber (string s) {
        int len = s.size();
        d[0] = (len-1)/4+1;
        int i,j,k;
        for(i = 1; i < maxl; i++) d[i] = 0;
        for(i = len-1; i >= 0; i--) {
            j = (len-i-1)/4+1;
            k = (len-i-1)%4;
            d[j] += ten[k]*(s[i]-'0');
        }
        while(d[0] > 1 && d[d[0]] == 0)
          --d[0];
    }
    BigNumber() {
        *this = BigNumber(string("0"));
    }
    string toString() {
        string s("");
        int i,j,temp;
        for(i = 3; i >= 1; --i)
            if(d[d[0]] >= ten[i]) break;
        temp = d[d[0]];
        for(j = i; j >= 0; j--) {
            s = s + (char)(temp/ten[j]+'0');
            temp %= ten[j];
        }
        for(i=d[0]-1; i > 0; i--) {
            temp = d[i];
            for(j = 3; j >= 0; j--) {
                s = s + (char)(temp/ten[j]+'0');
                temp %= ten[j];
            }
        }
        return s;
    }
};

BigNumber operator + (const BigNumber & a, const BigNumber & b) {
    BigNumber c;
    c.d[0] = max(a.d[0], b.d[0]);
    int i, x = 0;
    for(i = 1; i <= c.d[0]; i++) {
        x = a.d[i] + b.d[i] + x;
        c.d[i] = x % 10000;
        x /= 10000;
    }
    while(x!=0) {
        c.d[++c.d[0]] = x%10000;
        x /= 10000;
    }
    return c;
}

bool operator == (const BigNumber & a, const BigNumber & b) {
    int i;
    if(a.d[0] != b.d[0]) return false;
    for(i = 1; i <= a.d[0]; i++)
        if(a.d[i] != b.d[i]) return false;
    return true;
}
vector<BigNumber> f[maxn];

BigNumber DFS(int depth, int order) {
    if(depth == 1) {
        f[depth][order] = BigNumber(string("1"));
        return BigNumber(string("1"));
    }
    if(order < f[depth].size())
        if(!(f[depth][order] == BigNumber()))
            return f[depth][order];
    BigNumber ret = BigNumber();
    int now_val = end_num[depth][order].val;
    int now_pos = end_num[depth][order].pos;
    set<int> mysets;
    for(int i = end_num[depth-1].size()-1; i >= 0; i--) {
        int new_val = end_num[depth-1][i].val;
        int new_pos = end_num[depth-1][i].pos;
        if(now_val > new_val && now_pos > new_pos) {
            if(mysets.find(new_val) == mysets.end())
                mysets.insert(new_val);
            else continue;
            ret = ret + DFS(depth-1,i);
        }
    }
    f[depth][order] = ret;
    return ret;
}

BigNumber solve() {
    BigNumber ret = BigNumber();
    set<int> mysets;
    for(int i = end_num[ans].size()-1; i >= 0;  i--) {
        int val = end_num[ans][i].val;
        if(mysets.find(val) == mysets.end())
            mysets.insert(val);
        else continue;
        ret = ret + DFS(ans,i);
    }
    return ret;
}

int main()
{
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	c[i] = inf;
    }
    memset(dp,0,sizeof(dp));
    ans = 0;
    reverse(a+1, a+1+n);
    for(int i = 1; i <= n; i++) {
    	int k = lower_bound(c+1, c+1+n, a[i]) - c;
    	c[k] = a[i];
    	dp[i] = k;
    	ans = max(ans,dp[i]);
    	node tmp;
    	tmp.pos = i;
    	tmp.val = a[i];
    	end_num[k].push_back(tmp);
    }
    for(int i = 1; i <= ans; i++) {
        for(int j = 0; j < end_num[i].size(); j++) {
            f[i].push_back(BigNumber());
        }
    }
    BigNumber results = solve();
   	cout << ans << " " << results.toString() << endl;
    return 0;
}
