#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char a[200][205];
	int i=0;
	//���� 
	while(cin.getline(a[i],205)) i++;//��һ�� 
	//����+��� 
	int k=0;
	for(int j=0;j<i;j++)//˫��ѭ�� 
	{
		k=0;
		while(a[j][k]!='\0')
		{
			if(a[j][k]!=' ') printf("%c",a[j][k]+1);//���� 
			if(a[j][k]==' ') cout << ' ';//�ǿո��ӡ�ո� 
			k++;
		}
		cout << endl;
	}
	return 0;
}
