/*
ID: messifo2
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
string s;
int collect(int broken)
{
    int n = s.length();
    int l = broken % n;
    int r = (broken+1) % n;
    bool start = false;
    int num1 = 0, num2 = 0;
    int tag = 0 ;
    while(r != broken) {
        if(s[r] == 'r') {
            if(tag == 0) {
                tag = 1; num1++; r = (r+1)%n;
            }
            else if(tag == 1) {
                num1++; r = (r+1)%n;
            }
            else break;
        }
        else if(s[r] == 'b') {
            if(tag == 0) {
                tag = 2; num1++; r = (r+1)%n;
            }
            else if(tag == 2) {
                num1++; r = (r+1)%n;
            }
            else break;
        }
        else if(s[r] == 'w') {
            num1++; r = (r+1)%n;
        }
    }
    tag = 0;
    while(l != broken || !start ) {
        start = true;
        if(s[l] == 'r') {
            if(tag == 0) {
                tag = 1; num2++; l = (l+n-1)%n;
            }
            else if(tag == 1) {
                num2++; l = (l+n-1)%n;
            }
            else break;
        }
        else if(s[l] == 'b') {
            if(tag == 0) {
                tag = 2; num2++; l = (l+n-1)%n;
            }
            else if(tag == 2) {
                num2++; l = (l+n-1)%n;
            }
            else break;
        }
        else if(s[l] == 'w') {
            num2++; l = (l+n-1)%n;
        }
    }
    int ans = num1 + num2 ;
    if(ans > n ) return n;
    else return ans;
}
int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int n,i,j;
    cin >> n >> s;
    int ans = 0;
    for(i = 0 ; i < n; i++) {
       // cout << " i = " << i << endl;
        int tmp = collect(i);
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
