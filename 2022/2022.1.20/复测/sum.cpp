//�߾��ȼӷ� 
#include <iostream>
#include <cstdio>
using namespace std;
bool jin[105];//�Ƿ��λ 
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	string a,b;//����̫ˮ�ˣ�string����� 
	cin>>a>>b;
	if(a.size()>b.size()){//ͳһ������λ�� 
		int c=a.size()-b.size();//����ʱλ����䣬��ʹ��������洢   ��ͬ   
		for(int i=1;i<=c;i++){
			b='0'+b;
		}
	}else if(a.size()<b.size()){
		int c=b.size()-a.size();
		for(int i=1;i<=c;i++){
			a='0'+a;

		}
	}
	string c;//�� 
	for(int i=a.size()-1;i>=0;i--){
		int f=(a[i]-'0')+(b[i]-'0');//int����Խ�� 
		if(f>9||(f>8&&jin[i])){//�Ƿ���ǰ��λ 
			if(i!=0){
				jin[i-1]=1;//��ǰ��λ 
				f-=10;
			}else{
				cout<<1;//����ǰ��û����λ����������� 1 �����λ 
				f-=10;
			}
		}
		if(jin[i])	f++;//��λ 
		c=char(f+'0')+c;
	}
	cout<<c;
	return 0;
}

