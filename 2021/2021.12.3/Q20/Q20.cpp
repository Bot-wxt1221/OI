#include <iostream>
#include <cstdio>
using namespace std;
int ans1[133];
bool used[17];
int shu[17]={0,1,14,14,4,11,7,6,9,8,10,10,5,13,2,3,15};
void dfs(int step,int n,int ans,int fa);//step:����  n:����������ӷ�    ans:��   fa:ѡ�õ�����   
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=1;i<=16;i++){
		dfs(1,i,0,0); 
	}
	int _max=0;
	for(int i=1;i<=132;i++){//ɨ���������ֵ 
		if(ans1[i]>ans1[_max])
		_max=i;
	}
	cout<<_max<<" "<<ans1[_max];
	return 0;
}
void dfs(int step,int n,int ans,int fa){
	if(step==n+1){
		ans1[ans]++;//����Ͱ�������ͳ�� 
		return;
	}
	for(int i=fa+1;i<=16;i++){
		if(used[i]){
			continue;
		}
		used[i]=1;
		dfs(step+1,n,ans+shu[i],i);
		used[i]=0;
	}
	return;
}
