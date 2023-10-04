//递推，何老没给数据范围，所以滚动记录数据 

/*以铺满(n-1)个格子的方法，再向后添加一个1*1，可得答案
以铺满(n-2)个格子的方法，再向后添加一个1*2，可得答案
以铺满(n-3)个格子的方法，再向后添加一个1*3，可得答案
*/
#include <iostream>
#include <cstdio>
using namespace std;
long long read(){//快读，我也不知道我为什么要用 
	long long x=0,f=1;char c=getchar();
	while('0'>c||'9'<c)	c=='-'?f=-1:1,c=getchar();
	while('0'<=c&&c<='9')	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main(){
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	long long n=read(); 
	long long n1,n2,n3;//滚动 n1前1个 n2前2个 n3前3个   
	n1=4,n2=2,n3=1;//初始化 
	if(n==0){//特判，不然会红 
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		cout<<2;
		return 0;
	}
	if(n==3){
		cout<<4;
		return 0;
	}
	long long temp;
	for(long long i=4;i<=n;i++){//递推 
		temp=n1+n2+n3;
		n3=n2,n2=n1,n1=temp;
	}
	cout<<temp;
	return 0;
}

