#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char ab[2000005],bb[2000005];
int a[2000005],b[2000005],c[2000005];
int main(){
//	freopen("multi.in","r",stdin);
//	freopen("multi.out","w",stdout);
    cin>>aa>>bb;
	int n=strlen(ab),m=strlen(bb);
	for(int t=0;t<strlen(ab);t++){
		a[strlen(ab)-t]=ab[t]-'0';
	}
	for(int t=0;t<strlen(bb);t++){
		b[strlen(bb)-t]=bb[t]-'0';
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=m;j++){
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]=c[i+j-1]%10;
		}
		c[i+m]=x;
	}
	int lenc=n+m;
	while(c[lenc]==0)	lenc--;
	for(int i=lenc;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
