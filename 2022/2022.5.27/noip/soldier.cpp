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
	freopen("soldier.in","r",stdin);
	freopen("soldier.out","w",stdout);
	
	int N=read();
	for(int aa=1;aa<=N;aa++){
		a.clear();
		int n=read();
		for(int i=1;i<=n;i++){
			a.push_back(i);
		}
		while(a.size()>3){
			int have=a.size();
			std::_List_iterator<int> it=a.begin();
			for(int i=1;2*i<=have;i++){
				it++;
				std::_List_iterator<int> temp=it;
				temp++;
				a.erase(it);
				it=temp;
			}
			have=a.size();
			if(a.size()<=3){
				break;
			}
			it=a.begin();
			for(int i=1;3*i<=have;i++){
				it++;
				it++;
				std::_List_iterator<int> temp=it;
				temp++;
				a.erase(it);
				it=temp;
			}
		}
		std::_List_iterator<int> it=a.begin();
		for(int i=1;i<=a.size();i++){
			printf("%d ",*it);
			it++;
		}
		printf("\n");
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


