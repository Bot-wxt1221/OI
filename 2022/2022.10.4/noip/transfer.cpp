#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
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
class node{
	public:
		int cost,tim;
		node(){
			cost=tim=0;
		}
};
deque<node>fre;
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int n=read();
	long long cost=0;
	fre=deque<node>();
	for(int i=1;i<=n;i++){
		int op=read();
		int pri=read();
		int tim=read();
		while(fre.size()>0&&tim-fre.front().tim>45){
			fre.pop_front();
		}
		if(op==0){
			cost+=pri;
			node temp;
			temp.cost=pri;
			temp.tim=tim;
			fre.push_back(temp);
		}else{
			bool sus=0;
			deque<node>::iterator a=fre.begin();
			while(a!=fre.end()){
				if((*a).cost>=pri){
					sus=1;
					fre.erase(a);
					break;
				}
				a++;
			}
			if(sus==0){
				cost+=pri;
			}
		}
	}
	printf("%lld",cost);
	return 0;
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



