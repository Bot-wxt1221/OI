#include <iostream>
#include <cstdio>
inline int read();
int nn;
class node {
	public:
		int l,r;
		int now;
} a[500005],*root=NULL;
void insert(int now) {
	if(root==NULL) {
		a[++nn].now=now;
		a[nn].l=a[nn].r=-1;
		root=&a[nn];
		return ;
	}
	int x=1;
	int y;
	while(x!=-1) {
		if(a[x].now>now) {
			y=x;
			x=a[x].l;
		} else {
			y=x;
			x=a[x].r;
		}
	}
	if(a[y].now>now) {
		a[y].l=++nn;
		a[nn].now=now;
		a[nn].l=-1;
		a[nn].r=-1;
	} else {
		a[y].r=++nn;
		a[nn].now=now;
		a[nn].l=-1;
		a[nn].r=-1;
	}
}
void print1(int now) {
	if(now==-1) {
		return;
	}
	print1(a[now].l);
	printf(" %d",a[now].now);
	print1(a[now].r);
}
void Delete(int now) {
	int x=1;
	int y;
	while(x!=-1) {
		if(a[x].now>now) {
			y=x;
			x=a[x].l;
		} else if(a[x].now<now) {
			y=x;
			x=a[x].r;
		} else {
			break;
		}
	}
	if(a[x].l==-1&&a[x].r==-1) {
		if(a[y].now>now) {
			a[y].l=-1;
		} else if(a[y].now<now) {
			a[y].r=-1;
		}
	} else if(a[x].l==-1||a[x].r==-1) {
		if(a[y].now>now) {
			a[y].l=std::max(a[x].l,a[x].r);
		} else if(a[y].now<now) {
			a[y].r=std::max(a[x].l,a[x].r);
		}
	} else {
		int xx=a[x].r,yy=x;
		while(a[xx].l!=-1) {
			yy=xx;
			xx=a[xx].l;
		}
		a[x].now=a[xx].now;
        if(yy!=x){
            a[yy].l=a[xx].r;
        }else{
            a[yy].r=a[xx].r;
        }

	}
}
void print2(int now) {
	if(now==-1) {
		return;
	}
	printf(" %d",a[now].now);
	print2(a[now].l);
	print2(a[now].r);
}
bool find(int now) {
	int x=1;
	int y;
	while(x!=-1) {
		if(a[x].now>now) {
			y=x;
			x=a[x].l;
		} else if(a[x].now<now) {
			y=x;
			x=a[x].r;
		} else {
			return 1;
		}
	}
	return 0;
}
char temp[1000];
int main() {
	#ifdef ONLINE_JUDGE
	#else
	freopen("delete_bst.in","r",stdin);
	freopen("delete_bst.out","w",stdout);
	#endif
	int m=read();
	for(int i=1; i<=m; i++) {
		scanf("%s",temp);
		if(temp[0]=='i') {
			insert(read());
		} else if(temp[0]=='p') {
			print1(1);
			putchar('\n');
			print2(1);
			putchar('\n');
		} else if(temp[0]=='f') {
			if(find(read())) {
				printf("yes\n");
			} else {
				printf("no\n");
			}
		} else {
			Delete(read());
		}
	}
	return 0;
}
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
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
    模拟指针
*/

