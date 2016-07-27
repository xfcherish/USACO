/*
ID: messifo2
PROG: ride
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    string a,b;
    int i,suma=1,sumb=1;
    cin>>a>>b;
    for(i=0;i<a.size();i++) suma*=(a[i]-'A'+1);
    for(i=0;i<b.size();i++) sumb*=(b[i]-'A'+1);
    if(suma%47==sumb%47) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    return 0;
}
