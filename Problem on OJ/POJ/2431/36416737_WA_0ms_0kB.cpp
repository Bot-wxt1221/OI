#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int read(){
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
class node{
	public:
		int length,how;
};
bool operator<(node a,node b){
	return a.how<b.how;
}
bool cmp(node a,node b){
	return a.length<b.length;
}
priority_queue<node>a;
node b[10005];
int main(){
//	freopen("expedition.in","r",stdin);
//	freopen("expedition.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		b[i].length=read();
		b[i].how=read();
	}
	int l,p;
	l=read();p=read();
	for(int i=1;i<=n;i++){
		b[i].length=l-b[i].length;
	}
	int i1=1;
	int use=0;
	sort(b+1,b+n+1,cmp);
	while(p<l){
		use++;
		for(;i1<=n;i1++){
			if(b[i1].length<=p){
				a.push(b[i1]);
			}else{
				i1--;
				break;
			}
		}
		if(a.size()>0){
			p+=a.top().how;
			a.pop();
		}else{
			cout<<-1;
			return 0;
		}
	}
	cout<<use;
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	一群奶牛抓起一辆卡车，冒险进入丛林深处进行探险。作为相当糟糕的司机，奶牛不幸地跑过一块岩石并刺穿了卡车的油箱。卡车现在每行驶一
个单位的距离就会泄漏一个单位的燃料。
为了修理卡车，奶牛们需要沿着一条又长又弯的路开车到最近的城镇（距离不超过 1,000,000 个单位）。在这条路上，在城镇和卡车的当前位置
之间，有 N (1 <= N <= 10,000) 个燃料站，奶牛可以停下来获取额外的燃料（每个站 1..100 个单位）。
丛林对人类来说是一个危险的地方，对牛来说尤其危险。因此，奶牛们希望在去城镇的路上尽可能少地停下来加油。幸运的是，他们卡车上的油
箱容量如此之大，以至于它可以容纳的燃料量实际上没有限制。卡车目前距离城镇 L 个单位，并且有 P 个单位的燃料 (1 <= P <= 1,000,000)。
确定到达城镇所需的最少停靠次数，或者奶牛是否根本无法到达城镇。
Example:
	1:
		In:
			4
			4 4
			5 2
			11 5
			15 10
			25 10
		Out:
			2
贪心 
*/
