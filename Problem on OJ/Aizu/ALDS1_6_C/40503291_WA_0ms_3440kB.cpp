#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
    public:
        int num;
        char a;
};
node a[100005];
node b[100005];
bool operator < (node a,node b){
    return a.num<b.num;
}
void qsort(int l,int r){
    if(l+1>=r){
        return ;
    }
    int mid=(l+r)/2;
    int x=a[r-1].num;
    int now=l-1;
    for(int j=l;j<r-1;j++){
        if(a[j].num<=x){
            now++;
            std::swap(a[now],a[j]);
        }
    }
    std::swap(a[now+1],a[r-1]);
    qsort(l,mid);
    qsort(mid,r);
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
//	freopen("quick_sort.in","r",stdin);
//	freopen("quick_sort.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        while(a[i].a==' '||a[i].a=='\n'){
            a[i].a=getchar();
        }
        b[i]=a[i];
    }
    bool yes=1;
    qsort(1,n+1);
    std::stable_sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        if(b[i].a!=a[i].a){
            printf("\nNot stable");
            yes=0;
            break;
        }
    }
    if(yes)
        printf("\nStable");
    for(int i=1;i<=n;i++){
        printf("%s %d",a[i].a,a[i].num);
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


