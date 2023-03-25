/*
±©Á¦Ã¶¾Ùa,b,c,d 
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	int n;
	cin>>n;
	for(int a=1;a<=n;a++){
		for(int b=2;b<=n;b++){
			for(int c=b;c<=n;c++){
				for(int d=c;d<=n;d++){
					if(a*a*a==b*b*b+c*c*c+d*d*d){
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					}
				}
			}
		}
	}
	return 0;
}


