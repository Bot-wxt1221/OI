#include <iostream>
#include <cstring>
#include <cstdio>
inline int read();
int pos[62505];
int a[62505];
int tree[62505];
int f[62505];
int n;
int lowbit(int x){
    return x&-x;
}
void add(int x,int a){
    while(x<=n){
        tree[x]=std::max(tree[x],a);
        x+=lowbit(x);
    }
    return ;
}
int get(int x){
    int ans=0;
    while(x>0){
        ans=std::max(ans,tree[x]);
        x-=lowbit(x);
    }
    return ans;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    int ii=0;
    while(T--){
        int n=read(),p,q;
        p=read()+1;
        q=read()+1;
        memset(pos,0,sizeof(pos));
        memset(a,0,sizeof(a));
        memset(tree,0,sizeof(tree));
        memset(f,0,sizeof(f));
        for(int i=1;i<=p;i++){
            pos[read()]=i;
        }
        for(int i=1;i<=q;i++){
            a[i]=pos[read()];
        }
        ::n=q;
        for(int i=1;i<=q;i++){
            if(a[i]==0){
                continue;
            }
            f[i]=get(a[i])+1;
            add(a[i],f[i]);
        }
        printf("Case %d: %d\n",++ii,f[q]);
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
    Exercise
Description:
    最长公共子序列
Example:
	1:
		In:
            1
            3 6 7
            1 7 5 4 8 3 9
            1 4 3 5 6 2 8 9
		Out:
            Case 1: 4
More:
    第二个序列映射到第一个序列的下标上后跑最长上升子序列
*/