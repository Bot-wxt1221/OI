#include <iostream>
#include <cstdio>
using namespace std;
bool aa[10000005];
int _max2[5];
int work(int a,int b,int c,int d);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,_max=0;
	cin>>n;
	int i=1;
	for(int j=i+1;j<=n*i+1;j++){
		for(int m=j+1;m<=n*j+1;m++){
			for(int m2=m+1;m2<=n*m+1;m2++){
				if(_max<work(i,j,m,m2)){
					_max2[1]=m2,_max2[2]=m,_max2[3]=j,_max2[4]=i;
					_max=work(i,j,m,m2);
				}
			}
		} 
	}
	printf("%d %d %d %d %d\n",_max2[1],_max2[2],_max2[3],_max2[4],_max);
	return 0;
}
int work(int a,int b,int c,int d){
	memset(aa,0,sizeof(aa));
	for(int i=0;i<=4;i++){
		for(int j=0;j<=4-i;j++){
			for(int m=0;m<=4-i-j;m++){
				for(int m2=0;m2<=4-i-j-m;m2++){
					aa[a*i+b*j+c*m+d*m2]=1;
				} 
			}
		}
	}
	for(int i=1;;i++){
		if(aa[i]==0){
			return i-1;
		}
	}
}
