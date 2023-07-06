#include <iostream>
#include <cstdio>
#include <queue>
#include <list>
inline int read();

class mem{
    public:
        int l,r;
        mem(int ll=0,int rr=0){
            l=ll;
            r=rr;
        }
};
std::list<mem> me;
std::list<mem>::iterator to[10005];
int p[10005];
class node{
    public:
        int time,type,mem,i;
        node(int a=0,int b=0,int c=0,int ii=0){
            time=a;
            type=b;
            mem=c;
            i=ii;
        }
};

bool operator < (node a,node b){
    return a.time==b.time?a.type>b.type:a.time>b.time;
}
std::priority_queue<node> a;
std::queue<node> b;
int main(){
	// #ifdef ONLINE_JUDGE
	// #else
	freopen("memory.in","r",stdin);
	freopen("memory.out","w",stdout);
	// #endif
    int n=read();
    int t,m;
    int ii=0;
    me.push_back(mem(-1,-1));
    me.push_back(mem(n,n));
    while(scanf("%d%d%d",&t,&m,&p[ii+1])!=EOF){
        if(t==m&&m==p[ii+1]&&t==0){
            break;
        }
        p[ii+1]--;
        a.push(node(t,1,m,++ii));
        // std::cerr<<t<<' ';
    }
    int tt=0;
    int ttt=0;
    while(a.size()>0){
        node temp=a.top();
        a.pop();
        if(temp.i==5){
            std::cerr<<' ';
        }
        if(temp.type==0){
            me.erase(to[temp.i]);
            tt=std::max(tt,temp.time);
            if(a.size()==0||a.top().type==1||a.top().time!=temp.time){
                while(b.size()>0){
                    node temp1=b.front();
                    bool found=0;
                    for(std::list<mem>::iterator i=me.begin();std::next(i)!=me.end();i=std::next(i)){
                        mem l=*i;
                        mem r=*(next(i));
                        if(r.l-l.r-1>=temp1.mem){
                            found=1;
                            me.insert(next(i),mem(l.r+1,l.r+temp1.mem));
                            to[temp1.i]=next(i);
                            a.push(node(temp.time+p[temp1.i]+1,0,temp1.mem,temp1.i));
                            b.pop();
                            break;
                        }
                    }
                    if(!found){
                        break;
                    }
                }
            }
        }else{
            bool found=0;
            for(std::list<mem>::iterator i=me.begin();std::next(i)!=me.end();i=std::next(i)){
                mem l=*i;
                mem r=*(next(i));
                if(r.l-l.r-1>=temp.mem){
                    found=1;
                    me.insert(next(i),mem(l.r+1,l.r+temp.mem));
                    to[temp.i]=next(i);
                    a.push(node(temp.time+p[temp.i]+1,0,temp.mem,temp.i));
                    break;
                }
            }
            if(!found){
                ttt++;
                b.push(node(temp.time,temp.type,temp.mem,temp.i));
            }
        }
    }
    
    printf("%d\n%d",tt,ttt);
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


