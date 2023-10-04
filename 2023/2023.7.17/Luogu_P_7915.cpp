#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
inline int read();
int a[1000005];
char ans[1000005];
class node{
    public:
        int tag;
        int to;
        node(int a=0,int b=0){
            tag=a;
            to=b;
            return ;
        }
};
std::deque<node>st1,st2;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	int T=read();
    while(T--){
        int n=read();
        int op=1;
        for(int i=1;i<=2*n;i++){
            a[i]=read();
        }
        //L
        int pos=0;
        for(int i=2;i<=2*n;i++){
            if(a[i]==a[1]){
                pos=i;
            }
        }
        st1.clear();
        st2.clear();
        for(int i=2;i<pos;i++){
            st1.push_back(node(0,a[i]));
        }
        for(int i=pos+1;i<=2*n;i++){
            st2.push_front(node(0,a[i]));
        }
        bool fail=0;
        while(st1.size()>0||st2.size()>0){
            node top1,top2,back1,back2;
            if(st1.size()>0){
                top1=st1.front();
                back1=st1.back();
            }
            if(st2.size()>0){
                top2=st2.front();
                back2=st2.back();
            }
            if(top1.to==back1.to&&st1.size()>1){
                ans[++op]='L';
                ans[2*n-op+1]='L';
                st1.pop_front();
                st1.pop_back();
                continue;
            }
            if(top1.to==back2.to){
                ans[++op]='L';
                ans[2*n-op+1]='R';
                st1.pop_front();
                st2.pop_back();
                continue;
            }
            if(top2.to==back1.to){
                ans[++op]='R';
                ans[2*n-op+1]='L';
                st2.pop_front();
                st1.pop_back();
                continue;
            }
            if(top2.to==back2.to&&st2.size()>1){
                ans[++op]='R';
                ans[2*n-op+1]='R';
                st2.pop_front();
                st2.pop_back();
                continue;
            }
            fail=1;
            break;
        }
        if(fail){
            std::reverse(a+1,a+2*n+1);
            int pos=0;
            for(int i=2;i<=2*n;i++){
                if(a[i]==a[1]){
                    pos=i;
                }
            }
            st1.clear();
            st2.clear();
            op=1;
            for(int i=2;i<pos;i++){
                st1.push_back(node(0,a[i]));
            }
            for(int i=pos+1;i<=2*n;i++){
                st2.push_front(node(0,a[i]));
            }
            bool fail=0;
            while(st1.size()>0||st2.size()>0){
                node top1,top2,back1,back2;
                if(st1.size()>0){
                    top1=st1.front();
                    back1=st1.back();
                }
                if(st2.size()>0){
                    top2=st2.front();
                    back2=st2.back();
                }
                if(top2.to==back2.to&&st2.size()>1){
                    ans[++op]='L';
                    ans[2*n-op+1]='L';
                    st2.pop_front();
                    st2.pop_back();
                    continue;
                }
                if(top2.to==back1.to){
                    ans[++op]='L';
                    ans[2*n-op+1]='R';
                    st2.pop_front();
                    st1.pop_back();
                    continue;
                }
                if(top1.to==back2.to){
                    ans[++op]='R';
                    ans[2*n-op+1]='L';
                    st1.pop_front();
                    st2.pop_back();
                    continue;
                }
                if(top1.to==back1.to&&st1.size()>1){
                    ans[++op]='R';
                    ans[2*n-op+1]='R';
                    st1.pop_front();
                    st1.pop_back();
                    continue;
                }
                fail=1;
                break;
            }
            if(fail){
                printf("-1\n");
            }else{
                putchar('R');
                for(int i=2;i<=2*n-1;i++){
                    printf("%c",ans[i]);
                }
                putchar('L');
                putchar('\n');
            }
        }else{
            putchar('L');
            for(int i=2;i<=2*n-1;i++){
                printf("%c",ans[i]);
            }
            putchar('L');
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

*/


