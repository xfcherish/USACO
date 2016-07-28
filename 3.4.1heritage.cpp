/*
ID: messifo2
PROG: heritage
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
	char val;
	Node *left,*right;
	/* data */
};

string in_order, pre_order;
int num;

Node* subtree(string s){
	if(s.length() == 0)
		return NULL;
	Node* ans = (Node*)malloc(sizeof(Node));
	char root = pre_order[num];
	num = num+1;
	ans->val = root;
	string s1,s2;
	int i;
	for(i = 0; i < s.length(); i++) {
		if(s[i] == root) break;
		s1 += s[i];
	}
	for(i= i+1; i < s.length(); i++) 
		s2 += s[i];
	// cout << "root = " << root << endl;
	// cout << "s1 = " << s1 << endl;
	// cout << "s2 = " << s2 << endl;
	ans->left  =  subtree(s1);
	ans->right =  subtree(s2);
	return ans;
}

void post_order_travese(Node* root) {
	if(root == NULL) return;
	post_order_travese(root->left);
	post_order_travese(root->right);
	cout << root->val;
}

int main()
{
    freopen("heritage.in","r",stdin);
    freopen("heritage.out","w",stdout);
    cin >> in_order >> pre_order;
    Node* root;
    num = 0;
    root = subtree(in_order);
    post_order_travese(root);
    cout << endl;
    return 0;
}
