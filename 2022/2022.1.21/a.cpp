#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
string b[10000005];//���ַ��� 
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int i=1;//���ٸ��ַ� 
	char temp2=' ';//�������� 
	while(temp2!=EOF){//�߽��ж����Ƿ���� 
		temp2=getchar();
		if(temp2==EOF){
				break;
			}
		while(('a'<=temp2&&temp2<='z')||('A'<=temp2&&temp2<='Z')){//getchar�Ż��ٶ� 
			b[i]=b[i]+temp2;//ƴ�� 
			temp2=getchar();
			if(temp2==EOF){
				break;
			}
		}
		int temp=0;
		while(temp2==' '){//��ո�  ���ַ�����Ŀո�ŵ� �ַ���ǰ�棬��ת��������� 
			temp++;
			temp2=getchar();
			if(temp2==EOF){
				break;
			}
			b[i]=' '+b[i];
		}
		b[i+1]=temp2;
		i++;
	}
	for(int j=1;j<=(i-1)/2;j++){//���� 
		swap(b[j],b[i-j]);
	}
	for(int j=1;j<i;j++){//��� 
		cout<<b[j];
	}
	return 0;
}
