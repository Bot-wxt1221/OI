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
char a[20005];
unsigned long long hash1[20005];
unsigned hash2[20005];
unsigned long long base1[20005];
unsigned base2[20005];
bool abc(int i,int j,int a){
	unsigned long long temp1=(hash1[j-1]-hash1[i-1]*base1[a]);
	unsigned long long temp2=(hash1[j+a-1]-hash1[j-1]*base1[a]);
	if(temp1!=temp2){
		return 0;
	}
	unsigned temp12=(hash2[j-1]-hash2[i-1]*base2[a])%10007;
	unsigned temp22=(hash2[j+a-1]-hash2[j-1]*base2[a])%10007;
	if(temp12!=temp22){
		return 0;
	}
	return 1;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",a+1);
	int n=strlen(a+1);
	base1[0]=base2[0]=1;
	for(int i=1;i<=n;i++){
		hash1[i]=(hash1[i-1]*256+a[i]);
		base1[i]=base2[i]=256;
		base1[i]*=base1[i-1];
		hash2[i]=(hash2[i-1]*256+a[i])%10007;
		base2[i]*=base2[i-1];
		base2[i]%=10007;
	}
	int ans=0;
	for(int i=2;i<=n;i+=2){
		for(int j=1;j+i<=n+1;j++){
			if(abc(j,j+(i/2),i/2)){
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
	example
Description:
	找子串，子串的前一半和后一半相等的有几个（子串长度为偶数） 
Example:
	1:
		In:
			abcabcabc
		Out:
			3
More:
	双哈希 
*/



