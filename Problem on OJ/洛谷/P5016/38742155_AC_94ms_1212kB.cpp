#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int read(){
	char a=getchar();
	int f=1,x=0;
	while('0'>a||a>'9'){
		(a=='-')?f=-1:0;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=(x<<3)+(x<<1)+(a-'0');
		a=getchar();
	}
	return f*x;
}
int c[100005];
signed main(){
// 	freopen("fight.in","r",stdin);
// 	freopen("fight.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	int m,p1,s1,s2;
	m=read();
	p1=read();
	s1=read();
	s2=read();
	c[p1]+=s1;
	int dra=0,tig=0;
	for(int i=1;i<=n;i++){
		if(i<m){
			dra+=(m-i)*c[i];
		}else{
			tig+=(i-m)*c[i];
		}
	}
	int _min=abs(tig-dra);
	int mina=m;
	for(int i=1;i<=n;i++){
		int temp1;
		if(i<m){
			temp1=(m-i)*s2;
			if(_min>abs(temp1+dra-tig)){
				_min=abs(temp1+dra-tig);
				mina=i;
			}
		}else{
			temp1=(i-m)*s2;
			if(_min>abs(temp1-dra+tig)){
				_min=abs(temp1-dra+tig);
				mina=i;
			}
		}
	}
	printf("%d",mina);
	return 0;
}
