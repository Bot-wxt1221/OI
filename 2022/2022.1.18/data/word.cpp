#include <iostream>
#include <cstdio>
using namespace std;
char a[105],b[105],c[210];
int d[300];//ͳ��ÿ���ַ����ֵĴ��� 
int D,r,u;//D ��д���� r  Сд����   u  ���� 
int main(){
	freopen("word10.out","w",stdout);
	freopen("word10.in","r",stdin);
	gets(a);gets(b);//a b  ��ԭ����   c �Ǻϲ�������� 
	int size=-1;
	for(int i=0;a[i]!='\0';i++){
		c[++size]=a[i]; //����ȥ ��ͬ 
		d[a[i]]++;//ͳ�Ƴ��ִ���  ��ͬ 
	}
	c[++size]=' ';
	for(int i=0;b[i]!='\0';i++){
		c[++size]=b[i];
		d[b[i]]++;
	}
	c[++size]='\0';
	cout<<c<<endl;
	for(int i=0;c[i]!='\0';i++){//ͳ���ַ���������������� 
		if('a'<=c[i]&&c[i]<='z'){//'a'---'z'��ASCLL������������� 
			r++;
		}else if('A'<=c[i]&&c[i]<='Z'){//'A'---'Z'��ASCLL������������� 
			D++;
		}else{
			u++;
		}
	}
	cout<<D<<' '<<r<<' '<<u<<endl;///���ý��� 
	for(int i=0;i<26;i++){//����ĸ��˳����� 
		if(d[i+'a']){//��Сд 
			printf("%c:%d\n",i+'a',d[i+'a']);
		}
		if(d[i+'A']){//�ٴ�д 
			printf("%c:%d\n",i+'A',d[i+'A']);
		}
	}
	return 0;
}
