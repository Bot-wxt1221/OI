#include <iostream>
#include <cstdio>
using namespace std;
char a[100],b[100],c[200];
int D,d,u; 
int main(){
	gets(a);gets(b);
	int size=-1;
	for(int i=0;a[i]!='\0';i++){
		if('a'<=a[i]&&a[i]<='z'){
			d++;
		}else if('A'<=a[i]&&a[i]<='Z'){
			D++;
		}else{
			u++;
		}
	}
	for(int i=0;b[i]!='\0';i++){
		if('a'<=b[i]&&b[i]<='z'){
			d++;
		}else if('A'<=b[i]&&b[i]<='Z'){
			D++;
		}else{
			u++;
		}
	}
	printf("��%d����д��ĸ����%d��Сд��ĸ����%d������ĸ�ַ�",D,d,u);
	return 0;
}
