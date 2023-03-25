#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
std::priority_queue<int>a;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF&&(n!=0||k!=0))
     {   a=std::priority_queue<int>();
        for(int i=1;i<=n;i++){
            char temp[10];
            scanf("%s",temp);
            if(temp[0]=='I'){
                if(a.size()<k){
                    a.push(-read());
                }else{
                    int temp=read();
                    if((-a.top())>=temp){

                    }else{
                        a.pop();
                        a.push(-temp);
                    }
                }
            }else{
                printf("%d\n",-a.top());
            }
        }}
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


