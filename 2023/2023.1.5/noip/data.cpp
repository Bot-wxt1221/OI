#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stack>
inline int read();
std::stack<int>to;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	 freopen("dispatch1.in","w",stdout);
	#endif
	srand(time(NULL));
    int n=10;
    printf("%d\n",n);
    int now=1;
    for(int i=1;i<=n*2&&now<=n;i++){
    	if(to.size()==0||(rand()%2)){
    		to.push(now);
    		now++;
		}else{
			printf("%d ",to.top());
			to.pop();
		}
	}
	while(to.size()>0){
		printf("%d ",to.top());
			to.pop();
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


