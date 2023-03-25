#include <iostream>
#include <cstdio>
using namespace std;
int a[256];
int main(){
	freopen("mobile.in","r",stdin);
	freopen("mobile.out","w",stdout);
	a[' ']=a['a']=a['d']=a['g']=a['j']=a['m']=a['p']=a['t']=a['w']=1;
	a['b']=a['e']=a['h']=a['k']=a['n']=a['q']=a['u']=a['x']=2;
	a['c']=a['f']=a['i']=a['l']=a['o']=a['r']=a['v']=a['y']=3;
	a['s']=a['z']=4;
	char temp=getchar();
	int ans=0;
	while(temp!=EOF){
		ans+=a[temp];
		temp=getchar();
	}
	cout<<ans;
	return 0;
}

