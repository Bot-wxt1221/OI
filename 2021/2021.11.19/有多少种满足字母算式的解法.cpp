#include <iostream>
#include <cstdio>
using namespace std;
void dfs(int step);
int a[30];//�洢ÿ����   r 1 e 2 a 3 d 4 w 5 i 6 t 7 l 8 k 9 s 10 
bool use[10];//�Ƿ�ʹ�� 
int t[30];//���ĸ�����ʼ 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	t[1]=1,t[5]=1,t[7]=1;//��λ��Ϊ0 
	dfs(1);
	return 0;
}
void dfs(int step){
	if(step==11){
		int temp=a[1]*1000+a[2]*100+a[3]*10+a[4]+a[5]*10000+a[1]*1000+a[6]*100+a[7]*10+a[2]+a[7]*1000+a[3]*100+a[8]*10+a[9]*1;//������� 
		if(10000<=temp&&temp<=99999&&temp/10000==a[10]&&temp%10000/1000==a[9]&&temp%1000/100==a[6]&&temp%100/10==a[8]&&temp%10==a[8]){//�ж��ұ������Ƿ�Ϊ��λ��   ����λÿһλ�Ƿ������ĸ 
			printf("%d%d%d%d+%d%d%d%d%d+%d%d%d%d=%d\n",a[1],a[2],a[3],a[4],a[5],a[1],a[6],a[7],a[2],a[7],a[3],a[8],a[9],temp); 
		}
		return;
	}

	
		for(int i=t[step];i<=9;i++){
			if(use[i])	continue;
			use[i]=1;
			a[step]=i;
			dfs(step+1);
			use[i]=0;
		}
	return;
}
