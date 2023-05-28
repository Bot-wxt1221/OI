//dp 01背包 
#include <iostream>
#include <cstdio>
using namespace std;
int ans1[133];
int shu[17]={0,1,14,14,4,11,7,6,9,8,10,10,5,13,2,3,15};
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ans1[0]=1;
	for(int j=1;j<=16;j++){
		for(int i=132-shu[j];i>=0;i--){
			ans1[i+shu[j]]+=ans1[i];
		}
	}
	int _max=0;
	for(int i=1;i<=132;i++){//扫数组求最大值 
		if(ans1[i]>ans1[_max])
		_max=i;
	}
	cout<<_max<<' '<<ans1[_max];
	return 0;
}
