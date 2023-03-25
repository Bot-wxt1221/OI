#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string a,b;
void dfs(string a,string b);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>a>>b;
	dfs(a,b);
	return 0;
}
void dfs(string a,string b){
	char ch=b[b.size()-1];
	if(b.size()<=0){
		return;
	}
	cout<<ch;
	int k=a.find(ch);
	dfs(a.substr(0,k),b.substr(0,k));
	dfs(a.substr(k+1),b.substr(k,a.size()-k-1));
}