#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
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
unsigned long long ha1sh[10005];
char temp[1505];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",temp);
		int size=strlen(temp);
		for(int j=0;j<size;j++){
			ha1sh[i]*=129;
			ha1sh[i]+=temp[j];
		}
	}
	sort(ha1sh+1,ha1sh+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(ha1sh[i]!=ha1sh[i-1]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
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


