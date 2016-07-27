/*
ID: messifo2
PROG: friday
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int lastday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31} ;
bool isLeapyear(int year)
{
    return (year%100 == 0? (year%400 == 0) : (year%4 == 0) );
}
int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int week[7] = { 0 } ;
    int status = 0,year = 1900,month = 1,day = 1;
    int n ;
    cin >> n;
    while( year <= 1900 + n -1 ) {
        if(day == 13) week[status] ++ ;
        status  = (status + 1) % 7;
        if(isLeapyear(year)) lastday[2] = 29;
        else lastday[2] = 28;
        if(month == 12 ) {
            if(day == lastday[month]) {
                day = 1;
                month = 1;
                year += 1;
            }
            else day ++ ;
        }
        else{
            if(day == lastday[month]) {
                day = 1;
                month += 1;
            }
            else day ++ ;
        }
    }
    cout<<week[5]<<" "<<week[6]<<" "<<week[0]<<" "<<
    week[1]<<" "<<week[2]<<" "<<week[3]<<" "<<week[4]<<endl;
    return 0;
}
