#include <iostream>
#include <cstdio>
using namespace std;
int ans1[133];
int shu[17]={0,1,14,14,4,11,7,6,9,8,10,10,5,13,2,3,15};
void dfs(int step,int ans);//step:步数  n:几个数参与加法    ans:和   fa:选用的数字   
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dfs(1,0);
	int _max=0;
	for(int i=1;i<=132;i++){//扫数组求最大值 
		if(ans1[i]>ans1[_max])
		_max=i;
	}
	cout<<_max<<" "<<ans1[_max];
	return 0;
}
void dfs(int step,int ans){
	if(step==17){
		ans1[ans]++;//类似桶排序进行统计 
		return;
	}
	dfs(step+1,ans+shu[step]);
	dfs(step+1,ans);
	return;
}
