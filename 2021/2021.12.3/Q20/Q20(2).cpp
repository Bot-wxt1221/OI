#include <iostream>
#include <cstdio>
using namespace std;
int ans1[133];
int shu[17]={0,1,14,14,4,11,7,6,9,8,10,10,5,13,2,3,15};
void dfs(int step,int ans);//step:����  n:����������ӷ�    ans:��   fa:ѡ�õ�����   
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dfs(1,0);
	int _max=0;
	for(int i=1;i<=132;i++){//ɨ���������ֵ 
		if(ans1[i]>ans1[_max])
		_max=i;
	}
	cout<<_max<<" "<<ans1[_max];
	return 0;
}
void dfs(int step,int ans){
	if(step==17){
		ans1[ans]++;//����Ͱ�������ͳ�� 
		return;
	}
	dfs(step+1,ans+shu[step]);
	dfs(step+1,ans);
	return;
}
