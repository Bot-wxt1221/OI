#include <iostream>
#include <cstdio>
#include <cstring>
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
char a[1000005];
unsigned long long base1[1000005];
int base2[1000005];
unsigned long long hash1[1000005];
int hash2[1000005];
char b[1000005];
int main(){
	freopen("substring_search.in","r",stdin);
	freopen("substring_search.out","w",stdout);
	scanf("%s%s",a+1,b+1);
	int sa=strlen(a+1);
	int sb=strlen(b+1);
	unsigned long long h1=0;
	int h2=0;
	for(int i=1;i<=sb;i++){
		h1=h1*256+b[i];
		h2=(h2*256+b[i])%10007;
	}
	base1[0]=base2[0]=1;
	for(int i=1;i<=sa;i++){
		base1[i]=base2[i]=256;
		base1[i]*=base1[i-1];
		base2[i]=(base2[i-1]*base2[i])%10007;
		hash1[i]=hash1[i-1]*256+a[i];
		hash2[i]=(hash2[i-1]*256+a[i])%10007;
	}
	int ans=0;
	for(int i=1;i+sb<=sa+1;i++){
		if(hash1[i+sb-1]-hash1[i-1]*base1[sb]==h1){
			if((((hash2[i+sb-1]-hash2[i-1]*base2[sb])%10007)+10007)%10007==h2){
				ans++;
			}
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



