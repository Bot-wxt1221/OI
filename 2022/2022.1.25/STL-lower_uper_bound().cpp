#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
const int INF=2*int(1e9)+10;
#define LL long long
int cmd(int a,int b){
	return a>b;
}
int main(){
	int num[6]={1,2,4,7,15,34}; 
	sort(num,num+6);                           //����С�������� 
	int pos1=lower_bound(num,num+6,7)-num;    //���������е�һ�����ڻ���ڱ�������ֵ 
	int pos2=upper_bound(num,num+6,7)-num;    //���������е�һ�����ڱ�������ֵ
	cout<<pos1<<" "<<num[pos1]<<endl;
	cout<<pos2<<" "<<num[pos2]<<endl;
	sort(num,num+6,cmd);                      //���Ӵ�С����
	int pos3=lower_bound(num,num+6,7,greater<int>())-num;  //���������е�һ��С�ڻ���ڱ�������ֵ 
	int pos4=upper_bound(num,num+6,7,greater<int>())-num;  //���������е�һ��С�ڱ�������ֵ 
	cout<<pos3<<" "<<num[pos3]<<endl;
	cout<<pos4<<" "<<num[pos4]<<endl;
	return 0;	
}
