#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>
using namespace std;
inline int read();
deque<int>a;
bitset<100000005>b;
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),q;
    q=read();
    for(int i=2;i<=n/2;i++){
        if(b[i]==1){
            continue;
        }
        for(int j=i+i;j<=n;j+=i){
            b[j]=1;
        }
    }
    for(int i=2;i<=n;i++){
        if(b[i]==0){
            a.push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",a[read()-1]);
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


