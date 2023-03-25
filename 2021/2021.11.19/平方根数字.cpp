#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool use[15];
int cnt=0;
char a[1000000];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=1000;1;i++){
		if(i==1326){
			cout<<1;
		}
		cnt=0;
		int temp=i;
		double b=sqrt(temp);
		sprintf(a,"%lf",b);
		string c=a;
		//cout<<c<<endl;
		cnt=0;
		int us=0;
		memset(use,0,sizeof(use));
		for(int j=0;cnt<9;j++){
			if('0'>c[j]||c[j]<'9')	continue;
			if(!use[c[j]-'0'])	cnt++;
			use[c[j]-'0']=1;
			us=j;
		}
		cout<<us<<endl;
	}
	return 0;
}
