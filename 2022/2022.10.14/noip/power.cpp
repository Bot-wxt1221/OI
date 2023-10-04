#include <iostream>
#include <cstdio>
#include <cmath>
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
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
while(scanf("%s",a+1)&&a[1]!='.'&&a[2]!='\0'){
	memset(base1,0,sizeof(base1));
	memset(hash2,0,sizeof(hash2));
	memset(hash1,0,sizeof(hash1));
	memset(base2,0,sizeof(base2));
	bool anss=0;
	int sa=strlen(a+1);
	base1[0]=base2[0]=1;
	for(int i=1;i<=sa;i++){
		base1[i]=base2[i]=256;
		base1[i]*=base1[i-1];
		base2[i]=(base2[i-1]*base2[i])%10007;
		hash1[i]=hash1[i-1]*256+a[i];
		hash2[i]=(hash2[i-1]*256+a[i])%10007;
	}
	for(int i=1;i<=sa;i++){
		if(sa%i!=0){
			continue;
		}
		int h1=(hash1[i]);
		int h2=hash2[i];
		bool ans=1;
		for(int j=i+1;j<sa;j+=i){
			if(h1!=(hash1[j+i-1]-hash1[j-1]*base1[i])){
				ans=0;
				break;
			}
			if(h2!=(((hash2[j+i-1]-hash2[j-1]*base2[i])%10007)+10007)%10007){
				ans=0;
				break;
			}
		}
		if(ans){
			printf("%d\n",sa/i);
			anss=1;
			break;
		}
	}
	if(anss==0)
		printf("%d\n",1);
}
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



