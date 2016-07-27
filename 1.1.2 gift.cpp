/*
ID: messifo2
PROG: gift1
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct one{
    string name;
    int give;
    int receive;
};
vector<one> people;
void give_gift(string giver,string rec, int number)
{
    for(int i = 0 ; i < people.size() ; i++ ) {
        if( people[i].name == giver ) {
            people[i].give +=  number;
        }
        if( people[i].name == rec) {
            people[i].receive += number;
        }
    }
}
int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    string giver,rec;
    one tmp;
    int n,i,j,give_num,initial;
    cin >> n;
    people.clear();
    for(i = 0; i < n; i++ ) {
        cin >> tmp.name;
        tmp.give = tmp.receive = 0;
        people.push_back(tmp) ;
    }
    for(i = 0; i < n; i++ ) {
        cin >> giver;
        cin >> initial >> give_num ;
        int actual_give = 0;
        if( give_num != 0 )
            actual_give = initial / give_num ;
     //   cout << "give_num = " << give_num << endl;
        for(j = 0; j < give_num ; j++ ) {
            cin >> rec;
            give_gift(giver,rec,actual_give);
        }
     //   cout << "done " << endl << endl;
    }
    for(i = 0; i < n; i++ ) {
        cout << people[i].name << " ";
        cout << people[i].receive - people[i].give << endl;
    }
    return 0;
}
