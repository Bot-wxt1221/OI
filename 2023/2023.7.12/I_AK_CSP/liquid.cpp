#include <iostream>
#include <cstdio>
#define int long long 
inline int read();
int c[100005];
bool kind[100005];
class node{
    public:
        node *l,*r;
        int ll,rr;
        int key;
        node(){
            l=r=NULL;
            return ;
        }
        ~node(){
            return ;
        }
}*root,tree[800005];
int cnt=0;
void build(){
    root=&tree[cnt++];
    (*root).key=0x7f7f7f7f7f7f7f7f;
    (*root).ll=0;
    (*root).rr=2000000000;
    return ;
}
void insert(node *now,int p,int ww){
    if((*now).ll==(*now).rr){
        (*now).key=std::min((*now).key,ww);
        return ;
    }
    int mid=((*now).ll+(*now).rr)/2;
    if(p<=mid){
        if((*now).l==NULL){
            (*now).l=&tree[cnt++];
            tree[cnt-1].ll=(*now).ll;
            tree[cnt-1].rr=mid;
            tree[cnt-1].key=0x7f7f7f7f7f7f7f7f;
        }
        insert((*now).l,p,ww);
    }else{
        if((*now).r==NULL){
            (*now).r=&tree[cnt++];
            tree[cnt-1].ll=mid+1;
            tree[cnt-1].rr=(*now).rr;
            tree[cnt-1].key=0x7f7f7f7f7f7f7f7f;
        }
        insert((*now).r,p,ww);
    }
    (*now).key=0x7f7f7f7f7f7f7f7f;
    if((*now).l!=NULL){
        (*now).key=std::min(((*now).l)->key,(*now).key);
    }
    if((*now).r!=NULL){
        (*now).key=std::min(((*now).r)->key,(*now).key);
    }
}
int get_min(node *now,int ll,int rr){
    if(now==NULL||(*now).key==0x7f7f7f7f7f7f7f7f){
        return 0x7f7f7f7f7f7f7f7f;
    }
    if((*now).rr<ll||rr<(*now).ll){
        return 0x7f7f7f7f7f7f7f7f;
    }
    if((*now).rr==(*now).ll){
        return now->key;
    }
    int mid=((*now).ll+(*now).rr)/2;
    int ans=0x7f7f7f7f7f7f7f7f;
    if((*now).l!=NULL){
        ans=std::min(ans,get_min(((*now).l),ll,rr));
    }
    if((*now).r!=NULL){
        ans=std::min(ans,get_min(((*now).r),ll,rr));
    }
    return ans;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("liquid.in","r",stdin);
	freopen("liquid.out","w",stdout);
	#endif
    int n=read();
    char op;
    for(int i=1;i<=n;i++){
        int x=read();
        op=getchar();
        c[i]+=c[i-1];
        if(op=='A'){
            c[i]+=x;
            kind[i]=1;
        }else{
            c[i]-=x;
        }
    }
    if(c[n]<0){
        for(int i=1;i<=n;i++){
            kind[i]=!kind[i];
            c[i]=-c[i];
        }
    }
    for(int i=1;i<=n;i++){
        c[i]+=1000000000ll;
    }
    build();
    insert(root,1000000000ll,0);
    for(int i=1;i<=n;i++){
        if(kind[i]){
            int f=get_min(root,c[i-1],c[i]-1)+1;
            insert(root,c[i],f);
        }
    }
    printf("%lld",get_min(root,c[n]-1,2000000000ll));
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


