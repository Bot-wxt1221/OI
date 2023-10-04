#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
inline int read();
bool eaten[500005];
class node{
    public:
        int i,sum;
}c[500005];
std::stack<node> d;
std::stack<node> d2;
bool operator < (node a,node b){
    return a.sum==b.sum?a.i<b.i:a.sum<b.sum;
}
bool operator > (node a,node b){
    return a.sum==b.sum?a.i>b.i:a.sum>b.sum;
}
class heap1{
    private:
        std::priority_queue<node,std::vector<node> ,std::less<node> > to;
        bool del[50005];
        int nn;
    public:
        void push(node now){
            nn++;
            del[now.i]=0;
            while(to.size()>0&&del[to.top().i]){
                to.pop();
            }
            to.push(now);
        }
        void pop(node now){
            nn--;
            del[now.i]=1;
            while(to.size()>0&&del[to.top().i]){
                to.pop();
            }
        }
        int size(){
            return nn;
        }
        node top(){
            while(to.size()>0&&del[to.top().i]){
                to.pop();
            }
            return to.top();
        }
}a;
class heap2{
    private:
        std::priority_queue<node,std::vector<node> ,std::greater<node> > to;
        bool del[500005];
        int nn;
    public:
        void push(node now){
            nn++;
            del[now.i]=0;
            while(to.size()>0&&del[to.top().i]){
                to.pop();
            }
            to.push(now);
        }
        void pop(node now){
            nn--;
            del[now.i]=1;
            while(to.size()>0&&del[to.top().i]){
                to.pop();
            }
        }
        int size(){
            return nn;
        }
        node top(){
            while(to.size()>0&&del[to.top().i]){
                to.pop();
            }
            return to.top();
        }
}b;
int die[100005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("lion.in","r",stdin);
	freopen("lion.out","w",stdout);
	#endif
    int n=read();
    int ans=0;
    for(int i=1;i<=n;i++){
        c[i].i=i;
        c[i].sum=read();
        a.push(c[i]);
        b.push(c[i]);
    }
    bool yes=0;
    int ls=0,ls2;
    do{
        if(a.size()==0||a.size()==1){
            break;
        }
        node t1=a.top();
        node t2=b.top();
        d.push(t2);
        d2.push(t1);
        b.pop(t2);
        a.pop(t2);
        a.pop(t1);
        b.pop(t1);
        t1.sum-=t2.sum;
        a.push(t1);
        b.push(t1);
        eaten[t2.i]=1;
        ans++;
        die[ans]=t2.i;
        yes=1;
    }while(yes);
    while(d.size()>0){
        node t2=d.top();
        node t1=d2.top();
        if(eaten[t1.i]){
            while(ans>0&&die[ans]!=t2.i){
                eaten[die[ans]]=0;
                die[ans]=0;
                ans--;
            }
            eaten[die[ans]]=0;
            die[ans]=0;
            ans--;
        }
        d.pop();
        d2.pop();
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(eaten[i]){
            printf("%d ",i);
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


