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
int main(){
	freopen("joseph.in","r",stdin);
	freopen("joseph.out","w",stdout);
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a.push_back(i);
	}
	std::_List_iterator<int> it=a.begin();
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			it++;
			if(it==a.end()){
				it=a.begin();
			}
		}
		std::_List_iterator<int> temp=it;
		it++;
		cout<<*(temp)<<' ';
		a.erase(temp);
		if(it==a.end()){
			it=a.begin();
		}
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


