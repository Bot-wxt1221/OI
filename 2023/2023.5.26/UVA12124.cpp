#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
inline int read();
int n;
class node{
    public:
        std::string a;
        std::string b;
        int pr;
        int qua;
}a[1005];
bool cmp(node a,node b){
    return a.a<b.a;
}
int check(int qua){
    int _min=0x7f7f7f7f;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].a!=a[i-1].a&&i!=1){
            if(_min==0x7f7f7f7f){
                return 0x7f7f7f7f;
            }
            ans+=_min;
            _min=0x7f7f7f7f;
        }
        if(a[i].qua>=qua){
            _min=std::min(_min,a[i].pr);
        }
    }
    if(_min==0x7f7f7f7f){
        return 0x7f7f7f7f;
    }
    ans+=_min;
    return ans;
}
char aa[22];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    while(T--){
        n=read();
        int b=read();
        for(int i=1;i<=n;i++){
            scanf("%s",&aa);
            a[i].a=aa;
            scanf("%s",&aa);
            a[i].b=aa;
            scanf("%d",&a[i].pr);
            scanf("%d",&a[i].qua);
        }
        std::sort(a+1,a+n+1,cmp);
        int l=0,r=1000000000;
        while(l<r-3){
            int mid=(l+r)/2;
            if(check(mid)>b){
                r=mid+1;
            }else{
                l=mid-1;
            }
        }
        for(int i=r;i>=l;i--){
            if(check(i)<=b){
                printf("%d\n",i);
                goto b;
            }
        }
        b:{};
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


