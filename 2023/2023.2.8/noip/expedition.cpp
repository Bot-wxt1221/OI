#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
inline int read();
class node{
    public:
        int dis,a;
}a[10005];
bool cmp(node a,node b){
    return a.dis<b.dis;
}
bool operator < (node a,node b){
    return a.a<b.a;
}
std::priority_queue<node>b;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("expedition.in","r",stdin);
	freopen("expedition.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i].dis=read();
        a[i].a=read();
    }
    int l=read();
    int p=read();
    for(int i=1;i<=n;i++){
        a[i].dis=l-a[i].dis;
    }
    std::sort(a+1,a+n+1,cmp);
    int j=1;
    int ans=0;
    while(p<l){
        ans++;
        for(;j<=n;j++){
            if(a[j].dis<=p){
                b.push(a[j]);
            }else{
                break;
            }
        }
        if(b.size()>0){
            p+=b.top().a;
            b.pop();
        }else{
            printf("-1");
            return 0;
        }
    }
    printf("%d",ans);
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


