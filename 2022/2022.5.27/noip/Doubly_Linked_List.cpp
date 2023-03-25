#include <iostream>
#include <cstdio>
#include <list>
#include <cstring>
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
char temp[100];
int main(){
	freopen("Doubly_Linked_List.in","r",stdin);
	freopen("Doubly_Linked_List.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",temp);
		if(strcmp(temp,"insert")==0){
			int x=read();
			a.push_front(x);
		}else if(strcmp(temp,"delete")==0){
			int x=read();
			std::_List_iterator<int> it=a.begin();
			for(int j=1;j<=a.size();j++){
				if((*it)==x){
					a.erase(it);
					break;
				}
				it++;
			}
		}else if(strcmp(temp,"deleteFirst")==0){
			a.erase(a.begin());
		}else if(strcmp(temp,"deleteLast")==0){
			std::_List_iterator<int> it=a.end();
			it--;
			a.erase(it);
		}
	}
	std::_List_iterator<int> it=a.begin();
	cout<<*it; 
	it++; 
	for(int i=1;i<a.size();i++){
		printf(" %d",*it);
		it++;
	}
	cout<<endl;
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


