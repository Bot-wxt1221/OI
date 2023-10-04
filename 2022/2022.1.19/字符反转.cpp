#include <iostream>
#include <cstdio>
using namespace std;
void er(int a);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	er(n);
	return 0;
}
void er(int a){
	if(a==0){
		return ;
	}
	er(a>>1);
	cout<<(a&1);
}
