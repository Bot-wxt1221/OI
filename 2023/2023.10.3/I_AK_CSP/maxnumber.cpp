#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int tree[200005];
int n=200001;
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y){
    while(x<=n){
        tree[x]=std::max(tree[x],y);
        x+=lowbit(x);
    }
    return ;
}
int query(int x){
    int ans=0;
    while(x>0){
        ans=std::max(tree[x],ans);
        x-=lowbit(x);
    }
    return ans;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("maxnumber.in","r",stdin);
	freopen("maxnumber.out","w",stdout);
	#endif
    int m=read(),p=read();
    int now=200001;
    int t=0;
    for(int i=m;i>0;i--){
        char temp[5];
        scanf("%s",temp+1);
        if(temp[1]=='Q'){
            int l=read();
            printf("%lld\n",t=query(now+l));
        }else{
            int a=read();
            a+=t;
            a%=p;
            add(now--,a);
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


