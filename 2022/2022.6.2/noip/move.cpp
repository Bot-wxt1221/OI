#include <iostream>
#include <cstdio>
#include <list>
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
list<int>a;
std::list<int>::iterator b[100005];
int main(){
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
	int aaa=1;
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		a.clear();
		for(int i=1;i<=n;i++){
			a.push_back(i);
			b[i]=a.end();
			b[i]--;
		}
		bool now=0;
		for(int i=1;i<=m;i++){
			int aa=read();
			
			if((aa==1&&now==0)||((aa==2)&&(now==1))){
				int x=read(),y;
				y=read();
				a.erase(b[x]);
				a.insert(b[y],x);
				b[x]=b[y];
				b[x]--;
			}else if((aa==2&&now==0)||((aa==1)&&(now==1))){
				int x=read(),y;
				y=read();				a.erase(b[x]);
				std::list<int>::iterator temp=b[y];
				temp++;
				a.insert(temp,x);
				b[x]=b[y];
				b[x]++;
			}else if(aa==3){
				int x=read(),y;
				y=read();
				*b[x]=y;
				*b[y]=x;
				swap(b[x],b[y]);
			}else{
				now=!now;
			}
		}
		printf("Case %d: ",aaa);
		unsigned long long ans=0;
		std::list<int>::iterator it;
		if(now==0){
			it=a.begin();
			int size=a.size();
			for(int i=1;i<=size;i+=2){
				ans+=*it;
				it++;
				it++;
			}
		}else{
			it=a.end();
			it--;
			int size=a.size();
			for(int i=1;i<=size;i+=2){
				ans+=*it;
				it--;
				it--;
			}
		}
		printf("%lld\n",ans);
		aaa++;
	}
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


