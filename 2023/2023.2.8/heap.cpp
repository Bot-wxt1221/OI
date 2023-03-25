#include <iostream>
#include <cstdio>
inline int read();
int heap[1000005];
char temp[105];
int now;
inline int up(int n){
    while(n>=1){
        if(heap[n]>heap[n/2]){
            std::swap(heap[n],heap[n/2]);
            n=n/2;
        }else{
            return n;
        }
    }
    return n;
}
inline int down(int n){
    while((n<<1)<=now){
        if(n>now||heap[n<<1]>=heap[((n<<1)|1)]){
            if(heap[n]<heap[n<<1]&&n<<1<=now){
                std::swap(heap[n],heap[n<<1]);
                n=(n<<1);
            }else{
                return n;
            }
        }else{
            if(heap[n]<heap[((n<<1)|1)]&&((n<<1)|1)<=now){
                std::swap(heap[n],heap[((n<<1)|1)]);
                n=((n<<1)|1);
            }else{
                return n;
            }
        }
    }
    return n;
}
inline void build(int n){
	now=n;
    for(int i=n>>1;i>=1;i--){
        down(i);
//        up(i);
    }
    return ;
}
inline void insert(int a){
    heap[++now]=a;
    // int b=now;
    up(now);
}
inline void Delete(){
    std::swap(heap[1],heap[now]);
    heap[now]=0;
    now--;
    down(1);
}
void change(int i,int now){
    heap[i]=now;
    up(down(i));
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("max_heap.in","r",stdin);
	freopen("max_heap.out","w",stdout);
	#endif
    int n=read();
    for(register int i=1;i<=n;i++){
        heap[i]=read();
    }
    build(n);
    for(register int i=1;i<=n;i++){
        printf("%d ",heap[i]);
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
    大根堆
*/


