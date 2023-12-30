#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
inline int read();
class node{
    public:
        int a,b,c;
        int cnt;
        int i;
        node(int aa=0,int bb=0,int cc=0){
            a=aa;
            b=bb;
            c=cc;
            return ;
        }
}b[1000005],a[1000005],tem[1000005];
int tree[200005];
int cnt2[1000005];
int end[1000005];
int f[1000005];
int lowbit(int a){
    return a&-a;
}
void add(int a,int i){
    while(a<=200000){
        tree[a]+=i;
        a+=lowbit(a);
    }
    return ;
}
int query(int a){
    int ans=0;
    while(a>0){
        ans+=tree[a];
        a-=lowbit(a);
    }
    return ans;
}
int ans[1000005];
bool cmp(node a,node b){
    if(a.a!=b.a){
        return a.a<b.a;
    }
    if(a.b!=b.b){
        return a.b<b.b;
    }
    return a.c<b.c;
}
void cdq(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    cdq(l,mid);
    cdq(mid+1,r);
    int ii1=l,ii2=mid+1;
    int da=l-1;
    memset(tree,0,sizeof(tree));
    while(ii1<=mid&&ii2<=r){
        if(a[ii1].b<=a[ii2].b){
            add(a[ii1].c,a[ii1].cnt);
            tem[++da]=a[ii1];
            ii1++;
        }else{
            ans[a[ii2].i]+=query(a[ii2].c);
            tem[++da]=a[ii2];
            ii2++;
        }
    }
    while(ii1<=mid){
        add(a[ii1].c,a[ii1].cnt);
        tem[++da]=a[ii1];
        ii1++;
    }
    while(ii2<=r){
        ans[a[ii2].i]+=query(a[ii2].c);
        tem[++da]=a[ii2];
        ii2++;
    }
    for(int i=l;i<=r;i++){
        a[i]=tem[i];
    }
    return ;

}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	int n=read(),k;
    k=read();
    for(int i=1;i<=n;i++){
        b[i].a=read();
        b[i].b=read();
        b[i].c=read();
    }
    std::sort(b+1,b+n+1,cmp);
    int cnt=0;
    int tot=0;
    for(int i=1;i<=n;i++){
        if(b[i].a!=b[i+1].a||b[i].b!=b[i+1].b||b[i].c!=b[i+1].c){
            cnt++;
            a[++tot]=b[i];
            end[i]=tot;
            cnt2[i]=cnt;
            a[tot].cnt=cnt;
            a[tot].i=i;
            cnt=0;
        }else{
            cnt++;
        }
    }
    cdq(1,tot);
    for(int i=1;i<=n;i++){
        if(end[i])
            f[ans[i]+cnt2[i]-1]+=cnt2[i];
    }
    for(int i=0;i<=n-1;i++){
        printf("%d\n",f[i]);
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


