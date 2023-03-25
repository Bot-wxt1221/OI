#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int mina=9000000,minb=9000000;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a,b,l;
	cin>>a>>b>>l;
	double temp=9000000;
	for(int za=l;za>=1;za--){
		for(int zb=l;zb>=1;zb--){
			if(double(za)/zb-double(a)/b>=0&&__gcd(za,zb)==1){
				double c=double(za)/zb-double(a)/b;
				if(c<temp){
					temp=c;
					mina=za;
					minb=zb;
				}
			}
		}
	}
	cout<<mina<<' '<<minb;
	return 0;
}