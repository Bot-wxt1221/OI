#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
inline int read();
int st[10000005];
int top=0;
char temp[10000005];
int have[300];
int lst[300];
bool out[10000005];
int num[300];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("removeDuplicateLetters.in","r",stdin);
	freopen("removeDuplicateLetters.out","w",stdout);
	#endif
    scanf("%s",temp+1);
    int siz=strlen(temp+1);
	for(int i=1;i<=siz;i++){
		lst[temp[i]]=i;
		num[temp[i]]++;
	}
    for(int i=1;i<=siz;i++){
		if(have[temp[i]]){
			num[temp[i]]--;
			continue;
		}
        while(top>0&&num[temp[st[top]]]!=0&&temp[st[top]]>temp[i]){
			have[temp[st[top]]]=0;
			out[st[top]]=0;
			top--;
		}
		out[i]=1;
		st[++top]=i;
		have[temp[i]]=1;
		num[temp[i]]--;
    }
	for(int i=1;i<=siz;i++){
		if(out[i]){
			printf("%c",temp[i]);
		}
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


