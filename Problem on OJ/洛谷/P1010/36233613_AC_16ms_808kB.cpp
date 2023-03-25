//先做二进制拆解  将其表达为2^n1+2^n2+……也就是2（n1）+2(n2)+……,再按同样步骤计算n1,n2,……。 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void dfs(int n);
int main(){
//	freopen("power.in","r",stdin);
//	freopen("power.out","w",stdout);
	int n;
	cin>>n;
	dfs(n);
	return 0;
}
void dfs(int n){
	if(n==2)	{	cout<<"2";return ;}//一堆特判 
	if(n==0)	{	cout<<"0";return ;}
	if(n==1)	{	cout<<"2(0)";return ;}
	if(n==4)	{	cout<<"2(2)";return ;}
	int temp=n;//下20~24行统计二进制位数 
	int j;
	for(j=0;temp>0;j++){
		temp=temp>>1;//用位运算替代除法 
	}
	int c=0;
	vector <int> a;//由于要反着来 所以把它全部存下来  见样例：降序排列 
	for(int m=1;m<=j;m++){
		if(n%2==1){// 二进制位是否为1 
			a.push_back(m-1);
		}
		n=n/2;
	}
	for(int i=a.size()-1;i>=0;i--){//反着搜  注意vector容器的下标从0开始 
		if(c==0){
			if(a[i]!=1)//计算2时样例给出的就是2，但是程序会计算为2（2（0）） ，结果都一样，但是一切以样例为王 
			{ 
				cout<<"2(";
				dfs(a[i]);
				cout<<")";
			}
			else
				cout<<2;//
			c++;
		}else{
			
			if(a[i]!=1)
			{
				cout<<"+2(";
				dfs(a[i]);
				cout<<")";
			}
			else
				cout<<'+'<<2;
		}
	}
	return ;
}