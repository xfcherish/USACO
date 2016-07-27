/*
ID: messifo2
PROG: ratios
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	return ( b == 0 ? a : gcd(b , a % b) ) ;
}

int main()
{
    freopen("ratios.in","r",stdin);
    freopen("ratios.out","w",stdout);
    int i,a[4],b[4],c[4],d[4],multi;
    for(i = 1; i <= 3; i++ ) cin >> d[i];
    for(i = 1; i <= 3; i++ ) {
    	cin >> a[i] >> b[i] >> c[i];
    }

    int A[3],B[3],C[3];
	A[1] = a[1]*d[2] - b[1]*d[1];
	B[1] = a[2]*d[2] - b[2]*d[1];
	C[1] = a[3]*d[2] - b[3]*d[1];
	A[2] = a[1]*d[3] - c[1]*d[1];
	B[2] = a[2]*d[3] - c[2]*d[1];
	C[2] = a[3]*d[3] - c[3]*d[1];
	int x,y,z;
	x = B[1]*C[2] - C[1]*B[2];
	y = C[1]*A[2] - A[1]*C[2];
	z = A[1]*B[2] - B[1]*A[2];
	if(x == 0 && y == 0 && z == 0) {
		A[2] = 1;
		B[2] = 1;
		C[2] = 1;
		x = B[1]*C[2] - C[1]*B[2];
		y = C[1]*A[2] - A[1]*C[2];
		z = A[1]*B[2] - B[1]*A[2];
		// cout << "hehe" << endl;
	}
	if( (x <= 0 && y <= 0 && z <= 0)|| (x>= 0 && y >= 0 && z >= 0)) {
		// cout << "x = " << x << " y = " << y << " z = " << z << endl;
		int ans[4];
		x = fabs(x);
		y = fabs(y);
		z = fabs(z);
		int common = gcd(gcd(x,y), gcd(x,z));
		if(x != 0) x = x/common;
		if(y != 0) y = y/common;
		if(z != 0) z = z/common;
		ans[1] = a[1]*x + a[2]*y + a[3]*z ;
		ans[2] = b[1]*x + b[2]*y + b[3]*z ;
		ans[3] = c[1]*x + c[2]*y + c[3]*z ;
		if(ans[1] > d[1]) {
			multi = ans[1]/d[1];
		}
		else {
			multi = d[1]/ans[1];
			x = multi * x;
			y = multi * y;
			z = multi * z;
			multi = 1;
		}
		// printf("%d:%d:%d = %d:%d:%d\n", d[1],d[2],d[3],ans[1],ans[2],ans[3]);
		if( !(x >= 100) || (y >= 100) || (z >= 100) ) {
			cout << x << " " << y << " " << z << " " << multi << endl;
			return 0;
		}
	}
	cout << "NONE" << endl;
    return 0;
}
