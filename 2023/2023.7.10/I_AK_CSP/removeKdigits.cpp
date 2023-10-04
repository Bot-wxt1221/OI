#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
inline int read();
char num[100005];
bool del[100005];
std::stack<int>a;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("removeKdigits.in","r",stdin);
	freopen("removeKdigits.out","w",stdout);
	#endif
    scanf("%s",num+1);
    int k=read();
    int sz=strlen(num+1);
    int nk=sz-k;
    for(int i=1;i<=sz;i++){
        while(a.size()>0&&k>0&&num[a.top()]>num[i]){
            del[a.top()]=1;
            k--;
            a.pop();
        }
        a.push(i);
    }
    int zero=0;
    int out=0;
    for(int i=1;i<=nk;i++){
        if(del[i]){
            nk++;
            continue;
        }
        if(num[i]!='0'){
            printf("%c",num[i]);
            zero=1;
            out=1;
        }else if(zero){
            printf("%c",num[i]);
            out=1;
        }
    }
    if(!out){
        printf("0");
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


