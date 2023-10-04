#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
    public:
        int v,pos;
}a[1000006];
bool cmp(node a,node b){
    return a.v<b.v;
}
int b[1000005];
int c[1000005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i].v=read();
        a[i].pos=i;
    }
    std::sort(a+1,a+n+1,cmp);
    a[0].v=-1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].v==a[i-1].v){
            b[a[i].pos]=b[a[i-1].pos];
        }else{
            b[a[i].pos]=++ans;
        }
    }
    int have=0;
    int j=1;
    int anss=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(have<ans){
            c[b[i]]++;
            if(c[b[i]]==1){
                have++;
            }
            if(have>=ans){
                while(c[b[j]]>1){
                    c[b[j]]--;
                    j++;
                }
                anss=std::min(anss,i-j+1);
            }
        }else{
            c[b[i]]++;
            while(c[b[j]]>1){
                c[b[j]]--;
                j++;
            }
            anss=std::min(anss,i-j+1);
        }
    }
    printf("%d",anss);
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


