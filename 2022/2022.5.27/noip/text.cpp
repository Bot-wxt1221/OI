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
	freopen("text.in","r",stdin);
	freopen("text.out","w",stdout);
	while(scanf("%s",a)!=EOF){
		b.clear();
		b.push_back('[');
		bool bei=0;
		int size=strlen(a);
		list<char>::iterator now=b.begin();
		for(int i=0;i<size;i++){
			if(a[i]=='['){
				now=b.begin();
			}else if(a[i]==']'){
				now=b.end();
			}else{
				b.insert(now,a[i]);
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


