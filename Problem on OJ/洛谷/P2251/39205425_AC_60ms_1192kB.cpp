#include <iostream>
#include <cstdio>
#include <queue>
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
deque<int>b;//下标
int a[1000005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int m=read();
    for(int i=1;i<m;i++){
        a[i]=read();
        while(b.size()>0&&a[b.back()]>=a[i]){
            b.pop_back();
        }
        b.push_back(i);
    }
    for(int i=m;i<=n;i++){
        a[i]=read();
        while(b.size()>0&&a[b.back()]>=a[i]){
            b.pop_back();
        }
        b.push_back(i);
        while(b.size()>0&&i-b.front()>=m){
            b.pop_front();
        }
        printf("%d\n",a[b.front()]);
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

