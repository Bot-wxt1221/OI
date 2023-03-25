#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int mod(char *a,int b);
int main(){
	freopen("atlantis.in","r",stdin);
	freopen("atlantis.out","w",stdout);
for(int i=1;i<=3;i++){
	int j,ans=0;
	for(j=0;;j++){
		char aa;
		aa=getchar();
		if(aa=='\n'){
			break;
		}
		ans+=aa-'0';
		ans%=3;
	}
	if(ans==0){
		cout<<"King will win.\n";
	}else {
		cout<<"MaoLaoDa will win.\n";
		cout<<ans<<'\n';
	}
}
	return 0;
}
