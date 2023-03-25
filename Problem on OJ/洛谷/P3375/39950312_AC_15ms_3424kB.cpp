#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char s1[1000005];
char s2[1000005];
int kmp[1000005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    scanf("%s",s1+1);
	scanf("%s",s2+1);
	int ns1=strlen(s1+1);
	int ns2=strlen(s2+1);
	for(int i=1,j=0;i<ns2;i++){
		while(j>0&&s2[i+1]!=s2[j+1]){
			j=kmp[j];
		}
		if(s2[i+1]==s2[j+1]){
			j++;
		}
		kmp[i+1]=j;
	}
	for(int i=0,j=0;i<ns1;i++){
		while(j>0&&s1[i+1]!=s2[j+1]){
			j=kmp[j];
		}
		if(s1[i+1]==s2[j+1]){
			j++;
		}
		if(j==ns2){
			printf("%d\n",i-ns2+2);
			j=kmp[j];
		}
	}
	for(int i=1;i<=ns2;i++){
		printf("%d ",kmp[i]);
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


