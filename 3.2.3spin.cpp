/*
ID: messifo2
PROG: spin
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int speed[6],num[6];
int position[6][6];
int len[6][6];
int vis[360];

int main()
{
    freopen("spin.in","r",stdin);
    freopen("spin.out","w",stdout);
    int i,j;
    for(i = 1; i <= 5; i++) {
    	cin >> speed[i] >> num[i];
    	for(j = 1; j <= num[i]; j++ ) {
    		cin >> position[i][j] >> len[i][j];
    	}
    }
    int second = 0;
    while(second <= 360) {
    	memset(vis,0,sizeof(vis));
    	for(i = 1; i <= 5; i++) {
    		for(j = 1; j <= num[i]; j++) {
    			for(int k = 0; k <= len[i][j]; k++){
    				int cur =  ( position[i][j] + k ) % 360;
    				vis[cur]++;
    			}
    		}
    	}
    	for(i = 0 ; i < 360; i++) {
    		if(vis[i] == 5) {
    			cout << second << endl;
    			return 0;
    		}
    	}
    	second++;
    	for(i = 1; i <= 5; i++) {
    		for(j = 1; j <= num[i]; j++) {
    			position[i][j] = (position[i][j] + speed[i]) % 360;
    		}
    	}
    }
    cout << "none" << endl;
    return 0;
}
