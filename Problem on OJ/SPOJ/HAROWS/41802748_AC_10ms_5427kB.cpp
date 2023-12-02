#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
char temp[10];
std::vector <int> a;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("row.in","r",stdin);
	freopen("row.out","w",stdout);
	#endif
    int T=read();
	for(int ii=1;ii<=T;ii++){
		int n=read();
		a.clear();
		a.resize(n+1);
		for(int i=1;i<=n;i++){
			scanf("%s",temp+1);
			int temp1=0;
			a[i]=0;
			for(int j=1;j<=n;j++){
				if(temp[j]=='1'){
					a[i]=j;
					temp1=1;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int ii=0x3f3f3f3f,jj=0;
			bool temp=1;
			for(int j=1;j<=int(a.size())-1;j++){
				if(a[j]<=i){
					jj=j;
					break;
				}
			}
			ans+=(jj-1);
			a.erase(a.begin()+jj);
		}
		printf("Case #%d: %d\n",ii,ans);
	}
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


