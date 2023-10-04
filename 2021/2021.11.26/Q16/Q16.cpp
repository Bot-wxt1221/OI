//³¤Îªc+x ¿íÎªc-x 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int cnt=0;
	for(int c=1;c<=125;c++){
		for(int b=1;b<c;b++){
			for(int a=1;a<c;a++){
				if((a*a+b*b)==(c*c)){
					if(__gcd(a,b)==1){
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt/2;
	return 0;
}
