/*
ID: messifo2
PROG: frameup
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int maxn = 35;
char a[maxn][maxn];
int H,W;

struct node
{
	int left,right,up,down; 
	/* data */
};

node b[30];
vector<int> top_letter[30];
vector<int> res[30];
vector<vector<int> > ans;

bool judge(vector<int> v1, vector<int> v2) {
    bool vis[26];
    memset(vis, 0 , sizeof(vis));
    for(int i = 0 ; i < v1.size(); i++)
        vis[v1[i]] = 1;
    for(int i = 0 ; i < v2.size(); i++) {
        int c = v2[i];
        for(int j = 0 ; j < top_letter[c].size(); j++) {
            if(vis[top_letter[c][j]] == 1)
                return false;
        }
    }
    return true;
}

void dfs(vector<int> answer, vector<int> letters) {
    if(judge(answer,letters) == false) return;
    if(letters.size() == 0) {
        ans.push_back(answer);
        return;
    }
    for(int i = 0; i < letters.size(); i++) {
        vector<int> next_letters = letters;
        vector<int> next_answer = answer;
        next_answer.push_back(letters[i]);
        next_letters.erase(next_letters.begin()+i);
        dfs(next_answer,next_letters);
    }
    return;
}

int main()
{
    freopen("frameup.in","r",stdin);
    freopen("frameup.out","w",stdout);
    cin >> H >> W;
    int cnt = 0;
    for(int i = 1; i <= H; i++) {
    	getchar();
        for(int j = 1; j <= W; j++) {
    		scanf("%c",&a[i][j]);
    	}
    }
    for(int i = 0; i < 26; i++) {
    	b[i].down = b[i].right = 0;
    	b[i].up = b[i].left = 100;
    }
    for(int i = 1; i <= H; i++) {
    	for(int j = 1; j <= W; j++) {
            if(a[i][j] >= 'A' && a[i][j] <= 'Z') {
        		int t = (int)(a[i][j]-'A');
        		b[t].up = min(b[t].up,i);
                b[t].down = max(b[t].down,i);
                b[t].left = min(b[t].left, j);
                b[t].right = max(b[t].right, j); 
            }
    	}
    }
    vector<int> letters;
    for(int i = 0; i < 26; i++) {
        if(b[i].right != 0) {
            cnt++;
            letters.push_back(i);
            int l = b[i].left;
            int r = b[i].right;
            int u = b[i].up;
            int d = b[i].down;
            bool v[26];
            memset(v, false, sizeof(v));
            for(int j = l; j <= r; j++) {
                if(a[u][j] <= 'Z' && a[u][j] >= 'A' &&
                    (int)(a[u][j] - 'A') != i) {
                    int tmp = (int)(a[u][j] - 'A');
                    if(v[tmp] == 0) {
                        top_letter[i].push_back(tmp);
                        v[tmp] = 1;
                    }
                }
                if(a[d][j] <= 'Z' && a[d][j] >= 'A' &&
                    (int)(a[d][j] - 'A') != i) {
                    int tmp = (int)(a[d][j] - 'A');
                    if(v[tmp] == 0) {
                        top_letter[i].push_back(tmp);
                        v[tmp] = 1;
                    }
                }
            }
            for(int j = u; j <= d; j++) {
                if(a[j][l] <= 'Z' && a[j][l] >= 'A' &&
                    (int)(a[j][l] - 'A') != i) {
                    int tmp = (int)(a[j][l] - 'A');
                    if(v[tmp] == 0) {
                        top_letter[i].push_back(tmp);
                        v[tmp] = 1;
                    }
                }
                if(a[j][r] <= 'Z' && a[j][r] >= 'A' &&
                    (int)(a[j][r] - 'A') != i) {
                    int tmp = (int)(a[j][r] - 'A');
                    // cout << "tmp="<<tmp << endl;
                    if(v[tmp] == 0) {
                        top_letter[i].push_back(tmp);
                        v[tmp] = 1;
                    }
                }
            }
        }
    }
    // for(int i = 0 ; i < cnt; i++) {
    //     int ii = letters[i];
    //     cout << (char)('A'+ii) << " above:";
    //     for(int j = 0 ; j < top_letter[ii].size(); j++) {
    //         cout << (char)('A'+top_letter[ii][j]) << " ";
    //     } 
    //     cout << endl;
    // }
    sort(letters.begin(), letters.end());
    // n = letters.size();
    vector<int> null_vector;
    dfs(null_vector, letters);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << (char)('A'+ans[i][j]);
        }
        cout << endl;
    }
    return 0;
}
