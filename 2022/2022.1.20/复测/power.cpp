//���������Ʋ��  ������Ϊ2^n1+2^n2+����Ҳ����2��n1��+2(n2)+����,�ٰ�ͬ���������n1,n2,������ 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void dfs(int n);
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n;
	cin>>n;
	dfs(n);
	return 0;
}
void dfs(int n){
	if(n==2)	{	cout<<"2";return ;}//һ������ 
	if(n==0)	{	cout<<"0";return ;}
	if(n==1)	{	cout<<"2(0)";return ;}
	if(n==4)	{	cout<<"2(2)";return ;}
	int temp=n;//��20~24��ͳ�ƶ�����λ�� 
	int j;
	for(j=0;temp>0;j++){
		temp=temp>>1;//��λ����������� 
	}
	int c=0;
	vector <int> a;//����Ҫ������ ���԰���ȫ��������  ���������������� 
	for(int m=1;m<=j;m++){
		if(n%2==1){// ������λ�Ƿ�Ϊ1 
			a.push_back(m-1);
		}
		n=n/2;
	}
	for(int i=a.size()-1;i>=0;i--){//������  ע��vector�������±��0��ʼ 
		if(c==0){
			if(a[i]!=1)//����2ʱ���������ľ���2�����ǳ�������Ϊ2��2��0���� �������һ��������һ��������Ϊ�� 
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
