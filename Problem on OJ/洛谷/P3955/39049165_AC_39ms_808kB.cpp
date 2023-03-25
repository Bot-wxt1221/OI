#include <iostream>
#include <cstdio>
#include <algorithm>
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
char a[1005];
string book[1005];
bool cmp(string a,string b){
	if(a.size()<b.size()){
		return 1;
	}else if(a.size()>b.size()){
		return 0;
	}
	return a<b;
}
int main(){
// 	freopen("librarian.in","r",stdin);
// 	freopen("librarian.out","w",stdout);
	int n=read(),q;
	q=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a);
		book[i]=a;
	}
	sort(book+1,book+n+1,cmp);
	for(int i=1;i<=q;i++){
		int si=read();
		char b[15];
		scanf("%s",b+1);
		bool have=0;
		for(int j=1;j<=n;j++){
			bool ans=1;
			for(int m=1;m<=si;m++){
				if(b[m]!=book[j][book[j].size()-si+m-1]){
					ans=0;
					break;
				}
			}
			if(ans){
				have=1;
				printf("%s\n",book[j].c_str());
				break;
			}
		}
		if(have==0){
			printf("-1\n");
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



