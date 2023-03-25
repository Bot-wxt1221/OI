#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <stack>
using namespace std;
list<char>b;
char a[100005];
stack<char>c;
int main(){
//	freopen("text1.in","r",stdin);
//	freopen("text.out","w",stdout);
	while(scanf("%s",a)!=EOF){
		b.clear();
		bool bei=0;
		int size=strlen(a);
		for(int i=0;i<size;i++){
			if(bei==0){
				if(a[i]=='['){
					bei=1;
				}else{
					b.push_back(a[i]);
				}
			}else{
				if(a[i]=='['){
					while(!c.empty()){
						b.push_front(c.top());
						c.pop();
					}
				}else if(a[i]==']'){
					while(!c.empty()){
						b.push_front(c.top());
						c.pop();
					}
					bei=0;
				}else{
					c.push(a[i]);
				}
			}
		}
		list<char>::iterator beinow=b.begin();
		for(int i=1;i<=b.size();i++){
			if(*beinow!='['&&*beinow!=']')
				cout<<*beinow;
			beinow++;
		}
		cout<<endl;
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

