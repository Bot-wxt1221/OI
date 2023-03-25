#include <iostream>
#include <cstdio>
inline int read();
int nn;
class node{
    public:
        node *l,*r;
        int now;
}a[500005],*root=NULL;
void insert(int now){
    if(root==NULL){
        a[++nn].now=now;
        a[nn].l=a[nn].r=NULL;
        root=&a[nn];
        return ;
    }
    node *x=root;
    node *y;
    while(x!=NULL){
        if(x->now>now){
            y=x;
            x=x->l;
        }else{
            y=x;
            x=x->r;
        }
    }
    if(y->now>now){
        y->l=&a[++nn];
        a[nn].now=now;
        a[nn].l=NULL;
        a[nn].r=NULL;
    }else{
        y->r=&a[++nn];
        a[nn].now=now;
        a[nn].l=NULL;
        a[nn].r=NULL;
    }
}
void print1(node *now){
    if(now==NULL){
        return;
    }
    print1(now->l);
    printf("%d ",now->now);
    print1(now->r);
}
void print2(node *now){
    if(now==NULL){
        return;
    }
    printf("%d ",now->now);
    print2(now->l);
    print2(now->r);
}
char temp[1000];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("insert_bst.in","r",stdin);
	freopen("insert_bst.out","w",stdout);
	#endif
    int m=read();
    for(int i=1;i<=m;i++){
        scanf("%s",temp);
        if(temp[0]=='i'){
            insert(read());
        }else{
            print1(root);
            putchar('\n');
            print2(root);
            putchar('\n');
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
    指针
*/

